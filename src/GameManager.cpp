#include "GameManager.h"
#include "GameConfig.h"
#include "raylib.h"
#include <cstdlib>
#include <ctime>

GameManager::GameManager() 
    : state(GameState::MENU), score(0), highScore(0), 
      lastUpdateTime(0.0f), gameSpeed(GAME_SPEED) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void GameManager::Initialize() {
    renderer.Initialize();
    ResetGame();
}

void GameManager::Update() {
    if (state == GameState::PLAYING) {
        float currentTime = GetTime();
        
        // Update game at fixed intervals
        if (currentTime - lastUpdateTime >= gameSpeed) {
            // Process input for direction change
            Direction inputDir = InputHandler::GetDirection();
            if (inputDir != Direction::NONE) {
                snake.ChangeDirection(inputDir);
            }
            
            // Update snake
            snake.Update();
            
            // Check collisions
            if (snake.CheckCollision() || snake.CheckSelfCollision()) {
                state = GameState::GAME_OVER;
                UpdateHighScore();
            }
            
            // Check food collision
            if (snake.GetHead() == food.GetPosition()) {
                snake.Grow();
                score += SCORE_PER_FOOD;
                food.GenerateNew(snake);
            }
            
            lastUpdateTime = currentTime;
        }
    }
}

void GameManager::Render() {
    renderer.BeginDrawing();
    
    switch (state) {
        case GameState::MENU:
            renderer.DrawStartScreen();
            break;
            
        case GameState::PLAYING:
            renderer.DrawGrid();
            renderer.DrawSnake(snake);
            renderer.DrawFood(food);
            renderer.DrawUI(score, highScore);
            break;
            
        case GameState::GAME_OVER:
            renderer.DrawGrid();
            renderer.DrawSnake(snake);
            renderer.DrawFood(food);
            renderer.DrawUI(score, highScore);
            renderer.DrawGameOver(score);
            break;
    }
    
    renderer.EndDrawing();
}

void GameManager::ProcessInput() {
    if (InputHandler::IsQuitPressed()) {
        return;
    }
    
    switch (state) {
        case GameState::MENU:
            if (InputHandler::IsStartPressed()) {
                state = GameState::PLAYING;
                ResetGame();
            }
            break;
            
        case GameState::PLAYING:
            // Input handled in Update() for direction changes
            break;
            
        case GameState::GAME_OVER:
            if (InputHandler::IsRestartPressed()) {
                state = GameState::PLAYING;
                ResetGame();
            }
            break;
    }
}

void GameManager::ResetGame() {
    score = 0;
    snake.Initialize(GRID_WIDTH / 2, GRID_HEIGHT / 2);
    food.GenerateNew(snake);
    lastUpdateTime = GetTime();
}

void GameManager::UpdateHighScore() {
    if (score > highScore) {
        highScore = score;
    }
}

bool GameManager::ShouldClose() {
    return renderer.ShouldClose() || InputHandler::IsQuitPressed();
}

void GameManager::Cleanup() {
    renderer.Close();
}

