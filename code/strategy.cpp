#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class AbstractStrategy {
public:
    virtual void AlgorithmInterface()=0;
};

class ConcreteStrategyA : public AbstractStrategy {
public:
    void AlgorithmInterface() {
        cout << "strategy A used" << endl;
    }

};

class ConcreteStrategyB : public AbstractStrategy {
public:
    void AlgorithmInterface() {
        cout << "strategy B used" << endl;
    }
};

class Context {
    AbstractStrategy * strategy;
public:
    enum ContextType { A, B };
    Context() : strategy { nullptr } {}
    void setStrategy(ContextType type) {
        if (type == ContextType::A) {
            delete strategy;
            strategy = new ConcreteStrategyA;
        }
        else {
            strategy = new ConcreteStrategyB;
        }
    }

    void performStrategy() {
        strategy->AlgorithmInterface();
    }
};

int main() {
    Context context;
    context.setStrategy(Context::ContextType::A);
    context.performStrategy();
    context.setStrategy(Context::ContextType::B);
    context.performStrategy();
}
