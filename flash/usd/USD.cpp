/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "USD.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/Processor.h"

/* ****************************************************************************
 * Macro
 */

/* ****************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
using chip::Processor;
using chip::flash::usd::Register;
using chip::flash::usd::USD;

/* ****************************************************************************
 * Static Variable
 */
Register& chip::flash::usd::USD0 = *reinterpret_cast<Register*>(Processor::BASE_USD);

/* ****************************************************************************
 * Construct Method
 */

/* ****************************************************************************
 * Operator Method
 */

/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * End of file
 */
