add_library(Imu mors_imu.cpp mors_imuHandler.cpp)
target_link_libraries(Imu PRIVATE Adafruit_Sensor Adafruit_BNO055)
target_link_arduino_libraries(Imu PRIVATE core Wire SPI)
