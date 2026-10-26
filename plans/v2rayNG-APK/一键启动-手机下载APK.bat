@echo off
chcp 936 >nul
title 手机下载 v2rayNG - 局域网分发（会自动申请管理员权限）

if /i "%~1"=="admin" goto run

fltmc >nul 2>&1
if %errorlevel% equ 0 goto run

echo.
echo   要用局域网把安装包发给手机，需要先给防火墙加一条放行规则。
echo   正在申请管理员权限，弹出的窗口请点「是」。
echo   （不点的话，手机连得上但会一直转圈打不开）
echo.
powershell -NoProfile -Command "Start-Process -FilePath '%~f0' -ArgumentList 'admin' -Verb RunAs"
exit /b

:run
cd /d "%~dp0share"

echo ============================================================
echo          v2rayNG 安装包 - 局域网分发服务
echo ============================================================
echo.
echo   [1/2] 放行防火墙（入站 TCP 8000）...
netsh advfirewall firewall delete rule name="v2rayNG APK Server" >nul 2>&1
netsh advfirewall firewall add rule name="v2rayNG APK Server" dir=in action=allow protocol=TCP localport=8000 profile=any >nul 2>&1
if %errorlevel% equ 0 (echo          放行成功) else (echo          放行失败，请看窗口末尾的说明)

for /f "tokens=2 delims=:" %%a in ('ipconfig ^| findstr /c:"192.168.137.1"') do set HOTSPOT=1

echo.
echo   [2/2] 服务已启动。现在用手机操作：
echo.
if defined HOTSPOT (
  echo         手机连上热点后，浏览器打开下面这个地址
) else (
  echo         *** 还没检测到 192.168.137.1，说明“移动热点”没开 ***
  echo         请先打开：设置 - 网络和 Internet - 移动热点
  echo         手机连上热点后，浏览器打开下面这个地址
)
echo.
echo             http://192.168.137.1:8000
echo.
echo         或者用手机相机扫这张图片里的二维码：
echo             %~dp0手机扫码下载APK.png
echo.
echo         打开后点页面上的「下载 v2rayNG.apk」即可。
echo.
echo ------------------------------------------------------------
echo   本窗口不要关掉，关掉服务就停止。
echo   想撤销防火墙规则，以管理员身份运行：
echo     netsh advfirewall firewall delete rule name="v2rayNG APK Server"
echo ------------------------------------------------------------
echo.

"C:\Users\fszzc\.workbuddy\binaries\python\versions\3.13.12\python.exe" -m http.server 8000 --bind 0.0.0.0 --directory "%~dp0share"

echo.
echo 服务已停止。按任意键关闭窗口。
pause >nul
