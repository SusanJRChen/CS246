# Templates
**Template** allow us to define one function that applies to all types of variables. 

They are an example of algorithm abstraction, which is the expression of algorithms in a general way so we can ignore details and concentrate on the substantive parts of the algorithm. Syntax:
```cpp
template <class T>
```

This tells the compile that the definition/declaration that follows is a template and that 'T' is a type parameter. ```T``` can be replaced by any type, whether the type is a class or not. The compiler produces a separate definition only for the types which use the template as required.
```cpp
template <class T>
void swapValues(T & var1, T & var2) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

int int1 = 1, int2 = 2;
swapValues(int1, int2);
char sym1 = 'A', sym2 = 'B';
swapValues(sym1, sym2);
```

## Multiple Parameters
Templates with multiple parameters can be deinfed, however, the following definition/declaration cannot have any unused templates. e.g.
```cpp
template <class T1, class T2>
```

# Class Templates
**Class templates** can be used to generalize a class. Defining class templates is the same as for function templates. Once the class template is defined, we can declare object of the class. The declaration must specify what type to be filled in for T. e.g.
```cpp
template <class T>
class Pair {
public:
    Pair(T f, T s);
    void setF(T f);
    void setS(T s);
    T getF() const;
    T getS() const;
private:
    T f;
    T s;
};
```

## Member Functions For Class Templates
Member functions that are part of a class template is defined in the same way as member functions for ordinary classes. The only difference is that the member functions are also templates.

The class name before the scope resolution operator has to have the template parameter. However, the constructor and destructor names do not have the template parameter. e.g.:
```cpp
template <class T>
Pair<T>::Pair(T f, T s) {
    this->f = f;
    this->s = s;
}
```

## Class Templates As Parameters
Class templates may be used as the type for a function paramter.
```cpp
int addUp(const Pair<int> & thePair);
```

They can also be used within a function template.
```cpp
template <class T>
T addUp(const Pair<T> & thePair);
```

## Type Definitions
We can also define a class type name that has the same meaning as specialized class template name, using ```typedef```. e.g.
```cpp
typedef Class_Name<T> New_Type_Name;
typedef Pair<int> PairOfInt;
```

## Friend Functions
When used with template classes, you must include a type parameter where appropriate

# Inheritance
When defining a derived template class, begin with a standard template class and derive the other template class from it.
```cpp
// Base Class
template <class T>
class Base {
public:
    Base();
    virtual ~Base();
private:
    T *a;
};

template <class T>
Base<T>::Base() {
    a = new T[5];
}

template <class T>
Base<T>::~Base() {
    delete [] a;
}

//Derived Class
template <class T>
class Derived : public Base<T> {
public:
    Derived();
    virtual ~Derived();
private:
    T *b;
};

template <class T>
Derived<T>::Derived() : Base<T>() {
    b = new T[5];
}

template <class T>
Derived<T>::~Derived() {
    delete [] b;
}
```

# Maps
Maps are a templated class that are containers of key-value pairs. The key values are used to sort and uniquely identify the elements while the mapped values store the content associated with the key. The elements are sorted by its key using the operator ```<```. To use user-defined classes as keys, the class must be:
1. Copyable
2. Assignable
3. Comparable (must implement operator ```<```)
```cpp
#include <map>
using namespace std;

int main() {
    map <string, int> m;
    m["abc"] = 1;
    m["def"] = 4;

    cout << m["abc"] << endl; // 1
    cout << m["ghi"] << endl; // if key is not defined, it will call the default constructor of value type and insert it in that key  (prints 0)

    m.erase("abc");

    if(m.count("def")) {} // 0 if not found, 1 if found

    for (auto &p : m) {
        cout << p.first << p.second << endl;
        // p.first gets key
        // p.second gets value
    }
}
```
