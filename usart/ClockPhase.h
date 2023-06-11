/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_979E472A_3462_4CA6_8D4A_6FCA41DFC757
#define CHIP_979E472A_3462_4CA6_8D4A_6FCA41DFC757

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct ClockPhase : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::ClockPhase : uint8_t {
  EDGE1 = 0x00, /*!< usart data capture is done on the clock leading edge */
  EDGE2 = 0x01  /*!< usart data capture is done on the clock trailing edge */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_979E472A_3462_4CA6_8D4A_6FCA41DFC757 */
