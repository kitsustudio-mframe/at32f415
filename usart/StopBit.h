/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_6EF1F4F4_D251_490B_AC43_554741A1A8BF
#define AT32F415_6EF1F4F4_D251_490B_AC43_554741A1A8BF

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
    enum struct StopBit : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::StopBit : uint8_t{
  BIT_1_0 = 0x00, /*!< usart stop bits num is 1 */
  BIT_0_5 = 0x01, /*!< usart stop bits num is 0.5 */
  BIT_2_0 = 0x02, /*!< usart stop bits num is 2 */
  BIT_1_5 = 0x03  /*!< usart stop bits num is 1.5 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_6EF1F4F4_D251_490B_AC43_554741A1A8BF */
