add_library(Joint mors_drive.cpp mors_joints.cpp)
target_link_arduino_libraries(Joint PRIVATE core)

