#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Top {
public:
    virtual ~Top() {}
    virtual void f() { cout << "Top called" << endl; }
};

// Left::f() > Top::f()
class Left : virtual public Top {
public:
    void f() { cout << "Left called" << endl; }
};

class Right : virtual public Top {};

class Bottom: public Left, public Right {};

int main() {
    Bottom b;
    b.f(); // calls Left::f();
}
