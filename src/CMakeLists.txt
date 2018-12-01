set(CMAKE_CXX_STANDARD 11)

find_library(LIBJIT jit)

find_path(LIBJIT_INCLUDE_DIR jit/jit.h)

add_executable(manda
    entrypoint/main.cc
        ast/source_span.cc ast/source_span.h ast/source_location.cc ast/source_location.h ast/token_type.h ast/token.cc ast/token.h)

target_include_directories(manda PUBLIC ${LIBJIT_INCLUDE_DIR})
target_link_libraries(manda ${LIBJIT})