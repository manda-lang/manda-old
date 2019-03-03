set(CMAKE_CXX_STANDARD 17)
include_directories(include)
file(GLOB_RECURSE bytecode_includes include/bytecode/*.hpp)
file(GLOB_RECURSE bytecode_srcs src/bytecode/*.cpp)
file(GLOB_RECURSE bytecode_includes include/runtime/*.hpp)
file(GLOB_RECURSE runtime_srcs src/runtime/*.cpp)

add_library(manda_bytecode ${bytecode_includes} ${bytecode_srcs})
add_library(manda_runtime ${bytecode_includes} ${runtime_includes} ${runtime_srcs})