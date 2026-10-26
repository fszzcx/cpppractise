// 第 2 小题：定义两个 char 变量 lower='x'、upper='M'，分别转成大写和小写
#include <cstdio>       // 【知识点 1】printf 所在头文件
#include <cctype>       // 【知识点 2】toupper / tolower 所在头文件

int main()
{
    // ========== 定义并初始化 ==========
    char lower = 'x';       // 【知识点 3】char 类型：存储"一个字符"
    char upper = 'M';       // 本质存的是 ASCII 码（一个整数），占 1 字节

    // ========== 方法一：手动加减 32（题目想让你体会的写法）==========
    // 【知识点 4】ASCII 码规律：
    //     'A'~'Z' → 65 ~ 90
    //     'a'~'z' → 97 ~ 122
    //     两套正好相差 32，所以小写转大写减 32，大写转小写加 32
    char toUpper1 = lower - 32;   // 'x'(120) - 32 = 88 = 'X'
    char toLower1 = upper + 32;   // 'M'(77)  + 32 = 109 = 'm'

    // ========== 方法二：用标准库函数（工程上推荐）==========
    // 【知识点 5】toupper / tolower：更直观、不用担心记错 32
    //     返回的是 int，所以赋给 char 时可以显式转换
    char toUpper2 = (char)toupper((unsigned char)lower);
    char toLower2 = (char)tolower((unsigned char)upper);

    // ========== 输出 ==========
    // 【知识点 6】同一份数据，%c 看是字符，%d 看是 ASCII 码数字
    // 【知识点 7】%% 在格式串里表示一个真正的百分号
    printf("----- 方法一：手动 ±32 -----\n");
    printf("'%c'(ASCII %d) 转大写 -> '%c'(ASCII %d)\n",
           lower, lower, toUpper1, toUpper1);
    printf("'%c'(ASCII %d) 转小写 -> '%c'(ASCII %d)\n",
           upper, upper, toLower1, toLower1);

    printf("\n----- 方法二：toupper/tolower -----\n");
    printf("'%c' 转大写 -> '%c'\n", lower, toUpper2);
    printf("'%c' 转小写 -> '%c'\n", upper, toLower2);

    // 【知识点 8】边界情况：非字母字符不会被改变
    char digit = '7';
    printf("\n边界测试：'%c' 转大写 -> '%c'（非字母原样返回）\n",
           digit, (char)toupper((unsigned char)digit));

    return 0;       // 【知识点 9】返回 0 表示正常结束
}
