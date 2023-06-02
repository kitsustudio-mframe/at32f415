/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9240E19E_FF55_46E1_BDEE_160881F1F22F
#define AT32F415_9240E19E_FF55_46E1_BDEE_160881F1F22F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::pwc {
  enum struct SleepEnter : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::pwc::SleepEnter : uint8_t {
  WFI = 0x00,  ///< use wfi enter sleep mode
  WFE = 0x01   ///< use wfe enter sleep mode
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9240E19E_FF55_46E1_BDEE_160881F1F22F */
