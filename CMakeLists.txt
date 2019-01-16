cmake_minimum_required(VERSION 3.0)
project(manda)
set(CMAKE_CXX_STANDARD 17)

add_executable(manda
        src/parsing/string_scanner.cc src/parsing/string_scanner.h)