// 演示：输入数字超过 8 位时，%8d 是否还能对齐
// 三种方案的对比：固定 %8d / 固定 %11d / 动态宽度 %*d
#include <bits/stdc++.h>
using namespace std;

// 数出一个整数打印出来占几个字符（含负号）
int widthOf(int x)
{
    char buf[32];
    return snprintf(buf, sizeof(buf), "%d", x);
}

int main()
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    printf("input        : %d  %d  %d\n", a, b, c);
    printf("digit count  : %d  %d  %d\n\n", widthOf(a), widthOf(b), widthOf(c));

    printf("[plan 1] fixed  %%8d\n");
    printf("         |%8d|%8d|%8d|\n\n", a, b, c);

    printf("[plan 2] fixed  %%11d   (covers whole int range)\n");
    printf("         |%11d|%11d|%11d|\n\n", a, b, c);

    int w = max({widthOf(a), widthOf(b), widthOf(c)});
    printf("[plan 3] dynamic %%*d,  width = %d\n", w);
    printf("         |%*d|%*d|%*d|\n", w, a, w, b, w, c);

    return 0;
}
