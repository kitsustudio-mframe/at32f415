/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_4C72F3F1_6189_4C60_9557_DD5D3F89509E
#define AT32F415_4C72F3F1_6189_4C60_9557_DD5D3F89509E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::dma {
  enum struct RequestSource : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::dma::RequestSource : uint8_t {
  CHANNEL = 0x00, /**< tmr dma request source select channel */
  OVERFLOW = 0x01 /**< tmr dma request source select overflow */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_4C72F3F1_6189_4C60_9557_DD5D3F89509E */
