set(CMAKE_CXX_STANDARD 17)
include_directories(include)
file(GLOB_RECURSE manda_includes include/*.hpp)
add_library(manda ${manda_includes}
        src/bytecode/BytecodeVisitor.cpp src/bytecode/Kernel.cpp
        src/bytecode/DataSection.cpp src/bytecode/Label.cpp src/bytecode/CodeSection.cpp src/bytecode/SyscallInstruction.cpp src/bytecode/AddInstruction.cpp)