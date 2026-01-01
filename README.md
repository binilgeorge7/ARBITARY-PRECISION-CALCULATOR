# ARBITARY-PRECISION-CALCULATOR
Arbitrary Precision Calculator implemented in C using doubly linked lists to perform addition, subtraction, multiplication, and division on integers of unlimited size. Each digit is stored as a node, enabling manual digit-wise computation with proper sign handling and dynamic memory management.

Arbitrary Precision Calculator in C

Using Doubly Linked Lists

📌 Overview

This project implements an Arbitrary Precision Calculator in C, capable of performing arithmetic operations on very large integers that exceed the limits of standard data types such as int and long long.

Instead of relying on built-in numeric types, the calculator represents numbers using doubly linked lists, where each node stores a single digit. All arithmetic operations are performed using manual digit-by-digit algorithms, similar to paper-based calculations.

✨ Features

Supports arbitrary-length integers

Handles positive and negative numbers

Implements:

Addition (+)

Subtraction (-)

Multiplication (x)

Division (/)

Proper sign handling

Leading zero trimming for clean output

Fully dynamic memory allocation

Modular and reusable linked-list based design

🧠 Design Approach

Each digit of a number is stored in a Doubly Linked List node

Least Significant Digit (LSD) is accessed via the tail

Operations traverse lists from tail to head

Borrow and carry are handled explicitly

Comparison logic determines sign and operation direction

Division is implemented using repeated subtraction

🗂️ Project Structure
.
├── main.c              // Argument parsing & control flow
├── addition.c          // Addition logic
├── subtraction.c       // Subtraction logic
├── multiplication.c    // Multiplication logic
├── division.c          // Division logic
├── list_operations.c   // Doubly linked list utilities
├── header.h            // Structure definitions & prototypes
└── README.md

🛠️ Compilation

Use gcc to compile all source files:

gcc *.c -o apc

▶️ Usage
./apc <operand1> <operator> <operand2>

Examples
./apc 4321 + 123456
./apc -99999999 x 88888888
./apc 123456789012345 / 12345

📥 Input Validation

Ensures exactly 3 arguments

Accepts only valid integers (with optional + / -)

Valid operators: + - x /

Prevents invalid or malformed input

🔍 Sample Output
 RESULT
=========================
 4321 + 123456 = 127777

🚀 Skills Demonstrated

C Programming

Data Structures (Doubly Linked Lists)

Dynamic Memory Management

Algorithm Design

Edge Case Handling

Modular Programming

Low-level arithmetic logic

📌 Future Enhancements

Support for modulo operation

Floating-point precision

Optimization for division

Unit testing framework

Improved error messages

👤 Author

Binil George
Embedded Systems & Firmware Enthusiast
C | Data Structures | Low-Level Programming
