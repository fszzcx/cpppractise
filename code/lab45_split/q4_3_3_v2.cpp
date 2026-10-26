#include <iostream>
using namespace std;

int main() {
    int i1 = 1, i2 = 2;
    int* p1 = &i1;
    int* p2 = &i2;
    int* t = p1;
    p1 = p2;
    p2 = t;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    return 0;
}
