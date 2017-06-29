cmake_minimum_required(VERSION 3.8)
project(stu)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sort.c hh.c)
add_executable(stu ${SOURCE_FILES})