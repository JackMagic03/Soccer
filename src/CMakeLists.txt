add_library(Globals globals.cpp)
target_link_libraries(Globals
  PUBLIC Joint
  PUBLIC Line
  PUBLIC Imu
  PUBLIC Pid
  PUBLIC Pixy
  PUBLIC Planner)
target_link_arduino_libraries(Globals PRIVATE core Wire SPI)

add_executable(firmware main.cpp)
target_link_libraries(firmware
  PUBLIC Globals
  PUBLIC Joint
  PUBLIC Line
  PUBLIC Imu
  PUBLIC Pid
  PUBLIC Pixy
  PUBLIC Planner)
target_link_arduino_libraries(firmware PRIVATE core Wire SPI)
target_enable_arduino_upload(firmware)
