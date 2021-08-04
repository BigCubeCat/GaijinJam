cmake_minimum_required(VERSION 3.20)
project(gaijinjam)

set(CMAKE_CXX_STANDARD 17 c++)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(gaijinjam main.cpp)

target_link_libraries(gaijinjam sfml-graphics sfml-audio box2d)
