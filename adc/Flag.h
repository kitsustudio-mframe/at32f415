/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_2858BD1D_A9E4_4C5D_A345_4BB7D70294DA
#define AT32F415_2858BD1D_A9E4_4C5D_A345_4BB7D70294DA

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
    enum struct Flag : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::Flag : uint8_t{
  VMOR = 0x01, /**< voltage monitoring out of range flag */
  CCE  = 0x02, /**< channels conversion end flag */
  PCCE = 0x04, /**< preempt channels conversion end flag */
  PCCS = 0x08, /**< preempt channel conversion start flag */
  OCCS = 0x10 /**< ordinary channel conversion start flag */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_2858BD1D_A9E4_4C5D_A345_4BB7D70294DA */
