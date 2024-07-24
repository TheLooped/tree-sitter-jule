const PREC = {
	call: 13, // Function calls
	field: 12, // Field access
	unary: 11, // Unary operators
	cast: 10, // Type casting
	multiplicative: 9, // *, %, /
	shift: 8, // <<, >>
	additive: 7, // +, -
	bitand: 6, // &
	bitxor: 5, // ^ (XOR)
	bitor: 4, // |
	comparative: 3, // ==, !=, <, <=, >, >=
	and: 2, // &&
	or: 1, // ||
	assign: 1, // Assignment
	comment: 0 // Comments
}

const numericTypes = [
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
	'f64'
]

const primitiveTypes = numericTypes.concat(['bool', 'str'])

const terminator = choice('\n', ';')

module.exports = grammar({
	name: 'jule',

	conflicts: ($) => [[$._type, $._expression]],

	extras: ($) => [$.comment, /\s+/],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(seq($._statement, terminator)),

		_statement: ($) => choice($._declaration, $._expression_statement),

		_declaration: ($) =>
			choice($._variable_declaration, $.assignment_statement),

		_expression_statement: ($) => choice($._expression),

		_expression: ($) =>
			choice(
				$._literals,
				$._type,
				$.identifier,
				$.indexed_expression,
				$.parenthesized_expression
			),

		expression_list: ($) => commaSep1($._expression),

		//------------Expressions------------//

		indexed_expression: ($) =>
			seq(
				field('object', $._expression),
				'[',
				field('index', $._expression),
				']'
			),

		parenthesized_expression: ($) => seq('(', $._expression, ')'),

		//------------Declarations------------//

		_variable_declaration: ($) =>
			choice(
				$.let_declaration,
				$.const_declaration,
				$.static_declaration
			),

		let_declaration: ($) =>
			seq(
				'let',
				optional($.mutable_flag),
				$._declarator_list,
				optional(seq(':', field('type', $._type))),
				optional(seq('=', field('value', $.expression_list)))
			),

		const_declaration: ($) =>
			seq(
				'const',
				$._single_declarator,
				optional(seq(':', field('type', $._type))),
				'=',
				field('value', $._expression)
			),

		static_declaration: ($) =>
			seq(
				'static',
				optional($.mutable_flag),
				$._single_declarator,
				':',
				field('type', $._type),
				'=',
				field('value', $._expression)
			),

		assignment_statement: ($) =>
			prec.right(
				PREC.assign,
				seq(
					field('left', $._assignable),
					'=',
					field('right', $.expression_list)
				)
			),

		_declarator_list: ($) =>
			choice($._single_declarator, $.multi_declarator),

		_single_declarator: ($) => field('name', $.identifier),

		multi_declarator: ($) =>
			seq(
				'(',
				commaSep1(
					choice(
						$.identifier,
						$.ignore_operator,
						seq($.mutable_flag, $.identifier)
					)
				),
				')'
			),

		_assignable: ($) =>
			prec(
				PREC.assign,
				seq(
					choice(
						$.identifier,
						$.indexed_expression,
						$.expression_list
					)
				)
			),

		//------------Types------------//

		_type: ($) =>
			choice(
				$.primitive_type,
				alias($.identifier, $.type_identifier),
				$._literals
			),

		primitive_type: (_) => choice(...primitiveTypes),

		//------------Literals------------//
		_literals: ($) =>
			choice(
				$._number_literal,
				$.boolean_literal,
				$.string_literal,
				$.raw_string_literal,
				$.rune_literal,
				$.byte_literal,
				$.nil,
				$.any
			),

		boolean_literal: ($) => choice('true', 'false'),

		_number_literal: ($) =>
			choice($.integer_literal, $.float_literal, $._negative_number),

		_negative_number: ($) => seq('-', $._unsigned_number),

		_unsigned_number: ($) => choice($.integer_literal, $.float_literal),

		integer_literal: ($) =>
			choice($._decimal_integer, $._non_decimal_integer),

		_non_decimal_integer: ($) =>
			choice($._binary_integer, $._octal_integer, $._hexadecimal_integer),

		_decimal_integer: ($) => $._decimal_digits,

		_binary_integer: ($) => seq('0b', $._binary_digits),

		_octal_integer: ($) =>
			choice(seq('0', $._octal_digits), seq('0o', $._octal_digits)),

		_hexadecimal_integer: ($) => seq('0x', $._hex_digits),

		float_literal: ($) =>
			choice(
				$._decimal_float,
				$._exponential_float,
				$._hexadecimal_float
			),

		_decimal_float: ($) =>
			choice(
				seq($._decimal_digits, '.', optional($._decimal_digits)),
				seq('.', $._decimal_digits)
			),

		_exponential_float: ($) =>
			seq(
				$._decimal_float_base,
				/[eE]/,
				optional(/[-+]/),
				$._decimal_digits
			),

		_hexadecimal_float: ($) =>
			seq(
				'0x',
				$._hex_float_base,
				/[pP]/,
				optional(/[-+]/),
				$._decimal_digits
			),

		_decimal_digits: ($) =>
			token(seq(/[0-9]/, repeat(seq(optional('_'), /[0-9]/)))),
		_binary_digits: ($) =>
			token(seq(/[01]/, repeat(seq(optional('_'), /[01]/)))),
		_octal_digits: ($) =>
			token(seq(/[0-7]/, repeat(seq(optional('_'), /[0-7]/)))),
		_hex_digits: ($) =>
			token(
				seq(/[0-9a-fA-F]/, repeat(seq(optional('_'), /[0-9a-fA-F]/)))
			),

		_decimal_float_base: ($) =>
			seq(
				$._decimal_digits,
				optional(seq('.', optional($._decimal_digits)))
			),

		_hex_float_base: ($) =>
			choice(
				seq($._hex_digits, '.', optional($._hex_digits)),
				seq('.', $._hex_digits)
			),

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

		string_literal: ($) => seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'),

		raw_string_literal: ($) => seq('`', repeat(/[^`]/), '`'),

		escape_sequence: (_) =>
			token.immediate(
				seq(
					'\\',
					choice(
						/[^xuU]/,
						/\d{2,3}/,
						/x[0-9a-fA-F]{2,}/,
						/u[0-9a-fA-F]{4}/,
						/U[0-9a-fA-F]{8}/
					)
				)
			),

		nil: ($) => 'nil',
		any: ($) => 'any',

		//------------Comments------------//
		comment: ($) => choice($.line_comment, $.block_comment),

		line_comment: ($) => token(seq('//', /[^\r\n]*/)),
		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')),

		//------------Tokens------------//
		mutable_flag: ($) => 'mut',

		ignore_operator: (_) => '_',

		identifier: (_) => /[a-zA-Zα-ωΑ-Ωµ_][a-zA-Zα-ωΑ-Ωµ\d_]*/
	}
})

//------------Helper Functions------------//

function commaSep(rule) {
	return optional(commaSep1(rule))
}

function commaSep1(rule) {
	return sep1(rule, ',')
}

function commaExternalSep1(rule, $) {
	return sep1(rule, choice(',', alias($._nl_comma, ',')))
}

function sep(rule, sep) {
	return optional(seq(rule, repeat(seq(sep, optional(rule)))))
}

function sep1(rule, sep) {
	return seq(rule, repeat(seq(sep, rule)))
}
