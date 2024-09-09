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
	assign: 1 // Assignment
}

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

	conflicts: ($) => [[$.call_expression]],

	word: ($) => $.identifier,

	rules: {
		source_file: ($) => repeat(seq($._statement, terminator)),

		_statement: ($) =>
			choice($._declaration, $._simple_statment, $._expression),

		//---Statments---//
		_simple_statment: ($) => choice($.return_expression),

		//---Expressions---//
		_expression: ($) =>
			choice($._non_block_expression, $._block_expression),

		_block_expression: ($) =>
			choice(
				$.block,
				$.for_expression,
				$.if_expression,
				$.else_expression
			),

		_non_block_expression: ($) =>
			choice(
				$.binary_expression,
				$.unary_expression,
				$.assignment_expression,
				$.call_expression,
				$.field_expression,
				$.parenthesized_expression,
				$.index_expression,
				$.slice_expression,
				$.anonymous_function,
				$._literals,
				$.qualified_identifier,
				$.identifier
			),

		expression_list: ($) => commaSep1($._expression),

		// If expression
		if_expression: ($) =>
			prec.right(
				seq(
					'if',
					field('condition', $._expression),
					field('consequence', $.block),
					optional(field('alternative', $.else_clause))
				)
			),

		else_clause: ($) =>
			choice(seq('else', $.block), seq('else', $.if_expression)),

		else_expression: ($) => seq($._expression, 'else', $.block),

		// for expression
		for_expression: ($) =>
			seq(optional('const'), choice($.for_each, $.while, $.while_next)),

		for_each: ($) =>
			seq(
				'for',
				choice(
					field('index', choice($.ignore_operator, $.identifier)),
					seq(
						field('index', choice($.ignore_operator, $.identifier)),
						',',
						field(
							'element',
							choice($.ignore_operator, $.identifier)
						)
					),
					seq(
						'(',
						optional('mut'),
						field('index', choice($.ignore_operator, $.identifier)),
						',',
						optional('mut'),
						field(
							'element',
							choice($.ignore_operator, $.identifier)
						),
						')'
					)
				),
				alias('in', $.keyword),
				field('collection', $._non_block_expression),

				field('body', $.block)
			),

		while: ($) =>
			seq(
				'for',
				field('condition', $._non_block_expression),
				field('body', $.block)
			),

		while_next: ($) =>
			seq(
				'for',
				field('condition', $._non_block_expression),
				';',
				field('update', $._non_block_expression),
				field('body', $.block)
			),

		// Indexed expressions
		index_expression: ($) =>
			prec.left(
				PREC.call,
				seq(
					field('target', $._non_block_expression),
					choice(
						seq('[', field('index', $._non_block_expression), ']'),
						$.slice_expression
					)
				)
			),

		// Slice expressions
		slice_expression: ($) =>
			seq(
				'[',
				optional(field('start', $._non_block_expression)),
				':',
				optional(field('end', $._non_block_expression)),
				']'
			),

		// Parenthesized expressions
		parenthesized_expression: ($) =>
			prec.dynamic(-1, seq('(', field('content', $._expression), ')')),

		// Field Access expressions
		field_expression: ($) =>
			prec(
				PREC.field,
				seq(
					field('object', $._non_block_expression),
					'.',
					field('property', $._field_identifier)
				)
			),

		// Function calls
		call_expression: ($) =>
			prec(
				PREC.call,
				seq(
					field('function', $._expression),
					optional(field('type_parameters', $.generic_parameters)),
					field('arguments', $.arguments),
					optional($.error_specifier)
				)
			),

		arguments: ($) =>
			seq(
				'(',
				commaSep(choice($._expression, $.variadic_argument)),
				optional(','),
				')'
			),

		variadic_argument: ($) =>
			prec.right(seq($._non_block_expression, '...')),

		// return expression
		return_expression: ($) =>
			prec.left(seq('ret', optional(field('values', $.expression_list)))),

		// assignment expr
		assignment_expression: ($) =>
			prec.right(
				PREC.assign,
				seq(
					field('left', $._expression),
					field('operator', $.assignment_operator),
					field('right', $._expression)
				)
			),

		assignment_operator: (_) =>
			choice(
				'=',
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

		// Unary expressionsn
		unary_expression: ($) =>
			choice(
				...[
					['~', PREC.unary],
					['&', PREC.unary],
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

		//---Declarations---//

		_declaration: ($) => choice($.named_function, $._var_decl, $.use_decl),

		//  Function Declaration
		named_function: ($) =>
			seq(
				optional($.function_modifiers),
				'fn',
				field('name', $.identifier),
				optional(field('generic_params', $.generic_parameters)),
				field('parameters', $.parameters),
				optional($.error_specifier),
				optional(seq(':', field('return_type', $._return_type))),
				$.block
			),

		function_modifiers: ($) => choice('co', 'unsafe', 'cpp', 'static'),

		generic_parameters: ($) =>
			seq('[', commaSep1($.generic_parameter), ']'),

		generic_parameter: ($) =>
			seq(
				field('name', $._type_identifier),
				optional(seq(':', field('constraint', $.type_constraint)))
			),

		type_constraint: ($) => sep1($._types, '|'),

		receiver_parameter: ($) => seq(optional(choice('mut', '&')), 'self'),

		parameters: ($) =>
			seq(
				'(',
				optional(
					commaSep1(
						choice(
							$.parameter,
							$.receiver_parameter,
							$.variadic_parameter
						)
					)
				),
				')'
			),

		parameter: ($) =>
			seq(
				field(
					'name',
					choice($.mut_pattern, $.ref_pattern, $.identifier)
				),
				optional(seq(':', field('type', $._types)))
			),

		variadic_parameter: ($) =>
			seq(
				field('name', $.identifier),
				':',
				'...',
				field('type', $._types)
			),

		_return_type: ($) =>
			choice($._types, $.multi_return, $.named_return_type),

		multi_return: ($) => seq('(', commaSep1($._types), ')'),

		named_return_type: ($) => seq('(', commaSep1($.named_return_item), ')'),

		named_return_item: ($) =>
			seq(field('name', $.identifier), ':', field('type', $._types)),

		// Anonymous Function
		anonymous_function: ($) =>
			seq(
				'fn',
				field('parameters', $.parameters),
				optional(seq(':', field('return_type', $._return_type))),
				field('body', $.block)
			),

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
				optional('mut'),
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
				optional('mut'),
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
			choice(
				$.identifier,
				$.ref_pattern,
				$.mut_pattern,
				seq(commaSep1($.identifier, $.ref_pattern, $.mut_pattern))
			),

		//---Identifiers---//
		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		_type_identifier: ($) => alias($.identifier, $.type_identifier),
		_field_identifier: ($) => alias($.identifier, $.field_identifier),

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

		qualified_type_identifier: ($) =>
			prec.left(
				seq(
					field(
						'namespace',
						choice($.identifier, $.qualified_type_identifier)
					),
					'::',
					field('member', $._type_identifier)
				)
			),

		//---Types---//
		_types: ($) =>
			choice(
				$.primitive_type,
				$._type_identifier,
				$.qualified_type_identifier,
				$.function_type,
				$.pointer_type,
				$.reference_type,
				$.map_type,
				$.slice_type,
				$.array_type
			),

		primitive_type: ($) => choice(...PRIMITIVE_TYPES),

		function_type: ($) =>
			seq(
				'fn',
				field('parameters', $.parameters),
				optional(seq(':', field('return_type', $._return_type)))
			),

		pointer_type: ($) =>
			prec(PREC.unary, seq('*', field('type', $._types))),

		reference_type: ($) =>
			seq(optional('mut'), '&', field('type', $._types)),

		map_type: ($) =>
			seq(
				'map[',
				field('key_type', $._types),
				']',
				field('value_type', $._types)
			),

		slice_type: ($) => seq('[', ']', field('element_type', $._types)),

		array_type: ($) =>
			seq(
				'[',
				field('length', $._non_block_expression),
				']',
				field('element_type', $._types)
			),

		auto_sized_array_type: ($) =>
			seq(
				'[',
				'...',
				optional(field('length', $._non_block_expression)),
				']',
				field('element_type', $._types)
			),

		//---Literals---//
		_literals: ($) =>
			choice(
				$.number_literal,
				$.bool_literal,
				$.nil_literal,
				$.string_literal,
				$.raw_string_literal,
				$.byte_literal,
				$.rune_literal,
				$.map_literal,
				$.array_literal
			),

		//---Numeric Literals---//
		number_literal: ($) => choice($.integer_literal, $.float_literal),

		integer_literal: ($) => intLiteral,
		float_literal: ($) => floatLiteral,

		// Array literals
		array_literal: ($) =>
			choice(
				seq('[', ']'),
				seq(
					'[',
					choice(
						commaSep1($._expression),
						seq($._expression, ',', '...')
					),
					optional(','),
					']'
				)
			),

		// Map literals
		map_literal: ($) =>
			seq('{', commaSep1($.map_entry), optional(','), '}'),

		map_entry: ($) =>
			seq(
				field('key', $._expression),
				':',
				field('value', $._expression)
			),

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
		error_specifier: ($) => '!',
		cpp_flag: () => 'cpp',

		ignore_operator: () => '_',

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

		//---Blocks---//
		block: ($) => seq('{', repeat($._statement), '}'),

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

function sep1(rule, separator) {
	return seq(rule, repeat(seq(separator, rule)))
}
