#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Base {
public:
    virtual void foo()=0;
};
class DerivedA : public Base {
public:
    void foo() { cout << "A" << endl; }
};
class DerivedB : public Base {
public:
    void foo() { cout << "B" << endl; }
};

class Foo {
public:
    void foo() { cout << "F" << endl; }
};

int main() {
    DerivedA * a = new DerivedA;
    cout << "address of item: " << a << endl;

    Base * b = a;
    cout << "address of item: " << b << endl;
    
    DerivedB * c = static_cast<DerivedB *>(b);
    cout << "address of item: " << c << endl;
    
    DerivedB * d = dynamic_cast<DerivedB *>(b);
    cout << "address of item: " << d << endl;
    
    DerivedA * e = dynamic_cast<DerivedA *>(b);
    cout << "address of item: " << e << endl;

    Foo * f = reinterpret_cast<Foo*>(a);
    cout << "address of item: " << f << endl;
    f->foo();
}
