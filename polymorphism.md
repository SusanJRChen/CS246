# Virtual Functions
**Polymorphism** - the ability to associate multiple meanings to one function name with virtual functions and late binding. 

**Virtual functions** - provide the capability of polymorphism and it is where a function is used before it is defined. The compiler waits til it is used in the program and gets the object's implementation. 

This technique is known as **late binding** or dynamic binding. Virtual functions are used when we don't know exactly how a function is implmented. This is different from Java where all functions are automatically virtual. 

To declare a function as virtual, we prepend the ```virtual``` keyword:
```cpp
virtual Return_Type foo();
```

## Inheritance
Inherited classes will keep the virtual properties of virtual functions in the base class (even without stating the virtual keyword).

## Override vs. Redefine
* if a virtual function is changed, it is **overriden** (defined at runtime)
* if a non-virtual function is changed, it is **redefined** (defined at compiletime)

## Disadvantages of Virtual Functions
1. More overhead
2. Uses more storage
3. Late binding makes the program run slower

# override Keyword
```override``` keyword is used to make clear if a function is overridden or redefined. This is specified in function declaration and ensures that the function is virtual and that it is overriding a virtual base class function.
```cpp
class Sale {
    virtual double bill() const;
};

class DiscountSale : public Sale {
    double bill() const override;
};
```

Having virtual functions allow us to accomodate multiple types under one abstraction (polymorphism).

```cpp
class Book {
public: 
    int numPages;
    Book(int n) : numPages {n} {}
    virtual bool isHeavy() const {
        return numPages > 200;
    }
};

class Comic : public Book {
public:
    Comic(int n) : Book(n) {}
    bool isHeavy() const override {
        return numPages > 30;
    }
};

int main() {
    Comic c {40};
    Book *pB {&c};
    Book &rB {c};
    Comic *pc {&c};

    cout << pc->isHeavy() // true
         << pB->isHeavy() // true
         << rB.isHeavy()  // true
         << endl;
}
```

# final Keyword
```final``` keyword prevents a virtual function from being overriden. This is useful for inherited classes that inherit virtual functions where we don't want its derived classes to override it.
```cpp
class Sale{
    virtual double bill() const final;
};

class DiscountSale : public Sale {
    double bill() const; // ERROR
}
```

# Pure Virtual Functions
**Pure virtual functions** are used when a base class does not have a definition for them. To make a virtual function pure, we append ```=0``` to its declaration. i.e.
```cpp
virtual type foo()=0;
```

# Abstract Classes
**Abstract classes** are classes with one or more virtual functions. Here are some properties of abstract claseses:
* can only be used as a base class
* cannot create objects of an abstract class
* can still write code with parameters of the abstract class type which will apply to all object of derived classses
* inherited classes from abstract class will be abstract unless you provide definitions for all the inherited pure virtual functions

# Slicing Problem
We have learnt in Inheritance that a derived class can be assigned to objects of the base class. However, this means that we can only assign values included in the parent type, and we lose any new fields that the derived class has. This is the **slicing problem**. i.e.
```cpp
class Pet {
public:
    string name;
    virtual void print() const;
};
class Dog : public Pet {
public:
    string breed;
    void print() const; // virtual
};

int main() {
    Dog vdog;
    Pet vpet;
    vdog.name = "Tiny";
    vdog.breed = "Great Dane";
    vpet = vdog;
}
```

When we assign ```vdog``` to ```vpet```, we lose the ```breed``` field. To solve this, we use pointers and dynamic variables, and in doing so, we can treat object of the derrived class as an object of the base class without losing variables.
```cpp
int main() {
    Pet *ppet;
    Dog *pdog;
    pdog->name = "Tiny";
    pdog->breed = "Great Dane";
    ppet = pdog;
    cout << ppet->breed; // ERROR
    ppet->print(); // accesses breed field
}
```

# Virtual Destructors
Consider the following example:
```cpp
Base *pBase = new Derived;
delete pBase;
```
This calls the base class's destructor and not the derived class's. To fix this, we make the destructor virtual. It is thus good practice to make all destructors virtual.

# Upcasting & Downcasting

## Upcasting
**Upcasting** is casting from subclass object to an superclass type. This is safe since you're only disregarding some info.

## Downcasting
**Downcasting** is casting from an superclass object to a subclass type. this is dangerous as we are not assumming that additional member fields are being added. 

To solve this, we use ```dynamic_cast```, which works only with pointer types.
```cpp
Pet *ppet;
ppet = new Dog;
Dog *pdog = dynamic_cast<Pet*>(ppet);
```

```dynamic_cast``` informs us if it fails by returning ```nullptr```. Keep the following in mind when downcasting:
1. Keep track of member fields so you know the info to be added is present
2. Member functions must be virtual since ```dynamic_cast``` uses the virtual functions info to perform cast
