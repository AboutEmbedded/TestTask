Inside you can find example of code for work with sensor LIS3MDL (functions for usage)


for using this code - you must to write functions for work with I2C
void i2c_read(uint8_t bus_address, uint8_t register_address, uint8_t *buffer, uint16_t length);
i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data, uint16_t length);

Change I2C device addres (file lis6mdltr.h), include it in your project and use functions in your code
