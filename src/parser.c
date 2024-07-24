#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 24
#define LARGE_STATE_COUNT 13
#define SYMBOL_COUNT 35
#define ALIAS_COUNT 0
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_true = 2,
  anon_sym_false = 3,
  anon_sym_DASH = 4,
  sym_decimal_integer = 5,
  sym_binary_integer = 6,
  sym_octal_integer = 7,
  sym_hexadecimal_integer = 8,
  sym_decimal_float = 9,
  sym_exponential_float = 10,
  sym_hexadecimal_float = 11,
  sym_byte_literal = 12,
  sym_rune_literal = 13,
  anon_sym_DQUOTE = 14,
  aux_sym_string_literal_token1 = 15,
  aux_sym_string_literal_token2 = 16,
  anon_sym_BQUOTE = 17,
  aux_sym_raw_string_literal_token1 = 18,
  sym_nil = 19,
  sym_any = 20,
  sym_line_comment = 21,
  sym_block_comment = 22,
  sym_source_file = 23,
  sym__literals = 24,
  sym_boolean_literal = 25,
  sym_negative_literal = 26,
  sym_integer_literal = 27,
  sym_float_literal = 28,
  sym_string_literal = 29,
  sym_raw_string_literal = 30,
  sym_comment = 31,
  aux_sym_source_file_repeat1 = 32,
  aux_sym_string_literal_repeat1 = 33,
  aux_sym_raw_string_literal_repeat1 = 34,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_DASH] = "-",
  [sym_decimal_integer] = "decimal_integer",
  [sym_binary_integer] = "binary_integer",
  [sym_octal_integer] = "octal_integer",
  [sym_hexadecimal_integer] = "hexadecimal_integer",
  [sym_decimal_float] = "decimal_float",
  [sym_exponential_float] = "exponential_float",
  [sym_hexadecimal_float] = "hexadecimal_float",
  [sym_byte_literal] = "byte_literal",
  [sym_rune_literal] = "rune_literal",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_literal_token1",
  [aux_sym_string_literal_token2] = "string_literal_token2",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_raw_string_literal_token1] = "raw_string_literal_token1",
  [sym_nil] = "nil",
  [sym_any] = "any",
  [sym_line_comment] = "line_comment",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym__literals] = "_literals",
  [sym_boolean_literal] = "boolean_literal",
  [sym_negative_literal] = "negative_literal",
  [sym_integer_literal] = "integer_literal",
  [sym_float_literal] = "float_literal",
  [sym_string_literal] = "string_literal",
  [sym_raw_string_literal] = "raw_string_literal",
  [sym_comment] = "comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
  [aux_sym_raw_string_literal_repeat1] = "raw_string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_decimal_integer] = sym_decimal_integer,
  [sym_binary_integer] = sym_binary_integer,
  [sym_octal_integer] = sym_octal_integer,
  [sym_hexadecimal_integer] = sym_hexadecimal_integer,
  [sym_decimal_float] = sym_decimal_float,
  [sym_exponential_float] = sym_exponential_float,
  [sym_hexadecimal_float] = sym_hexadecimal_float,
  [sym_byte_literal] = sym_byte_literal,
  [sym_rune_literal] = sym_rune_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [aux_sym_string_literal_token2] = aux_sym_string_literal_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_raw_string_literal_token1] = aux_sym_raw_string_literal_token1,
  [sym_nil] = sym_nil,
  [sym_any] = sym_any,
  [sym_line_comment] = sym_line_comment,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym__literals] = sym__literals,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_negative_literal] = sym_negative_literal,
  [sym_integer_literal] = sym_integer_literal,
  [sym_float_literal] = sym_float_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_raw_string_literal] = sym_raw_string_literal,
  [sym_comment] = sym_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
  [aux_sym_raw_string_literal_repeat1] = aux_sym_raw_string_literal_repeat1,
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_decimal_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_hexadecimal_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_float] = {
    .visible = true,
    .named = true,
  },
  [sym_exponential_float] = {
    .visible = true,
    .named = true,
  },
  [sym_hexadecimal_float] = {
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
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_raw_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_nil] = {
    .visible = true,
    .named = true,
  },
  [sym_any] = {
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
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_negative_literal] = {
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
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_raw_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
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
  [aux_sym_raw_string_literal_repeat1] = {
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
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 12,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(36);
      ADVANCE_MAP(
        '"', 53,
        '\'', 3,
        '-', 39,
        '.', 23,
        '/', 5,
        '0', 41,
        '\\', 35,
        '`', 58,
        'b', 37,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z') ||
          lookahead == 0xb5 ||
          (0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(38);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '/') ADVANCE(55);
      if (lookahead == '\\') ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0) ADVANCE(54);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(51);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(62);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(63);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == '`') ADVANCE(58);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 10:
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(4);
      END_STATE();
    case 11:
      if (lookahead == '_') ADVANCE(30);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == 'u') ADVANCE(14);
      if (lookahead == 'x') ADVANCE(33);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 13:
      if (lookahead == 'x') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != 'u') ADVANCE(4);
      END_STATE();
    case 14:
      if (lookahead == '{') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 15:
      if (lookahead == '}') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 17:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      END_STATE();
    case 18:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 19:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(43);
      END_STATE();
    case 20:
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(40);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(2);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(4);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 35:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(57);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\'') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 0xb5 ||
          (0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(38);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 0xb5 ||
          (0x391 <= lookahead && lookahead <= 0x3a9) ||
          (0x3b1 <= lookahead && lookahead <= 0x3c9)) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_decimal_integer);
      if (lookahead == '.') ADVANCE(48);
      if (lookahead == '_') ADVANCE(20);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(16);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_decimal_integer);
      ADVANCE_MAP(
        '.', 48,
        '_', 22,
        'b', 19,
        'o', 21,
        'x', 8,
        'E', 16,
        'e', 16,
        '8', 42,
        '9', 42,
      );
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(40);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_decimal_integer);
      if (lookahead == '.') ADVANCE(48);
      if (lookahead == '_') ADVANCE(22);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_binary_integer);
      if (lookahead == '_') ADVANCE(19);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_octal_integer);
      if (lookahead == '_') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_hexadecimal_integer);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '_') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_decimal_float);
      if (lookahead == '_') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_decimal_float);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_decimal_float);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_exponential_float);
      if (lookahead == '_') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_hexadecimal_float);
      if (lookahead == '_') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_byte_literal);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_rune_literal);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(62);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '/') ADVANCE(55);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(54);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_string_literal_token2);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(62);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_raw_string_literal_token1);
      if (lookahead == '/') ADVANCE(60);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(59);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(62);
      END_STATE();
    case 63:
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
      if (lookahead == 'a') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'n') ADVANCE(3);
      if (lookahead == 't') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'n') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 5:
      if (lookahead == 'y') ADVANCE(9);
      END_STATE();
    case 6:
      if (lookahead == 'l') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_any);
      END_STATE();
    case 10:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(15);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_false);
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
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 0},
  [23] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_decimal_integer] = ACTIONS(1),
    [sym_binary_integer] = ACTIONS(1),
    [sym_octal_integer] = ACTIONS(1),
    [sym_hexadecimal_integer] = ACTIONS(1),
    [sym_decimal_float] = ACTIONS(1),
    [sym_exponential_float] = ACTIONS(1),
    [sym_hexadecimal_float] = ACTIONS(1),
    [sym_byte_literal] = ACTIONS(1),
    [sym_rune_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_string_literal_token2] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_nil] = ACTIONS(1),
    [sym_any] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(5),
  },
  [1] = {
    [sym_source_file] = STATE(22),
    [sym__literals] = STATE(3),
    [sym_boolean_literal] = STATE(3),
    [sym_negative_literal] = STATE(3),
    [sym_integer_literal] = STATE(3),
    [sym_float_literal] = STATE(3),
    [sym_string_literal] = STATE(3),
    [sym_raw_string_literal] = STATE(3),
    [sym_comment] = STATE(1),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(9),
    [sym_decimal_integer] = ACTIONS(11),
    [sym_binary_integer] = ACTIONS(13),
    [sym_octal_integer] = ACTIONS(11),
    [sym_hexadecimal_integer] = ACTIONS(11),
    [sym_decimal_float] = ACTIONS(15),
    [sym_exponential_float] = ACTIONS(17),
    [sym_hexadecimal_float] = ACTIONS(17),
    [sym_byte_literal] = ACTIONS(19),
    [sym_rune_literal] = ACTIONS(19),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [anon_sym_BQUOTE] = ACTIONS(23),
    [sym_nil] = ACTIONS(19),
    [sym_any] = ACTIONS(19),
    [sym_line_comment] = ACTIONS(25),
    [sym_block_comment] = ACTIONS(25),
  },
  [2] = {
    [sym__literals] = STATE(2),
    [sym_boolean_literal] = STATE(2),
    [sym_negative_literal] = STATE(2),
    [sym_integer_literal] = STATE(2),
    [sym_float_literal] = STATE(2),
    [sym_string_literal] = STATE(2),
    [sym_raw_string_literal] = STATE(2),
    [sym_comment] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(27),
    [anon_sym_true] = ACTIONS(29),
    [anon_sym_false] = ACTIONS(29),
    [anon_sym_DASH] = ACTIONS(32),
    [sym_decimal_integer] = ACTIONS(35),
    [sym_binary_integer] = ACTIONS(38),
    [sym_octal_integer] = ACTIONS(35),
    [sym_hexadecimal_integer] = ACTIONS(35),
    [sym_decimal_float] = ACTIONS(41),
    [sym_exponential_float] = ACTIONS(44),
    [sym_hexadecimal_float] = ACTIONS(44),
    [sym_byte_literal] = ACTIONS(47),
    [sym_rune_literal] = ACTIONS(47),
    [anon_sym_DQUOTE] = ACTIONS(50),
    [anon_sym_BQUOTE] = ACTIONS(53),
    [sym_nil] = ACTIONS(47),
    [sym_any] = ACTIONS(47),
    [sym_line_comment] = ACTIONS(56),
    [sym_block_comment] = ACTIONS(56),
  },
  [3] = {
    [sym__literals] = STATE(2),
    [sym_boolean_literal] = STATE(2),
    [sym_negative_literal] = STATE(2),
    [sym_integer_literal] = STATE(2),
    [sym_float_literal] = STATE(2),
    [sym_string_literal] = STATE(2),
    [sym_raw_string_literal] = STATE(2),
    [sym_comment] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(59),
    [anon_sym_true] = ACTIONS(5),
    [anon_sym_false] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(9),
    [sym_decimal_integer] = ACTIONS(11),
    [sym_binary_integer] = ACTIONS(13),
    [sym_octal_integer] = ACTIONS(11),
    [sym_hexadecimal_integer] = ACTIONS(11),
    [sym_decimal_float] = ACTIONS(15),
    [sym_exponential_float] = ACTIONS(17),
    [sym_hexadecimal_float] = ACTIONS(17),
    [sym_byte_literal] = ACTIONS(61),
    [sym_rune_literal] = ACTIONS(61),
    [anon_sym_DQUOTE] = ACTIONS(21),
    [anon_sym_BQUOTE] = ACTIONS(23),
    [sym_nil] = ACTIONS(61),
    [sym_any] = ACTIONS(61),
    [sym_line_comment] = ACTIONS(25),
    [sym_block_comment] = ACTIONS(25),
  },
  [4] = {
    [sym_comment] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(63),
    [anon_sym_true] = ACTIONS(63),
    [anon_sym_false] = ACTIONS(63),
    [anon_sym_DASH] = ACTIONS(63),
    [sym_decimal_integer] = ACTIONS(65),
    [sym_binary_integer] = ACTIONS(63),
    [sym_octal_integer] = ACTIONS(65),
    [sym_hexadecimal_integer] = ACTIONS(65),
    [sym_decimal_float] = ACTIONS(65),
    [sym_exponential_float] = ACTIONS(63),
    [sym_hexadecimal_float] = ACTIONS(63),
    [sym_byte_literal] = ACTIONS(63),
    [sym_rune_literal] = ACTIONS(63),
    [anon_sym_DQUOTE] = ACTIONS(63),
    [anon_sym_BQUOTE] = ACTIONS(63),
    [sym_nil] = ACTIONS(63),
    [sym_any] = ACTIONS(63),
    [sym_line_comment] = ACTIONS(63),
    [sym_block_comment] = ACTIONS(63),
  },
  [5] = {
    [sym_comment] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(67),
    [anon_sym_true] = ACTIONS(67),
    [anon_sym_false] = ACTIONS(67),
    [anon_sym_DASH] = ACTIONS(67),
    [sym_decimal_integer] = ACTIONS(69),
    [sym_binary_integer] = ACTIONS(67),
    [sym_octal_integer] = ACTIONS(69),
    [sym_hexadecimal_integer] = ACTIONS(69),
    [sym_decimal_float] = ACTIONS(69),
    [sym_exponential_float] = ACTIONS(67),
    [sym_hexadecimal_float] = ACTIONS(67),
    [sym_byte_literal] = ACTIONS(67),
    [sym_rune_literal] = ACTIONS(67),
    [anon_sym_DQUOTE] = ACTIONS(67),
    [anon_sym_BQUOTE] = ACTIONS(67),
    [sym_nil] = ACTIONS(67),
    [sym_any] = ACTIONS(67),
    [sym_line_comment] = ACTIONS(67),
    [sym_block_comment] = ACTIONS(67),
  },
  [6] = {
    [sym_comment] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(71),
    [anon_sym_true] = ACTIONS(71),
    [anon_sym_false] = ACTIONS(71),
    [anon_sym_DASH] = ACTIONS(71),
    [sym_decimal_integer] = ACTIONS(73),
    [sym_binary_integer] = ACTIONS(71),
    [sym_octal_integer] = ACTIONS(73),
    [sym_hexadecimal_integer] = ACTIONS(73),
    [sym_decimal_float] = ACTIONS(73),
    [sym_exponential_float] = ACTIONS(71),
    [sym_hexadecimal_float] = ACTIONS(71),
    [sym_byte_literal] = ACTIONS(71),
    [sym_rune_literal] = ACTIONS(71),
    [anon_sym_DQUOTE] = ACTIONS(71),
    [anon_sym_BQUOTE] = ACTIONS(71),
    [sym_nil] = ACTIONS(71),
    [sym_any] = ACTIONS(71),
    [sym_line_comment] = ACTIONS(71),
    [sym_block_comment] = ACTIONS(71),
  },
  [7] = {
    [sym_comment] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(75),
    [anon_sym_true] = ACTIONS(75),
    [anon_sym_false] = ACTIONS(75),
    [anon_sym_DASH] = ACTIONS(75),
    [sym_decimal_integer] = ACTIONS(77),
    [sym_binary_integer] = ACTIONS(75),
    [sym_octal_integer] = ACTIONS(77),
    [sym_hexadecimal_integer] = ACTIONS(77),
    [sym_decimal_float] = ACTIONS(77),
    [sym_exponential_float] = ACTIONS(75),
    [sym_hexadecimal_float] = ACTIONS(75),
    [sym_byte_literal] = ACTIONS(75),
    [sym_rune_literal] = ACTIONS(75),
    [anon_sym_DQUOTE] = ACTIONS(75),
    [anon_sym_BQUOTE] = ACTIONS(75),
    [sym_nil] = ACTIONS(75),
    [sym_any] = ACTIONS(75),
    [sym_line_comment] = ACTIONS(75),
    [sym_block_comment] = ACTIONS(75),
  },
  [8] = {
    [sym_comment] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(79),
    [anon_sym_true] = ACTIONS(79),
    [anon_sym_false] = ACTIONS(79),
    [anon_sym_DASH] = ACTIONS(79),
    [sym_decimal_integer] = ACTIONS(81),
    [sym_binary_integer] = ACTIONS(79),
    [sym_octal_integer] = ACTIONS(81),
    [sym_hexadecimal_integer] = ACTIONS(81),
    [sym_decimal_float] = ACTIONS(81),
    [sym_exponential_float] = ACTIONS(79),
    [sym_hexadecimal_float] = ACTIONS(79),
    [sym_byte_literal] = ACTIONS(79),
    [sym_rune_literal] = ACTIONS(79),
    [anon_sym_DQUOTE] = ACTIONS(79),
    [anon_sym_BQUOTE] = ACTIONS(79),
    [sym_nil] = ACTIONS(79),
    [sym_any] = ACTIONS(79),
    [sym_line_comment] = ACTIONS(79),
    [sym_block_comment] = ACTIONS(79),
  },
  [9] = {
    [sym_comment] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(83),
    [anon_sym_true] = ACTIONS(83),
    [anon_sym_false] = ACTIONS(83),
    [anon_sym_DASH] = ACTIONS(83),
    [sym_decimal_integer] = ACTIONS(85),
    [sym_binary_integer] = ACTIONS(83),
    [sym_octal_integer] = ACTIONS(85),
    [sym_hexadecimal_integer] = ACTIONS(85),
    [sym_decimal_float] = ACTIONS(85),
    [sym_exponential_float] = ACTIONS(83),
    [sym_hexadecimal_float] = ACTIONS(83),
    [sym_byte_literal] = ACTIONS(83),
    [sym_rune_literal] = ACTIONS(83),
    [anon_sym_DQUOTE] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [sym_nil] = ACTIONS(83),
    [sym_any] = ACTIONS(83),
    [sym_line_comment] = ACTIONS(83),
    [sym_block_comment] = ACTIONS(83),
  },
  [10] = {
    [sym_comment] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(87),
    [anon_sym_true] = ACTIONS(87),
    [anon_sym_false] = ACTIONS(87),
    [anon_sym_DASH] = ACTIONS(87),
    [sym_decimal_integer] = ACTIONS(89),
    [sym_binary_integer] = ACTIONS(87),
    [sym_octal_integer] = ACTIONS(89),
    [sym_hexadecimal_integer] = ACTIONS(89),
    [sym_decimal_float] = ACTIONS(89),
    [sym_exponential_float] = ACTIONS(87),
    [sym_hexadecimal_float] = ACTIONS(87),
    [sym_byte_literal] = ACTIONS(87),
    [sym_rune_literal] = ACTIONS(87),
    [anon_sym_DQUOTE] = ACTIONS(87),
    [anon_sym_BQUOTE] = ACTIONS(87),
    [sym_nil] = ACTIONS(87),
    [sym_any] = ACTIONS(87),
    [sym_line_comment] = ACTIONS(87),
    [sym_block_comment] = ACTIONS(87),
  },
  [11] = {
    [sym_comment] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(91),
    [anon_sym_true] = ACTIONS(91),
    [anon_sym_false] = ACTIONS(91),
    [anon_sym_DASH] = ACTIONS(91),
    [sym_decimal_integer] = ACTIONS(93),
    [sym_binary_integer] = ACTIONS(91),
    [sym_octal_integer] = ACTIONS(93),
    [sym_hexadecimal_integer] = ACTIONS(93),
    [sym_decimal_float] = ACTIONS(93),
    [sym_exponential_float] = ACTIONS(91),
    [sym_hexadecimal_float] = ACTIONS(91),
    [sym_byte_literal] = ACTIONS(91),
    [sym_rune_literal] = ACTIONS(91),
    [anon_sym_DQUOTE] = ACTIONS(91),
    [anon_sym_BQUOTE] = ACTIONS(91),
    [sym_nil] = ACTIONS(91),
    [sym_any] = ACTIONS(91),
    [sym_line_comment] = ACTIONS(91),
    [sym_block_comment] = ACTIONS(91),
  },
  [12] = {
    [sym_comment] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(95),
    [anon_sym_true] = ACTIONS(95),
    [anon_sym_false] = ACTIONS(95),
    [anon_sym_DASH] = ACTIONS(95),
    [sym_decimal_integer] = ACTIONS(97),
    [sym_binary_integer] = ACTIONS(95),
    [sym_octal_integer] = ACTIONS(97),
    [sym_hexadecimal_integer] = ACTIONS(97),
    [sym_decimal_float] = ACTIONS(97),
    [sym_exponential_float] = ACTIONS(95),
    [sym_hexadecimal_float] = ACTIONS(95),
    [sym_byte_literal] = ACTIONS(95),
    [sym_rune_literal] = ACTIONS(95),
    [anon_sym_DQUOTE] = ACTIONS(95),
    [anon_sym_BQUOTE] = ACTIONS(95),
    [sym_nil] = ACTIONS(95),
    [sym_any] = ACTIONS(95),
    [sym_line_comment] = ACTIONS(95),
    [sym_block_comment] = ACTIONS(95),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(5), 1,
      sym_block_comment,
    ACTIONS(13), 1,
      sym_binary_integer,
    ACTIONS(15), 1,
      sym_decimal_float,
    STATE(13), 1,
      sym_comment,
    ACTIONS(17), 2,
      sym_exponential_float,
      sym_hexadecimal_float,
    STATE(6), 2,
      sym_integer_literal,
      sym_float_literal,
    ACTIONS(11), 3,
      sym_decimal_integer,
      sym_octal_integer,
      sym_hexadecimal_integer,
  [29] = 6,
    ACTIONS(99), 1,
      anon_sym_DQUOTE,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    STATE(14), 1,
      sym_comment,
    STATE(15), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(101), 2,
      aux_sym_string_literal_token1,
      aux_sym_string_literal_token2,
  [49] = 6,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    ACTIONS(107), 1,
      anon_sym_DQUOTE,
    STATE(15), 1,
      sym_comment,
    STATE(16), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(101), 2,
      aux_sym_string_literal_token1,
      aux_sym_string_literal_token2,
  [69] = 5,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 2,
      aux_sym_string_literal_token1,
      aux_sym_string_literal_token2,
    STATE(16), 2,
      sym_comment,
      aux_sym_string_literal_repeat1,
  [87] = 6,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    ACTIONS(114), 1,
      anon_sym_BQUOTE,
    ACTIONS(116), 1,
      aux_sym_raw_string_literal_token1,
    STATE(17), 1,
      sym_comment,
    STATE(19), 1,
      aux_sym_raw_string_literal_repeat1,
  [106] = 4,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    STATE(18), 1,
      sym_comment,
    ACTIONS(118), 3,
      anon_sym_DQUOTE,
      aux_sym_string_literal_token1,
      aux_sym_string_literal_token2,
  [121] = 6,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    ACTIONS(116), 1,
      aux_sym_raw_string_literal_token1,
    ACTIONS(120), 1,
      anon_sym_BQUOTE,
    STATE(19), 1,
      sym_comment,
    STATE(20), 1,
      aux_sym_raw_string_literal_repeat1,
  [140] = 5,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    ACTIONS(122), 1,
      anon_sym_BQUOTE,
    ACTIONS(124), 1,
      aux_sym_raw_string_literal_token1,
    STATE(20), 2,
      sym_comment,
      aux_sym_raw_string_literal_repeat1,
  [157] = 4,
    ACTIONS(103), 1,
      sym_line_comment,
    ACTIONS(105), 1,
      sym_block_comment,
    STATE(21), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_BQUOTE,
      aux_sym_raw_string_literal_token1,
  [171] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(5), 1,
      sym_block_comment,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    STATE(22), 1,
      sym_comment,
  [184] = 1,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(13)] = 0,
  [SMALL_STATE(14)] = 29,
  [SMALL_STATE(15)] = 49,
  [SMALL_STATE(16)] = 69,
  [SMALL_STATE(17)] = 87,
  [SMALL_STATE(18)] = 106,
  [SMALL_STATE(19)] = 121,
  [SMALL_STATE(20)] = 140,
  [SMALL_STATE(21)] = 157,
  [SMALL_STATE(22)] = 171,
  [SMALL_STATE(23)] = 184,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 1, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 1, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_negative_literal, 2, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_negative_literal, 2, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 2, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_raw_string_literal, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 1, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_raw_string_literal_repeat1, 2, 0, 0),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_raw_string_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_raw_string_literal_repeat1, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
