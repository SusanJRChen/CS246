#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVec(vector<int> vec) {
    for (int el: vec) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1,2,3};
    cout << "size: " << vec.size() << endl;
    
    printVec(vec);
    return 0;
}
