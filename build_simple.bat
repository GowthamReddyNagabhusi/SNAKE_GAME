@echo off
echo Building Simple Snake Game (C++ DSA Demo)...
echo.

g++ -std=c++17 snake_game.cpp -o snake_game.exe -I C:\raylib\include -L C:\raylib\lib -lraylib -lwinmm -lgdi32 -lopengl32

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Run snake_game.exe to play.
    echo.
    echo DSA Concepts Demonstrated:
    echo - deque (Double Ended Queue) for snake body
    echo - Linear search for collision detection
    echo - push_front/pop_back operations
) else (
    echo.
    echo Build failed! Check the errors above.
    pause
)

