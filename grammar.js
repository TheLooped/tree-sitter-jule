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

const primitiveTypes = numericTypes.concat(['bool', 'str', 'any'])

module.exports = grammar({
	name: 'jule',

	extras: ($) => [$.comment, /\s+/],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(choice($.comment, $._literals)),

		identifier: (_) => /[a-zA-Zα-ωΑ-Ωµ_][a-zA-Zα-ωΑ-Ωµ\d_]*/,

		//------------Literals------------//
		_literals: ($) =>
			choice(
				$.integer_literal,
				$.float_literal,
				$.negative_literal,
				$.boolean_literal,
				$.string_literal,
				$.raw_string_literal,
				$.rune_literal,
				$.byte_literal,
				$.nil,
				$.any
			),

		boolean_literal: ($) => choice('true', 'false'),

		negative_literal: ($) =>
			seq('-', choice($.integer_literal, $.float_literal)),

		integer_literal: ($) =>
			choice(
				$.decimal_integer,
				$.binary_integer,
				$.octal_integer,
				$.hexadecimal_integer
			),

		decimal_integer: ($) =>
			token(seq(/[0-9]/, repeat(seq(optional('_'), /[0-9]/)))),

		binary_integer: ($) =>
			token(seq('0b', /[01]/, repeat(seq(optional('_'), /[01]/)))),

		octal_integer: ($) =>
			token(
				choice(
					seq('0', /[0-7]/, repeat(seq(optional('_'), /[0-7]/))),
					seq('0o', /[0-7]/, repeat(seq(optional('_'), /[0-7]/)))
				)
			),

		hexadecimal_integer: ($) =>
			token(
				seq(
					'0x',
					/[0-9a-fA-F]/,
					repeat(seq(optional('_'), /[0-9a-fA-F]/))
				)
			),

		float_literal: ($) =>
			choice($.decimal_float, $.exponential_float, $.hexadecimal_float),

		decimal_float: ($) =>
			token(
				choice(
					seq(
						/[0-9]/,
						repeat(seq(optional('_'), /[0-9]/)),
						'.',
						optional(
							seq(/[0-9]/, repeat(seq(optional('_'), /[0-9]/)))
						)
					),
					seq('.', /[0-9]/, repeat(seq(optional('_'), /[0-9]/)))
				)
			),

		exponential_float: ($) =>
			token(
				seq(
					/[0-9]/,
					repeat(seq(optional('_'), /[0-9]/)),
					optional(
						seq('.', /[0-9]/, repeat(seq(optional('_'), /[0-9]/)))
					),
					/[eE]/,
					optional(/[-+]/),
					/[0-9]/,
					repeat(seq(optional('_'), /[0-9]/))
				)
			),

		hexadecimal_float: ($) =>
			token(
				seq(
					'0x',
					choice(
						seq(
							/[0-9a-fA-F]/,
							repeat(seq(optional('_'), /[0-9a-fA-F]/)),
							'.',
							optional(
								seq(
									/[0-9a-fA-F]/,
									repeat(seq(optional('_'), /[0-9a-fA-F]/))
								)
							)
						),
						seq(
							'.',
							/[0-9a-fA-F]/,
							repeat(seq(optional('_'), /[0-9a-fA-F]/))
						)
					),
					/[pP]/,
					optional(/[-+]/),
					/[0-9]/,
					repeat(seq(optional('_'), /[0-9]/))
				)
			),

		byte_literal: ($) =>
			token(
				seq(
					"b'",
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
		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))
	}
})
