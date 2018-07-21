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

add_executable(${MANDA_EXECUTABLE}
        runtime/main.c runtime/runtime.h runtime/print_help.c)
target_link_libraries(${MANDA_EXECUTABLE} ${MANDA_LIBRARY})
set_target_properties(${MANDA_EXECUTABLE} PROPERTIES OUTPUT_NAME ${MANDA_LIBRARY})

install(TARGETS ${MANDA_LIBRARY} ${MANDA_EXECUTABLE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)