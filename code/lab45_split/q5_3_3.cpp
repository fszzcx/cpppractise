#include <iostream>
using namespace std;

int main() {
    int x = 1, y = 2;
    int& r = x;
    r = y;
    cout << "x = " << x << ", y = " << y << ", r = " << r << endl;
    cout << "&x = " << &x << ", &y = " << &y << ", &r = " << &r << endl;
    return 0;
}
