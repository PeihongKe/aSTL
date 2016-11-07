cmake_minimum_required(VERSION 2.6)

project(astl CXX)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(astl)
add_subdirectory(tests)