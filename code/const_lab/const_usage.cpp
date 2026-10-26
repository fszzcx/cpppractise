// ===================================================================
// 实验 3：const 用法
// 所有"尝试修改"的非法语句都以注释形式保留在原位，
// 注释里记录的是 g++ 真实编译报错原文（g++ -std=c++17）。
// ===================================================================
#include <cstdio>

// ---------------------- 1.1 const 修饰普通变量 ----------------------
const double PI   = 3.14159265358979;
const int    MAXN = 1000;

// ---------------------- 2.2 四类指针/变量组合 ----------------------
void case1() {
    const int x = 1;
    // x = 2;                       // error: assignment of read-only variable 'x'
    printf("case1: x = %d（x 是 const 变量，本身不可写）\n", x);
}

void case2() {
    const int A = 78;
    int       c = 13;
    const int* p = &A;              // p 是"指向常量的指针"：*p 不可写，p 本身可改

    // *p = 1;                      // error: assignment of read-only location '* p'
    p = &c;                         // 合法！p 这个"指针变量"本身不是 const，可以改指向
    printf("case2: *p = %d（p 已改指向普通变量 c，但通过 p 仍然只能读）\n", *p);
}

void case3() {
    int c = 13; (void)c;            // c 只在注释掉的非法语句里用到
    int v = 5;
    int* const q = &v;              // q 是"常量指针"：q 本身不可改指向，*q 可写

    // q = &c;                      // error: assignment of read-only variable 'q'
    *q = 9;                         // 合法！指向的对象 v 不是 const，可以写
    printf("case3: *q = %d（q 不能改指向，但可以通过 q 修改 v）\n", *q);
}

void case4() {
    int v = 5; (void)v;             // v 只在注释掉的非法语句里用到
    const int M = 10;
    const int* const r = &M;        // 双重 const：r 不可改指向，*r 也不可写

    // r = &v;                      // error: assignment of read-only variable 'r'
    // *r = 1;                      // error: assignment of read-only location '*(const int*)r'
    printf("case4: *r = %d（r 的指向和指向的对象都被锁死，只能读）\n", *r);
}

// ---------------------- 3.3 指向常量的指针 指向 普通变量 ----------------------
void printArray(const int* a, int n) {  // 实际用途：函数用"指向常量的指针"接参数
    for (int i = 0; i < n; i++)         // 承诺"我只读，绝不改你的数据"
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    // 1.1 用 const 常量算圆面积
    double r = 2.0;
    printf("半径 %.1f 的圆面积 = %f\n\n", r, PI * r * r);
    // PI   = 3.14;   // error: assignment of read-only variable 'PI'
    // MAXN = 2000;   // error: assignment of read-only variable 'MAXN'

    // 2.2 四类逐个观察
    case1(); case2(); case3(); case4();

    // 3.3 "指向常量的指针" 指向 普通变量
    int v = 5;
    const int* p = &v;              // 合法：普通变量可以交给"只读指针"看管
    // *p = 1;                      // error: assignment of read-only location '* p'
                                    // 通过 p 走这条路，编译器一律禁止写

    v = 99;                         // 合法！v 自己没有被 const，直接改完全没问题
    printf("\n3.3: v = %d\n", v);
    printf("     通过 p 读到的 *p = %d\n", *p);   // p 只是"看"的窗口，数据变了它看到的也变
    printf("     结论：const int* 锁的是\"通过 p 这条路写\"，不是锁 v 本身\n\n");

    int arr[3] = {1, 2, 3};
    printArray(arr, 3);             // 常见用法：把数组交给一个"保证只读"的函数
    return 0;
}
