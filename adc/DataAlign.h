/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E43AF8A4_08D8_4341_B4A3_AA356FBB81A8
#define CHIP_E43AF8A4_08D8_4341_B4A3_AA356FBB81A8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::adc {
  enum struct DataAlign : uint8_t;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::adc::DataAlign : uint8_t {
  RIGHT = 0x00, /**< data right alignment */
  LEFT = 0x01   /**< data left alignment  */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_E43AF8A4_08D8_4341_B4A3_AA356FBB81A8 */
