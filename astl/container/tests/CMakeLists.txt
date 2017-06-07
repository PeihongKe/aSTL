cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)

link_directories(${Boost_LIBRARY_DIRS})
add_executable(test_container  vector_tests.cpp list_tests.cpp)
target_link_libraries(test_container astl_container ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME test_container COMMAND test_container)
