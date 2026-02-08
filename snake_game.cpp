#include "raylib.h"
#include <deque>
#include <ctime>
#include <cstdlib>

using namespace std;

// Window settings
const int screenWidth = 800;
const int screenHeight = 600;
const int cellSize = 20;
const int gridWidth = screenWidth / cellSize;
const int gridHeight = screenHeight / cellSize;

// Snake body using deque (demonstrates DSA - Double Ended Queue)
deque<Vector2> snake = {{10, 10}};
Vector2 direction = {1, 0};

// Food
Vector2 food;

// Game state
bool gameOver = false;
int score = 0;
float timer = 0;
float gameSpeed = 0.15f;

// Spawn food randomly (ensures it doesn't spawn on snake)
void SpawnFood() {
    bool validPosition = false;
    int attempts = 0;
    
    while (!validPosition && attempts < 100) {
        food.x = GetRandomValue(0, gridWidth - 1);
        food.y = GetRandomValue(0, gridHeight - 1);
        
        validPosition = true;
        // Check if food spawns on snake
        for (const auto& segment : snake) {
            if (segment.x == food.x && segment.y == food.y) {
                validPosition = false;
                break;
            }
        }
        attempts++;
    }
}

// Update snake movement
void UpdateGame() {
    // Calculate new head position
    Vector2 newHead = {
        snake.front().x + direction.x,
        snake.front().y + direction.y
    };

    // Wall collision detection
    if (newHead.x < 0 || newHead.y < 0 ||
        newHead.x >= gridWidth ||
        newHead.y >= gridHeight) {
        gameOver = true;
        return;
    }

    // Self collision detection (DSA: Linear search through deque)
    for (const auto& segment : snake) {
        if (segment.x == newHead.x && segment.y == newHead.y) {
            gameOver = true;
            return;
        }
    }

    // Add new head to front (DSA: deque push_front operation)
    snake.push_front(newHead);

    // Food collision detection
    if (newHead.x == food.x && newHead.y == food.y) {
        score += 10;
        SpawnFood();
        // Snake grows (don't pop_back when eating)
    } else {
        // Remove tail (DSA: deque pop_back operation)
        snake.pop_back();
    }
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Initialize raylib window
    InitWindow(screenWidth, screenHeight, "Snake Game - C++ DSA Demo");
    SetTargetFPS(60);

    // Initial food spawn
    SpawnFood();

    // Main game loop
    while (!WindowShouldClose()) {
        if (!gameOver) {
            // Input controls with direction validation (prevents reversing into self)
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                if (direction.y != 1) direction = {0, -1};
            }
            if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                if (direction.y != -1) direction = {0, 1};
            }
            if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                if (direction.x != 1) direction = {-1, 0};
            }
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                if (direction.x != -1) direction = {1, 0};
            }

            // Game update timer (controls snake movement speed)
            timer += GetFrameTime();
            if (timer >= gameSpeed) {
                UpdateGame();
                timer = 0;
            }
        } else {
            // Restart game on space press
            if (IsKeyPressed(KEY_SPACE)) {
                gameOver = false;
                score = 0;
                snake.clear();
                snake.push_back({10, 10});
                direction = {1, 0};
                SpawnFood();
                timer = 0;
            }
        }

        // Rendering
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw grid (optional visual aid)
        for (int i = 0; i <= gridWidth; i++) {
            DrawLine(i * cellSize, 0, i * cellSize, screenHeight, DARKGRAY);
        }
        for (int i = 0; i <= gridHeight; i++) {
            DrawLine(0, i * cellSize, screenWidth, i * cellSize, DARKGRAY);
        }

        // Draw snake (DSA: iterate through deque)
        for (size_t i = 0; i < snake.size(); i++) {
            const auto& segment = snake[i];
            Color segmentColor = (i == 0) ? GREEN : DARKGREEN; // Head is brighter
            DrawRectangle(
                segment.x * cellSize + 1,
                segment.y * cellSize + 1,
                cellSize - 2,
                cellSize - 2,
                segmentColor
            );
        }

        // Draw food
        DrawRectangle(
            food.x * cellSize + 1,
            food.y * cellSize + 1,
            cellSize - 2,
            cellSize - 2,
            RED
        );

        // Score display
        DrawText(TextFormat("Score: %d", score), 10, 10, 30, WHITE);
        DrawText(TextFormat("Length: %zu", snake.size()), 10, 45, 20, LIGHTGRAY);

        // Game over screen
        if (gameOver) {
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.7f));
            DrawText("GAME OVER", screenWidth / 2 - 120, screenHeight / 2 - 40, 40, RED);
            DrawText(TextFormat("Final Score: %d", score), screenWidth / 2 - 100, screenHeight / 2, 25, WHITE);
            DrawText("Press SPACE to restart", screenWidth / 2 - 140, screenHeight / 2 + 40, 20, YELLOW);
            DrawText("Press ESC to exit", screenWidth / 2 - 100, screenHeight / 2 + 70, 20, LIGHTGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

