# Reference
**reference** - represents name of a storage location. They are constant pointers that are automatically dereferenced. They are denoted by an ampersand ```&``` after the data type. We can have standalone references, such as:
```cpp
int robert;
int & bob = robert;
```
In this example, ```bob``` is a reference to the storage location for ```robert```. ```bob``` is known as an alias for ```robert```: any change to ```bob``` results in a change to ```robert```.

Returning a reference allows us to overload certain operators in a more naturla way. e.g.
```cpp
double & sampleFunction(double & variable);
```
For examples, see the overloading of inserter ```<<``` and extractor ```>>``` operators. We should not return a local variable because that creates an alias to a variable that is destroyed once the function call is done.

## L-Values and R-Values
**L-Value** - appears on the left-hand side of an assignment operator; represent a storage location (most references are of this type). Persists beyond expression.

**R-Value** - appears on the right-hand side of an assignment operator. We can have a reference to an r-value by using a double-ampersand ```&&``` (used in move semantics). A temporary value that does not persist beyond the expression. e.g. ```2+3```

# Pointers
**pointers** - represent the memory address of a variable. To declare pointers, we place an asterick ```*``` after the data type. i.e. ```DataType * var1, * var2, ...;```

**dereferencing operator** - ```*``` retrieves the value that the pointer is pointing to. e.g. ```int i = *intptr;```

**addressof operator** - ```&``` retrieves the address of the variable. e.g. ```int *ptr = &i;```

```cpp
int *ptr; // declares an int pointer
int a = 5;
ptr = &a; // points to a
int b = *ptr; // b = 5
```

# New Operator
The ```new``` operator creates a new dynamic variable of a specified type and returns a pointer to the new variable.
```cpp
MyType *p;
p = new MyType;
```

If the type is a class type, the default constructor is called for the newly created dynamic var. We can specify a different constructor by including args, as follows:
```cpp
MyType *p;
p = new MyType(32, 17);
```

Similarly, we can initialize dynamic vars of nonclass types
```cpp
int *n = new int(17); // *n == 17
```

# Basic Memory Management
The freestore or **heap** is reserved for dynamically-allocated vars (i.e. dynamic variables created by ```new```). If there is insufficient memory to create the new var, ```new``` terminates program.

It is good practice to recycle any freestore memory used by dynamic vars.

# Delete Operator
The ```delete``` operator eliminates a dynamic var and returns the memory to the freestore manager so that the memory can be reused. i.e.
```cpp
delete p; // value of p is undefined
```

Notice that the value of ```p``` is undefined after we free its memory. The undefined pointer vars are called **dangling pointers**. It is good practice to set these pointers to ```NULL```.

