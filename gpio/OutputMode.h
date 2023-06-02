/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9ADA95FA_B26A_487D_8F47_F3E14B56951E
#define AT32F415_9ADA95FA_B26A_487D_8F47_F3E14B56951E

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
    enum struct OutputMode : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::OutputMode : uint8_t{
  PUSHPULL  = 0x00, /*!< output push-pull */
  OPENDRAIN = 0x04  /*!< output open-drain */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9ADA95FA_B26A_487D_8F47_F3E14B56951E */
