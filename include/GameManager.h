#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "InputHandler.h"

enum class GameState {
    MENU,
    PLAYING,
    GAME_OVER
};

class GameManager {
private:
    GameState state;
    Snake snake;
    Food food;
    Renderer renderer;
    int score;
    int highScore;
    float lastUpdateTime;
    float gameSpeed;

public:
    GameManager();
    void Initialize();
    void Update();
    void Render();
    void ProcessInput();
    void ResetGame();
    void UpdateHighScore();
    bool ShouldClose();
    void Cleanup();
};

#endif // GAME_MANAGER_H

