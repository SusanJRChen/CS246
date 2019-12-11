#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Pet {
public:
    Pet() {}
    ~Pet() {}
    string name;
    virtual void print() const {};
};
class Dog : public Pet {
public:
    Dog() {}
    ~Dog() {}
    string breed;
    void print() const {}; // virtual
};

int main() {
    Pet *ppet;
    Dog *pdog;
    pdog->name = "Tiny";
    pdog->breed = "Great Dane";
    ppet = pdog;
    cout << ppet->name << endl;
    pdog = static_cast<Dog*>(ppet);
    cout << pdog->breed << endl;
    // ppet->print(); // accesses breed field
}