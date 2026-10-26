// 复现你的错误：printf("%*d\n", a) 只传了 1 个参数
// %*d 其实需要 2 个参数：第 1 个是宽度，第 2 个才是数值
#include <cstdio>

int main()
{
    int a = 67;

    printf("A) printf(\"%%*d\", a)      -> |%*d|\n", a);      // 错：缺参数
    printf("B) printf(\"%%*d\", 8, a)   -> |%*d|\n", 8, a);   // 对：宽度8
    printf("C) printf(\"%%d\", a)       -> |%d|\n", a);
    printf("D) printf(\"%%8d\", a)      -> |%8d|\n", a);
    return 0;
}
