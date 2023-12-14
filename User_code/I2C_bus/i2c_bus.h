#ifndef __I2C_BUS_H_
#define __I2C_BUS_H_

//======================================================
//    #include "i2c_bus.h" //functions for work with I2C
//======================================================

#include "stdint.h"

/// @brief function for read data - I2C bus
/// @param bus_address device address
/// @param register_address start adress of register
/// @param buffer pointer on buffer for receive data 
/// @param length lenght of data buffer
void i2c_read(uint8_t bus_address, uint8_t register_address, uint8_t *buffer, uint16_t length);

/// @brief function for write data - I2C bus
/// @param bus_address device address
/// @param register_address start adress of register
/// @param data pointer on data for Tx
/// @param length lenght of data buffer
void i2c_write(uint8_t bus_address, uint8_t register_address, uint8_t *data, uint16_t length);

#endif /* __I2C_BUS_H_ */