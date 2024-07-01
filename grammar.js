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
	assign: 0, // Assignment
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

	supertypes: ($) => [$._expression, $._type, $._literals],

	conflicts: ($) => [[$._type, $._expression], [$.call_expression]],

	inline: ($) => [$._type_identifier],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => seq(repeat($._statement)),

		_statement: ($) =>
			choice($._expression_statement, $._declaration_statement),

		// ===============
		// Declarations
		// ===============
		_declaration_statement: ($) =>
			choice(
				$.function_declaration,
				$.function_signature,
				$.variable_declaration,
				$.struct_declaration,
				$.enum_declaration
			),

		function_declaration: ($) =>
			prec.right(
				1,
				seq(
					// does static keyword belong here?
					optional(field('modifier', choice($.unsafe, $.cpp))),
					'fn',
					field('name', $.identifier),
					field(
						'type_parameters',
						optional($.generic_type_parameters)
					),
					field('parameters', $.parameters),
					optional($.return_type),
					field('body', optional($.block))
				)
			),

		function_signature: ($) =>
			seq(
				optional(field('modifier', choice($.unsafe, $.cpp))),
				'fn',
				field('name', $.identifier),
				field('type_parameters', optional($.generic_type_parameters)),
				field('parameters', $.parameters),
				optional($.return_type),
				field('body', optional($.block))
			),

		generic_type_parameters: ($) =>
			seq(token.immediate('['), sepBy(',', $.type_param), ']'),

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
				optional(seq(':', field('type', $._type)))
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

		variadic_argument: ($) =>
			prec.right(choice(seq($._expression, '...'), '...')),

		argument_list: ($) =>
			seq(
				'(',
				optional(
					seq(
						choice($._expression, $.variadic_argument),
						repeat(
							seq(',', choice($._expression, $.variadic_argument))
						),
						optional(',')
					)
				),
				')'
			),

		variable_declaration: ($) =>
			seq(
				choice('const', 'let', 'static'),
				choice(
					$.declaration_list,
					seq(
						optional($.mutable_flag),
						$.declaration_content,
						optional(
							seq(
								'=',
								field(
									'value',
									choice($.map_literal, $._expression)
								)
							)
						)
					)
				)
			),

		declaration_list: ($) =>
			prec.right(
				seq(
					'(',
					sepBy(',', $.declaration_item),
					')',
					optional(
						seq('=', sepBy(',', field('value', $._expression)))
					)
				)
			),

		declaration_item: ($) =>
			choice(
				$.declaration_content,
				seq($.mutable_flag, $.declaration_content),
				'_'
			),

		declaration_content: ($) =>
			seq(
				field('name', $.identifier),
				optional(seq(':', field('type', $._type)))
			),

		struct_declaration: ($) =>
			seq(
				'struct',
				field('name', $._type_identifier),
				optional(field('type_parameters', $.generic_type_parameters)),
				field('body', $.struct_body)
			),

		struct_body: ($) => seq('{', repeat($.struct_field_list), '}'),

		struct_field_list: ($) =>
			choice($.field_member, $.default_field_member),

		field_member: ($) =>
			seq(
				field('name', $._field_identifier),
				':',
				field('type', $._type)
			),

		default_field_member: ($) =>
			seq($.field_member, '=', field('default_value', $._expression)),

		enum_declaration: ($) =>
			seq(
				'enum',
				field('name', $._type_identifier),
				optional(seq(':', field('type', $._type))),
				field('body', $.enum_body)
			),

		enum_body: ($) =>
			seq('{', sepBy(',', $.enum_member), optional(','), '}'),

		enum_member: ($) =>
			seq(
				field('name', $.identifier),
				optional(seq(':', field('value', $._expression)))
			),

		// ===============
		// Expressions
		// ===============
		_expression_statement: ($) =>
			prec.left(
				choice(
					seq($._expression, optional($.terminator)),
					prec(1, $._expression_ending_with_block)
				)
			),

		_expression: ($) =>
			choice(
				$.unary_expression,
				$.binary_expression,
				$.call_expression,
				$.struct_expression,
				$.assignment_expression,
				$.compound_assignment_expr,
				$.slice_expression,
				$.index_expression,
				$.array_expression,
				$.return_expression,
				$.inc_expr,
				$.dec_expr,
				$._type,
				$._literals,
				$.identifier
			),

		_expression_ending_with_block: ($) =>
			choice($.block, $.for_expression, $.if_expression),

		call_expression: ($) =>
			prec(
				PREC.call,
				seq(
					optional(field('modifier', $.co)),
					field('function', $._expression),
					optional(field('type_arguments', $.type_arguments)),
					field('arguments', $.argument_list)
				)
			),

		assignment_expression: ($) =>
			prec.left(
				PREC.assign,
				seq(
					field('left', $._expression),
					'=',
					field('right', $._expression)
				)
			),

		compound_assignment_expr: ($) =>
			prec.left(
				PREC.assign,
				seq(
					field('left', $._expression),
					field(
						'operator',
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
						)
					),
					field('right', $._expression)
				)
			),

		struct_expression: ($) =>
			prec(
				1,
				seq(
					field('name', $._type_identifier),
					field('body', $.struct_fields)
				)
			),

		struct_fields: ($) =>
			seq(
				'{',
				optional(
					sepBy(',', choice($.struct_named_element, $.struct_element))
				),
				optional(','),
				'}'
			),
		struct_element: ($) => choice($._expression, $.struct_fields),

		struct_named_element: ($) =>
			seq(
				field('field', $._field_identifier),
				':',
				field('value', $.struct_element)
			),

		return_expression: ($) =>
			choice(
				prec.left(seq('ret', field('values', $._expression))),
				prec(-1, 'ret')
			),

		array_expression: ($) =>
			seq('[', repeat(seq($._expression, optional(','))), ']'),

		slice_expression: ($) =>
			prec(
				PREC.call,
				seq(
					field('operand', $._expression),
					choice('[', token.immediate('[')),
					optional(field('first', $._expression)),
					token.immediate(':'),
					optional(field('second', $._expression)),
					']'
				)
			),

		index_expression: ($) =>
			prec(
				PREC.call,
				seq(
					field('operand', $._expression),
					choice('[', token.immediate('[')),
					field('index', $._expression),
					']'
				)
			),

		//==================
		//Control Flow
		//==================

		for_expression: ($) =>
			seq(
				'for',
				optional(choice($.while_next, $.for_each, $._expression)),
				field('body', $.block)
			),

		while_next: ($) =>
			prec.left(
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
			prec.left(
				1,
				seq(
					field('iter', choice('_', $._expression, $.identifier)),
					optional(
						seq(
							token.immediate(','),
							field(
								'value',
								choice('_', $._expression, $.identifier)
							)
						)
					),
					alias('in', $.keyword),
					field('right', choice($._expression, $._type_identifier))
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

		unary_expression: ($) =>
			prec.left(
				PREC.unary,
				seq(
					field('operator', $.unary_operator),
					field('operand', $._expression)
				)
			),

		inc_expr: ($) => seq($._expression, '++'),

		dec_expr: ($) => seq($._expression, '--'),

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

		// ===============
		// Types
		// ===============
		_type: ($) =>
			choice(
				$.primitive_type,
				$.function_type,
				$.array_type,
				$.map_type,
				$.generic_type,
				alias($.identifier, $.type_identifier),
				$._literals
			),

		primitive_type: (_) => choice(...primitiveTypes),

		function_type: ($) =>
			prec.right(
				seq(
					prec(
						PREC.call,
						seq('fn', field('parameters', $.parameters))
					),
					optional(seq(':', field('return_type', $._type)))
				)
			),

		generic_type: ($) =>
			prec(
				1,
				seq(
					field('type', $._type_identifier),
					field('type_arguments', $.type_arguments)
				)
			),

		type_arguments: ($) =>
			prec.dynamic(2, seq('[', sepBy(',', $.type_param), ']')),

		type_param: ($) =>
			prec(
				1,
				choice(
					$._type,
					$.type_constraint_param,
					alias($.identifier, $.type_identifier)
				)
			),

		//TODO: fix precedence
		type_constraint_param: ($) =>
			prec(
				1,
				seq(
					field('name', $.identifier),
					':',
					choice(
						sepBy1('|', field('constraint', $._type)),
						field('constraint', $._type)
					)
				)
			),

		array_type: ($) =>
			prec(
				1,
				seq(
					'[',
					optional(
						choice(
							field('auto_size', '...'),
							field('length', choice($.integer, $.identifier))
						)
					),
					']',
					field('element', $._type)
				)
			),

		map_type: ($) =>
			seq('map[', field('key', $._type), ']', field('value', $._type)),

		// ===============
		// Literals
		// ===============

		_literals: ($) =>
			choice($.integer, $.float, $.bool, $.char, $.string, $.raw_string),

		map_literal: ($) =>
			seq('{', sepBy(',', $.map_entry), optional(','), '}'),

		map_entry: ($) =>
			seq(
				field('key', $._expression),
				':',
				field('value', $._expression)
			),

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
					'}',
					optional($.terminator)
				)
			),

		// ===============
		// Keywords
		// ===============
		mutable_flag: (_) => 'mut',

		terminator: (_) => ';',

		exception_flag: (_) => '!',

		static: (_) => 'static',
		cpp: (_) => 'cpp',
		unsafe: (_) => 'unsafe',
		co: (_) => 'co',

		// ===============
		// Identifiers
		// ===============
		identifier: (_) => /[\p{XID_Start}][_0-9\p{XID_Continue}]*/,

		_type_identifier: ($) => alias($.identifier, $.type_identifier),

		_field_identifier: ($) => alias($.identifier, $.field_identifier),

		// ===============
		// Operators
		// ===============
		unary_operator: (_) => choice('~', '!', '-', '-%'),

		// ===============
		// Comments
		// ===============
		comment: ($) => choice($.line_comment, $.block_comment),

		line_comment: ($) => token(seq('//', /[^\r\n]*/)),
		block_comment: ($) => token(seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))
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
