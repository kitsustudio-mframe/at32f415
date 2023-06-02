/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E700C623_D8A5_460D_BE91_21878D4648A3
#define AT32F415_E700C623_D8A5_460D_BE91_21878D4648A3

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
    enum struct PullMode : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::PullMode : uint8_t{
  PULL_NONE = 0x0004, ///< floating for input, no pull for output
  PULL_UP   = 0x0018, ///< pull-up
  PULL_DOWN = 0x0028  ///< pull-down
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_E700C623_D8A5_460D_BE91_21878D4648A3 */
