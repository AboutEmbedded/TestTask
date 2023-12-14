#ifndef __LIS6MDLTR_H_
#define __LIS6MDLTR_H_

//======================================================
//    #include "lis6mdltr.h" //functions for work with LIS6MDLTR
//======================================================

#include "i2c_bus.h"  //functions for work with I2C
#include "stdbool.h"  //for boolean variables
#include "stdint.h"   //for int variables

// address of sensor 0x1E - 0011110b(DO/SA1 pin on vcc) or 0011100b (gnd)
#define def_ADDR_LIS3MDLTR (0x1E << 1)

// variants of speed
enum e_LIS3MDLTR_DataRate {
  e_LIS3MDLTR_DataRate_0_625Hz = 0,
  e_LIS3MDLTR_DataRate_1_25Hz,
  e_LIS3MDLTR_DataRate_2_5Hz,
  e_LIS3MDLTR_DataRate_5_0Hz,
  e_LIS3MDLTR_DataRate_10_0Hz,
  e_LIS3MDLTR_DataRate_20_0Hz,
  e_LIS3MDLTR_DataRate_40_0Hz,
  e_LIS3MDLTR_DataRate_80_0Hz,
  e_LIS3MDLTR_DataRate_NotChanged
};

// addresses of axes
enum e_LIS3MDLTR_AXES { e_LIS3MDLTR_AXE_X = 0x28, e_LIS3MDLTR_AXE_Y = 0x2A, e_LIS3MDLTR_AXE_Z = 0x2C };

/// @brief function for receive all configs of sensor
/// @param buffer pointer on buffer at least 34B for sensor config
void get_AllConfig(uint8_t* buffer);

/// @brief function for get and set data rate
/// @param  enum with variants of speed
/// @return previous speed
uint8_t GetSet_DataRate(enum e_LIS3MDLTR_DataRate NextSpeedHz);

/// @brief function for setting interrupt pin
/// @param PinITR_En true for enable, false for disable
void set_ITR_Pin(bool PinITR_En);

/// @brief function for read axes data
/// @param enum with adress of axe data register
/// @return value by this axe
uint16_t get_Axe_data(enum e_LIS3MDLTR_AXES SelectedAxe);

#endif /* __LIS6MDLTR_H_ */