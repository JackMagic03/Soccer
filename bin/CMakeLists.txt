set(ARDUINO_DEFAULT_BOARD mega2560)
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)

generate_arduino_firmware(stub
  SRCS stub.cpp
  LIBS foo_lib bar_lib
  BOARD mega2560)
