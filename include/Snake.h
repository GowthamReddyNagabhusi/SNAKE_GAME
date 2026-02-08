#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "GameConfig.h"

struct Position {
    int x;
    int y;
    
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

class Snake {
private:
    std::vector<Position> body;
    Direction direction;
    Direction nextDirection;
    bool shouldGrow;

public:
    Snake();
    void Initialize(int startX, int startY);
    void Update();
    void ChangeDirection(Direction newDir);
    void Grow();
    bool CheckCollision() const;
    bool CheckSelfCollision() const;
    
    Position GetHead() const;
    const std::vector<Position>& GetBody() const;
    int GetLength() const;
    bool ShouldGrow() const { return shouldGrow; }
    void ResetGrow() { shouldGrow = false; }
};

#endif // SNAKE_H

