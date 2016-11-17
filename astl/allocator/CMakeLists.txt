set(alloc_SRCS
construct.cpp
)
file(GLOB_RECURSE alloc_HEADERS "*hpp")
add_library(astl_alloc ${alloc_SRCS} ${alloc_HEADERS})

install(TARGETS astl_alloc DESTINATION lib)
install(FILES ${base_HEADERS} DESTINATION include)


add_subdirectory(tests)