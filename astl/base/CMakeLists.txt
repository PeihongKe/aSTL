
file(GLOB_RECURSE base_HEADERS "*hpp")
add_library(astl_base ${base_HEADERS})
target_link_libraries(astl_base)

install(FILES ${base_HEADERS} DESTINATION include)