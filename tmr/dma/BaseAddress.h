/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F6334E07_789A_4A65_974C_FDFD18E73318
#define CHIP_F6334E07_789A_4A65_974C_FDFD18E73318

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::dma {
  enum struct BaseAddress : uint16_t;
}  // namespace chip::tmr::dma

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::dma::BaseAddress : uint16_t {
  CTRL1 = 0x0000,  /**< tmr dma base address ctrl1 */
  CTRL2 = 0x0001,  /**< tmr dma base address ctrl2 */
  STCTRL = 0x0002, /**< tmr dma base address stctrl */
  IDEN = 0x0003,   /**< tmr dma base address iden */
  ISTS = 0x0004,   /**< tmr dma base address ists */
  SWEVT = 0x0005,  /**< tmr dma base address swevt */
  CM1 = 0x0006,    /**< tmr dma base address cm1 */
  CM2 = 0x0007,    /**< tmr dma base address cm2 */
  CCTRL = 0x0008,  /**< tmr dma base address cctrl */
  CVAL = 0x0009,   /**< tmr dma base address cval */
  DIV = 0x000A,    /**< tmr dma base address div */
  PR = 0x000B,     /**< tmr dma base address pr */
  RPR = 0x000C,    /**< tmr dma base address rpr */
  C1DT = 0x000D,   /**< tmr dma base address c1dt */
  C2DT = 0x000E,   /**< tmr dma base address c2dt */
  C3DT = 0x000F,   /**< tmr dma base address c3dt */
  C4DT = 0x0010,   /**< tmr dma base address c4dt */
  BRK = 0x0011,    /**< tmr dma base address brake */
  DMACTRL = 0x0012 /**< tmr dma base address dmactrl */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_F6334E07_789A_4A65_974C_FDFD18E73318 */
