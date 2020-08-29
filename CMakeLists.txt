cmake_minimum_required (VERSION 3.12)

# add the subdirectory
add_subdirectory(libraries)
add_subdirectory(programs)

#add executable
add_executable(Soccer main.cpp)

target_link_libraries(Soccer Globals Libraries)