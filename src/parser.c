#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 21
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
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
  sym_source_file = 13,
  sym__literals = 14,
  sym_number_literal = 15,
  sym_bool_literal = 16,
  sym_string_literal = 17,
  sym_raw_string_literal = 18,
  aux_sym_source_file_repeat1 = 19,
  aux_sym_string_literal_repeat1 = 20,
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
      if (eof) ADVANCE(58);
      ADVANCE_MAP(
        '"', 74,
        '\'', 3,
        '-', 8,
        '.', 33,
        '0', 59,
        '\\', 11,
        '`', 77,
        'f', 16,
        'n', 19,
        't', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(57);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '"') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(75);
      if (lookahead != 0) ADVANCE(76);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(74);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(6);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(4);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(83);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == 'U') ADVANCE(5);
      if (lookahead == 'u') ADVANCE(25);
      if (lookahead == 'x') ADVANCE(44);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(85);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(33);
      if (lookahead == '0') ADVANCE(59);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(40);
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 11:
      if (lookahead == 'U') ADVANCE(56);
      if (lookahead == 'u') ADVANCE(48);
      if (lookahead == 'x') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(82);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(80);
      END_STATE();
    case 12:
      if (lookahead == '_') ADVANCE(29);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(65);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(66);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(40);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(34);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(14);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(40);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(14);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 22:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 25:
      if (lookahead == '{') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 26:
      if (lookahead == '}') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 28:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(14);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 29:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(65);
      END_STATE();
    case 30:
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(60);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(66);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(4);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(80);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 57:
      if (eof) ADVANCE(58);
      ADVANCE_MAP(
        '"', 74,
        '\'', 3,
        '-', 8,
        '.', 33,
        '0', 59,
        '`', 77,
        'f', 16,
        'n', 19,
        't', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(57);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 70,
        '_', 30,
        'B', 12,
        'b', 12,
        'O', 13,
        'o', 13,
        'X', 9,
        'x', 9,
        '8', 61,
        '9', 61,
        'E', 27,
        'P', 27,
        'e', 27,
        'p', 27,
      );
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '_') ADVANCE(30);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(61);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '_') ADVANCE(32);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '_') ADVANCE(35);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(63);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_integer_literal);
      ADVANCE_MAP(
        '.', 28,
        '_', 39,
        '+', 34,
        '-', 34,
        'E', 63,
        'e', 63,
        'P', 27,
        'p', 27,
      );
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '_') ADVANCE(39);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(63);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(29);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_integer_literal);
      if (lookahead == '_') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(33);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(36);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(14);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == '_') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_float_literal);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_nil_literal);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(75);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(76);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(78);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(80);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(81);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_byte_literal);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_byte_literal);
      if (lookahead == '\'') ADVANCE(83);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_rune_literal);
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
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 78},
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
  },
  [1] = {
    [sym_source_file] = STATE(13),
    [sym__literals] = STATE(2),
    [sym_number_literal] = STATE(2),
    [sym_bool_literal] = STATE(2),
    [sym_string_literal] = STATE(2),
    [sym_raw_string_literal] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_integer_literal] = ACTIONS(5),
    [sym_float_literal] = ACTIONS(5),
    [anon_sym_true] = ACTIONS(7),
    [anon_sym_false] = ACTIONS(7),
    [sym_nil_literal] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [anon_sym_BQUOTE] = ACTIONS(13),
    [sym_byte_literal] = ACTIONS(9),
    [sym_rune_literal] = ACTIONS(15),
  },
  [2] = {
    [sym__literals] = STATE(3),
    [sym_number_literal] = STATE(3),
    [sym_bool_literal] = STATE(3),
    [sym_string_literal] = STATE(3),
    [sym_raw_string_literal] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym_integer_literal] = ACTIONS(5),
    [sym_float_literal] = ACTIONS(5),
    [anon_sym_true] = ACTIONS(7),
    [anon_sym_false] = ACTIONS(7),
    [sym_nil_literal] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [anon_sym_BQUOTE] = ACTIONS(13),
    [sym_byte_literal] = ACTIONS(19),
    [sym_rune_literal] = ACTIONS(21),
  },
  [3] = {
    [sym__literals] = STATE(3),
    [sym_number_literal] = STATE(3),
    [sym_bool_literal] = STATE(3),
    [sym_string_literal] = STATE(3),
    [sym_raw_string_literal] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_integer_literal] = ACTIONS(25),
    [sym_float_literal] = ACTIONS(25),
    [anon_sym_true] = ACTIONS(28),
    [anon_sym_false] = ACTIONS(28),
    [sym_nil_literal] = ACTIONS(31),
    [anon_sym_DQUOTE] = ACTIONS(34),
    [anon_sym_BQUOTE] = ACTIONS(37),
    [sym_byte_literal] = ACTIONS(31),
    [sym_rune_literal] = ACTIONS(40),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(45), 3,
      sym_integer_literal,
      sym_float_literal,
      sym_rune_literal,
    ACTIONS(43), 7,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_byte_literal,
  [15] = 2,
    ACTIONS(49), 3,
      sym_integer_literal,
      sym_float_literal,
      sym_rune_literal,
    ACTIONS(47), 7,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_byte_literal,
  [30] = 2,
    ACTIONS(53), 3,
      sym_integer_literal,
      sym_float_literal,
      sym_rune_literal,
    ACTIONS(51), 7,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_byte_literal,
  [45] = 2,
    ACTIONS(57), 3,
      sym_integer_literal,
      sym_float_literal,
      sym_rune_literal,
    ACTIONS(55), 7,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_byte_literal,
  [60] = 2,
    ACTIONS(61), 3,
      sym_integer_literal,
      sym_float_literal,
      sym_rune_literal,
    ACTIONS(59), 7,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym_nil_literal,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      sym_byte_literal,
  [75] = 3,
    ACTIONS(63), 1,
      anon_sym_DQUOTE,
    STATE(10), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(65), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [86] = 3,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(69), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [97] = 3,
    ACTIONS(71), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(73), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [108] = 1,
    ACTIONS(76), 1,
      aux_sym_raw_string_literal_token1,
  [112] = 1,
    ACTIONS(78), 1,
      ts_builtin_sym_end,
  [116] = 1,
    ACTIONS(80), 1,
      anon_sym_BQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 15,
  [SMALL_STATE(6)] = 30,
  [SMALL_STATE(7)] = 45,
  [SMALL_STATE(8)] = 60,
  [SMALL_STATE(9)] = 75,
  [SMALL_STATE(10)] = 86,
  [SMALL_STATE(11)] = 97,
  [SMALL_STATE(12)] = 108,
  [SMALL_STATE(13)] = 112,
  [SMALL_STATE(14)] = 116,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_literal, 1, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number_literal, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_literal, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [78] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
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
