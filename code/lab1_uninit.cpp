// 实验一 第2题：局部变量未初始化的输出
#include <iostream>
using namespace std;

int main()
{
    int a;      // 局部变量，未赋初值
    int b = 0;  // 显式初始化为 0

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    return 0;
}
