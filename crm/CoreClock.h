/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_D5750F69_7633_4EEB_8C41_7522E2DE455E
#define AT32F415_D5750F69_7633_4EEB_8C41_7522E2DE455E

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
  struct CoreClock;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::crm::CoreClock {
  uint32_t sclk_freq; /*!< system clock frequency */
  uint32_t ahb_freq;  /*!< ahb bus clock frequency */
  uint32_t apb2_freq; /*!< apb2 bus clock frequency */
  uint32_t apb1_freq; /*!< apb1 bus clock frequency */
  uint32_t adc_freq;  /*!< adc clock frequency */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_D5750F69_7633_4EEB_8C41_7522E2DE455E */
