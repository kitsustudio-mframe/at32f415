/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6EF1F4F4_D251_490B_AC43_554741A1A8BF
#define CHIP_6EF1F4F4_D251_490B_AC43_554741A1A8BF

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct StopBit : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::StopBit : uint8_t {
  BIT_1_0 = 0x00, /*!< usart stop bits num is 1 */
  BIT_0_5 = 0x01, /*!< usart stop bits num is 0.5 */
  BIT_2_0 = 0x02, /*!< usart stop bits num is 2 */
  BIT_1_5 = 0x03  /*!< usart stop bits num is 1.5 */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_6EF1F4F4_D251_490B_AC43_554741A1A8BF */
