#include <iostream>
using namespace std;

int main() {
    int v = 10;

    void* vp = &v;              // 合法：任何类型的地址都能放进 void*

    // cout << *vp << endl;     // 错误 E0852：void* 不能解引用
    cout << *static_cast<int*>(vp) << endl;   // 改法：先转回 int* 再解引用
    return 0;
}
