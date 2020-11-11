/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
 * This pass eliminates gotos by moving trivial instructions such a consts and
 * moves before a conditional branch.
 *
 * For example:
 *
 *       IF_EQZ v2, L1
 *       CONST v0, 1
 *       ... (GOTO elsewhere or RETURN or THROW)
 *   L1: CONST v0, 0 // where L1 is only reachable via the above IF-instruction
 *       GOTO L2
 *
 * becomes
 *
 *       CONST v0, 0
 *       IF_EQZ v2, L2
 *       CONST v0, 1
 *       ...
 *
 */

#include "UpCodeMotion.h"

#include <vector>

#include "ControlFlow.h"
#include "DexClass.h"
#include "DexUtil.h"
#include "IRCode.h"
#include "IRInstruction.h"
#include "IROpcode.h"
#include "PassManager.h"
#include "Show.h"
#include "TypeInference.h"
#include "Walkers.h"

namespace {

constexpr const char* METRIC_INSTRUCTIONS_MOVED = "num_instructions_moved";
constexpr const char* METRIC_BRANCHES_MOVED_OVER = "num_branches_moved_over";
constexpr const char* METRIC_INVERTED_CONDITIONAL_BRANCHES =
    "num_inverted_conditional_branches";
constexpr const char* METRIC_CLOBBERED_REGISTERS = "num_clobbered_registers";

} // namespace

// Helper function that scans a block for leading const and move instructions,
// and returning a value that indicates whether there's no other kind of
// instruction in the block.
bool UpCodeMotionPass::gather_movable_instructions(
    cfg::Block* b, std::vector<IRInstruction*>* instructions) {
  for (auto& mie : InstructionIterable(b)) {
    auto insn = mie.insn;

    // We really only support at this time...
    // - const, not const-wide, const-class, or const-string.
    // - move and move-object, not move-wide
    // - other trivial side-effect free computations that are not wide
    switch (insn->opcode()) {
    case OPCODE_NOP:
      continue;

    case OPCODE_CONST:
    case OPCODE_MOVE:
    case OPCODE_MOVE_OBJECT:

    case OPCODE_NEG_INT:
    case OPCODE_NOT_INT:
    case OPCODE_NEG_FLOAT:
    case OPCODE_INT_TO_FLOAT:
    case OPCODE_FLOAT_TO_INT:
    case OPCODE_INT_TO_BYTE:
    case OPCODE_INT_TO_CHAR:
    case OPCODE_INT_TO_SHORT:
    case OPCODE_CMPL_FLOAT:
    case OPCODE_CMPG_FLOAT:

    case OPCODE_ADD_INT:
    case OPCODE_SUB_INT:
    case OPCODE_MUL_INT:
    case OPCODE_AND_INT:
    case OPCODE_OR_INT:
    case OPCODE_XOR_INT:
    case OPCODE_SHL_INT:
    case OPCODE_SHR_INT:
    case OPCODE_USHR_INT:
    case OPCODE_ADD_INT_LIT16:
    case OPCODE_RSUB_INT:
    case OPCODE_MUL_INT_LIT16:
    case OPCODE_AND_INT_LIT16:
    case OPCODE_OR_INT_LIT16:
    case OPCODE_XOR_INT_LIT16:
    case OPCODE_ADD_INT_LIT8:
    case OPCODE_RSUB_INT_LIT8:
    case OPCODE_MUL_INT_LIT8:
    case OPCODE_AND_INT_LIT8:
    case OPCODE_OR_INT_LIT8:
    case OPCODE_XOR_INT_LIT8:
    case OPCODE_SHL_INT_LIT8:
    case OPCODE_SHR_INT_LIT8:
    case OPCODE_USHR_INT_LIT8:
      instructions->push_back(insn);
      continue;

    default:
      return false;
    }
  }

  return true;
}

