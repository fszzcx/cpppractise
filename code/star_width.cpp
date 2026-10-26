// 演示 %d 与 %*d 的区别
// 关键：%*d 的宽度不是写死在格式串里的，而是从参数里"读"出来的
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 42;
    int w = 8;

    printf("a = 42   w = 8\n\n");

    printf("A) printf(\"%%d\", a)          -> |%d|\n", a);
    printf("B) printf(\"%%8d\", a)         -> |%8d|\n", a);
    printf("C) printf(\"%%*d\", w, a)      -> |%*d|\n", w, a);
    printf("D) printf(\"%%*d\", 12, a)     -> |%*d|\n", 12, a);
    printf("E) printf(\"%%*d\", -8, a)     -> |%*d|\n", -8, a);

    printf("\n循环里改宽度，只用 %%*d 才做得到：\n");
    for (int i = 1; i <= 10; i++)
        printf("   width=%2d -> |%*d|\n", i, i, a);

    return 0;
}
