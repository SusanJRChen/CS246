# Exception Handling
**Exception handling** is the process where we deal with exceptional cases/edge cases. 

In general, exceptions are always preferred over using error codes in terms of program design. Consider:
```cpp
int milk, donuts;
cin >> milk >> donuts;
double dpg = donuts/ static_cast<double> (milk);
```

This code assumes that ```milk != 0```. If ```milk == 0```, then there be an error due to division by zero. One way to handle this is by if statement. But alternatively, we can use **try-catch blocks**.

# Try-Catch
```cpp
try {
    int milk, donuts;
    cin >> milk >> donuts;

    if (milk <= 0) throw donuts;

    double dpg = donuts / static_cast<double> (milk);
    dout << dpg;
}
catch (int e) {
    cout << "We have " << e << " donuts, and no milk!" << endl;
}
```

## Try Block
**try block** contains the code that tells the program what to do when everything goes smoothly. 

If something unusual happens, we throw an eception, and flows of control is transferred to the catch block.

## Catch Block
**catch block** contains code that executes when the try block throws an exception. Executing the catch block is known as "catching the exception" or "handling the exception". 

The catch block takes in a catch-block parameter, which is preceded by a type name that specifies the type of thrown value to be used in the catch block. If no parameter is needed, the variable name can be left out.

```catch(...)``` is a sepcial kind of ```catch``` block that cna be used to catch a thrown value of any type.

## Nested Try-Catch Blocks
If an exception is thrown in the inner try block but not caught in any of the inner catch blocks, then the exception is thrown to the outer try block and possibly caught by an outer catch block.

# Defining Your Own Exception Class
It is common to define a class whose objects can carry precise info on what is thrown to the catch block. This allows us to have a different type to identify each possible kind of exception situation. 

An exception class is just a class. e.g.:
```cpp
class NoMilk {
public:
    NoMilk(int num) : c(num) {}
    int getC() const { return c; }
private:
    int c;
};

int main() {
    try {
        int milk, donuts;
        cin >> milk >> donuts;

        if (milk <= 0) throw NoMilk(donuts);

        double dpg = donuts / static_cast<double> (milk);
        cout << dpg;
    }
    catch (NoMilk e) {
        cout << "We have " << e.getCount() << " donuts, and no milk!" << endl;
    }
}
```

## Trivial Exception Class
Exception classes with no member data can be defined as it allows us to throw an object of that class and activate the appropriate catch block. e.g.
```cpp
class DividedByZero{};
```

# Multiple Throws and Catches
A try block can throw any number of exception values. When catching multiple exceptions the order of the catch blocks can be important.

The catch blocks are tried in order, so it recommended to place more specific exceptions first and more generic exceptions last. e.g.
```cpp
try {
    int milk, donuts;
    cin << milk << donuts;

    if (milk < 0) throw NegativeNumber("milk");
    if (milk == 0) throw DivideByZero();

    double dpg = donuts / static_cast<double>(milk);
    cout << dpg;
} catch(NegativeNumber e) {
    cout << "Cannot have a negative number of " << e.getMessage() << endl;
} catch (DivideByZero) { 
    // no need to give parameter if not used
    cout << "ERROR: DIVIDE BY ZERO!";
}
```

# Throwing Exceptions in Functions
If we want to define the catch block outside of a function, the function can throw an exception that is handled when the function is called within a try block.
```cpp
// Function throws to outer try-catch block
double safeDivide(int top, int bot) throw (DivideByZero) {
    if (bottom == 0) throw DivideByZero();
    return top / static_cast (bottom);
}

int main() {
    try {
        quotient = safeDivide(num, denom);
    }
    catch (DivideByZero) {
    cout << "ERROR: DIVSION BY ZERO!";
    }
}
```

# Exception Specification
**exception specification** also known as **throw list**, lists the types of exceptions that the function might throw but does not handle/catch. 

Exception specifications appears in both the function declaration and definition and if there are multiple function declarations, all of them must have identical exception specifications. If there are multiple possible exceptions, the exception types are separated by commas. e.g.
```cpp
void foo() throw (DividedByZero, SomeOtherException);
```

If a function should not throw any exceptions that are caugh inside the function, we use an empty exception specification. e.g.
```cpp
void foo() throw ();
```

Any exceptions that are not included in the throw list invoke ```unexpected()```. The behaviour of it can be changed with ```set_unexpected()```, which takes in a new function as its parameter, but its default action is terminate the progrma.

## In Practice
Exception specifications have been proven useful in practice:
* Run-time checking:
  * exception specifications are checked at runtime rather than at compile time
  * unhandled exceptions call ```std::unexpected()``` which defaults to terminating the program
* Run-time overhead:
  * run-time checking requires the compiler to produced additional code. Affects optimizations
* Unusable in generic code:
  * not generally possible to know what types of exceptions may be thrown, so not a precise exception specification cannot be written.

