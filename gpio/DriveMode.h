/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99
#define CHIP_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  enum struct DriveMode : uint8_t;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::gpio::DriveMode : uint8_t {
  STRONGER = 0x01, /*!< stronger sourcing/sinking strength */
  MODERATE = 0x02, /*!< moderate sourcing/sinking strength */
  MAXIMUM = 0x03   /*!< maximum sourcing/sinking strength */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_97E7C1B0_10B2_407D_9B9E_EBC2DDA6DB99 */
