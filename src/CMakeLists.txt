find_package(FLEX REQUIRED)

FLEX_TARGET(MandaScanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/scanner.hpp)


add_library(manda ${FLEX_MandaScanner_OUTPUTS} parser.cpp parser.h lexer.cpp lexer.h token.cpp token.h)
target_compile_options(manda PUBLIC -Wno-register)
target_include_directories(manda PUBLIC ${CMAKE_CURRENT_BINARY_DIR})