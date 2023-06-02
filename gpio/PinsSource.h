/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E696B80A_A700_4D5D_9DB3_2FFA5553F041
#define AT32F415_E696B80A_A700_4D5D_9DB3_2FFA5553F041

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
    enum struct PinsSource : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::PinsSource : uint8_t{
  PINS0  = 0x00, ///< gpio pins source number 0 
  PINS1  = 0x01, ///< gpio pins source number 1 
  PINS2  = 0x02, ///< gpio pins source number 2 
  PINS3  = 0x03, ///< gpio pins source number 3 
  PINS4  = 0x04, ///< gpio pins source number 4 
  PINS5  = 0x05, ///< gpio pins source number 5 
  PINS6  = 0x06, ///< gpio pins source number 6 
  PINS7  = 0x07, ///< gpio pins source number 7 
  PINS8  = 0x08, ///< gpio pins source number 8 
  PINS9  = 0x09, ///< gpio pins source number 9 
  PINS10 = 0x0A, ///< gpio pins source number 10
  PINS11 = 0x0B, ///< gpio pins source number 11
  PINS12 = 0x0C, ///< gpio pins source number 12
  PINS13 = 0x0D, ///< gpio pins source number 13
  PINS14 = 0x0E, ///< gpio pins source number 14
  PINS15 = 0x0F  ///< gpio pins source number 15
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_E696B80A_A700_4D5D_9DB3_2FFA5553F041 */
