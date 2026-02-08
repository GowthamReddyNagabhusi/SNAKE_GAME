#include "Renderer.h"
#include "GameConfig.h"
#include <string>

Renderer::Renderer() {
    offsetX = 10;
    offsetY = 10;
}

void Renderer::Initialize() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game");
    SetTargetFPS(60);
}

void Renderer::BeginDrawing() {
    ::BeginDrawing();
    ClearBackground(GameColors::BACKGROUND);
}

void Renderer::EndDrawing() {
    ::EndDrawing();
}

void Renderer::DrawGrid() {
    // Draw grid lines
    for (int i = 0; i <= GRID_WIDTH; i++) {
        int x = offsetX + i * CELL_SIZE;
        DrawLine(x, offsetY, x, offsetY + GRID_HEIGHT * CELL_SIZE, GameColors::GRID_LINES);
    }
    
    for (int i = 0; i <= GRID_HEIGHT; i++) {
        int y = offsetY + i * CELL_SIZE;
        DrawLine(offsetX, y, offsetX + GRID_WIDTH * CELL_SIZE, y, GameColors::GRID_LINES);
    }
    
    // Draw border
    Rectangle border = {
        static_cast<float>(offsetX - 2),
        static_cast<float>(offsetY - 2),
        static_cast<float>(GRID_WIDTH * CELL_SIZE + 4),
        static_cast<float>(GRID_HEIGHT * CELL_SIZE + 4)
    };
    DrawRectangleLinesEx(border, 2.0f, GameColors::BORDER);
}

void Renderer::DrawSnake(const Snake& snake) {
    const std::vector<Position>& body = snake.GetBody();
    
    if (body.empty()) return;
    
    // Draw head
    Position head = body[0];
    Rectangle headRect = {
        static_cast<float>(offsetX + head.x * CELL_SIZE + 2),
        static_cast<float>(offsetY + head.y * CELL_SIZE + 2),
        static_cast<float>(CELL_SIZE - 4),
        static_cast<float>(CELL_SIZE - 4)
    };
    DrawRectangleRounded(headRect, 0.3f, 8, GameColors::SNAKE_HEAD);
    
    // Draw body
    for (size_t i = 1; i < body.size(); i++) {
        Rectangle bodyRect = {
            static_cast<float>(offsetX + body[i].x * CELL_SIZE + 2),
            static_cast<float>(offsetY + body[i].y * CELL_SIZE + 2),
            static_cast<float>(CELL_SIZE - 4),
            static_cast<float>(CELL_SIZE - 4)
        };
        DrawRectangleRounded(bodyRect, 0.2f, 6, GameColors::SNAKE_BODY);
    }
}

void Renderer::DrawFood(const Food& food) {
    Position pos = food.GetPosition();
    float centerX = offsetX + pos.x * CELL_SIZE + CELL_SIZE / 2.0f;
    float centerY = offsetY + pos.y * CELL_SIZE + CELL_SIZE / 2.0f;
    float radius = CELL_SIZE / 2.5f;
    
    DrawCircle(centerX, centerY, radius, GameColors::FOOD);
    DrawCircle(centerX, centerY, radius - 2, YELLOW);
}

void Renderer::DrawUI(int score, int highScore) {
    int uiX = offsetX + GRID_WIDTH * CELL_SIZE + 20;
    int uiY = offsetY + 20;
    
    // Draw score
    std::string scoreText = "Score: " + std::to_string(score);
    DrawText(scoreText.c_str(), uiX, uiY, 24, GameColors::TEXT);
    
    // Draw high score
    std::string highScoreText = "High: " + std::to_string(highScore);
    DrawText(highScoreText.c_str(), uiX, uiY + 40, 20, GameColors::TEXT);
    
    // Draw instructions
    DrawText("Controls:", uiX, uiY + 100, 18, GameColors::TEXT);
    DrawText("WASD / Arrows", uiX, uiY + 125, 16, LIGHTGRAY);
    DrawText("ESC - Quit", uiX, uiY + 150, 16, LIGHTGRAY);
}

void Renderer::DrawGameOver(int score) {
    int centerX = WINDOW_WIDTH / 2;
    int centerY = WINDOW_HEIGHT / 2;
    
    std::string gameOverText = "GAME OVER";
    std::string scoreText = "Score: " + std::to_string(score);
    std::string restartText = "Press SPACE to restart";
    
    int gameOverWidth = MeasureText(gameOverText.c_str(), 48);
    int scoreWidth = MeasureText(scoreText.c_str(), 32);
    int restartWidth = MeasureText(restartText.c_str(), 24);
    
    DrawText(gameOverText.c_str(), centerX - gameOverWidth / 2, centerY - 80, 48, RED);
    DrawText(scoreText.c_str(), centerX - scoreWidth / 2, centerY - 20, 32, GameColors::TEXT);
    DrawText(restartText.c_str(), centerX - restartWidth / 2, centerY + 40, 24, LIGHTGRAY);
}

void Renderer::DrawStartScreen() {
    int centerX = WINDOW_WIDTH / 2;
    int centerY = WINDOW_HEIGHT / 2;
    
    std::string titleText = "SNAKE GAME";
    std::string startText = "Press SPACE to start";
    
    int titleWidth = MeasureText(titleText.c_str(), 48);
    int startWidth = MeasureText(startText.c_str(), 24);
    
    DrawText(titleText.c_str(), centerX - titleWidth / 2, centerY - 40, 48, GameColors::SNAKE_HEAD);
    DrawText(startText.c_str(), centerX - startWidth / 2, centerY + 40, 24, LIGHTGRAY);
}

void Renderer::Close() {
    CloseWindow();
}

bool Renderer::ShouldClose() {
    return WindowShouldClose();
}

