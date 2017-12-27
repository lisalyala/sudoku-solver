# stack-calculator
In this programming assignment, I wrote an LC-3 program capable of evaluating postfix expressions (aka reverse polish notation) using a stack. A postfix expression is a sequence of numbers ('1','5', etc.) and operators ('+', '*', '-', etc.) where every operator comes after its pair of operands. For example “3 + 2” would be represented as “3 2 + ­” in postfix. The expression "(3 − 4) + 5" with 2 operators would be "3 4 − 5 +" in postfix. Notice that a nice feature of postfix is that the parentheses are not necessary, which makes the expressions more compact. The proj1 file contains the following subroutines:


EVALUATE: This subroutine for each input value, calls the push, pop, add, subtract, multiply, divide and power after evaluating if the value read from the memory is an operator or operand and if it is an operator, which kind. If the stack underflows or if after evaluating the whole expression the stack has more than one value, print "Invalid Expression" to the screen and halt.
PUSH: Pushes items onto stack
POP: Pops items off stack
ADD: Adds the two operands.
SUBTRACT: Performs subtraction.
MULTIPLY: Performs multiplication.
DIVIDE: Performs division. In case the division results in a remainder, just return the integer quotient. The input values will always be positive integers.
POWER: Performs power operation. You may assume that the register storing the result will not overflow. The input values will always be positive integers.
PRINT_HEX: This subroutine prints the output of the input expression in its hexadecimal representation.
