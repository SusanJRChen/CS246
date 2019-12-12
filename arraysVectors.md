# Declaring and Accessing Arrays
**Array** - a collection of data of the same type. Declaration of an array of size n is:
```cpp
Data_Type arr[n];
```
This declares an array of n variables of type Data_Type. Delcaration of arrays can be grouped together with delcaration of regular variables.

**Elements** - of the array can be access using the ```[]``` operator and include the index of the element inside the brackets. The index span from 0 to n-1. 
```cpp
arr[i];
```

# Initializing Arrays
```cpp
int foo1 [3] = { 16, 2, 77};
int foo2 [3] = { 16, 2 };  // last element = 0
int foo3 [3] = { };   // all 0

// foo1 is equivalent to:
int foo4[3];
foo4[0] = 16;
foo4[1] = 2;
foo4[2] = 77;

// Also equivalent:
int foo5[] = { 16, 2, 77 };
```
If fewer values than the array size is provided, the array is filled from the beginning and the rest are filled with the "zero" of the base array type (0 in the case with int).

If the array size is not specified, the size is determined by the number of initialization values.

# Iterating Through Arrays

## For Loops
Arrays naturally work well with counting loops. For example, to iterate through the elements of an array, we can use the for loop and iterate from 0 to size - 1 as such:
```cpp
for (int i = 0; i < size; i++) {
  cout << array[i];
}
```
One major pitfall of this technique is that the for loop might go beyond the range of the array, and it is up to the programmer to make sure it stays within the array size. Note the ```<``` in the for loop condition above. If we had used ```<=```, the loop would have tried to access an element out of the array's range. For example, given an array of size 5, ```array[5]``` is out of range as the last element has index of ```5 - 1 = 4```.

## Range-Based For Loops
Another to ensuring we iterate only within the range of the array is to use range-based for loops.
```cpp
for (datatype varname : array) {
  do_Something(varname);
}
```
```varname``` can be set to any name the programmer chooses. ```varname``` is a local copy of the element in the array. Mutating it will not modify the original element in the array. In order to do so, we must pass ```varname``` in as a reference.

```cpp
for (datatype& varname : array) {
  mutate(varname);  // original element changes
}
```

# Arrays in Functions

## Passing Elements
Individual elements of an array can be passed in to a function in 2 ways:
1. Pass by value - local copy is created. Any changes does not affect original copy.
2. Pass by reference - address is copied. Any changes in the function modifies original element.

We specify which type of argument the function is taking in the parameter list:
```cpp
void foo1 (int elem);
void foo2 (int& elem);
foo1(arr[2]);  // by value
foo2(arr[2]);  // by reference
```

## Passing Entire Arrays
An entire array can be passed in to a function, but this formal parameter is neither a call-by-value or call-by-reference parameter; instead it is an array parameter. Typically, the size of the array is sent in as a second argument. To specify an array parameter: ```void foo (int arr[], int size);```

When an array is passed in, it is similar to a pass-by-reference: any changes made to the array by the function mutates the original array. This is because when an array is passed in, only the address of the first element is passed in. Note that when passing in an array, no square brackets should be included. e.g.
```cpp
const int SIZE = 5;
int array[SIZE] = { 1, 2, 3, 4, 5 };
void foo(int arr[], const int size) {
  for (int i = 0; i < size; i++) {
    arr[i] += 1;  // modifies original array
  }
}
foo(array);  // NO square brackets
```

In the event where the array should not be modified, we place the const modifier before the array parameter. e.g. ```void foo (const int arr[]);```

# Multi-Dimensional Arrays
Arrays with more than one index can also be created, for example, a 2-dimensional array can be used to represent a 2-D grid. A 2-D array can be viewed as an "array of arrays". For example:
```cpp
char grid[5][10];
// be viewed as a grid of 5 rows and 10 columns
grid[0][0], grid[0][1], ..., grid[0][9]
grid[1][0], grid[1][1], ..., grid[1][9]
...
grid[4][0], grid[4][1], ..., grid[4][9]
```

