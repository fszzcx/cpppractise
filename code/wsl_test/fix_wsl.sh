#!/bin/bash
# WSL2 VSCode C++ 环境修复脚本
set -e

EXT="$HOME/.vscode-server/extensions/ms-vscode.cpptools-1.34.4-linux-x64"

echo "=== 1. 检查扩展目录 ==="
if [ ! -d "$EXT" ]; then
    echo "错误：扩展目录不存在，请先把 cpptools 装进去"
    exit 1
fi
echo "找到: $EXT"

echo ""
echo "=== 2. 修复所有可执行文件权限 ==="
find "$EXT/debugAdapters" -type f -exec chmod +x {} \; 2>/dev/null || true
find "$EXT/bin" -type f -exec chmod +x {} \; 2>/dev/null || true
find "$EXT/LLVM" -type f -exec chmod +x {} \; 2>/dev/null || true
chmod +x "$EXT/debugAdapters/bin/OpenDebugAD7" 2>/dev/null || true
echo "已处理"

echo ""
echo "=== 3. 关键文件权限确认 ==="
ls -la "$EXT/debugAdapters/bin/OpenDebugAD7"
ls -la "$EXT/bin/cpptools" 2>/dev/null | head -1

echo ""
echo "=== 4. 修复 vscode-server node ==="
chmod +x "$HOME/.vscode-server/bin/"*/node 2>/dev/null || true
ls -la "$HOME/.vscode-server/bin/"*/node 2>/dev/null | head -3

echo ""
echo "=== 5. 验证调试器能否启动 ==="
"$EXT/debugAdapters/bin/OpenDebugAD7" --version 2>&1 | head -3 || echo "(--version 不被支持，属正常)"

echo ""
echo "===== 完成！回到 VSCode 按 Ctrl+Shift+P -> reload ====="
