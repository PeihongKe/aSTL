set(container_SRCS
vector.cpp
list.cpp
)

file(GLOB_RECURSE container_HEADERS "*.hpp")

add_library(astl_container ${container_SRCS} ${container_HEADERS})

target_link_libraries(astl_container astl_iterator)
add_subdirectory(tests)

install(TARGETS astl_container DESTINATION lib)
install(FILES ${container_HEADERS} DESTINATION include)