/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1
#define CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/gpio/PinsSource.h"
#include "chip_arterytek_at32f415/gpio/PortSource.h"
#include "chip_arterytek_at32f415/gpio/iomux/PinMap.h"
#include "chip_arterytek_at32f415/gpio/iomux/Register.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio::iomux {
  class IOMUX;
  extern Register& IOMUX0;
}  // namespace chip::gpio::iomux

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::gpio::iomux::IOMUX : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new IOMUX object
   * 
   */
  IOMUX(void);

  /**
   * @brief Destroy the IOMUX object
   * 
   */
  virtual ~IOMUX(void) override;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Static Variable
   */
  
  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  enable or disable the event output.
   * @param  confirm_state: new state of the event output.
   *         this parameter can be: TRUE or FALSE.
   * @return none
   */
  static void eventOutputEnable(bool newState) {
    IOMUX0.evtout_bit.evoen = newState;
    return;
  }

  /**
   * @brief  reset the mux functions (remap, event control
   *         and exint configuration) registers to their default values.
   * @param  none
   * @return none
   */
  static void iomuxReset(void);

  /**
   * @brief  select the gpio pin used as event output.
   * @param  gpio_port_source: select the gpio port to be used as source
   *         for event output.
   * @param  gpio_pin_source: specifies the pin for the event output.
   * @return none
   */
  static void eventOutputConfig(chip::gpio::PortSource portSource,
                                chip::gpio::PinsSource pinsSource);

  /**
   * @brief  select the gpio pin used as exint line.
   * @param  portSource: select the gpio port to be used as source for exint.
   * @param  pinsSource: specifies the pin for the event output.
   * @return none
   */
  static void exintLineConfig(chip::gpio::PortSource portSource,
                              chip::gpio::PinsSource pinsSource);

  /**
   * @brief  iomux remap and debug i/o configuration.
   * @param  pinMap: select the pin to remap.
   * @param  newState: (TRUE or FALSE)
   * @return none
   */
  static void pinRemapConfig(chip::gpio::iomux::PinMap pinMap, bool newState);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_B95F5BE8_5089_41DA_BA22_58C3A0EBF8A1 */
