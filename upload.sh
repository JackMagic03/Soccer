mkdir -p build
cd build
cmake ..
make upload-firmware SERIAL_PORT=/dev/ttyACM0
