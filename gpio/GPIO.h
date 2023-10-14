/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33
#define CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/gpio/DriveMode.h"
#include "chip_arterytek_at32f415/gpio/GPIO.h"
#include "chip_arterytek_at32f415/gpio/Mode.h"
#include "chip_arterytek_at32f415/gpio/OutputMode.h"
#include "chip_arterytek_at32f415/gpio/PinConfig.h"
#include "chip_arterytek_at32f415/gpio/Pins.h"
#include "chip_arterytek_at32f415/gpio/PinsSource.h"
#include "chip_arterytek_at32f415/gpio/PortSource.h"
#include "chip_arterytek_at32f415/gpio/PullMode.h"
#include "chip_arterytek_at32f415/gpio/Register.h"

/* ****************************************************************************
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

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::gpio::GPIO {
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
   * @brief Construct a new GPIO object
   *
   */
  GPIO(void) = default;

  /**
   * @brief Destroy the GPIO object
   *
   */
  virtual ~GPIO(void) = default;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  read the specified input port pin.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @return flag_status (SET or RESET)
   */
  static inline bool inputDataBitRead(Register& reg, Pins pins) {
    return (reg.idt & static_cast<uint32_t>(pins));
  }

  /**
   * @brief  read the specified gpio input data port.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @return gpio input data port value.
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
   * @return gpio input data port value.
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
   * @return none
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
   * @return none
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
   * @return none
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
   * @return none
   */
  static void portWirte(Register& reg, uint16_t portValue) {
    reg.odt = portValue;
    return;
  }

  /**
   * @brief  reset the gpio register
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @return none
   */
  static void reset(Register& reg);

  /**
   * @brief  initialize the gpio peripheral.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  gpio_init_struct: pointer to gpio init structure.
   * @return none
   */
  static void init(Register& reg, PinConfig& pinConfig);

  /**
   * @brief  fill each gpio_init_type member with its default value.
   * @param  gpio_init_struct : pointer to a gpio_init_type structure which will be initialized.
   * @return none
   */
  static void defaultParaInit(PinConfig& pinConfig);

  /**
   * @brief  write protect gpio pins configuration registers.
   * @param  reg: to select the gpio peripheral.
   *         this parameter can be one of the following values:
   *         GPIOA, GPIOB, GPIOC, GPIOD, GPIOF.
   * @param  pins: gpio pin number
   * @return none
   */
  static void pinWpConfig(Register& reg, Pins pins);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_C53C5B22_4DD0_47EE_84ED_09DCE17C5F33 */
