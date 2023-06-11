/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_D5750F69_7633_4EEB_8C41_7522E2DE455E
#define CHIP_D5750F69_7633_4EEB_8C41_7522E2DE455E

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::crm {
  struct CoreClock;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::crm::CoreClock {
  uint32_t sclk_freq; /*!< system clock frequency */
  uint32_t ahb_freq;  /*!< ahb bus clock frequency */
  uint32_t apb2_freq; /*!< apb2 bus clock frequency */
  uint32_t apb1_freq; /*!< apb1 bus clock frequency */
  uint32_t adc_freq;  /*!< adc clock frequency */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_D5750F69_7633_4EEB_8C41_7522E2DE455E */
