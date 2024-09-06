#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 23
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_integer_literal = 1,
  sym_float_literal = 2,
  anon_sym_true = 3,
  anon_sym_false = 4,
  sym_nil_literal = 5,
  anon_sym_DQUOTE = 6,
  aux_sym_string_literal_token1 = 7,
  anon_sym_BQUOTE = 8,
  aux_sym_raw_string_literal_token1 = 9,
  sym_escape_sequence = 10,
  sym_byte_literal = 11,
  sym_rune_literal = 12,
  sym_line_comment = 13,
  sym_block_comment = 14,
  sym_source_file = 15,
  sym__literals = 16,
  sym_number_literal = 17,
  sym_bool_literal = 18,
  sym_string_literal = 19,
  sym_raw_string_literal = 20,
  aux_sym_source_file_repeat1 = 21,
  aux_sym_string_literal_repeat1 = 22,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__literals] = "_literals",
  [sym_number_literal] = "number_literal",
  [sym_bool_literal] = "bool_literal",
  [sym_string_literal] = "string_literal",
  [sym_raw_string_literal] = "raw_string_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__literals] = sym__literals,
  [sym_number_literal] = sym_number_literal,
  [sym_bool_literal] = sym_bool_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_raw_string_literal] = sym_raw_string_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
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
      if (eof) ADVANCE(69);
      ADVANCE_MAP(
        '"', 85,
        '\'', 10,
        '-', 18,
        '.', 42,
        '/', 15,
        '0', 70,
        '\\', 3,
        '`', 91,
        'f', 25,
        'n', 28,
        't', 31,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(68);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(8);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(8);
      if (lookahead == '\r') SKIP(1);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(8);
      if (lookahead == '\r') SKIP(1);
      if (lookahead == 'U') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(57);
      if (lookahead == 'x') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(102);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(100);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(9);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(9);
      if (lookahead == '\r') SKIP(4);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(9);
      if (lookahead == '\r') SKIP(4);
      if (lookahead == 'U') ADVANCE(65);
      if (lookahead == 'u') ADVANCE(57);
      if (lookahead == 'x') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(102);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(100);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(9);
      if (lookahead == '"') ADVANCE(85);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == '\\') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(89);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(10);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '0') ADVANCE(70);
      if (lookahead == '\\') SKIP(2);
      if (lookahead == '`') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(28);
      if (lookahead == 't') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(85);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '\\') SKIP(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      END_STATE();
    case 10:
      if (lookahead == '\'') ADVANCE(11);
      if (lookahead == '\\') ADVANCE(12);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(11);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 11:
      if (lookahead == '\'') ADVANCE(103);
      END_STATE();
    case 12:
      if (lookahead == '\'') ADVANCE(104);
      if (lookahead == 'U') ADVANCE(14);
      if (lookahead == 'u') ADVANCE(34);
      if (lookahead == 'x') ADVANCE(53);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '\'') ADVANCE(105);
      END_STATE();
    case 14:
      if (lookahead == '\'') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '/') ADVANCE(106);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '/') ADVANCE(107);
      if (lookahead != 0) ADVANCE(17);
      END_STATE();
    case 17:
      if (lookahead == '*') ADVANCE(16);
      if (lookahead != 0) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == '0') ADVANCE(70);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 19:
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '_') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 20:
      if (lookahead == '.') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 21:
      if (lookahead == '_') ADVANCE(38);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(76);
      END_STATE();
    case 22:
      if (lookahead == '_') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(77);
      END_STATE();
    case 23:
      if (lookahead == '_') ADVANCE(49);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(43);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(23);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 24:
      if (lookahead == '_') ADVANCE(49);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(23);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(29);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(32);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 32:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 33:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 34:
      if (lookahead == '{') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 35:
      if (lookahead == '}') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 36:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 37:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(23);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 38:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(76);
      END_STATE();
    case 39:
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(71);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(77);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(100);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 57:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 64:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 66:
      if (eof) ADVANCE(69);
      if (lookahead == '\n') SKIP(68);
      END_STATE();
    case 67:
      if (eof) ADVANCE(69);
      if (lookahead == '\n') SKIP(68);
      if (lookahead == '\r') SKIP(66);
      END_STATE();
    case 68:
      if (eof) ADVANCE(69);
      if (lookahead == '"') ADVANCE(85);
      if (lookahead == '\'') ADVANCE(10);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '0') ADVANCE(70);
      if (lookahead == '\\') SKIP(67);
      if (lookahead == '`') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(25);
      if (lookahead == 'n') ADVANCE(28);
      if (lookahead == 't') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(68);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 81,
        '_', 39,
        'B', 21,
        'b', 21,
        'O', 22,
        'o', 22,
        'X', 19,
        'x', 19,
        '8', 72,
        '9', 72,
        'E', 36,
        'P', 36,
        'e', 36,
        'p', 36,
      );
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(71);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(81);
      if (lookahead == '_') ADVANCE(39);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(72);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(81);
      if (lookahead == '_') ADVANCE(41);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '_') ADVANCE(44);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(74);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 37,
        '_', 48,
        '+', 43,
        '-', 43,
        'E', 74,
        'e', 74,
        'P', 36,
        'p', 36,
      );
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(74);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(38);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(45);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(23);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_nil_literal);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(88);
      if (lookahead == '/') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(90);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead == '/') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(88);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(90);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(98);
      if (lookahead == '\r') ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(99);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(99);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '`') ADVANCE(106);
      if (lookahead != 0) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(97);
      if (lookahead == '/') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(99);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '/') ADVANCE(99);
      if (lookahead == '`') ADVANCE(17);
      if (lookahead != 0) ADVANCE(97);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '`') ADVANCE(17);
      if (lookahead != 0) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '/') ADVANCE(95);
      if (lookahead == '\\') ADVANCE(92);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(100);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(101);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_byte_literal);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_byte_literal);
      if (lookahead == '\'') ADVANCE(105);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_rune_literal);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_block_comment);
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
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 98},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(13),
    [sym__literals] = STATE(2),
    [sym_number_literal] = STATE(2),
    [sym_bool_literal] = STATE(2),
    [sym_string_literal] = STATE(2),
    [sym_raw_string_literal] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_integer_literal] = ACTIONS(7),
    [sym_float_literal] = ACTIONS(7),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_nil_literal] = ACTIONS(11),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_BQUOTE] = ACTIONS(15),
    [sym_byte_literal] = ACTIONS(17),
    [sym_rune_literal] = ACTIONS(17),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__literals] = STATE(3),
    [sym_number_literal] = STATE(3),
    [sym_bool_literal] = STATE(3),
    [sym_string_literal] = STATE(3),
    [sym_raw_string_literal] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_integer_literal] = ACTIONS(7),
    [sym_float_literal] = ACTIONS(7),
    [anon_sym_true] = ACTIONS(9),
    [anon_sym_false] = ACTIONS(9),
    [sym_nil_literal] = ACTIONS(21),
    [anon_sym_DQUOTE] = ACTIONS(13),
    [anon_sym_BQUOTE] = ACTIONS(15),
    [sym_byte_literal] = ACTIONS(23),
    [sym_rune_literal] = ACTIONS(23),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__literals] = STATE(3),
    [sym_number_literal] = STATE(3),
    [sym_bool_literal] = STATE(3),
    [sym_string_literal] = STATE(3),
    [sym_raw_string_literal] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_integer_literal] = ACTIONS(27),
    [sym_float_literal] = ACTIONS(27),
    [anon_sym_true] = ACTIONS(30),
    [anon_sym_false] = ACTIONS(30),
    [sym_nil_literal] = ACTIONS(33),
    [anon_sym_DQUOTE] = ACTIONS(36),
    [anon_sym_BQUOTE] = ACTIONS(39),
    [sym_byte_literal] = ACTIONS(42),
    [sym_rune_literal] = ACTIONS(42),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_integer_literal] = ACTIONS(47),
    [sym_float_literal] = ACTIONS(47),
    [anon_sym_true] = ACTIONS(45),
    [anon_sym_false] = ACTIONS(45),
    [sym_nil_literal] = ACTIONS(45),
    [anon_sym_DQUOTE] = ACTIONS(45),
    [anon_sym_BQUOTE] = ACTIONS(45),
    [sym_byte_literal] = ACTIONS(47),
    [sym_rune_literal] = ACTIONS(47),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_integer_literal] = ACTIONS(51),
    [sym_float_literal] = ACTIONS(51),
    [anon_sym_true] = ACTIONS(49),
    [anon_sym_false] = ACTIONS(49),
    [sym_nil_literal] = ACTIONS(49),
    [anon_sym_DQUOTE] = ACTIONS(49),
    [anon_sym_BQUOTE] = ACTIONS(49),
    [sym_byte_literal] = ACTIONS(51),
    [sym_rune_literal] = ACTIONS(51),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(53),
    [sym_integer_literal] = ACTIONS(55),
    [sym_float_literal] = ACTIONS(55),
    [anon_sym_true] = ACTIONS(53),
    [anon_sym_false] = ACTIONS(53),
    [sym_nil_literal] = ACTIONS(53),
    [anon_sym_DQUOTE] = ACTIONS(53),
    [anon_sym_BQUOTE] = ACTIONS(53),
    [sym_byte_literal] = ACTIONS(55),
    [sym_rune_literal] = ACTIONS(55),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(57),
    [sym_integer_literal] = ACTIONS(59),
    [sym_float_literal] = ACTIONS(59),
    [anon_sym_true] = ACTIONS(57),
    [anon_sym_false] = ACTIONS(57),
    [sym_nil_literal] = ACTIONS(57),
    [anon_sym_DQUOTE] = ACTIONS(57),
    [anon_sym_BQUOTE] = ACTIONS(57),
    [sym_byte_literal] = ACTIONS(59),
    [sym_rune_literal] = ACTIONS(59),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(61),
    [sym_integer_literal] = ACTIONS(63),
    [sym_float_literal] = ACTIONS(63),
    [anon_sym_true] = ACTIONS(61),
    [anon_sym_false] = ACTIONS(61),
    [sym_nil_literal] = ACTIONS(61),
    [anon_sym_DQUOTE] = ACTIONS(61),
    [anon_sym_BQUOTE] = ACTIONS(61),
    [sym_byte_literal] = ACTIONS(63),
    [sym_rune_literal] = ACTIONS(63),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    STATE(10), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(67), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
    ACTIONS(69), 2,
      sym_line_comment,
      sym_block_comment,
  [15] = 4,
    ACTIONS(71), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(69), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(73), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [30] = 4,
    ACTIONS(75), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(69), 2,
      sym_line_comment,
      sym_block_comment,
    ACTIONS(77), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [45] = 2,
    ACTIONS(80), 1,
      aux_sym_raw_string_literal_token1,
    ACTIONS(69), 2,
      sym_line_comment,
      sym_block_comment,
  [53] = 2,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
  [61] = 2,
    ACTIONS(84), 1,
      anon_sym_BQUOTE,
    ACTIONS(3), 2,
      sym_line_comment,
      sym_block_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 15,
  [SMALL_STATE(11)] = 30,
  [SMALL_STATE(12)] = 45,
  [SMALL_STATE(13)] = 53,
  [SMALL_STATE(14)] = 61,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_literal, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number_literal, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [82] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
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
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
