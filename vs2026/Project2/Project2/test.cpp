#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    /* ---------- 第一步：借纸、写。文件不存在会新建，存在会清空 ---------- */
    FILE *fp = fopen("scores.txt", "w");        // "w" 只写
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fprintf(fp, "Alice 90\n");                  // 往文件写一行（含换行符 \n）
    fprintf(fp, "Bob 85\n");
    fprintf(fp, "Cathy 60\n");
    fclose(fp);                                 // 写完必须先关，数据才落盘

    /* ---------- 第二步：借回来，求平均 ---------- */
    fp = fopen("scores.txt", "r");              // "r" 只读
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char name[32];      // 存名字的字符数组（数组名字本身就是地址）
    double score;       // 存分数
    double sum = 0.0;   // 累加器，记得清零
    int cnt = 0;        // 人数计数器

    // fscanf 返回成功读到几个字段，模式串里有 2 个 %，读满就是 2
    while (fscanf(fp, "%31s %lf", name, &score) == 2) {
        sum += score;                           // 累加成绩
        cnt++;                                  // 人数加一
        printf("%s: %.1f\n", name, score);      // 打印到屏幕
    }
    fclose(fp);

    if (cnt > 0)                                // 防止除以 0
        printf("平均分: %.2f\n", sum / cnt);
    return 0;
}
