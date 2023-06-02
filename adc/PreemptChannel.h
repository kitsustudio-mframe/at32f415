/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E1999E3A_54B2_4C44_B509_48BA5F63C2E7
#define AT32F415_E1999E3A_54B2_4C44_B509_48BA5F63C2E7

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
    enum struct PreemptChannel : uint8_t;
  }
}  // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::PreemptChannel : uint8_t {
  CHANNEL1 = 0x00, /**< adc preempt channel 1 */
  CHANNEL2 = 0x01, /**< adc preempt channel 2 */
  CHANNEL3 = 0x02, /**< adc preempt channel 3 */
  CHANNEL4 = 0x03  /**< adc preempt channel 4 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_E1999E3A_54B2_4C44_B509_48BA5F63C2E7 */