## Multi-Dimensional Array Parameters
Multi-dimensional array parameters are passed into functions in a similar way to one-dimensional arrays:
* First dimension size is not provided; given as second parameter (size)
* Second dimension size is given
e.g.
```cpp
void foo(const char grid[][10], int size);
```

# Arrays in Memory
When arrays are declared, memory is allocated for the entire array. The memory is **sequentially-allocated** which means that the addresses of the elements of the array are allocated "back-to-back".

## Static Arrays
All the arrays we have provided in the examples above were **static arrays**. They are created on the stack and have automatic storage duration (get destroyed when function call ends). They necessarily have a fixed size, which is a limitation if we do not know the size needed before the program runs. A workaround is to estimate the maximum size needed, which is a waste of memory. Another solution is to use dynamic arrays.

## Dynamically-Allocated Arrays
These are arrays whose size is not specified when writing the program. They are initialized with the new keyword (see here for more on new). i.e. 
```cpp
double a = new double[size];
```

To destroy a dynamically-allocated array we use the **array deallocation** function: 
```cpp
delete[] a
```

# Arrays As Pointers
As mentioned above, array variables are just the addresses of their first element. Thus, array variables are just like pointers, the only difference is that they are constant pointers const int *, which means that they cannot change where they point to. e.g.
```cpp
int a[10];
int b = *a;  // b == a[0]
int *c;
c = a; // LEGAL - points to a[0]
a = c; // ILLEGAL - array pointer is a constant pointer
```

## Resizing A Dynamic Array
1. Allocate a new [] array and store it in a temp pointer
2. Copy over previous values
3. delete[] old array
4. Change any necessary pointer to array and size
```cpp
int* newArr = new int[new_size];
std::copy(oldArr, oldArr + std::min(old_size, new_size), newArr);
delete[] oldArr;
oldArr = newArr;
```

## Returning An Array
Functions cannot return an array type. We must return a pointer to the array. i.e.
```cpp
int [] function(); // ILLEGAL
int * function(); // LEGAL
```

## Pointer Arithmetic
Since arrays are just pointers, coupled with the fact that arrays are sequentially-allocated, we can perform arithmetic operations on array variables.. e.g.
```cpp
int *d = new int[10];
int a = d;      // a == d[0]
int b = d + 1;  // b == d[1]
int c = d + 2;  // c == d[2]We can also use pointer arithmetic to iterate through the array, for example:
for (int i = 0; i < arraySize; i++) {
  cout << *(d + i) << " ";
}
```

## Multi-Dimensional Dynamic Arrays
The following example first creates an array of 3 pointers, and then allocates each pointer an array of 4 ```int```s
```cpp
typedef int* IntArrayPtr;
IntArrayPtr *m = new IntArrayPtr[3];
for (int i = 0; i < 3; i++) {
  m[i] = new int[4];
}
```

# Vectors
Vectors are similar to arrays in that it has a base type and is a collection of base type values. However, vectors are allowed to grow and shrink in size. Syntax: 
```cpp
vector<Base_Type> vec;
```

This syntax indicates a template class (discussed later) and any type can be put inside the angle brackets and it will produce a new class of vectors with that base type. It will call the default constructor for the class ```vector<Base_Type>``` and create an empty vector object.

## Vector Operations
* ```vec.at(int pos)``` returns a reference to the element at pos
* ```vec[int pos]``` similar to ```vec.at()``` but does not check if pos is out of range.
* ```vec.push_back(Base_Type x)``` adds x to end of vector
* ```vec.size()``` returns number of elements in vector
* ```vec.capacity()``` returns capacity of vector; can be equal or greater than vector size. Represents size of storage space (in terms of number of elements) currently allocated to vector
* ```vec.clear()``` removes all elements from vector (destroys them) and leave the vector with a size of 0
* ```vec.erase(iterator pos)``` removes a single element at position. Can remove a range of elements by using: ```vec.erase(iterator first, iterator last)``` which removes ```[first, last)```
