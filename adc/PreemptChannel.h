/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E1999E3A_54B2_4C44_B509_48BA5F63C2E7
#define CHIP_E1999E3A_54B2_4C44_B509_48BA5F63C2E7

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::adc {
  enum struct PreemptChannel : uint8_t;
}  // namespace chip::adc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::adc::PreemptChannel : uint8_t {
  CHANNEL1 = 0x00, /**< adc preempt channel 1 */
  CHANNEL2 = 0x01, /**< adc preempt channel 2 */
  CHANNEL3 = 0x02, /**< adc preempt channel 3 */
  CHANNEL4 = 0x03  /**< adc preempt channel 4 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_E1999E3A_54B2_4C44_B509_48BA5F63C2E7 */
