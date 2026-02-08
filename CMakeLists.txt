cmake_minimum_required(VERSION 3.11)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib configuration
# Try system installation first (C:\raylib on Windows)
if(WIN32 AND EXISTS "C:/raylib/include/raylib.h")
    set(RAYLIB_PATH "C:/raylib")
    message(STATUS "Using system raylib at: ${RAYLIB_PATH}")
else()
    set(RAYLIB_PATH ${CMAKE_SOURCE_DIR}/raylib)
    if(NOT EXISTS ${RAYLIB_PATH})
        message(STATUS "Raylib not found. Please download raylib and place it in the project directory.")
        message(STATUS "Or use: git clone https://github.com/raysan5/raylib.git")
    endif()
endif()

# Store raylib linking info for later
set(RAYLIB_LINK_LIBS "")

# Include raylib
if(EXISTS ${RAYLIB_PATH}/include/raylib.h)
    # System installation (C:\raylib style)
    include_directories(${RAYLIB_PATH}/include)
    link_directories(${RAYLIB_PATH}/lib)
    set(RAYLIB_LINK_LIBS raylib)
    message(STATUS "Using raylib from: ${RAYLIB_PATH}")
elseif(EXISTS ${RAYLIB_PATH}/src/raylib.h)
    # Source tree installation
    include_directories(${RAYLIB_PATH}/src)
    # Check if raylib CMakeLists.txt exists
    if(EXISTS ${RAYLIB_PATH}/CMakeLists.txt)
        add_subdirectory(${RAYLIB_PATH})
        set(RAYLIB_LINK_LIBS raylib)
    else()
        # If raylib is pre-built, just link it
        message(STATUS "Linking to pre-built raylib")
        if(WIN32)
            link_directories(${RAYLIB_PATH}/lib)
            set(RAYLIB_LINK_LIBS raylib)
        else()
            find_library(RAYLIB_LIB raylib PATHS ${RAYLIB_PATH}/lib)
            if(RAYLIB_LIB)
                set(RAYLIB_LINK_LIBS ${RAYLIB_LIB})
            endif()
        endif()
    endif()
else()
    # Try to find raylib via pkg-config or system install
    find_package(raylib QUIET)
    if(NOT raylib_FOUND)
        message(FATAL_ERROR "Raylib not found. Please install raylib or clone it into the project directory.")
        message(FATAL_ERROR "Clone with: git clone https://github.com/raysan5/raylib.git")
    else()
        set(RAYLIB_LINK_LIBS raylib)
    endif()
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/Snake.cpp
    src/Food.cpp
    src/Renderer.cpp
    src/InputHandler.cpp
    src/GameManager.cpp
)

# Header files
set(HEADERS
    include/GameConfig.h
    include/Snake.h
    include/Food.h
    include/Renderer.h
    include/InputHandler.h
    include/GameManager.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link raylib
if(RAYLIB_LINK_LIBS)
    target_link_libraries(${PROJECT_NAME} ${RAYLIB_LINK_LIBS})
endif()

# Platform-specific settings
if(WIN32)
    target_link_libraries(${PROJECT_NAME} winmm gdi32 opengl32)
endif()

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

