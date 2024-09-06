#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 123
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 0
#define TOKEN_COUNT 40
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 12
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 20

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_LF = 2,
  anon_sym_SEMI = 3,
  anon_sym_NULL = 4,
  anon_sym_COMMA = 5,
  anon_sym_use = 6,
  anon_sym_COLON_COLON_STAR = 7,
  anon_sym_COLON_COLON = 8,
  anon_sym_LBRACE = 9,
  anon_sym_self = 10,
  anon_sym_RBRACE = 11,
  anon_sym_for = 12,
  anon_sym_let = 13,
  anon_sym_COLON = 14,
  anon_sym_EQ = 15,
  anon_sym_const = 16,
  anon_sym_static = 17,
  anon_sym_COLON_EQ = 18,
  sym_primitive_type = 19,
  sym_integer_literal = 20,
  sym_float_literal = 21,
  anon_sym_true = 22,
  anon_sym_false = 23,
  sym_nil_literal = 24,
  anon_sym_DQUOTE = 25,
  aux_sym_string_literal_token1 = 26,
  anon_sym_BQUOTE = 27,
  aux_sym_raw_string_literal_token1 = 28,
  sym_escape_sequence = 29,
  sym_byte_literal = 30,
  sym_rune_literal = 31,
  sym_cpp_flag = 32,
  sym_ignore_operator = 33,
  anon_sym_mut = 34,
  anon_sym_AMP = 35,
  anon_sym_LPAREN = 36,
  anon_sym_RPAREN = 37,
  sym_line_comment = 38,
  sym_block_comment = 39,
  sym_source_file = 40,
  sym__statement = 41,
  sym__expression = 42,
  sym_expression_list = 43,
  sym_use_decl = 44,
  sym_simple = 45,
  sym_wildcard = 46,
  sym_selector = 47,
  sym_aliased = 48,
  sym__var_decl = 49,
  sym_let_decl = 50,
  sym_single_var = 51,
  sym_multi_var = 52,
  sym_const_decl = 53,
  sym_static_decl = 54,
  sym_short_decl = 55,
  sym_short_names = 56,
  sym_qualified_identifier = 57,
  sym__types = 58,
  sym__literals = 59,
  sym_number_literal = 60,
  sym_bool_literal = 61,
  sym_string_literal = 62,
  sym_raw_string_literal = 63,
  sym_mut_flag = 64,
  sym_ref_pattern = 65,
  sym_mut_pattern = 66,
  sym_tuple_pattern = 67,
  aux_sym_source_file_repeat1 = 68,
  aux_sym_expression_list_repeat1 = 69,
  aux_sym_selector_repeat1 = 70,
  aux_sym_short_names_repeat1 = 71,
  aux_sym_string_literal_repeat1 = 72,
  aux_sym_tuple_pattern_repeat1 = 73,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LF] = "\n",
  [anon_sym_SEMI] = ";",
  [anon_sym_NULL] = "\0",
  [anon_sym_COMMA] = ",",
  [anon_sym_use] = "use",
  [anon_sym_COLON_COLON_STAR] = "::*",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_LBRACE] = "{",
  [anon_sym_self] = "self_import",
  [anon_sym_RBRACE] = "}",
  [anon_sym_for] = "for",
  [anon_sym_let] = "let",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_const] = "const",
  [anon_sym_static] = "static",
  [anon_sym_COLON_EQ] = ":=",
  [sym_primitive_type] = "primitive_type",
  [sym_integer_literal] = "integer_literal",
  [sym_float_literal] = "float_literal",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_nil_literal] = "nil_literal",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_content",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_raw_string_literal_token1] = "raw_string_content",
  [sym_escape_sequence] = "escape_sequence",
  [sym_byte_literal] = "byte_literal",
  [sym_rune_literal] = "rune_literal",
  [sym_cpp_flag] = "cpp_flag",
  [sym_ignore_operator] = "ignore_operator",
  [anon_sym_mut] = "mut",
  [anon_sym_AMP] = "&",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_expression_list] = "expression_list",
  [sym_use_decl] = "use_decl",
  [sym_simple] = "simple",
  [sym_wildcard] = "wildcard",
  [sym_selector] = "selector",
  [sym_aliased] = "aliased",
  [sym__var_decl] = "_var_decl",
  [sym_let_decl] = "let_decl",
  [sym_single_var] = "single_var",
  [sym_multi_var] = "multi_var",
  [sym_const_decl] = "const_decl",
  [sym_static_decl] = "static_decl",
  [sym_short_decl] = "short_decl",
  [sym_short_names] = "short_names",
  [sym_qualified_identifier] = "qualified_identifier",
  [sym__types] = "_types",
  [sym__literals] = "_literals",
  [sym_number_literal] = "number_literal",
  [sym_bool_literal] = "bool_literal",
  [sym_string_literal] = "string_literal",
  [sym_raw_string_literal] = "raw_string_literal",
  [sym_mut_flag] = "mut_flag",
  [sym_ref_pattern] = "ref_pattern",
  [sym_mut_pattern] = "mut_pattern",
  [sym_tuple_pattern] = "tuple_pattern",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_expression_list_repeat1] = "expression_list_repeat1",
  [aux_sym_selector_repeat1] = "selector_repeat1",
  [aux_sym_short_names_repeat1] = "short_names_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
  [aux_sym_tuple_pattern_repeat1] = "tuple_pattern_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_NULL] = anon_sym_NULL,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_COLON_COLON_STAR] = anon_sym_COLON_COLON_STAR,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_self] = anon_sym_self,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_const] = anon_sym_const,
  [anon_sym_static] = anon_sym_static,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [sym_primitive_type] = sym_primitive_type,
  [sym_integer_literal] = sym_integer_literal,
  [sym_float_literal] = sym_float_literal,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_nil_literal] = sym_nil_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_raw_string_literal_token1] = aux_sym_raw_string_literal_token1,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_byte_literal] = sym_byte_literal,
  [sym_rune_literal] = sym_rune_literal,
  [sym_cpp_flag] = sym_cpp_flag,
  [sym_ignore_operator] = sym_ignore_operator,
  [anon_sym_mut] = anon_sym_mut,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_expression_list] = sym_expression_list,
  [sym_use_decl] = sym_use_decl,
  [sym_simple] = sym_simple,
  [sym_wildcard] = sym_wildcard,
  [sym_selector] = sym_selector,
  [sym_aliased] = sym_aliased,
  [sym__var_decl] = sym__var_decl,
  [sym_let_decl] = sym_let_decl,
  [sym_single_var] = sym_single_var,
  [sym_multi_var] = sym_multi_var,
  [sym_const_decl] = sym_const_decl,
  [sym_static_decl] = sym_static_decl,
  [sym_short_decl] = sym_short_decl,
  [sym_short_names] = sym_short_names,
  [sym_qualified_identifier] = sym_qualified_identifier,
  [sym__types] = sym__types,
  [sym__literals] = sym__literals,
  [sym_number_literal] = sym_number_literal,
  [sym_bool_literal] = sym_bool_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_raw_string_literal] = sym_raw_string_literal,
  [sym_mut_flag] = sym_mut_flag,
  [sym_ref_pattern] = sym_ref_pattern,
  [sym_mut_pattern] = sym_mut_pattern,
  [sym_tuple_pattern] = sym_tuple_pattern,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_expression_list_repeat1] = aux_sym_expression_list_repeat1,
  [aux_sym_selector_repeat1] = aux_sym_selector_repeat1,
  [aux_sym_short_names_repeat1] = aux_sym_short_names_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
  [aux_sym_tuple_pattern_repeat1] = aux_sym_tuple_pattern_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_self] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_const] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_static] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_float_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_nil_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_literal_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_raw_string_literal_token1] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_byte_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_rune_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_cpp_flag] = {
    .visible = true,
    .named = true,
  },
  [sym_ignore_operator] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_mut] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_expression_list] = {
    .visible = true,
    .named = true,
  },
  [sym_use_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_simple] = {
    .visible = true,
    .named = true,
  },
  [sym_wildcard] = {
    .visible = true,
    .named = true,
  },
  [sym_selector] = {
    .visible = true,
    .named = true,
  },
  [sym_aliased] = {
    .visible = true,
    .named = true,
  },
  [sym__var_decl] = {
    .visible = false,
    .named = true,
  },
  [sym_let_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_single_var] = {
    .visible = true,
    .named = true,
  },
  [sym_multi_var] = {
    .visible = true,
    .named = true,
  },
  [sym_const_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_static_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_short_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_short_names] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__types] = {
    .visible = false,
    .named = true,
  },
  [sym__literals] = {
    .visible = false,
    .named = true,
  },
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_raw_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_mut_flag] = {
    .visible = true,
    .named = true,
  },
  [sym_ref_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_mut_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_pattern] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_expression_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_selector_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_short_names_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tuple_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_alias = 1,
  field_import = 2,
  field_items = 3,
  field_member = 4,
  field_name = 5,
  field_names = 6,
  field_namespace = 7,
  field_path = 8,
  field_pattern = 9,
  field_type = 10,
  field_value = 11,
  field_values = 12,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_import] = "import",
  [field_items] = "items",
  [field_member] = "member",
  [field_name] = "name",
  [field_names] = "names",
  [field_namespace] = "namespace",
  [field_path] = "path",
  [field_pattern] = "pattern",
  [field_type] = "type",
  [field_value] = "value",
  [field_values] = "values",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 2},
  [10] = {.index = 15, .length = 1},
  [11] = {.index = 16, .length = 2},
  [12] = {.index = 18, .length = 2},
  [13] = {.index = 20, .length = 2},
  [14] = {.index = 22, .length = 3},
  [15] = {.index = 25, .length = 2},
  [16] = {.index = 27, .length = 2},
  [17] = {.index = 29, .length = 3},
  [18] = {.index = 32, .length = 3},
  [19] = {.index = 35, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_path, 0},
  [1] =
    {field_name, 1},
  [2] =
    {field_name, 2},
  [3] =
    {field_member, 2},
    {field_namespace, 0},
  [5] =
    {field_names, 0},
    {field_values, 2},
  [7] =
    {field_alias, 0},
    {field_import, 2},
  [9] =
    {field_name, 1},
    {field_type, 3},
  [11] =
    {field_name, 1},
    {field_value, 3},
  [13] =
    {field_pattern, 1},
    {field_values, 3},
  [15] =
    {field_name, 3},
  [16] =
    {field_name, 2},
    {field_type, 4},
  [18] =
    {field_name, 2},
    {field_value, 4},
  [20] =
    {field_items, 3},
    {field_path, 0},
  [22] =
    {field_name, 1},
    {field_type, 3},
    {field_value, 5},
  [25] =
    {field_name, 3},
    {field_type, 5},
  [27] =
    {field_name, 3},
    {field_value, 5},
  [29] =
    {field_items, 3},
    {field_items, 4},
    {field_path, 0},
  [32] =
    {field_name, 2},
    {field_type, 4},
    {field_value, 6},
  [35] =
    {field_name, 3},
    {field_type, 5},
    {field_value, 7},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 35,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 108,
};

