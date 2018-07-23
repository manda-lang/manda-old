include(ExternalProject)
find_package(Readline)
find_library(LIBJIT jit)
find_library(LIBJIT_PLUS jitplus)
find_path(LIBJIT_INCLUDE_DIR jit/jit-plus.h jit-plus.h)
include_directories(${LIBJIT_INCLUDE_DIR})

add_library(${MANDA_LIBRARY}
        runtime/Memory.cpp runtime/Memory.h
        runtime/VM.cpp runtime/VM.h
        runtime/Fiber.cpp runtime/Fiber.h
        runtime/TaggedPointer.cpp runtime/TaggedPointer.h
        runtime/Type.cpp runtime/Type.h
        runtime/Function.cpp runtime/Function.h
        runtime/Symbol.cpp runtime/Symbol.h
        runtime/SymbolTable.cpp runtime/SymbolTable.h
        text/Error.h
        text/SourceSpan.h
        text/Lexer.cpp text/Lexer.h
        text/Parser.cpp text/Parser.h
        text/Token.cpp text/Token.h
        text/SourceSpan.cpp
        text/text.h src.h
        text/AstNode.cpp text/AstNode.h
        text/ExpressionNode.cpp text/ExpressionNode.h
        text/NumberLiteralNode.cpp text/NumberLiteralNode.h
        text/StatementNode.cpp text/StatementNode.h
        text/ExpressionStatementNode.cpp text/ExpressionStatementNode.h
        text/ProgramNode.cpp text/ProgramNode.h
        runtime/runtime.h
        runtime/Interpreter.cpp runtime/Interpreter.h text/SimpleIdentifierNode.cpp text/SimpleIdentifierNode.h runtime/InterpreterCallbacks.cpp)
target_link_libraries(${MANDA_LIBRARY} ${SYMBOL_TABLE_CPP})

add_executable(${MANDA_EXECUTABLE} entrypoint/main.cc)

target_link_libraries(${MANDA_EXECUTABLE} ${MANDA_LIBRARY} ${Readline_LIBRARY} ${LIBJIT} ${LIBJIT_PLUS})
set_target_properties(${MANDA_EXECUTABLE} PROPERTIES OUTPUT_NAME ${MANDA_LIBRARY})

install(TARGETS ${MANDA_LIBRARY} ${MANDA_EXECUTABLE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)