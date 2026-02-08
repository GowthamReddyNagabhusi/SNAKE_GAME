#include "InputHandler.h"
#include "raylib.h"

Direction InputHandler::GetDirection() {
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
        return Direction::UP;
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        return Direction::DOWN;
    }
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
        return Direction::LEFT;
    }
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
        return Direction::RIGHT;
    }
    return Direction::NONE;
}

bool InputHandler::IsRestartPressed() {
    return IsKeyPressed(KEY_SPACE);
}

bool InputHandler::IsStartPressed() {
    return IsKeyPressed(KEY_SPACE);
}

bool InputHandler::IsQuitPressed() {
    return IsKeyPressed(KEY_ESCAPE);
}

