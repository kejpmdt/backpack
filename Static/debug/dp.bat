@echo
:st
build.exe
std.exe
P2168.exe
fc P2168_.out P2168_.ans
if not errorlevel 1 goto st
pause