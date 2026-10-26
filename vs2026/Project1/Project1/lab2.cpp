#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cout << "请输入两个整数m,n:";
	cin >> m >> n;
	
	cout << "m/n =" << m / n << endl;                // 整数除
	cout << "double m/n =" << double(m) / n << endl; // 浮点除
	

	return 0;
}