static TSCharacterRange sym_escape_sequence_character_set_1[] = {
  {'"', '"'}, {'\'', '\''}, {'0', '7'}, {'U', 'U'}, {'\\', '\\'}, {'a', 'b'}, {'f', 'f'}, {'n', 'n'},
  {'r', 'r'}, {'t', 'v'}, {'x', 'x'},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(98);
      ADVANCE_MAP(
        0, 101,
        '"', 148,
        '&', 169,
        '\'', 22,
        '(', 170,
        ')', 171,
        ',', 102,
        '-', 31,
        '.', 71,
        '/', 28,
        '0', 136,
        ':', 109,
        ';', 100,
        '=', 110,
        '\\', 6,
        '`', 154,
        'a', 120,
        'b', 123,
        'f', 115,
        'i', 113,
        'r', 131,
        's', 128,
        'u', 112,
        '{', 106,
        '}', 107,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(95);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(101);
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == ';') ADVANCE(100);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '\\') SKIP(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if ((!eof && lookahead == 00)) ADVANCE(101);
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(108);
      if (lookahead == ';') ADVANCE(100);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '\\') SKIP(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        0, 101,
        '"', 148,
        '&', 169,
        '\'', 22,
        '(', 170,
        ')', 171,
        ',', 102,
        '-', 31,
        '.', 71,
        '/', 28,
        '0', 136,
        ':', 109,
        ';', 100,
        '=', 110,
      );
      if (lookahead == '\\') SKIP(5);
      if (lookahead == '`') ADVANCE(154);
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead == 'b') ADVANCE(123);
      if (lookahead == 'f') ADVANCE(115);
      if (lookahead == 'i') ADVANCE(113);
      if (lookahead == 'r') ADVANCE(131);
      if (lookahead == 's') ADVANCE(128);
      if (lookahead == 'u') ADVANCE(112);
      if (lookahead == '{') ADVANCE(106);
      if (lookahead == '}') ADVANCE(107);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(3);
      if (lookahead == '\r') SKIP(4);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(3);
      if (lookahead == '\r') SKIP(4);
      if (lookahead == 'U') ADVANCE(94);
      if (lookahead == 'u') ADVANCE(86);
      if (lookahead == 'x') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(165);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(163);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(1);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(1);
      if (lookahead == '\r') SKIP(7);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(2);
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '\r') SKIP(9);
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(21);
      END_STATE();
    case 12:
      if (lookahead == '\n') SKIP(21);
      if (lookahead == '\r') SKIP(11);
      END_STATE();
    case 13:
      if (lookahead == '\n') SKIP(21);
      if (lookahead == '\r') SKIP(11);
      if (lookahead == 'U') ADVANCE(94);
      if (lookahead == 'u') ADVANCE(86);
      if (lookahead == 'x') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(165);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(163);
      END_STATE();
    case 14:
      if (lookahead == '\n') SKIP(21);
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '/') ADVANCE(149);
      if (lookahead == '\\') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0) ADVANCE(153);
      END_STATE();
    case 15:
      if (lookahead == '\n') SKIP(27);
      END_STATE();
    case 16:
      if (lookahead == '\n') SKIP(27);
      if (lookahead == '\r') SKIP(15);
      END_STATE();
    case 17:
      if (lookahead == '\n') SKIP(34);
      END_STATE();
    case 18:
      if (lookahead == '\n') SKIP(34);
      if (lookahead == '\r') SKIP(17);
      END_STATE();
    case 19:
      if (lookahead == '\n') SKIP(35);
      END_STATE();
    case 20:
      if (lookahead == '\n') SKIP(35);
      if (lookahead == '\r') SKIP(19);
      END_STATE();
    case 21:
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == '\\') SKIP(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(21);
      END_STATE();
    case 22:
      if (lookahead == '\'') ADVANCE(23);
      if (lookahead == '\\') ADVANCE(24);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(23);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == '\'') ADVANCE(166);
      END_STATE();
    case 24:
      if (lookahead == '\'') ADVANCE(167);
      if (lookahead == 'U') ADVANCE(26);
      if (lookahead == 'u') ADVANCE(63);
      if (lookahead == 'x') ADVANCE(82);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == '\'') ADVANCE(168);
      END_STATE();
    case 26:
      if (lookahead == '\'') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(93);
      END_STATE();
    case 27:
      if (lookahead == ')') ADVANCE(171);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == '\\') SKIP(16);
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'b') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'i') ADVANCE(37);
      if (lookahead == 'r') ADVANCE(61);
      if (lookahead == 's') ADVANCE(58);
      if (lookahead == 'u') ADVANCE(36);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(27);
      END_STATE();
    case 28:
      if (lookahead == '*') ADVANCE(30);
      if (lookahead == '/') ADVANCE(172);
      END_STATE();
    case 29:
      if (lookahead == '*') ADVANCE(29);
      if (lookahead == '/') ADVANCE(173);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 30:
      if (lookahead == '*') ADVANCE(29);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(71);
      if (lookahead == '0') ADVANCE(136);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 32:
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == '_') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 33:
      if (lookahead == '.') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 34:
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(108);
      if (lookahead == '=') ADVANCE(110);
      if (lookahead == '\\') SKIP(18);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(34);
      END_STATE();
    case 35:
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(43);
      if (lookahead == '\\') SKIP(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 36:
      if (lookahead == '1') ADVANCE(41);
      if (lookahead == '3') ADVANCE(38);
      if (lookahead == '6') ADVANCE(40);
      if (lookahead == '8') ADVANCE(134);
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 37:
      if (lookahead == '1') ADVANCE(41);
      if (lookahead == '3') ADVANCE(38);
      if (lookahead == '6') ADVANCE(40);
      if (lookahead == '8') ADVANCE(134);
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 38:
      if (lookahead == '2') ADVANCE(134);
      END_STATE();
    case 39:
      if (lookahead == '3') ADVANCE(38);
      if (lookahead == '6') ADVANCE(40);
      END_STATE();
    case 40:
      if (lookahead == '4') ADVANCE(134);
      END_STATE();
    case 41:
      if (lookahead == '6') ADVANCE(134);
      END_STATE();
    case 42:
      if (lookahead == ':') ADVANCE(105);
      if (lookahead == '=') ADVANCE(111);
      END_STATE();
    case 43:
      if (lookahead == ':') ADVANCE(104);
      END_STATE();
    case 44:
      if (lookahead == ':') ADVANCE(104);
      if (lookahead == '=') ADVANCE(111);
      END_STATE();
    case 45:
      if (lookahead == '_') ADVANCE(67);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(142);
      END_STATE();
    case 46:
      if (lookahead == '_') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(143);
      END_STATE();
    case 47:
      if (lookahead == '_') ADVANCE(78);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(72);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      END_STATE();
    case 48:
      if (lookahead == '_') ADVANCE(78);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(134);
      END_STATE();
    case 50:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 53:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 54:
      if (lookahead == 'o') ADVANCE(55);
      if (lookahead == 'y') ADVANCE(59);
      END_STATE();
    case 55:
      if (lookahead == 'o') ADVANCE(50);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(134);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(134);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(135);
      END_STATE();
    case 61:
      if (lookahead == 'u') ADVANCE(52);
      END_STATE();
    case 62:
      if (lookahead == 'y') ADVANCE(134);
      END_STATE();
    case 63:
      if (lookahead == '{') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 64:
      if (lookahead == '}') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 65:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 66:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 67:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(142);
      END_STATE();
    case 68:
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(137);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(143);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(163);
      END_STATE();
    case 77:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(84);
      END_STATE();
    case 87:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 88:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      END_STATE();
    case 89:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(87);
      END_STATE();
    case 90:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 91:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(89);
      END_STATE();
    case 92:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(90);
      END_STATE();
    case 93:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(91);
      END_STATE();
    case 94:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(92);
      END_STATE();
    case 95:
      if (eof) ADVANCE(98);
      ADVANCE_MAP(
        0, 101,
        '"', 148,
        '&', 169,
        '\'', 22,
        '(', 170,
        ')', 171,
        ',', 102,
        '-', 31,
        '.', 71,
        '/', 28,
        '0', 136,
        ':', 109,
        ';', 100,
        '=', 110,
      );
      if (lookahead == '\\') SKIP(97);
      if (lookahead == '`') ADVANCE(154);
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead == 'b') ADVANCE(123);
      if (lookahead == 'f') ADVANCE(115);
      if (lookahead == 'i') ADVANCE(113);
      if (lookahead == 'r') ADVANCE(131);
      if (lookahead == 's') ADVANCE(128);
      if (lookahead == 'u') ADVANCE(112);
      if (lookahead == '{') ADVANCE(106);
      if (lookahead == '}') ADVANCE(107);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(95);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 96:
      if (eof) ADVANCE(98);
      if (lookahead == '\n') SKIP(95);
      END_STATE();
    case 97:
      if (eof) ADVANCE(98);
      if (lookahead == '\n') SKIP(95);
      if (lookahead == '\r') SKIP(96);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_COLON_COLON_STAR);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      if (lookahead == '*') ADVANCE(103);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(105);
      if (lookahead == '=') ADVANCE(111);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(117);
      if (lookahead == '3') ADVANCE(114);
      if (lookahead == '6') ADVANCE(116);
      if (lookahead == '8') ADVANCE(133);
      if (lookahead == 'i') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(117);
      if (lookahead == '3') ADVANCE(114);
      if (lookahead == '6') ADVANCE(116);
      if (lookahead == '8') ADVANCE(133);
      if (lookahead == 'n') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3') ADVANCE(114);
      if (lookahead == '6') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(124);
      if (lookahead == 'y') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_primitive_type);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_primitive_type);
      if (lookahead == 'p') ADVANCE(58);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 147,
        '_', 68,
        'B', 45,
        'b', 45,
        'O', 46,
        'o', 46,
        'X', 32,
        'x', 32,
        '8', 138,
        '9', 138,
        'E', 65,
        'P', 65,
        'e', 65,
        'p', 65,
      );
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(137);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(147);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(138);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(147);
      if (lookahead == '_') ADVANCE(70);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(66);
      if (lookahead == '_') ADVANCE(73);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(140);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 66,
        '_', 77,
        '+', 72,
        '-', 72,
        'E', 140,
        'e', 140,
        'P', 65,
        'p', 65,
      );
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(66);
      if (lookahead == '_') ADVANCE(77);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(140);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(141);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(67);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(71);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(74);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(47);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(144);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '/') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(153);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(150);
      if (lookahead == '/') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(151);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(151);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '/') ADVANCE(149);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(152);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(153);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(153);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(162);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(162);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(162);
      if (lookahead == '`') ADVANCE(172);
      if (lookahead != 0) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(160);
      if (lookahead == '/') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(162);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(159);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == '`') ADVANCE(30);
      if (lookahead != 0) ADVANCE(160);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(159);
      if (lookahead == '`') ADVANCE(30);
      if (lookahead != 0) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '/') ADVANCE(158);
      if (lookahead == '\\') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(162);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(162);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(163);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(164);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_byte_literal);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_byte_literal);
      if (lookahead == '\'') ADVANCE(168);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_rune_literal);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(172);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_block_comment);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == '\\') SKIP(1);
      if (lookahead == '_') ADVANCE(2);
      if (lookahead == 'c') ADVANCE(3);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'l') ADVANCE(5);
      if (lookahead == 'm') ADVANCE(6);
      if (lookahead == 'n') ADVANCE(7);
      if (lookahead == 's') ADVANCE(8);
      if (lookahead == 't') ADVANCE(9);
      if (lookahead == 'u') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '\r') SKIP(11);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_ignore_operator);
      END_STATE();
    case 3:
      if (lookahead == 'o') ADVANCE(12);
      if (lookahead == 'p') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 6:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 7:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(19);
      if (lookahead == 't') ADVANCE(20);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 10:
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(0);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 13:
      if (lookahead == 'p') ADVANCE(24);
      END_STATE();
    case 14:
      if (lookahead == 'l') ADVANCE(25);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 17:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 18:
      if (lookahead == 'l') ADVANCE(29);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(30);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(33);
      END_STATE();
    case 23:
      if (lookahead == 's') ADVANCE(34);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_cpp_flag);
      END_STATE();
    case 25:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_nil_literal);
      END_STATE();
    case 30:
      if (lookahead == 'f') ADVANCE(36);
      END_STATE();
    case 31:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 34:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_self);
      END_STATE();
    case 37:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_static);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 14},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 14},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 14},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 27},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 27},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 1},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 27},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 1},
  [77] = {.lex_state = 1},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 27},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 27},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 34},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 27},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 35},
  [95] = {.lex_state = 27},
  [96] = {.lex_state = 34},
  [97] = {.lex_state = 27},
  [98] = {.lex_state = 34},
  [99] = {.lex_state = 27},
  [100] = {.lex_state = 27},
  [101] = {.lex_state = 27},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 27},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 27},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 27},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 161},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_COLON_COLON_STAR] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_self] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_const] = ACTIONS(1),
    [anon_sym_static] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [sym_primitive_type] = ACTIONS(1),
    [sym_integer_literal] = ACTIONS(1),
    [sym_float_literal] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_nil_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_byte_literal] = ACTIONS(1),
    [sym_rune_literal] = ACTIONS(1),
    [sym_cpp_flag] = ACTIONS(1),
    [sym_ignore_operator] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(106),
    [sym__statement] = STATE(77),
    [sym__expression] = STATE(77),
    [sym_use_decl] = STATE(77),
    [sym__var_decl] = STATE(77),
    [sym_let_decl] = STATE(77),
    [sym_single_var] = STATE(79),
    [sym_multi_var] = STATE(79),
    [sym_const_decl] = STATE(77),
    [sym_static_decl] = STATE(77),
    [sym_short_decl] = STATE(77),
    [sym_short_names] = STATE(117),
    [sym_qualified_identifier] = STATE(34),
    [sym__types] = STATE(77),
    [sym__literals] = STATE(77),
    [sym_number_literal] = STATE(77),
    [sym_bool_literal] = STATE(77),
    [sym_string_literal] = STATE(77),
    [sym_raw_string_literal] = STATE(77),
    [sym_ref_pattern] = STATE(83),
    [sym_mut_pattern] = STATE(83),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_use] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
    [anon_sym_const] = ACTIONS(13),
    [anon_sym_static] = ACTIONS(15),
    [sym_primitive_type] = ACTIONS(17),
    [sym_integer_literal] = ACTIONS(19),
    [sym_float_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(21),
    [anon_sym_false] = ACTIONS(21),
    [sym_nil_literal] = ACTIONS(17),
    [anon_sym_DQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [sym_byte_literal] = ACTIONS(17),
    [sym_rune_literal] = ACTIONS(17),
    [sym_cpp_flag] = ACTIONS(27),
    [anon_sym_mut] = ACTIONS(29),
    [anon_sym_AMP] = ACTIONS(31),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__statement] = STATE(77),
    [sym__expression] = STATE(77),
    [sym_use_decl] = STATE(77),
    [sym__var_decl] = STATE(77),
    [sym_let_decl] = STATE(77),
    [sym_single_var] = STATE(79),
    [sym_multi_var] = STATE(79),
    [sym_const_decl] = STATE(77),
    [sym_static_decl] = STATE(77),
    [sym_short_decl] = STATE(77),
    [sym_short_names] = STATE(117),
    [sym_qualified_identifier] = STATE(34),
    [sym__types] = STATE(77),
    [sym__literals] = STATE(77),
    [sym_number_literal] = STATE(77),
    [sym_bool_literal] = STATE(77),
    [sym_string_literal] = STATE(77),
    [sym_raw_string_literal] = STATE(77),
    [sym_ref_pattern] = STATE(83),
    [sym_mut_pattern] = STATE(83),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_identifier] = ACTIONS(35),
    [anon_sym_use] = ACTIONS(38),
    [anon_sym_let] = ACTIONS(41),
    [anon_sym_const] = ACTIONS(44),
    [anon_sym_static] = ACTIONS(47),
    [sym_primitive_type] = ACTIONS(50),
    [sym_integer_literal] = ACTIONS(53),
    [sym_float_literal] = ACTIONS(53),
    [anon_sym_true] = ACTIONS(56),
    [anon_sym_false] = ACTIONS(56),
    [sym_nil_literal] = ACTIONS(50),
    [anon_sym_DQUOTE] = ACTIONS(59),
    [anon_sym_BQUOTE] = ACTIONS(62),
    [sym_byte_literal] = ACTIONS(50),
    [sym_rune_literal] = ACTIONS(50),
    [sym_cpp_flag] = ACTIONS(65),
    [anon_sym_mut] = ACTIONS(68),
    [anon_sym_AMP] = ACTIONS(71),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__statement] = STATE(77),
    [sym__expression] = STATE(77),
    [sym_use_decl] = STATE(77),
    [sym__var_decl] = STATE(77),
    [sym_let_decl] = STATE(77),
    [sym_single_var] = STATE(79),
    [sym_multi_var] = STATE(79),
    [sym_const_decl] = STATE(77),
    [sym_static_decl] = STATE(77),
    [sym_short_decl] = STATE(77),
    [sym_short_names] = STATE(117),
    [sym_qualified_identifier] = STATE(34),
    [sym__types] = STATE(77),
    [sym__literals] = STATE(77),
    [sym_number_literal] = STATE(77),
    [sym_bool_literal] = STATE(77),
    [sym_string_literal] = STATE(77),
    [sym_raw_string_literal] = STATE(77),
    [sym_ref_pattern] = STATE(83),
    [sym_mut_pattern] = STATE(83),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(74),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_use] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
    [anon_sym_const] = ACTIONS(13),
    [anon_sym_static] = ACTIONS(15),
    [sym_primitive_type] = ACTIONS(17),
    [sym_integer_literal] = ACTIONS(19),
    [sym_float_literal] = ACTIONS(19),
    [anon_sym_true] = ACTIONS(21),
    [anon_sym_false] = ACTIONS(21),
    [sym_nil_literal] = ACTIONS(17),
    [anon_sym_DQUOTE] = ACTIONS(23),
    [anon_sym_BQUOTE] = ACTIONS(25),
    [sym_byte_literal] = ACTIONS(17),
    [sym_rune_literal] = ACTIONS(17),
    [sym_cpp_flag] = ACTIONS(27),
    [anon_sym_mut] = ACTIONS(29),
    [anon_sym_AMP] = ACTIONS(31),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    STATE(78), 1,
      sym_expression_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(78), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(27), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [43] = 10,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    STATE(66), 1,
      sym_expression_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(78), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(27), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [86] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(80), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(58), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [126] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(82), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(72), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [166] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(84), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(80), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [206] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(86), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(57), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [246] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(33), 4,
      ts_builtin_sym_end,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_AMP,
    ACTIONS(88), 15,
      anon_sym_use,
      anon_sym_let,
      anon_sym_const,
      anon_sym_static,
      sym_identifier,
      sym_primitive_type,
      sym_integer_literal,
      sym_float_literal,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
      sym_cpp_flag,
      anon_sym_mut,
  [274] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(90), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(61), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [314] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(92), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(67), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [354] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(94), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(69), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [394] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(96), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(55), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [434] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(98), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(82), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [474] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(100), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(73), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [514] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(102), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(84), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [554] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(104), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(81), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [594] = 9,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      anon_sym_BQUOTE,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(34), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(19), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(21), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(106), 4,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(42), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [634] = 7,
    ACTIONS(108), 1,
      anon_sym_LF,
    ACTIONS(112), 1,
      anon_sym_COMMA,
    ACTIONS(114), 1,
      anon_sym_COLON_COLON,
    ACTIONS(116), 1,
      anon_sym_COLON_EQ,
    STATE(71), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(110), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
  [658] = 6,
    ACTIONS(29), 1,
      anon_sym_mut,
    ACTIONS(31), 1,
      anon_sym_AMP,
    ACTIONS(122), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(120), 2,
      sym_identifier,
      sym_ignore_operator,
    STATE(56), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [680] = 8,
    ACTIONS(124), 1,
      sym_identifier,
    ACTIONS(126), 1,
      anon_sym_mut,
    ACTIONS(128), 1,
      anon_sym_AMP,
    ACTIONS(130), 1,
      anon_sym_LPAREN,
    STATE(26), 1,
      sym_ref_pattern,
    STATE(87), 1,
      sym_mut_flag,
    STATE(118), 1,
      sym_tuple_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [706] = 3,
    ACTIONS(132), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(134), 5,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
      anon_sym_COLON_COLON_STAR,
      anon_sym_COLON_COLON,
  [721] = 4,
    ACTIONS(136), 1,
      sym_identifier,
    STATE(31), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(70), 4,
      sym_simple,
      sym_wildcard,
      sym_selector,
      sym_aliased,
  [738] = 5,
    ACTIONS(29), 1,
      anon_sym_mut,
    ACTIONS(31), 1,
      anon_sym_AMP,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(138), 2,
      sym_identifier,
      sym_ignore_operator,
    STATE(91), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [757] = 5,
    ACTIONS(140), 1,
      anon_sym_LF,
    ACTIONS(144), 1,
      anon_sym_COLON,
    ACTIONS(146), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(142), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [775] = 5,
    ACTIONS(148), 1,
      anon_sym_LF,
    ACTIONS(152), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(150), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [793] = 5,
    ACTIONS(154), 1,
      anon_sym_LF,
    ACTIONS(158), 1,
      anon_sym_COLON,
    ACTIONS(160), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(156), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [811] = 5,
    ACTIONS(152), 1,
      anon_sym_COMMA,
    ACTIONS(162), 1,
      anon_sym_LF,
    STATE(33), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(164), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [829] = 5,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(170), 1,
      anon_sym_COLON,
    ACTIONS(172), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(168), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [847] = 5,
    ACTIONS(174), 1,
      anon_sym_LF,
    ACTIONS(178), 1,
      anon_sym_COLON_COLON_STAR,
    ACTIONS(180), 1,
      anon_sym_COLON_COLON,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(176), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [865] = 5,
    ACTIONS(29), 1,
      anon_sym_mut,
    ACTIONS(31), 1,
      anon_sym_AMP,
    ACTIONS(182), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(101), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [883] = 5,
    ACTIONS(184), 1,
      anon_sym_LF,
    ACTIONS(188), 1,
      anon_sym_COMMA,
    STATE(33), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(186), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [901] = 4,
    ACTIONS(108), 1,
      anon_sym_LF,
    ACTIONS(114), 1,
      anon_sym_COLON_COLON,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(110), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [917] = 3,
    ACTIONS(191), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(193), 4,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COLON,
      anon_sym_EQ,
  [931] = 6,
    ACTIONS(126), 1,
      anon_sym_mut,
    ACTIONS(128), 1,
      anon_sym_AMP,
    ACTIONS(195), 1,
      sym_identifier,
    STATE(30), 1,
      sym_ref_pattern,
    STATE(64), 1,
      sym_mut_flag,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [951] = 3,
    ACTIONS(197), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(199), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [964] = 4,
    ACTIONS(201), 1,
      anon_sym_LF,
    ACTIONS(205), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(203), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [979] = 4,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    STATE(50), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(209), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [994] = 4,
    ACTIONS(211), 1,
      anon_sym_LF,
    ACTIONS(215), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(213), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1009] = 3,
    ACTIONS(217), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(219), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1022] = 3,
    ACTIONS(184), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(186), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1035] = 4,
    ACTIONS(174), 1,
      anon_sym_LF,
    ACTIONS(180), 1,
      anon_sym_COLON_COLON,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(176), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1050] = 4,
    ACTIONS(221), 1,
      sym_identifier,
    STATE(43), 1,
      sym_qualified_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(68), 2,
      sym_simple,
      sym_selector,
  [1065] = 3,
    ACTIONS(223), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(225), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1078] = 4,
    ACTIONS(227), 1,
      anon_sym_LF,
    ACTIONS(231), 1,
      anon_sym_EQ,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(229), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1093] = 4,
    ACTIONS(233), 1,
      anon_sym_DQUOTE,
    STATE(39), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(235), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1108] = 3,
    ACTIONS(237), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(239), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1121] = 3,
    ACTIONS(241), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(243), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1134] = 4,
    ACTIONS(245), 1,
      anon_sym_DQUOTE,
    STATE(50), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(247), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1149] = 3,
    ACTIONS(250), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(252), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1161] = 3,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(254), 2,
      anon_sym_self,
      sym_identifier,
  [1173] = 3,
    ACTIONS(258), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(260), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1185] = 4,
    ACTIONS(126), 1,
      anon_sym_mut,
    ACTIONS(262), 1,
      sym_identifier,
    STATE(105), 1,
      sym_mut_flag,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1199] = 3,
    ACTIONS(264), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(266), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1211] = 4,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
    STATE(75), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1225] = 3,
    ACTIONS(272), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(274), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1237] = 3,
    ACTIONS(276), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(278), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1249] = 4,
    ACTIONS(280), 1,
      anon_sym_COMMA,
    ACTIONS(283), 1,
      anon_sym_RBRACE,
    STATE(59), 1,
      aux_sym_selector_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1263] = 3,
    ACTIONS(285), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(287), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1275] = 3,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(291), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1287] = 4,
    ACTIONS(293), 1,
      anon_sym_COMMA,
    ACTIONS(296), 1,
      anon_sym_COLON_EQ,
    STATE(62), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1301] = 4,
    ACTIONS(31), 1,
      anon_sym_AMP,
    ACTIONS(298), 1,
      sym_identifier,
    STATE(65), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1315] = 4,
    ACTIONS(128), 1,
      anon_sym_AMP,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(28), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1329] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(302), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_RPAREN,
  [1339] = 3,
    ACTIONS(304), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(306), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1351] = 3,
    ACTIONS(308), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(310), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1363] = 3,
    ACTIONS(312), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(314), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1375] = 3,
    ACTIONS(316), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(318), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1387] = 3,
    ACTIONS(320), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(322), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1399] = 4,
    ACTIONS(324), 1,
      anon_sym_COMMA,
    ACTIONS(326), 1,
      anon_sym_COLON_EQ,
    STATE(62), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1413] = 3,
    ACTIONS(328), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(330), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1425] = 3,
    ACTIONS(332), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(334), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1437] = 4,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(338), 1,
      anon_sym_RBRACE,
    STATE(59), 1,
      aux_sym_selector_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1451] = 4,
    ACTIONS(268), 1,
      anon_sym_COMMA,
    ACTIONS(340), 1,
      anon_sym_RPAREN,
    STATE(86), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1465] = 3,
    ACTIONS(342), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(344), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1477] = 3,
    ACTIONS(346), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(348), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1489] = 3,
    ACTIONS(350), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(352), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1501] = 3,
    ACTIONS(354), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(356), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1513] = 3,
    ACTIONS(358), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(360), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1525] = 3,
    ACTIONS(362), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(364), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1537] = 3,
    ACTIONS(366), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(368), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1549] = 4,
    ACTIONS(324), 1,
      anon_sym_COMMA,
    ACTIONS(370), 1,
      anon_sym_COLON_EQ,
    STATE(71), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1563] = 3,
    ACTIONS(372), 1,
      anon_sym_LF,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(374), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1575] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(191), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_RPAREN,
  [1585] = 4,
    ACTIONS(376), 1,
      anon_sym_COMMA,
    ACTIONS(379), 1,
      anon_sym_RPAREN,
    STATE(86), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1599] = 4,
    ACTIONS(128), 1,
      anon_sym_AMP,
    ACTIONS(381), 1,
      sym_identifier,
    STATE(30), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1613] = 4,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(383), 1,
      anon_sym_RBRACE,
    STATE(74), 1,
      aux_sym_selector_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1627] = 3,
    ACTIONS(385), 1,
      anon_sym_COLON,
    ACTIONS(387), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1638] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(283), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1647] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(379), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1656] = 3,
    ACTIONS(389), 1,
      sym_primitive_type,
    STATE(38), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1667] = 3,
    ACTIONS(391), 1,
      sym_identifier,
    ACTIONS(393), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1678] = 3,
    ACTIONS(395), 1,
      anon_sym_COLON_COLON,
    ACTIONS(397), 1,
      anon_sym_for,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1689] = 3,
    ACTIONS(399), 1,
      sym_primitive_type,
    STATE(114), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1700] = 3,
    ACTIONS(401), 1,
      anon_sym_COLON,
    ACTIONS(403), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1711] = 3,
    ACTIONS(405), 1,
      sym_primitive_type,
    STATE(115), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1722] = 3,
    ACTIONS(407), 1,
      anon_sym_COLON,
    ACTIONS(409), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1733] = 3,
    ACTIONS(411), 1,
      sym_primitive_type,
    STATE(116), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1744] = 3,
    ACTIONS(413), 1,
      sym_primitive_type,
    STATE(46), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1755] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(296), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [1764] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(415), 2,
      sym_identifier,
      anon_sym_AMP,
  [1773] = 3,
    ACTIONS(417), 1,
      sym_primitive_type,
    STATE(40), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1784] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(419), 2,
      anon_sym_self,
      sym_identifier,
  [1793] = 2,
    ACTIONS(421), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1801] = 2,
    ACTIONS(423), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1809] = 2,
    ACTIONS(425), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1817] = 2,
    ACTIONS(427), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1825] = 2,
    ACTIONS(391), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1833] = 2,
    ACTIONS(429), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1841] = 2,
    ACTIONS(395), 1,
      anon_sym_COLON_COLON,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1849] = 2,
    ACTIONS(431), 1,
      anon_sym_let,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1857] = 2,
    ACTIONS(433), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1865] = 2,
    ACTIONS(435), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1873] = 2,
    ACTIONS(437), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1881] = 2,
    ACTIONS(439), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1889] = 2,
    ACTIONS(441), 1,
      anon_sym_COLON_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1897] = 2,
    ACTIONS(443), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1905] = 2,
    ACTIONS(445), 1,
      aux_sym_raw_string_literal_token1,
    ACTIONS(118), 2,
      sym_line_comment,
      sym_block_comment,
  [1913] = 2,
    ACTIONS(447), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1921] = 2,
    ACTIONS(449), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1929] = 2,
    ACTIONS(451), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 43,
  [SMALL_STATE(6)] = 86,
  [SMALL_STATE(7)] = 126,
  [SMALL_STATE(8)] = 166,
  [SMALL_STATE(9)] = 206,
  [SMALL_STATE(10)] = 246,
  [SMALL_STATE(11)] = 274,
  [SMALL_STATE(12)] = 314,
  [SMALL_STATE(13)] = 354,
  [SMALL_STATE(14)] = 394,
  [SMALL_STATE(15)] = 434,
  [SMALL_STATE(16)] = 474,
  [SMALL_STATE(17)] = 514,
  [SMALL_STATE(18)] = 554,
  [SMALL_STATE(19)] = 594,
  [SMALL_STATE(20)] = 634,
  [SMALL_STATE(21)] = 658,
  [SMALL_STATE(22)] = 680,
  [SMALL_STATE(23)] = 706,
  [SMALL_STATE(24)] = 721,
  [SMALL_STATE(25)] = 738,
  [SMALL_STATE(26)] = 757,
  [SMALL_STATE(27)] = 775,
  [SMALL_STATE(28)] = 793,
  [SMALL_STATE(29)] = 811,
  [SMALL_STATE(30)] = 829,
  [SMALL_STATE(31)] = 847,
  [SMALL_STATE(32)] = 865,
  [SMALL_STATE(33)] = 883,
  [SMALL_STATE(34)] = 901,
  [SMALL_STATE(35)] = 917,
  [SMALL_STATE(36)] = 931,
  [SMALL_STATE(37)] = 951,
  [SMALL_STATE(38)] = 964,
  [SMALL_STATE(39)] = 979,
  [SMALL_STATE(40)] = 994,
  [SMALL_STATE(41)] = 1009,
  [SMALL_STATE(42)] = 1022,
  [SMALL_STATE(43)] = 1035,
  [SMALL_STATE(44)] = 1050,
  [SMALL_STATE(45)] = 1065,
  [SMALL_STATE(46)] = 1078,
  [SMALL_STATE(47)] = 1093,
  [SMALL_STATE(48)] = 1108,
  [SMALL_STATE(49)] = 1121,
  [SMALL_STATE(50)] = 1134,
  [SMALL_STATE(51)] = 1149,
  [SMALL_STATE(52)] = 1161,
  [SMALL_STATE(53)] = 1173,
  [SMALL_STATE(54)] = 1185,
  [SMALL_STATE(55)] = 1199,
  [SMALL_STATE(56)] = 1211,
  [SMALL_STATE(57)] = 1225,
  [SMALL_STATE(58)] = 1237,
  [SMALL_STATE(59)] = 1249,
  [SMALL_STATE(60)] = 1263,
  [SMALL_STATE(61)] = 1275,
  [SMALL_STATE(62)] = 1287,
  [SMALL_STATE(63)] = 1301,
  [SMALL_STATE(64)] = 1315,
  [SMALL_STATE(65)] = 1329,
  [SMALL_STATE(66)] = 1339,
  [SMALL_STATE(67)] = 1351,
  [SMALL_STATE(68)] = 1363,
  [SMALL_STATE(69)] = 1375,
  [SMALL_STATE(70)] = 1387,
  [SMALL_STATE(71)] = 1399,
  [SMALL_STATE(72)] = 1413,
  [SMALL_STATE(73)] = 1425,
  [SMALL_STATE(74)] = 1437,
  [SMALL_STATE(75)] = 1451,
  [SMALL_STATE(76)] = 1465,
  [SMALL_STATE(77)] = 1477,
  [SMALL_STATE(78)] = 1489,
  [SMALL_STATE(79)] = 1501,
  [SMALL_STATE(80)] = 1513,
  [SMALL_STATE(81)] = 1525,
  [SMALL_STATE(82)] = 1537,
  [SMALL_STATE(83)] = 1549,
  [SMALL_STATE(84)] = 1563,
  [SMALL_STATE(85)] = 1575,
  [SMALL_STATE(86)] = 1585,
  [SMALL_STATE(87)] = 1599,
  [SMALL_STATE(88)] = 1613,
  [SMALL_STATE(89)] = 1627,
  [SMALL_STATE(90)] = 1638,
  [SMALL_STATE(91)] = 1647,
  [SMALL_STATE(92)] = 1656,
  [SMALL_STATE(93)] = 1667,
  [SMALL_STATE(94)] = 1678,
  [SMALL_STATE(95)] = 1689,
  [SMALL_STATE(96)] = 1700,
  [SMALL_STATE(97)] = 1711,
  [SMALL_STATE(98)] = 1722,
  [SMALL_STATE(99)] = 1733,
  [SMALL_STATE(100)] = 1744,
  [SMALL_STATE(101)] = 1755,
  [SMALL_STATE(102)] = 1764,
  [SMALL_STATE(103)] = 1773,
  [SMALL_STATE(104)] = 1784,
  [SMALL_STATE(105)] = 1793,
  [SMALL_STATE(106)] = 1801,
  [SMALL_STATE(107)] = 1809,
  [SMALL_STATE(108)] = 1817,
  [SMALL_STATE(109)] = 1825,
  [SMALL_STATE(110)] = 1833,
  [SMALL_STATE(111)] = 1841,
  [SMALL_STATE(112)] = 1849,
  [SMALL_STATE(113)] = 1857,
  [SMALL_STATE(114)] = 1865,
  [SMALL_STATE(115)] = 1873,
  [SMALL_STATE(116)] = 1881,
  [SMALL_STATE(117)] = 1889,
  [SMALL_STATE(118)] = 1897,
  [SMALL_STATE(119)] = 1905,
  [SMALL_STATE(120)] = 1913,
  [SMALL_STATE(121)] = 1921,
  [SMALL_STATE(122)] = 1929,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(113),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(108),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_names, 1, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_identifier, 3, 0, 4),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_qualified_identifier, 3, 0, 4),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 2, 0, 2),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 2, 0, 2),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 1, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_list, 1, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 10),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 10),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 2, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_list, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 3, 0, 3),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 3, 0, 3),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple, 1, 0, 1),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple, 1, 0, 1),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0),
  [188] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_pattern, 2, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ref_pattern, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 7),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 7),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 5, 0, 11),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 5, 0, 11),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 15),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 15),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_literal, 1, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number_literal, 1, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0),
  [247] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector, 4, 0, 1),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_selector, 4, 0, 1),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_wildcard, 2, 0, 1),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_wildcard, 2, 0, 1),
  [262] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 8, 0, 19),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 8, 0, 19),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 7, 0, 18),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 7, 0, 18),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 7, 0, 18),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 7, 0, 18),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_selector_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_selector_repeat1, 2, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector, 6, 0, 17),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_selector, 6, 0, 17),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 16),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 16),
  [293] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_short_names_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_short_names_repeat1, 2, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_pattern, 2, 0, 0),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_decl, 3, 0, 5),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_decl, 3, 0, 5),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 6, 0, 14),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 6, 0, 14),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_aliased, 3, 0, 6),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_aliased, 3, 0, 6),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_decl, 6, 0, 14),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_decl, 6, 0, 14),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_use_decl, 2, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_use_decl, 2, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_names, 2, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 8),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 8),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 14),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 14),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selector, 5, 0, 13),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_selector, 5, 0, 13),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [348] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_var, 4, 0, 9),
  [352] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multi_var, 4, 0, 9),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_decl, 1, 0, 0),
  [356] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_decl, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_decl, 4, 0, 8),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_decl, 4, 0, 8),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 5, 0, 12),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 5, 0, 12),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 4, 0, 8),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 4, 0, 8),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_names, 1, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 5, 0, 12),
  [374] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 5, 0, 12),
  [376] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tuple_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tuple_pattern_repeat1, 2, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_flag, 1, 0, 0),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [423] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 3, 0, 0),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [445] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 2, 0, 0),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 4, 0, 0),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_jule(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
