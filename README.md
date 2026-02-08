# Snake Game 🐍 - C++ DSA Demonstration

A simple, elegant Snake game implementation in C++ using Raylib, designed to demonstrate core C++ programming and Data Structures & Algorithms (DSA) concepts. Perfect for coding interviews and portfolio projects.

## 🎯 Project Purpose

This project showcases:
- **C++ Fundamentals**: Object-oriented concepts, STL containers, memory management
- **Data Structures**: `deque` (Double Ended Queue) for efficient snake body management
- **Algorithms**: Collision detection, linear search, game loop logic
- **GUI Programming**: Raylib integration for graphics and input handling

## ✨ Features

- 🎮 **Simple & Clean**: Single-file implementation (~150 lines)
- 📚 **DSA Concepts**: Demonstrates `deque`, linear search, collision detection
- 🎨 **Modern GUI**: Beautiful graphics using Raylib
- ⌨️ **Responsive Controls**: WASD and Arrow key support
- 🎯 **Score Tracking**: Real-time score and length display
- 🔄 **Game States**: Start, play, game over with restart functionality

## 🛠️ Requirements

- **C++17** or higher
- **Raylib** library (installed at `C:\raylib` on Windows)
- **G++ compiler** (MinGW/MSYS2) or any C++ compiler

## 🚀 Quick Start

### Windows (Simple Build)

1. **Ensure Raylib is installed at `C:\raylib`**
   - Download from: https://www.raylib.com/
   - Or clone: `git clone https://github.com/raysan5/raylib.git C:\raylib`

2. **Build the game:**
   ```bash
   .\build_simple.bat
   ```

3. **Run the game:**
   ```bash
   .\snake_game.exe
   ```

### Manual Compilation

```bash
g++ -std=c++17 snake_game.cpp -o snake_game.exe -I C:\raylib\include -L C:\raylib\lib -lraylib -lwinmm -lgdi32 -lopengl32
```

### Linux/macOS

```bash
g++ -std=c++17 snake_game.cpp -o snake_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

## 🎮 How to Play

- **Movement**: `WASD` or `Arrow Keys` to control the snake
- **Objective**: Eat red food to grow and score points
- **Avoid**: Don't hit walls or your own tail
- **Restart**: Press `SPACE` after game over
- **Quit**: Press `ESC` to exit

## 📚 DSA Concepts Demonstrated

### 1. **Deque (Double Ended Queue)**
```cpp
deque<Vector2> snake;  // Efficient insertion/removal at both ends
snake.push_front(newHead);  // O(1) - Add head
snake.pop_back();           // O(1) - Remove tail
```
- **Why deque?**: Perfect for snake body - need to add at front (head) and remove from back (tail)
- **Time Complexity**: O(1) for both operations
- **Space Complexity**: O(n) where n is snake length

### 2. **Linear Search Algorithm**
```cpp
// Self-collision detection
for (const auto& segment : snake) {
    if (segment.x == newHead.x && segment.y == newHead.y) {
        gameOver = true;
    }
}
```
- **Time Complexity**: O(n) where n is snake length
- **Use Case**: Checking if new head position collides with body

### 3. **Collision Detection**
- **Wall Collision**: Boundary checking (O(1))
- **Food Collision**: Position comparison (O(1))
- **Self Collision**: Linear search through body (O(n))

### 4. **Game Loop Pattern**
```cpp
while (!WindowShouldClose()) {
    ProcessInput();
    UpdateGame();
    Render();
}
```
- Classic game development pattern
- Separates input, logic, and rendering

## 📁 Project Structure

```
SNAKE_GAME/
├── snake_game.cpp      # Main game file (single file implementation)
├── build_simple.bat    # Windows build script
├── README.md           # This file
└── (legacy files)      # Previous modular version
```

## 🔍 Code Highlights

### Key C++ Features Used:
- **STL Containers**: `deque`, `vector` concepts
- **Namespaces**: `std` namespace usage
- **Constants**: `const` for immutability
- **References**: `const auto&` for efficient iteration
- **Function Organization**: Modular functions for clarity

### Algorithm Complexity:
- **Snake Movement**: O(1) - deque operations
- **Collision Detection**: O(n) - linear search
- **Food Spawning**: O(n) worst case - ensures valid position
- **Overall Game Loop**: O(n) per frame where n = snake length

## 🎓 Learning Outcomes

This project demonstrates:
1. ✅ Understanding of STL containers (`deque`)
2. ✅ Algorithm implementation (search, collision detection)
3. ✅ Time/space complexity awareness
4. ✅ Clean, readable code structure
5. ✅ Game development fundamentals
6. ✅ C++ best practices

## 🐛 Troubleshooting

### Raylib Not Found
- Ensure raylib is at `C:\raylib` (Windows)
- Update include/library paths in build command
- Check raylib installation: https://www.raylib.com/

### Compilation Errors
- Verify C++17 support: `g++ --version`
- Check raylib paths are correct
- Ensure all required libraries are linked

### Runtime Issues
- Missing DLLs: Copy raylib DLLs to executable directory
- Window doesn't open: Check graphics drivers

## 📝 Notes for Interviews

When discussing this project, highlight:
- **Why deque?**: Explain O(1) operations for snake body management
- **Collision Detection**: Discuss trade-offs between different approaches
- **Code Organization**: Single file vs modular design trade-offs
- **Performance**: O(n) collision check is acceptable for this use case
- **Extensibility**: How you'd add features (power-ups, levels, etc.)

## 🔄 Future Enhancements (Optional)

- High score persistence
- Multiple difficulty levels
- Power-ups and obstacles
- Multiplayer support
- Sound effects

## 📄 License

This project is open source and available for educational purposes.

---

**Perfect for**: Coding interviews, portfolio projects, C++ learning, DSA practice

Enjoy coding! 🚀
