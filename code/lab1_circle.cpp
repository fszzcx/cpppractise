// 姓名：XXX   学号：XXXXXXXX
/* 实验一 */
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.141592653589793;
    double r;

    cout << "请输入半径 r: ";
    cin >> r;

    double girth = 2 * PI * r;
    double area = PI * r * r;

    cout << "radius=" << r << endl;
    cout << "girth=" << girth << endl;
    cout << "area=" << area << endl;

    return 0;
}
