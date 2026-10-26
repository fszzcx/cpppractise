// 环境回归验证程序
// 用于确认 MSYS2 / WSL 两套编译环境均未受影响
#include <iostream>
#include <cstdio>
#include <climits>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "          Hello, World!" << std::endl;
    std::cout << "========================================" << std::endl;

#if defined(__linux__)
    std::cout << "[环境] Linux (WSL2)" << std::endl;
#elif defined(_WIN32)
    std::cout << "[环境] Windows (MSYS2 / MSVC)" << std::endl;
#else
    std::cout << "[环境] 未知平台" << std::endl;
#endif

#if defined(__clang__)
    std::cout << "[编译器] Clang " << __clang_major__ << "."
              << __clang_minor__ << "." << __clang_patchlevel__ << std::endl;
#elif defined(__GNUC__)
    std::cout << "[编译器] GCC " << __GNUC__ << "."
              << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
#elif defined(_MSC_VER)
    std::cout << "[编译器] MSVC " << _MSC_VER << std::endl;
#endif

    std::cout << "[C++ 标准] " << __cplusplus << std::endl;
    std::cout << "[指针大小] " << sizeof(void*) * 8 << " 位" << std::endl;
    std::cout << "[sizeof(long)] " << sizeof(long) << " 字节" << std::endl;
    std::cout << "[int 最大值] " << INT_MAX << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "编译与运行均正常，环境未受影响。" << std::endl;
    return 0;
}
