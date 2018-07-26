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
        runtime/Symbol.cpp runtime/Symbol.h
        runtime/SymbolTable.cpp runtime/SymbolTable.h
        text/Error.h
        text/SourceSpan.h
        text/Lexer.cpp text/Lexer.h
        text/Parser.cpp text/Parser.h
        text/Token.cpp text/Token.h
        text/SourceSpan.cpp
        text/text.h manda_src.h
        text/AstNode.cpp text/AstNode.h
        text/ExpressionNode.cpp text/ExpressionNode.h
        text/NumberLiteralNode.cpp text/NumberLiteralNode.h
        text/StatementNode.cpp text/StatementNode.h
        text/ExpressionStatementNode.cpp text/ExpressionStatementNode.h
        text/CompilationUnitNode.cpp text/CompilationUnitNode.h
        runtime/runtime.h
        runtime/Interpreter.cpp runtime/Interpreter.h text/SimpleIdentifierNode.cpp text/SimpleIdentifierNode.h text/InfixParselet.cpp text/InfixParselet.h text/BinaryExpressionParselet.cpp text/BinaryExpressionParselet.h text/BinaryExpressionNode.cpp text/BinaryExpressionNode.h text/VariableDeclarationStatementNode.cpp text/VariableDeclarationStatementNode.h analysis/Analyzer.cpp analysis/Analyzer.h analysis/Module.cpp analysis/Module.h analysis/Function.cpp analysis/Function.h analysis/Block.cpp analysis/Block.h analysis/Instruction.cpp analysis/Instruction.h analysis/Type.cpp analysis/Type.h analysis/Object.cpp analysis/Object.h analysis/Program.cpp analysis/Program.h text/TracksErrors.cpp text/TracksErrors.h analysis/analysis.h analysis/NumType.cpp analysis/NumType.h analysis/TypeObject.cpp analysis/TypeObject.h analysis/ObjectInstruction.cpp analysis/ObjectInstruction.h analysis/AssignmentInstruction.cpp analysis/AssignmentInstruction.h analysis/Reference.cpp analysis/Reference.h runtime/nanbox.h text/ParameterNode.cpp text/ParameterNode.h text/TypeNode.cpp text/TypeNode.h text/TypeReferenceNode.cpp text/TypeReferenceNode.h text/ParameterListNode.cpp text/ParameterListNode.h text/FunctionBodyNode.cpp text/FunctionBodyNode.h text/FunctionSignatureNode.cpp text/FunctionSignatureNode.h text/ArrowFunctionBodyNode.cpp text/ArrowFunctionBodyNode.h)
target_link_libraries(${MANDA_LIBRARY} ${SYMBOL_TABLE_CPP})

add_executable(${MANDA_EXECUTABLE} entrypoint/main.cc)

target_link_libraries(${MANDA_EXECUTABLE} ${MANDA_LIBRARY} ${Readline_LIBRARY} ${LIBJIT} ${LIBJIT_PLUS})
set_target_properties(${MANDA_EXECUTABLE} PROPERTIES OUTPUT_NAME ${MANDA_LIBRARY})

install(TARGETS ${MANDA_LIBRARY} ${MANDA_EXECUTABLE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)