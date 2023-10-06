/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_A117A6CD_6694_4F2E_9CCC_9051D7000128
#define CHIP_A117A6CD_6694_4F2E_9CCC_9051D7000128

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
  enum struct Interrupt : uint32_t;
}  // namespace chip::adc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::adc::Interrupt : uint32_t {
  CCE = 0x00000020,  /**< channels conversion end interrupt */
  VMOR = 0x00000040, /**< voltage monitoring out of range interrupt */
  PCCE = 0x00000080  /**< preempt channels conversion end interrupt */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_A117A6CD_6694_4F2E_9CCC_9051D7000128 */
