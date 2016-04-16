cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(Shape)
add_executable(Shape src/main.cpp src/window.cpp)

find_package(SDL2 REQUIRED)

set_property(TARGET Shape PROPERTY CXX_STANDARD_REQUIRED 11)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(Shape ${SDL2_LIBRARY})