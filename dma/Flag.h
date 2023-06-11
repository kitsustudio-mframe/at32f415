/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_68CB5690_102A_4BD9_970E_EC037F4F0C3A
#define CHIP_68CB5690_102A_4BD9_970E_EC037F4F0C3A

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct Flag : uint32_t;

  enum_auto_operator(Flag, uint32_t)
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::Flag : uint32_t {
  DMA1_GL1 = 0x00000001,     ///< dma1 channel1 global flag
  DMA1_FDT1 = 0x00000002,    ///< dma1 channel1 full data transfer flag
  DMA1_HDT1 = 0x00000004,    ///< dma1 channel1 half data transfer flag
  DMA1_DTERR1 = 0x00000008,  ///< dma1 channel1 error flag
  DMA1_GL2 = 0x00000010,     ///< dma1 channel2 global flag
  DMA1_FDT2 = 0x00000020,    ///< dma1 channel2 full data transfer flag
  DMA1_HDT2 = 0x00000040,    ///< dma1 channel2 half data transfer flag
  DMA1_DTERR2 = 0x00000080,  ///< dma1 channel2 error flag
  DMA1_GL3 = 0x00000100,     ///< dma1 channel3 global flag
  DMA1_FDT3 = 0x00000200,    ///< dma1 channel3 full data transfer flag
  DMA1_HDT3 = 0x00000400,    ///< dma1 channel3 half data transfer flag
  DMA1_DTERR3 = 0x00000800,  ///< dma1 channel3 error flag
  DMA1_GL4 = 0x00001000,     ///< dma1 channel4 global flag
  DMA1_FDT4 = 0x00002000,    ///< dma1 channel4 full data transfer flag
  DMA1_HDT4 = 0x00004000,    ///< dma1 channel4 half data transfer flag
  DMA1_DTERR4 = 0x00008000,  ///< dma1 channel4 error flag
  DMA1_GL5 = 0x00010000,     ///< dma1 channel5 global flag
  DMA1_FDT5 = 0x00020000,    ///< dma1 channel5 full data transfer flag
  DMA1_HDT5 = 0x00040000,    ///< dma1 channel5 half data transfer flag
  DMA1_DTERR5 = 0x00080000,  ///< dma1 channel5 error flag
  DMA1_GL6 = 0x00100000,     ///< dma1 channel6 global flag
  DMA1_FDT6 = 0x00200000,    ///< dma1 channel6 full data transfer flag
  DMA1_HDT6 = 0x00400000,    ///< dma1 channel6 half data transfer flag
  DMA1_DTERR6 = 0x00800000,  ///< dma1 channel6 error flag
  DMA1_GL7 = 0x01000000,     ///< dma1 channel7 global flag
  DMA1_FDT7 = 0x02000000,    ///< dma1 channel7 full data transfer flag
  DMA1_HDT7 = 0x04000000,    ///< dma1 channel7 half data transfer flag
  DMA1_DTERR7 = 0x08000000,  ///< dma1 channel7 error flag

  DMA2_MARK = 0x10000000,

  DMA2_GL1 = 0x10000001,     ///< dma2 channel1 global flag
  DMA2_FDT1 = 0x10000002,    ///< dma2 channel1 full data transfer flag
  DMA2_HDT1 = 0x10000004,    ///< dma2 channel1 half data transfer flag
  DMA2_DTERR1 = 0x10000008,  ///< dma2 channel1 error flag
  DMA2_GL2 = 0x10000010,     ///< dma2 channel2 global flag
  DMA2_FDT2 = 0x10000020,    ///< dma2 channel2 full data transfer flag
  DMA2_HDT2 = 0x10000040,    ///< dma2 channel2 half data transfer flag
  DMA2_DTERR2 = 0x10000080,  ///< dma2 channel2 error flag
  DMA2_GL3 = 0x10000100,     ///< dma2 channel3 global flag
  DMA2_FDT3 = 0x10000200,    ///< dma2 channel3 full data transfer flag
  DMA2_HDT3 = 0x10000400,    ///< dma2 channel3 half data transfer flag
  DMA2_DTERR3 = 0x10000800,  ///< dma2 channel3 error flag
  DMA2_GL4 = 0x10001000,     ///< dma2 channel4 global flag
  DMA2_FDT4 = 0x10002000,    ///< dma2 channel4 full data transfer flag
  DMA2_HDT4 = 0x10004000,    ///< dma2 channel4 half data transfer flag
  DMA2_DTERR4 = 0x10008000,  ///< dma2 channel4 error flag
  DMA2_GL5 = 0x10010000,     ///< dma2 channel5 global flag
  DMA2_FDT5 = 0x10020000,    ///< dma2 channel5 full data transfer flag
  DMA2_HDT5 = 0x10040000,    ///< dma2 channel5 half data transfer flag
  DMA2_DTERR5 = 0x10080000,  ///< dma2 channel5 error flag
  DMA2_GL6 = 0x10100000,     ///< dma2 channel6 global flag
  DMA2_FDT6 = 0x10200000,    ///< dma2 channel6 full data transfer flag
  DMA2_HDT6 = 0x10400000,    ///< dma2 channel6 half data transfer flag
  DMA2_DTERR6 = 0x10800000,  ///< dma2 channel6 error flag
  DMA2_GL7 = 0x11000000,     ///< dma2 channel7 global flag
  DMA2_FDT7 = 0x12000000,    ///< dma2 channel7 full data transfer flag
  DMA2_HDT7 = 0x14000000,    ///< dma2 channel7 half data transfer flag
  DMA2_DTERR7 = 0x18000000   ///< dma2 channel7 error flag
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_68CB5690_102A_4BD9_970E_EC037F4F0C3A */
