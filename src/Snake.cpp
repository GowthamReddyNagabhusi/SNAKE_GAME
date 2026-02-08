#include "Snake.h"
#include <algorithm>

Snake::Snake() : direction(Direction::NONE), nextDirection(Direction::NONE), shouldGrow(false) {
    body.clear();
}

void Snake::Initialize(int startX, int startY) {
    body.clear();
    direction = Direction::NONE;
    nextDirection = Direction::NONE;
    shouldGrow = false;
    
    // Initialize snake with initial length
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        body.push_back(Position(startX - i, startY));
    }
}

void Snake::Update() {
    // Update direction
    if (nextDirection != Direction::NONE) {
        // Prevent reversing into itself
        bool canChange = true;
        if ((direction == Direction::UP && nextDirection == Direction::DOWN) ||
            (direction == Direction::DOWN && nextDirection == Direction::UP) ||
            (direction == Direction::LEFT && nextDirection == Direction::RIGHT) ||
            (direction == Direction::RIGHT && nextDirection == Direction::LEFT)) {
            canChange = false;
        }
        
        if (canChange) {
            direction = nextDirection;
        }
    }
    
    if (direction == Direction::NONE) {
        return;
    }
    
    // Calculate new head position
    Position newHead = body[0];
    
    switch (direction) {
        case Direction::UP:
            newHead.y--;
            break;
        case Direction::DOWN:
            newHead.y++;
            break;
        case Direction::LEFT:
            newHead.x--;
            break;
        case Direction::RIGHT:
            newHead.x++;
            break;
        default:
            break;
    }
    
    // Add new head
    body.insert(body.begin(), newHead);
    
    // Remove tail if not growing
    if (!shouldGrow) {
        body.pop_back();
    } else {
        shouldGrow = false;
    }
}

void Snake::ChangeDirection(Direction newDir) {
    if (newDir != Direction::NONE) {
        nextDirection = newDir;
    }
}

void Snake::Grow() {
    shouldGrow = true;
}

bool Snake::CheckCollision() const {
    Position head = GetHead();
    
    // Check wall collision
    if (head.x < 0 || head.x >= GRID_WIDTH || 
        head.y < 0 || head.y >= GRID_HEIGHT) {
        return true;
    }
    
    return false;
}

bool Snake::CheckSelfCollision() const {
    Position head = GetHead();
    
    // Check if head collides with body (skip first element as it's the head)
    for (size_t i = 1; i < body.size(); i++) {
        if (head == body[i]) {
            return true;
        }
    }
    
    return false;
}

Position Snake::GetHead() const {
    if (body.empty()) {
        return Position(0, 0);
    }
    return body[0];
}

const std::vector<Position>& Snake::GetBody() const {
    return body;
}

int Snake::GetLength() const {
    return static_cast<int>(body.size());
}

