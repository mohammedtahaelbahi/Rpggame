cmake_minimum_required(VERSION 3.10)
project(Rpggame)

set(CMAKE_CXX_STANDARD 17)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Add your executable
add_executable(Rpggame main.cpp
        Src/Player.cpp
        Src/Player.h
        Src/Skeleton.cpp
        Src/Skeleton.h
        Src/Math.cpp
        Src/Math.h
        Src/FrameRate.cpp
        Src/FrameRate.h
        Src/Bullet.cpp
        Src/Bullet.h
        Src/Map.cpp
        Src/Map.h
        Src/Tile.h
        Src/MapLoader.cpp
        Src/MapLoader.h
        Src/MapData.h)

# So #include "Player.h" still works from anywhere
include_directories(Src)

# Link SFML libraries
target_link_libraries(Rpggame sfml-graphics sfml-window sfml-system sfml-audio)