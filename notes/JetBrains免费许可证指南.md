# JetBrains 免费许可证薅羊毛指南

> 整理日期：2026-10-26
> 适用：大一学生写 C++ / 以后写 Python 等场景

## 一、CLion 非商业免费（2025 年 5 月起）

- **来源**：JetBrains 官方博客 https://blog.jetbrains.com/zh-hans/clion/2025/05/clion-is-now-free-for-non-commercial-use/
- **条件**：从 **v2025.1.1** 起，非商业用途免费，功能与付费版一致（仅 Code With Me 降级为社区版）
- **什么算非商业**：学习自学、写作业、开源贡献、内容创作、业余项目——**写 C++ 练习完全符合**
- **激活步骤**：
  1. 官网 https://www.jetbrains.com/clion/ 下载 2025.1.1 以后的版本
  2. 首次启动选「Free non-commercial use」
  3. 登录/注册 JetBrains 账号激活，许可一年一续
- **续期规则**：一年自动续，前提是订阅期最后 6 个月内至少用过一次；超过 6 个月没用就重新申请一次即可
- **注意**：免费许可会收集匿名 IDE 功能使用统计（不含代码内容），介意需知晓

## 二、学生教育许可证（覆盖全家桶，更香）⭐

- **申请入口**：https://www.jetbrains.com/student/
- **资格**：高校在读学生，用**学校邮箱**（edu 邮箱）或上传在读证明材料申请
- **覆盖范围**：JetBrains 全家桶——CLion、PyCharm Professional、DataGrip、WebStorm、Rider 等，一年一续，在校期间可持续续
- **大一新生就能申请**，没 edu 邮箱可以用学信网/学生证等证明文件走人工审核
- **和 CLion 免费许可的关系**：二选一即可；教育许可证功能更多（全家桶 + 更新更快），能用教育许可就用它

## 三、实操备忘

- [ ] 学信网确认自己学籍信息可查（申请教育许可要用）
- [ ] 用学校邮箱申请：https://www.jetbrains.com/student/
- [ ] 申请通过后，JetBrains Account 里能看到 Educational Pack
- [ ] CLion/PyCharm 激活时选「Activate License」→ 登录 JetBrains 账号 → 选教育许可
- [ ] 每年续期邮件会发到申请邮箱，注意别漏

## 四、相关环境背景（2026-10-26 时的本机情况）

- 主力：Visual Studio 2026（`D:\cpp\vs2026\`）+ VSCode/MSYS2（`D:\cpp\code\`）
- CLion 用 **CMake** 构建体系，和 VS 的 .vcxproj 不同；项目建议放 `D:\cpp\clion\` 下，与 git 仓库（github.com/fszzcx/cpppractise）无缝管理
- CLion 对内存要求较高，电脑配置紧张时优先用现有两套环境
