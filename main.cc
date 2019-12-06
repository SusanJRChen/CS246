#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void printVec(vector<int> vec) {
    for (int el: vec) {
        cout << el << " ";
    }
    cout << endl;
}

class Obj {
public:
    Obj() { cout << "Obj created" << endl; }
    Obj(int a) { cout << "Obj created with int " << endl; }
    ~Obj() { cout << "Obj " << this << " destroyed" << endl; }
    void print() { cout << "Obj at " << this << endl; }
};

void print(unique_ptr<Obj> obj) { obj->print(); }

int main() {
    Obj * raw = new Obj(1);
    weak_ptr<Obj> shobj;
    {
        // unique_ptr<Obj> shared = make_unique<Obj>();
    }
    return 0;
}
