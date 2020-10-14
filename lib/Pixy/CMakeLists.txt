add_library(Pixy mors_pixyHandler.cpp)
target_link_arduino_libraries(Pixy PRIVATE core SPI)
