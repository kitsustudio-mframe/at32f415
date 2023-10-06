/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56
#define CHIP_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr {
  enum struct PolarityActive : uint8_t;
}  // namespace chip::tmr

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::PolarityActive : uint8_t {
  HIGH = 0x00, /*!< tmr polarity active high */
  LOW = 0x01,  /*!< tmr polarity active low */
  BOTH = 0x02  /*!< tmr polarity active both high ande low */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56 */
