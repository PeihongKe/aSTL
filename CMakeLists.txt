cmake_minimum_required(VERSION 3.0)

project(astl CXX)

add_definitions(-DBOOST_ALL_DYN_LINK)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost found !")
endif()
 


enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(astl)