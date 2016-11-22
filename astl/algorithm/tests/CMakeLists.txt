cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)

link_directories(${Boost_LIBRARY_DIRS})
add_executable(test_algo modify_algo_test.cpp)
target_link_libraries(test_algo astl_algo  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME test_algo COMMAND test_algo)