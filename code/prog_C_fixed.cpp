#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int& r2 = x;
    cout << r2 << endl;
    const int& r3 = 10;
    double d = 3.14;
    double& r4 = d;
    int a = 1, b = 2;
    int& r5 = a;
    r5 = b;
    cout << a << b << r5 << endl;
    const int c = 7;
    const int& r6 = c;
    const int& r7 = c;
    const int& r8 = a * 2;
    const int& r9 = 42;
    return 0;
}
