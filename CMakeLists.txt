cmake_minimum_required(VERSION 3.10)
project(Rpggame)

set(CMAKE_CXX_STANDARD 17)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Add your executable
add_executable(Rpggame main.cpp
        Player.cpp
        Player.h
        Skeleton.cpp
        Skeleton.h
        Math.cpp
        Math.h
        FrameRate.cpp
        FrameRate.h
        Bullet.cpp
        Bullet.h)

# Link SFML libraries
target_link_libraries(Rpggame sfml-graphics sfml-window sfml-system sfml-audio)
