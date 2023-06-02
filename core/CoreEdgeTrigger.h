/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0
#define AT32F415_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../exint/package-info.h"
#include "hal/package-info.h"
#include "lang/package-info.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::core {
  class CoreEdgeTrigger;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class at32f415::core::CoreEdgeTrigger : public lang::Object,
                                        public hal::trigger::EdgeTrigger,
                                        public hal::InterruptEvent,
                                        public hal::trigger::EventFall,
                                        public hal::trigger::EventRise {
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
  hal::trigger::EventRise* mEventRise;
  hal::trigger::EventFall* mEventFall;
  at32f415::exint::Line mLine;
  bool mStatusRise;
  bool mStatusFall;

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
   * @brief Construct a new Core Edge Trigger object
   *
   * @param line
   */
  CoreEdgeTrigger(at32f415::exint::Line line);

  /**
   * @brief Destroy the Core Edge Trigger object
   *
   */
  virtual ~CoreEdgeTrigger(void) override;

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
   * Public Method <Override> - hal::trigger::EdgeTrigger
   */
 public:
  virtual void enableAll(bool enable) override;

  virtual void enableFall(bool enable) override;

  virtual void enableRise(bool enable) override;

  virtual void setEventRise(hal::trigger::EventRise* event) override;

  virtual void setEventFall(hal::trigger::EventFall* event) override;

  virtual bool readRise(void) override;

  virtual bool readFall(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::InterruptEvent
   */
 public:
  virtual void interruptEvent(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::trigger::EventFall
   */
 public:
  virtual void onEdgeTriggerFall(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::trigger::EventRise
   */
 public:
  virtual void onEdgeTriggerRise(void) override;

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

#endif /* AT32F415_03434AE2_6EA9_4B98_8C25_5E12DC94E3B0 */
