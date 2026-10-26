#include <iostream>
using namespace std;

int main() {
    int* p;                       // 未初始化
    int v = 10;
    cout << *p << endl;           // 解引用随机地址
    int* q = nullptr;
    cout << *q << endl;           // 解引用空指针
    const int k = 100;
    const int* pk = &k;
    int m = 1;
    const int* cp = &m;
    cp = &v;
    int* const qc = &v;
    *qc = 99;
    double d = 1.2;
    double* pd = &d;
    void* vp = &v;
    cout << *static_cast<int*>(vp) << endl;
    return 0;
}
