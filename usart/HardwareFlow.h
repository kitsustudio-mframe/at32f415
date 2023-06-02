/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_6C96308D_E0BF_4FBA_8C4B_BB69758F57C9
#define AT32F415_6C96308D_E0BF_4FBA_8C4B_BB69758F57C9

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace usart{
    enum struct HardwareFlow : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::HardwareFlow : uint8_t{
  NONE    = 0x00, /*!< usart without hardware flow */
  RTS     = 0x01, /*!< usart hardware flow only rts */
  CTS     = 0x02, /*!< usart hardware flow only cts */
  RTS_CTS = 0x03  /*!< usart hardware flow both rts and cts */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_6C96308D_E0BF_4FBA_8C4B_BB69758F57C9 */
