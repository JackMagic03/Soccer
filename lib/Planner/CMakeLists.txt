add_library(Planner mors_attackPlanner.cpp mors_defensePlanner.cpp)
target_link_arduino_libraries(Planner PRIVATE core SPI Wire)
