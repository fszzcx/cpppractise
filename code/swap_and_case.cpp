// 1) 定义两个 int 变量并初始化，分别用指针和引用交换
// 2) 定义 char 变量 lower='x', upper='M'，分别转成大写和小写
#include <cstdio>                       // 【1】printf 所在头文件

// ---------- 用指针交换 ----------
// 形参是 int*：传进来的是"地址"，通过 *pa / *pb 能直接改到 main 里的 a、b
void swapByPointer(int* pa, int* pb)    // 【2】指针作函数参数
{
    int t = *pa;                        // *pa = a 的值（解引用）
    *pa = *pb;                          // 通过地址改 main 里的 a
    *pb = t;
}

// ---------- 用引用交换 ----------
// int& 是"引用"：ra 就是 a 的别名，改 ra 就是改 a
// 注意：引用是 C++ 才有的语法，C 语言里没有
void swapByReference(int& ra, int& rb)  // 【3】引用作函数参数
{
    int t = ra;
    ra = rb;
    rb = t;
}

int main()
{
    // ========== 第 1 问 ==========
    int a = 12, b = 7;                  // 【4】定义并初始化：定义的同时给初值

    printf("交换前      : a=%d, b=%d\n", a, b);

    swapByPointer(&a, &b);              // 【5】调用时传"地址"：&a、&b
    printf("指针交换后  : a=%d, b=%d\n", a, b);

    swapByReference(a, b);              // 【6】引用调用直接传变量本身，不写 &
    printf("引用换回原状: a=%d, b=%d\n\n", a, b);

    // ========== 第 2 问 ==========
    char lower = 'x';                   // 【7】char 存的是 ASCII 码（一个整数）
    char upper = 'M';

    char toUpper = lower - 32;          // 【8】小写转大写：ASCII 码 - 32
    char toLower = upper + 32;          //            大写转小写：ASCII 码 + 32
                                        // 'a'~'z' = 97~122，'A'~'Z' = 65~90
                                        // 两套正好相差 32

    printf("'%c'(ASCII %d) 转大写 -> '%c'(ASCII %d)\n",
           lower, lower, toUpper, toUpper);
    printf("'%c'(ASCII %d) 转小写 -> '%c'(ASCII %d)\n",
           upper, upper, toLower, toLower);
    return 0;
}
