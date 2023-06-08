/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8
#define AT32F415_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../tmr/package-info.h"
#include "hal/package-info.h"
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::core {
  class CoreTimer;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class at32f415::core::CoreTimer : public lang::Object,
                                  public hal::timer::Timer,
                                  public hal::InterruptEvent,
                                  public hal::timer::EventCancel,
                                  public hal::timer::EventTrigger {
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
  at32f415::tmr::Register& mReg;
  hal::timer::EventTrigger* mEventTrigger;
  hal::timer::EventCancel* mEventCancel;

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
   * @brief Construct a new Core Timer object
   *
   * @param reg
   */
  CoreTimer(at32f415::tmr::Register& reg);

  /**
   * @brief Destroy the Core Timer object
   *
   */
  virtual ~CoreTimer(void) override;

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
   * Public Method <Override> - hal::timer::Timer
   */
 public:
  virtual void cancel(void) override;

  virtual bool isBusy(void) override;

  virtual bool isDone(void) override;

  virtual void waitDone(void) override;

  virtual uint32_t getTimerClock(void) override;

  virtual bool startAtTick(uint32_t tick) override;

  virtual bool startAtTime(float second) override;
 
  virtual bool startAtHertz(float hertz) override;

  virtual void resetTick(uint32_t tick) override;

  virtual void setEventTrigger(hal::timer::EventTrigger* event) override;

  virtual void setEventCancel(hal::timer::EventCancel* event) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::timer::EventCencel
   */
 public:
  virtual void onTimerCancel(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::timer::EventCencel
   */
 public:
  virtual void onTimerTrigger(void) override;

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

#endif /* AT32F415_20B4C8B1_8FF1_45C9_8678_F51C7602D9A8 */
