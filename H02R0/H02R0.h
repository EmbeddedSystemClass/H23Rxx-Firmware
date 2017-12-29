/*
    BitzOS (BOS) V0.0.0 - Copyright (C) 2016 Hexabitz
    All rights reserved

    File Name     : H02R0.h
    Description   : Header file for module H02R0.
										Bluetooth module (BT800/BT900)
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef H02R0_H
#define H02R0_H

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"
#include "H02R0_uart.h"
#include "H02R0_gpio.h"
#include "H02R0_dma.h"

/* Exported definitions -------------------------------------------------------*/

//#define	modulePN		_H02R0
#define	modulePN		_H02R1

/* Port-related definitions */
#define	NumOfPorts		6
#define P_PROG 				P2						/* ST factory bootloader UART */

/* Define available ports */
#define _P1
#define _P2
#define _P3
#define _P4
#define _P5
#define _P6

/* Define available USARTs */
#define _Usart1 1
#define _Usart2 1
#define _Usart3 1
#define _Usart4 1
#define _Usart5 1
#define _Usart6 1

/* Port-UART mapping */
#define P1uart &huart4
#define P2uart &huart2
#define P3uart &huart6
#define P4uart &huart1
#define P5uart &huart5
#define P6uart &huart3

/* Port Definitions */
#define	USART1_TX_PIN		GPIO_PIN_9
#define	USART1_RX_PIN		GPIO_PIN_10
#define	USART1_TX_PORT	GPIOA
#define	USART1_RX_PORT	GPIOA
#define	USART1_AF				GPIO_AF1_USART1

#define	USART2_TX_PIN		GPIO_PIN_2
#define	USART2_RX_PIN		GPIO_PIN_3
#define	USART2_TX_PORT	GPIOA
#define	USART2_RX_PORT	GPIOA
#define	USART2_AF				GPIO_AF1_USART2

#define	USART4_TX_PIN		GPIO_PIN_0
#define	USART4_RX_PIN		GPIO_PIN_1
#define	USART4_TX_PORT	GPIOA
#define	USART4_RX_PORT	GPIOA
#define	USART4_AF				GPIO_AF4_USART4

#define	USART5_TX_PIN		GPIO_PIN_3
#define	USART5_RX_PIN		GPIO_PIN_4
#define	USART5_TX_PORT	GPIOB
#define	USART5_RX_PORT	GPIOB
#define	USART5_AF				GPIO_AF4_USART5

#define	USART6_TX_PIN		GPIO_PIN_4
#define	USART6_RX_PIN		GPIO_PIN_5
#define	USART6_TX_PORT	GPIOA
#define	USART6_RX_PORT	GPIOA
#define	USART6_AF				GPIO_AF5_USART6

/* Module-specific Definitions */
#define	USART3_TX_PIN			GPIO_PIN_10
#define	USART3_RX_PIN			GPIO_PIN_11
#define	USART3_RTS_PIN		GPIO_PIN_1
#define	USART3_CTS_PIN		GPIO_PIN_6
#define	USART3_TX_PORT		GPIOB
#define	USART3_RX_PORT		GPIOB
#define	USART3_RTS_PORT		GPIOB
#define	USART3_CTS_PORT		GPIOA
#define	USART3_AF					GPIO_AF4_USART3
#ifdef H02R0
	#define	_BT_RST_PIN			GPIO_PIN_15
	#define	_BT_RST_PORT		GPIOB
#endif
#ifdef H02R1
	#define	_BT_RST_PIN							GPIO_PIN_2
	#define	_BT_RST_PORT						GPIOB
	#define	_BT_VSP_PIN							GPIO_PIN_14
	#define	_BT_VSP_PORT						GPIOB
	#define	_BT_MODE_PIN						GPIO_PIN_7
	#define	_BT_MODE_PORT						GPIOA
	#define	_BT_HOST_WKUP_PIN				GPIO_PIN_12
	#define	_BT_HOST_WKUP_PORT			GPIOB
#endif

/* H02R0_Status Type Definition */
typedef enum
{
  H02R0_OK = 0,
	H02R0_ERR_UnknownMessage = 1,
	H02R0_ERR_WrongParams,
	H02R0_RUN_VspCommandMode,
	H02R0_RUN_VspBridgeToUartMode,
	H02R0_ERROR = 255
} Module_Status;

