cmake_minimum_required(VERSION 3.14)
project(targil2 C)

set(CMAKE_C_STANDARD 99)

add_executable(targil2 main.c books.h books.c local_library.c local_library.h)