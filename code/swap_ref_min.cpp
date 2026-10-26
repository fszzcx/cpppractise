#include <cstdio>
using namespace std;

int main() {
    int a = 12, b = 7;

    // 定义引用：ra 是 a 的别名，rb 是 b 的别名
    // 引用必须在定义时初始化（绑定），之后不能改绑到别的变量
    int& ra = a;
    int& rb = b;

    int t = ra;     // t = 12
    ra = rb;        // a = 7
    rb = t;         // b = 12

    printf("a=%d, b=%d\n", a, b);
    return 0;
}
