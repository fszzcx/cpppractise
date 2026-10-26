#include <iostream>
using namespace std;

const double PI = 3.141592653589793;   // const 常量
const int MAXN = 1000;

PI =3，14；
MAXN = 2000；


int main()
{
    double r;
    cout << "请输入半径 r: ";
    cin >> r;
    cout << "area = " << PI * r * r << endl;   // 用 const PI 算圆面积
    cout << "MAXN = " << MAXN << endl;

    // PI = 3.14;      // 尝试修改（放开后无法通过编译）
    // MAXN = 2000;    // 同样不允许
    return 0;
}
