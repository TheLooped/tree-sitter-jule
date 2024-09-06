const DIGIT = /[0-9]/
const HEX_DIGIT = /[0-9a-fA-F]/
const BIN_DIGIT = /[01]/
const OCT_DIGIT = /[0-7]/

const underscore = optional('_')
const digits = (digit) => seq(digit, repeat(seq(underscore, digit)))

const intLiteral = token(
	choice(
		seq(
			optional('-'),
			choice(
				seq('0', choice('x', 'X'), underscore, digits(HEX_DIGIT)),
				seq('0', choice('b', 'B'), underscore, digits(BIN_DIGIT)),
				seq(
					'0',
					optional(choice('o', 'O')),
					underscore,
					digits(OCT_DIGIT)
				),
				seq(optional('0'), digits(DIGIT))
			)
		)
	)
)

const exponent = seq(
	choice('e', 'E', 'p', 'P'),
	optional(choice('+', '-')),
	digits(DIGIT)
)

const floatLiteral = token(
	seq(
		optional('-'),
		choice(
			seq(
				digits(DIGIT),
				'.',
				optional(digits(DIGIT)),
				optional(exponent)
			),
			seq(digits(DIGIT), exponent),
			seq('.', digits(DIGIT), optional(exponent)),
			seq(
				'0',
				choice('x', 'X'),
				underscore,
				choice(
					seq(digits(HEX_DIGIT), '.', optional(digits(HEX_DIGIT))),
					seq(digits(HEX_DIGIT)),
					seq('.', digits(HEX_DIGIT))
				),
				exponent
			)
		)
	)
)

module.exports = grammar({
	name: 'jule',
	rules: {
		source_file: ($) => repeat($._literals),

		//---Literals---//
		_literals: ($) =>
			choice(
				$.number_literal,
				$.bool_literal,
				$.nil_literal,
				$.string_literal,
				$.raw_string_literal,
				$.byte_literal,
				$.rune_literal
			),

		//---Numeric Literals---//
		number_literal: ($) => choice($.integer_literal, $.float_literal),

		integer_literal: ($) => intLiteral,
		float_literal: ($) => floatLiteral,

		//---Bool Literals---//
		bool_literal: ($) => choice('true', 'false'),

		//---Nil Literal---//
		nil_literal: ($) => 'nil',

		//---String Literals---//
		string_literal: ($) =>
			seq(
				'"',
				repeat(
					choice(
						alias(
							token.immediate(prec(1, /[^\\"\n]+/)),
							$.string_content
						),
						$.escape_sequence
					)
				),
				'"'
			),

		// Raw String Literal
		raw_string_literal: ($) =>
			seq('`', alias(token(/[^`]*/), $.raw_string_content), '`'),

		// Escape Sequence
		escape_sequence: ($) =>
			token.immediate(
				seq(
					'\\',
					choice(
						/[\\abfnrtv'"]/,
						/x[0-9a-fA-F]{2}/,
						/u[0-9a-fA-F]{4}/,
						/U[0-9a-fA-F]{8}/,
						/[0-7]{1,3}/
					)
				)
			),

		// Byte literal
		byte_literal: ($) =>
			token(
				seq(
					"'",
					choice(
						seq('\\', choice(/[^xu]/, /x[0-9a-fA-F]{2}/)),
						/[!-~]/
					),
					"'"
				)
			),

		// Rune literal
		rune_literal: ($) =>
			token(
				seq(
					"'",
					choice(
						seq(
							'\\',
							choice(
								/[^xu]/,
								/u[0-9a-fA-F]{4}/,
								/u\{[0-9a-fA-F]+\}/,
								/x[0-9a-fA-F]{2}/,
								/U[0-9a-fA-F]{8}/
							)
						),
						/[^\\']/
					),
					"'"
				)
			)
	}
})
