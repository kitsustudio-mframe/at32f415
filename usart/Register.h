/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_238DC162_D5C0_4BA0_BE3D_ACD29155C0EC
#define CHIP_238DC162_D5C0_4BA0_BE3D_ACD29155C0EC

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::usart {
  struct Register;
}  // namespace chip::usart

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief @brief 通用同步異步收發器(USART)
 *
 * 通用同步異步收發器（USART）是一個能通過多種不同的配置與使用不同的數據格式的外設進行通信的通用接口，
 * 同時支持異步全雙工，異步半雙工以及同步傳輸。 USART 提供了可編程的波特率發生器，
 * 根據系統頻率以及分頻係數的不同，可產生高達 9.375MBits/s 的波特率，
 * 用戶以通過配置系統時鐘以及分頻係數以此產生所需要的特定通信頻率。
 *
 * USART 除了支持標準的 NRZ 異步以及同步收發通信協議外，
 * 還支持一些常用的其他類型的串行通信協議，如 LIN(局域互聯網)，
 * IrDA（紅外數據組織）SIRENDEC 規範，ISO7816-3 標準的異步智能卡協議，
 * 以及 CTS/RTS（Clear To Send/Request To Send）硬件流操作。
 *
 * USART 還支持多處理器通信，以及可配置通過空閒幀或 ID 匹配喚醒的靜默模式，
 * 以此搭建 USART 網絡，並且同時支持使用 DMA 進行數據的收發，以此實現高速通信。
 *
 * ---
 * USART主要特性如下所列：
 *
 * - 可編程配置的全雙工或半雙工通信
 *   - 全雙工異步通信
 *   - 單線半雙工通信
 *
 * - 可編程配置的通信模式
 *   - NRZ標準格式（Mark/Space）
 *   - LIN（局域互聯網）：LIN主機有發送間隔幀的能力以及LIN從機有檢測間隔幀的能力
 *   - IrDASIR（串行紅外）：在普通模式下持續時間為3/16位，在紅外低功耗模式下位
 *
 * - 持續時間可調
 *   - ISO7816-3標準裡定義的異步智能卡協議：智能卡模式支持0.5或1.5個停止位
 *   - RS-232CTS/RTS（ClearToSend/RequestToSend）硬件流操作
 */
struct chip::usart::Register {
  union {
    /**
     * @brief 狀態寄存器 (USART_STS), offset:0x00
     *
     * 偏移位置：0x00
     * 復位值：0x0000 00C0
     */
    volatile uint32_t sts;

    /**
     * @brief 狀態寄存器 位元訪問模式
     */
    struct {
      /**
       * @brief 校驗錯誤(Parity error) [0] <RO>
       *
       * 接收如果出現奇偶校驗錯誤，該位被硬件置起，由軟件將
       * 其清零(先讀狀態寄存器(USART_STS)，再讀數據寄
       * 存器(USART_DT))。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t perr : 1;

      /**
       * @brief 幀錯誤 (Framing error) [1] <RO>
       *
       * 當檢測到停止位異常(檢測到低電平)、過多的雜訊噪聲
       * 或者檢測到間隔幀，該位被硬件置起，由軟件將其清零
       * (先讀狀態寄存器(USART_STS)，再讀數據寄存器
       * (USART_DT))。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t ferr : 1;

      /**
       * @brief 噪聲錯誤 (Noise error) [2] <RO>
       *
       * 接收到的數據有雜訊時，該位被硬件置起，由軟件將其清
       * 零(先讀狀態寄存器(USART_STS)，再讀數據寄存器
       * (USART_DT))。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t nerr : 1;

      /**
       * @brief 接收器溢出錯誤 (Receiver overflow error) [3] <RO>
       *
       * 當 RDNE 仍然置起沒有清除的時候，如果此時又收到數
       * 據，該位被硬件置起，由軟件將其清零(先讀狀態寄存器
       * (USART_STS)，再讀 USART_DT)。
       *
       * - 0：無；
       * - 1：有。
       *
       * 注意：該位被置位時，DT 寄存器中的數據不會丟失，但
       * 是後續的數據會被覆蓋。
       *
       * 復位值：0x0
       */
      volatile uint32_t roerr : 1;

      /**
       * @brief 總線空閒 (Idle flag) [4] <RW>
       *
       * 當檢測到總線空閒時，該位被硬件置起，由軟件將其清零
       * (先讀狀態寄存器(USART_STS)，再讀數據寄存器
       * (USART_DT))。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t idlef : 1;

      /**
       * @brief 接收數據緩衝器滿 (Receive data buffer full) [5] <RW0C>
       *
       * 當接收到數據時，該位被硬件置起，由軟件將其清零(方
       * 式 1：讀數據寄存器(USART_DT)；方式 2：操作該位
       * 寫’0’)。
       *
       * - 0：未收到；
       * - 1：收到。
       *
       * 復位值：0x1
       */
      volatile uint32_t rdbf : 1;

