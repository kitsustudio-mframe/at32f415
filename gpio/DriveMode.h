/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99
#define AT32F415_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99

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
    enum struct DriveMode : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::DriveMode : uint8_t{
  STRONGER = 0x01, /*!< stronger sourcing/sinking strength */
  MODERATE = 0x02, /*!< moderate sourcing/sinking strength */
  MAXIMUM  = 0x03  /*!< maximum sourcing/sinking strength */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99 */
