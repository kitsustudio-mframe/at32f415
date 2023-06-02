/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_4880F19E_D918_472A_B649_19E40FC6E120
#define AT32F415_4880F19E_D918_472A_B649_19E40FC6E120

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415 {
  namespace pwc {
    enum struct DeepSleepEnter : uint8_t;
  }
} // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::pwc::DeepSleepEnter : uint8_t {
  WFI = 0x00, ///< use wfi enter deepsleep mode
  WFE = 0x01  ///< use wfe enter deepsleep mode
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_4880F19E_D918_472A_B649_19E40FC6E120 */
