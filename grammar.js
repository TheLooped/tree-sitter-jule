//----Constants----------//
// Operator Precedences
// - Assignment precedence (lowest)
// - Logical OR precedence
// - Logical AND precedence
// - Equality comparison precedence
// - Relational comparison precedence
// - Bitwise OR precedence
// - Bitwise XOR precedence
// - Bitwise AND precedence
// - Shift precedence
// - Additive precedence
// - Multiplicative precedence
// - Unary precedence
// - Call and member access precedence (highest)
// Numeric Parsing Information
// - Integer - Hex, octal, and binary
// - Floating-point - Decimal and exponential
//  Type Information
//  - Primitive types

module.exports = grammar({
	name: 'jule',
	rules: {
		//----Source Structure----//
		// File structure
		// Import declarations
		//----Comments-----------//
		// Single-line comments
		// Multi-line comments
		//----Literals-----------//
		// Integer literals
		// - Decimal integers
		// - Hexadecimal integers
		// - Octal integers
		// - Binary integers
		// Float literals
		// - Decimal floats
		// - Exponential notation
		// String literals
		// - Double-quoted strings
		// - Raw string literals
		// Boolean literals
		// Nil literal
		// Array literals
		// Map literals
		//----Types--------------//
		// Primitive types
		// - Integer types (int8, int16, int32, int64, uint8, uint16, uint32, uint64)
		// - Floating-point types (float32, float64)
		// - Boolean type
		// - String type
		// Composite types
		// - Array types
		//   - Fixed-size arrays
		//   - Dynamic arrays
		// - Slice types
		// - Map types
		// - Struct types
		// Function types
		// Pointer types
		// Generic types
		// - Type parameters
		// - Constraints
		// Type aliases
		// Type conversions
		//----Statements---------//
		// Declaration statements
		// Assignment statements
		// Control flow statements
		// - If statements
		//   - If-else chains
		//   - If with initialization
		// - For statements
		//   - C-style for loops
		//   - For-each loops
		//   - Infinite loops
		// - Match statements
		//   - Match arms
		//   - Default case
		// - Return statements
		// - Break statements
		// - Continue statements
		// Defer statements
		// Expression statements
		//----Declarations-------//
		// Variable declarations
		// - Single variable
		// - Multiple variables
		// - With type inference
		// - With explicit type
		// Constant declarations
		// Static declarations
		// Function declarations
		// - Function parameters
		// - Return types
		// - Function body
		// Method declarations
		// - Receiver parameter
		// Struct declarations
		// - Struct fields
		// Enum declarations
		// - Enum values
		// - Methods on enums
		// Type alias declarations
		// Generic type declarations
		//----Identifiers--------//
		// Variable identifiers
		// Function identifiers
		// Type identifiers
		// Field identifiers
		// Method identifiers
		// Package identifiers
		// Label identifiers
		//----Expressions--------//
		// Binary expressions
		// - Arithmetic
		// - Logical
		// - Comparison
		// - Bitwise
		// Unary expressions
		// Function calls
		// Method calls
		// Member access
		// - Struct field access
		// - Array/slice indexing
		// - Map key access
		// Index expressions
		// Slice expressions
		// Type assertions
		// Type conversions
		// Parenthesized expressions
		// Anonymous functions
		// Struct literals
		// Array/slice literals
		// Map literals
		//----Operators----------//
		// Arithmetic operators
		// Comparison operators
		// Logical operators
		// Bitwise operators
		// Assignment operators
		//----Modules------------//
		// Import declarations
		// - Single import
		// - Multiple imports
		// - Aliased imports
		// Package clause
		//----Generics-----------//
		// Generic type declarations
		// - Type parameters
		// - Constraints
		// Generic function declarations
		// Generic type instantiations
		// Generic interface declarations
	}
})
