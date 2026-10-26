// 实验题 4：指针用法（四小问合一个程序，可直接编译运行）
#include <iostream>
using namespace std;

// 3.3 版本一：通过指针交换"所指对象的值"
void swapByPtr(int* pa, int* pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main()
{
    // ==================== 1.1 ====================
    int x = 10;
    int* p = &x;                    // p 存 x 的地址

    cout << "x  = " << x << endl;   // 10        变量本身的值
    cout << "*p = " << *p << endl;  // 10        解引用：p 指向的那个变量的值
    cout << "&x = " << &x << endl;  // x 的地址
    cout << "p  = " << p << endl;   // 与 &x 相同：指针里存的就是地址

    *p = 100;                       // 通过指针改 x 的值
    cout << "用 *p=100 改值后, x = " << x << endl << endl;

    // ==================== 2.2 两段对比 ====================
    // ---- 版本A（危险写法，勿直接运行）----
    // int* q;
    // cout << *q << endl;
    // 结果：编译有警告（使用了未初始化的 q），运行时解引用随机地址
    //       大概率程序崩溃（Segmentation fault / 0xC0000005）

    // ---- 版本B（安全写法）----
    int* q = nullptr;
    if (q != nullptr)
        cout << *q << endl;
    else
        cout << "null pointer" << endl;
    cout << endl;

    // ==================== 3.3 两个版本 ====================
    // 版本一：交换"所指对象的值" —— i1、i2 真的互换
    int i1 = 1, i2 = 2;
    swapByPtr(&i1, &i2);
    cout << "版本一(换对象的值): i1=" << i1 << " i2=" << i2 << endl;

    // 版本二：只交换两个指针变量本身 —— 对象不动，指向对调
    int* p1 = &i1;
    int* p2 = &i2;
    int* t = p1;                    // 交换 p1、p2 里存的地址
    p1 = p2;
    p2 = t;
    cout << "版本二(只换指针): *p1=" << *p1 << " *p2=" << *p2
         << " i1=" << i1 << " i2=" << i2 << endl;
    cout << "结论：i1、i2 完全没变，变的只是 p1、p2 各自指向谁" << endl << endl;

    // ==================== 4.4 判断并改错 ====================
    int i = 0;
    // double* dp = &i;             // 错：double* 不能指向 int
    double d = 1.5;
    double* dp = &d;                // 改法一：指向同类型的变量
    int* ip = &i;                   // 本来就合法
    (void)dp; (void)ip;             // 仅演示声明合法性，不使用
    void* vp = &i;                  // 合法：void* 可以接收任何类型的地址
    // cout << *vp << endl;         // 错：void* 不带类型信息，不能解引用
    cout << "*static_cast<int*>(vp) = "
         << *static_cast<int*>(vp) << endl;   // 改法二：转回 int* 再解引用
    return 0;
}
