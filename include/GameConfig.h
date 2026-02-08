#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include "raylib.h"

// Game constants
const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;
const int CELL_SIZE = 30;
const int WINDOW_WIDTH = GRID_WIDTH * CELL_SIZE + 200;  // Extra space for UI
const int WINDOW_HEIGHT = GRID_HEIGHT * CELL_SIZE + 100;
const int INITIAL_SNAKE_LENGTH = 3;
const int SCORE_PER_FOOD = 10;
const float GAME_SPEED = 0.15f;  // Seconds per move

// Direction enum
enum class Direction {
    NONE = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Colors (using raylib colors)
namespace GameColors {
    const Color BACKGROUND = DARKGREEN;
    const Color GRID_LINES = GREEN;
    const Color SNAKE_HEAD = YELLOW;
    const Color SNAKE_BODY = LIME;
    const Color FOOD = RED;
    const Color TEXT = WHITE;
    const Color BORDER = DARKGRAY;
}

#endif // GAME_CONFIG_H

