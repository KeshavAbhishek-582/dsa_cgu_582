#include <iostream>
using namespace std;

class Base1 {
    public:
    Base1() {
            cout << " Base1" << endl;
    }
};
class Base2 {
    public:
    Base2() {
        cout << "Base2" << endl;
    }
};

class Derived: public Base1, public Base2 {
    public:
    Derived() {
        cout << "Derived" << endl;
    }
};
int main() {
    Derived d;
    return 0;
}