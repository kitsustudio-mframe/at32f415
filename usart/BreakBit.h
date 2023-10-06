/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_794B5884_2258_48B2_B6D7_395FCDCB3388
#define CHIP_794B5884_2258_48B2_B6D7_395FCDCB3388

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
  enum struct BreakBit : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::BreakBit : uint8_t {
  BITS10 = 0x00, /*!< usart lin mode berak frame detection 10 bits */
  BITS11 = 0x01  /*!< usart lin mode berak frame detection 11 bits */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_794B5884_2258_48B2_B6D7_395FCDCB3388 */
