#include "lis6mdltr.h"  //functions for work with LIS6MDLTR

// Local Defines
#define def_CTRL_REG1 0x20  // control register
#define def_INT_CFG 0x30    // ITR register

void get_AllConfig(uint8_t* buffer) { i2c_read(def_ADDR_LIS3MDLTR, 0x00, buffer, 34); }

// CTRL_REG1 (20h) - TEMP_EN OM1 OM0 DO2 DO1 DO0 FAST_ODR ST - MSb?
uint8_t GetSet_DataRate(enum e_LIS3MDLTR_DataRate NextSpeedHz) {
  uint8_t DevSpeed = 0x00;
  i2c_read(def_ADDR_LIS3MDLTR, def_CTRL_REG1, &DevSpeed, 1);

  if (NextSpeedHz < e_LIS3MDLTR_DataRate_NotChanged) {
    uint8_t new_rate = (DevSpeed & 0xE3) | (NextSpeedHz << 2);  // create new speed (another bits not changed)
    i2c_write(def_ADDR_LIS3MDLTR, def_CTRL_REG1, &new_rate, 1);
  }
  return (DevSpeed & 0x1C);  // select DO2 DO1 DO0
}

// INT_CFG (30h) - XIEN YIEN ZIEN 0 (1) 1 IEA LIR IEN
// IEN-Enables the interrupt on the INT pin. Default value: 0 (0: disabled; 1: enabled)
void set_ITR_Pin(bool PinITR_En) {
  uint8_t DevITRs = 0x00;
  i2c_read(def_ADDR_LIS3MDLTR, def_INT_CFG, &DevITRs, 1);

  DevITRs &= 0xFE;  // delete ITR bit
  if (PinITR_En) {
    DevITRs |= 1;
  }
  i2c_write(def_ADDR_LIS3MDLTR, def_INT_CFG, &DevITRs, 1);
}

// registers in format OUT_X_L (28h), OUT_X_H (29h), need to convert in MSB
uint16_t get_Axe_data(enum e_LIS3MDLTR_AXES SelectedAxe) {
  uint8_t TempArr[2] = {0};
  i2c_read(def_ADDR_LIS3MDLTR, SelectedAxe, &TempArr, 2);

  uint16_t RealData = (TempArr[1] << 8) | TempArr[0];  // convert - possible to rewrite
  return RealData;
}