      /**
       * @brief 發送數據完成 (Transmit data complete) [6] <RW0C>
       *
       * 當發送數據完成，該位被硬件置起，由軟件將其清零(方
       * 式 1：先讀狀態寄存器(USART_STS)，再寫數據寄存
       * 器(USART_DT)；方式 2：操作該位寫’0’)。
       *
       * - 0：未完成；
       * - 1：完成。
       *
       * 復位值：0x1
       */
      volatile uint32_t tdc : 1;

      /**
       * @brief 發送緩衝器空 (Transmit data buffer empty) [7] <RO>
       *
       * 當發送緩衝器為空，可以再次寫入數據時，該位被硬件置
       * 起。對數據寄存器(USART_DT)的寫操作，將清零該
       * 位。
       *
       * 0：非空；
       * 1：空。
       *
       * 復位值：0x0
       */
      volatile uint32_t tdbe : 1;

      /**
       * @brief 間隔幀標誌 (break frame flag) [8] (RO)
       *
       * 當檢測到間隔幀時，該位被硬件置起，由軟件將其清零。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t bff : 1;

      /**
       * @brief CTS 變化標誌 (CTS change flag) [9] <RO>
       *
       * 當 CTS 線發送變化時，該位被硬件置起，由軟件將其清
       * 零。
       *
       * - 0：無；
       * - 1：有。
       *
       * 復位值：0x0
       */
      volatile uint32_t ctscf : 1; /* [9] */

      /**
       * @brief 保留位 [31:10] <RESD>
       *
       */
      volatile uint32_t reserved1 : 22; /* [31:10] */
    } sts_bit;
  };

  union {
    /**
     * @brief 數據寄存器 (USART_DT), offset:0x04
     *
     * 偏移位置：0x04
     * 復位值：0x0000 0000
     */
    volatile uint32_t dt;

    /**
     * @brief 數據寄存器 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 數據值 (Data value) [8:0] <RW>
       *
       * 該寄存器包含讀和寫的功能。當奇偶校驗位使能，發送操
       * 作時，寫到 MSB 的值會被校驗位取代。接收操作時，讀
       * 到的 MSB 位是接收到的校驗位。
       */
      volatile uint32_t dt : 9;

