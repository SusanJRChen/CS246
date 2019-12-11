# Structures
**Structures** - another form of "aggregate" data type, like arrays. It differs from arrays in that it allows for a collection of values of different types. Structs, like arrays, are treated as a single item. One major difference is that a struct must be defined prior to declaring any variables.

## Defining a Struct
When a struct is defined, no memory is allocated. It is a "placeholder" for what the struct will look like. The structure definition will have a list of member names in the enclosing braces. Note that a semi-colon must follow the closing brace. An example of a structure definition is:
```cpp
struct CDAccount {  // struct keyword
  // member names
  double balance;
  double interestRate;
  int term;
};  // Dont forget semi-colon
```

## Initializing a Struct
Structures can be initialized at declaration: ```CDAccount account = { 12.50, 0.05, 3 };```

The initialization provides the initial data to all member variables.

## Accessing a Struct
Once a structure definition is given, the structure type can be used to declare **structure values**, which is a collection of **member values** (one for each member name). These **structure variables** can be accessed with the dot operator ```.```: e.g.
```cpp
CDAccount account;  // declaration
account.balance;  // accesses "balance" member variable
```

## Structure Assignment
Given 2 objects of the same structure type, assignments copy each member variable from one to the other. e.g. ```account1 = account2;```

# Classes
**Classes** - like structures with **member functions**. The value of a class variable is called an **object**. Classes are integral to OOP whose focus is on objects containing data and operations. The definition of a class is very similar to that of structures:
```cpp
class DayofYear {
public:
  int month;
  int day;
  void output();  // member function
};  // Don't forget semicolon
```

Declaring objects is the same as other variables, e.g. ```DayofYear today, birthday;```

Objects include:
* Data - Member variables
* Operations - Member functions

Class member variables are accessed in the same way as structs, with the dot operator. e.g. ```today.output();``` invokes the member function ```output()``` of the object ```today```.

# Class Member Functions
Class member functions must be defined/implemented after the class definition. Typically, function declarations are placed in the interface file while the implementations are kept elsewhere (information hiding). Syntax: 
```cpp
Return_Type Class_Name::Function_Name Parameter_List){}
```

Notice the **scope resolution operator** ```::```. It tells the compiler which class the member is from. The item before ```::``` (the class name) is called the ```type qualifier.``` e.g.
```cpp
void DayofYear::output() {
  cout << "Month: " << month << ", Day: " << day;
}
```

# Classes and OOP
1. Information Hiding
   * Details of how operations work are not known to users
   * Accomplished by restricting access to member variables (private/protected)
2. Data Abstraction
   * User knows how to use ADT/class, but details of how data is manipulated within ADT/class is not known to user
   * Can be used as a technique for identifying which information should be hidden
3. Encapsulation
   * Aggregates data and operations but keeps some details hidden (through information hiding) and others visible
   * Objects are an encapsulation of data values and operations

# Public and Private Members
## Private Members
Member variables in classes are **private** by default (opposite of structures whose members are public by default), or under the ```private:``` tag, which means they are accessible only inside the class. They cannot be accessed outside the class definition via the dot operator. This upholds the principles of OOP as it hides data from the client and allows manipulation only through public member functions.

## Public Members
**Public** member variables specified under the public: tag, which makes them accessible from outside the class by the client through the dot operator. e.g.
```cpp
class DayofYear {
public:
  void input();
  void output();
private:
  int month;  // data is private
  int day;
};
DayofYear date;
cin >> date.month;  // not allowed
date.input();  // allowed
```

# Class Initialization
## Member Initialization
**Member initialization** allow us to set default values for member vars by initializing them within the class definition.
```cpp
class DayofYear {
  int month = 1;  // member initialization
  int day = 1;
};
```

## Uniform Initialization
Classes can be initialized similar to arrays: ```int arr[4] = { 0, 1, 2, 3 };``` For a class with only public vars:
```cpp
class Student {
public:
  String name;
  int id;
}
Student s1 = { "Sarah", 1222 };  // aggregate initialization
```
For a class with private vars, we need to define a constructor to initialize the private vars.
```cpp
class Student {
private:
  String name;
  int id;
public:
  Student(String name, int id) : name {name}, id {id} {}
}
Student s2 = { "John", 3344 };  // calls constructor
```

