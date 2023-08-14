/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_B783141D_7465_4A74_900D_2B6244C11E04
#define CHIP_B783141D_7465_4A74_900D_2B6244C11E04

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../core/CoreGeneralPort.h"
#include "./../core/CoreInterrupt.h"
#include "./../core/CoreIomux.h"

/* ****************************************************************************************
 * Namespace
 */

namespace chip::core {
  class Core;
}

/* ****************************************************************************************
 * Class Object
 */
class chip::core::Core : public mframe::lang::Object {
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
 public:
  static core::CoreInterrupt interrupt;
  static core::CoreIomux iomux;
  static core::CoreGeneralPort gpioa;
  static core::CoreGeneralPort gpiob;
  static core::CoreGeneralPort gpioc;
  static core::CoreGeneralPort gpiod;
  static core::CoreGeneralPort gpiof;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 private:
  /**
   *
   */
  Core(void);

  /**
   *
   */
  virtual ~Core(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:

  /**
   * @brief Get the System Core Clock object
   * 
   * @return uint32_t 
   */
  static uint32_t getSystemCoreClock(void);

  /**
   * @brief Set the System Core Clock object
   *
   * @param mhz
   * @return true
   * @return false
   */
  static bool setSystemCoreClock(uint32_t mhz);

  /**
   * @brief 
   * 
   */
  static void defaultSetup(void);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* *****************************************************************************************
 * End of file
 */

#endif /* CHIP_B783141D_7465_4A74_900D_2B6244C11E04 */
