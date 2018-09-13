set(CMAKE_CXX_STANDARD 11)
add_executable(manda
        src/analysis/MandaType.cpp src/analysis/MandaType.h
        src/analysis/MandaIntegerType.cpp src/analysis/MandaIntegerType.h
        src/analysis/MandaCoreTypes.cpp src/analysis/MandaCoreTypes.h
        src/analysis/SymbolTable.cpp src/analysis/SymbolTable.h
        src/analysis/MandaObject.cpp src/analysis/MandaObject.h
        src/analysis/MandaObjectOrType.cpp src/analysis/MandaObjectOrType.h
        src/entrypoint/main.cpp)