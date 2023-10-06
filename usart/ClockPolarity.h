/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_92B0B599_71E0_4692_B0F5_8874D3FE4DA3
#define CHIP_92B0B599_71E0_4692_B0F5_8874D3FE4DA3

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
  enum struct ClockPolarity : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::ClockPolarity : uint8_t {
  LOW = 0x00, /*!< usart clock stay low level outside transmission window */
  HIGH = 0x01 /*!< usart clock stay high level outside transmission window */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_92B0B599_71E0_4692_B0F5_8874D3FE4DA3 */
