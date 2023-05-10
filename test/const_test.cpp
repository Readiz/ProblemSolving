#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyClass {
public:
    T val;
    MyClass(const T& a) {
        val = a; // Deep copy
    }
};


int main() {
    const string a = "Hihi";
    auto m = new MyClass<string>(a);
    cout << m->val << endl;
}