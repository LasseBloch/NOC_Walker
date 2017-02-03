cmake_minimum_required(VERSION 3.6)
project(Walker)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})



set(SOURCE_FILES main.cpp Game.cpp Game.h walker.cpp walker.h)
add_executable(Walker ${SOURCE_FILES})
target_link_libraries(Walker ${SDL2_LIBRARY})

