cmake_minimum_required(VERSION 3.28)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex2 main.cpp
        Mat.h
        Mat.cpp
        Game.h
        Game.cpp
        Player.h
        Player.cpp)
