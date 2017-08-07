/*
 * board_def.h
 *
 *  Created on: Aug 7, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_BOARD_BOARD_DEF_H_
#define SRC_HW_BOARD_BOARD_DEF_H_

#include "hw.h"
#include "W7500x_gpio.h"

/* Application Firmware Version */
#define MAJOR_VER           1
#define MINOR_VER           1
#define MAINTENANCE_VER     0

#define DEVICE_AT_MODE      0
#define DEVICE_GW_MODE      1
typedef enum{ST_BOOT, ST_APP, ST_UPGRADE} teDEVSTATUS;

#define NONBLOCKING_MODE 0
#define BLOCKING_MODE    1

/* Available board list */
#define WIZwiki_W7500       1
#define WIZwiki_W7500P      2
#define WIZwiki_W7500ECO    3
#define WIZ750SR            4
#define WIZ750JR            5
#define W7500P_S2E          6
#define WIZ750MINI          7
#define UNKNOWN_DEVICE      0xff

/* Target Board Selector */
//#define DEVICE_BOARD_NAME WIZwiki_W7500
//#define DEVICE_BOARD_NAME WIZwiki_W7500P
//#define DEVICE_BOARD_NAME WIZwiki_W7500ECO
//#define DEVICE_BOARD_NAME WIZ750SR
//#define DEVICE_BOARD_NAME WIZ750JR
//#define DEVICE_BOARD_NAME WIZ750MINI
//#define DEVICE_BOARD_NAME W7500P_S2E

#ifdef DEVICE_BOARD_NAME
#if (DEVICE_BOARD_NAME == WIZwiki_W7500)
#define __W7500__
#define __USE_APPBACKUP_AREA__
#define DATA_UART_CH                 UART_CH1
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_8MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZwiki"
#elif (DEVICE_BOARD_NAME == WIZwiki_W7500P)
#define __W7500P__
#define __USE_APPBACKUP_AREA__
#define DATA_UART_CH                 UART_CH0
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_8MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZwiki_P"
#elif (DEVICE_BOARD_NAME == WIZwiki_W7500ECO)
#define __W7500__
#define __USE_EXT_EEPROM__
#define __USE_APPBACKUP_AREA__
#define DATA_UART_CH                 UART_CH1
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_8MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZwiki_ECO"
#elif (DEVICE_BOARD_NAME == WIZ750SR)
#define __W7500P__
#define __USE_UART_IF_SELECTOR__
#define __USE_EXT_EEPROM__
#define __USE_BOOT_ENTRY__
#define __USE_APPBACKUP_AREA__
#define __USE_GPIO_HARDWARE_FLOWCONTROL__
#define __USE_USERS_GPIO__
#define DATA_UART_CH                 UART_CH0
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_SOURCE_12MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZ750SR"
#elif (DEVICE_BOARD_NAME == WIZ750JR)
#define __USE_EXT_EEPROM__
#define __USE_BOOT_ENTRY__
#define __USE_APPBACKUP_AREA__
#define __USE_GPIO_HARDWARE_FLOWCONTROL__
#define DATA_UART_CH                 UART_CH0
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_SOURCE_12MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZ750Jr"
#elif (DEVICE_BOARD_NAME == W7500P_S2E) // Chip product
#define __W7500P__
#define __USE_UART_IF_SELECTOR__
#define __USE_BOOT_ENTRY__
#define __USE_APPBACKUP_AREA__
#define __USE_GPIO_HARDWARE_FLOWCONTROL__
#define __USE_USERS_GPIO__
#define DATA_UART_CH                 UART_CH0
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_SOURCE_12MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "W7500P-S2E"
#elif (DEVICE_BOARD_NAME == WIZ750MINI)
#define __W7500P__
#define __USE_UART_IF_SELECTOR__    // RS-232/TTL or RS-422/485 selector using UART IF selector pin
#define __USE_EXT_EEPROM__          // External EEPROM or Internal Data flash (DAT0/1)
#define __USE_BOOT_ENTRY__          // Application boot mode entry pin activated
#define __USE_APPBACKUP_AREA__      // If this option activated, Application firmware area is consists of App (50kB) and App backup (50kB). If not, user's application can be 100kB size. (Does not use the backup area)
#define __USE_GPIO_HARDWARE_FLOWCONTROL__
#define DATA_UART_CH                 UART_CH0
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_SOURCE_12MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "WIZ750Mini" // Device name
#else
#define __USE_EXT_EEPROM__
#define __USE_APPBACKUP_AREA__
#define __USE_GPIO_HARDWARE_FLOWCONTROL__
#define DATA_UART_CH                 UART_CH1
#define DEVICE_CLOCK_SELECT          EXTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK      PLL_8MHz
#define DEVICE_TARGET_SYSTEM_CLOCK   SYSTEM_48MHz
#define DEVICE_ID_DEFAULT            "W7500-S2E" // Device name: WIZwiki_W7500 or WIZwiki_W7500ECO Board
#endif
#else
#define __USE_APPBACKUP_AREA__
#define DATA_UART_CH                     UART_CH1
#define DEVICE_CLOCK_SELECT              INTERNAL_CLOCK
#define DEVICE_PLL_SOURCE_CLOCK          PLL_8MHz
#define DEVICE_TARGET_SYSTEM_CLOCK       SYSTEM_48MHz
#define DEVICE_BOARD_NAME                UNKNOWN_DEVICE
#define DEVICE_ID_DEFAULT                "UNKNOWN"
#endif

/* PHY init defines: USE MDC/MDIO */
#define __DEF_USED_MDIO__
#define PHYLINK_CHECK_CYCLE_MSEC         1000
#define PHYLINK_STATE_INPUT_PIN          9
#define PHYLINK_STATE_INPUT_PORT         PORT_A

#endif /* SRC_HW_BOARD_BOARD_DEF_H_ */
