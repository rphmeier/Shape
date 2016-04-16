cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Shape)
add_executable(Shape 
    src/main.cpp src/window.cpp src/graphics/sprite.cpp src/graphics/graphics.cpp
)

find_package(SDL2 REQUIRED)
find_package(glbinding REQUIRED)

set_property(TARGET Shape PROPERTY CXX_STANDARD_REQUIRED 11)
include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(Shape ${SDL2_LIBRARY} "GL" glbinding::glbinding)