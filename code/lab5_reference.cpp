// 实验题 5：引用用法（四小问合一个程序，可直接编译运行）
#include <iostream>
using namespace std;

// 4.4 用引用交换两个整数
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    // ==================== 1.1 ====================
    int x = 5;
    int& r = x;                     // r 是 x 的别名，绑定后不可改
    r = 10;                         // 通过引用改值，x 同步变
    cout << "x = " << x << ", r = " << r << endl;
    cout << "&x = " << &x << ", &r = " << &r << endl;
    cout << "两个地址完全相同 -> r 就是 x 本身" << endl << endl;

    // ==================== 2.2 三句错误尝试 ====================
    // int& r2;            错：引用必须初始化（没有"先定义后绑定"）
    // int& r3 = 10;       错：非常量引用不能绑定字面量（10 是临时值）
    // double d = 3.14;
    // int& r4 = d;        错：引用类型必须与被引用者完全一致
    // 三句的正确/合法写法：
    const int& r3 = 10;             // const 引用可以绑字面量
    double d = 3.14;
    double& r4 = d;                 // 类型一致即可
    cout << "r3 = " << r3 << ", r4 = " << r4 << endl << endl;

    // ==================== 3.3 r=y 之后 r 变成 y 的引用吗 ====================
    int x1 = 1, y1 = 2;
    int& r5 = x1;                   // r5 绑定 x1
    r5 = y1;                        // 这是"把 y1 的值赋给 x1"，不是改绑
    cout << "x1=" << x1 << " y1=" << y1 << " r5=" << r5 << endl;
    cout << "&x1=" << &x1 << " &y1=" << &y1 << " &r5=" << &r5 << endl;
    cout << "结论：r5 没有变成 y1 的引用（&r5 仍等于 &x1）" << endl << endl;

    // ==================== 4.4 常引用 ====================
    int m = 1, n = 2;
    swap(m, n);                     // 传变量本身，函数内通过别名互换
    cout << "swap 后: m=" << m << " n=" << n << endl;

    int a = 3;
    const int& ra = a;              // 常引用：可以读，不能写
    // ra = 1;                      // 错：不能通过 const 引用修改
    a = 8;                          // 但 a 自己可以改，ra 读到的值跟着变
    const int& rb = a * 2;          // 合法：const 引用可绑临时值(表达式结果)
    const int& rc = 42;             // 合法：const 引用可绑字面量
    cout << "ra=" << ra << " rb=" << rb << " rc=" << rc << endl;
    return 0;
}
