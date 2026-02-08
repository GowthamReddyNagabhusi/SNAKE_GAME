#include "GameManager.h"

int main() {
    GameManager game;
    game.Initialize();
    
    // Main game loop
    while (!game.ShouldClose()) {
        game.ProcessInput();
        game.Update();
        game.Render();
    }
    
    game.Cleanup();
    return 0;
}

