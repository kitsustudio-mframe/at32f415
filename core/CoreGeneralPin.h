/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CORE_EF4F5B70_C257_44EE_8874_9BBD7AFAD856
#define CORE_EF4F5B70_C257_44EE_8874_9BBD7AFAD856

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../gpio/package-info.h"
#include "hal/package-info.h"
#include "lang/package-info.h"
//-----------------------------------------------------------------------------------------
#include "./CoreGeneralPort.h"

/* ****************************************************************************************
 * Namespace
 */

namespace at32f415::core {
  class CoreGeneralPin;
}

/* ****************************************************************************************
 * Class Object
 */
class at32f415::core::CoreGeneralPin : public lang::Object,
                                       public hal::GeneralPin {
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
 private:
  gpio::Register& mReg;
  uint32_t mPin;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  /**
   * Construct.
   */
  CoreGeneralPin(core::CoreGeneralPort& base,
                 uint32_t pin);

  /**
   * Dis:.
   */
  virtual ~CoreGeneralPin(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - hal::GeneralOutput
   */
 public:
  /**
   * @brief Set the High object
   *
   */
  virtual void setHigh(void) override;

  /**
   * @brief Set the Low object
   *
   */
  virtual void setLow(void) override;

  /**
   * @brief Set the Toggle object
   *
   */
  virtual void setToggle(void) override;

  /**
   * @brief
   *
   * @param level
   */
  virtual void setValue(bool level) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::GeneralInput
   */
 public:
  /**
   * @brief Get io pin.
   *
   * @return true high
   * @return false low
   */
  virtual bool getValue(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::GeneralPin
   */
  /**
   * @brief
   *
   * @return PinMode
   */
  virtual hal::GeneralPinMode getPinMode(void) override;

  /**
   * @brief Set the Pin Mode object
   *
   * @param mode
   * @return hal::GeneralPinMode 返回設定模式
   */
  virtual hal::GeneralPinMode setPinMode(hal::GeneralPinMode mode) override;

  /**
   * @brief  Get io direction.
   *
   * @return true output
   * @return false input
   */
  virtual bool getDir(void) override;

  /**
   * @brief Set io direction.
   *
   * @param dir false = input, true = output.
   */
  virtual void setDir(bool dir) override;

  /**
   * @brief Set the Input object
   *
   */
  virtual void setInput(void) override;

  /**
   * @brief Set the Output object
   *
   */
  virtual void setOutput(void) override;

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

#endif /* CORE_EF4F5B70_C257_44EE_8874_9BBD7AFAD856 */
