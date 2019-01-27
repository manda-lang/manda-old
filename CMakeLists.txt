cmake_minimum_required(VERSION 3.0)
project(manda)
set(CMAKE_CXX_STANDARD 11)

find_package(BISON)
find_package(FLEX)

bison_target(MandaParser src/parsing/manda_parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(MandaLexer src/parsing/manda_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_flex_bison_dependency(MandaLexer MandaParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(manda
        ${BISON_MandaParser_OUTPUTS}
        ${FLEX_MandaLexer_OUTPUTS} src/parsing/parsing.cpp src/parsing/parsing.h src/parsing/test_it.cpp)