/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_70548A17_D8FD_40BF_A4F1_373131DEDF8A
#define AT32F415_70548A17_D8FD_40BF_A4F1_373131DEDF8A

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
    enum struct ParitySelection : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::ParitySelection : uint8_t{
  NONE = 0x00, /*!< usart no parity */
  EVEN = 0x01, /*!< usart even parity */
  ODD  = 0x02  /*!< usart odd parity */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_70548A17_D8FD_40BF_A4F1_373131DEDF8A */
