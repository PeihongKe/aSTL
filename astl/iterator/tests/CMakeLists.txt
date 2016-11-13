cmake_minimum_required(VERSION 2.8.11)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(iterator_traits_test_exe  iterator_traits_test.cpp)
target_link_libraries(iterator_traits_test_exe ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
add_test(NAME iterator_traits_test COMMAND iterator_traits_test_exe)

