/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E4582BA1_72FE_4209_90B3_706A4A88F375
#define CHIP_E4582BA1_72FE_4209_90B3_706A4A88F375

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::output {
  enum struct Polarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::output::Polarity : uint8_t {
  ACTIVE_HIGH = 0x00, /*!< tmr output channel polarity high */
  ACTIVE_LOW = 0x01   /*!< tmr output channel polarity low */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_E4582BA1_72FE_4209_90B3_706A4A88F375 */
