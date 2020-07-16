#ifndef __MAIN_H
#define __MAIN_H

#include "stm32h7xx_hal.h"
#include "stm32h7xx.h"

static void SystemClock_Config(void);
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);
#endif /* __MAIN_H */

