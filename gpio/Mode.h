/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7
#define AT32F415_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace gpio{
    enum struct Mode : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::Mode : uint8_t{
  INPUT  = 0x00, /*!< gpio input mode */
  OUTPUT = 0x10, /*!< gpio output mode */
  MUX    = 0x08, /*!< gpio mux function mode */
  ANALOG = 0x03  /*!< gpio analog in/out mode */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_5280EA0E_A93A_4CBD_99CC_6B9AFA08E8C7 */
