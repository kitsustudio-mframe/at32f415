/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_2D13BF88_9829_4781_82A1_CA026D6AFC77
#define CHIP_2D13BF88_9829_4781_82A1_CA026D6AFC77

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./subordinate/ModeSelect.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr {
  enum struct EncoderMode : uint8_t;

}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::EncoderMode : uint8_t {
  MODE_A = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_A), /*!< tmr encoder mode a */
  MODE_B = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_B), /*!< tmr encoder mode b */
  MODE_C = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_C)  /*!< tmr encoder mode c */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_2D13BF88_9829_4781_82A1_CA026D6AFC77 */
