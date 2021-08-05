cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17 c++)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(game src/main.cpp
    src/Animation.cpp
    src/Character.cpp 
    src/GameObject.cpp
    src/Player.cpp 
    headers/Animation.h
    headers/Character.h
    headers/constants.h
    headers/GameObject.h
    headers/Player.h
)

target_link_libraries(game sfml-graphics sfml-audio box2d)
