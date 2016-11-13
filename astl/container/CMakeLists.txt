set(container_SRCS
vector.cpp
)

file(GLOB_RECURSE container_HEADERS "*.hpp")

add_library(astl_container ${container_SRCS} ${container_HEADERS})

target_link_libraries(astl_container astl_iterator)

install(TARGETS astl_container DESTINATION lib)
install(FILES ${container_HEADERS} DESTINATION include)