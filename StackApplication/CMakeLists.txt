cmake_minimum_required(VERSION 3.24)
project(stack_application)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp calc.cpp)
add_executable(stack_app_run ${SOURCE_FILES})

include_directories(StackLib)

target_link_libraries(stack_app_run StackLib)
