file(GLOB iterator_SRCS "*.cpp")
file(GLOB iterator_HEADERS "*.hpp")

add_library(astl_iterator ${iterator_SRCS} ${iterator_HEADERS})

add_subdirectory(tests)

install(TARGETS astl_iterator DESTINATION lib)
install(FILES ${iterator_HEADERS} DESTINATION include/astl/iterator)