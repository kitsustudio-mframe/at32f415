/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_41873779_7F02_4B18_A11C_DAAAE774C530
#define CHIP_41873779_7F02_4B18_A11C_DAAAE774C530

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::dma {
  enum struct TransferLength : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::dma::TransferLength : uint8_t {
  TRANSFER_1BYTE = 0x00,   /**< tmr dma transfer length 1 byte */
  TRANSFER_2BYTES = 0x01,  /**< tmr dma transfer length 2 bytes */
  TRANSFER_3BYTES = 0x02,  /**< tmr dma transfer length 3 bytes */
  TRANSFER_4BYTES = 0x03,  /**< tmr dma transfer length 4 bytes */
  TRANSFER_5BYTES = 0x04,  /**< tmr dma transfer length 5 bytes */
  TRANSFER_6BYTES = 0x05,  /**< tmr dma transfer length 6 bytes */
  TRANSFER_7BYTES = 0x06,  /**< tmr dma transfer length 7 bytes */
  TRANSFER_8BYTES = 0x07,  /**< tmr dma transfer length 8 bytes */
  TRANSFER_9BYTES = 0x08,  /**< tmr dma transfer length 9 bytes */
  TRANSFER_10BYTES = 0x09, /**< tmr dma transfer length 10 bytes */
  TRANSFER_11BYTES = 0x0A, /**< tmr dma transfer length 11 bytes */
  TRANSFER_12BYTES = 0x0B, /**< tmr dma transfer length 12 bytes */
  TRANSFER_13BYTES = 0x0C, /**< tmr dma transfer length 13 bytes */
  TRANSFER_14BYTES = 0x0D, /**< tmr dma transfer length 14 bytes */
  TRANSFER_15BYTES = 0x0E, /**< tmr dma transfer length 15 bytes */
  TRANSFER_16BYTES = 0x0F, /**< tmr dma transfer length 16 bytes */
  TRANSFER_17BYTES = 0x10, /**< tmr dma transfer length 17 bytes */
  TRANSFER_18BYTES = 0x11  /**< tmr dma transfer length 18 bytes */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_41873779_7F02_4B18_A11C_DAAAE774C530 */
