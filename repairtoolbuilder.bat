@echo off
g++ src\commands.cpp src\security.cpp src\input.cpp src\display.cpp src\command_rgstry.cpp src\main.cpp src\log.cpp -Iinclude -o RepairKit
echo Build complete.
pause