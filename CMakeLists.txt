cmake_minimum_required(VERSION 3.20)
project(gaijinjam)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories("assets")

add_executable(gaijinjam src/main.cpp
    src/Animation.cpp
    src/Character.cpp
    src/Client.cpp
    src/GameObject.cpp
    src/Player.cpp
    src/Wall.cpp
    src/Wall.cpp 
    src/Helper.cpp 
    src/ClientController.cpp
    src/Sensor.cpp
    src/Slider.cpp
    src/Game.cpp
    headers/Game.h
    headers/Slider.h
    headers/Sensor.h
    headers/ClientController.h
    headers/Client.h
    headers/Animation.h
    headers/Character.h
    headers/constants.h
    headers/GameObject.h
    headers/Player.h
    headers/Wall.h 
    headers/Helper.h
    resources/maps.txt
    src/FPS.cpp
        headers/FPS.h
        assets/floor.png
        assets/Map.png
        )



target_link_libraries(gaijinjam sfml-graphics sfml-audio box2d)





