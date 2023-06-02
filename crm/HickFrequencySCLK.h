/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_5DF1B21D_285A_4FC2_9CD3_264D0A069E83
#define AT32F415_5DF1B21D_285A_4FC2_9CD3_264D0A069E83

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
  enum struct HickFrequencySCLK : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::HickFrequencySCLK : uint8_t {
  HICK_8MHZ = 0x00, /*!< fixed 8 mhz when hick is selected as sclk */
  HICK_48MHZ = 0x01 /*!< 8 mhz or 48 mhz depend on hickdiv when hick is selected as sclk */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_5DF1B21D_285A_4FC2_9CD3_264D0A069E83 */
