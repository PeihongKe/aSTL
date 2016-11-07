set(iterator_SRCS
iterator.cpp
iteratorUtil.cpp
)

add_library(astl_iterator ${iterator_SRCS})

install(TARGETS astl_iterator DESTINATION lib)

file(GLOB HEADERS "*.hpp")
install(FILES ${HEADERS} DESTINATION include/astl/iterator)