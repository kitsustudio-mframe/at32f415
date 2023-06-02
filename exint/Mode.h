/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_6774CA30_BDEC_4755_BBFA_92A3A853634E
#define AT32F415_6774CA30_BDEC_4755_BBFA_92A3A853634E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::exint{
  enum struct Mode : uint8_t;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::exint::Mode : uint8_t{
  INTERRUPUT = 0x00, ///< external interrupt line interrupt mode
  EVENT      = 0x01  ///< external interrupt line event mode
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_6774CA30_BDEC_4755_BBFA_92A3A853634E */
