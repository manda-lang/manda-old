find_package(BISON)
find_package(FLEX)

BISON_TARGET(MandaParser manda_parser.y ${CMAKE_CURRENT_BINARY_DIR}/manda_parser.c)
FLEX_TARGET(MandaLexer manda_parser.l ${CMAKE_CURRENT_BINARY_DIR}/manda_lexer.c)
ADD_FLEX_BISON_DEPENDENCY(MandaLexer MandaParser)

add_library(${MANDA_LIBRARY}
    ${BISON_MandaParser_OUTPUTS}
    ${BISON_MandaLexer_OUTPUTS}
        text/ast.c)
target_include_directories(${MANDA_LIBRARY} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})