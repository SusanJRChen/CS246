#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Product {
public:
    static Product * makeProduct(string type);
};

class ProductA : public Product {};
class ProductB : public Product {};

Product * Product::makeProduct(string type) {
    if (type == "A") return new ProductA();
    else if (type == "B") return new ProductB();
}

int main() {
    Product * a = Product::makeProduct("A");
}