Uniform Initialization searches for:
1. initializer_list constructor, i.e. ```myclass (std::initializer_list<int> v);```
2. Regular constructors
   * private member vars
   * public constructor
3. Aggregate Initialization (with public member vars)


## Member Initialization List
Fields are initialized in the order of declaration in the class, not in the order of MIL. This is more efficient than initializing in the body as it calls the constructor once rather than calling the default constructor and then initializing the member vars.

# Accessor and Mutator Functions
Accessor and Mutator functions are used to set/modify and retrieve the private member data of objects.
* Accessor Functions - allows client to retrieve data from object. Should not change class data (represented by making function a constant function via const keyword after function parameter list. Explained more here.)
* Mutator Function - allows client to change the data
```cpp
class DayofYear {
public:
  void input();
  void output();
  // Mutator Functions
  void setMonth (int month);
  void setDay (int day);
  // Accessor Functions
  int getMonth() const;
  int getDay() const;
private:
  int month;  // data is private
  int day;
};
```

# Structures vs. Classes
Property|Structure|Class
--------|---------|-----
Default Scope|Public|Private
Member Functions|None|Interface member functions are public

# Constructors
Constructors are member functions that are called when an object of that class is declared. It initializes some or all member variables. It can also be used to validate the data provided to ensure that the appropriate data is assigned to the member variables. A constructor is defined like any other function except:
1. must have the same name as class
2. cannot return a value. They return an anonymous object (for example, overloaded functions returning a new object as seen here).
3. no type given (not even void)

We can then declare objects of that type with the initialization parameters provided. Note that we cannot call constructors like other member functions.
```cpp
class DayofYear {
public:
  DayofYear(int month, int day); // ctor initializes month and day
private:
  int month;  // data is private
  int day;
};
DayofYear date1(3, 14), date2(2, 29);
// The following is ILLEGAL
DayofYear date1;
date1.DayofYear(7, 4);
```
A contructor definition looks like this:
```cpp
DayofYear::DayofYear(int monthValue, int dayValue) {
  month = monthValue;
  day = dayValue;
}
```

## Initialization Section
We can also use an **initialization section** to initalize member data. The initialization section is placed after the parameter list and before the opening braces. It consists of a colon followed by a list of some or all member vars separated by commas. Each member varaiable included is then followed by its initializing value in parenthesis. This is favoured over the other method as it is more efficient: less overhead (explained later). e.g.
```cpp
DayofYear::DayofYear(int monthValue, int dayValue)
  : month(monthValue), day(dayValue) {}
```

## Overloaded Constructors
Constructors can also be overloaded like other functions. This allows for multiple contructors of different parameters. The default constructor (without parameters) should not be declared with any brackets, else the compiler will mistake it for a function.
```cpp
DayofYear date1;  // Correct
DayofYear date1(); // Wrong
```

## Constructor Delegation
When dealing with multiple constructors, we might encounter repetitive code across constructors. To reduce this, we can apply **constructor delegation**. We call the constructor we are delegating to as the only item in the initialization section.
```cpp
class Max {
  int max, min, middle;
};
Max::Max(int my_max) {
  max = my_max > 0 ? my_max : 10;
}
Max(int my_max, int my_min) : Max(my_max) {
  min = my_min > 0 && my_min < max ? my_min : 1;
}
Max(int my_max, int my_min, int my_middle) : Max (my_max, my_min){
  middle = my_middle < max && my_middle > min ? my_middle : 5;
}
```

## Explicit Constructor Calls
Constructors can be called even after object has been declared. e.g. ```holiday = DayofYear(5, 5);```

Note that for the default constructor with no arguments, we do have to include parenthesis this time.

