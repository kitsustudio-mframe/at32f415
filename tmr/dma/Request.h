/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_49AB021F_C10C_484A_B273_1E479C1A20A1
#define AT32F415_49AB021F_C10C_484A_B273_1E479C1A20A1

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
  enum struct Request : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::dma::Request : uint32_t {
  OVERFLOW = 0x00000100, /**< tmr dma request select overflow */
  C1 = 0x00000200,       /**< tmr dma request select channel 1 */
  C2 = 0x00000400,       /**< tmr dma request select channel 2 */
  C3 = 0x00000800,       /**< tmr dma request select channel 3 */
  C4 = 0x00001000,       /**< tmr dma request select channel 4 */
  HALL = 0x00002000,     /**< tmr dma request select hall */
  TRIGGER = 0x00004000   /**< tmr dma request select trigger */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_49AB021F_C10C_484A_B273_1E479C1A20A1 */
