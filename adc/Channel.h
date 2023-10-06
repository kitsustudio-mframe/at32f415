/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_597F8946_D1A4_48CA_A4B7_4C48FD3CEBF1
#define CHIP_597F8946_D1A4_48CA_A4B7_4C48FD3CEBF1

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::adc {
  enum struct Channel : uint8_t;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::adc::Channel : uint8_t {
  CHANNEL0 = 0x00,  /**< adc channel 0  */
  CHANNEL1 = 0x01,  /**< adc channel 1  */
  CHANNEL2 = 0x02,  /**< adc channel 2  */
  CHANNEL3 = 0x03,  /**< adc channel 3  */
  CHANNEL4 = 0x04,  /**< adc channel 4  */
  CHANNEL5 = 0x05,  /**< adc channel 5  */
  CHANNEL6 = 0x06,  /**< adc channel 6  */
  CHANNEL7 = 0x07,  /**< adc channel 7  */
  CHANNEL8 = 0x08,  /**< adc channel 8  */
  CHANNEL9 = 0x09,  /**< adc channel 9  */
  CHANNEL10 = 0x0A, /**< adc channel 10 */
  CHANNEL11 = 0x0B, /**< adc channel 11 */
  CHANNEL12 = 0x0C, /**< adc channel 12 */
  CHANNEL13 = 0x0D, /**< adc channel 13 */
  CHANNEL14 = 0x0E, /**< adc channel 14 */
  CHANNEL15 = 0x0F, /**< adc channel 15 */
  CHANNEL16 = 0x10, /**< adc channel 16 */
  CHANNEL17 = 0x11  /**< adc channel 17 */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_597F8946_D1A4_48CA_A4B7_4C48FD3CEBF1 */
