cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)

link_directories(${Boost_LIBRARY_DIRS})
add_executable(container_test_exe  vector_tests.cpp)
target_link_libraries(container_test_exe astl_container ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME container_test COMMAND container_test_exe)
