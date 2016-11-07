set(iterator_SRCS
vector.cpp
)

add_library(astl_container ${container_SRCS})
target_link_libraries(astl_container astl_iterator)


install(TARGETS astl_container DESTINATION lib)

file(GLOB HEADERS "*.hpp")
install(FILES ${HEADERS} DESTINATION include/astl/iterator)