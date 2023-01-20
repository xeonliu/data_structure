cmake_minimum_required(VERSION 3.24)
project(new_datastructure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(datastructure_run ${SOURCE_FILES})

include_directories(ListLib)
add_subdirectory(ListLib)

target_link_libraries(datastructure_run ListLib)

add_subdirectory(Doctest)
