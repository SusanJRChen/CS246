# If Statements
Chooses between alternative actions based on value of Boolean expression.
```cpp
if (Boolean_Expression_1) {
  Action1();
} else if (Boolean_Expression_2) {
  Action2();
} else {
  Action3();
}
```

Enclosing braces within each branch can be omitted if there is only one statement provided. Enclosing braces are used for **compound statements**. The ```else``` statement is also optional if not needed. If statements can also be **nested**.

## Ternary Operator
**Ternary operators** are shorthand if-else statements that allows embedding of conditionals in expressions. Syntax: 
```cpp
var = (Boolean_Expression) ? True_Case : False_Case
```
e.g. Set the value of max to the maximum of n1 and n2. ```max = (n1 > n2) ? n1 : n2```

# Switch Statements
Similar to if statements but more convenient. Choice of branch is determined by a **controlling expression** given in paranthesis, which can only be one of:
1. bool
2. enum
3. int
4. char
```cpp
switch (Controlling_Expression) {
  case Constant_1:
    Statement_Sequence_1
    break;
  case Constant_2:
    Statement_Sequence_2
    break;
  default:  // default branch if all other branches return false
    Default_Statement_Sequence
}
```

# Loops
There are 3 types of loops in C++:
1. While loops - Most flexible, no restrictions.
2. Do-while loops - least flexible, always executes body at least once.
3. For loops - Iterates/counts through a defined range of values.

## While Loops
```cpp
while (Boolean_Expression) {  // Loops Condition
  Statements
}
```

## Do-while Loops
```cpp
do {
  Statements
} while (Boolean_Expression);  // Loop Condition
```

## Comma Operator
The **comma operator**, evaluates a list of expressions and returns the value of the last expression. Used in for loops.
e.g. ```first = (first = 2, second = first + 1);```
* ```first``` gets assigned the value 3
* ```second``` gets assigned the value 3

*Does not guarantee what order the expression will be evaluated. To guarantee the order, use parenthesis.

## For Loops
For loops are used to step through a range of values, most commonly integers.
```cpp
for (Initialization_Action; Boolean_Expression; Update_Action){
  Statements
}
```
The comma operator can be used to add multiple actions to the items in the loop condition. e.g.
```cpp
for (Initialization_Action_1, Initialization_Action_2; Boolean_Expression; Update_Action){
  Statements
}
```

# Break and Continue Statements

**break** - forces the loop to exit immediately

**continue** - skips rest of loop body
