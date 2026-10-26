// WSL 环境验证程序：确认 Linux 侧编译与调试链路是否打通
#include <iostream>
#include <cstdio>
#include <unistd.h>

int main()
{
    std::cout << "=== WSL / Linux 环境验证 ===" << std::endl;

#ifdef __linux__
    std::cout << "[OK] 当前编译目标: Linux" << std::endl;
#else
    std::cout << "[!!] 当前编译目标: 非 Linux（说明用错编译器了）" << std::endl;
#endif

    std::cout << "编译器: ";
    std::fflush(stdout);
    std::system("g++ --version | head -1");

    std::cout << "内核: ";
    std::fflush(stdout);
    std::system("uname -r");

    std::cout << "用户: ";
    std::fflush(stdout);
    std::system("whoami");

    std::cout << "当前目录: ";
    std::fflush(stdout);
    std::system("pwd");

    std::cout << "os << 大小: " << sizeof(long) << " 字节（Linux x64 应为 8）" << std::endl;

    int counter = 0;
    for (int i = 1; i <= 3; ++i) {
        counter += i * 10;
        std::cout << "循环第 " << i << " 次，计数器 = " << counter << std::endl;
    }

    std::cout << "=== 全部完成 ===" << std::endl;
    return 0;
}
