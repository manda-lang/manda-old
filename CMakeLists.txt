cmake_minimum_required(VERSION 3.0)
project(manda C)

set(MANDA_LIBRARY manda CACHE STRING "The name of the Manda library, against which you can link.")

include_directories(include)
add_subdirectory(src)