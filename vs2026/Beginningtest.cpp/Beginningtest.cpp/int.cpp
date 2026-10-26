//#include <cstdio>
//using namespace std;
//int main() {
//	int a = 67;
//	printf("%*d\n", 2, a);
//
//	return 0;
//}
//#include <cstdio>
//using namespace std;
//int main() {
//	const double pi = 3.14159265358979323846;
//	const int MAXN = 1000;
//	
//	double r = 2.0;
//	printf("圆面积 = %f\n", pi * r * r);
//
//
//	pi = 3.14; // 错误：不能修改常量
//	MAXN = 2000; // 错误：不能修改常量
//
//	return 0;
//
//}
//#include <cstdio>
//using namespace std;
//int main() {
//	int v = 5;
//	const int M = 10;
//	const int* const r = &M; // r是一个指向常量整数的常量指针
//
//	r = &v;
//	*r = 1;
//
//	return 0;
//}
//#include <cstdio>
//using namespace std;
//int main() {
//	const int* p        // const 在 * 左边  → 锁"对象"：*p 不能写，p 能改指向
//    int* const q        // const 在 * 右边  → 锁"指针"：p 不能改指向，*q 能写
//	const int* const r  // 两边都有        → 全锁，只能读
//
//}
//
//#include <cstdio>
//
//int main()
//{
//    int v = 5;
//    const int* p = &v;      // p 指向 v，但通过 p 只能读
//
//    // *p = 1;              // 编译错误: assignment of read-only location '* p'
//    v = 99;                 // 合法: v 自己不是 const
//
//    printf("v  = %d\n", v);
//    printf("*p = %d\n", *p);
//    return 0;
//}
//#include <cstdio>
//using namespace std;
//int main() {
//	int a = 12;
//	int b = 5;
//	int* pa = &a;
//	int* pb = &b;
//
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//
//	int& ra = a;
//	int& rb = b;
//
//	int t2 = ra;
//	ra = rb;
//	rb = t2;
//
//	printf("a = %d, b = %d\n", a, b);
//
//		return 0;
//}
//#include <cstdio>
//
//int main()
//{
//    char lower = 'x';
//    char upper = 'M';
//
//    char toUpper = lower - 32;
//    char toLower = upper + 32;
//
//    printf("'%c'-> '%c'\n",
//           lower, lower, toUpper, toUpper);
//    printf("'%c'-> '%c'\n",
//           upper, upper, toLower, toLower);
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {                             
//    int b = 5;
//    int a = b + 10;
//    const int n = 20;
//    const double PI = 3.14159;
//    cout << a << endl;
//    cout << b << endl;
//    int x = 5, y = 2;
//    cout << x / y << endl;              
//    cout << double(x) / y << endl;
//    char c;
//    cin >> c;
//    cout << int(c) << endl;
//    cout << int(c + 1) << endl;         
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int v = 10;
//    int* p = &v;                            
//    cout << *p << endl;                 
//    int* q = nullptr;                   
//    cout << *q << endl;                 
//    const int k = 100;
//    const int* pk = &k;                                               
//    int m = 1;
//    const int* cp = &m;                 
//    cp = &v;                            
//    int* const qc = &v;                      
//    *qc = 99;                           
//    double d = 1.2;
//    double* pd = &d;                       
//    void* vp = &v;
//    cout << *static_cast<int*>(vp) << endl;                
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int& r1;                           
//    int x = 5;
//    int& r2 = x;
//    cout << r2 << endl;
//    int& r3 = 10;                      
//    double d = 3.14;
//    int& r4 = d;                        
//    int a = 1, b = 2;
//    int& r5 = a;
//    r5 = b;                             
//    cout << a << b << r5 << endl;
//    const int c = 7;
//    int& r6 = c;                        
//    const int& r7 = c;
//    r7 = 8;                             
//    const int& r8 = a * 2;              
//    const int& r9 = 42;                 
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 5;
//    int& r2 = x;
//    cout << r2 << endl;
//    const int& r3 = 10;
//    double d = 3.14;
//    double& r4 = d;
//    int a = 1, b = 2;
//    int& r5 = a;
//    r5 = b;
//    cout << a << b << r5 << endl;
//    const int c = 7;
//    const int& r6 = c;
//    const int& r7 = c;
//    const int& r8 = a * 2;
//    const int& r9 = 42;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//void swapByPtr(int* pa, int* pb)
//{
//    int t = *pa;
//    *pa = *pb;
//    *pb = t;
//}
//int main() {
//    int a = 10;
//    int* p = &a;
//
//    cout << "a =" << a << endl;
//    cout << "*p =" << *p << endl;
//    cout << "p =" << p << endl;
//    cout << "&a =" << &a << endl;
//
//    cout <<"用*p改值后，a =" << a << endl;
//    *p = 100;
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int* q = nullptr;
//    if (q != nullptr)
//        cout << *q << endl;
//    else
//        cout << "null pointer" << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int i1 = 1, i2 = 2;
//    int* p1 = &i1;
//    int* p2 = &i2;
//    int* t = p1;
//    p1 = p2;
//    p2 = t;
//    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;
//    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int i = 0;
//    double d = 1.5;
//    double* dp = &d;
//    int* ip = &i;
//    void* vp = &i;
//    cout << "*dp = " << *dp << endl;
//    cout << "*ip = " << *ip << endl;
//    cout << "*static_cast<int*>(vp) = " << *static_cast<int*>(vp) << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 5;
//    int& r = x;
//    r = 10;
//    cout << "x = " << x << ", r = " << r << endl;
//    cout << "&x = " << &x << ", &r = " << &r << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    const int& r3 = 10;
//    double d = 3.14;
//    double& r4 = d;
//    cout << "r3 = " << r3 << ", r4 = " << r4 << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int x = 1, y = 2;
//    int& r = x;
//    r = y;
//    cout << "x = " << x << ", y = " << y << ", r = " << r << endl;
//    cout << "&x = " << &x << ", &y = " << &y << ", &r = " << &r << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//void swap(int& a, int& b) {
//    int t = a;
//    a = b;
//    b = t;
//}
//
//int main() {
//    int m = 1, n = 2;
//    swap(m, n);
//    cout << "m = " << m << ", n = " << n << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a = 3;
//    const int& ra = a;
//    a = 8;
//    const int& rb = a * 2;
//    const int& rc = 42;
//    cout << "ra = " << ra << ", rb = " << rb << ", rc = " << rc << endl;
//    return 0;
//}
