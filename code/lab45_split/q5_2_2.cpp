#include <iostream>
using namespace std;

int main() {
    const int& r3 = 10;
    double d = 3.14;
    double& r4 = d;
    cout << "r3 = " << r3 << ", r4 = " << r4 << endl;
    return 0;
}
