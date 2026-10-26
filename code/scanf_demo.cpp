// 演示 scanf 的三个关键行为：返回值、%c 的坑、格式串里空格的作用
#include <cstdio>

int main()
{
    int a = 0, b = 0;
    char c1 = 0, c2 = 0;

    int n1 = scanf("%d %d", &a, &b);
    printf("1) scanf(\"%%d %%d\", &a, &b)\n");
    printf("   返回值 n1 = %d   （成功读入 2 项）\n", n1);
    printf("   a = %d,  b = %d\n\n", a, b);

    int n2 = scanf("%c", &c1);
    printf("2) scanf(\"%%c\", &c1)    <- %%c 前面没有空格\n");
    printf("   返回值 n2 = %d，读到 ASCII %d", n2, (int)c1);
    if (c1 == '\n')      printf("  -> 是换行符 '\\n'  【坑】\n");
    else if (c1 == ' ')  printf("  -> 是空格\n");
    else                 printf("  -> 是字符 '%c'\n", c1);

    int n3 = scanf(" %c", &c2);
    printf("\n3) scanf(\" %%c\", &c2)   <- %%c 前面加了空格\n");
    printf("   返回值 n3 = %d，读到 ASCII %d", n3, (int)c2);
    if (c2 == '\n')      printf("  -> 还是换行符\n");
    else if (c2 == ' ')  printf("  -> 是空格\n");
    else                 printf("  -> 是字符 '%c'  【正确】\n", c2);

    return 0;
}
