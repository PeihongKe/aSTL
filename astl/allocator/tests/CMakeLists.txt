cmake_minimum_required(VERSION 3.0)
set(Boost_USE_STATIC_LIBS ON)


link_directories(${Boost_LIBRARY_DIRS})
add_executable(allocator_test_exe  allocator_test.cpp)
target_link_libraries(allocator_test_exe astl_alloc  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME astl_alloc_test COMMAND astl_alloc_exe)