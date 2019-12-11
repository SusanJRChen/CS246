# Variables
**variables** - used to store a value. The name of a variable is called an **identifier**, which are case-sensitive.

Here are some types of variables:
* ```short``` (short int)
* ```int```
* ```long``` (long int)
* ```float```
* ```double```
* ```long double```
* ```char```
* ```bool```
* ```enums```
* ```auto``` deduces type of variable based on expression. ```auto x = express;```
* ```decltype``` determines type of expression based on provided arguments. ```decltype(x*3.5) y;``` declares y as a double.

**literals** - constants whose values cannot be changed during execution. Is literally typed into the program.

# Declaration
Every variable must be delcared before it is used. This tells the compile what kind of data is being store in the variable so that it can allocate the required space for it. Uninitialized, declared variables have default garbage value set to them. Syntax:
```cpp
Type_Name val;
```

# Assignment
Evaluates the right-hand side of equal sign and sets the variable on the left-hand side equal to the value. Syntax:
```cpp
Variable = Expression;
```

**Assignment** can be chained ```n = m = 2;```, which is equivalent to ```n = (m = 2);```. First m is set to 2, this expression is evaluated to 2 and assigned to n.

**Initialization** is when a variable is assigned a value at the time of declaration. There are 2 methods of initialization:
```cpp
int count = 0;
int count(0);
```
