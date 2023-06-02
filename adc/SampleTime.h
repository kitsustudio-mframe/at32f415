/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_51F6D24A_FE05_4796_947B_046F2F4214F7
#define AT32F415_51F6D24A_FE05_4796_947B_046F2F4214F7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415 {
  namespace adc {
    enum struct SampleTime : uint8_t;
  }
}  // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::SampleTime : uint8_t {
  CYCLE_1_5 = 0x00,  /**< adc sample time 1.5 cycle */
  CYCLE_7_5 = 0x01,  /**< adc sample time 7.5 cycle */
  CYCLE_13_5 = 0x02, /**< adc sample time 13.5 cycle */
  CYCLE_28_5 = 0x03, /**< adc sample time 28.5 cycle */
  CYCLE_41_5 = 0x04, /**< adc sample time 41.5 cycle */
  CYCLE_55_5 = 0x05, /**< adc sample time 55.5 cycle */
  CYCLE_71_5 = 0x06, /**< adc sample time 71.5 cycle */
  CYCLE_239_5 = 0x07 /**< adc sample time 239.5 cycle */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_51F6D24A_FE05_4796_947B_046F2F4214F7 */
