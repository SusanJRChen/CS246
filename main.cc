#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class NoMilk {
public:
int i;
    NoMilk(int i) : i {i} {
        cout << i << " created" << endl;
    }
    ~NoMilk() {
        cout << i << "des" << endl;
    }
};

void f() { vector<NoMilk> v(1, 1); }
void g() { vector<NoMilk *> v(1, new NoMilk(2)); }
void h() { vector<shared_ptr<NoMilk>> v(1, make_shared<NoMilk>(3)); }

int main () {
    f();
    g();
    h();
}