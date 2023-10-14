/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_3B3265D7_1A90_4225_920F_1A2377378018
#define CHIP_3B3265D7_1A90_4225_920F_1A2377378018

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/crm/AutoStepMode.h"
#include "chip_arterytek_at32f415/crm/ClockOutSelect.h"
#include "chip_arterytek_at32f415/crm/CoreClock.h"
#include "chip_arterytek_at32f415/crm/DividerADC.h"
#include "chip_arterytek_at32f415/crm/DividerAHB.h"
#include "chip_arterytek_at32f415/crm/DividerAPB1.h"
#include "chip_arterytek_at32f415/crm/DividerAPB2.h"
#include "chip_arterytek_at32f415/crm/DividerClockOut.h"
#include "chip_arterytek_at32f415/crm/DividerHICK.h"
#include "chip_arterytek_at32f415/crm/DividerUSB.h"
#include "chip_arterytek_at32f415/crm/Flag.h"
#include "chip_arterytek_at32f415/crm/HickFrequencySCLK.h"
#include "chip_arterytek_at32f415/crm/Interrupt.h"
#include "chip_arterytek_at32f415/crm/MultPLL.h"
#include "chip_arterytek_at32f415/crm/PeriphClock.h"
#include "chip_arterytek_at32f415/crm/PeriphClockSleepMode.h"
#include "chip_arterytek_at32f415/crm/PeriphReset.h"
#include "chip_arterytek_at32f415/crm/PostDividerPLL.h"
#include "chip_arterytek_at32f415/crm/ReferenceClockPLL.h"
#include "chip_arterytek_at32f415/crm/Register.h"
#include "chip_arterytek_at32f415/crm/SourceClockCore.h"
#include "chip_arterytek_at32f415/crm/SourceClockERTC.h"
#include "chip_arterytek_at32f415/crm/SourceClockPLL.h"
#include "chip_arterytek_at32f415/crm/SourceClockSCLK.h"
#include "chip_arterytek_at32f415/crm/SourceClockUSB.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::crm {
  class CRM;
  extern Register& CRM0;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::crm::CRM : public mframe::lang::Object {
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
   * @brief Construct a new CRM object
   *
   */
  CRM(void) = default;

  /**
   * @brief Destroy the CRM object
   *
   */
  virtual ~CRM(void) override = default;

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
 public:
  static const uint32_t HEXT_STARTUP_TIMEOUT = 0x00003000;
  static const uint32_t HICK_VALUE = 8000000;
  static const uint32_t HEXT_VALUE = 8000000;

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  enable or disable crm low speed external crystal bypass
   * @param  newState (true or false)
   * @return none
   */
  static inline void lextBypass(bool newState) {
    CRM0.bpdc_bit.lextbyps = newState;
  }

  /**
   * @brief  enable or disable crm high speed external crystal bypass
   * @param  newState (true or false)
   * @return none
   */
  static inline void hextBypass(bool newState) {
    CRM0.ctrl_bit.hextbyps = newState;
  }

  /**
   * @brief  set the hick trimming value
   * @param  trimValue (0x00~0x3F)
   * @return none
   */
  static inline void hickClockTrimmingSet(uint8_t trimValue) {
    CRM0.ctrl_bit.hicktrim = trimValue;
  }

  /**
   * @brief  select ertc clock
   * @param  value
   *         this parameter can be one of the following values:
   *         - SourceClockERTC::CLOCK_LEXT
   *         - SourceClockERTC::CLOCK_LICK
   *         - SourceClockERTC::CLOCK_HEXT_DIV
   * @return none
   */
  static inline void ertcClockSelect(SourceClockERTC value) {
    CRM0.bpdc_bit.ertcsel = static_cast<uint8_t>(value);
    return;
  }

  /**
   * @brief  enable or disable ertc
   * @param  newState (true or false)
   * @return none
   */
  static inline void ertcClockEnable(bool newState) {
    CRM0.bpdc_bit.ertcen = newState;
  }

  /**
   * @brief  set crm ahb division
   * @param  value
   *         this parameter can be one of the following values:
   *         - DividerAHB::DIV1
   *         - DividerAHB::DIV2
   *         - DividerAHB::DIV4
   *         - DividerAHB::DIV8
   *         - DividerAHB::DIV16
   *         - DividerAHB::DIV64
   *         - DividerAHB::DIV128
   *         - DividerAHB::DIV256
   *         - DividerAHB::DIV512
   * @return none
   */
  static inline void ahbDivSet(DividerAHB value) {
    CRM0.cfg_bit.ahbdiv = static_cast<uint8_t>(value);
  }

  /**
   * @brief  set crm apb1 division
   * @param  value
   *         this parameter can be one of the following values:
   *         - DividerAPB1::DIV1
   *         - DividerAPB1::DIV2
   *         - DividerAPB1::DIV4
   *         - DividerAPB1::DIV8
   *         - DividerAPB1::DIV16
   * @return none
   */
  static inline void apb1DivSet(DividerAPB1 value) {
    CRM0.cfg_bit.apb1div = static_cast<uint8_t>(value);
  }

  /**
   * @brief  set crm apb2 division
   * @param  value
   *         this parameter can be one of the following values:
   *         -  DividerAPB2::DIV1
   *         -  DividerAPB2::DIV2
   *         -  DividerAPB2::DIV4
   *         -  DividerAPB2::DIV8
   *         -  DividerAPB2::DIV16
   * @return none
   */
  static inline void apb2DivSet(DividerAPB2 value) {
    CRM0.cfg_bit.apb2div = static_cast<uint8_t>(value);
  }

  /**
   * @brief  select system clock source
   * @param  value
   *         this parameter can be one of the following values:
   *         - SourceClockSCLK::HICK
   *         - SourceClockSCLK::HEXT
   *         - SourceClockSCLK::PLL
   * @return none
   */
  static void sysclkSwitch(SourceClockSCLK value) {
    CRM0.cfg_bit.sclksel = static_cast<uint8_t>(value);
    return;
  }

  /**
   * @brief  indicate which clock source is used as system clock
   * @param  none
   * @return crm_sclk
   *         this return can be one of the following values:
   *         - SourceClockSCLK::HIC
   *         - SourceClockSCLK::HEX
   *         - SourceClockSCLK::PLL
   */
  static inline SourceClockSCLK sysclkSwitchStatusGet(void) {
    return static_cast<SourceClockSCLK>(CRM0.cfg_bit.sclksts);
  }

  /**
   * @brief  set crm clkout division
   * @param  clkout_div
   *         this parameter can be one of the following values:
   *         - DividerClockOut::DIV1
   *         - DividerClockOut::DIV2
   *         - DividerClockOut::DIV4
   *         - DividerClockOut::DIV8
   *         - DividerClockOut::DIV16
   *         - DividerClockOut::DIV64
   *         - DividerClockOut::DIV128
   *         - DividerClockOut::DIV256
   *         - DividerClockOut::DIV512
   * @return none
   */
  static inline void clkoutDivSet(DividerClockOut clkoutDiv) {
    CRM0.misc1_bit.clkoutdiv = static_cast<uint8_t>(clkoutDiv);
  }

  /**
   * @brief  enable or disable otgfs end-point3 remap, only available in at32f415xx revision C.
   *         at32f415xx revision B: (not support)
   *         do not support configuration ep3 remap.
   *
   *         at32f415xx revision C: (support)
   *         support configuration ep3 remap.
   * @return none
   */
  static inline void otgfsEp3RemapEnable(bool newState) {
    CRM0.otg_extctrl_bit.ep3_rmpen = newState;
  }

  /**
   * @brief  usb divider reset, only available in at32f415xx revision C.
   *         at32f415xx revision B: (not support)
   *         usb divider(CRM_CFG[usbdiv]) do not support to be reset.
   *
   *         at32f415xx revision C: (support)
   *         usb divider(CRM_CFG[usbdiv]) support to be reset.
   * @param  newState (true or false)
   * @return none
   */
  static inline void usbdivReset(bool newState) {
    CRM0.otg_extctrl_bit.usbdivrst = newState;
  }

  /**
   * @brief  reset the crm register
   * @param  none
   * @return none
   */
  static void reset(void);
  /**
   * @brief  get crm flag status
   * @param  flag
   *         this parameter can be one of the following values:
   *         - Flag::HICK_STABLE
   *         - Flag::HEXT_STABLE
   *         - Flag::PLL_STABLE
   *         - Flag::LEXT_STABLE
   *         - Flag::LICK_STABLE
   *         - Flag::NRST_RESET
   *         - Flag::POR_RESET
   *         - Flag::SW_RESET
   *         - Flag::WDT_RESET
   *         - Flag::WWDT_RESET
   *         - Flag::LOWPOWER_RESET
   *         interrupt flag:
   *         - Flag::LICK_READY_INT
   *         - Flag::LEXT_READY_INT
   *         - Flag::HICK_READY_INT
   *         - Flag::HEXT_READY_INT
   *         - Flag::PLL_READY_INT
   *         - Flag::CLOCK_FAILURE_INT
   * @return flag_status
   */
  static bool flagGet(Flag flag);

  /**
   * @brief  wait for hext stable
   * @param  none
   * @return error_status (ERROR or SUCCESS)
   */
  static bool hextStableWait(void);

  /**
   * @brief  set the crm calibration value
   * @param  cali_value (0x00~0xFF)
   * @return none
   */
  static void hickClockCalibrationSet(uint8_t caliValue);

  /**
   * @brief  enable or disable the peripheral clock
   * @param  value
   *         this parameter can be one of the following values:
   *         - PeriphClock::CLOCK_DMA1         - PeriphClock::CLOCK_DMA2         - PeriphClock::CLOCK_CRC         - PeriphClock::CLOCK_SDIO1
   *         - PeriphClock::CLOCK_OTGFS1       - PeriphClock::CLOCK_IOMUX        - PeriphClock::CLOCK_GPIOA       - PeriphClock::CLOCK_GPIOB
   *         - PeriphClock::CLOCK_GPIOC        - PeriphClock::CLOCK_GPIOD        - PeriphClock::CLOCK_GPIOF       - PeriphClock::CLOCK_ADC1
   *         - PeriphClock::CLOCK_TMR1         - PeriphClock::CLOCK_SPI1         - PeriphClock::CLOCK_USART1      - PeriphClock::CLOCK_TMR9
   *         - PeriphClock::CLOCK_TMR10        - PeriphClock::CLOCK_TMR11        - PeriphClock::CLOCK_TMR2        - PeriphClock::CLOCK_TMR3
   *         - PeriphClock::CLOCK_TMR4         - PeriphClock::CLOCK_TMR5         - PeriphClock::CLOCK_TMR9
   *         - PeriphClock::CLOCK_TMR10        - PeriphClock::CLOCK_TMR11        - PeriphClock::CLOCK_CMP         - PeriphClock::CLOCK_WWDT
   *         - PeriphClock::CLOCK_SPI2         - PeriphClock::CLOCK_USART2       - PeriphClock::CLOCK_USART3      - PeriphClock::CLOCK_UART4
   *         - PeriphClock::CLOCK_UART5        - PeriphClock::CLOCK_I2C1         - PeriphClock::CLOCK_I2C2        - PeriphClock::CLOCK_CAN1
   *         - PeriphClock::CLOCK_PWC
   * @param  newState (true or false)
   * @return none
   */
  static void periphClockEnable(PeriphClock value, bool newState);

  /**
   * @brief  get peripheral clock is enable or disable
   * @param  value
   *         this parameter can be one of the following values:
   *         - PeriphClock::CLOCK_DMA1         - PeriphClock::CLOCK_DMA2         - PeriphClock::CLOCK_CRC         - PeriphClock::CLOCK_SDIO1
   *         - PeriphClock::CLOCK_OTGFS1       - PeriphClock::CLOCK_IOMUX        - PeriphClock::CLOCK_GPIOA       - PeriphClock::CLOCK_GPIOB
   *         - PeriphClock::CLOCK_GPIOC        - PeriphClock::CLOCK_GPIOD        - PeriphClock::CLOCK_GPIOF       - PeriphClock::CLOCK_ADC1
   *         - PeriphClock::CLOCK_TMR1         - PeriphClock::CLOCK_SPI1         - PeriphClock::CLOCK_USART1      - PeriphClock::CLOCK_TMR9
   *         - PeriphClock::CLOCK_TMR10        - PeriphClock::CLOCK_TMR11        - PeriphClock::CLOCK_TMR2        - PeriphClock::CLOCK_TMR3
   *         - PeriphClock::CLOCK_TMR4         - PeriphClock::CLOCK_TMR5         - PeriphClock::CLOCK_TMR9
   *         - PeriphClock::CLOCK_TMR10        - PeriphClock::CLOCK_TMR11        - PeriphClock::CLOCK_CMP         - PeriphClock::CLOCK_WWDT
   *         - PeriphClock::CLOCK_SPI2         - PeriphClock::CLOCK_USART2       - PeriphClock::CLOCK_USART3      - PeriphClock::CLOCK_UART4
   *         - PeriphClock::CLOCK_UART5        - PeriphClock::CLOCK_I2C1         - PeriphClock::CLOCK_I2C2        - PeriphClock::CLOCK_CAN1
   *         - PeriphClock::CLOCK_PWC
   * @return none
   */
  static bool getPeriphClockEnable(PeriphClock value);

  /**
   * @brief  enable or disable the peripheral reset
   * @param  value
   *         this parameter can be one of the following values:
   *         - PeriphReset::RESET_IOMUX        - PeriphReset::RESET_EXINT        - PeriphReset::RESET_GPIOA       - PeriphReset::RESET_GPIOB
   *         - PeriphReset::RESET_GPIOC        - PeriphReset::RESET_GPIOD        - PeriphReset::RESET_GPIOF       - PeriphReset::RESET_ADC1
   *         - PeriphReset::RESET_TMR1         - PeriphReset::RESET_SPI1         - PeriphReset::RESET_USART1      - PeriphReset::RESET_TMR9
   *         - PeriphReset::RESET_TMR10        - PeriphReset::RESET_TMR11        - PeriphReset::RESET_TMR2        - PeriphReset::RESET_TMR3
   *         - PeriphReset::RESET_TMR4         - PeriphReset::RESET_TMR5         - PeriphReset::RESET_CMP         - PeriphReset::RESET_WWDT
   *         - PeriphReset::RESET_SPI2         - PeriphReset::RESET_USART2       - PeriphReset::RESET_USART3      - PeriphReset::RESET_UART4
   *         - PeriphReset::RESET_UART5        - PeriphReset::RESET_I2C1         - PeriphReset::RESET_I2C2        - PeriphReset::RESET_CAN1
   *         - PeriphReset::RESET_PWC          - PeriphReset::RESET_OTGFS1
   * @param  newState (true or false)
   * @return none
   */
  static void periphReset(PeriphReset value, bool newState);

  /**
   * @brief  enable or disable the peripheral clock in sleep mode
   * @param  value
   *         this parameter can be one of the following values:
   *         - CRM_SRAM_PERIPH_CLOCK_SLEEP_MODE
   *         - CRM_FLASH_PERIPH_CLOCK_SLEEP_MODE
   * @param  newState (true or false)
   * @return none
   */
  static void periphSleepModeClockEnable(PeriphClockSleepMode value, bool newState);

  /**
   * @brief  enable or disable the crm clock source
   * @param  source
   *         this parameter can be one of the following values:
   *         - SourceClockCore::CLOCL_HICK
   *         - SourceClockCore::CLOCL_HEXT
   *         - SourceClockCore::CLOCL_PLL
   *         - SourceClockCore::CLOCL_LEXT
   *         - SourceClockCore::CLOCL_LICK
   * @param  newState (true or false)
   * @return none
   */
  static void clockSourceEnable(SourceClockCore source, bool newState);

  /**
   * @brief  clear the crm reset flags
   * @param  flag
   *         this parameter can be one of the following values:
   *         reset flag:
   *         - Flag::NRST_RESET
   *         - Flag::POR_RESET
   *         - Flag::SW_RESET
   *         - Flag::WDT_RESET
   *         - Flag::WWDT_RESET
   *         - Flag::LOWPOWER_RESET
   *         - Flag::ALL_RESET
   *         interrupt flag:
   *         - Flag::LICK_READY_INT
   *         - Flag::LEXT_READY_INT
   *         - Flag::HICK_READY_INT
   *         - Flag::HEXT_READY_INT
   *         - Flag::PLL_READY_INT
   *         - Flag::CLOCK_FAILURE_INT
   * @return none
   */
  static void flagClear(Flag flag);

  /**
   * @brief  set crm adc division
   * @param  value
   *         this parameter can be one of the following values:
   *         - DividerADC::DIV2
   *         - DividerADC::DIV4
   *         - DividerADC::DIV6
   *         - DividerADC::DIV8
   *         - DividerADC::DIV12
   *         - DividerADC::DIV16
   * @return none
   */
  static void adcClockDivSet(DividerADC divValue);

  /**
   * @brief  set crm usb division
   * @param  value
   *         this parameter can be one of the following values:
   *         - DividerUSB::DIV1_5
   *         - DividerUSB::DIV1
   *         - DividerUSB::DIV2_5
   *         - DividerUSB::DIV2
   *         - DividerUSB::DIV3_5
   *         - DividerUSB::DIV3
   *         - DividerUSB::DIV4
   * @return none
   */
  static void usbClockDivSet(DividerUSB divValue);

  /**
   * @brief  enable or disable clock failure detection
   * @param  newState (true or false)
   * @return none
   */
  static inline void clockFailureDetectionEnable(bool newState) {
    CRM0.ctrl_bit.cfden = newState;
  }

  /**
   * @brief  battery powered domain software reset
   * @param  newState (true or false)
   * @return none
   */
  static void batteryPoweredDomainReset(bool newState) {
    CRM0.bpdc_bit.bpdrst = newState;
  }

  /**
   * @brief  config crm pll
   * @param  clock_source
   *         this parameter can be one of the following values:
   *         - SourceClockPLL::HICK
   *         - SourceClockPLL::HEXT
   *         - SourceClockPLL::HEXT_DIV
   * @param  mult_value (CRM_PLL_MULT_2~64)
   * @return none
   */
  static void pllConfig(SourceClockPLL clockSource, MultPLL multValue);

  /**
   * @brief  config crm pll function2, another method.
   *                        pll_rcs_freq * pll_ns
   *         pll clock = --------------------------------
   *                           pll_ms * pll_fr_n
   *         attemtion:
   *                  31 <= pll_ns <= 500
   *                  1  <= pll_ms <= 15
   *
   *                       pll_rcs_freq
   *         2mhz <=  ---------------------- <= 16mhz
   *                          pll_ms
   *
   *                       pll_rcs_freq * pll_ns
   *         500mhz <=  -------------------------------- <= 1000mhz
   *                               pll_ms
   * @param  clock_source
   *         this parameter can be one of the following values:
   *         - SourceClockPLL::HICK
   *         - SourceClockPLL::HEXT
   *         - SourceClockPLL::HEXT_DIV
   * @param  pll_ns (31~500)
   * @param  pll_ms (1~15)
   * @param  pll_fr
   *         this parameter can be one of the following values:
   *         - PostDividerPLL::DIV1
   *         - PostDividerPLL::DIV2
   *         - PostDividerPLL::DIV4
   *         - PostDividerPLL::DIV8
   *         - PostDividerPLL::DIV16
   *         - PostDividerPLL::DIV32
   * @return none
   */
  static void pllConfig2(SourceClockPLL clockSource, uint16_t pll_ns, uint16_t pllMs, PostDividerPLL pllFr);

  /**
   * @brief  get crm clocks freqency
   * @param  clocks
   *         - pointer to the crm_clocks_freq structure
   * @return none
   */
  static void clocksFreqGet(CoreClock& coreClock);

  /**
   * @brief  set crm clkout
   * @param  clkout
   *         this parameter can be one of the following values:
   *         - ClockOutSelect::SELECT_NOCLK
   *         - ClockOutSelect::SELECT_LICK
   *         - ClockOutSelect::SELECT_LEXT
   *         - ClockOutSelect::SELECT_SCLK
   *         - ClockOutSelect::SELECT_HICK
   *         - ClockOutSelect::SELECT_HEXT
   *         - ClockOutSelect::SELECT_PLL_DIV_2
   *         - ClockOutSelect::SELECT_PLL_DIV_4
   *         - ClockOutSelect::SELECT_USB
   *         - ClockOutSelect::SELECT_ADC
   * @return none
   */
  static void clockOutSet(ClockOutSelect clkout);

  /**
   * @brief  config crm interrupt
   * @param  int
   *         this parameter can be any combination of the following values:
   *         - Interrupt::LICK_STABLE
   *         - Interrupt::LEXT_STABLE
   *         - Interrupt::HICK_STABLE
   *         - Interrupt::HEXT_STABLE
   *         - Interrupt::PLL_STABLE
   * @param  newState (true or false)
   * @return none
   */
  static inline void interruptEnable(Interrupt interrupt, bool newState) {
    if (newState)
      CRM0.clkint |= static_cast<uint32_t>(interrupt);

    else

      CRM0.clkint &= ~static_cast<uint32_t>(interrupt);
  }

  /**
   * @brief  auto step clock switch enable
   * @param  newState (true or false)
   * @return none
   */
  static void autoStepModeEnable(bool newState) {
    if (newState == true)
      CRM0.misc2_bit.auto_step_en = static_cast<bool>(AutoStepMode::ENABLE);

    else
      CRM0.misc2_bit.auto_step_en = static_cast<bool>(AutoStepMode::DISABLE);

    return;
  }

  /**
   * @brief  config hick divider select
   * @param  value
   *         this parameter can be one of the following values:
   *         - DividerHICK::DIV6
   *         - DividerHICK::NODIV
   * @return none
   */
  static void hickDividerSelect(DividerHICK value) {
    CRM0.misc1_bit.hickdiv = static_cast<uint8_t>(value);
    return;
  }

  /**
   * @brief  hick as system clock frequency select
   * @param  value
   *         this parameter can be one of the following values:
   *         - HickFrequencySCLK::HICK_8MHZ
   *         - HickFrequencySCLK::HICK_48MHZ
   * @return none
   */
  static void hickSclkFrequencySelect(HickFrequencySCLK value);

  /**
   * @brief  usb 48 mhz clock source select
   * @param  value
   *         this parameter can be one of the following values:
   *         - SourceClockUSB::SOURCE_PLL
   *         - SourceClockUSB::SOURCE_HICK
   * @return none
   */
  static void usbClockSourceSelect(SourceClockUSB value);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_3B3265D7_1A90_4225_920F_1A2377378018 */
