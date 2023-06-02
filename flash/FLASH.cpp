/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./FLASH.h"

#include "./usd/USD.h"

/* ****************************************************************************************
 * Macro
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using at32f415::flash::FLASH;
using at32f415::flash::Register;
using at32f415::flash::Status;

/* ****************************************************************************************
 * Variable <Static>
 */
Register &at32f415::flash::FLASH0 = *reinterpret_cast<Register *>(at32f415::Chip::BASE_FLASH_REG);

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/** ---------------------------------------------------------------------------------------
 *
 */
bool FLASH::flagGet(Flag flag) {
  uint32_t flash_flag = static_cast<uint32_t>(flag);
  uint32_t flag_position;
  flag_position = flash_flag & 0x70000000;
  flash_flag &= 0x8FFFFFFF;
  switch (flag_position) {
    case 0x00000000:
      if (FLASH0.sts & flash_flag)
        return true;
      break;
    case 0x40000000:
      if (FLASH0.usd & flash_flag)
        return true;
      break;

    default:
      break;
  }
  /* return the new state of flash_flag (SET or false) */
  return false;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::operationStatusGet(void) {
  Status result = Status::DONE;
  if (FLASH0.sts_bit.obf != false) {
    result = Status::BUSY;
  } else if (FLASH0.sts_bit.prgmerr) {
    result = Status::PROGRAM_ERROR;
  } else if (FLASH0.sts_bit.epperr) {
    result = Status::EPP_ERROR;
  } else {
    result = Status::DONE;
  }
  /* return the flash status */
  return result;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::operationWaitFor(Timeout timeout) {
  uint32_t time_out = static_cast<uint32_t>(timeout);
  Status status = Status::DONE;
  /* check for the flash status */
  status = operationStatusGet();

  while ((status == Status::BUSY) && (time_out != 0x00)) {
    status = operationStatusGet();
    time_out--;
  }
  if (time_out == 0x00) {
    status = Status::TIMEOUT;
  }
  /* return the status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::sectorErase(uint32_t sectorAddress) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::ERASE);

  if (status == Status::DONE) {
    /* if the previous operation is completed, continue to erase the sector */
    FLASH0.ctrl_bit.secers = true;
    FLASH0.addr = sectorAddress;
    FLASH0.ctrl_bit.erstr = true;

    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::ERASE);

    /* disable the secers bit */
    FLASH0.ctrl_bit.secers = false;
  }
  /* return the erase status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::internalAllErase(void) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::ERASE);

  if (status == Status::DONE) {
    /* if the previous operation is completed, continue to erase */
    FLASH0.ctrl_bit.bankers = true;
    FLASH0.ctrl_bit.erstr = true;

    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::ERASE);

    /* disable the bankers bit */
    FLASH0.ctrl_bit.bankers = false;
  }
  /* return the erase status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::userSystemDataErase(void) {
  Status status = Status::DONE;
  uint16_t fap_val = FAP_RELIEVE_KEY;
  /* get the flash access protection status */
  if (fapStatusGet()) {
    fap_val = 0x0000;
  }

  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::ERASE);

  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false)
      ;

    /* erase the user system data */
    FLASH0.ctrl_bit.usders = true;
    FLASH0.ctrl_bit.erstr = true;

    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::ERASE);

    /* disable the usders bit */
    FLASH0.ctrl_bit.usders = false;

    if ((status == Status::DONE) && (fap_val == FAP_RELIEVE_KEY)) {
      /* enable the user system data programming operation */
      FLASH0.ctrl_bit.usdprgm = true;

      /* restore the last flash access protection value */
      usd::USD0.fap = (uint16_t)fap_val;

      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::PROGRAMMING);

      /*disable the usdprgm bit */
      FLASH0.ctrl_bit.usdprgm = false;
    }
  }
  /* return the erase status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::wordProgram(uint32_t address, uint32_t data) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    FLASH0.ctrl_bit.fprgm = true;
    *(volatile uint32_t *)address = data;
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    /* disable the fprgm bit */
    FLASH0.ctrl_bit.fprgm = false;
  }
  /* return the program status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::halfwordProgram(uint32_t address, uint16_t data) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    FLASH0.ctrl_bit.fprgm = true;
    *(volatile uint16_t *)address = data;
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    /* disable the fprgm bit */
    FLASH0.ctrl_bit.fprgm = false;
  }
  /* return the program status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::byteProgram(uint32_t address, uint8_t data) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    FLASH0.ctrl_bit.fprgm = true;
    *(volatile uint8_t *)address = data;
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    /* disable the fprgm bit */
    FLASH0.ctrl_bit.fprgm = false;
  }
  /* return the program status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::userSystemDataProgram(uint32_t address, uint8_t data) {
  Status status = Status::DONE;
  status = operationWaitFor(Timeout::PROGRAMMING);
  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false)
      ;

    /* enable the user system data programming operation */
    FLASH0.ctrl_bit.usdprgm = true;
    *(volatile uint16_t *)address = data;

    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    /* disable the usdprgm bit */
    FLASH0.ctrl_bit.usdprgm = false;
  }
  /* return the user system data program status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::eppSet(uint32_t *sectorBits) {
  uint16_t epp_data[4] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
  Status status = Status::DONE;
  sectorBits[0] = (uint32_t)(~sectorBits[0]);
  epp_data[0] = (uint16_t)((sectorBits[0] >> 0) & 0xFF);
  epp_data[1] = (uint16_t)((sectorBits[0] >> 8) & 0xFF);
  epp_data[2] = (uint16_t)((sectorBits[0] >> 16) & 0xFF);
  epp_data[3] = (uint16_t)((sectorBits[0] >> 24) & 0xFF);
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false)
      ;

    FLASH0.ctrl_bit.usdprgm = true;
    usd::USD0.epp0 = epp_data[0];
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    if (status == Status::DONE) {
      usd::USD0.epp1 = epp_data[1];
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::PROGRAMMING);
    }
    if (status == Status::DONE) {
      usd::USD0.epp2 = epp_data[2];
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::PROGRAMMING);
    }
    if (status == Status::DONE) {
      usd::USD0.epp3 = epp_data[3];
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::PROGRAMMING);
    }
    /* disable the usdprgm bit */
    FLASH0.ctrl_bit.usdprgm = false;
  }
  /* return the erase/program protection operation status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::fapEnable(bool newState) {
  Status status = Status::DONE;
  status = operationWaitFor(Timeout::ERASE);
  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false)
      ;

    FLASH0.ctrl_bit.usders = true;
    FLASH0.ctrl_bit.erstr = true;
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::ERASE);

    /* disable the usders bit */
    FLASH0.ctrl_bit.usders = false;

    if (status == Status::DONE) {
      if (newState == false) {
        /* enable the user system data programming operation */
        FLASH0.ctrl_bit.usdprgm = true;
        usd::USD0.fap = FAP_RELIEVE_KEY;

        /* Wait for operation to be completed */
        status = operationWaitFor(Timeout::ERASE);

        /* disable the usdprgm bit */
        FLASH0.ctrl_bit.usdprgm = false;
      }
    }
  }
  /* return the flash access protection operation status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::fapHighLevelEnable(bool newState) {
  Status status = Status::DONE;
  status = operationWaitFor(Timeout::ERASE);
  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false)
      ;

    if (newState == false) {
      FLASH0.ctrl_bit.fap_hl_dis = true;
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::ERASE);

      FLASH0.ctrl_bit.usders = true;
      FLASH0.ctrl_bit.erstr = true;
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::ERASE);

      /* disable the usders bit */
      FLASH0.ctrl_bit.usders = false;

      if (status == Status::DONE) {
        /* enable the user system data programming operation */
        FLASH0.ctrl_bit.usdprgm = true;
        usd::USD0.fap = FAP_RELIEVE_KEY;

        /* wait for operation to be completed */
        status = operationWaitFor(Timeout::ERASE);

        /* disable the usdprgm bit */
        FLASH0.ctrl_bit.usdprgm = false;
      }
    } else {
      FLASH0.ctrl_bit.usders = true;
      FLASH0.ctrl_bit.erstr = true;
      /* wait for operation to be completed */
      status = operationWaitFor(Timeout::ERASE);

      /* disable the usders bit */
      FLASH0.ctrl_bit.usders = false;

      if (status == Status::DONE) {
        /* enable the user system data programming operation */
        FLASH0.ctrl_bit.usdprgm = true;
        usd::USD0.fap = FAP_HIGH_LEVEL_KEY;

        /* wait for operation to be completed */
        status = operationWaitFor(Timeout::PROGRAMMING);

        /* disable the usdprgm bit */
        FLASH0.ctrl_bit.usdprgm = false;
      }
    }
  }
  /* return the flash access protection operation status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::ssbSet(uint8_t usdSsb) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    /* unlock the user system data */
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY1;
    FLASH0.usd_unlock = FLASH_UNLOCK_KEY2;
    while (FLASH0.ctrl_bit.usdulks == false) {
    }

    /* enable the user system data programming operation */
    FLASH0.ctrl_bit.usdprgm = true;

    usd::USD0.ssb = usdSsb;
    /* wait for operation to be completed */
    status = operationWaitFor(Timeout::PROGRAMMING);

    /* disable the usdprgm bit */
    FLASH0.ctrl_bit.usdprgm = false;
  }
  /* return the user system data program status */
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::slibEnable(uint32_t pwd, uint16_t startSector, uint16_t dataStartSector, uint16_t endSector) {
  uint32_t slib_range;
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  /*check range param limits*/
  if ((startSector >= dataStartSector) || ((dataStartSector > endSector) && (dataStartSector != 0x7FF)) || (startSector > endSector))
    return Status::PROGRAM_ERROR;

  if (status == Status::DONE) {
    /* unlock slib cfg register */
    FLASH0.slib_unlock = SLIB_UNLOCK_KEY;
    while (FLASH0.slib_misc_sts_bit.slib_ulkf == false)
      ;

    slib_range = ((uint32_t)(dataStartSector << 11) & SLIB_DATA_START_SECTOR) |
                 ((uint32_t)(endSector << 22) & SLIB_END_SECTOR) |
                 (startSector & SLIB_START_SECTOR);
    /* configure slib, set pwd and range */
    FLASH0.slib_set_pwd = pwd;
    status = operationWaitFor(Timeout::PROGRAMMING);
    FLASH0.slib_set_range = slib_range;
    status = operationWaitFor(Timeout::PROGRAMMING);
  }
  return status;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool FLASH::slibDisable(uint32_t pwd) {
  Status status = Status::DONE;
  /* write password to disable slib */
  FLASH0.slib_pwd_clr = pwd;

  status = operationWaitFor(Timeout::ERASE);
  if (status == Status::DONE) {
    if (FLASH0.slib_misc_sts_bit.slib_pwd_ok)
      return true;
    else
      return false;
  }
  return false;
}

/** ---------------------------------------------------------------------------------------
 *
 */
uint32_t FLASH::crcCalibrate(uint32_t start_addr, uint32_t sectorCnt) {
  FLASH0.crc_addr = start_addr;
  FLASH0.crc_ctrl = sectorCnt | 0x10000;
  operationWaitFor(Timeout::OPERATION);
  return FLASH0.crc_chkr;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void FLASH::bootMemoryExtensionModeEnable(void) {
  if (FLASH0.slib_sts0_bit.btm_ap_enf == false) {
    FLASH0.slib_unlock = SLIB_UNLOCK_KEY;
    while (FLASH0.slib_misc_sts_bit.slib_ulkf == false) {
    }

    FLASH0.btm_mode_set = 0;
    operationWaitFor(Timeout::OPERATION);
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
Status FLASH::extensionMemorySlibEnable(uint32_t pwd, uint16_t dataStartSector) {
  Status status = Status::DONE;
  /* wait for last operation to be completed */
  status = operationWaitFor(Timeout::PROGRAMMING);

  if (status == Status::DONE) {
    /* unlock slib cfg register */
    FLASH0.slib_unlock = SLIB_UNLOCK_KEY;
    while (FLASH0.slib_misc_sts_bit.slib_ulkf == false) {
    }

    /* configure slib, set pwd and range */
    FLASH0.slib_set_pwd = pwd;
    status = operationWaitFor(Timeout::PROGRAMMING);
    FLASH0.em_slib_set = static_cast<uint32_t>(dataStartSector << 16) + static_cast<uint32_t>(0x5AA5);
    status = operationWaitFor(Timeout::PROGRAMMING);
  }
  return status;
}
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

#pragma clang diagnostic pop
/* ****************************************************************************************
 * End of file
 */
