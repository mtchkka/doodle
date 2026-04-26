cmake_minimum_required(VERSION 4.2)
project(Hra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hra operations.cpp
        operations.h
        main.cpp
        player.h
        player.cpp
        village.h
        village.cpp
        monster.h
        monster.cpp
        ggg.cpp)
