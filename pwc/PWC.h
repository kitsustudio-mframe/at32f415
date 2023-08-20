/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B3F74285_D4AA_47C7_A7BA_F460F199D3C1
#define CHIP_B3F74285_D4AA_47C7_A7BA_F460F199D3C1

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../Processor.h"
#include "DeepSleepEnter.h"
#include "Flag.h"
#include "PvmVoltage.h"
#include "Register.h"
#include "Regulator.h"
#include "SleepEnter.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::pwc {
  class PWC;
  extern Register& PWC0;
}  // namespace chip::pwc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::pwc::PWC : public mframe::lang::Object {
  /* **************************************************************************************
   * Variable <Public>
   */

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
 public:
  PWC(void);

  virtual ~PWC(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  enable or disable access to the battery powered domain.
   * @param  newState: new state of battery powered domain access.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void batteryPoweredDomainAccess(bool newState) {
    PWC0.ctrl_bit.bpwen = newState;
    return;
  }

  /**
   * @brief  select the voltage threshold detected by the power voltage
   * detector.
   * @param  pvmVoltage: select pwc pvm voltage
   *         this parameter can be one of the following values:
   *         - VOLTAGE_2V3
   *         - VOLTAGE_2V4
   *         - VOLTAGE_2V5
   *         - VOLTAGE_2V6
   *         - VOLTAGE_2V7
   *         - VOLTAGE_2V8
   *         - VOLTAGE_2V9
   * @retval none
   */
  static inline void pvmLevelSelect(PvmVoltage pvmVoltage) {
    PWC0.ctrl_bit.pvmsel = static_cast<uint8_t>(pvmVoltage);
    return;
  }

  /**
   * @brief  enable or disable pwc power voltage monitor (pvm)
   * @param  new_state: new state of pvm.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void powerVoltageMonitorEnable(bool newState) {
    PWC0.ctrl_bit.pvmen = newState;
    return;
  }

  /**
   * @brief  enable or disable pwc standby wakeup pin
   * @param  pinNum: choose the wakeup pin.
   *         this parameter can be be any combination of the following values:
   *         - PWC_WAKEUP_PIN_1
   * @param  newState: new state of the standby wakeup pin.
   *         this parameter can be one of the following values:
   *         - TRUE <wakeup pin is used for wake up cpu from standby mode>
   *         - FALSE <wakeup pin is used for general purpose I/O>
   */
  static inline void wakeupPinEnable(uint32_t pinNum, bool newState) {
    if (newState)
      PWC0.ctrlsts |= pinNum;

    else
      PWC0.ctrlsts &= ~pinNum;

    return;
  }

  /**
   * @brief  clear flag of pwc
   * @param  flag: select the pwc flag.
   *         this parameter can be any combination of the following values:
   *         - PWC_WAKEUP_FLAG
   *         - PWC_STANDBY_FLAG
   *         - note:"PWC_PVM_OUTPUT_FLAG" cannot be choose!this bit is
   * readonly bit,it means the voltage monitoring output state
   * @retval none
   */
  static inline void flagClear(Flag flag) {
    if (static_cast<uint32_t>(flag) & static_cast<uint32_t>(Flag::STANDBY))
      PWC0.ctrl_bit.clsef = true;

    if (static_cast<uint32_t>(flag) & static_cast<uint32_t>(Flag::WAKEUP))
      PWC0.ctrl_bit.clswef = true;
  }

  /**
   * @brief  get flag of pwc
   * @param  flag: select the pwc flag.
   *         this parameter can be one of the following values:
   *         - PWC_WAKEUP_FLAG
   *         - PWC_STANDBY_FLAG
   *         - PWC_PVM_OUTPUT_FLAG
   * @retval state of select flag(SET or RESET).
   */
  static inline bool flagGet(Flag flag) {
    return (PWC0.ctrlsts & static_cast<uint32_t>(flag));
  }

  /**
   * @brief  regulate low power consumption in the deep sleep mode
   * @param  regulator: set the regulator state.
   *         this parameter can be one of the following values:
   *         - PWC_REGULATOR_ON
   *         - PWC_REGULATOR_LOW_POWER
   * @retval none
   */
  static inline void voltageRegulateSet(Regulator regulator) {
    PWC0.ctrl_bit.vrsel = static_cast<uint8_t>(regulator);
    return;
  }

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  static void reset(void);
  static void sleepModeEnter(SleepEnter sleepEnter);
  static void deepSleepModeEnter(DeepSleepEnter deepSleepEnter);
  static void standbyModeEnter(void);

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

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_B3F74285_D4AA_47C7_A7BA_F460F199D3C1 */
