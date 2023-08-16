/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_A629664E_EFF8_40C4_BB37_2B3051B29D75
#define CHIP_A629664E_EFF8_40C4_BB37_2B3051B29D75

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::core {
  class CoreAnalogInputPort;
}  // namespace chip::core

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::core::CoreAnalogInputPort : public mframe::lang::Object,
                                        public mframe::hal::AnalogInputPort,
                                        public mframe::hal::InterruptEvent {
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
  int mResult[16];
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
   * @brief Construct a new Core Analog Input Port object
   *
   */
  CoreAnalogInputPort(void);

  /**
   * @brief Destroy the Core Analog Input Port object
   *
   */
  virtual ~CoreAnalogInputPort(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::AnalogInputPort
   */
 public:
  virtual int read(int channel) override;

  virtual int getConvertLevel(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::Base
   */
 public:
  virtual bool deinit(void) override;

  virtual bool init(void) override;

  virtual bool isInit(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 設定ADC轉換取樣時間
   *
   * @param channel 通道
   * @param sampleTime 取樣時間
   * @return true 設定成功
   * @return false 設定失敗，可能為未知的通道
   */
  virtual bool setSampleTime(int channel, chip::adc::SampleTime sampleTime);

  /**
   * @brief ADC校正。
   *
   * @return true 校正成功。
   * @return false 校正失敗，可能ADC尚未啟用或是忙碌。
   */
  virtual bool calibration(void);

  /**
   * @brief ADC啟用。
   *
   * @return true 啟用成功。
   * @return false 啟用失敗，可能ADC已經啟用或是尚未初始化。
   */
  virtual bool enable(void);

  /**
   * @brief ADC停用。
   *
   * @return true 停用成功。
   * @return false 停用失敗，可能ADC尚未啟用或是尚未初始化。
   */
  virtual bool disable(void);

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

#endif /* CHIP_A629664E_EFF8_40C4_BB37_2B3051B29D75 */
