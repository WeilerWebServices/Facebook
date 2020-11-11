#!/bin/bash
# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

# shellcheck disable=SC2094

queries_in_file autocomplete "foo_parse_fail.js" --pretty
queries_in_file autocomplete "foo.js" --pretty
queries_in_file autocomplete "bar.js" --pretty
queries_in_file autocomplete "str.js" --pretty
queries_in_file autocomplete "num.js" --pretty
queries_in_file autocomplete "bool.js" --pretty
queries_in_file autocomplete "union.js" --pretty
queries_in_file autocomplete "object_builtins.js" --pretty
queries_in_file autocomplete "function_builtins.js" --pretty
queries_in_file autocomplete "fun.js" --pretty
queries_in_file autocomplete "this.js" --pretty
queries_in_file autocomplete "this2.js" --pretty
queries_in_file autocomplete "typeparams.js" --pretty
queries_in_file autocomplete "typeparams_function.js" --pretty
queries_in_file autocomplete "generics.js" --pretty
queries_in_file autocomplete "optional.js" --pretty
queries_in_file autocomplete "jsx1.js" --pretty
queries_in_file autocomplete "jsx2.js" --pretty
queries_in_file autocomplete "jsx3.js" --pretty
queries_in_file autocomplete "jsx4.js" --pretty
queries_in_file autocomplete "jsx-function-component.js" --pretty
queries_in_file autocomplete "jsx-function-component-2.js" --pretty
queries_in_file autocomplete "jsx-function-component-3.js" --pretty
queries_in_file autocomplete "jsx-abstract-component.js" --pretty
queries_in_file autocomplete "jsx-with-children.js" --pretty
queries_in_file autocomplete "jsx-text.js" --pretty
queries_in_file autocomplete "customfun.js" --pretty
queries_in_file autocomplete "issue-1368.js" --pretty
queries_in_file autocomplete "if.js" --pretty
queries_in_file autocomplete "override.js" --pretty
queries_in_file autocomplete "member_class_property.js" --lsp
queries_in_file autocomplete "member_class_static.js" --pretty
queries_in_file autocomplete "member_middle.js" --pretty
queries_in_file autocomplete "optional_chaining_middle.js" --pretty
queries_in_file autocomplete "optional_chaining_new.js" --pretty
queries_in_file autocomplete "optional_chaining_continue.js" --pretty
queries_in_file autocomplete "idx.js" --pretty
queries_in_file autocomplete "generic_alias.js" --pretty
queries_in_file autocomplete "object_literal.js" --pretty
queries_in_file autocomplete "optional_object.js" --pretty
queries_in_file autocomplete "indirect_array.js" --pretty
queries_in_file autocomplete "infer.js" --pretty
queries_in_file autocomplete "eval_predicate.js" --pretty
queries_in_file autocomplete "eval_destructor.js" --pretty
queries_in_file autocomplete "poly.js" --pretty
queries_in_file autocomplete "poly_no_args.js" --pretty
queries_in_file autocomplete "identifier.js" --pretty
queries_in_file autocomplete "identifier_middle.js" --pretty
queries_in_file autocomplete "super.js" --pretty
queries_in_file autocomplete "this-2.js" --pretty
queries_in_file autocomplete "pattern.js" --pretty
queries_in_file autocomplete "normalize-1.js" --pretty
queries_in_file autocomplete "normalize-2.js" --pretty
queries_in_file autocomplete "unqualified-type-annotation.js" --lsp
queries_in_file autocomplete "qualified-type-annotation.js" --pretty
queries_in_file autocomplete "qualified-type-annotation-require.js" --pretty
queries_in_file autocomplete "inherited-class-properties.js" --pretty
queries_in_file autocomplete "function-added-properties.js" --pretty
queries_in_file autocomplete "comments.js" --pretty
queries_in_file autocomplete "literal.js" --pretty
queries_in_file autocomplete "import_source.js" --pretty
queries_in_file autocomplete "object-with-prototype.js" --pretty
queries_in_file autocomplete "object-spread-1.js" --pretty
queries_in_file autocomplete "object-spread-2.js" --pretty
queries_in_file autocomplete "union-2.js" --pretty
queries_in_file autocomplete "type-alias.js" --pretty
queries_in_file autocomplete "intersection.js" --pretty
queries_in_file autocomplete "rank.js" --lsp
queries_in_file autocomplete "rank_union.js" --lsp
queries_in_file autocomplete "rank_intersection.js" --lsp
queries_in_file autocomplete "suggest_optional_chaining_1.js" --lsp
queries_in_file autocomplete "suggest_optional_chaining_2.js" --lsp
queries_in_file autocomplete "suggest_optional_chaining_3.js" --lsp
queries_in_file autocomplete "enums.js" --lsp
queries_in_file autocomplete "enum-id.js" --pretty
queries_in_file autocomplete "class_declaration_name.js" --pretty
queries_in_file autocomplete "pattern_object_key_middle.js" --pretty
queries_in_file autocomplete "jsdoc.js" --lsp
queries_in_file autocomplete "jsdoc-members-1.js" --lsp
queries_in_file autocomplete "jsdoc-members-2.js" --lsp
queries_in_file autocomplete "jsdoc-members-3.js" --lsp
queries_in_file autocomplete "jsdoc-members-4.js" --lsp
queries_in_file autocomplete "jsdoc-members-5.js" --lsp
queries_in_file autocomplete "jsdoc-members-6.js" --lsp
queries_in_file autocomplete "jsdoc-members-7.js" --lsp
queries_in_file autocomplete "jsdoc-members-8.js" --lsp
queries_in_file autocomplete "types-jsdoc.js" --lsp
queries_in_file autocomplete "qualified-types-jsdoc.js" --lsp