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

```NULL``` is actually the number 0 which can lead to ambiguity. We can resolve this problem by using the null pointer: ```nullptr```. It is not 0 and can be used anywhere we use ```NULL```.

# Dynamic vs. Automatic Variables
* Dynamic variables:
  * Created with ```new``` operator
  * Created and destroyed while program runs
  * Stored on heap
* Automatic vars/local vars:
  * declared within function definition
  * automatically created when function is declared
  * destroyed when call ends
  * not dynamic

# Typedef Operator
```typedef``` operator to define an alias for any type name or definition. It is usually placed outside the body of main so that it is available to the entire program.

It can be used to rename pointers, such as:
```cpp
typedef int * IntPtr;
IntPtr p; // equivalent to int * p;
```

# Arrow Operator and this Pointer

## Arrow Operator
**arrow operator** ```->``` combines dereferencing a pointer to a class/struct object and calling its member.
```cpp
Record * p;
p = new Record;
p->number = 2001; // same as (*p).number
p->grade = 'A'; // same as (*p).grade
```

## this Pointer
```this``` pointer represents a pointer pointing to the containing object. For example,
```cpp
class P {
public:
    P(int m);
private:
    int m;
};

P::P(int m) {
    // m referes to argument
    // to get object's m, we use "this"
    this->m = m;
}
```

# Shallow vs. Deep Copies
* **Shallow Copy**
  * copy contents of member vars from one object to the other
  * default assignment and copy constructors
  * fine if not pointers involved
* **Deep Copy**
  * pointers & dynamic memory is involved
  * creates copies of what each member var is pointing to
  * creates a separate but identical copy
  * must dereference pointer variable to get the data for copying
  * must write an overloaded assignment operator or copy constructor

# Resource Acquisition Is Initialization (RAII) Idiom
Consider the following example:
```cpp
void f() {
    MyClass * p = new MyClass;
    MyClass mc;
    try {
        y();
    }
    catch {
        delete p;
        throw;
    }
    doSomething();
    delete p;
}
```

This method is tedious and error prone (duplication of code). Instead of using pointers, we should use stack-allocated objects as much as possible as C++ guarantees that the destructors of stack-allocated objects will run.

The **RAII idiom** states that every resource should be wrapped in a stack-allocated object, where destructor deletes it. This can be seen with file I/O: ```ifstream f{"file"};```. The acquisition of the resource happens by initializaing the object ```f```. When ```f``` gets popped off the stack, the filestream is closed. The RAII idiom can be implemented via **smart pointers**, included in ```<memory>```

# Smart Pointers
**Smart pointers** - wrapper classes for pointers pointing to dynamic memory

## Unique Pointers
```cpp
class std::unique_ptr<T>
```
The **unique pointer** holds a pointer to an object of type ```T```. It guarantees that only one object holds that pointer, i.e. you cannot apply the copy constructor or copy assignment. it supports ```operator []``` and array initalization. It is used to model composition relationship.
```cpp
auto p = std::make_unique<C>();
unique_ptr<C> q = p; // ERROR, cannot have multiple pointers pointing to same object
```

However, you can use move semantics to transfer ownership of the pointer with ```std::move(ptr)```. The pointer that the unique pointer holds will be deleted when:
1. unique pointer is popped off the stack, calling the destructor which deletes the pointer
2. unique pointer is assigned to another pointer via ```operator =```

This provides exception safety to classes/functions that handle dynamic objects by guaranteeing deletion upon exit.
```cpp
template<typename T>
class unique_ptr {
    T* ptr;
public:
    unique_ptr(T * p) : ptr {p} {}
    ~unique_ptr() { delete ptr; }
    unique_ptr(unique_ptr<T> & other) = delete;
    unique_ptr(unique_ptr<T> && other) : ptr{ other.ptr} {
        other.ptr = nullptr;
    }
    unique_ptr<T> & operator=(const unique_ptr<T> && other) {
        using std::swap;
        swap(ptr, other.ptr);
        return *this;
    }
    T & operator*() { return *ptr; }
};
```

## Shared Pointers
```cpp
class std::shared_ptr<T> 
```
**shared pointers** work in the same way as unique pointers, with the only difference being that we can have multiple shared pointers with the same pointer.
```cpp
auto p1 = std::make_shared<MyClass>();
if(...) {
    auto p2 = p1; //p2 has the same pointer has p1
} // p2 is popped bbut object is NOT deleted
```

Shared pointers keep a count of how many pointers are sharing the pointer. Shared pointers will only delete the pointer once the count of shared pointers is zero. This can lead to a shared pointer not deleting its pointer even after the program exits if there is a cyclic dependency between shared pointers.
```cpp
class A {
    shared_ptr<A> ptr;
};
std::shared_ptr<A> a1 = std::make_shared<A>();
std::shared_ptr<A> a2 = std::make_shared<A>();
a1->ptr = a2;
a2->ptr = a1;
exit(0); // memory leak
```

A memory leak occurs in the above example because when the program tries to delete a1, it is kept alive by ```a2->ptr``` which is, in turn kept alive by ```a1->ptr```. An even simpler example:
```cpp
std::shared_ptr<A> a = std::make_shared<A>();
a->ptr = a; // never dies
```

### Dangers of Shared Pointers
1. if you have both raw and smart pointers to the same piece of heap memory then you might not realize when the memory is released
2. if you use raw pointers to create 2 smart pointers, they have independent count values and most certainly will lead to double free errors

## Weak Pointers
```cpp
class std::weak_ptr<T>
```
**weak pointers** are similar to shared pointers but they don't count towards the shared count. It is used to:
* implement temporary ownership of a shared_ptr
* prevent cyclic ownership in shared_ptr
