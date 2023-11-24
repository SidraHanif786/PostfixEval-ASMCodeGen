# Evaluating Postfix Expressions

## Description
This repository contains a program that evaluates postfix expressions involving single-digit integers and the operations +, -, *, and /. The program traces the action of postfix evaluation, displaying each token as it is encountered and the action of each stack operation. It is also capable of detecting and reporting malformed postfix expressions.

### Usage
To use the program, follow these steps:
1. Clone the repository to your local machine.
2. Compile the program using a C++ compiler.
3. Run the compiled executable, providing a postfix expression as input. like `572+*8-` , `921+/4*` , `92/34*+`

### Example
For the postfix expression `921+/4*`, the output of the program might resemble the following:

- Token 9      Push 9
- Token 2      Push 2
- Token 1      Push 1
- Token +      Pop  1      Pop  2      Push 3
- Token /      Pop  3      Pop  9      Push 3
- Token 4      Push 4
- Token *      Pop  4      Pop  3      Push 12

- Token END      Pop  12



# Generating Assembly Language Code

## Description
This extended version of the postfix evaluation program generates machine instructions in assembly code for evaluating expressions using one accumulator register. The supported instructions include:
- `LOAD x`: Place the value of x in the accumulator register.
- `STORE x`: Store the contents of the accumulator register into variable x.
- `ADD x`: Add the value of x to the contents of the accumulator register.
- `SUB x`: Subtract the value of x from the contents of the accumulator register.
- `MULT x`: Multiply the contents of the accumulator register by the value of x.
- `DIV x`: Divide the contents of the accumulator register by the value of x.

### Example
For the postfix expression `a b c + * d e * -`, the generated assembly code would be:

- LOAD b
- ADD c
- STORE temp1
- LOAD a
- MULT temp1
- STORE temp2
- LOAD d
- MULT e
- STORE temp3
- LOAD temp2
- SUB temp3
- STORE temp4