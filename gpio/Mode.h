/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7
#define CHIP_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::gpio {
  enum struct Mode : uint8_t;
}  // namespace chip::gpio

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::gpio::Mode : uint8_t {
  INPUT = 0x00,  /*!< gpio input mode */
  OUTPUT = 0x10, /*!< gpio output mode */
  MUX = 0x08,    /*!< gpio mux function mode */
  ANALOG = 0x03  /*!< gpio analog in/out mode */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7 */
