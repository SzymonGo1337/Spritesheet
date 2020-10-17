cmake_minimum_required(VERSION 3.15)
project(Spritesheet)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_BUILD_TYPE Debug)
find_package(SFML 2 COMPONENTS graphics system window audio network REQUIRED)
add_executable(Spritesheet main.cpp)
target_link_libraries(Spritesheet sfml-graphics sfml-system sfml-window sfml-audio sfml-network)