//----Constants----------//
// Operator Precedences
// - Assignment precedence (lowest)
// - Logical OR precedence
// - Logical AND precedence
// - Equality comparison precedence
// - Relational comparison precedence
// - Bitwise OR precedence
// - Bitwise XOR precedence
// - Bitwise AND precedence
// - Shift precedence
// - Additive precedence
// - Multiplicative precedence
// - Unary precedence
// - Call and member access precedence (highest)
const PREC = {
	assign: -2
}

//  Type Information

//  - Primitive types

const primitiveTypes = [
	'u8',
	'i8',
	'u16',
	'i16',
	'u32',
	'i32',
	'u64',
	'i64',
	'uint',
	'uintptr',
	'int',
	'f32',
	'f64',
	'bool',
	'any'
]

const newline = token(/\r?\n/)
const terminator = choice(newline, ';')

// Numeric Parsing Information

// - Integer - Hex, octal, and binary
const digitPattern = (pattern) =>
	seq(pattern, repeat(seq(optional('_'), pattern)))

const hexDigits = digitPattern(/[0-9a-fA-F]/)
const octalDigits = digitPattern(/[0-7]/)
const decimalDigits = digitPattern(/[0-9]/)
const binaryDigits = digitPattern(/[01]/)

const intLiteral = choice(
	seq('0', choice('x', 'X'), optional('_'), hexDigits),
	seq('0', optional(choice('o', 'O')), optional('_'), octalDigits),
	choice('0', seq(/[1-9]/, optional(seq(optional('_'), decimalDigits)))),
	seq('0', choice('b', 'B'), optional('_'), binaryDigits)
)

// - Floating-point - Decimal and exponential
const decimalFloatLiteral = choice(
	seq(
		decimalDigits,
		'.',
		optional(decimalDigits),
		optional(
			seq(choice('e', 'E'), optional(choice('+', '-')), decimalDigits)
		)
	),
	seq(
		decimalDigits,
		seq(choice('e', 'E'), optional(choice('+', '-')), decimalDigits)
	),
	seq(
		'.',
		decimalDigits,
		optional(
			seq(choice('e', 'E'), optional(choice('+', '-')), decimalDigits)
		)
	)
)

const hexFloatLiteral = seq(
	'0',
	choice('x', 'X'),
	choice(
		seq(optional('_'), hexDigits, '.', optional(hexDigits)),
		seq(optional('_'), hexDigits),
		seq('.', hexDigits)
	),
	seq(choice('p', 'P'), optional(choice('+', '-')), decimalDigits)
)

const floatLiteral = choice(decimalFloatLiteral, hexFloatLiteral)

