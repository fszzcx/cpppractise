#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "请输入一个字符: ";
    cin >> ch;

    cout << "字符本身: " << ch << endl;          // 按字符输出
    cout << "ASCII 值: " << (int)ch << endl;    // 强制转 int
    cout << "ch+1 的 int 值: " << (int)(ch + 1) << endl;

    if (ch >= 'a' && ch <= 'z')                 // 是小写字母
        cout << "对应大写: " << (char)(ch - 32) << endl;

    return 0;
}
