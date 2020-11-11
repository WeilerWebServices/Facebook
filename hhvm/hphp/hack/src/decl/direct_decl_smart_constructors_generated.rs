/**
 * Copyright (c) 2016, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional
 * directory.
 *
 **
 *
 * THIS FILE IS @generated; DO NOT EDIT IT
 * To regenerate this file, run
 *
 *   buck run //hphp/hack/src:generate_full_fidelity
 *
 **
 *
 */
use flatten_smart_constructors::*;
use smart_constructors::SmartConstructors;
use parser_core_types::compact_token::CompactToken;
use parser_core_types::token_factory::SimpleTokenFactoryImpl;

use crate::{State, Node};

#[derive(Clone)]
pub struct DirectDeclSmartConstructors<'src> {
    pub state: State<'src>,
    pub token_factory: SimpleTokenFactoryImpl<CompactToken>,
}
impl<'src> SmartConstructors for DirectDeclSmartConstructors<'src> {
    type State = State<'src>;
    type TF = SimpleTokenFactoryImpl<CompactToken>;
    type R = Node<'src>;

    fn state_mut(&mut self) -> &mut State<'src> {
        &mut self.state
    }

    fn into_state(self) -> State<'src> {
      self.state
    }

    fn token_factory(&mut self) -> &mut Self::TF {
        &mut self.token_factory
    }

    fn make_missing(&mut self, offset: usize) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_missing(self, offset)
    }

    fn make_token(&mut self, token: CompactToken) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_token(self, token)
    }

    fn make_list(&mut self, items: Vec<Self::R>, offset: usize) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_list(self, items, offset)
    }

    fn make_end_of_file(&mut self, token: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_end_of_file(self, token)
    }

    fn make_script(&mut self, declarations: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_script(self, declarations)
    }

    fn make_qualified_name(&mut self, parts: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_qualified_name(self, parts)
    }

    fn make_simple_type_specifier(&mut self, specifier: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_simple_type_specifier(self, specifier)
    }

    fn make_literal_expression(&mut self, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_literal_expression(self, expression)
    }

    fn make_prefixed_string_expression(&mut self, name: Self::R, str: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_prefixed_string_expression(self, name, str)
    }

    fn make_prefixed_code_expression(&mut self, prefix: Self::R, left_backtick: Self::R, expression: Self::R, right_backtick: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_prefixed_code_expression(self, prefix, left_backtick, expression, right_backtick)
    }

    fn make_variable_expression(&mut self, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_variable_expression(self, expression)
    }

    fn make_pipe_variable_expression(&mut self, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pipe_variable_expression(self, expression)
    }

    fn make_file_attribute_specification(&mut self, left_double_angle: Self::R, keyword: Self::R, colon: Self::R, attributes: Self::R, right_double_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_file_attribute_specification(self, left_double_angle, keyword, colon, attributes, right_double_angle)
    }

    fn make_enum_declaration(&mut self, attribute_spec: Self::R, keyword: Self::R, name: Self::R, colon: Self::R, base: Self::R, type_: Self::R, includes_keyword: Self::R, includes_list: Self::R, left_brace: Self::R, enumerators: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_enum_declaration(self, attribute_spec, keyword, name, colon, base, type_, includes_keyword, includes_list, left_brace, enumerators, right_brace)
    }

    fn make_enumerator(&mut self, name: Self::R, equal: Self::R, value: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_enumerator(self, name, equal, value, semicolon)
    }

    fn make_enum_class_declaration(&mut self, attribute_spec: Self::R, enum_keyword: Self::R, class_keyword: Self::R, name: Self::R, colon: Self::R, base: Self::R, extends: Self::R, extends_list: Self::R, left_brace: Self::R, elements: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_enum_class_declaration(self, attribute_spec, enum_keyword, class_keyword, name, colon, base, extends, extends_list, left_brace, elements, right_brace)
    }

    fn make_enum_class_enumerator(&mut self, name: Self::R, left_angle: Self::R, type_: Self::R, right_angle: Self::R, left_paren: Self::R, initial_value: Self::R, right_paren: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_enum_class_enumerator(self, name, left_angle, type_, right_angle, left_paren, initial_value, right_paren, semicolon)
    }

    fn make_record_declaration(&mut self, attribute_spec: Self::R, modifier: Self::R, keyword: Self::R, name: Self::R, extends_keyword: Self::R, extends_opt: Self::R, left_brace: Self::R, fields: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_record_declaration(self, attribute_spec, modifier, keyword, name, extends_keyword, extends_opt, left_brace, fields, right_brace)
    }

    fn make_record_field(&mut self, type_: Self::R, name: Self::R, init: Self::R, semi: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_record_field(self, type_, name, init, semi)
    }

    fn make_alias_declaration(&mut self, attribute_spec: Self::R, keyword: Self::R, name: Self::R, generic_parameter: Self::R, constraint: Self::R, equal: Self::R, type_: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_alias_declaration(self, attribute_spec, keyword, name, generic_parameter, constraint, equal, type_, semicolon)
    }

    fn make_property_declaration(&mut self, attribute_spec: Self::R, modifiers: Self::R, type_: Self::R, declarators: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_property_declaration(self, attribute_spec, modifiers, type_, declarators, semicolon)
    }

    fn make_property_declarator(&mut self, name: Self::R, initializer: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_property_declarator(self, name, initializer)
    }

    fn make_namespace_declaration(&mut self, header: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_declaration(self, header, body)
    }

    fn make_namespace_declaration_header(&mut self, keyword: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_declaration_header(self, keyword, name)
    }

    fn make_namespace_body(&mut self, left_brace: Self::R, declarations: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_body(self, left_brace, declarations, right_brace)
    }

    fn make_namespace_empty_body(&mut self, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_empty_body(self, semicolon)
    }

    fn make_namespace_use_declaration(&mut self, keyword: Self::R, kind: Self::R, clauses: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_use_declaration(self, keyword, kind, clauses, semicolon)
    }

    fn make_namespace_group_use_declaration(&mut self, keyword: Self::R, kind: Self::R, prefix: Self::R, left_brace: Self::R, clauses: Self::R, right_brace: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_group_use_declaration(self, keyword, kind, prefix, left_brace, clauses, right_brace, semicolon)
    }

    fn make_namespace_use_clause(&mut self, clause_kind: Self::R, name: Self::R, as_: Self::R, alias: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_namespace_use_clause(self, clause_kind, name, as_, alias)
    }

    fn make_function_declaration(&mut self, attribute_spec: Self::R, declaration_header: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_function_declaration(self, attribute_spec, declaration_header, body)
    }

    fn make_function_declaration_header(&mut self, modifiers: Self::R, keyword: Self::R, name: Self::R, type_parameter_list: Self::R, left_paren: Self::R, parameter_list: Self::R, right_paren: Self::R, capability: Self::R, capability_provisional: Self::R, colon: Self::R, type_: Self::R, where_clause: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_function_declaration_header(self, modifiers, keyword, name, type_parameter_list, left_paren, parameter_list, right_paren, capability, capability_provisional, colon, type_, where_clause)
    }

    fn make_capability(&mut self, left_bracket: Self::R, types: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_capability(self, left_bracket, types, right_bracket)
    }

    fn make_capability_provisional(&mut self, at: Self::R, left_brace: Self::R, type_: Self::R, unsafe_plus: Self::R, unsafe_type: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_capability_provisional(self, at, left_brace, type_, unsafe_plus, unsafe_type, right_brace)
    }

    fn make_where_clause(&mut self, keyword: Self::R, constraints: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_where_clause(self, keyword, constraints)
    }

    fn make_where_constraint(&mut self, left_type: Self::R, operator: Self::R, right_type: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_where_constraint(self, left_type, operator, right_type)
    }

    fn make_methodish_declaration(&mut self, attribute: Self::R, function_decl_header: Self::R, function_body: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_methodish_declaration(self, attribute, function_decl_header, function_body, semicolon)
    }

    fn make_methodish_trait_resolution(&mut self, attribute: Self::R, function_decl_header: Self::R, equal: Self::R, name: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_methodish_trait_resolution(self, attribute, function_decl_header, equal, name, semicolon)
    }

    fn make_classish_declaration(&mut self, attribute: Self::R, modifiers: Self::R, xhp: Self::R, keyword: Self::R, name: Self::R, type_parameters: Self::R, extends_keyword: Self::R, extends_list: Self::R, implements_keyword: Self::R, implements_list: Self::R, where_clause: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_classish_declaration(self, attribute, modifiers, xhp, keyword, name, type_parameters, extends_keyword, extends_list, implements_keyword, implements_list, where_clause, body)
    }

    fn make_classish_body(&mut self, left_brace: Self::R, elements: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_classish_body(self, left_brace, elements, right_brace)
    }

    fn make_trait_use_precedence_item(&mut self, name: Self::R, keyword: Self::R, removed_names: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_trait_use_precedence_item(self, name, keyword, removed_names)
    }

    fn make_trait_use_alias_item(&mut self, aliasing_name: Self::R, keyword: Self::R, modifiers: Self::R, aliased_name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_trait_use_alias_item(self, aliasing_name, keyword, modifiers, aliased_name)
    }

    fn make_trait_use_conflict_resolution(&mut self, keyword: Self::R, names: Self::R, left_brace: Self::R, clauses: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_trait_use_conflict_resolution(self, keyword, names, left_brace, clauses, right_brace)
    }

    fn make_trait_use(&mut self, keyword: Self::R, names: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_trait_use(self, keyword, names, semicolon)
    }

    fn make_require_clause(&mut self, keyword: Self::R, kind: Self::R, name: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_require_clause(self, keyword, kind, name, semicolon)
    }

    fn make_const_declaration(&mut self, modifiers: Self::R, keyword: Self::R, type_specifier: Self::R, declarators: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_const_declaration(self, modifiers, keyword, type_specifier, declarators, semicolon)
    }

    fn make_constant_declarator(&mut self, name: Self::R, initializer: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_constant_declarator(self, name, initializer)
    }

    fn make_type_const_declaration(&mut self, attribute_spec: Self::R, modifiers: Self::R, keyword: Self::R, type_keyword: Self::R, name: Self::R, type_parameters: Self::R, type_constraint: Self::R, equal: Self::R, type_specifier: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_const_declaration(self, attribute_spec, modifiers, keyword, type_keyword, name, type_parameters, type_constraint, equal, type_specifier, semicolon)
    }

    fn make_decorated_expression(&mut self, decorator: Self::R, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_decorated_expression(self, decorator, expression)
    }

    fn make_parameter_declaration(&mut self, attribute: Self::R, visibility: Self::R, call_convention: Self::R, type_: Self::R, name: Self::R, default_value: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_parameter_declaration(self, attribute, visibility, call_convention, type_, name, default_value)
    }

    fn make_variadic_parameter(&mut self, call_convention: Self::R, type_: Self::R, ellipsis: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_variadic_parameter(self, call_convention, type_, ellipsis)
    }

    fn make_old_attribute_specification(&mut self, left_double_angle: Self::R, attributes: Self::R, right_double_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_old_attribute_specification(self, left_double_angle, attributes, right_double_angle)
    }

    fn make_attribute_specification(&mut self, attributes: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_attribute_specification(self, attributes)
    }

    fn make_attribute(&mut self, at: Self::R, attribute_name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_attribute(self, at, attribute_name)
    }

    fn make_inclusion_expression(&mut self, require: Self::R, filename: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_inclusion_expression(self, require, filename)
    }

    fn make_inclusion_directive(&mut self, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_inclusion_directive(self, expression, semicolon)
    }

    fn make_compound_statement(&mut self, left_brace: Self::R, statements: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_compound_statement(self, left_brace, statements, right_brace)
    }

    fn make_expression_statement(&mut self, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_expression_statement(self, expression, semicolon)
    }

    fn make_markup_section(&mut self, hashbang: Self::R, suffix: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_markup_section(self, hashbang, suffix)
    }

    fn make_markup_suffix(&mut self, less_than_question: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_markup_suffix(self, less_than_question, name)
    }

    fn make_unset_statement(&mut self, keyword: Self::R, left_paren: Self::R, variables: Self::R, right_paren: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_unset_statement(self, keyword, left_paren, variables, right_paren, semicolon)
    }

    fn make_using_statement_block_scoped(&mut self, await_keyword: Self::R, using_keyword: Self::R, left_paren: Self::R, expressions: Self::R, right_paren: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_using_statement_block_scoped(self, await_keyword, using_keyword, left_paren, expressions, right_paren, body)
    }

    fn make_using_statement_function_scoped(&mut self, await_keyword: Self::R, using_keyword: Self::R, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_using_statement_function_scoped(self, await_keyword, using_keyword, expression, semicolon)
    }

    fn make_while_statement(&mut self, keyword: Self::R, left_paren: Self::R, condition: Self::R, right_paren: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_while_statement(self, keyword, left_paren, condition, right_paren, body)
    }

    fn make_if_statement(&mut self, keyword: Self::R, left_paren: Self::R, condition: Self::R, right_paren: Self::R, statement: Self::R, elseif_clauses: Self::R, else_clause: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_if_statement(self, keyword, left_paren, condition, right_paren, statement, elseif_clauses, else_clause)
    }

    fn make_elseif_clause(&mut self, keyword: Self::R, left_paren: Self::R, condition: Self::R, right_paren: Self::R, statement: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_elseif_clause(self, keyword, left_paren, condition, right_paren, statement)
    }

    fn make_else_clause(&mut self, keyword: Self::R, statement: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_else_clause(self, keyword, statement)
    }

    fn make_try_statement(&mut self, keyword: Self::R, compound_statement: Self::R, catch_clauses: Self::R, finally_clause: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_try_statement(self, keyword, compound_statement, catch_clauses, finally_clause)
    }

    fn make_catch_clause(&mut self, keyword: Self::R, left_paren: Self::R, type_: Self::R, variable: Self::R, right_paren: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_catch_clause(self, keyword, left_paren, type_, variable, right_paren, body)
    }

    fn make_finally_clause(&mut self, keyword: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_finally_clause(self, keyword, body)
    }

    fn make_do_statement(&mut self, keyword: Self::R, body: Self::R, while_keyword: Self::R, left_paren: Self::R, condition: Self::R, right_paren: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_do_statement(self, keyword, body, while_keyword, left_paren, condition, right_paren, semicolon)
    }

    fn make_for_statement(&mut self, keyword: Self::R, left_paren: Self::R, initializer: Self::R, first_semicolon: Self::R, control: Self::R, second_semicolon: Self::R, end_of_loop: Self::R, right_paren: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_for_statement(self, keyword, left_paren, initializer, first_semicolon, control, second_semicolon, end_of_loop, right_paren, body)
    }

    fn make_foreach_statement(&mut self, keyword: Self::R, left_paren: Self::R, collection: Self::R, await_keyword: Self::R, as_: Self::R, key: Self::R, arrow: Self::R, value: Self::R, right_paren: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_foreach_statement(self, keyword, left_paren, collection, await_keyword, as_, key, arrow, value, right_paren, body)
    }

    fn make_switch_statement(&mut self, keyword: Self::R, left_paren: Self::R, expression: Self::R, right_paren: Self::R, left_brace: Self::R, sections: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_switch_statement(self, keyword, left_paren, expression, right_paren, left_brace, sections, right_brace)
    }

    fn make_switch_section(&mut self, labels: Self::R, statements: Self::R, fallthrough: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_switch_section(self, labels, statements, fallthrough)
    }

    fn make_switch_fallthrough(&mut self, keyword: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_switch_fallthrough(self, keyword, semicolon)
    }

    fn make_case_label(&mut self, keyword: Self::R, expression: Self::R, colon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_case_label(self, keyword, expression, colon)
    }

    fn make_default_label(&mut self, keyword: Self::R, colon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_default_label(self, keyword, colon)
    }

    fn make_return_statement(&mut self, keyword: Self::R, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_return_statement(self, keyword, expression, semicolon)
    }

    fn make_goto_label(&mut self, name: Self::R, colon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_goto_label(self, name, colon)
    }

    fn make_goto_statement(&mut self, keyword: Self::R, label_name: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_goto_statement(self, keyword, label_name, semicolon)
    }

    fn make_throw_statement(&mut self, keyword: Self::R, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_throw_statement(self, keyword, expression, semicolon)
    }

    fn make_break_statement(&mut self, keyword: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_break_statement(self, keyword, semicolon)
    }

    fn make_continue_statement(&mut self, keyword: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_continue_statement(self, keyword, semicolon)
    }

    fn make_echo_statement(&mut self, keyword: Self::R, expressions: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_echo_statement(self, keyword, expressions, semicolon)
    }

    fn make_concurrent_statement(&mut self, keyword: Self::R, statement: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_concurrent_statement(self, keyword, statement)
    }

    fn make_simple_initializer(&mut self, equal: Self::R, value: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_simple_initializer(self, equal, value)
    }

    fn make_anonymous_class(&mut self, class_keyword: Self::R, left_paren: Self::R, argument_list: Self::R, right_paren: Self::R, extends_keyword: Self::R, extends_list: Self::R, implements_keyword: Self::R, implements_list: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_anonymous_class(self, class_keyword, left_paren, argument_list, right_paren, extends_keyword, extends_list, implements_keyword, implements_list, body)
    }

    fn make_anonymous_function(&mut self, attribute_spec: Self::R, static_keyword: Self::R, async_keyword: Self::R, function_keyword: Self::R, left_paren: Self::R, parameters: Self::R, right_paren: Self::R, colon: Self::R, type_: Self::R, use_: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_anonymous_function(self, attribute_spec, static_keyword, async_keyword, function_keyword, left_paren, parameters, right_paren, colon, type_, use_, body)
    }

    fn make_anonymous_function_use_clause(&mut self, keyword: Self::R, left_paren: Self::R, variables: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_anonymous_function_use_clause(self, keyword, left_paren, variables, right_paren)
    }

    fn make_lambda_expression(&mut self, attribute_spec: Self::R, async_: Self::R, signature: Self::R, arrow: Self::R, body: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_lambda_expression(self, attribute_spec, async_, signature, arrow, body)
    }

    fn make_lambda_signature(&mut self, left_paren: Self::R, parameters: Self::R, right_paren: Self::R, capability: Self::R, colon: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_lambda_signature(self, left_paren, parameters, right_paren, capability, colon, type_)
    }

    fn make_cast_expression(&mut self, left_paren: Self::R, type_: Self::R, right_paren: Self::R, operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_cast_expression(self, left_paren, type_, right_paren, operand)
    }

    fn make_scope_resolution_expression(&mut self, qualifier: Self::R, operator: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_scope_resolution_expression(self, qualifier, operator, name)
    }

    fn make_member_selection_expression(&mut self, object: Self::R, operator: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_member_selection_expression(self, object, operator, name)
    }

    fn make_safe_member_selection_expression(&mut self, object: Self::R, operator: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_safe_member_selection_expression(self, object, operator, name)
    }

    fn make_embedded_member_selection_expression(&mut self, object: Self::R, operator: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_embedded_member_selection_expression(self, object, operator, name)
    }

    fn make_yield_expression(&mut self, keyword: Self::R, operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_yield_expression(self, keyword, operand)
    }

    fn make_prefix_unary_expression(&mut self, operator: Self::R, operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_prefix_unary_expression(self, operator, operand)
    }

    fn make_postfix_unary_expression(&mut self, operand: Self::R, operator: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_postfix_unary_expression(self, operand, operator)
    }

    fn make_binary_expression(&mut self, left_operand: Self::R, operator: Self::R, right_operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_binary_expression(self, left_operand, operator, right_operand)
    }

    fn make_is_expression(&mut self, left_operand: Self::R, operator: Self::R, right_operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_is_expression(self, left_operand, operator, right_operand)
    }

    fn make_as_expression(&mut self, left_operand: Self::R, operator: Self::R, right_operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_as_expression(self, left_operand, operator, right_operand)
    }

    fn make_nullable_as_expression(&mut self, left_operand: Self::R, operator: Self::R, right_operand: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_nullable_as_expression(self, left_operand, operator, right_operand)
    }

    fn make_conditional_expression(&mut self, test: Self::R, question: Self::R, consequence: Self::R, colon: Self::R, alternative: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_conditional_expression(self, test, question, consequence, colon, alternative)
    }

    fn make_eval_expression(&mut self, keyword: Self::R, left_paren: Self::R, argument: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_eval_expression(self, keyword, left_paren, argument, right_paren)
    }

    fn make_define_expression(&mut self, keyword: Self::R, left_paren: Self::R, argument_list: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_define_expression(self, keyword, left_paren, argument_list, right_paren)
    }

    fn make_isset_expression(&mut self, keyword: Self::R, left_paren: Self::R, argument_list: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_isset_expression(self, keyword, left_paren, argument_list, right_paren)
    }

    fn make_function_call_expression(&mut self, receiver: Self::R, type_args: Self::R, left_paren: Self::R, argument_list: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_function_call_expression(self, receiver, type_args, left_paren, argument_list, right_paren)
    }

    fn make_function_pointer_expression(&mut self, receiver: Self::R, type_args: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_function_pointer_expression(self, receiver, type_args)
    }

    fn make_parenthesized_expression(&mut self, left_paren: Self::R, expression: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_parenthesized_expression(self, left_paren, expression, right_paren)
    }

    fn make_braced_expression(&mut self, left_brace: Self::R, expression: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_braced_expression(self, left_brace, expression, right_brace)
    }

    fn make_embedded_braced_expression(&mut self, left_brace: Self::R, expression: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_embedded_braced_expression(self, left_brace, expression, right_brace)
    }

    fn make_list_expression(&mut self, keyword: Self::R, left_paren: Self::R, members: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_list_expression(self, keyword, left_paren, members, right_paren)
    }

    fn make_collection_literal_expression(&mut self, name: Self::R, left_brace: Self::R, initializers: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_collection_literal_expression(self, name, left_brace, initializers, right_brace)
    }

    fn make_object_creation_expression(&mut self, new_keyword: Self::R, object: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_object_creation_expression(self, new_keyword, object)
    }

    fn make_constructor_call(&mut self, type_: Self::R, left_paren: Self::R, argument_list: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_constructor_call(self, type_, left_paren, argument_list, right_paren)
    }

    fn make_record_creation_expression(&mut self, type_: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_record_creation_expression(self, type_, left_bracket, members, right_bracket)
    }

    fn make_darray_intrinsic_expression(&mut self, keyword: Self::R, explicit_type: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_darray_intrinsic_expression(self, keyword, explicit_type, left_bracket, members, right_bracket)
    }

    fn make_dictionary_intrinsic_expression(&mut self, keyword: Self::R, explicit_type: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_dictionary_intrinsic_expression(self, keyword, explicit_type, left_bracket, members, right_bracket)
    }

    fn make_keyset_intrinsic_expression(&mut self, keyword: Self::R, explicit_type: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_keyset_intrinsic_expression(self, keyword, explicit_type, left_bracket, members, right_bracket)
    }

    fn make_varray_intrinsic_expression(&mut self, keyword: Self::R, explicit_type: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_varray_intrinsic_expression(self, keyword, explicit_type, left_bracket, members, right_bracket)
    }

    fn make_vector_intrinsic_expression(&mut self, keyword: Self::R, explicit_type: Self::R, left_bracket: Self::R, members: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_vector_intrinsic_expression(self, keyword, explicit_type, left_bracket, members, right_bracket)
    }

    fn make_element_initializer(&mut self, key: Self::R, arrow: Self::R, value: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_element_initializer(self, key, arrow, value)
    }

    fn make_subscript_expression(&mut self, receiver: Self::R, left_bracket: Self::R, index: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_subscript_expression(self, receiver, left_bracket, index, right_bracket)
    }

    fn make_embedded_subscript_expression(&mut self, receiver: Self::R, left_bracket: Self::R, index: Self::R, right_bracket: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_embedded_subscript_expression(self, receiver, left_bracket, index, right_bracket)
    }

    fn make_awaitable_creation_expression(&mut self, attribute_spec: Self::R, async_: Self::R, compound_statement: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_awaitable_creation_expression(self, attribute_spec, async_, compound_statement)
    }

    fn make_xhp_children_declaration(&mut self, keyword: Self::R, expression: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_children_declaration(self, keyword, expression, semicolon)
    }

    fn make_xhp_children_parenthesized_list(&mut self, left_paren: Self::R, xhp_children: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_children_parenthesized_list(self, left_paren, xhp_children, right_paren)
    }

    fn make_xhp_category_declaration(&mut self, keyword: Self::R, categories: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_category_declaration(self, keyword, categories, semicolon)
    }

    fn make_xhp_enum_type(&mut self, keyword: Self::R, left_brace: Self::R, values: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_enum_type(self, keyword, left_brace, values, right_brace)
    }

    fn make_xhp_lateinit(&mut self, at: Self::R, keyword: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_lateinit(self, at, keyword)
    }

    fn make_xhp_required(&mut self, at: Self::R, keyword: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_required(self, at, keyword)
    }

    fn make_xhp_class_attribute_declaration(&mut self, keyword: Self::R, attributes: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_class_attribute_declaration(self, keyword, attributes, semicolon)
    }

    fn make_xhp_class_attribute(&mut self, type_: Self::R, name: Self::R, initializer: Self::R, required: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_class_attribute(self, type_, name, initializer, required)
    }

    fn make_xhp_simple_class_attribute(&mut self, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_simple_class_attribute(self, type_)
    }

    fn make_xhp_simple_attribute(&mut self, name: Self::R, equal: Self::R, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_simple_attribute(self, name, equal, expression)
    }

    fn make_xhp_spread_attribute(&mut self, left_brace: Self::R, spread_operator: Self::R, expression: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_spread_attribute(self, left_brace, spread_operator, expression, right_brace)
    }

    fn make_xhp_open(&mut self, left_angle: Self::R, name: Self::R, attributes: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_open(self, left_angle, name, attributes, right_angle)
    }

    fn make_xhp_expression(&mut self, open: Self::R, body: Self::R, close: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_expression(self, open, body, close)
    }

    fn make_xhp_close(&mut self, left_angle: Self::R, name: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_xhp_close(self, left_angle, name, right_angle)
    }

    fn make_type_constant(&mut self, left_type: Self::R, separator: Self::R, right_type: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_constant(self, left_type, separator, right_type)
    }

    fn make_pu_access(&mut self, left_type: Self::R, separator: Self::R, right_type: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pu_access(self, left_type, separator, right_type)
    }

    fn make_vector_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, type_: Self::R, trailing_comma: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_vector_type_specifier(self, keyword, left_angle, type_, trailing_comma, right_angle)
    }

    fn make_keyset_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, type_: Self::R, trailing_comma: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_keyset_type_specifier(self, keyword, left_angle, type_, trailing_comma, right_angle)
    }

    fn make_tuple_type_explicit_specifier(&mut self, keyword: Self::R, left_angle: Self::R, types: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_tuple_type_explicit_specifier(self, keyword, left_angle, types, right_angle)
    }

    fn make_varray_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, type_: Self::R, trailing_comma: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_varray_type_specifier(self, keyword, left_angle, type_, trailing_comma, right_angle)
    }

    fn make_type_parameter(&mut self, attribute_spec: Self::R, reified: Self::R, variance: Self::R, name: Self::R, param_params: Self::R, constraints: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_parameter(self, attribute_spec, reified, variance, name, param_params, constraints)
    }

    fn make_type_constraint(&mut self, keyword: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_constraint(self, keyword, type_)
    }

    fn make_darray_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, key: Self::R, comma: Self::R, value: Self::R, trailing_comma: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_darray_type_specifier(self, keyword, left_angle, key, comma, value, trailing_comma, right_angle)
    }

    fn make_dictionary_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, members: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_dictionary_type_specifier(self, keyword, left_angle, members, right_angle)
    }

    fn make_closure_type_specifier(&mut self, outer_left_paren: Self::R, function_keyword: Self::R, inner_left_paren: Self::R, parameter_list: Self::R, inner_right_paren: Self::R, capability: Self::R, colon: Self::R, return_type: Self::R, outer_right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_closure_type_specifier(self, outer_left_paren, function_keyword, inner_left_paren, parameter_list, inner_right_paren, capability, colon, return_type, outer_right_paren)
    }

    fn make_closure_parameter_type_specifier(&mut self, call_convention: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_closure_parameter_type_specifier(self, call_convention, type_)
    }

    fn make_classname_type_specifier(&mut self, keyword: Self::R, left_angle: Self::R, type_: Self::R, trailing_comma: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_classname_type_specifier(self, keyword, left_angle, type_, trailing_comma, right_angle)
    }

    fn make_field_specifier(&mut self, question: Self::R, name: Self::R, arrow: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_field_specifier(self, question, name, arrow, type_)
    }

    fn make_field_initializer(&mut self, name: Self::R, arrow: Self::R, value: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_field_initializer(self, name, arrow, value)
    }

    fn make_shape_type_specifier(&mut self, keyword: Self::R, left_paren: Self::R, fields: Self::R, ellipsis: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_shape_type_specifier(self, keyword, left_paren, fields, ellipsis, right_paren)
    }

    fn make_shape_expression(&mut self, keyword: Self::R, left_paren: Self::R, fields: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_shape_expression(self, keyword, left_paren, fields, right_paren)
    }

    fn make_tuple_expression(&mut self, keyword: Self::R, left_paren: Self::R, items: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_tuple_expression(self, keyword, left_paren, items, right_paren)
    }

    fn make_generic_type_specifier(&mut self, class_type: Self::R, argument_list: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_generic_type_specifier(self, class_type, argument_list)
    }

    fn make_nullable_type_specifier(&mut self, question: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_nullable_type_specifier(self, question, type_)
    }

    fn make_like_type_specifier(&mut self, tilde: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_like_type_specifier(self, tilde, type_)
    }

    fn make_soft_type_specifier(&mut self, at: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_soft_type_specifier(self, at, type_)
    }

    fn make_attributized_specifier(&mut self, attribute_spec: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_attributized_specifier(self, attribute_spec, type_)
    }

    fn make_reified_type_argument(&mut self, reified: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_reified_type_argument(self, reified, type_)
    }

    fn make_type_arguments(&mut self, left_angle: Self::R, types: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_arguments(self, left_angle, types, right_angle)
    }

    fn make_type_parameters(&mut self, left_angle: Self::R, parameters: Self::R, right_angle: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_type_parameters(self, left_angle, parameters, right_angle)
    }

    fn make_tuple_type_specifier(&mut self, left_paren: Self::R, types: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_tuple_type_specifier(self, left_paren, types, right_paren)
    }

    fn make_union_type_specifier(&mut self, left_paren: Self::R, types: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_union_type_specifier(self, left_paren, types, right_paren)
    }

    fn make_intersection_type_specifier(&mut self, left_paren: Self::R, types: Self::R, right_paren: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_intersection_type_specifier(self, left_paren, types, right_paren)
    }

    fn make_error(&mut self, error: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_error(self, error)
    }

    fn make_list_item(&mut self, item: Self::R, separator: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_list_item(self, item, separator)
    }

    fn make_pocket_atom_expression(&mut self, glyph: Self::R, expression: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_atom_expression(self, glyph, expression)
    }

    fn make_pocket_identifier_expression(&mut self, qualifier: Self::R, pu_operator: Self::R, field: Self::R, operator: Self::R, name: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_identifier_expression(self, qualifier, pu_operator, field, operator, name)
    }

    fn make_pocket_atom_mapping_declaration(&mut self, glyph: Self::R, name: Self::R, left_paren: Self::R, mappings: Self::R, right_paren: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_atom_mapping_declaration(self, glyph, name, left_paren, mappings, right_paren, semicolon)
    }

    fn make_pocket_enum_declaration(&mut self, attributes: Self::R, modifiers: Self::R, enum_: Self::R, name: Self::R, left_brace: Self::R, fields: Self::R, right_brace: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_enum_declaration(self, attributes, modifiers, enum_, name, left_brace, fields, right_brace)
    }

    fn make_pocket_field_type_expr_declaration(&mut self, case: Self::R, type_: Self::R, name: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_field_type_expr_declaration(self, case, type_, name, semicolon)
    }

    fn make_pocket_field_type_declaration(&mut self, case: Self::R, type_: Self::R, type_parameter: Self::R, semicolon: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_field_type_declaration(self, case, type_, type_parameter, semicolon)
    }

    fn make_pocket_mapping_id_declaration(&mut self, name: Self::R, initializer: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_mapping_id_declaration(self, name, initializer)
    }

    fn make_pocket_mapping_type_declaration(&mut self, keyword: Self::R, name: Self::R, equal: Self::R, type_: Self::R) -> Self::R {
        <Self as FlattenSmartConstructors<'src, State<'src>>>::make_pocket_mapping_type_declaration(self, keyword, name, equal, type_)
    }

}