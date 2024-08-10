//----Constants----------//

// Operator Precedences
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
	assign: -2 // Assignment
}

//  Type Information

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
	'rune',
	'byte',
	'bool',
	'str',
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

	extras: ($) => [$.block_comment, $.line_comment, /\s|\\\r?\n/],

	supertypes: ($) => [$._expression, $._type, $._literal, $._pattern_item],

	inline: ($) => [$._path, $._field_identifier, $._block_expression],

	conflicts: ($) => [
		[$._path_identifier, $._value_identifier],
		[$._type_identifier, $._value_identifier],
		[$._type_identifier, $._non_block_expression],
		[$._value_identifier, $._type_identifier, $._non_block_expression],
		[$._type_identifier, $.struct_expression, $._non_block_expression],
		[$.struct_expression, $._non_block_expression],
		[$.generic_param, $._non_block_expression],
		[$.expression_list, $.else_statment],
		[$.call_expression],
		[$.expression_list],
		[$.expression_list, $.arguments]
	],

	word: ($) => $.identifier,

	rules: {
		//----Source Structure----//
		// File structure

		source_file: ($) =>
			seq(repeat(seq($._statement, terminator)), optional($._statement)),

		//----Comments-----------//
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
				$.nil_literal,
				$.array_literal,
				$.map_literal
			),

		// Array literals
		array_literal: ($) =>
			prec.right(
				choice(
					seq(
						'[',

						']'
					),
					seq(
						'[',
						choice(
							commaSep1($._expression),
							seq($._expression, ',', '...')
						),
						optional(','),
						']'
					)
				)
			),

		//Map literals
		map_literal: ($) =>
			prec.right(
				-4,
				seq('{', commaSep1($.map_entry), optional(','), '}')
			),

		map_entry: ($) =>
			prec(
				1,
				seq(
					field('key', $._expression),
					':',
					field('value', $._expression)
				)
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
						alias(
							token.immediate(prec(1, /[^\\"\n]+/)),
							$.string_content
						),
						$.escape_sequence
					)
				),
				'"'
			),

		raw_string_literal: ($) =>
			seq('`', repeat(alias(token(/[^`]/), $.raw_string_content)), '`'),

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
									/x[0-9a-fA-F]{2}/,
									/U[0-9a-fA-F]{8}/
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
		_type: ($) =>
			choice(
				$._type_identifier,
				$.scoped_type_identifier,
				$.primitive_type,
				$.cpp_type,
				$.function_type,
				$.generic_type,
				$.slice_type,
				$.array_type,
				$.auto_sized_array_type,
				$.map_type,
				$.pointer_type,
				$.reference_type
			),

		primitive_type: (_) => choice(...primitiveTypes),

		generic_type: ($) =>
			prec.left(
				-1,
				seq(
					field(
						'type_name',
						choice($._type_identifier, $.scoped_type_identifier)
					),
					optional(field('type_args', $.type_arguments))
				)
			),

		type_arguments: ($) =>
			prec.dynamic(
				2,
				seq('[', commaSep1($.generic_constraint), optional(','), ']')
			),

		cpp_type: ($) => prec.right(-1, seq($.cpp_flag, '.', $._type)),

		pointer_type: ($) =>
			prec(
				PREC.unary,
				seq('*', choice($._type, $.scoped_type_identifier))
			),

		reference_type: ($) =>
			prec(
				PREC.unary,
				seq(
					'&',
					field('type', choice($._type, $.scoped_type_identifier))
				)
			),

		map_type: ($) =>
			seq(
				'map[',
				field('key_type', $._type),
				']',
				field('value_type', $._type)
			),

		slice_type: ($) =>
			prec.right(seq('[', ']', field('element_type', choice($._type)))),

		array_type: ($) =>
			prec.right(
				seq(
					'[',
					field('length', $._expression),
					']',
					field('element_type', choice($._type))
				)
			),

		auto_sized_array_type: ($) =>
			seq('[', '...', ']', field('element_type', choice($._type))),

		// Function types
		function_type: ($) =>
			prec.left(
				-1,
				seq(
					'fn',
					field('parameters', $.parameters),
					optional(seq(':', field('return_type', $._return_type)))
				)
			),

		//----Statements---------//
		_statement: ($) =>
			choice(
				$.label,
				$.pragma,
				$.goto_statement,
				$._declaration,
				$._expression_statement,
				$.return_statement,
				$.continue_statement,
				$.break_statement
			),

		_expression_statement: ($) =>
			prec.left(seq($._expression, optional(terminator))),

		pragma: ($) =>
			prec.left(
				seq(
					'#',
					field('directive', $.identifier),
					optional(field('argument', $._expression))
				)
			),

		label: ($) =>
			prec.left(
				-4,
				seq(
					field('label', alias($.identifier, $.label_identifier)),
					token.immediate(':'),
					optional(terminator)
				)
			),

		goto_statement: ($) =>
			prec.right(
				seq(
					'goto',
					field('label', alias($.identifier, $.label_identifier))
				)
			),

		//  Return statements
		return_statement: ($) =>
			prec.right(
				seq('ret', optional(field('values', $.expression_list)))
			),

		// Break statements
		break_statement: ($) =>
			prec.right(
				seq(
					'break',
					optional(
						field('label', alias($.identifier, $.label_identifier))
					)
				)
			),

		// Continue statements
		continue_statement: ($) =>
			prec.right(
				seq(
					'continue',
					optional(
						field('label', alias($.identifier, $.label_identifier))
					)
				)
			),

		assignment_statement: ($) =>
			choice($.simple_assign, $.composite_assign),

		simple_assign: ($) =>
			prec.right(
				PREC.assign,
				seq(
					field('left', alias($.expression_list, $.assign_list)),
					field('operator', '='),
					field('right', $.expression_list)
				)
			),

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

		//------------Control Flow------------//
		for_statement: ($) => seq('for', choice($._for_clause)),

		_for_clause: ($) => prec(-1, choice($.for_each, $.while_next, $.block)),

		for_each: ($) =>
			prec.right(
				seq(
					field(
						'iter',
						choice(
							$._pattern_item,
							commaSep($._pattern_item),
							$.tuple_pattern
						)
					),
					field('keyword', $.in),
					field('collection', $._expression),

					field('body', $.block)
				)
			),

		while_next: ($) =>
			prec.right(
				seq(
					choice(
						seq(
							field('condition', $._expression),
							optional(seq(';', field('update', $._expression)))
						),
						seq(
							optional(field('condition', $._expression)),
							seq(';', field('update', $._expression))
						)
					),
					field('body', $.block)
				)
			),

		if_statement: ($) =>
			prec.right(
				seq(
					'if',
					choice(
						seq('(', field('condition', $._expression), ')'),
						field('condition', $._expression)
					),
					field('consequence', $.block),
					optional(field('alternative', $.else_block))
				)
			),

		else_block: ($) => seq('else', choice($.block, $.if_statement)),

		else_statment: ($) =>
			seq(
				field('condition', $._expression),
				'else',
				field('body', $.block)
			),

		// - Match statements

		match_statement: ($) =>
			seq(
				'match',
				optional($.match_subject),
				field('body', $.match_block)
			),

		match_subject: ($) => choice($._expression, seq($.type, $._expression)),

		match_block: ($) =>
			prec(
				-1,
				seq(
					'{',
					repeat($.match_branch),
					optional($.match_default_branch),
					'}'
				)
			),

		match_branch: ($) =>
			prec(
				10,
				seq(
					field('pattern', repeat1($.match_case)),
					token.immediate(':'),
					optional(
						choice(
							field('body', $._expression),
							seq(
								field('body', $._statement),
								repeat(
									seq(terminator, field('body', $._statement))
								),
								optional(terminator)
							)
						)
					)
				)
			),

		match_default_branch: ($) =>
			seq('|:', optional(repeat1(field('body', $._statement)))),

		match_case: ($) =>
			prec(
				10,
				seq(
					field('guard', token('|')),
					field('case', choice($._expression, $._statement))
				)
			),

		//----Declarations-------//
		_declaration: ($) =>
			choice(
				$.use_decl,
				$._var_decl,
				$.function_decl,
				$.static_fn_decl,
				$.struct_decl,
				$.enum_decl,
				$.type_alias,
				$.trait_decl,
				$.impl_decl
			),

		use_decl: ($) => choice(seq('use', choice($._use_clause)), $.cpp_use),

		_use_clause: ($) =>
			choice($._path, $.scoped_use, $.aliased_use, $.wildcard_use),

		cpp_use: ($) => seq($.cpp_flag, 'use', $.string_literal),

		aliased_use: ($) =>
			prec(
				-1,
				seq(
					field('alias', $._value_identifier),
					'for',
					field('path', choice($._path, $.scoped_use, $.wildcard_use))
				)
			),

		scoped_use: ($) =>
			seq(
				field('path', $._path),
				'::',
				field('items', $.scoped_use_list)
			),

		scoped_use_list: ($) =>
			seq(
				'{',
				optional(
					seq(
						commaSep1(field('name', $._value_identifier)),
						optional(',')
					)
				),
				'}'
			),

		wildcard_use: ($) => seq(field('path', $._path), '::', '*'),

		// Variable declarations
		_var_decl: ($) => choice($.let_decl, $.const_decl, $.static_decl),

		// Let declarations
		let_decl: ($) => choice($.single_decl, $.multi_decl),

		single_decl: ($) =>
			prec.left(
				seq(
					optional($.cpp_flag),
					'let',
					optional($.mut_flag),
					field('name', choice($._value_identifier, $.ref_pattern)),
					optional(seq(':', field('type', choice($._type)))),
					optional(seq('=', field('value', $._expression)))
				)
			),

		multi_decl: ($) =>
			seq(
				'let',
				choice(field('pattern', $.tuple_pattern)),
				'=',
				field(
					'values',
					choice($.expression_list, seq('(', $.expression_list, ')'))
				)
			),

		// Constant declarations
		const_decl: ($) =>
			seq(
				'const',
				field('name', $._value_identifier),
				optional(seq(':', field('type', choice($._type, $._type)))),
				'=',
				field('value', $._expression)
			),

		// Static declarations
		static_decl: ($) =>
			seq(
				'static',
				optional($.mut_flag),
				field('name', $._value_identifier),
				optional(seq(':', field('type', choice($._type, $._type)))),
				'=',
				field('value', $._expression)
			),

		// Function declarations

		function_decl: ($) =>
			seq(
				optional($.function_modifier),
				'fn',
				field('name', $._value_identifier),
				optional(field('generic_params', $.generic_params)),
				field('parameters', $.parameters),
				optional($.error_specifier),
				optional(
					seq(optional(':'), field('return_type', $._return_type))
				),
				choice(field('body', $.block), terminator)
			),

		static_fn_decl: ($) => seq('static', $.function_decl),

		// Generic type declarations
		generic_param: ($) =>
			seq(
				field('param_type', $._type),
				optional(seq(':', field('constraint', $.generic_constraint)))
			),

		generic_constraint: ($) => sep1(field('type', $._type), '|'),

		generic_params: ($) =>
			seq('[', commaSep1(field('param', $.generic_param)), ']'),
		// - Function parameters
		parameters: ($) =>
			seq(
				'(',
				commaSep(
					choice(
						$._parameter,
						$.receiver_parameter,
						$.variadic_parameter
					),
					optional(',')
				),
				')'
			),

		_parameter: ($) =>
			choice(
				seq(
					field(
						'name',
						choice(
							$._value_identifier,
							$.ref_pattern,
							$.mut_pattern
						)
					),
					optional(seq(':', field('type', choice($._type))))
				),
				$._type
			),

		variadic_parameter: ($) =>
			seq(
				seq(
					optional($.mut_flag),
					field('name', $._value_identifier),
					':'
				),
				'...',
				field('type', choice($._type))
			),

		receiver_parameter: ($) =>
			seq(optional($.mut_flag), optional('&'), $.self),

		error_specifier: ($) => '!',

		// - Return types
		_return_type: ($) => choice($._type, $.tuple_type, $.named_return_type),

		tuple_type: ($) => seq('(', commaSep1(choice($._type)), ')'),

		named_return_type: ($) =>
			seq(
				'(',
				commaSep1(
					seq(
						optional(field('name', $._value_identifier)),
						':',
						field('type', choice($._type))
					)
				),
				')'
			),

		type_alias: ($) =>
			seq(
				optional($.cpp_flag),
				$.type,
				field('name', $._type_identifier),
				':',
				field('type', $._type)
			),

		struct_decl: ($) =>
			seq(
				optional($.cpp_flag),
				'struct',
				field('name', $._value_identifier),
				optional(field('generic_params', $.generic_params)),
				field('body', $.struct_fields)
			),

		struct_fields: ($) => seq('{', repeat($._struct_decl_field), '}'),

		_struct_decl_field: ($) => choice($.regular_field, $.default_field),

		regular_field: ($) =>
			seq(
				optional($.mut_flag),
				field('name', $._field_identifier),
				':',
				field('value', $._type)
			),

		default_field: ($) =>
			seq(
				optional($.mut_flag),
				field('name', $._field_identifier),
				':',
				field('value', $._type),
				'=',
				field('default_value', $._expression)
			),

		//-------Implementations-------//
		impl_decl: ($) =>
			seq(
				'impl',
				optional(
					seq(
						field(
							'trait',
							choice(
								alias($.identifier, $.trait_identifier),
								$.scoped_identifier
							)
						),
						'for'
					)
				),
				field(
					'struct',
					choice(
						alias($.identifier, $.struct_identifier),
						$.scoped_identifier
					)
				),
				field('body', $.block)
			),

		//-------Trait-------//
		trait_decl: ($) =>
			seq(
				'trait',
				field('name', $._value_identifier),
				field('body', $.trait_body)
			),

		trait_body: ($) =>
			seq(
				'{',
				repeat(
					choice($.identifier, $.scoped_identifier, $._declaration)
				),
				'}'
			),

		//------Enums-----//
		enum_decl: ($) =>
			seq(
				'enum',
				field('name', alias($.identifier, $.enum_identifier)),
				optional(seq(':', field('type', $._type))),
				field('body', $.enum_body)
			),

		enum_body: ($) => seq('{', commaSep($.enum_member), optional(','), '}'),

		enum_member: ($) =>
			prec(
				1,
				seq(
					field('name', $._expression),
					optional(seq(':', field('value', $._expression)))
				)
			),

		//----Identifiers--------//
		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		// Value identifiers
		_value_identifier: ($) => alias($.identifier, $.value_identifier),

		// Type identifiers
		_type_identifier: ($) => alias($.identifier, $.type_identifier),

		// Field identifiers
		_field_identifier: ($) => alias($.identifier, $.field_identifier),

		// Path identifiers
		_path_identifier: ($) => alias($.identifier, $.path_identifier),

		_path: ($) => choice($._path_identifier, $.scoped_identifier),

		scoped_identifier: ($) =>
			prec.right(
				PREC.field, // Use field precedence
				seq(
					field('path', $._path),
					'::',
					field('name', $._value_identifier)
				)
			),

		scoped_type_identifier: ($) =>
			prec.right(
				PREC.field, // Use field precedence
				seq(
					field('path', $._path),
					'::',
					field('name', $._type_identifier)
				)
			),

		function_modifier: ($) =>
			choice(
				seq($.cpp_flag, $.unsafe_flag),
				$.unsafe_flag,
				$.cpp_flag,
				$.co_flag
			),

		//----Keywords--------//

		self: () => 'self',

		type: () => 'type',

		in: () => 'in',

		mut_flag: () => 'mut',

		unsafe_flag: () => 'unsafe',

		cpp_flag: () => 'cpp',

		co_flag: () => 'co',

		fallthrough: () => 'fall',

		//----Expressions--------//
		_expression: ($) =>
			choice($._non_block_expression, $._block_expression),

		_non_block_expression: ($) =>
			choice(
				$.assignment_statement,
				$.unary_expression,
				$.binary_expression,
				$.ref_expression,
				$.call_expression,
				$.field_expression,
				$.index_expression,
				$.paren_expression,
				$.type_cast_expression,
				$.scoped_identifier,
				$.self,
				$.identifier,
				$._literal,
				$._type
			),

		_block_expression: ($) =>
			choice(
				$.block,
				$.defer_block,
				$.unsafe_block,
				$.if_statement,
				$.anonymous_function,
				$.struct_expression,
				$.match_statement,
				$.for_statement,
				$.else_statment
			),

		struct_expression: ($) =>
			prec.dynamic(
				1,
				seq(
					optional(
						field(
							'name',
							choice(
								alias($.identifier, $.struct_identifier),
								$.scoped_identifier
							)
						)
					),
					optional(field('generic', $.generic_params)),
					field('body', $.struct_list)
				)
			),

		struct_list: ($) =>
			prec(2, seq('{', commaSep($.struct_item), optional(','), '}')),

		struct_item: ($) =>
			prec.left(
				2,
				choice(
					field('field', $._expression),
					seq(
						field('field', $._field_identifier),
						token.immediate(':'),
						field('value', $._expression)
					)
				)
			),

		// Anonymous functions
		anonymous_function: ($) =>
			seq(
				optional($.function_modifier),
				'fn',
				field('parameters', $.parameters),
				optional(seq(':', field('return_type', $._return_type))),
				field('body', $.block)
			),

		// Field Access expressions
		field_expression: ($) =>
			prec.right(
				PREC.field,
				seq(
					field('object', choice($._expression, $.cpp_flag)),
					'.',
					field('property', $._expression)
				)
			),

		// Slice expressions
		slice_expression: ($) =>
			prec.right(
				PREC.call,
				seq(
					field('object', $._expression),
					'[',
					optional(field('start', $._expression)),
					':',
					optional(field('end', $._expression)),
					']'
				)
			),

		// Indexed expressions
		index_expression: ($) =>
			prec(
				PREC.call,
				choice(
					seq(
						field('object', $._expression),
						'[',
						field('index', $._expression),
						']'
					),
					$.slice_expression
				)
			),

		// Parenthesized expressions
		paren_expression: ($) => prec(-1, seq('(', $._expression, ')')),

		// Function calls
		call_expression: ($) =>
			prec(
				PREC.call,
				seq(
					optional($.co_flag),
					field('caller', $._expression),
					optional(field('type_arguments', $.generic_params)),
					field('arguments', $.arguments),
					optional($.error_specifier)
				)
			),

		arguments: ($) =>
			prec.right(
				PREC.call,
				seq(
					'(',
					commaSep(choice($._expression, $.variadic_argument)),
					optional(','),
					')'
				)
			),

		variadic_argument: ($) => prec.right(seq($._expression, '...')),

		ref_expression: ($) =>
			prec.right(PREC.unary, seq('&', field('value', $._expression))),

		// Unary expressionsn
		unary_expression: ($) =>
			choice(
				...[
					['~', PREC.unary],
					['-', PREC.unary],
					['!', PREC.unary],
					['^', PREC.unary],
					['*', PREC.unary],
					['+', PREC.unary]
				].map(([operator, precedence]) =>
					prec.right(
						precedence,
						seq(
							field('operator', operator),
							field('operand', $._expression)
						)
					)
				),
				prec.left(
					PREC.unary,
					seq(
						field('operand', $._expression),
						field('operator', choice('++', '--'))
					)
				)
			),

		// Binary expressions
		binary_expression: ($) => {
			const table = [
				[PREC.or, '||'],
				[PREC.and, '&&'],
				[PREC.comparative, choice('==', '!=', '<', '<=', '>', '>=')],
				[PREC.bitor, '|'],
				[PREC.bitxor, '^'],
				[PREC.bitand, '&'],
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

		type_cast_expression: ($) => choice($._paren_cast, $._simple_cast),

		// Assuming you can only cast with primitive types
		_paren_cast: ($) =>
			prec(
				PREC.cast,
				seq(
					'(',
					field('type', $.primitive_type),
					')',
					'(',
					field('value', $._expression),
					')'
				)
			),

		_simple_cast: ($) =>
			prec(
				PREC.cast,
				seq(
					field('type', $.primitive_type),
					'(',
					field('operand', $._expression),
					optional(','),
					')'
				)
			),

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
			prec.left(
				seq(
					$.mut_flag,
					field(
						'item',
						choice($._type, $._value_identifier, $.ref_pattern)
					)
				)
			),

		ref_pattern: ($) =>
			prec.right(seq('&', field('item', $._value_identifier))),

		//----Blocks------------//
		block: ($) =>
			seq(
				'{',
				repeat(seq($._statement, terminator)),
				optional($._statement),
				'}'
			),

		unsafe_block: ($) => seq(optional($.cpp_flag), $.unsafe_flag, $.block),

		defer_block: ($) => seq(optional($.unsafe_flag), 'defer', $.block)
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