/* Indicator LED */
#define _IND_LED_PORT		GPIOA
#define _IND_LED_PIN		GPIO_PIN_11

/* Port-related Bluetooth - BT900 */
#define PORT_BTC_CONN								P6

/* Macros define to enable/disable debug information will be shown 
 * on Terminal Application for Bluetooth
 */
#define H02R0_ENABLE_DEBUG_BTC          1
#define H02R0_DISABLE_DEBUG_BTC         0

#define H02R0_UART_DEBUG_PORT           P2
#define H02R0_SHOW_DEBUG_INFO_TERMINAL  0




/* Export UART variables */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;

/* Define UART Init prototypes */
extern void MX_USART1_UART_Init(void);
extern void MX_USART2_UART_Init(void);
extern void MX_USART3_UART_Init(void);
extern void MX_USART4_UART_Init(void);
extern void MX_USART5_UART_Init(void);
extern void MX_USART6_UART_Init(void);

/* handler for control bluetooth module task */
extern TaskHandle_t ControlBluetoothTaskHandle;

/* -----------------------------------------------------------------------
	|														Message Codes	 														 	|
   -----------------------------------------------------------------------
*/

#define	CODE_H02R0_GET_INFO								200
#define	CODE_H02R0_OTA_MODE								201
#define	CODE_H02R0_RUN_MODE								202
#define	CODE_H02R0_VSP_COMMAND_MODE				203
#define	CODE_H02R0_VSP_BRIDGE_MODE				204
#define	CODE_H02R0_SPP_MODE								205
#define CODE_H02R0_LED_STATUS_ON					206
#define CODE_H02R0_LED_STATUS_OFF					207

#define CODE_H02R0_BTC_DEL_ALL_DATA_SEG		208

#define CODE_H02R0_EVBTC_SPPCONN					209
#define CODE_H02R0_EVBTC_SPPDISCON				210
#define CODE_H02R0_EVBTC_PAIR_REQUEST			211
#define CODE_H02R0_EVBTC_PIN_REQUEST			212
#define CODE_H02R0_EVBTC_PAIR_RESULT			213
#define CODE_H02R0_EVBTC_AUTHREQ					214
#define CODE_H02R0_EVBTC_PASSKEY					215
#define CODE_H02R0_SHOW_DEBUG_INFO				216


/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   -----------------------------------------------------------------------
*/

#ifdef H02R1
	#define BT_SET_RST_PIN()				HAL_GPIO_WritePin(_BT_RST_PORT,_BT_RST_PIN,GPIO_PIN_SET)
	#define BT_CLEAR_RST_PIN()			HAL_GPIO_WritePin(_BT_RST_PORT,_BT_RST_PIN,GPIO_PIN_RESET);

	#define BT_SET_VSP_PIN()				HAL_GPIO_WritePin(_BT_VSP_PORT,_BT_VSP_PIN,GPIO_PIN_SET)
	#define BT_CLEAR_VSP_PIN()			HAL_GPIO_WritePin(_BT_VSP_PORT,_BT_VSP_PIN,GPIO_PIN_RESET)

	#define BT_SET_MODE_PIN()				HAL_GPIO_WritePin(_BT_MODE_PORT,_BT_MODE_PIN,GPIO_PIN_SET)
	#define BT_CLEAR_MODE_PIN()			HAL_GPIO_WritePin(_BT_MODE_PORT,_BT_MODE_PIN,GPIO_PIN_RESET)
#endif

extern void resetBt900Module(void);
extern void btUpdateScript(void);
extern Module_Status btSetVspMode(int8_t inputVspMode);

extern HAL_StatusTypeDef btSendCommandToBtc(uint8_t *command);


/* -----------------------------------------------------------------------
	|															Commands																 	|
   -----------------------------------------------------------------------
*/

extern const CLI_Command_Definition_t btUpdateScriptCommandDefinition;
extern const CLI_Command_Definition_t btRunScriptCommandDefinition;
extern const CLI_Command_Definition_t btVspModeCommandDefinition;
extern const CLI_Command_Definition_t btSetBaudrateCommandDefinition;


#endif /* H02R0_H */

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