module.exports = grammar({
	name: 'jule',

	extras: ($) => [$.comment, /\s|\\\r?\n/],

	word: ($) => $.identifier,

	rules: {
		//----Source Structure----//
		// File structure

		source_file: ($) =>
			seq(repeat(seq($._statement, terminator)), optional($._statement)),

		//----Comments-----------//
		comment: ($) => choice($.line_comment, $.block_comment),

		line_comment: ($) => token(seq('//', /(\\+(.|\r?\n)|[^\\\n])*/)),

		block_comment: ($) =>
			token(seq('/*', /[^*]*[*]+(?:[^/*][^*]*[*]+)*/, '/')),

		//----Literals-----------//
		_literal: ($) =>
			choice(
				$.integer_literal,
				$.float_literal,
				$.bool_literal,
				$.string_literal,
				$.raw_string_literal,
				$.byte_literal,
				$.rune_literal,
				$.nil_literal
			),

		// Number literals

		// Integer literals
		integer_literal: ($) => token(intLiteral),

		// Float literals
		float_literal: ($) => token(floatLiteral),

		// Boolean literals
		bool_literal: ($) => choice('true', 'false'),

		// String literals

		// - Double-quoted strings
		string_literal: ($) =>
			seq(
				'"',
				repeat(
					choice(
						/[^"\\]/, // Any character except " and \
						$.escape_sequence // Escape sequences
					)
				),
				'"'
			),

		// - Raw string literals
		raw_string_literal: ($) => seq('`', repeat(/[^`]/), '`'),

		escape_sequence: (_) =>
			token.immediate(
				seq(
					'\\',
					choice(
						/[\\abfnrtv'"]/,
						/x[0-9a-fA-F]{2}/,
						/u[0-9a-fA-F]{4}/,
						/U[0-9a-fA-F]{8}/,
						/\d{2,3}/
					)
				)
			),

		// Byte literals
		byte_literal: ($) =>
			token(
				seq(
					"'",
					choice(
						seq('\\', choice(/[^xu]/, /x[0-9a-fA-F]{2}/)),
						/[^\\']/
					),
					"'"
				)
			),

		// Rune literals
		rune_literal: ($) =>
			token(
				seq(
					"'",
					optional(
						choice(
							seq(
								'\\',
								choice(
									/[^xu]/,
									/u[0-9a-fA-F]{4}/,
									/u\{[0-9a-fA-F]+\}/,
									/x[0-9a-fA-F]{2}/
								)
							),
							/[^\\']/
						)
					),
					"'"
				)
			),

		// Nil literal
		nil_literal: ($) => 'nil',

		//----Types--------------//
		_type: ($) => choice($.primitive_type),

		primitive_type: (_) => choice(...primitiveTypes),

		// Composite types
		// - Array types
		//   - Fixed-size arrays
		//   - Dynamic arrays
		// - Slice types
		// - Map types
		// - Struct types
		// Function types
		// Pointer types
		// Generic types
		// - Type parameters
		// - Constraints
		// Type aliases
		// Type conversions

		//----Statements---------//
		_statement: ($) =>
			choice(
				$._declaration,
				$._expression_statement,
				$.assignment_statement
			),

		_expression_statement: ($) => seq($._expression, terminator),

		assignment_statement: ($) =>
			choice($.simple_assign, $.composite_assign),

		simple_assign: ($) =>
			prec.right(
				PREC.assign,
				seq(
					field('left', choice($.assign_list, $._expression)),
					field('operator', '='),
					field('right', choice($.expression_list, $._expression))
				)
			),

		assign_list: ($) => commaSep1(field('item', $._assignable)),

		_assignable: ($) => choice($._expression, $.ignore_operator),

		expression_list: ($) => commaSep1($._expression),

		composite_assign: ($) =>
			prec.right(
				PREC.assign,
				seq(
					field('left', $._expression),
					field('operator', $.assignment_operator),
					field('right', $._expression)
				)
			),

		// Control flow statements
		// - If statements
		//   - If-else chains
		//   - If with initialization
		// - For statements
		//   - C-style for loops
		//   - For-each loops
		//   - Infinite loops
		// - Match statements
		//   - Match arms
		//   - Default case
		// - Return statements
		// - Break statements
		// - Continue statements
		// Defer statements
		// Expression statements

		//----Declarations-------//
		_declaration: ($) => choice($.var_decl),

		var_decl: ($) => choice($.let_decl, $.const_decl, $.static_decl),

		let_decl: ($) => choice($.single_decl, $.multi_decl),

		single_decl: ($) =>
			seq(
				'let',
				optional($.mut_flag),
				field('name', choice($._value_identifier, $.ref_pattern)),
				optional(seq(':', field('type', $._type))),
				optional(seq('=', field('value', $._expression)))
			),

		multi_decl: ($) =>
			seq(
				'let',
				field('pattern', $.tuple_pattern),
				'=',
				field(
					'values',
					choice($.expression_list, seq('(', $.expression_list, ')'))
				)
			),

		const_decl: ($) =>
			seq(
				'const',
				field('name', $._value_identifier),
				optional(seq(':', field('type', $._type))),
				'=',
				field('value', $._expression)
			),

		static_decl: ($) =>
			seq(
				'static',
				field('name', $._value_identifier),
				optional(seq(':', field('type', $._type))),
				'=',
				field('value', $._expression)
			),

		// Variable declarations
		// - Single variable
		// - Multiple variables
		// - With type inference
		// - With explicit type
		// Constant declarations
		// Static declarations
		// Function declarations
		// - Function parameters
		// - Return types
		// - Function body
		// Method declarations
		// - Receiver parameter
		// Struct declarations
		// - Struct fields
		// Enum declarations
		// - Enum values
		// - Methods on enums
		// Type alias declarations
		// Generic type declarations

		//----Identifiers--------//
		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		_value_identifier: ($) => alias($.identifier, $.value_identifier),

		// Type identifiers

		_type_identifier: ($) => alias($.identifier, $.type_identifier),
		// Variable identifiers
		// Function identifiers
		// Field identifiers
		// Method identifiers
		// Package identifiers
		// Label identifiers

		//----Tokens--------//

		mut_flag: () => 'mut',

		//----Expressions--------//
		_expression: ($) =>
			choice($._non_block_expression, $._block_expression),

		_non_block_expression: ($) => choice($.identifier, $._literal, $._type),

		_block_expression: ($) => choice(),
		// Binary expressions
		// - Arithmetic
		// - Logical
		// - Comparison
		// - Bitwise
		// Unary expressionsn
		// Function calls
		// Method calls
		// Member access
		// - Struct field access
		// - Array/slice indexing
		// - Map key access
		// Index expressions
		// Slice expressions
		// Type assertions
		// Type conversions
		// Parenthesized expressions
		// Anonymous functions
		// Struct literals
		// Array/slice literals
		// Map literals
		//----Operators----------//

		// Assignment operators
		assignment_operator: (_) =>
			choice(
				'+=',
				'-=',
				'*=',
				'/=',
				'%=',
				'&=',
				'|=',
				'^=',
				'<<=',
				'>>='
			),

		// Ignore operators
		ignore_operator: (_) => '_',

		// Arithmetic operators
		// Comparison operators
		// Logical operators
		// Bitwise operators

		//----Patterns------------//

		_pattern_item: ($) =>
			choice(
				$.mut_pattern,
				$.ref_pattern,
				$._value_identifier,
				$.ignore_operator
			),

		tuple_pattern: ($) =>
			seq('(', commaSep1(field('item', $._pattern_item)), ')'),

		mut_pattern: ($) =>
			seq(
				$.mut_flag,
				field('item', choice($._value_identifier, $.ref_pattern))
			),

		ref_pattern: ($) => seq('&', field('item', $._value_identifier))
		//----Modules------------//
		// Import declarations
		// - Single import
		// - Multiple imports
		// - Aliased imports
		// Package clause

		//----Generics-----------//
		// Generic type declarations
		// - Type parameters
		// - Constraints
		// Generic function declarations
		// Generic type instantiations
		// Generic interface declarations
	}
})

//----Helpers------------//
function sep1(rule, separator) {
	return seq(rule, repeat(seq(separator, rule)))
}

function commaSep1(rule) {
	return seq(rule, repeat(seq(',', rule)))
}

function commaSep(rule) {
	return optional(commaSep1(rule))
}
