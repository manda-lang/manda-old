cmake_minimum_required(VERSION 3.0)
project(manda)
set(CMAKE_CXX_STANDARD 17)

add_executable(manda
        src/parsing/lexer.cc src/parsing/lexer.h
        src/parsing/string_scanner.cc src/parsing/string_scanner.h
        src/parsing/token.cc src/parsing/token.h
        src/parsing/test_it.cpp)