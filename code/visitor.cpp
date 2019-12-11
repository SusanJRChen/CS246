#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class AbstractVisitor {
public:
    virtual void visit(ConcreteElementA &obj)=0;
    virtual void visit(ConcreteElementB &obj)=0;
};

class AbstractElement {
public:
    virtual void accept(AbstractVisitor &v)=0;
};

class ConcreteElementA : public AbstractElement {
public:
    void accept(AbstractVisitor &v) { v.visit(*this); }
};

class ConcreteElementB : public AbstractElement {
public:
    void accept(AbstractVisitor &v) { v.visit(*this); }
};

class ConcreteVisitor : public AbstractVisitor {
public:
    void visit(ConcreteElementA & obj) {
        cout << "ConcreteElementA visited" << endl;
    }
    void visit(ConcreteElementB & obj) {
        cout << "ConcreteElementB visited" << endl;
    }
};

int main() {
    ConcreteVisitor v;
    ConcreteElementA a;
    ConcreteElementB b;

    a.accept(v);
    b.accept(v);
}
