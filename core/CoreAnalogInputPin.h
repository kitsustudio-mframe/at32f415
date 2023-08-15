/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CHIP_9B7A9BBD_8B78_4DFC_9C43_4949BE7E17B8
#define CHIP_9B7A9BBD_8B78_4DFC_9C43_4949BE7E17B8

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./CoreAnalogInputPort.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::core {
  class CoreAnalogInputPin;
}  // namespace chip::core

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::core::CoreAnalogInputPin : public mframe::lang::Object,
                                       public mframe::hal::AnalogInputPin {
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
    chip::core::CoreAnalogInputPort& mCoreAnalogInputPort;
    int mChannel;

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
   * @brief Construct a new Core Analog Input Pin object
   * 
   * @param coreAnalogInputPort ADC Port
   * @param channel ADC通道
   */
  CoreAnalogInputPin(chip::core::CoreAnalogInputPort& coreAnalogInputPort, int channel);

  /**
   * @brief Destroy the Core Analog Input Pin object
   *
   */
  virtual ~CoreAnalogInputPin(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::AnalogInputPin
   */
 public:

  virtual int convert(void) override;

  virtual int getConvertLevel(void) override;

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

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_9B7A9BBD_8B78_4DFC_9C43_4949BE7E17B8 */
