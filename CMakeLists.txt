cmake_minimum_required(VERSION 3.20)
project(gaijinjam)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(gaijinjam src/main.cpp
    src/Animation.cpp
    src/Character.cpp
    src/Client.cpp
    src/GameObject.cpp
    src/Player.cpp
    src/Wall.cpp
    headers/Animation.h
    headers/Character.h
    headers/constants.h
    headers/GameObject.h
    headers/Player.h
        src/Wall.cpp headers/Wall.h src/Helper.cpp headers/Helper.h)

target_link_libraries(gaijinjam sfml-graphics sfml-audio box2d)





