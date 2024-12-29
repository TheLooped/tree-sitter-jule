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
		_simple_statment: ($) =>
			choice(
				$.return_expression,
				$.break_statement,
				$.goto_statement,
				$.label,
				$.pragma,
				$.continue_statement
			),

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
				$.fn_expr,
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
			prec(
				1,
				seq(
					'for',
					optional(field('condition', $._non_block_expression)),
					field('body', $.block)
				)
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
					optional(field('type_parameters', $.generic_params)),
					field('arguments', $.arguments),
					optional($.err_tkn)
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

		_bind: ($) =>
			choice($.identifier, $.mut_bind, $.ref_bind, $.ignore_operator),

		mut_bind: ($) => seq('mut', choice($.identifier, $.ref_bind)),

		ref_bind: ($) => prec(-1, seq('&', $.identifier)),

		type_annotation: ($) => seq(':', field('type', $._types)),

		pragma: ($) =>
			prec.left(
				seq(
					'#',
					field('directive', $.identifier),
					optional(field('argument', $._expression))
				)
			),

		label: ($) =>
			prec(-8, seq(field('label', $.identifier), ':', terminator)),

		goto_statement: ($) =>
			prec.right(seq('goto', field('label', $.identifier))),

		break_statement: ($) =>
			prec.right(seq('break', optional(field('label', $.identifier)))),

		continue_statement: ($) =>
			prec.right(seq('continue', optional(field('label', $.identifier)))),

		//---Declarations---//

		_declaration: ($) =>
			choice(
				$.fn_decl,
				$.struct_declaration,
				$.enum_declaration,
				$.trait_decl,
				$.impl_decl,
				$._var_decl,
				$.use_decl
			),

		struct_declaration: ($) =>
			seq(
				optional('cpp'),
				'struct',
				field('name', $.identifier),
				optional(field('generic_parameters', $.generic_params)),
				'{',
				optional(repeat($.struct_field)),
				'}'
			),

		struct_field: ($) =>
			seq(
				field('name', $.identifier),
				':',
				field('type', $._types),
				optional(
					seq('=', field('default_value', $._non_block_expression))
				)
			),

		enum_declaration: ($) =>
			seq(
				'enum',
				field('name', $.identifier),
				optional(seq(':', field('type', $._types))),
				'{',
				commaSep($.enum_field),
				optional(','),
				'}'
			),

		enum_field: ($) =>
			seq(
				field('name', $.identifier),
				optional(seq(':', field('type', $._types)))
			),

		impl_decl: ($) =>
			seq(
				'impl',
				optional(
					seq(
						field(
							'trait',
							choice($.identifier, $.qualified_identifier)
						),
						'for'
					)
				),
				field('struct', choice($.identifier, $.qualified_identifier)),
				field('body', $.block)
			),

		trait_decl: ($) =>
			seq(
				'trait',
				field('name', $.identifier),
				field('body', $.trait_body)
			),

		trait_body: ($) =>
			seq(
				'{',
				repeat(choice($.identifier, $.qualified_identifier, $.fn_decl)),
				'}'
			),

		//  Function Declaration
		fn_decl: ($) =>
			seq(
				optional(field('modifiers', $.fn_modifiers)),
				'fn',
				field('name', $.identifier),
				optional(field('generics', $.generic_params)),
				field('parameters', $.param_list),
				optional(field('return_type', $.return_spec)),
				field('body', $.fn_body)
			),

		// Function modifiers
		fn_modifiers: () => choice('unsafe', 'static'),

		// Function body
		fn_body: ($) => choice($._fn_block, terminator),

		// ============ Generic Parameters ============
		/**
		 * Generic type parameters with optional constraints
		 * Example: [T: Comparable]
		 */
		generic_params: ($) => seq('[', commaSep1($.generic_param), ']'),

		generic_param: ($) =>
			seq(
				field('name', $.identifier),
				optional(seq(':', field('constraints', sep1($._types, '|'))))
			),

		// ============ Parameter Definitions ============
		/**
		 * Function parameter list supporting regular, self, and variadic params
		 * Example: (x: int, mut y: float, &z: string)
		 */
		param_list: ($) =>
			seq(
				'(',
				optional(
					commaSep1(choice($.param, $.self_param, $.variadic_param))
				),
				')'
			),

		/**
		 * Regular parameter with binding modes
		 * Example: x: int, mut y: float, &z: string
		 */
		param: ($) => seq(field('bind', $._bind), optional($.type_annotation)),

		/**
		 * Self parameter for methods
		 * Example: self, mut self, &self
		 */
		self_param: ($) =>
			seq(optional(seq(optional('mut'), optional('&'))), 'self'),

		/**
		 * Variadic parameter
		 * Example: args: ...string
		 */
		variadic_param: ($) =>
			seq(
				optional(field('name', $._bind)),
				optional(':'),
				'...',
				field('type', $._types)
			),

		// ============ Return Specifications ============

		return_spec: ($) =>
			choice(
				field('err_ident', $.err_tkn),
				seq(':', field('type', $._ret_type)),
				seq(
					field('err_ident', $.err_tkn),
					seq(':', field('type', $._ret_type))
				)
			),

		err_tkn: ($) => '!',

		_ret_type: ($) => choice($._types, $.multi_ret, $.named_ret_list),

		multi_ret: ($) => seq('(', commaSep1($._types), ')'),

		named_ret_list: ($) => seq('(', commaSep1($.named_ret), ')'),

		named_ret: ($) =>
			seq(
				field('name', alias($.identifier, $.ret_id)),
				':',
				field('type', $._types)
			),

		// Anonymous Function
		fn_expr: ($) =>
			seq(
				'fn',
				field('parameters', $.param_list),
				optional(seq(':', field('return_type', $._types))),
				field('body', choice($.block, terminator))
			),

		// Use Declaration
		use_decl: ($) =>
			seq(
				'use',
				optional(field('alias', $.identifier)),
				field('path', $.string_literal)
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
				$.fn_type,
				$.pointer_type,
				$.reference_type,
				$.map_type,
				$.slice_type,
				$.array_type
			),

		primitive_type: ($) => choice(...PRIMITIVE_TYPES),

		fn_type: ($) =>
			seq(
				'fn',
				field('params', $.fn_type_params),
				optional(seq(':', field('ret_type', $._types)))
			),

		fn_type_params: ($) =>
			seq('(', optional(commaSep1($.fn_type_param)), ')'),

		fn_type_param: ($) =>
			seq(
				optional(
					seq(field('name', alias($.identifier, $.param_id)), ':')
				),
				field('type', $._types)
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
		block: ($) =>
			choice(
				$._normal_block,
				$.unsafe_block,
				$.defer_block,
				$.unsafe_defer_block
			),

		_normal_block: ($) => seq('{', optional(repeat1($._statement)), '}'),

		unsafe_block: ($) => seq('unsafe', $._normal_block),

		defer_block: ($) => seq('defer', $._normal_block),

		unsafe_defer_block: ($) => seq('unsafe', 'defer', $._normal_block),

		_fn_block: ($) => alias($._normal_block, $.fn_block),

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
