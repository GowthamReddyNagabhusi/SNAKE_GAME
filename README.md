# Snake Game 🐍

A modern, GUI-based Snake game built with C++ and Raylib. Features smooth graphics, responsive controls, and a clean modular architecture.

## Features

- 🎮 **Beautiful GUI**: Modern graphics using Raylib with smooth animations
- 🎯 **Score System**: Track your score and high score
- 🎨 **Visual Grid**: Clean grid-based gameplay with distinct colors
- ⌨️ **Multiple Controls**: Support for both WASD and Arrow keys
- 🔄 **Game States**: Menu, Playing, and Game Over screens
- 🏗️ **Modular Design**: Clean, maintainable code structure

## Requirements

- C++17 or higher
- CMake 3.11 or higher
- Raylib library
- A C++ compiler (GCC, Clang, or MSVC)

## Installation

### Windows

1. **Install Raylib:**
   ```bash
   # Option 1: Clone raylib into project directory
   git clone https://github.com/raysan5/raylib.git
   
   # Option 2: Download precompiled binaries from raylib website
   # https://www.raylib.com/
   ```

2. **Build the project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. **Run the game:**
   ```bash
   .\SnakeGame.exe
   ```

### Linux

1. **Install dependencies:**
   ```bash
   sudo apt-get install libraylib-dev cmake build-essential
   ```

2. **Build the project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the game:**
   ```bash
   ./SnakeGame
   ```

### macOS

1. **Install Raylib:**
   ```bash
   brew install raylib
   ```

2. **Build the project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the game:**
   ```bash
   ./SnakeGame
   ```

## How to Play

- **Movement**: Use `WASD` or `Arrow Keys` to control the snake
- **Objective**: Eat the red food to grow and increase your score
- **Avoid**: Don't hit the walls or your own tail
- **Restart**: Press `SPACE` to restart after game over
- **Quit**: Press `ESC` to exit the game

## Project Structure

```
SNAKE_GAME/
├── include/           # Header files
│   ├── GameConfig.h   # Game constants and configuration
│   ├── Snake.h        # Snake class definition
│   ├── Food.h         # Food class definition
│   ├── Renderer.h     # Rendering system
│   ├── InputHandler.h # Input handling
│   └── GameManager.h  # Main game logic manager
├── src/               # Source files
│   ├── main.cpp       # Entry point
│   ├── Snake.cpp      # Snake implementation
│   ├── Food.cpp       # Food implementation
│   ├── Renderer.cpp   # Rendering implementation
│   ├── InputHandler.cpp # Input implementation
│   └── GameManager.cpp # Game manager implementation
├── CMakeLists.txt     # Build configuration
└── README.md          # This file
```

## Game Mechanics

- **Grid Size**: 20x20 cells
- **Initial Length**: 3 segments
- **Score per Food**: 10 points
- **Game Speed**: Adjustable via `GAME_SPEED` constant in `GameConfig.h`

## Customization

You can customize the game by modifying constants in `include/GameConfig.h`:

- `GRID_WIDTH` / `GRID_HEIGHT`: Change grid dimensions
- `CELL_SIZE`: Adjust cell size (affects window size)
- `GAME_SPEED`: Change game speed (lower = faster)
- `SCORE_PER_FOOD`: Points awarded per food
- Colors in `GameColors` namespace

## Building from Source

### Using CMake (Recommended)

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Manual Compilation

```bash
g++ -std=c++17 src/*.cpp -I include -I raylib/src -L raylib/lib -lraylib -o SnakeGame
```

## Troubleshooting

### Raylib Not Found
- Ensure raylib is cloned into the project directory, or
- Install raylib system-wide
- Update `CMakeLists.txt` with correct raylib path

### Compilation Errors
- Ensure C++17 support is enabled
- Check that all required headers are in the `include/` directory
- Verify raylib is properly installed

### Runtime Issues
- On Windows, ensure required DLLs are in the same directory as the executable
- On Linux, ensure raylib shared libraries are in your library path

## License

This project is open source and available for educational purposes.

## Contributing

Feel free to submit issues, fork the repository, and create pull requests for any improvements.

---

Enjoy playing! 🎮
