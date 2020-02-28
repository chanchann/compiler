cmake_minimum_required(VERSION 3.13)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 ./include/link.h
        ./include/token.h
        ./src/link.c
        ./src/token.c
        ./src/main.c)