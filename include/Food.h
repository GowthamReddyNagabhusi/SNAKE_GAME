#ifndef FOOD_H
#define FOOD_H

#include "Snake.h"

class Food {
private:
    Position position;

public:
    Food();
    void GenerateNew(const Snake& snake);
    Position GetPosition() const;
    bool CheckCollision(const Position& pos) const;
};

#endif // FOOD_H

