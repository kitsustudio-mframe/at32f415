/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_39BF0942_072C_4AB3_9CBC_16781034D7F9
#define CHIP_39BF0942_072C_4AB3_9CBC_16781034D7F9

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../AT32F415.h"
#include "./../flash/Flag.h"
#include "./../flash/Interrupt.h"
#include "./../flash/Register.h"
#include "./../flash/Status.h"
#include "./../flash/Timeout.h"
#include "./../flash/WaitCycle.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::flash {
  class FLASH;
  extern Register &FLASH0;
}  // namespace chip::flash

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::flash::FLASH : public mframe::lang::Object {
  /* **************************************************************************************
   * Variable <Public>
   */
 public:
  static const uint32_t FLASH_UNLOCK_KEY1 = 0x45670123; /*!< flash operation unlock order key1 */
  static const uint32_t FLASH_UNLOCK_KEY2 = 0xCDEF89AB; /*!< flash operation unlock order key2 */
  static const uint16_t FAP_RELIEVE_KEY = 0x00A5;       /*!< flash fap relieve key val */
  static const uint16_t FAP_HIGH_LEVEL_KEY = 0x00CC;    /*!< flash fap high level enable key val */
  static const uint32_t SLIB_UNLOCK_KEY = 0xA35F6D24;   /*!< flash slib operation unlock order key */

  static const uint32_t SLIB_START_SECTOR = 0x000007FF;      /*!< flash slib start sector */
  static const uint32_t SLIB_DATA_START_SECTOR = 0x003FF800; /*!< flash slib d-bus area start sector */
  static const uint32_t SLIB_END_SECTOR = 0xFFC00000;        /*!< flash slib end sector */

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
  /**
   * @brief Construct a new FLASH object
   *
   */
  FLASH(void);

  /**
   * @brief Destroy the FLASH object
   *
   */
  virtual ~FLASH(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  set the flash psr register
   * @param  waitCycle: the flash wait cycle.
   *         this parameter can be one of the following values:
   *         - FLASH_WAIT_CYCLE_0
   *         - FLASH_WAIT_CYCLE_1
   *         - FLASH_WAIT_CYCLE_2
   *         - FLASH_WAIT_CYCLE_3
   *         - FLASH_WAIT_CYCLE_4
   */
  static inline void psrSet(WaitCycle waitCycle) {
    FLASH0.psr |= static_cast<uint32_t>(0x150 | static_cast<uint32_t>(waitCycle));
  }

  /**
   * @brief  clear the flash flag.
   * @param  flag: specifies the flash flags to clear.
   *         this parameter can be any combination of the following values:
   *         - ODF
   *         - PRGMERR
   *         - EPPERR
   * @retval none
   */
  static void flagClear(Flag flag) {
    FLASH0.sts = static_cast<uint32_t>(flag);
    return;
  }

  /**
   * @brief  unlock the flash controller.
   * @param  none
   * @retval none
   */
  static inline void unlock(void) {
    FLASH0.unlock = FLASH_UNLOCK_KEY1;
    FLASH0.unlock = FLASH_UNLOCK_KEY2;
    return;
  }

  /**
   * @brief  lock the flash controller.
   * @param  none
   * @retval none
   */
  static inline void lock(void) {
    FLASH0.ctrl_bit.oplk = true;
  }

  /**
   * @brief  return the flash erase/program protection status.
   * @param  sector_bits: pointer to get the epps register.
   * @retval none
   */
  static inline void eppStatusGet(uint32_t *sectorBits) {
    sectorBits[0] = static_cast<uint32_t>(FLASH0.epps);
    return;
  }

  /**
   * @brief  check the flash access protection status.
   * @param  none
   * @retval flash access protection status(SET or RESET)
   */
  static inline bool fapStatusGet(void) {
    return FLASH0.usd_bit.fap;
  }

  /**
   * @brief  check the flash access protection high level status.
   * @param  none
   * @retval flash access protection high level status(SET or RESET)
   */
  static inline bool fapHighLevelStatusGet(void) {
    return FLASH0.usd_bit.fap_hl;
  }

  /**
   * @brief  get the main block slib state.
   * @param  none
   * @retval SET or RESET
   */
  static inline bool slibStateGet(void) {
    return FLASH0.slib_sts0_bit.slib_enf;
  }

  /**
   * @brief  get the main block start sector of slib.
   * @param  none
   * @retval uint16_t
   */
  static inline uint16_t slibStartSectorGet(void) {
    return static_cast<uint16_t>(FLASH0.slib_sts1_bit.slib_ss);
  }

  /**
   * @brief  get the main block data start sector of slib.
   * @param  none
   * @retval uint16_t
   */
  static inline uint16_t slibDatastartSectorGet(void) {
    return static_cast<uint16_t>(FLASH0.slib_sts1_bit.slib_dat_ss);
  }

  /**
   * @brief  get the main block end sector of slib.
   * @param  none
   * @retval uint16_t
   */
  static inline uint16_t slibEndSectorGet(void) {
    return static_cast<uint16_t>(FLASH0.slib_sts1_bit.slib_es);
  }

  /**
   * @brief  get the extension memory slib state.
   * @param  none
   * @retval SET or RESET
   */
  static inline bool extensionMemorySlibStateGet(void) {
    return FLASH0.slib_sts0_bit.em_slib_enf;
  }

  /**
   * @brief  get the extension memory data start sector of slib.
   * @param  none
   * @retval uint16_t
   */
  static inline uint16_t emSlibDatastartSectorGet(void) {
    return static_cast<uint16_t>(FLASH0.slib_sts0_bit.em_slib_dat_ss);
  }
  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  check whether the specified flash flag is set or not.
   * @param  flag: specifies the flash flag to check.
   *         this parameter can be one of flash flag status:
   *         - OBF
   *         - ODF
   *         - PRGMERR
   *         - EPPERR
   *         - USDERR
   * @retval the new state of flash_flag (SET or RESET).
   */
  static bool flagGet(Flag flag);

  /**
   * @brief  return the flash operation status.
   * @param  none
   * @retval status: the returned value can be: FLASH_OPERATE_BUSY,
   *         FLASH_PROGRAM_ERROR, FLASH_EPP_ERROR or FLASH_OPERATE_DONE.
   */
  static Status operationStatusGet(void);

  /**
   * @brief  wait for flash operation complete or timeout.
   * @param  timeout: flash operation timeout
   * @return Status
   *  - PROGRAM_ERROR
   *  - EPP_ERROR
   *  - OPERATE_DONE
   *  - OPERATE_TIMEOUT
   */
  static Status operationWaitFor(Timeout timeout);

  /**
   * @brief  erase a specified flash sector.
   * @param  sector_address: the sector address to be erased.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status sectorErase(uint32_t sectorAddress);

  /**
   * @brief  erase flash all internal sectors.
   * @param  none
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status internalAllErase(void);

  /**
   * @brief  erase the flash user system data.
   * @note   this functions erases all user system data except the fap byte.
   *         when fap high level enabled, can't use this function.
   * @param  none
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status userSystemDataErase(void);

  /**
   * @brief  program a word at a specified address.
   * @param  address: specifies the address to be programmed, word alignment is recommended.
   * @param  data: specifies the data to be programmed.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status wordProgram(uint32_t address, uint32_t data);

  /**
   * @brief  program a halfword at a specified address.
   * @param  address: specifies the address to be programmed, halfword alignment is recommended.
   * @param  data: specifies the data to be programmed.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status halfwordProgram(uint32_t address, uint16_t data);

  /**
   * @brief  program a byte at a specified address.
   * @param  address: specifies the address to be programmed.
   * @param  data: specifies the data to be programmed.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status byteProgram(uint32_t address, uint8_t data);

  /**
   * @brief  program a halfword at a specified user system data address.
   * @param  address: specifies the address to be programmed.
   * @param  data: specifies the data to be programmed.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status userSystemDataProgram(uint32_t address, uint8_t data);

  /**
   * @brief  config erase/program protection for the desired sectors.
   * @param  sector_bits:
   *         the pointer of the address of the sectors to be erase/program protected.
   *         the first 31 bits general every bit is used to protect 2 sectors. the bit
   *         31 is used to protect the rest sectors and extension memory.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status eppSet(uint32_t *sectorBits);

  /**
   * @brief  enable or disable the flash access protection.
   * @note   if the user has already programmed the other user system data before calling
   *         this function, must re-program them since this function erase all user system data.
   * @param  new_state: new state of the flash access protection.
   *         this parameter can be: TRUE or FALSE.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status fapEnable(bool newState);

  /**
   * @brief  enable or disable the flash access protection high level.
   * @note   if the user has already programmed the other user system data before calling
   *         this function, must re-program them since this function erase all user system data.
   * @param  new_state: new state of the flash access protection high level.
   *         this parameter can be: TRUE or FALSE.
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status fapHighLevelEnable(bool newState);

  /**
   * @brief  program the flash system setting byte in usd: wdt_ato_en / depslp_rst / stdby_rst .
   * @param  usd_ssb: the system setting byte
   * @note   this parameter usd_ssb must contain a combination of all the following 3 types of data
   *         type 1: wdt_ato_en, select the wdt auto start
   *         this data can be one of the following values:
   *         - USD_WDT_ATO_DISABLE: disable wdt auto start
   *         - USD_WDT_ATO_ENABLE: enable wdt auto start
   *         type 2: depslp_rst, reset event when entering deepsleep mode.
   *         this data can be one of the following values:
   *         - USD_DEPSLP_NO_RST: no reset generated when entering in deepsleep
   *         - USD_DEPSLP_RST: reset generated when entering in deepsleep
   *         type 3: stdby_rst, reset event when entering standby mode.
   *         this data can be one of the following values:
   *         - USD_STDBY_NO_RST: no reset generated when entering in standby
   *         - USD_STDBY_RST: reset generated when entering in standby
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status ssbSet(uint8_t usdSsb);

  /**
   * @brief  return the flash system setting byte status.
   * @param  none
   * @retval values from flash_usd register: wdt_ato_en(bit0), depslp_rst(bit1),
   *         stdby_rst(bit2).
   */
  static inline uint8_t ssbStatusGet(void) {
    /* return the system setting byte status */
    return static_cast<uint8_t>(static_cast<uint32_t>(FLASH0.usd) >> 2);
  }

  /**
   * @brief  enable or disable the specified flash interrupts.
   * @param  flash_int: specifies the flash interrupt sources to be enabled or disabled.
   *         this parameter can be any combination of the following values:
   *         - Interrupt::ERR
   *         - Interrupt::ODF
   * @param  new_state: new state of the specified flash interrupts.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void interruptEnable(Interrupt interrupt, bool newState) {
    if (static_cast<uint32_t>(interrupt) & static_cast<uint32_t>(Interrupt::ERR))
      FLASH0.ctrl_bit.errie = newState;
    if (static_cast<uint32_t>(interrupt) & static_cast<uint32_t>(Interrupt::ODF))
      FLASH0.ctrl_bit.odfie = newState;
  }

  /**
   * @brief  enable main block security library function.
   * @param  pwd: slib password
   *         start_sector: security library start sector
   *         data_start_sector: security library d-bus area start sector
   *         end_sector: security library end sector
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status slibEnable(uint32_t pwd, uint16_t startSector, uint16_t dataStartSector, uint16_t endSector);

  /**
   * @brief  disable main block slib when slib enabled.
   * @param  pwd: slib password
   * @retval success or error
   */
  static bool slibDisable(uint32_t pwd);

  /**
   * @brief  flash crc calibration.
   * @param  start_addr: crc calibration start sector address
   *         sector_cnt: crc calibration sector count
   * @retval uint32: crc calibration result
   */
  static uint32_t crcCalibrate(uint32_t start_addr, uint32_t sectorCnt);

  /**
   * @brief  enable boot memory as extension mode.
   * @note   this function is irreversible, can not disable!!!
   * @param  none
   * @retval none.
   */
  static void bootMemoryExtensionModeEnable(void);

  /**
   * @brief  enable extension memory security library function.
   * @param  pwd: slib password
   *         data_start_sector: extension memory security library d-bus area start sector, range 1~17 or 0xFF
   * @retval status: the returned value can be: Status::PROGRAM_ERROR,
   *         Status::EPP_ERROR, Status::DONE or Status::TIMEOUT.
   */
  static Status extensionMemorySlibEnable(uint32_t pwd, uint16_t dataStartSector);

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

#endif /* CHIP_39BF0942_072C_4AB3_9CBC_16781034D7F9 */
