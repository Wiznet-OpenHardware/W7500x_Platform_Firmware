/**
 ******************************************************************************
 * @file
 * @author  Kei, Team Module
 * @version v0.0.1
 * @date    Aug-2017
 * @brief   Main program body
 ******************************************************************************
 * @attention
 * @par Revision history
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, WIZnet SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2016 WIZnet Co., Ltd.</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"

/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void)
{
    initSystemClock(EXTERNAL_CLOCK, PLL_8MHz, SYSTEM_48MHz);
    initSysTickTimerMs(1);

    while (1) {

    }

} // End of main


/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
void delay(__IO uint32_t milliseconds)
{
    TimingDelay = milliseconds;
    while (TimingDelay != 0)
        ;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00) {
        TimingDelay--;
    }
}

