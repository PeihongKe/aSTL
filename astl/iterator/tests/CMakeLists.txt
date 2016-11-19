cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)

link_directories(${Boost_LIBRARY_DIRS})
add_executable(test_iterator_traits  iterator_test.cpp)
target_link_libraries(test_iterator_traits astl_iterator  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME test_iterator_traits COMMAND test_iterator_traits)