      /**
       * @brief 保留位 [31:9] <RESD>
       *
       */
      volatile uint32_t reserved1 : 23;
    } dt_bit;
  };

  union {
    /**
     * @brief 波特比率寄存器 (USART_BAUDR) , offset:0x08
     *
     * 注意：如果TE或 RE被分別禁止，波特計數器停止計數。
     *
     * 偏移位置：0x08
     * 復位值：0x0000 0000
     */
    volatile uint32_t baudr;

    struct {
      /**
       * @brief 分頻係數 (Division) [15:0]
       *
       * 這 16 位定義了 USART 分頻係數
       *
       */
      volatile uint32_t div : 16;

      /**
       * @brief 保留位
       *
       * 硬體強制為0
       */
      volatile uint32_t reserved1 : 16;
    } baudr_bit;
  };

  union {
    /**
     * @brief 控制寄存器1 (UART CTRL 1) , offset:0x0C
     *
     * 偏移位置：0x0C
     * 復位值：0x0000 0000
     */
    volatile uint32_t ctrl1;

    /**
     * @brief 控制寄存器1 位元訪問模式
     */
    struct {
      /**
       * @brief 發送間隔幀 (Send break frame) [0]
       *
       * 使用該位來發送間隔幀。該位可以由軟件置起或清零。常
       * 規用法是軟件置起該位，間隔幀發送完成後，由硬件將該
       * 位清零。
       *
       * - 0：無
       * - 1：發送
       */
      volatile uint32_t sbf : 1;

      /**
       * @brief 接收靜默 (Receiver mute) [1]
       *
       * 該位定義接收端靜默的開啟，可由軟件置起或清零。當配
       * 置為空閒幀喚醒時，喚醒後硬件也會將其清零，當配置為
       * 匹配地址喚醒時，收到匹配地址喚醒後硬件會將其清零，
       * 收到不匹配地址後硬件會再次將其置起進入靜默狀態。
       *
       * - 0：普通
       * - 1：靜默
       */
      volatile uint32_t rm : 1;

      /**
       * @brief 接收使能 (Receiver enable) [2]
       *
       * 該位定義接收端的使能。
       *
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t ren : 1;

      /**
       * @brief 發送使能 (Transmitter enable) [3]
       *
       * 該位定義發送端的使能。
       *
       * - 0：關閉；
       * - 1：開啟
       */
      volatile uint32_t ten : 1;

      /**
       * @brief 總線空閒中斷使能 (IDLE interrupt enable) [4]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t idleien : 1;

      /**
       * @brief 接收數據緩衝器滿中斷使能 (RDBF interrupt enable [5]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t rdbfien : 1;

      /**
       * @brief 發送數據完成中斷使能(TDC interrupt enable) [6]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t tdcien : 1;

      /**
       * @brief 發送數據緩衝器空中斷使能(TDBE interrupt enable) [7]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t tdbeien : 1;

      /**
       * @brief PERR 中斷使能(PERR interrupt enable) [8]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t perrien : 1;

      /**
       * @brief 奇偶校驗選擇(Parity selection) [9]
       *
       * 該位定義是採用奇校驗還是偶校驗。
       *
       * - 0：偶校驗；
       * - 1：奇校驗。
       */
      volatile uint32_t psel : 1;

      /**
       * @brief 奇偶校驗使能(Parity enable)  [10]
       *
       * 該位定義使能硬件奇偶校驗(對於發送來說就是校驗位的
       * 產生；對於接收來說就是校驗位的檢測) 。當使能了該
       * 位，硬件將發送數據的最高位替換成校驗位；對接收到的
       * 數據檢查其校驗位是否正確。
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t pen : 1;

      /**
       * @brief 喚醒方式(Wake up mode) [11]
       *
       * 該位定義靜默狀態下被喚醒的方式。
       *
       * 0：空閒幀喚醒；
       * 1：ID 匹配喚醒。
       */
      volatile uint32_t wum : 1;

      /**
       * @brief 數據位個數(Data bit num) [12]
       *
       * 該位定義了數據位的個數。
       *
       * - 0： 8 位；
       * - 1： 9 位。
       */
      volatile uint32_t dbn : 1;

      /**
       * @brief USART 使能(USART enable) [13]
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t uen : 1;

      /**
       * @brief 保留位 [31:14]
       *
       */
      volatile uint32_t reserved1 : 18;
    } ctrl1_bit;
  };

  union {
    /**
     * @brief 控制寄存器2 (USART_CTRL2), offset:0x10
     *
     * 偏移位置：0x10
     * 復位值：0x0000 0000
     */
    volatile uint32_t ctrl2;

    /**
     * @brief 控制寄存器2 位元訪問模式
     */
    struct {
      /**
       * @brief USART的ID號 (USART identification) [3:0] <RW>
       *
       * 可配置的USART的ID號。
       */
      volatile uint32_t id : 4;

      /**
       * @brief 保留位 [4] <RESD>
       *
       */
      volatile uint32_t reserved1 : 1;

      /**
       * @brief 間隔幀位數 (break frame bit num) [5] <RW>
       *
       * 該位用來選擇是 11 位還是 10 位的間隔幀。
       *
       * - 0：10 位；
       * - 1：11 位。
       */
      volatile uint32_t bfbn : 1;

      /**
       * @brief 间隔帧中断使能 (break frame interrupt enable) [6] <RW>
       *
       * - 0：关闭；
       * - 1：开启。
       */
      volatile uint32_t bfien : 1;

      /**
       * @brief 保留位 [7] <RESD>
       *
       */
      volatile uint32_t reserved2 : 1;

      /**
       * @brief 最後一位時鐘脈衝 (Last bit clock pulse) [8] <RW>
       *
       * 在同步模式下，使用該位來控制是否在時鐘管腳上輸出數
       * 據的最後一位對應的時鐘脈衝
       *
       * - 0：不輸出；
       * - 1：輸出。
       */
      volatile uint32_t lbcp : 1;

      /**
       * @brief 時鐘相位 (Clock phase) [9] <RW>
       *
       * 在同步模式或智能卡模式下，可以用該位選擇時鐘管腳上
       * 時鐘輸出的相位。
       *
       * - 0：第一個邊沿進行數據捕獲；
       * - 1：第二個邊沿進行數據捕獲。
       */
      volatile uint32_t clkpha : 1;

      /**
       * @brief 時鐘極性 (Clock polarity) [10] <RW>
       *
       * 在同步模式或智能卡模式下，可以用該位選擇時鐘管腳上
       * 總線空閒時時鐘輸出的極性。
       *
       * - 0：低電平；
       * - 1：高電平。
       */
      volatile uint32_t clkpol : 1;

      /**
       * @brief 時鐘使能 (Clock enable) [11] <RW>
       *
       * 該位用來使能同步模式或智能卡模式的時鐘管腳。
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t clken : 1;

      /**
       * @brief 停止位個數 (STOP bit num) [13:12] <RW>
       *
       * 這2位用來設置停止位的個數
       *
       * - 00：1 位；
       * - 01：0.5 位；
       * - 10：2 位；
       * - 11：1.5 位；
       */
      volatile uint32_t stopbn : 2;

      /**
       * @brief LIN 模式使能 (LIN mode enable) [14] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       *
       */
      volatile uint32_t linen : 1;

      /**
       * @brief 保留位 [31:15] <RESD>
       *
       */
      volatile uint32_t reserved3 : 17;

    } ctrl2_bit;
  };

  union {
    /**
     * @brief 控制寄存器3 (USART_CTRL3), offset:0x14
     *
     * 偏移位置：0x14
     * 復位值：0x0000 0000
     */
    volatile uint32_t ctrl3;

    /**
     * @brief 控制寄存器3 位元訪問模式
     */
    struct {
      /**
       * @brief 錯誤中斷使能 (Error interrupt enable)[0] <RW>
       *
       * 當有幀錯誤、接收溢出錯誤或者雜訊錯誤時產生中斷。
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t errien : 1;

      /**
       * @brief 紅外功能使能 (IrDA enable) [1] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t irdaen : 1;

      /**
       * @brief 紅外低功耗模式配置 (IrDA low-power mode) [2] <RW>
       *
       * 該位用來配置紅外低功耗模式。
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t irdalp : 1;

      /**
       * @brief 單線雙向半雙工模式使能 (Single line bidirectional half-duplex enable) [3] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t slben : 1;

      /**
       * @brief 智能卡 NACK 使能 (Smart card NACK enable) [4] <RW>
       *
       * 該位用於配置校驗錯誤出現時，發送 NACK。
       *
       * - 0：不發送；
       * - 1：發送。
       */
      volatile uint32_t scnacken : 1;

      /**
       * @brief 智能卡模式使能 (Smart card mode enable) [5] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t scmen : 1;

      /**
       * @brief DMA 接收使能 (DMA receiver enable) [6] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t dmaren : 1;

      /**
       * @brief DMA 發送使能 (DMA transmit enable) [7] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t dmaten : 1;

      /**
       * @brief RTS 使能 (RTS enable) [8] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t rtsen : 1;

      /**
       * @brief CTS 使能 (CTS enable) [9] <RW>
       *
       * 0：關閉；
       * 1：開啟。
       */
      volatile uint32_t ctsen : 1;

      /**
       * @brief CTSCF 中斷使能 (CTSCF interrupt enable) [10] <RW>
       *
       * - 0：關閉；
       * - 1：開啟。
       */
      volatile uint32_t ctscfien : 1;

      /**
       * @brief 保留位 [31:11]
       *
       */
      volatile uint32_t reserved1 : 21;
    } ctrl3_bit;
  };

  union {
    /**
     * @brief 保護時間和預分頻寄存器 (USART_GDIV), offset:0x18
     *
     * 偏移位置：0x18
     * 復位值：0x0000 0000
     */
    volatile uint32_t gdiv;

    /**
     * @brief 保護時間和預分頻寄存器 位元訪問模式
     */
    struct {
      /**
       * @brief 紅外或者智能卡分頻係數(IrDA/smartcard division)[7:0] <RW>
       *
       * 紅外(IrDA)模式：
       *
       * 8 位[7：0]有效，普通模式無效且只能設置為 00000001，
       *
       * 低功耗模式分頻係數對外設時鐘進行分頻，作為脈衝寬度的基數週期；
       *
       * - 00000000：保留–不要寫入該值；
       * - 00000001：1 分頻；
       * - 00000010：2 分頻；
       * - ......
       *
       *
       * 智能卡模式：
       *
       * 低 5 位[4：0]有效，分頻係數對外設時鐘進行分頻，給智能卡提供時鐘。可以設置為如下值：
       *
       * - 00000：保留–不要寫入該值；
       * - 00001：2 分頻；
       * - 00010：4 分頻；
       * - 00011：6 分頻；
       * - ......
       */
      volatile uint32_t isdiv : 8;

      /**
       * @brief 智能卡保護時間值 (Smart card guard time) [15:8] <RW>
       *
       * 在智能卡模式下，當保護時間過去後，才會設置發送完成
       * 標誌，這幾位配置保護時間值。
       */
      volatile uint32_t scgt : 8;

      /**
       * @brief 保留位 [31:16] <RESD>
       *
       */
      volatile uint32_t reserved1 : 16;
    } gdiv_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_238DC162_D5C0_4BA0_BE3D_ACD29155C0EC */
