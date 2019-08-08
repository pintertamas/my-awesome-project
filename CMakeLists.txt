cmake_minimum_required(VERSION 3.12)
project(farmville2 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
set(SDL2_INCLUDE_DIR C:/MinGW/include/SDL2)
set(SDL2_LIBRARY C:/MinGW/lib)

add_executable(HeadBall ${SOURCE_FILES})
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(HeadBall ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)
