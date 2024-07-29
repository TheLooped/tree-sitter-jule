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
	assign: -2 //Assignments
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

	extras: ($) => [$.comment, /\s|\\\r?\n/],

	conflicts: ($) => [
		[$._type_identifier, $._value_identifier],
		[$._type_identifier, $._non_block_expression], // cause: for_each
		[$._value_identifier, $._non_block_expression] // cause: struct_init_expr
	],

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
				$.nil_literal,
				$.array_literal,
				$.map_literal
			),

		// Array literals
		array_literal: ($) =>
			prec(
				1,
				seq(
					'[',
					choice(
						commaSep($._expression),
						seq($._expression, ',', '...')
					),
					optional(','),
					']'
				)
			),

		//Map literals
		map_literal: ($) => seq('{', commaSep($.map_entry), optional(','), '}'),

		map_entry: ($) =>
			seq(
				field('key', $._expression),
				':',
				field('value', $._expression)
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
		_type: ($) =>
			choice(
				$.primitive_type,
				$.function_type,
				$.array_type,
				$.auto_sized_array_type,
				$.slice_type,
				$.map_type,
				$.pointer_type,
				$.reference_type,
				$.scoped_type_identifier
			),

		scoped_type_identifier: ($) =>
			seq(
				field('path', choice($.identifier, $.scoped_type_identifier)),
				'::',
				field('name', $.identifier)
			),

		primitive_type: (_) => choice(...primitiveTypes),

		pointer_type: ($) => prec(PREC.unary, seq('*', $._type)),

		reference_type: ($) =>
			prec(PREC.unary, seq('&', field('type', $._type))),

		map_type: ($) =>
			seq(
				'map',
				'[',
				field('key_type', $._type),
				']',
				field('value_type', $._type)
			),

		slice_type: ($) =>
			prec.right(
				seq(
					'[',
					']',
					field('element_type', choice($._type, $._type_identifier))
				)
			),

		array_type: ($) =>
			prec.right(
				seq(
					'[',
					field('length', $._expression),
					']',
					field('element_type', choice($._type, $._type_identifier))
				)
			),

		auto_sized_array_type: ($) =>
			seq(
				'[',
				'...',
				']',
				field('element_type', choice($._type, $._type_identifier))
			),

		// Function types
		function_type: ($) =>
			prec(
				-1,
				seq(
					'fn',
					optional(seq(field('parameters', $.parameters), ':')),
					field('return_type', choice($._type, $._type_identifier))
				)
			),

		// Composite types
		// - Struct types
		// Generic types
		// - Type parameters
		// - Constraints
		// Type aliases

		//----Statements---------//
		_statement: ($) =>
			choice(
				$.label,
				$._declaration,
				$._expression_statement,
				$.match_statement,
				$.continue_statement,
				$.break_statement,
				$.assignment_statement,
				$.return_statement
			),

		label: ($) =>
			prec(
				-4,
				seq(field('label', $._label_identifier), token.immediate(':'))
			),

		_expression_statement: ($) => seq($._expression, terminator),

		//  Return statements
		return_statement: ($) =>
			prec.right(
				seq('ret', optional(field('values', $.expression_list)))
			),

		// Break statements
		break_statement: ($) =>
			prec.right(
				seq('break', optional(field('label', $._label_identifier)))
			),

		// Continue statements
		continue_statement: ($) =>
			prec.right(
				seq('continue', optional(field('label', $._label_identifier)))
			),

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

		//------------Control Flow------------//
		for_statement: ($) =>
			prec(
				-1,
				seq(
					'for',
					optional(choice($.while_next, $.for_each)),
					field('body', $.block)
				)
			),

		while_next: ($) =>
			prec.right(
				seq(
					field('condition', $._expression),
					optional(seq(';', field('update', $._expression)))
				)
			),

		for_each: ($) =>
			prec.right(
				seq(
					choice(
						field('iter', $._pattern_item),
						seq(
							optional('('),
							field('index', $._pattern_item),
							',',
							field('value', $._expression),
							optional(')')
						)
					),
					$.in,
					field('collection', $._expression)
				)
			),

		if_statement: ($) =>
			prec.right(
				seq(
					'if',
					field('condition', $._expression),
					field('consequence', $.block),
					optional(field('alternative', $.else_block))
				)
			),

		else_block: ($) => seq('else', choice($.block, $.if_statement)),

		// - Match statements
		match_statement: ($) =>
			seq(
				'match',
				optional($.match_subject),
				'{',
				repeat($.match_branch),
				optional($.match_default_branch),
				'}'
			),

		match_subject: ($) => choice($._expression, seq('type', $._expression)),

		match_branch: ($) =>
			seq(
				alias('|', $.match_branch_start),
				$.match_case,
				alias(':', $.match_branch_end),
				$._statement,
				optional($.fall)
			),

		match_case: ($) =>
			prec.left(
				1,
				sep1(
					alias($._expression, $.match_pattern),
					alias('|', $.match_pattern_delimiter)
				)
			),

		match_default_branch: ($) =>
			seq(
				alias('|:', $.match_default_pattern),
				$._statement,
				optional($.fall)
			),

		//----Declarations-------//
		_declaration: ($) =>
			choice(
				$.var_decl,
				$.function_decl,
				$.static_fn_decl,
				$.struct_decl,
				$.enum_decl,
				$.type_alias,
				$.trait_decl,
				$.impl_decl
			),

		// Variable declarations
		var_decl: ($) => choice($.let_decl, $.const_decl, $.static_decl),

		// Let declarations
		let_decl: ($) => choice($.single_decl, $.multi_decl),

		single_decl: ($) =>
			seq(
				'let',
				optional($.mut_flag),
				field('name', choice($._value_identifier, $.ref_pattern)),
				optional(
					seq(':', field('type', choice($._type, $._type_identifier)))
				),
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
				field('name', $._value_identifier),
				optional(seq(':', field('type', choice($._type, $._type)))),
				'=',
				field('value', $._expression)
			),

		// Function declarations

		function_decl: ($) =>
			seq(
				'fn',
				field('name', $._value_identifier),
				optional(field('generic_params', $.generic_parameters)),
				field('parameters', $.parameters),
				optional($.error_specifier),
				optional(
					seq(optional(':'), field('return_type', $._return_type))
				),
				choice(field('body', $.block), terminator)
			),

		static_fn_decl: ($) => seq('static', $.function_decl),

		// Generic type declarations
		generic_parameter: ($) =>
			seq(
				field('name', $._type_identifier),
				optional(seq(':', field('constraint', $.generic_constraint)))
			),

		generic_constraint: ($) => sep1(field('type', $._type), '|'),

		generic_parameters: ($) =>
			seq('[', commaSep1(field('parameter', $.generic_parameter)), ']'),

		// - Function parameters
		parameters: ($) =>
			seq(
				'(',
				commaSep(
					choice(
						$._parameter,
						$.receiver_parameter,
						$.variadic_parameter
					)
				),
				')'
			),

		_parameter: ($) =>
			seq(
				optional(
					seq(
						field(
							'name',
							choice(
								$._value_identifier,
								$.ref_pattern,
								$.mut_pattern
							)
						),
						':'
					)
				),
				field('type', choice($._type, $._type_identifier))
			),

		variadic_parameter: ($) =>
			seq(
				field('name', $._value_identifier),
				':',
				'...',
				field('type', choice($._type, $._type_identifier))
			),

		receiver_parameter: ($) =>
			seq(optional($.mut_flag), optional('&'), $.self),

		error_specifier: ($) => '!',

		// - Return types
		_return_type: ($) =>
			choice(
				$._type_identifier,
				$._type,
				$.tuple_type,
				$.named_return_type
			),

		tuple_type: ($) =>
			seq('(', commaSep1(choice($._type, $._type_identifier)), ')'),

		named_return_type: ($) =>
			seq(
				'(',
				commaSep1(
					seq(
						field('name', $._value_identifier),
						':',
						field('type', choice($._type, $._type_identifier))
					)
				),
				')'
			),

		_type_constraint: ($) =>
			sep1(field('constraint', choice($._type, $._type_identifier)), '|'),

		type_alias: ($) =>
			seq(
				'type',
				field('name', $._type_identifier),
				':',
				field('type', $._type)
			),

		struct_decl: ($) =>
			seq(
				'struct',
				field('name', $._value_identifier),
				optional(field('generic_params', $.generic_parameters)),
				field('fields', $.struct_fields)
			),

		struct_fields: ($) => {
			return seq('{', repeat($._struct_decl_field), '}')
		},

		_struct_decl_field: ($) => choice($.regular_field, $.default_field),

		regular_field: ($) =>
			seq(
				optional($.mut_flag),
				field('name', $._field_identifier),
				':',
				field('value', $._expression)
			),

		default_field: ($) =>
			seq(
				optional($.mut_flag),
				field('name', $._field_identifier),
				':',
				field('value', $._expression),
				'=',
				field('default_value', $._expression)
			),

		//-------Implementations-------//
		impl_decl: ($) =>
			seq(
				'impl',
				optional(
					seq(
						field('trait', alias($.identifier, $.trait_identifier)),
						'for'
					)
				),
				field('struct', alias($.identifier, $.struct_identifier)),
				field('body', $.impl_body)
			),

		impl_body: ($) => seq('{', repeat($._declaration), '}'),

		//-------Trait-------//
		trait_decl: ($) =>
			seq(
				'trait',
				field('name', $._value_identifier),
				field('body', $.trait_body)
			),

		trait_body: ($) =>
			seq('{', repeat(choice($.identifier, $._declaration)), '}'),

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
			seq(
				field('name', $.identifier),
				optional(seq(':', field('value', $._expression)))
			),

		// - Function body
		// Method declarations
		// - Receiver parameter
		// Struct declarations
		// - Struct fields
		// Enum declarations
		// - Enum values
		// - Methods on enums
		// Type alias declarations

		//----Identifiers--------//
		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		// Value identifiers
		_value_identifier: ($) => alias($.identifier, $.value_identifier),

		// Type identifiers
		_type_identifier: ($) => alias($.identifier, $.type_identifier),

		// Label identifiers
		_label_identifier: ($) => alias($.identifier, $.label_identifier),

		// Field identifiers
		_field_identifier: ($) => alias($.identifier, $.field_identifier),

		// Variable identifiers
		// Function identifiers
		// Method identifiers
		// Package identifiers

		//----Keywords--------//

		self: () => 'self',

		in: () => 'in',

		mut_flag: () => 'mut',

		unsafe_flag: () => 'unsafe',

		fall: () => 'fall',

		//----Expressions--------//
		_expression: ($) =>
			choice($._non_block_expression, $._block_expression),

		_non_block_expression: ($) =>
			choice(
				$.unary_expression,
				$.binary_expression,
				$.ref_expression,
				$.call_expression,
				$.field_expression,
				$.index_expression,
				$.paren_expression,
				$.variadic_argument,
				$.type_cast_expression,
				$.struct_init_expression,
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
				$.anonymous_function,
				$.for_statement,
				$.if_statement
			),

		// Struct init expression
		struct_init_expression: ($) =>
			prec.left(
				seq(
					field('struct', $._value_identifier),
					'{',
					optional(commaSep($._struct_init_field)),
					optional(','),
					'}'
				)
			),

		_struct_init_field: ($) =>
			choice($.named_init_field, $.default_init_field),

		default_init_field: ($) => $._expression,

		named_init_field: ($) =>
			seq(
				field('name', $._field_identifier),
				':',
				field('value', $._expression)
			),

		// Anonymous functions
		anonymous_function: ($) =>
			seq(
				'fn',
				field('parameters', $.parameters),
				optional(seq(':', field('return_type', $._return_type))),
				field('body', $.block)
			),

		// Field Access expressions
		field_expression: ($) =>
			prec(
				PREC.field,
				seq(
					field('object', $._expression),
					'.',
					field('property', $._value_identifier)
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
			prec.right(
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
					field('caller', $._expression),
					optional(
						field('type_arguments', optional($.generic_parameters))
					),
					field('arguments', $.arguments)
				)
			),

		arguments: ($) => seq('(', optional(commaSep1($._expression)), ')'),

		variadic_argument: ($) => seq($._expression, '...'),

		ref_expression: ($) =>
			prec.left(PREC.unary, seq('&', field('value', $._expression))),

		// Unary expressionsn
		unary_expression: ($) =>
			choice(
				...[
					['~', PREC.unary],
					['-', PREC.unary],
					['!', PREC.unary],
					['^', PREC.unary],
					['*', PREC.unary]
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

		type_cast_expression: ($) =>
			prec(PREC.cast, choice($._paren_cast, $._simple_cast)),

		_paren_cast: ($) =>
			prec(
				PREC.cast,
				seq(
					'(',
					field('type', choice($._type)),
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
					field('type', $._type),
					'(',
					field('value', $._expression),
					')'
				)
			),

		// Method calls
		// Member access
		// - Struct field access
		// - Array/slice indexing
		// - Map key access
		// Struct literals
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
			seq(
				$.mut_flag,
				field('item', choice($._value_identifier, $.ref_pattern))
			),

		ref_pattern: ($) => seq('&', field('item', $._value_identifier)),

		//----Blocks------------//
		block: ($) => prec.left(1, seq('{', repeat($._statement), '}')),

		unsafe_block: ($) => seq($.unsafe_flag, $.block),

		defer_block: ($) => seq(optional($.unsafe_flag), 'defer', $.block)

		//----Modules------------//
		// Import declarations
		// - Single import
		// - Multiple imports
		// - Aliased imports
		// Package clause
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
