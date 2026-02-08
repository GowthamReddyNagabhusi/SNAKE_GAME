cmake_minimum_required(VERSION 3.11)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib configuration
set(RAYLIB_PATH ${CMAKE_SOURCE_DIR}/raylib)

# Download raylib if not present
if(NOT EXISTS ${RAYLIB_PATH})
    message(STATUS "Raylib not found. Please download raylib and place it in the project directory.")
    message(STATUS "Or use: git clone https://github.com/raysan5/raylib.git")
endif()

# Include raylib
if(EXISTS ${RAYLIB_PATH}/src/raylib.h)
    include_directories(${RAYLIB_PATH}/src)
    # Check if raylib CMakeLists.txt exists
    if(EXISTS ${RAYLIB_PATH}/CMakeLists.txt)
        add_subdirectory(${RAYLIB_PATH})
        target_link_libraries(${PROJECT_NAME} raylib)
    else()
        # If raylib is pre-built, just link it
        message(STATUS "Linking to pre-built raylib")
        if(WIN32)
            link_directories(${RAYLIB_PATH}/lib)
            target_link_libraries(${PROJECT_NAME} raylib)
        else()
            find_library(RAYLIB_LIB raylib PATHS ${RAYLIB_PATH}/lib)
            if(RAYLIB_LIB)
                target_link_libraries(${PROJECT_NAME} ${RAYLIB_LIB})
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
        target_link_libraries(${PROJECT_NAME} raylib)
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

# Platform-specific settings
if(WIN32)
    target_link_libraries(${PROJECT_NAME} winmm)
endif()

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

