#include <cstdio>

int main()
{
    int a = 10, b = 20;
    int r = (a > b ? a : b);
    printf("r = %d\n", r);

    printf("a > b 的值 = %d   (0 就是假)\n", a > b);

    int r2;
    if (a > b) r2 = a;
    else       r2 = b;
    printf("r2 = %d   (if-else 版本结果一样)\n", r2);

    int n = 7;
    printf("%d is %s\n", n, n % 2 == 0 ? "even" : "odd");

    int v = -8;
    int absv = v > 0 ? v : -v;
    printf("|%d| = %d\n", v, absv);
    return 0;
}
