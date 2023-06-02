/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_84367C49_579D_47E9_972D_80EC819FA095
#define AT32F415_84367C49_579D_47E9_972D_80EC819FA095

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::flash {
  enum struct WaitCycle : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::flash::WaitCycle : uint8_t {
  WAIT_CYCLE0 = 0x00, /*!< sysclk 1~32mhz */
  WAIT_CYCLE1 = 0x01, /*!< sysclk 33~64mhz */
  WAIT_CYCLE2 = 0x02, /*!< sysclk 65~96mhz */
  WAIT_CYCLE3 = 0x03, /*!< sysclk 97~120mhz */
  WAIT_CYCLE4 = 0x04  /*!< sysclk 121~150mhz */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_84367C49_579D_47E9_972D_80EC819FA095 */
