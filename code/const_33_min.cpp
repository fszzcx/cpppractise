// 3.3 指向常量的指针 指向 普通变量（最小可运行版）
#include <cstdio>

int main()
{
    int v = 5;
    const int* p = &v;      // p 指向 v，但通过 p 只能读

    // *p = 1;              // 编译错误: assignment of read-only location '* p'
    v = 99;                 // 合法: v 自己不是 const

    printf("v  = %d\n", v);
    printf("*p = %d\n", *p);
    return 0;
}