## Default Constructor
The **default constructor** is the constructor without any arguments. It is auto-generated only if no other constructors are defined. As a rule, it should always be defined to allow for accidental declarations of classes without parameters, i.e. ```DayofYear date;```

# The Big 3
The **big 3** consists of:
* Destructor
* Copy Constructor
* Copy Assignment Operator

It is a rule of thumb of C++ for building exception-safe code and for formalizing rules on resource management. It claims that if a class defines one (or more) of the following, it should probably explicitly define all three.

# Destructors
Destructors are executed whenever an object of its class goes out of scope or is deallocated by the ```delete``` operator. Syntax: 
```cpp
~className(){}
```
Its default version only destroys regular variables and not dynamic variables.

# Copy Constructor
A copy constructor is used when a copy of an object is made, in the following situations:
1. A class object is declared and initialized by another object of the same type in parameters. e.g.
   * ```Class c1(c2);```
   * ```Class c1 = c2;```
2. When a function returns a value of the class type.
3. When an argument of the class type is plugged in for a call-by-value parameter

The copy constructor has one call-by-reference parameter of same class type (normally const). Any class that uses pointers/new operator should have a copy constructor.
```cpp
Class::Class(const Class& Object) {
  ptr = new int;
  *ptr = Object->ptr; // copies value over
}
```

# Copy Assignment Operator
This is called when an already initialized object is assigned a new value from another existing object. This is a fallback for move assignment when move is unavailable (rvalues can bind to const references)
```cpp
Class &Class::operator=(const Class &Object) {
  if (this != &Object){
    // get rid of old data
    delete ptr;
    ptr = nullptr;
    // copy over values
    ptr = new int;
    *ptr = Object->ptr;
    return *this;
  }
}
Class c2 = c1;  // calls copy constructor
```

# Copy And Swap Idiom
The **copy and swap idiom** provides a strong exception guarantee for resource managing class. Normally, copying is done as follows:
1. Check for self-assignment
2. Free up memory
3. Allocate new memory
4. Deep copy similar to copy constructor

For example, in a LinkedList:
```cpp
struct Node {
private:
  Node *next;

public:
  Node &operator =(const Node &other) {
    if (this != &other) {
      delete next;
      next = other.next ? new Node (*other.next) : nullptr;
      return *this;
    }
  }
}
```
This method does not leak memory, however, it has 3 disadvantages:
1. Self-assignment rarely occurs, slows program down to check. Would be better if it could work regardless.
2. Only provides a basic exception guarantee. It does not maintain the state of the object when an exception is thrown. If new fails, next has lost its data.
3. Duplicates code written elsewhere.

To solve this, we use the copy and swap idiom, as follows:
```cpp
#include <utility>  // swap
struct Node {
private:
  Node *next;
  int data;
public:
  void swap(Node &other){
    using std::swap;
    swap(data, other.data); // data now contains other.data, other.data contains your data
    swap(next, other.next);
  }
  Node &operator =(const Node &other) {
    Node temp = other;  // copy constructor
    swap(temp);  // swap temp with this
    return *this;
  }
}
```
Note that the above 3 disadvantages are solved:
1. Works even with self-assignment due to temp
2. Provides a strong exception guarantee. If new fails, we won't even reach the point of the function where the current object is being altered. swap is non-throwing and the temp variable will be destroyed when the function ends.
3. This idiom does not repeat code, thus we cannot introduce bugs.

# Explicit Type Conversion

## Implicit Type Conversion
By default, copy constructors are **implicit**. This means that a type conversion can be done if there is a constructor with that type. For example,
```cpp
struct Node {
  Node(int data) : data {data}, next{nullptr} {}
};
// explicit type conversions calls ctor
Node n(4);
Node n = 4;
```

## Explicit Type Conversion
To prevent the compiler from using constructors to perform implicit conversions, we prepend the ```explicit``` keyword to the constructor. One reason to do so is to avoid accidental construction of the object with other types.
```cpp
struct Node {
  explicit Node(int data) : data {data}, next{nullptr} {}
};
Node n(4);   // OK
Node n = 4;  //Not OK
```

