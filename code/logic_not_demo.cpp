#include <cstdio>

int main()
{
    int flag = 2;

    printf("!0  = %d\n", !0);
    printf("!1  = %d\n", !1);
    printf("!2  = %d\n", !2);
    printf("!-5 = %d\n", !-5);
    printf("!!2 = %d\n", !!2);
    printf("\n");

    if (!flag)
        printf("hehe\n");
    else
        printf("hehe mei da yin, yinwei !flag = %d\n", !flag);

    printf("if(flag) %s\n", flag ? "chengli" : "bu chengli");
    return 0;
}
