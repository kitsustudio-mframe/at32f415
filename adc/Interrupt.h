/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_A117A6CD_6694_4F2E_9CCC_9051D7000128
#define AT32F415_A117A6CD_6694_4F2E_9CCC_9051D7000128

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
  namespace adc{
    enum struct Interrupt : uint32_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::Interrupt : uint32_t{
  CCE  = 0x00000020, /**< channels conversion end interrupt */
  VMOR = 0x00000040, /**< voltage monitoring out of range interrupt */
  PCCE = 0x00000080 /**< preempt channels conversion end interrupt */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_A117A6CD_6694_4F2E_9CCC_9051D7000128 */
