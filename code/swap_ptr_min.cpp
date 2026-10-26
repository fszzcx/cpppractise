#include <cstdio>
using namespace std;

int main() {
    int a = 12, b = 7;      // 先定义两个普通变量并初始化
    int* pa = &a;           // 指针存的是"地址"，所以要写 &a
    int* pb = &b;

    int t = *pa;            // *pa = 取出 a 的值（12）
    *pa = *pb;              // 把 b 的值写进 a
    *pb = t;

    printf("a=%d, b=%d\n", a, b);
    return 0;
}
