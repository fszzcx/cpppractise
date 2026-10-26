#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int m = 1, n = 2;
    swap(m, n);
    cout << "m = " << m << ", n = " << n << endl;
    return 0;
}
