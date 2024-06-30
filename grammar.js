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

const primitiveTypes = numericTypes.concat([
	'bool',
	'str',
	'char',
	'nil',
	'any'
])

module.exports = grammar({
	name: 'jule',

	extras: ($) => [/\s+/, $.comment],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => seq(repeat($._statement)),

		_statement: ($) =>
			choice($._expression_statement, $._declaration_statement),

		// ===============
		// Declarations
		// ===============
		_declaration_statement: ($) =>
			choice($.function_declaration, $.function_declaration),

		function_declaration: ($) =>
			prec.right(
				seq(
					'fn',
					field('name', $.identifier),
					optional($.parameters),
					field('body', optional($.block)),
					optional(alias(';', $.terminator))
				)
			),

		function_signature: ($) =>
			seq(
				'fn',
				field('name', $.identifier),
				field('parameters', $.parameters),
				optional(seq(':', field('return_type', $._type)))
			),

		parameters: ($) =>
			seq(
				'(',
				sepBy(',', seq(choice($.parameter, $.variadic_parameter))),
				optional(','),
				')'
			),

		parameter: ($) =>
			seq(
				optional($.mutable_flag),
				field('name', $.identifier),
				':',
				field('type', $._type)
			),

		variadic_parameter: ($) =>
			seq(
				field('name', $.identifier),
				':',
				'...',
				field('type', $._type)
			),

		return_type: ($) =>
			seq(optional($.exception_flag), ':', field('return_type', $._type)),

		// ===============
		// Expressions
		// ===============
		_expression_statement: ($) =>
			prec.left(
				choice(
					seq($._expression, optional(alias(';', $.terminator))),
					prec(1, $._expression_ending_with_block)
				)
			),

		_expression: ($) => choice($.identifier),

		_expression_ending_with_block: ($) => choice($.block),

		// ===============
		// Types
		// ===============
		_type: ($) =>
			choice(
				$.primitive_type,
				alias($.identifier, $.type_identifier),
				$._literals
			),

		primitive_type: (_) => choice(...primitiveTypes),

		// ===============
		// Literals
		// ===============

		_literals: ($) =>
			choice($.integer, $.float, $.bool, $.char, $.string, $.raw_string),

		integer: (_) =>
			token(
				seq(choice(/[0-9]+/, /0x[0-9a-fA-F]+/, /0b[01]+/, /0o[0-7]+/))
			),

		float: (_) => {
			const decimal = /[0-9][0-9_]*/
			const hexadecimal = /[0-9a-fA-F][0-9a-fA-F_]*/
			return prec.left(
				token(
					seq(
						choice(
							seq(/0[xX]/, hexadecimal, '.', hexadecimal),
							seq(decimal, '.', decimal)
						),
						optional(/[eEpP][+-]?\d+/)
					)
				)
			)
		},

		char: ($) => seq("'", optional(choice($.escape_sequence, /./)), "'"),

		string: ($) =>
			seq(
				'"',
				repeat(choice($.escape_sequence, /[^"\\]+/)),
				token.immediate('"')
			),

		raw_string: (_) => token(seq('`', repeat(/[^`]/), '`')),

		escape_sequence: (_) =>
			token.immediate(
				seq(
					'\\',
					choice(
						/[^xu\n]/,
						/u[0-9a-fA-F]{4}/,
						/u\{[0-9a-fA-F]+\}/,
						/x[0-9a-fA-F]{2}/
					)
				)
			),

		bool: (_) => choice('true', 'false'),

		// ===============
		// Blocks
		// ===============
		block: ($) =>
			prec.left(
				seq(
					'{',
					optional(repeat($._statement)),
					optional($._expression),
					'}'
				)
			),

		// ===============
		// Keywords
		// ===============
		mutable_flag: (_) => 'mut',

		terminator: (_) => ';',

		exception_flag: (_) => '!',

		// ===============
		// Comments
		// ===============
		comment: ($) => choice($.line_comment, $.block_comment),

		line_comment: ($) => token(seq('//', /[^\r\n]*/)),
		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')),

		identifier: (_) => /[\p{XID_Start}][_0-9\p{XID_Continue}]*/
	}
})

// ===============
// Functions
// ===============
function sepBy1(sep, rule) {
	return seq(rule, repeat(seq(sep, rule)), optional(sep))
}
function sepBy(sep, rule) {
	return optional(sepBy1(sep, rule))
}
