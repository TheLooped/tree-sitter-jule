const PRIMITIVE_TYPES = [
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
	'rune',
	'byte',
	'bool',
	'str',
	'any'
]

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

const terminator = choice('\n', ';', '\0')

module.exports = grammar({
	name: 'jule',

	extras: ($) => [$.block_comment, $.line_comment, /\s|\\\r?\n/],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(seq($._statement, terminator)),

		_statement: ($) => choice($._var_decl, $._expression, $.use_decl),

		_expression: ($) =>
			choice($._literals, $._types, $.qualified_identifier, $.identifier),

		expression_list: ($) => commaSep1($._expression),

		//---Declarations---//

		// Use Declaration
		use_decl: ($) =>
			seq('use', choice($.simple, $.wildcard, $.selector, $.aliased)),

		simple: ($) => field('path', $.qualified_identifier),

		wildcard: ($) => seq(field('path', $.qualified_identifier), '::*'),

		selector: ($) =>
			seq(
				field('path', $.qualified_identifier),
				'::',
				'{',
				field(
					'items',
					commaSep(choice($.identifier, alias('self', $.self_import)))
				),
				'}'
			),

		aliased: ($) =>
			seq(
				field('alias', $.identifier),
				'for',
				field('import', choice($.simple, $.selector))
			),

		// Variable Declaration
		_var_decl: ($) =>
			choice($.let_decl, $.const_decl, $.static_decl, $.short_decl),

		// Let declarations
		let_decl: ($) => choice($.single_var, $.multi_var),

		single_var: ($) =>
			seq(
				optional($.cpp_flag),
				'let',
				optional($.mut_flag),
				field('name', choice($.identifier, $.ref_pattern)),
				optional(seq(':', field('type', $._types))),
				optional(seq('=', field('value', $._expression)))
			),

		multi_var: ($) =>
			seq(
				'let',
				field('pattern', $.tuple_pattern),
				'=',
				field('values', $.expression_list)
			),

		// Constant declarations
		const_decl: ($) =>
			seq(
				'const',
				field('name', $.identifier),
				optional(seq(':', field('type', $._types))),
				'=',
				field('value', $._expression)
			),

		// Static declarations
		static_decl: ($) =>
			seq(
				'static',
				optional($.mut_flag),
				field('name', $.identifier),
				optional(seq(':', field('type', $._types))),
				'=',
				field('value', $._expression)
			),

		// Short variable declarations
		short_decl: ($) =>
			seq(
				field('names', $.short_names),
				':=',
				field('values', $.expression_list)
			),

		short_names: ($) =>
			seq(
				choice($.identifier, $.ref_pattern, $.mut_pattern),
				repeat(
					seq(',', choice($.identifier, $.ref_pattern, $.mut_pattern))
				)
			),

		//---Identifiers---//
		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		qualified_identifier: ($) =>
			prec.left(
				seq(
					field(
						'namespace',
						choice($.identifier, $.qualified_identifier)
					),
					'::',
					field('member', $.identifier)
				)
			),

		//---Types---//
		_types: ($) => choice($.primitive_type),

		primitive_type: ($) => token(choice(...PRIMITIVE_TYPES)),

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
			token(seq("'", choice(seq('\\', /x[0-9a-fA-F]{2}/), /[!-~]/), "'")),

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
			),

		//---Patterns---//
		cpp_flag: () => 'cpp',
		ignore_operator: () => '_',
		mut_flag: () => 'mut',
		ref_pattern: ($) => seq('&', $.identifier),
		mut_pattern: ($) => seq('mut', choice($.ref_pattern, $.identifier)),
		tuple_pattern: ($) =>
			seq(
				'(',
				commaSep(
					choice(
						$.identifier,
						$.ref_pattern,
						$.mut_pattern,
						$.ignore_operator
					)
				),
				')'
			),

		//---Comments---//

		line_comment: ($) => token(seq('//', /.*/)),

		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))
	}
})

//---Helper Functions---//
function commaSep(rule) {
	return optional(commaSep1(rule))
}

function commaSep1(rule) {
	return seq(rule, repeat(seq(',', rule)))
}
