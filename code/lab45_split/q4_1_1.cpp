#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;
    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;
    cout << "&x = " << &x << endl;
    cout << "p = " << p << endl;
    *p = 100;
    cout << "x = " << x << endl;
    return 0;
}
