/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_25C7B452_0536_494F_9927_E6F526433BAC
#define AT32F415_25C7B452_0536_494F_9927_E6F526433BAC

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../usart/package-info.h"
#include "hal/package-info.h"
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::core {
  class CoreUSART;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class at32f415::core::CoreUSART : public lang::Object,
                                  public hal::usart::USART,
                                  public hal::InterruptEvent,
                                  public hal::usart::EventTransfer,
                                  public hal::usart::EventReceiver {
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
  at32f415::usart::Register& mReg;
  hal::usart::EventTransfer* mEventTransfer;
  hal::usart::EventReceiver* mEventReceiver;
  uint32_t mBaudrate;

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
   * @brief Construct a new Core USART object
   *
   * @param reg
   */
  CoreUSART(at32f415::usart::Register& reg);

  /**
   * @brief Destroy the Core USART object
   *
   */
  virtual ~CoreUSART(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - hal::Base
   */
 public:
  virtual bool deinit(void) override;

  virtual bool init(void) override;

  virtual bool isInit(void) override;
  /* **************************************************************************************
   * Public Method <Override> - hal::usart::USART
   */
 public:
  virtual uint32_t setBaudrate(uint32_t baudrate) override;

  virtual uint32_t getBaudrate(void) override;

  virtual void beginTransfer(bool enable) override;

  virtual void beginReceiver(bool enable) override;

  virtual void setEventTransfer(hal::usart::EventTransfer* event) override;

  virtual void setEventReceiver(hal::usart::EventReceiver* event) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::usart::EventReceiver
   */
 public:
  virtual bool onUartReceiver(const uint8_t data) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::usart::EventTransfer
   */
 public:
  virtual bool onUartTransfer(uint8_t& data) override;
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

#endif /* AT32F415_25C7B452_0536_494F_9927_E6F526433BAC */
