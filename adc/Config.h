/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_09E1DC08_5A58_4545_8FCE_09117383EA40
#define CHIP_09E1DC08_5A58_4545_8FCE_09117383EA40

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../adc/DataAlign.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::adc {
  struct Config;
}  // namespace chip::adc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::adc::Config {
  uint8_t ordinaryChannelLength;
  DataAlign dataAlign;
  bool sequenceMode;
  bool repeatMode;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_09E1DC08_5A58_4545_8FCE_09117383EA40 */
