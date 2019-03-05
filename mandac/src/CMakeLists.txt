find_package(FLEX REQUIRED)
flex_target(MandaFlex lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
        COMPILE_FLAGS -Pmanda_flex_
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/lexer.hpp)
add_executable(mandac ${FLEX_MandaFlex_OUTPUTS}
        scanner.cpp scanner.hpp token.cpp token.hpp main.cpp)
target_include_directories(mandac PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})