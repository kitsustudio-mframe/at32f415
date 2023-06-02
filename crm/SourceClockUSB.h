/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_4DC72D62_4AE8_4CA0_884F_D4697C41B6F7
#define AT32F415_4DC72D62_4AE8_4CA0_884F_D4697C41B6F7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::crm {
  enum struct SourceClockUSB : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::SourceClockUSB : uint8_t {
  PLL = 0x00, /*!< select phase locking loop clock as usb clock source */
  HICK = 0x01 /*!< select high speed internal clock as usb clock source */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_4DC72D62_4AE8_4CA0_884F_D4697C41B6F7 */
