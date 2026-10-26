# C 语言通关笔记（六·七）：动态内存与文件操作

> 写给正在准备从 C 切到 C++ 的自己。这两块是 C 的"实用最后一课"——动态内存管的是**程序运行时才知道多大的数据**，文件操作管的是**程序退出后数据还在不在**。

---

## 一、动态内存

### 1. 为什么需要它

到目前为止，你的数组大小都是写死的：

```c
int scores[100];   // 编译时就定死 100 个
```

问题来了：老师让你写个程序处理学生成绩，学生人数是运行时用户输入的——可能 3 个人，也可能 30000 人。开 30000 浪费，开 3 不够。这时候就需要**运行时向操作系统借内存**：

```c
int n;
scanf("%d", &n);

int *scores = malloc(n * sizeof(int));  // 借 n 个 int 的空间
```

### 2. 四个函数

都位于 `<stdlib.h>`：

```c
void *malloc(size_t size);              // 借 size 字节，内容不初始化（是垃圾值）
void *calloc(size_t n, size_t size);    // 借 n*size 字节，内容清零
void *realloc(void *p, size_t size);    // 把之前借的空间调整成 size 字节
void free(void *p);                     // 还回去
```

用法示例：

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int *p = malloc(n * sizeof(int));   // 注意：n * sizeof(int)，不是 n！
    if (p == NULL) {                    // 借不到（内存不足）会返回 NULL
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        p[i] = i * i;                   // 动态数组用起来和普通数组一样

    // 扩容到 10 个
    int *tmp = realloc(p, 10 * sizeof(int));
    if (tmp != NULL)
        p = tmp;                        // 注意：realloc 可能搬家，要用返回值

    free(p);                            // 用完必还
    p = NULL;                           // 好习惯：防止悬空指针误用
    return 0;
}
```

几个要点：

- `malloc` 的参数是**字节数**，所以永远写 `n * sizeof(类型)`。写 `malloc(n)` 是新手最经典 bug。
- **判 NULL 不能省**。借不到时直接解引用就是崩溃。
- `realloc(p, size)` 可能返回新地址（原地扩不开就搬家并复制旧数据），所以要用一个临时变量接住返回值，不能直接 `p = realloc(p, ...)`——一旦失败返回 NULL，你原来的指针就丢了，旧内存再也还不了。
- **malloc 和 free 必须一一配对**。一次 malloc 配一次 free，不多不少。

### 3. 内存泄漏——C 程序员的第一大罪

每次 malloc 都在堆上占一块地。只借不还，程序越长占越多，最后系统内存被吃光。这就是**内存泄漏**：

```c
void bad(void) {
    int *p = malloc(100 * sizeof(int));
    // 函数结束，p 消失了，那 100 个 int 没人知道在哪
    // ——泄漏！这块内存直到程序结束都收不回来
}
```

更隐蔽的泄漏场景：

```c
int *p = malloc(sizeof(int));
p = malloc(sizeof(int));   // 第二次赋值把第一个地址覆盖了，第一块泄漏
```

自查口诀：**每个 malloc 出来的地址，要么被 free，要么被存起来以后 free。**

### 4. 常见错误一览

| 错误                               | 后果              |
| -------------------------------- | --------------- |
| `free(p)` 之后继续用 `p`（悬空指针）        | 未定义行为，可能读到垃圾或崩溃 |
| 同一块内存 `free` 两次                  | 未定义行为，破坏堆结构     |
| `malloc` 忘了判 NULL                | 内存不足时直接解引用崩溃    |
| `free` 栈上变量 / 只 free 数组中间某个元素的地址 | 未定义行为           |
| 只 `malloc` 不 `free`              | 内存泄漏            |

### 5. 实战：动态结构体数组

结合结构体（第 5 点），做一个"运行时才确定人数"的学生表：

```c
typedef struct {
    char name[32];
    double score;
} Student;

int main(void) {
    int n;
    scanf("%d", &n);

    Student *stu = calloc(n, sizeof(Student));
    for (int i = 0; i < n; i++) {
        scanf("%31s %lf", stu[i].name, &stu[i].score);
    }

    // ... 处理 ...
    free(stu);
    return 0;
}
```

这块理解透了，C++ 里的 `new/delete`、`std::vector` 就只是换了个更省心的语法。

---

## 二、文件操作

### 1. 为什么程序退出数据就没了

普通变量都活在**内存**里，程序一结束，内存被回收，数据蒸发。要让数据活过一次运行，就得写进**磁盘文件**。C 用 `FILE*` 这一套（标准库 `<stdio.h>`）来干这件事。

### 2. 打开与关闭：fopen / fclose

```c
FILE *fp = fopen("data.txt", "r");   // 打开文件，返回 FILE*
if (fp == NULL) {                    // 打不开（不存在/没权限）返回 NULL
    perror("fopen");
    return 1;
}
// ... 读写 ...
fclose(fp);                          // 用完必须关闭
```

常用打开模式：

| 模式     | 含义           | 文件不存在时       |
| ------ | ------------ | ------------ |
| `"r"`  | 只读           | 打开失败，返回 NULL |
| `"w"`  | 只写，**清空原内容** | 自动创建         |
| `"a"`  | 追加写，写在末尾     | 自动创建         |
| `"r+"` | 读写（不清空）      | 失败           |
| `"w+"` | 读写（清空）       | 创建           |

二进制文件（图片、自己存的结构体数据）在模式里加 `b`：`"rb"`、`"wb"`。Windows 下文本模式会把 `\n` 翻译成 `\r\n`，加 `b` 就原样读写。

**经典坑**：想往文件里追加数据却用了 `"w"`——原文件被清空，欲哭无泪。

### 3. 格式化读写：fprintf / fscanf

和 `printf`/`scanf` 几乎一样，只是第一个参数多了个 `fp`：

```c
FILE *fp = fopen("students.txt", "w");
if (fp == NULL) return 1;