// Helper function that, given a branch and a goto edge, figures out if all
// movable instructions of the branch edge target block have a matching
// (same dest register) leading instruction in the goto edge target block,
// and that move-instructions don't read what's written.
bool UpCodeMotionPass::gather_instructions_to_insert(
    cfg::Edge* branch_edge,
    cfg::Edge* goto_edge,
    std::vector<IRInstruction*>* instructions_to_insert) {
  cfg::Block* branch_block = branch_edge->target();
  // The branch edge target block must end in a goto, and
  // have a unique predecessor.
  if (branch_block->branchingness() != opcode::BRANCH_GOTO ||
      branch_block->preds().size() != 1) {
    TRACE(UCM, 5, "[up code motion] giving up: branch block");
    return false;
  }

  std::vector<IRInstruction*> ordered_branch_instructions;
  // Gather all of the movable instructions of the branch edge
  // target block; give up when there are any other instructions.
  if (!gather_movable_instructions(branch_block,
                                   &ordered_branch_instructions)) {
    TRACE(UCM, 5, "[up code motion] giving up: gather");
    return false;
  }

  cfg::Block* goto_block = goto_edge->target();
  std::vector<IRInstruction*> ordered_instructions_in_goto_block;
  // Gather all of the movable instructions of the branch edge
  // goto block; it's okay if there are other trailing instructions.
  gather_movable_instructions(goto_block, &ordered_instructions_in_goto_block);

  // In the following, we check if all the registers assigned to by
  // movable instructions of the branch edge target block also
  // get assigned by the goto edge target block.
  std::unordered_map<uint32_t, size_t> goto_instruction_ends;
  for (size_t i = 0; i < ordered_instructions_in_goto_block.size(); i++) {
    IRInstruction* insn = ordered_instructions_in_goto_block[i];
    // only the first emplace for a particular register will stick
    goto_instruction_ends.emplace(insn->dest(), i + 1);
  }

  std::unordered_set<uint32_t> destroyed_dests;
  size_t ordered_instructions_in_goto_block_index_end = 0;
  for (IRInstruction* insn : ordered_branch_instructions) {
    uint32_t dest = insn->dest();
    destroyed_dests.insert(dest);
    auto it = goto_instruction_ends.find(dest);
    if (it == goto_instruction_ends.end()) {
      TRACE(UCM, 5,
            "[up code motion] giving up: branch instruction assigns to "
            "dest with no corresponding goto instructions");
      return false;
    }
    ordered_instructions_in_goto_block_index_end =
        std::max(ordered_instructions_in_goto_block_index_end, it->second);
  }

  if (destroyed_dests.empty()) {
    return false;
  }

  // Do the goto-instructions need any src that the branch-instructions
  // destroy?
  for (size_t i = 0; i < ordered_instructions_in_goto_block_index_end; i++) {
    IRInstruction* insn = ordered_instructions_in_goto_block[i];
    for (auto src : insn->srcs()) {
      if (destroyed_dests.count(src)) {
        TRACE(UCM, 5,
              "[up code motion] giving up: goto source overlaps with "
              "branch dest");
        return false;
      }
    }
    destroyed_dests.erase(insn->dest());
  }

  // All tests passed. Let's populate instructions_to_insert...
  for (IRInstruction* insn : ordered_branch_instructions) {
    insn = new IRInstruction(*insn);
    instructions_to_insert->push_back(insn);
  }

  return true;
}

