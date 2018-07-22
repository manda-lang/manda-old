cmake_minimum_required(VERSION 3.0)
project(manda CXX)

set(CMAKE_CXX_STANDARD 11)
set(MANDA_EXECUTABLE manda_exe CACHE STRING "The name of the Manda executable target.")
set(MANDA_LIBRARY manda CACHE STRING "The name of the Manda library, against which you can link.")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include_directories(include)
add_subdirectory(src)

install(DIRECTORY include DESTINATION include)