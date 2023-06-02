/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_83B5994F_0532_4599_84BB_2DC745E84441
#define AT32F415_83B5994F_0532_4599_84BB_2DC745E84441

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::misc {
  enum struct LowPowerMode : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::misc::LowPowerMode : uint8_t {
  SLEEPONEXIT = 0x02, /*!< send event on pending */
  SLEEPDEEP = 0x04,   /*!< enable sleep-deep output signal when entering sleep mode */
  SEVONPEND = 0x10    /*!< enable sleep-on-exit feature */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_83B5994F_0532_4599_84BB_2DC745E84441 */
