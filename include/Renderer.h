#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include "Snake.h"
#include "Food.h"
#include <string>

class Renderer {
private:
    int offsetX;
    int offsetY;

public:
    Renderer();
    void Initialize();
    void BeginDrawing();
    void EndDrawing();
    void DrawGrid();
    void DrawSnake(const Snake& snake);
    void DrawFood(const Food& food);
    void DrawUI(int score, int highScore);
    void DrawGameOver(int score);
    void DrawStartScreen();
    void Close();
    bool ShouldClose();
};

#endif // RENDERER_H

