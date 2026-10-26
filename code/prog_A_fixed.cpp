#include <iostream>
using namespace std;

int main() {
    int b = 5;
    int a = b + 10;
    const int n = 20;
    const double PI = 3.14159;
    cout << a << endl;
    cout << b << endl;
    int x = 5, y = 2;
    cout << x / y << endl;
    cout << double(x) / y << endl;
    char c;
    cin >> c;
    cout << int(c) << endl;
    cout << int(c + 1) << endl;
    return 0;
}
