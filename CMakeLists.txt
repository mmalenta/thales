# Just in case we need the native CUDA support in the future
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(thales LANGUAGES CXX VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(thales thales/thales.cpp 
                      thales/command_line_parser.cpp
                      thales/interpreter.cpp)

target_include_directories(thales PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS thales DESTINATION ${PROJECT_BINARY_DIR}/bin)

enable_testing()
add_test(NAME startup COMMAND thales --help)