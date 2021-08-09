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
    src/Wall.cpp 
    src/Helper.cpp 
    src/ClientController.cpp
    src/Sensor.cpp
    headers/Sensor.h
    headers/ClientController.h
    headers/Animation.h
    headers/Character.h
    headers/constants.h
    headers/GameObject.h
    headers/Player.h
    headers/Wall.h 
    headers/Helper.h
    resources/maps.txt
    assets/characters/playerM.png
    assets/characters/playerW.png
    assets/characters/aM.png
    assets/characters/aN.png
    assets/characters/bN.png
    assets/characters/bM.png
    assets/characters/cM.png
    assets/characters/cN.png
    assets/Map.png
)



target_link_libraries(gaijinjam sfml-graphics sfml-audio box2d)





