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
public mframe::hal::AnalogInputPort {
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
    uint16_t mValue[16];

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
  /**
   * @brief
   *
   * @param pin
   * @return int
   */
  virtual int read(int channel) override;

  /**.
   * @brief Get the adc convert bit.
   *
   * @return int
   */
  virtual int getConvertLevel(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mframe::hal::Base
   */
 public:
  /**
   * @brief 硬體去初始化。
   *
   * @return true 去初始化成功。
   * @return false 去初始化失敗，可能原因如下：
   * - 設備尚未初始化。
   * - 設備異常。
   */
  virtual bool deinit(void) override;

  /**
   * @brief 硬體初始化。
   *
   * @return true 初始化成功
   * @return false 初始化失敗，可能原因如下：
   * - 設備已經初始化。
   * - 設備異常。
   */
  virtual bool init(void) override;

  /**
   * @brief 取得硬體是否已初始化。
   *
   * @return true 設備上會初始化。
   * @return false 設備已經初始化。
   */
  virtual bool isInit(void) override;

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

#endif /* CHIP_A629664E_EFF8_40C4_BB37_2B3051B29D75 */
