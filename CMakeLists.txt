cmake_minimum_required(VERSION 4.0)
project(Progetto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Progetto main.cpp
        Activity.h
        Sport.h
        Register.h
        Register.cpp)
