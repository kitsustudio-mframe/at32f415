/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_92B0B599_71E0_4692_B0F5_8874D3FE4DA3
#define AT32F415_92B0B599_71E0_4692_B0F5_8874D3FE4DA3

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
    enum struct ClockPolarity : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::ClockPolarity : uint8_t{
  LOW  = 0x00, /*!< usart clock stay low level outside transmission window */
  HIGH = 0x01  /*!< usart clock stay high level outside transmission window */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_92B0B599_71E0_4692_B0F5_8874D3FE4DA3 */
