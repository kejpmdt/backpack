@echo off
::设置要永久加入到path环境变量中的路径
::要以管理员权限运行
set My_PATH=E:\TDM-GCC10.3.0\bin;E:\TDM-GCC10.3.0\gdb64\bin;C:\Program Files (x86)\Dev-Cpp\MinGW64\bin;E:\Vim\vim82;
 
set PATH=%PATH%;%My_PATH%
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v "Path" /t REG_EXPAND_SZ /d "%PATH%" /f
exit