#include <iostream>
using namespace std;

int main() {
    int i = 0;
    double d = 1.5;
    double* dp = &d;
    int* ip = &i;
    void* vp = &i;
    cout << "*dp = " << *dp << endl;
    cout << "*ip = " << *ip << endl;
    cout << "*static_cast<int*>(vp) = " << *static_cast<int*>(vp) << endl;
    return 0;
}
