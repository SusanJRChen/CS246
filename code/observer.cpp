#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;


template <class T>
class AbstractObserver {
public:
    virtual void notify(T obj)=0;

};

template <class T>
class AbstractSubject {
    vector<AbstractObserver<T> *> obs;
public:
    void attach(AbstractObserver<T> * ob) { obs.push_back(ob); }
    void detach(AbstractObserver<T> & ob) {
        obs.erase(remove(obs.begin(), obs.end(), ob), obs.end());
    }
    void notify(T obj) {
        for (auto ob : this->obs) ob->notify(obj);
    }
};

template <class T>
class ConcreteSubject : public AbstractSubject<T> {
public:
    void update(T obj) { AbstractSubject<T>::notify(obj); }
};

template <class T>
class ConcreteObserver : public AbstractObserver<T> {
    T data;
public:
    ConcreteObserver(T data) : data { data } {}
    void notify(T obj) { cout << "current data: " << data << " notified with obj " << obj << endl; }
};

int main() {
    ConcreteSubject<char> sub;
    ConcreteObserver<char> ob1('a');
    ConcreteObserver<char> ob2('b');
    ConcreteObserver<char> ob3('c');
    ConcreteObserver<char> ob4('d');

    sub.attach(&ob1);
    sub.attach(&ob2);
    sub.attach(&ob3);
    sub.attach(&ob4);

    sub.update('e');

}
