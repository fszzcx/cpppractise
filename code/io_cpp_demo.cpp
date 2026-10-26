#include <iostream>
#include <iomanip>   // setw / setprecision / fixed 都在这个头文件
using namespace std;

int main() {
    int age = 18;
    double pi = 3.14159265;

    // ---- C++ 版输出：不用记 %d %f，类型自动识别 ----
    cout << "年龄: " << age << ", 圆周率: " << pi << endl;

    // ---- 对应 printf("%8d\n", age)：占 8 个字符宽度右对齐 ----
    cout << setw(8) << age << endl;

    // ---- 对应 printf("%.2f\n", pi)：保留 2 位小数 ----
    cout << fixed << setprecision(2) << pi << endl;

    // ---- 对应 scanf：cin 后面直接写变量名，不用 & ----
    int x;
    cout << "请输入一个整数: ";
    cin >> x;
    cout << "你输入的是 " << x << "，翻倍是 " << x * 2 << endl;
    return 0;
}