In practice, only two forms of exception-throwing guarantees are useful:
1. might throw any exception: omit exception-specification
2. will never throw any exception: noexcept

```noexcept``` takes in an expression, but does not evaluate it. <br>
If a function might throw an exception, we omit any throw statement or use ```noexcept(false)```. <br>
If a function does not throw, use ```noexcept(true)```.

```cpp
void f() noexcpt; //f does not throw
```

If you know a function will never throw, declare it ```noexcept``` because it will facilitate optimization of your code.

## Inheritance
Exception class hierarchies are useful. If we have a derived class ```D``` of class ```B```, and ```B``` is in the exception specification, then a thrown ```D``` will be caught.

# Programming Techniques For Exception Handling
1. Separate throwing and catching into separate functions - throw within a function definition and list it in the exception specification, but place the catch clause in a different function
2. Never let the destructor throw an exception as it might be called when dealing with another exception
3. Exceptions should be used sparingly as they alter the flow of control. As a good rule of thumb, if a throw is desired, consider how to do it without the throw and if reasonable, do that instead.

# 4 Levels of Exception Safety
There are 4 levels of exception safety:
1. No Guarantee
   * If an exception occurs, it will not be handled
   * Memory can be leaked
   * Class invariants can be violated
```cpp
class A {
    int * i;
    A(int * i) : i{ i } {}
    ~A() { delete i; }
}
```

If an error occurs and an exception is thorwn with an object of type ```A```, the destructor will not be called and there will be a memory leak. This does not have any exception handling thus it has no guarantee.

2. Basic Guarantee
   * If an exception occurs, the program is valid, but in an unspecified state
   * Nothing is leaked
   * Class invariants are maintained
   * e.g. Regular copy constructor where data is lost:
```cpp
class A {}
class B {}
class C {
    A a;
    B b;
public:
    void f() {
        a.method1();
        b.method2();
    }
};
```
If ```a.method1()``` runs and ```b.method2()``` has an error, the state of ```a``` is changed without ```b``` changing. This results in a **partial function**.

3. Strong Guarantee
   * Exception is raised while executing error
   * The state of the program will be as if the function had not been called
   * e.g. copy and swap idiom:
```cpp
class C {
  A a;
  B b;
public:
  void f() {
    A aTemp = a;  // calls copy ctor
    B bTemp = b;
    aTemp.method1();
    bTemp.method2();
    std::swap(a, aTemp);  // nothrow
    std::swap(b, bTemp);  // nothrow
  }
}
```
If we had used a copy assignment operator instead of ```swap```, we would not have a strong exception guarantee because copy assignment operator could thorw. The non-throwing ```swap``` ensures that the state of ```a``` and ```b``` are not changed if the above methods fail.

4. Nothrow Guarantee
   * Function will never throw an exception
   * no exception is emitted outside of the function
   * Always accomplishes its task
   * use ```noexcept```
```cpp
struct Cimpl {
    A a;
    B b;
}

class C {
    unique_ptr pImpl; // pointer to implementation
public:
    auto temp = make_unique(*pImpl);
    // if temp == nullptr, nothing happens
    temp->a.method1();
    temp->b.method2();
    std::swap(pImpl, temp);
}
```
A possible further enhancement to the strong guarantee example with strong guarantee is to use pointers via the pImpl idiom as copying pointers cannot throw exceptions. This provides a nothrow guarantee.

# STL Vectors
Vectors encapsulate heap-allocated arrays. This is a form of the RAII idiom because when the stack-allocated vector goes out of scope, the internal heap-allocated array is free.

```cpp
void f() { vector<MyClass> v; }
```
when ```v``` goes out of scope, the ```MyClass``` destructor runs on all items in the array and the array is freed.

```cpp 
void g() { vector<MyClass *> v; }
```
when ```v``` goes out of scope, pointers dont have destructors, so only the array is freed while pointers are not. 

```cpp
void h() { vector<shared_ptr<MyClass>> v; }
```
To fix this, we can use shared pointers.

## Emplace Back
```vector<T>::emplace_back``` offers strong guaratee because if the array is full, it:
1. allocates a new, larger array
2. copy the objects over via copy constructor
3. if copy constructor throws:
   * destroys new array
   * old array is intact
   * strong guarantee
4. else delete old array

Consider the move constructor. With the move constructor, ```emplace_back``` will:
1. allocate new larger array
2. move the objects over
3. delete old array

The problem is that if the move constructor were to throw, ```emplace_back``` wouldn't offer strong guarantee because the original array would no longer be intact. However, ```emplace_back``` promises the strong guarantee, so if the move constructor offers nothrow guarantee, ```emplace_back``` will use it, otherwise it will use the copy constructor which may be slower.

### Rule of Thumb
Move operations hsould provide nothrow guarantee if possible and should indicate that they do so.
```cpp
class MyClass {
public:
    MyClass(MyClass && other) noexcept {}
    MyClass &operator=(MyClass && other) noexcept {}
};
```
