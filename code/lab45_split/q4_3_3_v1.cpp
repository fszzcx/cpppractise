#include <iostream>
using namespace std;

void swapByPtr(int* pa, int* pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main() {
    int i1 = 1, i2 = 2;
    swapByPtr(&i1, &i2);
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    return 0;
}
