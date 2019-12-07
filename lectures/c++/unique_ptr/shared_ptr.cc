#include <iostream>
#include <memory>
using namespace std;

class Basic {
 public:
  int x;
  Basic (int x) : x(x) { cout << "Basic ctor running (x = " << x << ")" << endl; }
  ~Basic() { cout << "Basic dtor running" << endl; }
};

int main () {
  // auto for brevity; type of p1 is std::shared_ptr<Basic>
  auto p1 = make_shared<Basic>(5);  // 5 is ctor argument, passed to Basic

  if (p1->x < 10) {
    auto p2 = p1;  // two pointers to the same object
    cout << "Access x field through smart ptr p2:  " << p2->x << endl;
  }  // p2 is popped, but the object is NOT deleted  
  
  cout << "Access x field through smart ptr p1:  " << p1->x << endl;
}  // p1 is popped; the object IS deleted
