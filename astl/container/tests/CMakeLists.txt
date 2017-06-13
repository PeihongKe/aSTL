cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)

link_directories(${Boost_LIBRARY_DIRS})

add_executable(test_vector  vector_tests.cpp)
target_link_libraries(test_vector astl_container ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME test_vector COMMAND test_vector)

add_executable(test_list  list_tests.cpp)
target_link_libraries(test_list astl_container ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME test_list COMMAND test_list)

