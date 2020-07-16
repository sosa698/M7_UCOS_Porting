#ifndef __KEY_H
#define	__KEY_H

#include "stm32h7xx.h"
#include "main.h"
//接腳定義
/*******************************************************/
#define KEY1_PIN                  GPIO_PIN_0                 
#define KEY1_GPIO_PORT            GPIOA                      
#define KEY1_GPIO_CLK_ENABLE()    __GPIOA_CLK_ENABLE()

#define KEY2_PIN                  GPIO_PIN_13                 
#define KEY2_GPIO_PORT            GPIOC                      
#define KEY2_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
/*******************************************************/

 /** 按鍵按下標置巨集
	* 按鍵按下為高電位，設置 KEY_ON=1， KEY_OFF=0
	* 若按鍵按下為低電位，把函式設置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define KEY_ON	1
#define KEY_OFF	0

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /* __LED_H */
