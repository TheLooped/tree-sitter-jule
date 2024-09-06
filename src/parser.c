#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 118
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 60
#define ALIAS_COUNT 0
#define TOKEN_COUNT 33
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 16

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_LF = 2,
  anon_sym_SEMI = 3,
  anon_sym_NULL = 4,
  anon_sym_COMMA = 5,
  anon_sym_let = 6,
  anon_sym_COLON = 7,
  anon_sym_EQ = 8,
  anon_sym_LPAREN = 9,
  anon_sym_RPAREN = 10,
  anon_sym_const = 11,
  anon_sym_static = 12,
  anon_sym_COLON_EQ = 13,
  sym_primitive_type = 14,
  sym_integer_literal = 15,
  sym_float_literal = 16,
  anon_sym_true = 17,
  anon_sym_false = 18,
  sym_nil_literal = 19,
  anon_sym_DQUOTE = 20,
  aux_sym_string_literal_token1 = 21,
  anon_sym_BQUOTE = 22,
  aux_sym_raw_string_literal_token1 = 23,
  sym_escape_sequence = 24,
  sym_byte_literal = 25,
  sym_rune_literal = 26,
  sym_cpp_flag = 27,
  sym_ignore_operator = 28,
  anon_sym_mut = 29,
  anon_sym_AMP = 30,
  sym_line_comment = 31,
  sym_block_comment = 32,
  sym_source_file = 33,
  sym__statement = 34,
  sym__expression = 35,
  sym_expression_list = 36,
  sym__var_decl = 37,
  sym_let_decl = 38,
  sym_single_var = 39,
  sym_multi_var = 40,
  sym_const_decl = 41,
  sym_static_decl = 42,
  sym_short_decl = 43,
  sym_short_names = 44,
  sym__types = 45,
  sym__literals = 46,
  sym_number_literal = 47,
  sym_bool_literal = 48,
  sym_string_literal = 49,
  sym_raw_string_literal = 50,
  sym_mut_flag = 51,
  sym_ref_pattern = 52,
  sym_mut_pattern = 53,
  sym_tuple_pattern = 54,
  aux_sym_source_file_repeat1 = 55,
  aux_sym_expression_list_repeat1 = 56,
  aux_sym_short_names_repeat1 = 57,
  aux_sym_string_literal_repeat1 = 58,
  aux_sym_tuple_pattern_repeat1 = 59,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LF] = "\n",
  [anon_sym_SEMI] = ";",
  [anon_sym_NULL] = "\0",
  [anon_sym_COMMA] = ",",
  [anon_sym_let] = "let",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
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
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_expression_list] = "expression_list",
  [sym__var_decl] = "_var_decl",
  [sym_let_decl] = "let_decl",
  [sym_single_var] = "single_var",
  [sym_multi_var] = "multi_var",
  [sym_const_decl] = "const_decl",
  [sym_static_decl] = "static_decl",
  [sym_short_decl] = "short_decl",
  [sym_short_names] = "short_names",
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
  [anon_sym_let] = anon_sym_let,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
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
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_expression_list] = sym_expression_list,
  [sym__var_decl] = sym__var_decl,
  [sym_let_decl] = sym_let_decl,
  [sym_single_var] = sym_single_var,
  [sym_multi_var] = sym_multi_var,
  [sym_const_decl] = sym_const_decl,
  [sym_static_decl] = sym_static_decl,
  [sym_short_decl] = sym_short_decl,
  [sym_short_names] = sym_short_names,
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
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
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
  field_name = 1,
  field_names = 2,
  field_pattern = 3,
  field_type = 4,
  field_value = 5,
  field_values = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_names] = "names",
  [field_pattern] = "pattern",
  [field_type] = "type",
  [field_value] = "value",
  [field_values] = "values",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 1},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 2},
  [10] = {.index = 15, .length = 3},
  [11] = {.index = 18, .length = 4},
  [12] = {.index = 22, .length = 2},
  [13] = {.index = 24, .length = 2},
  [14] = {.index = 26, .length = 3},
  [15] = {.index = 29, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 2},
  [2] =
    {field_names, 0},
    {field_values, 2},
  [4] =
    {field_name, 1},
    {field_type, 3},
  [6] =
    {field_name, 1},
    {field_value, 3},
  [8] =
    {field_pattern, 1},
    {field_values, 3},
  [10] =
    {field_name, 3},
  [11] =
    {field_name, 2},
    {field_type, 4},
  [13] =
    {field_name, 2},
    {field_value, 4},
  [15] =
    {field_name, 1},
    {field_type, 3},
    {field_value, 5},
  [18] =
    {field_pattern, 1},
    {field_values, 3},
    {field_values, 4},
    {field_values, 5},
  [22] =
    {field_name, 3},
    {field_type, 5},
  [24] =
    {field_name, 3},
    {field_value, 5},
  [26] =
    {field_name, 2},
    {field_type, 4},
    {field_value, 6},
  [29] =
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
  [10] = 7,
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
  [40] = 37,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 38,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 28,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 29,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 34,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 30,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 46,
  [83] = 83,
  [84] = 39,
  [85] = 48,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 35,
  [92] = 92,
  [93] = 42,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 41,
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
  [114] = 101,
  [115] = 115,
  [116] = 113,
  [117] = 102,
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
      if (eof) ADVANCE(93);
      ADVANCE_MAP(
        0, 96,
        '"', 140,
        '&', 161,
        '\'', 20,
        '(', 101,
        ')', 102,
        ',', 97,
        '-', 29,
        '.', 66,
        '/', 26,
        '0', 128,
        ':', 99,
        ';', 95,
        '=', 100,
        '\\', 6,
        '`', 146,
        'a', 112,
        'b', 115,
        'f', 107,
        'i', 105,
        'r', 123,
        's', 120,
        'u', 104,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(90);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(96);
      if (lookahead == '\n') ADVANCE(94);
      if (lookahead == ',') ADVANCE(97);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == ';') ADVANCE(95);
      if (lookahead == '=') ADVANCE(100);
      if (lookahead == '\\') SKIP(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if ((!eof && lookahead == 00)) ADVANCE(96);
      if (lookahead == '\n') ADVANCE(94);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == ':') ADVANCE(98);
      if (lookahead == ';') ADVANCE(95);
      if (lookahead == '=') ADVANCE(100);
      if (lookahead == '\\') SKIP(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        0, 96,
        '"', 140,
        '&', 161,
        '\'', 20,
        '(', 101,
        ')', 102,
        ',', 97,
        '-', 29,
        '.', 66,
        '/', 26,
        '0', 128,
        ':', 99,
        ';', 95,
        '=', 100,
      );
      if (lookahead == '\\') SKIP(5);
      if (lookahead == '`') ADVANCE(146);
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 'b') ADVANCE(115);
      if (lookahead == 'f') ADVANCE(107);
      if (lookahead == 'i') ADVANCE(105);
      if (lookahead == 'r') ADVANCE(123);
      if (lookahead == 's') ADVANCE(120);
      if (lookahead == 'u') ADVANCE(104);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(125);
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
      if (lookahead == 'U') ADVANCE(89);
      if (lookahead == 'u') ADVANCE(81);
      if (lookahead == 'x') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(157);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(155);
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
      if (lookahead == '\n') SKIP(19);
      END_STATE();
    case 12:
      if (lookahead == '\n') SKIP(19);
      if (lookahead == '\r') SKIP(11);
      END_STATE();
    case 13:
      if (lookahead == '\n') SKIP(19);
      if (lookahead == '\r') SKIP(11);
      if (lookahead == 'U') ADVANCE(89);
      if (lookahead == 'u') ADVANCE(81);
      if (lookahead == 'x') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(157);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(155);
      END_STATE();
    case 14:
      if (lookahead == '\n') SKIP(19);
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '/') ADVANCE(141);
      if (lookahead == '\\') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 15:
      if (lookahead == '\n') SKIP(25);
      END_STATE();
    case 16:
      if (lookahead == '\n') SKIP(25);
      if (lookahead == '\r') SKIP(15);
      END_STATE();
    case 17:
      if (lookahead == '\n') SKIP(32);
      END_STATE();
    case 18:
      if (lookahead == '\n') SKIP(32);
      if (lookahead == '\r') SKIP(17);
      END_STATE();
    case 19:
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == '\\') SKIP(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      END_STATE();
    case 20:
      if (lookahead == '\'') ADVANCE(21);
      if (lookahead == '\\') ADVANCE(22);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(21);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == '\'') ADVANCE(158);
      END_STATE();
    case 22:
      if (lookahead == '\'') ADVANCE(159);
      if (lookahead == 'U') ADVANCE(24);
      if (lookahead == 'u') ADVANCE(58);
      if (lookahead == 'x') ADVANCE(77);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 23:
      if (lookahead == '\'') ADVANCE(160);
      END_STATE();
    case 24:
      if (lookahead == '\'') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 25:
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == ',') ADVANCE(97);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == '\\') SKIP(16);
      if (lookahead == 'a') ADVANCE(46);
      if (lookahead == 'b') ADVANCE(49);
      if (lookahead == 'f') ADVANCE(36);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'r') ADVANCE(56);
      if (lookahead == 's') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(33);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(25);
      END_STATE();
    case 26:
      if (lookahead == '*') ADVANCE(28);
      if (lookahead == '/') ADVANCE(162);
      END_STATE();
    case 27:
      if (lookahead == '*') ADVANCE(27);
      if (lookahead == '/') ADVANCE(163);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 28:
      if (lookahead == '*') ADVANCE(27);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 29:
      if (lookahead == '.') ADVANCE(66);
      if (lookahead == '0') ADVANCE(128);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(73);
      if (lookahead == '_') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 32:
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == ':') ADVANCE(98);
      if (lookahead == '=') ADVANCE(100);
      if (lookahead == '\\') SKIP(18);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(32);
      END_STATE();
    case 33:
      if (lookahead == '1') ADVANCE(38);
      if (lookahead == '3') ADVANCE(35);
      if (lookahead == '6') ADVANCE(37);
      if (lookahead == '8') ADVANCE(126);
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 34:
      if (lookahead == '1') ADVANCE(38);
      if (lookahead == '3') ADVANCE(35);
      if (lookahead == '6') ADVANCE(37);
      if (lookahead == '8') ADVANCE(126);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 35:
      if (lookahead == '2') ADVANCE(126);
      END_STATE();
    case 36:
      if (lookahead == '3') ADVANCE(35);
      if (lookahead == '6') ADVANCE(37);
      END_STATE();
    case 37:
      if (lookahead == '4') ADVANCE(126);
      END_STATE();
    case 38:
      if (lookahead == '6') ADVANCE(126);
      END_STATE();
    case 39:
      if (lookahead == '=') ADVANCE(103);
      END_STATE();
    case 40:
      if (lookahead == '_') ADVANCE(62);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(134);
      END_STATE();
    case 41:
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(135);
      END_STATE();
    case 42:
      if (lookahead == '_') ADVANCE(73);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(67);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 43:
      if (lookahead == '_') ADVANCE(73);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(126);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(50);
      if (lookahead == 'y') ADVANCE(54);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(45);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(126);
      END_STATE();
    case 52:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(127);
      END_STATE();
    case 56:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 57:
      if (lookahead == 'y') ADVANCE(126);
      END_STATE();
    case 58:
      if (lookahead == '{') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 59:
      if (lookahead == '}') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 60:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 61:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 62:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(134);
      END_STATE();
    case 63:
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(129);
      END_STATE();
    case 64:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(135);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(155);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(71);
      END_STATE();
    case 77:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(76);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
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
      if (eof) ADVANCE(93);
      ADVANCE_MAP(
        0, 96,
        '"', 140,
        '&', 161,
        '\'', 20,
        '(', 101,
        ')', 102,
        ',', 97,
        '-', 29,
        '.', 66,
        '/', 26,
        '0', 128,
        ':', 99,
        ';', 95,
        '=', 100,
      );
      if (lookahead == '\\') SKIP(92);
      if (lookahead == '`') ADVANCE(146);
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 'b') ADVANCE(115);
      if (lookahead == 'f') ADVANCE(107);
      if (lookahead == 'i') ADVANCE(105);
      if (lookahead == 'r') ADVANCE(123);
      if (lookahead == 's') ADVANCE(120);
      if (lookahead == 'u') ADVANCE(104);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(90);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 91:
      if (eof) ADVANCE(93);
      if (lookahead == '\n') SKIP(90);
      END_STATE();
    case 92:
      if (eof) ADVANCE(93);
      if (lookahead == '\n') SKIP(90);
      if (lookahead == '\r') SKIP(91);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(103);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(109);
      if (lookahead == '3') ADVANCE(106);
      if (lookahead == '6') ADVANCE(108);
      if (lookahead == '8') ADVANCE(125);
      if (lookahead == 'i') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1') ADVANCE(109);
      if (lookahead == '3') ADVANCE(106);
      if (lookahead == '6') ADVANCE(108);
      if (lookahead == '8') ADVANCE(125);
      if (lookahead == 'n') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3') ADVANCE(106);
      if (lookahead == '6') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(116);
      if (lookahead == 'y') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_primitive_type);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_primitive_type);
      if (lookahead == 'p') ADVANCE(53);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 139,
        '_', 63,
        'B', 40,
        'b', 40,
        'O', 41,
        'o', 41,
        'X', 30,
        'x', 30,
        '8', 130,
        '9', 130,
        'E', 60,
        'P', 60,
        'e', 60,
        'p', 60,
      );
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(129);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == '_') ADVANCE(63);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(130);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == '_') ADVANCE(65);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(61);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 61,
        '_', 72,
        '+', 67,
        '-', 67,
        'E', 132,
        'e', 132,
        'P', 60,
        'p', 60,
      );
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(61);
      if (lookahead == '_') ADVANCE(72);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(62);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(66);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(69);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '/') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(143);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '/') ADVANCE(141);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(153);
      if (lookahead == '\r') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(154);
      if (lookahead == '`') ADVANCE(162);
      if (lookahead != 0) ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(152);
      if (lookahead == '/') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '/') ADVANCE(154);
      if (lookahead == '`') ADVANCE(28);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '`') ADVANCE(28);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '/') ADVANCE(150);
      if (lookahead == '\\') ADVANCE(147);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(154);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(155);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(156);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_byte_literal);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_byte_literal);
      if (lookahead == '\'') ADVANCE(160);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_rune_literal);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(162);
      END_STATE();
    case 163:
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
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '\r') SKIP(10);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_ignore_operator);
      END_STATE();
    case 3:
      if (lookahead == 'o') ADVANCE(11);
      if (lookahead == 'p') ADVANCE(12);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 6:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 7:
      if (lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(0);
      END_STATE();
    case 11:
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 12:
      if (lookahead == 'p') ADVANCE(20);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 15:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 19:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_cpp_flag);
      END_STATE();
    case 21:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_nil_literal);
      END_STATE();
    case 25:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 33:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 34:
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
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 14},
  [37] = {.lex_state = 14},
  [38] = {.lex_state = 14},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 14},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 14},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 25},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 25},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 25},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 25},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 1},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 25},
  [81] = {.lex_state = 25},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 25},
  [87] = {.lex_state = 25},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 25},
  [90] = {.lex_state = 25},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 32},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 32},
  [95] = {.lex_state = 25},
  [96] = {.lex_state = 32},
  [97] = {.lex_state = 25},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 153},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 25},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 153},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
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
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(106),
    [sym__statement] = STATE(79),
    [sym__expression] = STATE(79),
    [sym__var_decl] = STATE(79),
    [sym_let_decl] = STATE(79),
    [sym_single_var] = STATE(77),
    [sym_multi_var] = STATE(77),
    [sym_const_decl] = STATE(79),
    [sym_static_decl] = STATE(79),
    [sym_short_decl] = STATE(79),
    [sym_short_names] = STATE(110),
    [sym__types] = STATE(79),
    [sym__literals] = STATE(79),
    [sym_number_literal] = STATE(79),
    [sym_bool_literal] = STATE(79),
    [sym_string_literal] = STATE(79),
    [sym_raw_string_literal] = STATE(79),
    [sym_ref_pattern] = STATE(73),
    [sym_mut_pattern] = STATE(73),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_let] = ACTIONS(9),
    [anon_sym_const] = ACTIONS(11),
    [anon_sym_static] = ACTIONS(13),
    [sym_primitive_type] = ACTIONS(15),
    [sym_integer_literal] = ACTIONS(17),
    [sym_float_literal] = ACTIONS(17),
    [anon_sym_true] = ACTIONS(19),
    [anon_sym_false] = ACTIONS(19),
    [sym_nil_literal] = ACTIONS(15),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [anon_sym_BQUOTE] = ACTIONS(23),
    [sym_byte_literal] = ACTIONS(15),
    [sym_rune_literal] = ACTIONS(15),
    [sym_cpp_flag] = ACTIONS(25),
    [anon_sym_mut] = ACTIONS(27),
    [anon_sym_AMP] = ACTIONS(29),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__statement] = STATE(79),
    [sym__expression] = STATE(79),
    [sym__var_decl] = STATE(79),
    [sym_let_decl] = STATE(79),
    [sym_single_var] = STATE(77),
    [sym_multi_var] = STATE(77),
    [sym_const_decl] = STATE(79),
    [sym_static_decl] = STATE(79),
    [sym_short_decl] = STATE(79),
    [sym_short_names] = STATE(110),
    [sym__types] = STATE(79),
    [sym__literals] = STATE(79),
    [sym_number_literal] = STATE(79),
    [sym_bool_literal] = STATE(79),
    [sym_string_literal] = STATE(79),
    [sym_raw_string_literal] = STATE(79),
    [sym_ref_pattern] = STATE(73),
    [sym_mut_pattern] = STATE(73),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym_identifier] = ACTIONS(33),
    [anon_sym_let] = ACTIONS(36),
    [anon_sym_const] = ACTIONS(39),
    [anon_sym_static] = ACTIONS(42),
    [sym_primitive_type] = ACTIONS(45),
    [sym_integer_literal] = ACTIONS(48),
    [sym_float_literal] = ACTIONS(48),
    [anon_sym_true] = ACTIONS(51),
    [anon_sym_false] = ACTIONS(51),
    [sym_nil_literal] = ACTIONS(45),
    [anon_sym_DQUOTE] = ACTIONS(54),
    [anon_sym_BQUOTE] = ACTIONS(57),
    [sym_byte_literal] = ACTIONS(45),
    [sym_rune_literal] = ACTIONS(45),
    [sym_cpp_flag] = ACTIONS(60),
    [anon_sym_mut] = ACTIONS(63),
    [anon_sym_AMP] = ACTIONS(66),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__statement] = STATE(79),
    [sym__expression] = STATE(79),
    [sym__var_decl] = STATE(79),
    [sym_let_decl] = STATE(79),
    [sym_single_var] = STATE(77),
    [sym_multi_var] = STATE(77),
    [sym_const_decl] = STATE(79),
    [sym_static_decl] = STATE(79),
    [sym_short_decl] = STATE(79),
    [sym_short_names] = STATE(110),
    [sym__types] = STATE(79),
    [sym__literals] = STATE(79),
    [sym_number_literal] = STATE(79),
    [sym_bool_literal] = STATE(79),
    [sym_string_literal] = STATE(79),
    [sym_raw_string_literal] = STATE(79),
    [sym_ref_pattern] = STATE(73),
    [sym_mut_pattern] = STATE(73),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(69),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_let] = ACTIONS(9),
    [anon_sym_const] = ACTIONS(11),
    [anon_sym_static] = ACTIONS(13),
    [sym_primitive_type] = ACTIONS(15),
    [sym_integer_literal] = ACTIONS(17),
    [sym_float_literal] = ACTIONS(17),
    [anon_sym_true] = ACTIONS(19),
    [anon_sym_false] = ACTIONS(19),
    [sym_nil_literal] = ACTIONS(15),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [anon_sym_BQUOTE] = ACTIONS(23),
    [sym_byte_literal] = ACTIONS(15),
    [sym_rune_literal] = ACTIONS(15),
    [sym_cpp_flag] = ACTIONS(25),
    [anon_sym_mut] = ACTIONS(27),
    [anon_sym_AMP] = ACTIONS(29),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_LPAREN,
    STATE(65), 1,
      sym_expression_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(71), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(30), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [41] = 8,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    STATE(49), 1,
      sym_expression_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(71), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(30), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [79] = 8,
    ACTIONS(81), 1,
      anon_sym_DQUOTE,
    ACTIONS(83), 1,
      anon_sym_BQUOTE,
    STATE(107), 1,
      sym_expression_list,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(77), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(79), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(75), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(75), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [117] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(85), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(35), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [152] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(87), 5,
      sym_identifier,
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
  [187] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(89), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(54), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [222] = 7,
    ACTIONS(81), 1,
      anon_sym_DQUOTE,
    ACTIONS(83), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(77), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(79), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(91), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(91), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [257] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(93), 5,
      sym_identifier,
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
  [292] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(95), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(63), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [327] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(97), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(50), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [362] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(99), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(70), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [397] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(101), 5,
      sym_identifier,
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
  [432] = 3,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(31), 4,
      ts_builtin_sym_end,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_AMP,
    ACTIONS(103), 14,
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
  [459] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(105), 5,
      sym_identifier,
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
  [494] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(107), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(53), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [529] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(109), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(64), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [564] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(111), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(51), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [599] = 7,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(17), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(19), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(113), 5,
      sym_identifier,
      sym_primitive_type,
      sym_nil_literal,
      sym_byte_literal,
      sym_rune_literal,
    STATE(78), 7,
      sym__expression,
      sym__types,
      sym__literals,
      sym_number_literal,
      sym_bool_literal,
      sym_string_literal,
      sym_raw_string_literal,
  [634] = 8,
    ACTIONS(115), 1,
      sym_identifier,
    ACTIONS(117), 1,
      anon_sym_LPAREN,
    ACTIONS(119), 1,
      anon_sym_mut,
    ACTIONS(121), 1,
      anon_sym_AMP,
    STATE(26), 1,
      sym_ref_pattern,
    STATE(71), 1,
      sym_mut_flag,
    STATE(112), 1,
      sym_tuple_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [660] = 6,
    ACTIONS(27), 1,
      anon_sym_mut,
    ACTIONS(29), 1,
      anon_sym_AMP,
    ACTIONS(125), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(123), 2,
      sym_identifier,
      sym_ignore_operator,
    STATE(62), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [682] = 5,
    ACTIONS(27), 1,
      anon_sym_mut,
    ACTIONS(29), 1,
      anon_sym_AMP,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(127), 2,
      sym_identifier,
      sym_ignore_operator,
    STATE(83), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [701] = 6,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(133), 1,
      anon_sym_COMMA,
    ACTIONS(135), 1,
      anon_sym_COLON_EQ,
    STATE(58), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(131), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
  [722] = 5,
    ACTIONS(139), 1,
      anon_sym_LF,
    ACTIONS(143), 1,
      anon_sym_COLON,
    ACTIONS(145), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(141), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [740] = 5,
    ACTIONS(27), 1,
      anon_sym_mut,
    ACTIONS(29), 1,
      anon_sym_AMP,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    STATE(95), 2,
      sym_ref_pattern,
      sym_mut_pattern,
  [758] = 3,
    ACTIONS(149), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(151), 4,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COLON,
      anon_sym_EQ,
  [772] = 5,
    ACTIONS(153), 1,
      anon_sym_LF,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(155), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [790] = 5,
    ACTIONS(160), 1,
      anon_sym_LF,
    ACTIONS(164), 1,
      anon_sym_COMMA,
    STATE(34), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(162), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [808] = 5,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(170), 1,
      anon_sym_COLON,
    ACTIONS(172), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(168), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [826] = 6,
    ACTIONS(119), 1,
      anon_sym_mut,
    ACTIONS(121), 1,
      anon_sym_AMP,
    ACTIONS(174), 1,
      sym_identifier,
    STATE(33), 1,
      sym_ref_pattern,
    STATE(56), 1,
      sym_mut_flag,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [846] = 5,
    ACTIONS(176), 1,
      anon_sym_LF,
    ACTIONS(180), 1,
      anon_sym_COLON,
    ACTIONS(182), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(178), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [864] = 5,
    ACTIONS(164), 1,
      anon_sym_COMMA,
    ACTIONS(184), 1,
      anon_sym_LF,
    STATE(29), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(186), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [882] = 3,
    ACTIONS(153), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(155), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [895] = 4,
    ACTIONS(188), 1,
      anon_sym_DQUOTE,
    STATE(36), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(190), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [910] = 4,
    ACTIONS(193), 1,
      anon_sym_DQUOTE,
    STATE(36), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(195), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [925] = 4,
    ACTIONS(197), 1,
      anon_sym_DQUOTE,
    STATE(37), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(199), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [940] = 3,
    ACTIONS(201), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(203), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [953] = 4,
    ACTIONS(205), 1,
      anon_sym_DQUOTE,
    STATE(36), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(195), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [968] = 3,
    ACTIONS(207), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(209), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [981] = 3,
    ACTIONS(211), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(213), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [994] = 4,
    ACTIONS(215), 1,
      anon_sym_LF,
    ACTIONS(219), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(217), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1009] = 4,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    STATE(40), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(223), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1024] = 4,
    ACTIONS(225), 1,
      anon_sym_LF,
    ACTIONS(229), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(227), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1039] = 3,
    ACTIONS(231), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(233), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1052] = 4,
    ACTIONS(235), 1,
      anon_sym_LF,
    ACTIONS(239), 1,
      anon_sym_EQ,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(237), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1067] = 3,
    ACTIONS(241), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(243), 3,
      anon_sym_SEMI,
      anon_sym_NULL,
      anon_sym_COMMA,
  [1080] = 3,
    ACTIONS(245), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(247), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1092] = 3,
    ACTIONS(249), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(251), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1104] = 3,
    ACTIONS(253), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(255), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1116] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(149), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
  [1126] = 3,
    ACTIONS(257), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(259), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1138] = 3,
    ACTIONS(261), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(263), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1150] = 4,
    ACTIONS(265), 1,
      anon_sym_COMMA,
    ACTIONS(268), 1,
      anon_sym_COLON_EQ,
    STATE(55), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1164] = 4,
    ACTIONS(121), 1,
      anon_sym_AMP,
    ACTIONS(270), 1,
      sym_identifier,
    STATE(31), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1178] = 3,
    ACTIONS(272), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(274), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1190] = 4,
    ACTIONS(276), 1,
      anon_sym_COMMA,
    ACTIONS(278), 1,
      anon_sym_COLON_EQ,
    STATE(55), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1204] = 4,
    ACTIONS(153), 1,
      anon_sym_RPAREN,
    ACTIONS(280), 1,
      anon_sym_COMMA,
    STATE(59), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1218] = 4,
    ACTIONS(283), 1,
      anon_sym_COMMA,
    ACTIONS(285), 1,
      anon_sym_RPAREN,
    STATE(76), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1232] = 3,
    ACTIONS(287), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(289), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1244] = 4,
    ACTIONS(283), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1258] = 3,
    ACTIONS(293), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(295), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1270] = 3,
    ACTIONS(297), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(299), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1282] = 3,
    ACTIONS(301), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(303), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1294] = 3,
    ACTIONS(305), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(307), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1306] = 3,
    ACTIONS(309), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(311), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1318] = 4,
    ACTIONS(184), 1,
      anon_sym_RPAREN,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    STATE(59), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1332] = 3,
    ACTIONS(315), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(317), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1344] = 3,
    ACTIONS(319), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(321), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1356] = 4,
    ACTIONS(121), 1,
      anon_sym_AMP,
    ACTIONS(323), 1,
      sym_identifier,
    STATE(33), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1370] = 4,
    ACTIONS(29), 1,
      anon_sym_AMP,
    ACTIONS(325), 1,
      sym_identifier,
    STATE(80), 1,
      sym_ref_pattern,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1384] = 4,
    ACTIONS(276), 1,
      anon_sym_COMMA,
    ACTIONS(327), 1,
      anon_sym_COLON_EQ,
    STATE(58), 1,
      aux_sym_short_names_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1398] = 4,
    ACTIONS(119), 1,
      anon_sym_mut,
    ACTIONS(329), 1,
      sym_identifier,
    STATE(108), 1,
      sym_mut_flag,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1412] = 4,
    ACTIONS(160), 1,
      anon_sym_RPAREN,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    STATE(68), 1,
      aux_sym_expression_list_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1426] = 4,
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    STATE(76), 1,
      aux_sym_tuple_pattern_repeat1,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1440] = 3,
    ACTIONS(336), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(338), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1452] = 3,
    ACTIONS(340), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(342), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1464] = 3,
    ACTIONS(344), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(346), 2,
      anon_sym_SEMI,
      anon_sym_NULL,
  [1476] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(348), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON_EQ,
  [1486] = 3,
    ACTIONS(350), 1,
      sym_primitive_type,
    STATE(45), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1497] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(231), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1506] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(334), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1515] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(201), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1524] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(241), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1533] = 3,
    ACTIONS(352), 1,
      sym_primitive_type,
    STATE(43), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1544] = 3,
    ACTIONS(354), 1,
      sym_primitive_type,
    STATE(99), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1555] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(356), 2,
      sym_identifier,
      anon_sym_AMP,
  [1564] = 3,
    ACTIONS(358), 1,
      sym_primitive_type,
    STATE(105), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1575] = 3,
    ACTIONS(360), 1,
      sym_primitive_type,
    STATE(47), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1586] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(153), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1595] = 3,
    ACTIONS(362), 1,
      anon_sym_COLON,
    ACTIONS(364), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1606] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(211), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1615] = 3,
    ACTIONS(366), 1,
      anon_sym_COLON,
    ACTIONS(368), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1626] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(268), 2,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
  [1635] = 3,
    ACTIONS(370), 1,
      anon_sym_COLON,
    ACTIONS(372), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1646] = 3,
    ACTIONS(374), 1,
      sym_primitive_type,
    STATE(111), 1,
      sym__types,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1657] = 2,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(207), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1666] = 2,
    ACTIONS(376), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1674] = 2,
    ACTIONS(378), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1682] = 2,
    ACTIONS(380), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1690] = 2,
    ACTIONS(382), 1,
      aux_sym_raw_string_literal_token1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
  [1698] = 2,
    ACTIONS(384), 1,
      anon_sym_let,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1706] = 2,
    ACTIONS(386), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1714] = 2,
    ACTIONS(388), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1722] = 2,
    ACTIONS(390), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1730] = 2,
    ACTIONS(392), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1738] = 2,
    ACTIONS(394), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1746] = 2,
    ACTIONS(396), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1754] = 2,
    ACTIONS(398), 1,
      anon_sym_COLON_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1762] = 2,
    ACTIONS(400), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1770] = 2,
    ACTIONS(402), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1778] = 2,
    ACTIONS(404), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1786] = 2,
    ACTIONS(406), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1794] = 2,
    ACTIONS(408), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1802] = 2,
    ACTIONS(410), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [1810] = 2,
    ACTIONS(412), 1,
      aux_sym_raw_string_literal_token1,
    ACTIONS(137), 2,
      sym_line_comment,
      sym_block_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 41,
  [SMALL_STATE(6)] = 79,
  [SMALL_STATE(7)] = 117,
  [SMALL_STATE(8)] = 152,
  [SMALL_STATE(9)] = 187,
  [SMALL_STATE(10)] = 222,
  [SMALL_STATE(11)] = 257,
  [SMALL_STATE(12)] = 292,
  [SMALL_STATE(13)] = 327,
  [SMALL_STATE(14)] = 362,
  [SMALL_STATE(15)] = 397,
  [SMALL_STATE(16)] = 432,
  [SMALL_STATE(17)] = 459,
  [SMALL_STATE(18)] = 494,
  [SMALL_STATE(19)] = 529,
  [SMALL_STATE(20)] = 564,
  [SMALL_STATE(21)] = 599,
  [SMALL_STATE(22)] = 634,
  [SMALL_STATE(23)] = 660,
  [SMALL_STATE(24)] = 682,
  [SMALL_STATE(25)] = 701,
  [SMALL_STATE(26)] = 722,
  [SMALL_STATE(27)] = 740,
  [SMALL_STATE(28)] = 758,
  [SMALL_STATE(29)] = 772,
  [SMALL_STATE(30)] = 790,
  [SMALL_STATE(31)] = 808,
  [SMALL_STATE(32)] = 826,
  [SMALL_STATE(33)] = 846,
  [SMALL_STATE(34)] = 864,
  [SMALL_STATE(35)] = 882,
  [SMALL_STATE(36)] = 895,
  [SMALL_STATE(37)] = 910,
  [SMALL_STATE(38)] = 925,
  [SMALL_STATE(39)] = 940,
  [SMALL_STATE(40)] = 953,
  [SMALL_STATE(41)] = 968,
  [SMALL_STATE(42)] = 981,
  [SMALL_STATE(43)] = 994,
  [SMALL_STATE(44)] = 1009,
  [SMALL_STATE(45)] = 1024,
  [SMALL_STATE(46)] = 1039,
  [SMALL_STATE(47)] = 1052,
  [SMALL_STATE(48)] = 1067,
  [SMALL_STATE(49)] = 1080,
  [SMALL_STATE(50)] = 1092,
  [SMALL_STATE(51)] = 1104,
  [SMALL_STATE(52)] = 1116,
  [SMALL_STATE(53)] = 1126,
  [SMALL_STATE(54)] = 1138,
  [SMALL_STATE(55)] = 1150,
  [SMALL_STATE(56)] = 1164,
  [SMALL_STATE(57)] = 1178,
  [SMALL_STATE(58)] = 1190,
  [SMALL_STATE(59)] = 1204,
  [SMALL_STATE(60)] = 1218,
  [SMALL_STATE(61)] = 1232,
  [SMALL_STATE(62)] = 1244,
  [SMALL_STATE(63)] = 1258,
  [SMALL_STATE(64)] = 1270,
  [SMALL_STATE(65)] = 1282,
  [SMALL_STATE(66)] = 1294,
  [SMALL_STATE(67)] = 1306,
  [SMALL_STATE(68)] = 1318,
  [SMALL_STATE(69)] = 1332,
  [SMALL_STATE(70)] = 1344,
  [SMALL_STATE(71)] = 1356,
  [SMALL_STATE(72)] = 1370,
  [SMALL_STATE(73)] = 1384,
  [SMALL_STATE(74)] = 1398,
  [SMALL_STATE(75)] = 1412,
  [SMALL_STATE(76)] = 1426,
  [SMALL_STATE(77)] = 1440,
  [SMALL_STATE(78)] = 1452,
  [SMALL_STATE(79)] = 1464,
  [SMALL_STATE(80)] = 1476,
  [SMALL_STATE(81)] = 1486,
  [SMALL_STATE(82)] = 1497,
  [SMALL_STATE(83)] = 1506,
  [SMALL_STATE(84)] = 1515,
  [SMALL_STATE(85)] = 1524,
  [SMALL_STATE(86)] = 1533,
  [SMALL_STATE(87)] = 1544,
  [SMALL_STATE(88)] = 1555,
  [SMALL_STATE(89)] = 1564,
  [SMALL_STATE(90)] = 1575,
  [SMALL_STATE(91)] = 1586,
  [SMALL_STATE(92)] = 1595,
  [SMALL_STATE(93)] = 1606,
  [SMALL_STATE(94)] = 1615,
  [SMALL_STATE(95)] = 1626,
  [SMALL_STATE(96)] = 1635,
  [SMALL_STATE(97)] = 1646,
  [SMALL_STATE(98)] = 1657,
  [SMALL_STATE(99)] = 1666,
  [SMALL_STATE(100)] = 1674,
  [SMALL_STATE(101)] = 1682,
  [SMALL_STATE(102)] = 1690,
  [SMALL_STATE(103)] = 1698,
  [SMALL_STATE(104)] = 1706,
  [SMALL_STATE(105)] = 1714,
  [SMALL_STATE(106)] = 1722,
  [SMALL_STATE(107)] = 1730,
  [SMALL_STATE(108)] = 1738,
  [SMALL_STATE(109)] = 1746,
  [SMALL_STATE(110)] = 1754,
  [SMALL_STATE(111)] = 1762,
  [SMALL_STATE(112)] = 1770,
  [SMALL_STATE(113)] = 1778,
  [SMALL_STATE(114)] = 1786,
  [SMALL_STATE(115)] = 1794,
  [SMALL_STATE(116)] = 1802,
  [SMALL_STATE(117)] = 1810,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [36] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_names, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 2, 0, 1),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 2, 0, 1),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_pattern, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ref_pattern, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_list, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 7),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 7),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 3, 0, 2),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 3, 0, 2),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_list, 2, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_list, 2, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0),
  [190] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_literal, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number_literal, 1, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 12),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 12),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 5, 0, 8),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 5, 0, 8),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 4),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 4),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_decl, 3, 0, 3),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_decl, 3, 0, 3),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_decl, 6, 0, 10),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_decl, 6, 0, 10),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 8, 0, 15),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 8, 0, 15),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 7, 0, 14),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 7, 0, 14),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 7, 0, 14),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 7, 0, 14),
  [265] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_short_names_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_short_names_repeat1, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 13),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 13),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_names, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_expression_list_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 4, 0, 5),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 4, 0, 5),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 6, 0, 10),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 6, 0, 10),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 5, 0, 9),
  [299] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 5, 0, 9),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_var, 4, 0, 6),
  [303] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multi_var, 4, 0, 6),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multi_var, 6, 0, 11),
  [307] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multi_var, 6, 0, 11),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_decl, 4, 0, 5),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_decl, 4, 0, 5),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_static_decl, 4, 0, 5),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_static_decl, 4, 0, 5),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 6, 0, 10),
  [321] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 6, 0, 10),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_names, 1, 0, 0),
  [329] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [331] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tuple_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tuple_pattern_repeat1, 2, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_decl, 1, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_let_decl, 1, 0, 0),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_var, 5, 0, 9),
  [342] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_var, 5, 0, 9),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [346] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_pattern, 2, 0, 0),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_flag, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 2, 0, 0),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [382] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [390] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 4, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_pattern, 3, 0, 0),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [412] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
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
