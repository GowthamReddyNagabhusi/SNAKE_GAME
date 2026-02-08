@echo off
echo Building Snake Game...
echo.

g++ -std=c++17 -I include -I C:\raylib\include src\*.cpp -o SnakeGame.exe -L C:\raylib\lib -lraylib -lwinmm -lgdi32 -lopengl32

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Run SnakeGame.exe to play.
) else (
    echo.
    echo Build failed! Check the errors above.
    pause
)

