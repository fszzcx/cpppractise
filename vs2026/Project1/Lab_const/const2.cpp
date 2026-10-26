// 情况①
const int x = 1;
x = 2;              // ✗ 报错: assignment of read-only variable 'x'

// 情况②
const int A = 78;  int c = 13;
const int* p = &A;  // 指向常量的指针（底层 const）
*p = 1;             // ✗ 报错: assignment of read-only location '*p'
p = &c;             // ✓ 合法！p 的指向可以改

// 情况③
int v = 5;
int* const q = &v;  // 常量指针（顶层 const）
q = &c;             // ✗ 报错: assignment of read-only variable 'q'
*q = 9;             // ✓ 合法！可以通过 q 改 v 的值（v 变成 9）

// 情况④
const int M = 10;
const int* const r = &M;  // 双重 const
r = &v;             // ✗ 报错: assignment of read-only variable 'r'
*r = 1;             // ✗ 报错: assignment of read-only location '*r'
