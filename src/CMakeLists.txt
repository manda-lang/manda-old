set(CMAKE_CXX_STANDARD 11)

find_library(LIBJIT jit)

find_path(LIBJIT_INCLUDE_DIR jit/jit.h)

add_executable(manda
    entrypoint/main.cc
)

target_include_directories(manda PUBLIC ${LIBJIT_INCLUDE_DIR})
target_link_libraries(manda ${LIBJIT})