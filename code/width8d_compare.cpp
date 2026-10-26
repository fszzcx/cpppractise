#include<bits/stdc++.h>
using namespace std;
int main()
{
//对比：同样三列数据，加不加宽度限制的差别
printf("--- 不加宽度 %%d ---\n");
printf("%d %d %d\n", 95, 100, 7);
printf("%d %d %d\n", 8, 1000, 123456);
printf("%d %d %d\n", -5, 42, 99999999);

printf("--- 加宽度 %%8d ---\n");
printf("%8d%8d%8d\n", 95, 100, 7);
printf("%8d%8d%8d\n", 8, 1000, 123456);
printf("%8d%8d%8d\n", -5, 42, 99999999);
return 0;
}
