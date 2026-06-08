cmake_minimum_required(VERSION 4.2)
project(Hra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hra
        main.cpp
        player.h
        player.cpp
        village.h
        village.cpp
        monster.h
        monster.cpp
        wandering.h
        wandering.cpp
        fight.h
        fight.cpp
)
