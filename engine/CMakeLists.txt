cmake_minimum_required(VERSION 3.9)
project(engine)

set(CMAKE_CXX_STANDARD 11)

add_executable(engine
        objects/Airport.cpp
        objects/Airport.h
        objects/Route.h
        objects/Route.cpp
        engine.cpp
        engine.h
        main.cpp)
