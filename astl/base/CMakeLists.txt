PROJECT(astl_base C CXX)
file(GLOB_RECURSE base_HEADERS "*hpp")



install(FILES ${base_HEADERS} DESTINATION include)