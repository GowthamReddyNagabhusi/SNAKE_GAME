#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Food::Food() {
    position = Position(GRID_WIDTH / 2, GRID_HEIGHT / 2);
}

void Food::GenerateNew(const Snake& snake) {
    bool validPosition = false;
    int attempts = 0;
    const int maxAttempts = 1000;
    
    while (!validPosition && attempts < maxAttempts) {
        position.x = rand() % GRID_WIDTH;
        position.y = rand() % GRID_HEIGHT;
        
        // Check if position is not on snake
        validPosition = true;
        const std::vector<Position>& snakeBody = snake.GetBody();
        
        for (const auto& segment : snakeBody) {
            if (position == segment) {
                validPosition = false;
                break;
            }
        }
        
        attempts++;
    }
    
    // If we couldn't find a valid position after max attempts, use a default
    if (!validPosition) {
        position = Position(GRID_WIDTH / 2, GRID_HEIGHT / 2);
    }
}

Position Food::GetPosition() const {
    return position;
}

bool Food::CheckCollision(const Position& pos) const {
    return position == pos;
}

