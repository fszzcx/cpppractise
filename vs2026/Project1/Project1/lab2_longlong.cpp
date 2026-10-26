#include <iostream>
using namespace std;
 int main()
 {
	 int x;
	 long long y;

	 cout << "Please input a large integer: ";
	 cin >> x;
	 if (!cin) {
			 cin.clear();
			 cout << "int x =" << x << " (overflow!)" << endl;
		 }else {
		 cout << "int x =" << x << endl;

	 }

	 cout << "Please re-enter the same integer: ";
	 cin >> y;
	 cout << "long long y =" << y << endl;

	 return 0;

 }
