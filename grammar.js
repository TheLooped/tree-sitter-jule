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

const DIGIT = /[0-9]/
const HEX_DIGIT = /[0-9a-fA-F]/
const BIN_DIGIT = /[01]/
const OCT_DIGIT = /[0-7]/
const UNDERSCORE_SEP = /_?/

const primitiveTypes = numericTypes.concat(['bool', 'str'])

const newline_terminator = token(prec.dynamic(-1, /\r?\n/))

const terminator = choice(newline_terminator, ';')

module.exports = grammar({
	name: 'jule',

	conflicts: ($) => [
		[$._expression, $.generic_parameter, $._type_identifier],
		[$._type_identifier, $._expression],
		[$._primary_type, $.generic_type],
		[$._type, $._expression],
		[$.call_expression]
	],

	extras: ($) => [$.comment, /\s+/],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(seq($._statement, optional(terminator))),

		_statement: ($) =>
			choice($._declaration, seq($._expression_statement, terminator)),

		_declaration: ($) =>
			choice(
				$.function_declaration,
				$._variable_declaration,
				$.assignment_statement,
				$.function_signature
			),

		_expression_statement: ($) =>
			choice($._expression, $._expression_ending_with_block),

		_expression: ($) =>
			choice(
				$._composite_expression,
				$._literals,
				$._type,
				$.identifier,
				$.indexed_expression,
				$.parenthesized_expression,
				$.return_expression,
				$.call_expression,
				$.field_expression,
				$.break_expression,
				$.continue_expression
			),

		_expression_ending_with_block: ($) =>
			choice(
				$.block,
				$.for_expression,
				$.if_expression,
				$.match_expression
			),

		_composite_expression: ($) =>
			choice(
				$.array_expression,
				$.map_expression,
				$.inc_expression,
				$.dec_expression
			),

		//------------Expressions------------//

		inc_expression: ($) => prec(-1, seq($._expression, '++')),
		dec_expression: ($) => prec(-1, seq($._expression, '--')),

		break_expression: ($) =>
			prec.left(seq('break', optional(field('label', $.identifier)))),

		continue_expression: ($) =>
			prec.left(seq('continue', optional($.identifier))),

		call_expression: ($) =>
			prec(
				PREC.call,
				choice(
					seq(
						optional($.co_flag),
						field('function', $.identifier),
						field('arguments', $.arguments)
					),
					seq(
						optional($.co_flag),
						field('function', $._expression),
						field('type_arguments', optional($.generic_parameters)),
						field('arguments', $.arguments)
					)
				)
			),

		arguments: ($) => seq('(', commaSep($._expression), optional(','), ')'),

		field_expression: ($) =>
			prec(
				PREC.field,
				seq(
					field('value', $._expression),
					'.',
					field('field', $._field_identifier)
				)
			),

		indexed_expression: ($) =>
			prec(
				PREC.call,
				seq(
					field('object', $._expression),
					'[',
					field('index', $._expression),
					']'
				)
			),

		parenthesized_expression: ($) => seq('(', $._expression, ')'),

		map_expression: ($) =>
			seq('{', optional(commaSep($.map_entry)), optional(','), '}'),

		map_entry: ($) =>
			seq(
				field('key', $._expression),
				':',
				field('value', $._expression)
			),

		array_expression: ($) =>
			prec.right(
				seq(
					'[',
					optional(
						choice(
							commaSep($._expression),
							seq($._expression, ',', '...')
						)
					),
					optional(','),
					']'
				)
			),

		return_expression: ($) =>
			prec.right(
				choice(
					seq(
						'ret',
						choice(
							field('values', $._expression),
							commaSep1(field('values', $._expression))
						)
					),
					prec(-1, 'ret')
				)
			),

		//------------Control Flow------------//
		for_expression: ($) =>
			seq(
				'for',
				optional(choice($.while_next, $.for_each, $._expression)),
				field('body', $.block)
			),

		while_next: ($) =>
			prec.right(
				seq(
					optional(
						seq(field('initializer', optional($._expression)), ';')
					),
					field('condition', optional($._expression)),
					';',
					field('update', optional($._expression))
				)
			),

		for_each: ($) =>
			prec.right(
				seq(
					field('iter', choice('_', $._expression)),
					optional(
						seq(
							token.immediate(','),
							field('value', choice('_', $._expression))
						)
					),
					alias('in', $.keyword),
					field('right', choice($._expression))
				)
			),

		if_expression: ($) =>
			prec.right(
				seq(
					'if',
					field('condition', $._expression),
					field('consequence', $.block),
					optional(field('alternative', $.else_block))
				)
			),

		else_block: ($) => seq('else', choice($.block, $.if_expression)),

		match_expression: ($) =>
			seq(
				'match',
				optional(field('type_flag', alias('type', $.keyword))),
				optional(field('value', $._expression)),
				field('body', $.match_block)
			),

		match_block: ($) =>
			seq('{', repeat1($.match_arm), optional($.last_match_arm), '}'),

		match_arm: ($) =>
			prec.right(
				seq(
					choice(
						field('patterns', repeat(seq('|', $.match_pattern))),
						$.multiple_patterns
					),
					':',
					field('value', $.match_arm_body)
				)
			),

		last_match_arm: ($) => seq('|:', field('value', $.match_arm_body)),

		match_pattern: ($) => choice($._expression),

		multiple_patterns: ($) =>
			seq($._expression, repeat1(seq('|', $._expression))),

		match_arm_body: ($) =>
			prec.right(
				choice(seq(repeat1($._statement), optional($.fall)), $.fall)
			),

		//------------Declarations------------//

		function_declaration: ($) =>
			prec.right(
				1,
				seq(
					field('modifiers', optional($._function_modifiers)),
					'fn',
					field('name', $.identifier),
					optional(field('generic_params', $.generic_parameters)),
					field('parameters', $.parameters),
					optional($.return_type),
					field('body', $.block)
				)
			),

		function_signature: ($) =>
			seq(
				field('modifiers', optional($._function_modifiers)),
				'fn',
				field('name', $.identifier),
				optional(field('generic_params', $.generic_parameters)),
				field('parameters', $.parameters),
				optional($.return_type),
				field('body', optional($.block))
			),

		parameters: ($) =>
			seq(
				'(',
				commaSep(
					seq(
						choice(
							$.parameter,
							$.self_parameter,
							$.variadic_parameter
						)
					)
				),
				optional(','),
				')'
			),

		parameter: ($) =>
			seq(
				optional($.mutable_flag),
				field('name', $.identifier),
				optional(seq(':', field('type', $._type)))
			),

		self_parameter: ($) =>
			seq(optional('&'), optional($.mutable_flag), $.self),

		generic_parameter: ($) =>
			choice(
				field('name', $.identifier),
				seq(
					field('name', $.identifier),
					':',
					field('constraint', $.generic_constraint)
				)
			),

		generic_constraint: ($) => sep1(field('type', $._type), '|'),

		generic_parameters: ($) =>
			seq('[', commaSep1(field('parameter', $.generic_parameter)), ']'),

		return_type: ($) =>
			choice(
				$.single_return_type,
				$.multiple_return_types,
				$.named_return_types,
				$.generic_return_type
			),

		single_return_type: ($) =>
			seq(optional($.exception_flag), ':', field('type', $._type)),

		generic_return_type: ($) =>
			seq(optional($.exception_flag), field('type', $._type)),

		multiple_return_types: ($) =>
			seq(
				optional($.exception_flag),
				':',
				'(',
				commaSep1(field('type', $._type)),
				')'
			),

		named_return_types: ($) =>
			seq(
				optional($.exception_flag),
				':',
				'(',
				commaSep1($.named_return_type),
				')'
			),

		named_return_type: ($) =>
			seq(field('name', $.identifier), ':', field('type', $._type)),

		variadic_parameter: ($) =>
			seq(
				field('name', $.identifier),
				':',
				'...',
				field('type', $._type)
			),

		_variable_declaration: ($) =>
			choice(
				$.let_declaration,
				$.const_declaration,
				$.static_declaration
			),

		let_declaration: ($) =>
			prec.right(
				seq(
					'let',
					optional($.mutable_flag),
					$._declarator_list,
					optional(seq(':', field('type', $._type))),
					optional(
						seq(
							'=',
							field('value', commaSep($._expression_statement))
						)
					)
				)
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
					field('left', commaSep($._expression_statement)),
					'=',
					field('right', commaSep($._expression_statement))
				)
			),

		_declarator_list: ($) =>
			choice($._single_declarator, $.multi_declarator),

		_single_declarator: ($) => field('name', $.identifier),

		multi_declarator: ($) =>
			seq('(', commaSep($._expression_statement), ')'),

		//------------Types------------//

		_type: ($) => choice($._primary_type, $._composite_type, $._literals),

		_primary_type: ($) => choice($.primitive_type, $._type_identifier),

		_composite_type: ($) =>
			choice(
				$.array_type,
				$.auto_sized_array_type,
				$.slice_type,
				$.map_type,
				$.function_type,
				$.generic_type
			),

		primitive_type: (_) => choice(...primitiveTypes),

		function_type: ($) =>
			prec.right(
				seq(
					'fn',
					field('parameters', $.parameters),
					optional(seq(':', field('return_type', $._type)))
				)
			),

		generic_type: ($) =>
			seq(
				field('base_type', $._type_identifier),
				optional(field('type_arguments', $.generic_type_arguments))
			),

		generic_type_arguments: ($) =>
			seq('[', commaSep1(field('argument', $._type)), ']'),

		map_type: ($) =>
			seq(
				'map',
				'[',
				field('key_type', $._type),
				']',
				field('value_type', $._type)
			),

		array_type: ($) =>
			prec.right(
				seq(
					'[',
					field('length', $._expression),
					']',
					field('element_type', $._type),
					optional($._multi_dimensional_array)
				)
			),

		_multi_dimensional_array: ($) =>
			prec.right(
				seq(
					'[',
					field('length', $._expression),
					']',
					field('element_type', $._type),
					optional($._multi_dimensional_array)
				)
			),

		auto_sized_array_type: ($) =>
			seq('[', '...', ']', field('type', $._type)),

		slice_type: ($) => seq('[', ']', field('type', $._type)),

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
			choice(
				$._decimal_integer,
				$._binary_integer,
				$._octal_integer,
				$._hexadecimal_integer
			),

		_decimal_integer: ($) =>
			token(seq(DIGIT, repeat(seq(UNDERSCORE_SEP, DIGIT)))),

		_binary_integer: ($) =>
			token(
				seq(/0[bB]/, BIN_DIGIT, repeat(seq(UNDERSCORE_SEP, BIN_DIGIT)))
			),

		_octal_integer: ($) =>
			token(
				seq(/0[oO]?/, OCT_DIGIT, repeat(seq(UNDERSCORE_SEP, OCT_DIGIT)))
			),

		_hexadecimal_integer: ($) =>
			token(
				seq(/0[xX]/, HEX_DIGIT, repeat(seq(UNDERSCORE_SEP, HEX_DIGIT)))
			),

		float_literal: ($) =>
			choice(
				$._decimal_float,
				$._exponential_float,
				$._hexadecimal_float
			),

		_decimal_float: ($) =>
			token(
				seq(
					optional(seq(DIGIT, repeat(seq(UNDERSCORE_SEP, DIGIT)))),
					'.',
					optional(seq(DIGIT, repeat(seq(UNDERSCORE_SEP, DIGIT))))
				)
			),

		_exponential_float: ($) =>
			token(
				seq(
					seq(
						optional(
							seq(DIGIT, repeat(seq(UNDERSCORE_SEP, DIGIT)))
						),
						'.',
						optional(seq(DIGIT, repeat(seq(UNDERSCORE_SEP, DIGIT))))
					),
					/[eE]/,
					optional(/[-+]/),
					DIGIT,
					repeat(seq(UNDERSCORE_SEP, DIGIT))
				)
			),

		_hexadecimal_float: ($) =>
			token(
				seq(
					/0[xX]/,
					optional(
						seq(HEX_DIGIT, repeat(seq(UNDERSCORE_SEP, HEX_DIGIT)))
					),
					'.',
					optional(
						seq(HEX_DIGIT, repeat(seq(UNDERSCORE_SEP, HEX_DIGIT)))
					),
					/[pP]/,
					optional(/[-+]/),
					DIGIT,
					repeat(seq(UNDERSCORE_SEP, DIGIT))
				)
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

		//------------Blocks------------//
		block: ($) =>
			prec.right(
				-1,
				seq(
					'{',
					optional(repeat($._statement)),
					optional($._expression),
					'}',
					optional(terminator)
				)
			),

		//------------Comments------------//
		comment: ($) => choice($.line_comment, $.block_comment),

		line_comment: ($) => token(seq('//', /[^\r\n]*/)),
		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/')),

		//------------Tokens------------//
		mutable_flag: ($) => 'mut',

		self: ($) => 'self',

		fall: ($) => 'fall',

		exception_flag: ($) => '!',

		label: ($) => seq(field('name', $.identifier), ':'),

		_function_modifiers: ($) =>
			choice($.unsafe_flag, $.cpp_flag, $.static_flag, $.co_flag),

		co_flag: ($) => 'co',

		unsafe_flag: ($) => 'unsafe',

		cpp_flag: ($) => 'cpp',

		static_flag: ($) => 'static',

		//------------Identifiers------------//
		identifier: (_) => /[a-zA-Zα-ωΑ-Ωµ_][a-zA-Zα-ωΑ-Ωµ\d_]*/,

		_type_identifier: ($) => alias($.identifier, $.type_identifier),

		_field_identifier: ($) => alias($.identifier, $.field_identifier)
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