UpCodeMotionPass::Stats UpCodeMotionPass::process_code(bool is_static,
                                                       DexType* declaring_type,
                                                       DexTypeList* args,
                                                       IRCode* code) {
  Stats stats;

  code->build_cfg(/* editable = true*/);
  auto& cfg = code->cfg();

  std::unique_ptr<type_inference::TypeInference> type_inference;
  std::unordered_set<cfg::Block*> blocks_to_remove;
  for (cfg::Block* b : cfg.blocks()) {
    if (blocks_to_remove.count(b)) {
      continue;
    }

    auto br = b->branchingness();
    if (br != opcode::BRANCH_IF) {
      continue;
    }

    auto last_insn_it = b->get_last_insn();
    always_assert(last_insn_it != b->end());

    auto if_insn = last_insn_it->insn;
    always_assert(opcode::is_a_conditional_branch(if_insn->opcode()));
    always_assert(!if_insn->is_wide());

    // We found a block that ends with a conditional branch.
    // Let's see if our transformation can be applied.
    cfg::Edge* branch_edge = cfg.get_succ_edge_of_type(b, cfg::EDGE_BRANCH);
    always_assert(branch_edge != nullptr);
    cfg::Edge* goto_edge = cfg.get_succ_edge_of_type(b, cfg::EDGE_GOTO);
    always_assert(goto_edge != nullptr);

    std::vector<IRInstruction*> instructions_to_insert;
    std::vector<uint32_t> clobbered_regs;
    // Can we do our code transformation directly?
    if (!gather_instructions_to_insert(branch_edge, goto_edge,
                                       &instructions_to_insert)) {
      // Or do we first have to flip the conditional branch?
      if (!gather_instructions_to_insert(goto_edge, branch_edge,
                                         &instructions_to_insert)) {
        // We just can't do it.
        continue;
      }

      // Flip conditional branch before doing actual transformation.
      if_insn->set_opcode(opcode::invert_conditional_branch(if_insn->opcode()));
      // swap goto and branch target
      cfg::Block* branch_target = branch_edge->target();
      cfg::Block* goto_target = goto_edge->target();
      cfg.set_edge_target(branch_edge, goto_target);
      cfg.set_edge_target(goto_edge, branch_target);
      stats.inverted_conditional_branches++;
    }

    // We want to insert the (cloned) movable instructions of the branch edge
    // target block just in front of the if-instruction. However, if the if-
    // instruction reads from the same registers that the movable
    // instructions write to, then we have a problem. To work around that
    // problem, we move the problematic registers used by the if-instruction to
    // new temp registers, and then rewrite the if-instruction to use the new
    // temp register. Even though the new move instructions increase code size
    // here, this is largely undone later by register allocation + copy
    // propagation.

    std::unordered_map<uint32_t, uint32_t> temps;
    for (auto instruction_to_insert : instructions_to_insert) {
      auto dest = instruction_to_insert->dest();
      const auto& srcs = if_insn->srcs();
      for (size_t i = 0; i < srcs.size(); i++) {
        if (srcs[i] == dest) {
          uint32_t temp;
          auto temp_it = temps.find(dest);
          if (temp_it != temps.end()) {
            temp = temp_it->second;
          } else {
            if (!type_inference) {
              // We run the type inference once, and reuse results within this
              // method. This is okay, even though we mutate the cfg, because
              // we don't change the set of if-instructions, and only do per-
              // instructions lookups in the type environments.
              type_inference.reset(new type_inference::TypeInference(cfg));
              type_inference->run(is_static, declaring_type, args);
            }

            auto& type_environments = type_inference->get_type_environments();
            auto& type_environment = type_environments.at(if_insn);
            auto type = type_environment.get_type(dest);
            always_assert(!type.is_top() && !type.is_bottom());

            temp = cfg.allocate_temp();
            auto it = b->to_cfg_instruction_iterator(last_insn_it);
            IRInstruction* move_insn = new IRInstruction(
                type.element() == REFERENCE ? OPCODE_MOVE_OBJECT : OPCODE_MOVE);
            move_insn->set_src(0, dest)->set_dest(temp);
            cfg.insert_before(it, move_insn);
            stats.clobbered_registers++;
            temps.emplace(dest, temp);
          }
          if_insn->set_src(i, temp);
        }
      }
    }

    // Okay, we can apply our transformation:
    // We insert the (cloned) movable instructions of the branch edge target
    // block just in front of the if-instruction.
    // And then we remove the branch edge target block, rewiring the branch edge
    // to point to the goto target of the branch edge target block.

    cfg::Block* branch_block = branch_edge->target();
    for (IRInstruction* insn : instructions_to_insert) {
      auto it = b->to_cfg_instruction_iterator(last_insn_it);
      cfg.insert_before(it, insn);
    }
    cfg.set_edge_target(branch_edge, branch_block->goes_to());
    blocks_to_remove.insert(branch_block);

    stats.instructions_moved += instructions_to_insert.size();
    stats.branches_moved_over++;
  }

  for (cfg::Block* b : blocks_to_remove) {
    cfg.remove_block(b);
  }

  code->clear_cfg();
  return stats;
}

void UpCodeMotionPass::run_pass(DexStoresVector& stores,
                                ConfigFiles& /* unused */,
                                PassManager& mgr) {
  auto scope = build_class_scope(stores);

  Stats stats = walk::parallel::methods<Stats>(scope, [](DexMethod* method) {
    const auto code = method->get_code();
    if (!code) {
      return Stats{};
    }

    Stats stats =
        UpCodeMotionPass::process_code(is_static(method), method->get_class(),
                                       method->get_proto()->get_args(), code);
    if (stats.instructions_moved || stats.branches_moved_over) {
      TRACE(UCM, 3,
            "[up code motion] Moved %u instructions over %u conditional "
            "branches while inverting %u conditional branches and dealing "
            "with %u clobbered registers in {%s}",
            stats.instructions_moved, stats.branches_moved_over,
            stats.inverted_conditional_branches, stats.clobbered_registers,
            SHOW(method));
    }
    return stats;
  });

  mgr.incr_metric(METRIC_INSTRUCTIONS_MOVED, stats.instructions_moved);
  mgr.incr_metric(METRIC_BRANCHES_MOVED_OVER, stats.branches_moved_over);
  mgr.incr_metric(METRIC_INVERTED_CONDITIONAL_BRANCHES,
                  stats.inverted_conditional_branches);
  mgr.incr_metric(METRIC_CLOBBERED_REGISTERS, stats.clobbered_registers);
  TRACE(UCM, 1,
        "[up code motion] Moved %u instructions over %u conditional branches "
        "while inverting %u conditional branches and dealing with %u clobbered "
        "registers in total",
        stats.instructions_moved, stats.branches_moved_over,
        stats.inverted_conditional_branches, stats.clobbered_registers);
}

static UpCodeMotionPass s_pass;