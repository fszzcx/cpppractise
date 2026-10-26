#include <iostream>
using namespace std;

int main() {
    int a = 3;
    const int& ra = a;
    a = 8;
    const int& rb = a * 2;
    const int& rc = 42;
    cout << "ra = " << ra << ", rb = " << rb << ", rc = " << rc << endl;
    return 0;
}