# The Big 5
The **big 5** is an extension of the Big 3, implemented in C++11. It consists of:
1. Destructor
2. Copy Constructor
3. Move Constructor
4. Copy Assignment Operator
5. Move Assignment Operator
It implements move semantics, allowing destination objects to grab data from temporary objects.

# Move Constructor

## Move Semantics
Copying was the means to transfer the state of an object to another. Moving is faster as they move existing resources to the new destination and sets the other to the default constructor, while copying requires the creation of a new resource from scratch. The lack of allocation and copying makes it faster and more efficient than copying.

## The Move Constructor
The move constructor removes need for deep copy or ```delete```. Takes in an r-value reference. ```std::move()``` is a cast that can be applied on an l-value argument to produce an rvalue reference. e.g.
```cpp
MemoryPage (MemoryPage &&other) : size(0), buf(nullptr) {
  // pilfers other's resources
  size = other.size;
  buf = other.buf;
  // reset other
  other.size = 0;
  other.bug = nullptr;
}
```

# Move Assignment Operator
Similar to move constructor except that before pilfering source object, it releases any resources the object might own. Performs the following steps:
1. Releases source object *this currently owns
2. Pilfers other's resources
3. Set other to a default state
4. return *this
```cpp
MemoryPage& MemoryPage::operator=(MemoryPage&& other){
  if (this != &other) {
    // release the current object’s resources
    delete[] buf;
    size = 0;
    // pilfer other’s resource
    size = other.size;
    buf = other.buf;
    // reset other
    other.size = 0;
    other.buf = nullptr;
  }
  return *this;
}
```
## Move and Swap Example
```cpp
MemoryPage& MemoryPage::operator=(MemoryPage&& other){
  using std::swap;
  swap(size, other.size); // swap values of this with other (R-value to be destroyed)
  swap(buf, other.buf);
  return *this
}
```

Every class comes with:
1. default constructor
2. copy constructor
3. copy assignment operator
4. destructor
5. move constructor
6. move assignment operator

Example of a class with Big 5 implemented:
```cpp
/* class.h */
class Class {
  int *ptr;
public:
  Class() {};  // default ctor
  Class(int i); // overloaded ctor
  // BIG 5
  Class(const Class &other);  // copy ctor
  Class(Class &&other);  // move ctor
  Class &operator=(const Class &other);  // copy assignment
  Class &operator=(Class &&other);  // move assignment
  ~Class();
}

/* class.cc */
// Constructors
Class::Class() : ptr { nullptr } {}
Class::Class(int i) : ptr { new int(i) } {}

// Copy Ctor
Class::Class(const Class &other) : ptr { new int(*(other.ptr)) } {}

// Move Ctor
Class::Class(Class &&other) : ptr { nullptr } {
  std::swap(ptr, other.ptr);
}

// Copy Assignment Operator
Class &Class::operator=(const Class &other) {
  Class temp(other);  // Copy Ctor
  std::swap(ptr, temp.ptr); // Copy and Swap
  return *this;
}

// Move Assignment Operator
Class &Class::operator=(Class &&other) {
  std::swap(ptr, other.ptr); // Move and Swap
  return *this;
}

// Destructor
Class~Class() { delete ptr; }
```

# Copy/Move Elision
**Copy or move elision** is an optimization technique where compilers are required or permitted to omit the copy/move constructors, even if these constructors and destructors have observable side effects. This prevents extra (potentially expensive) copies. We can disable elision with ```-fno-elide-constructors```. This should not be done because the elision would ignore the side effects. If your program relies on side effects of copy constructors, it is badly written; copy constructors should be written such that elision is safe.
```cpp
struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
  return C();
}

int main() {
  std::cout << "Hello World!\n";
  C obj = f();
}
```
Depending on the compiler and the level of elision, the following outputs are all valid:
```cpp
Hello World!
A copy was made.
A copy was made.
```
```cpp
Hello World!
A copy was made.
```
```cpp
Hello World!
```

