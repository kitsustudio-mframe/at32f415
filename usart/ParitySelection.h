/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_70548A17_D8FD_40BF_A4F1_373131DEDF8A
#define CHIP_70548A17_D8FD_40BF_A4F1_373131DEDF8A

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
  enum struct ParitySelection : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::ParitySelection : uint8_t {
  NONE = 0x00, /*!< usart no parity */
  EVEN = 0x01, /*!< usart even parity */
  ODD = 0x02   /*!< usart odd parity */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_70548A17_D8FD_40BF_A4F1_373131DEDF8A */
