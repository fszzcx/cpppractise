// 验证 * 与参数的对应关系
#include <cstdio>

int main()
{
    int a = 67, b = 5;

    printf("1) printf(\"[%%*d]\", 8, a)\n");
    printf("   -> [%*d]\n\n", 8, a);

    printf("2) printf(\"[%%*d][%%*d]\", 5, a, 3, b)\n");
    printf("   -> [%*d][%*d]\n\n", 5, a, 3, b);

    printf("3) printf(\"[%%.*f]\", 3, 3.14159265)   精度也能用 *\n");
    printf("   -> [%.*f]\n", 3, 3.14159265);
    return 0;
}
