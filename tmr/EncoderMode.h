/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_2D13BF88_9829_4781_82A1_CA026D6AFC77
#define AT32F415_2D13BF88_9829_4781_82A1_CA026D6AFC77

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./subordinate/ModeSelect.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  enum struct EncoderMode : uint8_t;

}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::EncoderMode : uint8_t {
  MODE_A = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_A), /*!< tmr encoder mode a */
  MODE_B = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_B), /*!< tmr encoder mode b */
  MODE_C = static_cast<uint8_t>(subordinate::ModeSelect::ENCODER_C)  /*!< tmr encoder mode c */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_2D13BF88_9829_4781_82A1_CA026D6AFC77 */
