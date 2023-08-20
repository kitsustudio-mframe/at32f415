/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1
#define CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"
#define USING_CHIP_GPIO
#include "chip.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::gpio::iomux {
  class IOMUX;
  extern Register& IOMUX0;
}  // namespace chip::gpio::iomux

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::gpio::iomux::IOMUX : public mframe::lang::Object {
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
  IOMUX(void);

  virtual ~IOMUX(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  enable or disable the event output.
   * @param  confirm_state: new state of the event output.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static void eventOutputEnable(bool newState) {
    IOMUX0.evtout_bit.evoen = newState;
    return;
  }

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  reset the mux functions (remap, event control
   *         and exint configuration) registers to their default values.
   * @param  none
   * @retval none
   */
  static void iomuxReset(void);

  /**
   * @brief  select the gpio pin used as event output.
   * @param  gpio_port_source: select the gpio port to be used as source
   *         for event output.
   * @param  gpio_pin_source: specifies the pin for the event output.
   * @retval none
   */
  static void eventOutputConfig(PortSource portSource, PinsSource pinsSource);

  /**
   * @brief  select the gpio pin used as exint line.
   * @param  portSource: select the gpio port to be used as source for exint.
   * @param  pinsSource: specifies the pin for the event output.
   */
  static void exintLineConfig(PortSource portSource, PinsSource pinsSource);

  /**
   * @brief  iomux remap and debug i/o configuration.
   * @param  pinMap: select the pin to remap.
   * @param  newState: (TRUE or FALSE)
   * @retval none
   */
  static void pinRemapConfig(PinMap pinMap, bool newState);
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

#endif /* CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1 */
