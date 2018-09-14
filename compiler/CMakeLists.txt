set(CMAKE_CXX_STANDARD 11)

find_library(ANTLR4 antlr4-runtime)
find_library(LIBJIT jit)

include_directories(${ANTLR4_INCLUDE_DIR})

add_executable(manda
        src/analysis/MandaType.cpp src/analysis/MandaType.h
        src/analysis/MandaIntegerType.cpp src/analysis/MandaIntegerType.h
        src/analysis/MandaCoreTypes.cpp src/analysis/MandaCoreTypes.h
        src/analysis/SymbolTable.cpp src/analysis/SymbolTable.h
        src/analysis/MandaObject.cpp src/analysis/MandaObject.h
        src/analysis/MandaObjectOrType.cpp src/analysis/MandaObjectOrType.h
        src/parser/MandaBaseVisitor.cpp src/parser/MandaBaseVisitor.h
        src/parser/MandaLexer.cpp src/parser/MandaLexer.h
        src/parser/MandaParser.cpp src/parser/MandaParser.h
        src/parser/MandaVisitor.cpp src/parser/MandaVisitor.h
        src/entrypoint/main.cpp
        src/parser/parser.h
        src/analysis/MandaAnalyzer.cpp
        src/analysis/MandaAnalyzer.h
        src/analysis/SourceSpan.cpp src/analysis/SourceSpan.h
        src/analysis/MandaError.cpp src/analysis/MandaError.h
        src/analysis/CfgNode.cpp src/analysis/CfgNode.h src/analysis/CfgStatement.cpp src/analysis/CfgStatement.h)

target_link_libraries(manda ${ANTLR4} ${LIBJIT})