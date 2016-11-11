set(iterator_SRCS
iterator.cpp
iteratorUtil.cpp
)

file(GLOB iterator_HEADERS "*.hpp")

add_library(astl_iterator ${iterator_SRCS} ${iterator_HEADERS})



install(TARGETS astl_iterator DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/astl/iterator)