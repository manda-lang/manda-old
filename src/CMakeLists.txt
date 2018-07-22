include(ExternalProject)
find_package(Readline)

add_library(${MANDA_LIBRARY}
        manda_text/MandaBaseVisitor.cpp
        manda_text/MandaBaseVisitor.h
        manda_text/MandaLexer.cpp
        manda_text/MandaLexer.h
        manda_text/MandaParser.cpp
        manda_text/MandaParser.h
        manda_text/MandaVisitor.cpp
        manda_text/MandaVisitor.h manda_text/manda_text.h
        vm/Memory.cpp vm/Memory.h
        vm/VM.cpp vm/VM.h
        vm/Fiber.cpp vm/Fiber.h
        vm/Interpreter.cpp vm/Interpreter.h
        vm/Object.cpp vm/Object.h
        vm/Type.cpp vm/Type.h
        vm/Number.cpp vm/Number.h
        vm/Function.cpp vm/Function.h)
target_link_libraries(${MANDA_LIBRARY} ${SYMBOL_TABLE_CPP})

add_executable(${MANDA_EXECUTABLE} entrypoint/main.cc)
find_library(ANTLR4 antlr4-runtime)

ExternalProject_Add(SYMBOL_TABLE
        GIT_REPOSITORY "https://github.com/thosakwe/symbol_table_cpp.git"
        GIT_TAG 7ac8614
        GIT_SHALLOW 1
)

ExternalProject_Get_Property(SYMBOL_TABLE source_dir)
include_directories(${source_dir})
include_directories(${Readline_INCLUDE_DIR})

ExternalProject_Get_Property(SYMBOL_TABLE binary_dir)
link_directories(${binary_dir})
find_library(SYMBOL_TABLE_CPP symbol_table_cpp HINTS ${binary_dir})

add_dependencies(${MANDA_LIBRARY} SYMBOL_TABLE)
target_link_libraries(${MANDA_EXECUTABLE} ${MANDA_LIBRARY} ${ANTLR4} ${SYMBOL_TABLE_CPP} ${Readline_LIBRARY})
set_target_properties(${MANDA_EXECUTABLE} PROPERTIES OUTPUT_NAME ${MANDA_LIBRARY})

install(TARGETS ${MANDA_LIBRARY} ${MANDA_EXECUTABLE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)