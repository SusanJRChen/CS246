#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class AbstractClass {
protected:
    void virtual operation()=0;
public:
    void templateMethod() {
        cout << "Class does ";
        operation();
    }
};

class ConcreteClassA : public AbstractClass {
protected:
    void operation() {
        cout << "A operation" << endl;
    }
};

class ConcreteClassB : public AbstractClass {
protected:
    void operation() {
        cout << "B operation" << endl;
    }
};

int main() {
    ConcreteClassA a;
    a.templateMethod();
    ConcreteClassB b;
    b.templateMethod();
}
