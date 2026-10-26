# VS Enterprise → Community 换版清单

日期：2026-10-23　当前安装：Visual Studio Enterprise 2026 (18.10.3)，位于 `C:\Program Files\Microsoft Visual Studio\18\Enterprise`

## 一、先给结论：**现在不要删**

正确顺序是 **先装 Community → 验证工程能编译 → 再卸 Enterprise**。反过来的话，一旦 Community 出问题，你会连一个能用的 IDE 都没有。

## 二、已经替你做完的

| 项目 | 结果 |
|---|---|
| 源码备份 | `D:\WorkBuddy\backup\vs2026_backup_2026-10-23.zip`（3.5 MB，含 D:\vs2026 全部内容） |
| 工程位置核查 | 全部工程在 `D:\vs2026`，**C:\Users\fszzc\source\repos 是空的**，卸载不受影响 |
| 扩展核查 | `18.0_052bfce2\Extensions` 为空，**没有需要单独保留的第三方扩展**（Copilot 是安装组件，不是扩展） |
| 组件清单 | 见下方第四节 |

工程清单（共 4 个解决方案、8 个工程）：

- `D:\vs2026\Project1\Project1.slnx`（Project1、Project1_LongLong、Lab2_char、Lab_const、Lab_enum.cpp）
- `D:\vs2026\Project2\Project2.slnx`
- `D:\vs2026\Beginningtest.cpp\Beginningtest.cpp.slnx`
- 配套：`D:\vs2026\.editorconfig`、`D:\vs2026\common.props`（属性表，新工程要挂）

## 三、还需要你自己动手保存的（只有一项）

**IDE 个性化设置**：已导出完成（2026-10-23），实际位置：

```
C:\Users\fszzc\AppData\Local\Microsoft\VisualStudio\18.0_052bfce2\Settings\Exported-2026-10-23.vssettings
```

（287 KB，内容已验证为有效 XML 设置文件；另在 `D:\WorkBuddy\backup\` 留有副本。）恢复方法：Community 里 `工具 → 导入和导出设置向导 → 导入选定设置文件`，指向该文件即可。

这一步能带走：字体字号、缩进/制表符、窗口布局、快捷键、**你之前改过的“关闭快速操作图标”“关闭悬停提示”等选项**、代码片段。不导出的话，Community 里要重新点一遍。

> 注意：该向导**不包含** `.vcxproj` 里的编译选项（如 `/source-charset:utf-8`），但那些写在工程文件里，跟着 D 盘走，不会丢。

## 四、Community 安装时要勾的组件（照这张单子）

**当前 Enterprise 实际装了 7 个工作负荷（104 个包，全部为默认选择，无手动增删）：**

| 工作负荷 | 中文名 | 你需不需要 |
|---|---|---|
| CoreEditor | 核心编辑器 | 必需（基础，不能取消） |
| **NativeDesktop** | **使用 C++ 的桌面开发** | **必勾（主力用途）** |
| NativeCrossPlat | 使用 C++ 的 Linux 和嵌入式开发 | 建议勾（WSL 那套） |
| ManagedDesktop | .NET 桌面开发 | 不需要 |
| Python | Python 开发 | 不需要 |
| Node | Node.js 开发 | 不需要 |
| NetCrossPlat | .NET MAUI 跨平台（移动端） | 不需要 |

**NativeDesktop 工作负荷下的关键组件（勾了工作负荷会自动带）：**

- `VC.Tools.x86.x64` — MSVC v145 编译器工具集
- `VC.CoreIde` — C++ 核心 IDE 功能
- `Windows11SDK.26100` — Windows 11 SDK
- `VC.CMake.Project` + `WebToolsExtensions.CMake` — CMake 支持
- `Vcpkg` — 包管理器
- `VC.ASAN` — 地址消毒剂（内存错误检测）
- `VC.TestAdapterForGoogleTest` / `BoostTest` — C++ 测试适配器
- `VC.ATL`、`VC.Redist.14.Latest`、`VC.DiagnosticTools`、`CppBuildInsights`
- `Component.VisualStudio.GitHub.Copilot` — **Copilot（需单独确认勾上）**

**结论：Community 里只需要勾 2 个框** —— “使用 C++ 的桌面开发”（含上述全部组件）+ 单个组件里的 “GitHub Copilot”（以及可选“适用于 Linux 的 C++ 开发”）。

## 五、换版执行顺序

1. Visual Studio Installer → 选 **Community 2026** → 按第四节勾组件 → 安装（约 5–8 GB）
2. 用 Community 打开 `D:\vs2026\Project1\Project1.slnx`，随便编译一个工程（比如 Lab2_char），确认 **0 错误**
3. 关掉所有 VS，删除 `D:\vs2026\Project1\.vs`（IDE 缓存，两版本共用会冲突；删了自动重建）
4. 确认无误后再卸 Enterprise（命令行方式，需管理员权限）：

```
"C:\Program Files (x86)\Microsoft Visual Studio\Installer\setup.exe" uninstall --installPath "C:\Program Files\Microsoft Visual Studio\18\Enterprise"
```

## 六、风险提示

- 卸载 Enterprise **不会**删除 `D:\vs2026` 下任何文件；
- 但会删除 `C:\Program Files\Microsoft Visual Studio\18\Enterprise` 和部分共享组件，如果 Community 依赖同一版本共享组件，Installer 会自动保留；
- 别手工删 `C:\Program Files\Microsoft Visual Studio` 目录，用 Installer 卸载才干净。
