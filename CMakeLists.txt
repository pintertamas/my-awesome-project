cmake_minimum_required(VERSION 3.13)
project(my-awesome-project C)

set(CMAKE_C_STANDARD 99)
set(raylib_INCLUDE_DIR C:/MinGW/include)
set(raylib_LIBRARY C:/MinGW/lib)

add_executable(my-awesome-project main.c game.c game.h ship.c ship.h global.c global.h ball.c ball.h bullet.c bullet.h ship.c ship.h coin.c coin.h menu.c menu.h settings.c settings.h textures.c textures.h buttons.c buttons.h)
include_directories(${raylib_INCLUDE_DIR})
target_link_libraries(my-awesome-project ${raylib_LIBRARY} -lmingw32 -lraylib)