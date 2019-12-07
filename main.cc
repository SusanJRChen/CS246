#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void g(int *p) {
    cout << p << endl;
}

void f(const int *p) {
    cout << p <<endl;
    g((int *)p);
    cout << p <<endl;

}

int main() {
    int p = 1;
    f(&p);
}
