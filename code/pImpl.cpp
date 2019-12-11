#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// class.h
class Class {
    class Private;
    Private *pImpl;
public:
    Class();
    ~Class();
    void foo();
};

// class.cc
class Class::Private {
    // actual class implementation
public:
    void privateFoo() {
        cout << "private foo function" << endl;
    }
};

Class::Class() {
    pImpl = new Private();
}

Class::~Class() {
    delete pImpl;
}

void Class::foo(){
    pImpl->privateFoo();
}

int main() {
    Class c;
    c.foo();
}
