#include <iostream>
using namespace std;

int main() {
    int* q = nullptr;
    if (q != nullptr)
        cout << *q << endl;
    else
        cout << "null pointer" << endl;
    return 0;
}
