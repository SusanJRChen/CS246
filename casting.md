# Introduction to Casting
**casting** - the process of forcing one data type to be converted into another. There more general casts are used as follows: ```(type)expression)```. For example when converting from a double to an int: ```(int) 5.6``` becomes ```5```

There are 4 other types of casts:
1. static_cast
2. const_cast
3. dynamic_cast
4. reinterpret_cast

# Static Cast
```cpp
static_cast<Type> (Expression);
```
This function takes in a type and returns an "equivalent" value of type ```Type```. This can be used for non-polymorphic downcasting from a parent pointer to a child pointer. It does not change the value of variable in expression.

# Const Cast
```cpp
const_cast<Type> (Expression);
```
This is used to explicitly override ```const``` / ```volatile``` in a cast. The target type must be the same. It is used to either set or remove the ```const``` attribute.

```cpp
void g(int *p);
void f(const int *p) {
    g(const_cast(p));
}
```

# Dynamic Cast
```cpp
dynamic_cast<Type> (Expression);
```
Dynamic casting is a type-safe form of downcasting by verifying the validity of the cast at runtime. It performs polymorphic downcasting from a parent pointer to a child pointer. If it fails (i.e. pointer does not point to the type specified), it returns nullptr. It is safer than static_cast, but less efficient. This only works on polymorphic classes (have at least one virtual method).
```cpp
Book *pb;
Text *pt = static_cast<Text>(pb)->getTopic(); // might throw error

// alternatively:
Text *pt = dynamic_cast<Text>(pb); // nullptr if error
if (ptr) cout << pt->getTopic();
else cout << "not a Text";
```

# Reinterpret Cast
```cpp
reinterpret_cast<Type> (Expression);
```
This operator changes a pointer to any other type of pointer. It also allows casting from pointer to an integer type and vice versa. This is an implementation dependent cast and is unsafe.
```cpp
Student s;
// Force student to be treated like a turtle
Turtle *t = reinterpret_cast<Turtle*>(&s);
```

# Downcasting
**downcasting** is generally frowned upon because we might be downcasting to a wrong type. If possible, we should be using polymorphism rather than trying to downcast. If we do have to downcast, however, ```dynamic_cast``` provides a type-safe downcast operation because it returns a ```nullptr``` if the cast is not proper.
```cpp
Pet *b = new Cat; // Upcast
Dog *d1 = dynamic_cast<Dog*> (b); // returns nullptr
cat *c1 = dynamic_cast<Cat*> (b); // OK
```

## Downcasting References
Downcasting pointers is exception-safe as discussed earlier (returns ```nullptr``` if wrong type). However, if we try to ```dynamic_cast``` a reference variable of the wrong type, ```dynamic_cast``` will throw a ```bad_cast``` because there is no such ting as a null reference.

# RTTI (Run-Time Type Information)
**RTTI** refers to the ability to provide information about the type of a dynamic-typed object at runtime. ```dynamic_cast``` is a form of RTTI. We can also use ```typeid``` (declared in ```<typeinfo>```) and ```static_cast``` to downcast. 

```typeid``` returns a reference to a ```std::type_info``` object which can be used to compare objects/references/pointers with the desired type using ```==``` and ```!=```. ```typeid(obj).name()``` returns a string representation of the type name
```cpp
Circle c;
Shapre *s = &c; // Upcast
if (typeid(Circle) == typeid(s)) s = static_cast<Shape*>(&c);
```

## Mechanisms of RTTI with Dynamic Cast
When ```dynamic_cast<destination*>(src)``` is used:
1. Source pointers RTTI info is retrieved
2. RTTI info of destination is fetched
3. Library routine then determines whether source pointers type is of destination type or base class type

## Creating Your Own RTTI
RTTI requires only a virtual function to identify the exact type of the class, and a function to take a pointer to the base type and cast it down to the derived type.

This function produces a pointer of the derived type.
