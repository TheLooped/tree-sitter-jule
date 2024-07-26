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
	assign: 0 // Assignment
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
		[$._expression, $._single_declarator, $._type_identifier],
		[$._expression, $._field_identifier, $._type_identifier],
		[$._type_identifier, $._expression],
		[$._type, $._expression],
		[$.simple_cast, $._expression],
		[$.parenthesized_cast, $._expression],
		[$._composite_type, $._expression],
		[$._type, $.type_param],
		[$.call_expression]
	],

	extras: ($) => [/\s|\\\r?\n/, $.line_comment, $.block_comment],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(seq($._statement, optional(terminator))),

		_statement: ($) =>
			choice(
				$._declaration,
				seq($._expression_statement, terminator),
				$._simple_statement,
				$.label
			),

		_declaration: ($) =>
			choice(
				$.use_declaration,
				$.function_declaration,
				$._variable_declaration,
				$.struct_declaration,
				$.enum_declaration,
				$.impl_declaration,
				$.trait_declaration,
				$.type_alias_declaration
			),

		_simple_statement: ($) =>
			choice($.assignment_statement, $.compound_assignment_statement),

		_expression_statement: ($) =>
			choice($._expression, prec(-1, $._expression_ending_with_block)),

		_expression: ($) =>
			choice(
				$.slice_expression,
				$._composite_expression,
				$.indexed_expression,
				$.function_literal,
				$.parenthesized_expression,
				$.return_expression,
				$.call_expression,
				$.field_expression,
				$.break_expression,
				$.continue_expression,
				$.cast_expression,
				$.identifier,
				$._literals,
				$._type,
				$.self,
				alias($.scoped_type_identifier, $.scoped_identifier)
			),

		_expression_ending_with_block: ($) =>
			choice(
				$.block,
				$.for_expression,
				$.if_expression,
				$.match_expression,
				$.struct_expression
			),

		_composite_expression: ($) =>
			choice(
				$.array_expression,
				$.map_expression,
				$.inc_expression,
				$.dec_expression,
				$.unary_expression,
				$.binary_expression,
				$.reference_expression
			),

		//------------Expressions------------//

		slice_expression: ($) =>
			prec.right(
				PREC.call,
				seq(
					field('operand', $._expression),
					'[',
					optional(field('first', $._expression)),
					':',
					optional(field('second', $._expression)),
					']',
					optional($.variadic_flag)
				)
			),

		reference_expression: ($) =>
			prec(PREC.unary, seq('&', field('value', $._expression))),

		unary_expression: ($) =>
			prec.left(
				PREC.unary,
				seq(
					field('operator', $.unary_operator),
					field('operand', $._expression)
				)
			),

		binary_expression: ($) => {
			const table = [
				[PREC.and, '&&'],
				[PREC.or, '||'],
				[PREC.bitand, '&'],
				[PREC.bitor, '|'],
				[PREC.bitxor, '^'],
				[PREC.comparative, choice('==', '!=', '<', '<=', '>', '>=')],
				[PREC.shift, choice('<<', '>>')],
				[PREC.additive, choice('+', '-')],
				[PREC.multiplicative, choice('*', '/', '%')]
			]

			return choice(
				...table.map(([precedence, operator]) =>
					prec.left(
						precedence,
						seq(
							field('left', $._expression),
							field(
								'operator',
								alias(operator, $.binary_operator)
							),
							field('right', $._expression)
						)
					)
				)
			)
		},
		inc_expression: ($) => prec(-1, seq($._expression, '++')),
		dec_expression: ($) => prec(-1, seq($._expression, '--')),

		break_expression: ($) =>
			prec.left(seq('break', optional(field('label', $.identifier)))),

		continue_expression: ($) =>
			prec.left(seq('continue', optional(field('label', $.identifier)))),

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
			prec.left(
				PREC.field,
				seq(
					field('value', $._expression),
					'.',
					field('field', choice($._expression, $._field_identifier))
				)
			),

		indexed_expression: ($) =>
			prec.left(
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
			prec(
				-3,
				seq('{', optional(commaSep($.map_entry)), optional(','), '}')
			),

		map_entry: ($) =>
			prec(
				-2,
				seq(
					field('key', $._expression),
					':',
					field('value', $._expression)
				)
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
				optional($.match_value),
				'{',
				repeat($.match_case),
				optional($.default_case),
				'}'
			),

		match_value: ($) => seq(optional('type'), $._expression),

		match_case: ($) => seq('|', $.case_expression_list, ':', $._statement),

		case_expression_list: ($) => sep1($.case, '|'),

		case: ($) => $._expression,

		default_case: ($) => seq('|:', $._statement),

		type_alias_declaration: ($) =>
			seq('type', $.identifier, ':', field('type', $._type)),

		cast_expression: ($) =>
			prec(PREC.cast, choice($.parenthesized_cast, $.simple_cast)),

		parenthesized_cast: ($) =>
			seq(
				'(',
				field('type', $._type),
				')',
				'(',
				field('value', $._expression),
				')'
			),

		simple_cast: ($) =>
			seq(
				field('type', $._type),
				'(',
				field('value', $._expression),
				')'
			),

		//------------Declarations------------//

		//------Use------//
		use_declaration: ($) => seq('use', $._use_clause),

		_use_clause: ($) =>
			choice(
				$.wildcard,
				$.aliased,
				$.grouped,
				$.scoped_type_identifier,
				$.identifier
			),

		wildcard: ($) =>
			seq(
				optional(
					seq(choice($.scoped_type_identifier, $.identifier), '::')
				),
				'*'
			),

		aliased: ($) =>
			prec(
				1,
				seq(
					field('alias', $.identifier),
					'for',
					field('path', $._aliased_path)
				)
			),

		_aliased_path: ($) =>
			choice(
				$.scoped_type_identifier,
				$.identifier,
				$.wildcard,
				$.grouped
			),

		grouped: ($) =>
			seq(
				field(
					'path',
					optional(
						seq(
							choice($.identifier, $.scoped_type_identifier),
							'::'
						)
					)
				),
				field(
					'list',
					seq(
						'{',
						commaSep(
							choice(
								$.identifier,
								$.scoped_type_identifier,
								$.wildcard
							)
						),
						optional(','),
						'}'
					)
				)
			),

		scoped_type_identifier: ($) =>
			seq(
				field('path', choice($.identifier, $.scoped_type_identifier)),
				'::',
				field('name', $.identifier)
			),

		//------Functions------//
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
					optional(field('body', $.block))
				)
			),

		function_literal: ($) =>
			prec.right(
				seq(
					'fn',
					optional(field('name', $.identifier)),
					field('parameters', $.parameters),
					optional($.return_type),
					field('body', $.block)
				)
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
				optional('&'),
				field('name', $.identifier),
				optional(seq(':', field('type', $._type)))
			),

		self_parameter: ($) =>
			choice(
				$.self,
				seq(optional('&'), optional($.mutable_flag), $.self)
			),

		variadic_parameter: ($) =>
			seq(
				field('name', $.identifier),
				':',
				$.variadic_flag,
				field('type', $._type)
			),

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

		//------Variables-----//

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
				optional(seq(':', field('type', $._type))),
				'=',
				field('value', $._expression)
			),

		_declarator_list: ($) =>
			choice($._single_declarator, $.multi_declarator),

		_single_declarator: ($) =>
			seq(optional('&'), field('name', $.identifier)),

		multi_declarator: ($) => seq('(', commaSep($.declaration_item), ')'),

		declaration_item: ($) =>
			choice(
				$._single_declarator,
				seq($.mutable_flag, $._single_declarator),
				$._expression_statement,
				'_'
			),

		assignment_statement: ($) =>
			prec.left(
				PREC.assign,
				seq(
					field('left', commaSep($._expression_statement)),
					'=',
					field('right', commaSep($._expression_statement))
				)
			),
		compound_assignment_statement: ($) =>
			prec.left(
				PREC.assign,
				seq(
					field('left', $._expression_statement),
					field('operator', $.assignment_operator),
					field('right', $._expression_statement)
				)
			),
		//------Structs-----//
		struct_declaration: ($) =>
			seq(
				'struct',
				field('name', $.identifier),
				optional(field('type_parameters', $.generic_parameters)),
				field('body', $.struct_decl_body)
			),

		struct_decl_body: ($) => seq('{', repeat($.struct_decl_field), '}'),

		struct_decl_field: ($) => choice($.regular_field, $.default_field),

		regular_field: ($) =>
			seq(
				optional($.mutable_flag),
				field('name', $._field_identifier),
				':',
				field('type', $._type)
			),

		default_field: ($) =>
			seq(
				optional($.mutable_flag),
				field('name', $._field_identifier),
				':',
				field('type', $._type),
				'=',
				field('default_value', $._expression)
			),

		struct_expression: ($) =>
			prec(
				1,
				seq(
					field('name', $.identifier),
					field('body', $.struct_expr_body)
				)
			),

		struct_expr_body: ($) =>
			seq(
				'{',
				optional(commaSep($.struct_expr_field)),
				optional(','),
				'}'
			),

		struct_expr_field: ($) =>
			choice(
				seq(
					field('field', $._field_identifier),
					':',
					field('value', $._expression)
				),
				$._expression
			),

		//-------Implementations-------//
		impl_declaration: ($) =>
			seq(
				'impl',
				optional(seq(field('trait', $.identifier), 'for')),
				field('struct', $.identifier),
				field('body', $.impl_body)
			),

		impl_body: ($) => seq('{', repeat($._declaration), '}'),

		//-------Trait-------//
		trait_declaration: ($) =>
			seq(
				'trait',
				field('name', $.identifier),
				field('body', $.trait_body)
			),

		trait_body: ($) =>
			seq('{', repeat(choice($.trait_item, $._declaration)), '}'),

		trait_item: ($) => $.identifier,

		//------Enums-----//
		enum_declaration: ($) =>
			seq(
				'enum',
				field('name', $._type_identifier),
				optional(seq(':', field('type', $._type))),
				field('body', $.enum_body)
			),

		enum_body: ($) => seq('{', commaSep($.enum_member), optional(','), '}'),

		enum_member: ($) =>
			seq(
				field('name', $.identifier),
				optional(seq(':', field('value', $._expression)))
			),
		//------------Types------------//

		_type: ($) =>
			choice(
				$._composite_type,
				$.primitive_type,
				$._type_identifier,
				$._literals
			),

		_composite_type: ($) =>
			choice(
				$.array_type,
				$.auto_sized_array_type,
				$.slice_type,
				$.map_type,
				$.function_type,
				$.generic_type,
				$.reference_type,
				$.pointer_type,
				$.scoped_type_identifier
			),

		primitive_type: (_) => choice(...primitiveTypes),

		reference_type: ($) =>
			prec(PREC.unary, seq('&', field('type', $._type))),

		pointer_type: ($) => prec(PREC.unary, seq('*', $._type)),

		function_type: ($) =>
			prec.right(
				-1,
				seq(
					'fn',
					field('parameters', $.parameters),
					optional(seq(':', field('return_type', $._type)))
				)
			),

		generic_type: ($) =>
			prec(
				-1,
				seq(
					field('type', $._type_identifier),
					field('type_arguments', $.type_arguments)
				)
			),

		type_arguments: ($) =>
			seq('[', commaSep(choice($._type, $.type_param)), ']'),

		type_param: ($) =>
			choice($._literals, $.type_constraint_param, $._type_identifier),

		type_constraint_param: ($) =>
			seq(
				field('name', $.identifier),
				':',
				choice(
					sep(field('constraint', $._type), '|'),
					field('constraint', $._type)
				)
			),

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

		unsafe_block: ($) => seq('unsafe', $.block),

		defer_block: ($) => seq(optional($.unsafe_flag), 'defer', $.block),

		//------------Operators------------//
		unary_operator: (_) => prec.left(choice('~', '!', '-', '-%')),

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

		//------------Comments------------//
		line_comment: ($) => token(seq('//', /(\\+(.|\r?\n)|[^\\\n])*/)),
		block_comment: ($) =>
			token(seq('/*', /[^*]*[*]+(?:[^/*][^*]*[*]+)*/, '/')),

		//------------Tokens------------//
		mutable_flag: ($) => 'mut',

		self: ($) => 'self',

		fall: ($) => 'fall',

		variadic_flag: ($) => '...',

		exception_flag: ($) => '!',

		label: ($) =>
			prec(-4, seq(field('label', $.identifier), token.immediate(':'))),

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
