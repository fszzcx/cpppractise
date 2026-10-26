#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int& r = x;
    r = 10;
    cout << "x = " << x << ", r = " << r << endl;
    cout << "&x = " << &x << ", &r = " << &r << endl;
    return 0;
}