for (int i = 0; i < n; i++)
    fprintf(fp, "%s %.1f\n", stu[i].name, stu[i].score);
fclose(fp);
```

读回来：

```c
fp = fopen("students.txt", "r");
char name[32];
double score;
while (fscanf(fp, "%31s %lf", name, &score) == 2) {
    printf("%s %.1f\n", name, score);
}
fclose(fp);
```

**要点**：用 `fscanf` 的**返回值**控制循环。它返回成功读到的字段数，读到文件尾就不等于 2 了——这是最干净的循环写法，别用 `while(!feof(fp))`（详见下面的坑）。

### 4. 按行读写：fgets / fputs

读文本文件按行处理更稳：

```c
char line[256];
FILE *fp = fopen("data.txt", "r");
while (fgets(line, sizeof(line), fp) != NULL) {
    // line 包含行尾的 '\n'，不需要时可以去掉
    line[strcspn(line, "\n")] = '\0';
    printf("读到一行: %s\n", line);
}
fclose(fp);
```

`fgets` 三个优点：读满 `sizeof(line)-1` 自动停（**不会缓冲区溢出**）、按行分割、能判断文件尾。写文件配 `fputs(fp, ...)` 或直接 `fprintf`。

### 5. 二进制读写：fread / fwrite

把一整块内存原样写盘/读盘，速度快、不丢精度，配合动态内存正好：

```c
// 写：把 n 个 Student 结构体一次性写入
FILE *fp = fopen("students.dat", "wb");
fwrite(stu, sizeof(Student), n, fp);
fclose(fp);

// 读：先不知道 n？那就一块一块读
FILE *fp = fopen("students.dat", "rb");
Student *arr = NULL;
int n = 0, cap = 0;
Student tmp;
while (fread(&tmp, sizeof(Student), 1, fp) == 1) {
    if (n == cap) {                       // 空间不够，扩容
        cap = cap ? cap * 2 : 8;
        arr = realloc(arr, cap * sizeof(Student));
    }
    arr[n++] = tmp;
}
fclose(fp);
```

上面这段是**动态内存 + 文件操作**的合体实战：动态数组边读边扩容。这两个知识点放一起考的时候，多半就是这种题。

### 6. 判断文件尾：feof 的正确用法

**坑**：`while(!feof(fp))` 是错的。因为 `feof` 只有在**已经读到文件尾还尝试读**之后才置位，所以最后一次读取必然"失败"但你已经把垃圾数据当真了——最后会多处理一条重复记录。

正确姿势是**用读函数的返回值当循环条件**（就像上面 `fscanf(...) == 2`、`fgets(...) != NULL`、`fread(...) == 1`），`feof` 只用来在循环结束后区分"正常读完"还是"读取出错"。

### 7. 一个综合小例子：把成绩存文件再读出来求平均

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* 写入 */
    FILE *fp = fopen("scores.txt", "w");
    if (!fp) { perror("fopen"); return 1; }
    fprintf(fp, "Alice 90\nBob 75\nCathy 88\n");
    fclose(fp);

    /* 读回 */
    fp = fopen("scores.txt", "r");
    if (!fp) { perror("fopen"); return 1; }

    double sum = 0; int cnt = 0;
    char name[32]; double score;
    while (fscanf(fp, "%31s %lf", name, &score) == 2) {
        sum += score; cnt++;
        printf("%s: %.1f\n", name, score);
    }
    fclose(fp);

    if (cnt) printf("平均分: %.2f\n", sum / cnt);
    return 0;
}
```

运行输出：

```
Alice: 90.0
Bob: 75.0
Cathy: 88.0
平均分: 84.33
```

---

## 三、两张表总结

**动态内存**

- `malloc(n * sizeof(T))` 借内存 → 判 NULL → 用 → `free` → 置 NULL
- 泄漏 = 只借不还；悬空指针 = 还了还用；重复 free = 灾难

**文件操作**

- `fopen` 判 NULL → 按"文本用 fprintf/fscanf/fgets、二进制用 fwrite/fread"读写 → `fclose`
- 循环条件用读函数返回值，别信 `!feof(fp)`

---

## 四、到 C++ 之后这些会变成什么

| C             | C++ 对应                          | 好处           |
| ------------- | ------------------------------- | ------------ |
| `malloc/free` | `new/delete`、`std::vector`      | 自动管理，几乎不会泄漏  |
| `FILE*` 全家桶   | `std::ifstream`/`std::ofstream` | 构造即打开，析构自动关闭 |

C 里这些手动操作都要自己记，C++ 会替你管——但正因为你在 C 里踩过泄漏和 feof 的坑，到了 C++ 才能真正理解那些"自动管理"到底在替你干什么。

> **自测**（对应上一节说的"链表"自测之外再加一条）：不看资料写出"从文件读入未知个数的学生记录到动态数组，处理后写回另一个文件"。能独立写对，第 6、7 点就算过了，可以正式转 C++。
