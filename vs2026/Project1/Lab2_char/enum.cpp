#include <iostream>
using namespace std;

enum colour { red, yellow, blue, white, black };

int main()
{
    colour c = blue;
    cout << "c 对应的整数 = " << c << endl;
    cout << "red=" << red << " blue=" << blue << " black=" << black << endl;
    return 0;
}
