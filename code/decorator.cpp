#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Component {
public:
    void virtual operation()=0;
};

class ConcreteComponent : public Component {
public:
    void operation() { cout << "does nothing" << endl; }
};

class Decorator : public Component {
protected:
    Component * component;
public:
    Decorator(Component * component) : component {component} {}
    virtual ~Decorator() { delete component; }
};

class ConcreteDecA : public Decorator {
public:
    ConcreteDecA(Component * component) : Decorator {component} {}
    void operation() { 
        component->operation();
        cout << "Decorator A applied" << endl; 
    }
};

class ConcreteDecB : public Decorator {
public:
    ConcreteDecB(Component * component) : Decorator {component} {}
    void operation() { 
        component->operation();
        cout << "Decorator B applied" << endl; 
    }
};


int main() {
    Component * a = new ConcreteComponent();
    a = new ConcreteDecA(a);
    a = new ConcreteDecB(a);
    a->operation();

}
