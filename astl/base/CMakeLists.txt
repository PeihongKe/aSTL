PROJECT(astl_base C CXX)
set(base_SRCS type_traits.cpp)


file(GLOB_RECURSE base_HEADERS "*hpp")
add_library(astl_base ${base_SRCS} ${base_HEADERS})



install(FILES ${base_HEADERS} DESTINATION include)