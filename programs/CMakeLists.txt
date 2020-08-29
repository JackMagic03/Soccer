# create library
add_library(Globals globals.cpp globals.hpp)

target_include_directories(Globals PUBLIC ${CMAKE_SOURCE_DIR}/libraries)
target_link_libraries(Globals Libraries)