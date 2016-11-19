set(algo_SRCS
modify.cpp
)
file(GLOB_RECURSE algo_HEADERS "*hpp")
add_library(astl_algo ${algo_SRCS} ${algo_HEADERS})

install(TARGETS astl_algo DESTINATION lib)
install(FILES ${algo_HEADERS} DESTINATION include)


 