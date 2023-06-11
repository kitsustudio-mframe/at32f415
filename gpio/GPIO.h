/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33
#define CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../AT32F415.h"
#include "./../crm/PeriphClock.h"
#include "./../crm/PeriphReset.h"
#include "./../gpio/DriveMode.h"
#include "./../gpio/Mode.h"
#include "./../gpio/OutputMode.h"
#include "./../gpio/PinConfig.h"
#include "./../gpio/Pins.h"
#include "./../gpio/PinsSource.h"
#include "./../gpio/PortSource.h"
#include "./../gpio/PullMode.h"
#include "./../gpio/Register.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::gpio {
  class GPIO;
  extern Register& GPIOA;
  extern Register& GPIOB;
  extern Register& GPIOC;
  extern Register& GPIOD;
  extern Register& GPIOF;
}  // namespace chip::gpio

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::gpio::GPIO {
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
  GPIO(void) = default;

  virtual ~GPIO(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  read the specified input port pin.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @retval flag_status (SET or RESET)
   */
  static inline bool inputDataBitRead(Register& reg, Pins pins) {
    return (reg.idt & static_cast<uint32_t>(pins));
  }

  /**
   * @brief  read the specified gpio input data port.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @retval gpio input data port value.
   */
  static inline uint16_t inputDataRead(Register& reg) {
    return static_cast<uint16_t>(reg.idt);
  }

  /**
   * @brief  read the specified output port pin.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @return
   */
  static inline bool outputDataBitRead(Register& reg, Pins pins) {
    return (reg.odt & static_cast<uint32_t>(pins));
  }

  /**
   * @brief  read the specified gpio ouput data port.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @retval gpio input data port value.
   */
  static inline uint16_t outputDataRead(Register& reg) {
    return static_cast<uint16_t>(reg.odt);
  }

  /**
   * @brief  set the selected data port bits.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @retval none
   */
  static inline void bitsSet(Register& reg, Pins pins) {
    reg.scr = static_cast<uint16_t>(pins);
    return;
  }

  /**
   * @brief  clear the selected data port bits.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @retval none
   */
  static inline void bitsReset(Register& reg, Pins pins) {
    reg.scr = static_cast<uint16_t>(pins);
  }

  /**
   * @brief  set or clear the selected data port bit.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @param  bit_state: specifies the value to be written to the selected bit (TRUE or FALSE).
   * @retval none
   */
  static inline void bitsWrite(Register& reg, Pins pins, bool bitState) {
    if (bitState)
      reg.scr = static_cast<uint16_t>(pins);

    else
      reg.clr = static_cast<uint16_t>(pins);

    return;
  }

  /**
   * @brief  write data to the specified gpio data port.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  port_value: specifies the value to be written to the port output data register.
   * @retval none
   */
  static void portWirte(Register& reg, uint16_t portValue) {
    reg.odt = portValue;
    return;
  }

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  reset the gpio register
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @retval none
   */
  static void reset(Register& reg);

  /**
   * @brief  initialize the gpio peripheral.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  gpio_init_struct: pointer to gpio init structure.
   * @retval none
   */
  static void init(Register& reg, PinConfig& pinConfig);

  /**
   * @brief  fill each gpio_init_type member with its default value.
   * @param  gpio_init_struct : pointer to a gpio_init_type structure which will be initialized.
   * @retval none
   */
  static void defaultParaInit(PinConfig& pinConfig);

  /**
   * @brief  write protect gpio pins configuration registers.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @retval none
   */
  static void pinWpConfig(Register& reg, Pins pins);

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

#endif /* CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33 */