# Static Modifier

## Static Variables
**Static member variables** are shared by all objects of that class. When one object changes it, all objects sees that change. To make a variable static, we place the ```static``` keyword before its type. Here are some potential uses:
1. for object of a class to communicate with each other and coordinate actions.
2. track how often a member function is called across all objects
3. count how many objects exist at a given time

Static variables are initialized outside the class definition. This ensures that the class' author performs the initializing of the static variables and no other programmer can initialize them (static vars cannot be initialized twice).

## Static Functions
Static member functions are member functions that does not need access to an object's data but still needs to be a member of that class. It can be called outside of the class without having to have a calling object. Note that it can only use static member variables and not any variable that depends on a calling object.
```cpp
class DayofYear {
public:
  static void printTodayDate();
private:
  int month;
  int day;
  static int numOfDates;
};
int DayofYear::numOfDates = 0; // initialize static var
DayofYear::printTodayDate(); // call static function
```

# Friend Classes
Similar to functions being a friend to a class. If a class ```F``` is a friend of class ```C```, then every member function of class ```F``` is a friend of class ```C```. We declare the friend class as a friend within the other class.
```cpp
class F;  // forward declaration
class C {
public:
  friend class F;
};
class F {};
```

# Forward Class Declaration
A **forward declaration** is a declaration of an identifier which the programmer has not yet provided a definition.

Tip: Always forward declare classes instead of using headers if possible.

When we include header files, we introduce a dependency that will cause the current class to recompile whenever the header file changes. Forward declaring classes will speed up compilation.

Note, however, that when we forward declare classes, all the compiler knows is that the class exists and nothing about its size or members, thus, we cannot use it when the current class needs to know the "insides" of the forward declared class. e.g.
```cpp
class F;  // forward declaration
class C {
public:
  F *ptr;  // allowed
  F obj;   // not allowed
};
```

As a rule of thumb, only forward declare when:
* Pointer
* Reference
* Paramter of function
* Return type of function

# Preconditions, Postconditions, Invariants
These are properties of classes/functions that allow us to specify what it does/accomplishes.

**Preconditions** - conditions that must be true of the parameters of a function and/or data members, if the function is to behave correctly, prior to running the function.

**Postconditions** - conditions that are true after the function is run.

e.g. consider the square root function that prints to the screen: 
```cpp
void sqrt(double x);
```
Precondition: ```x >= 0``` <br>
Postcondition: Square root of x is printed to screen

**Invariants** - set of asserts that must hold true from the creation to the destruction of objects.

For example, one of two member vars must be 0. We can use a member function to check if invariant holds and raise an assert if invariant is broken. Encapsulation enforces invariants by marking fields private and allowing us to ensure that the data is correct in the preconditions and postconditions.

The pre and postconditions ensure the invariants are not violated.
```cpp
struct Node {
    int data;
    Node * next;
    Node(int data, Node * next) : data {data}, next {next} {}
    ~Node() { delete next; }
};
// stack-allocated
Node n1 { 1, new Node{ 2, nullptr } };
Node n2 { 3, nullptr };
Node n3 { 4, &n2 };
```

Here is what happens when each object is pushed off the stack:
1. ```n1``` destructor called on n1, and its next node is deleted off heap
2. ```n2``` now a nullptr so nothing happens
3. ```n3``` undefined behaviour or crash since n2 is being deleted

To solve this issue, we use encapsulation by introducing a **wrapper class**.
```cpp
class List {
    struct Node; // private nested class
    Node * l = nullptr;
public:
    void addToFront(int n);
    int ith(int i);
    ~List();
};

struct List::Node {
  int data;
  Node * next;
  Node (int data, Node * next) : data {data}, next {next} {}
  ~Node() { delete next; }
};

List::~List() {
  delete l;
}

void list::addToFront(int n) {
  l = new Node(n, l);
}

int List::ith(int i) {
  Node * cur = l;
  for (int j=0; j < i && cur; ++j) {
    cur = cur->next;
    return cur->data;
  }
}
```
