#ifndef __LED_H
#define	__LED_H

#include "stm32h7xx.h"

//接腳定義
/*******************************************************/

#define LED0_PIN                  GPIO_PIN_5                 
#define LED0_GPIO_PORT            GPIOB                      
#define LED0_GPIO_CLK_ENABLE()    __GPIOB_CLK_ENABLE()

#define LED1_PIN                  GPIO_PIN_5                 
#define LED1_GPIO_PORT            GPIOE                      
#define LED1_GPIO_CLK_ENABLE()    __GPIOE_CLK_ENABLE()

#define LED2_PIN                  GPIO_PIN_4                 
#define LED2_GPIO_PORT            GPIOB                      
#define LED2_GPIO_CLK_ENABLE()    __GPIOB_CLK_ENABLE()

#define LED3_PIN                  GPIO_PIN_6                 
#define LED3_GPIO_PORT            GPIOF                       
#define LED3_GPIO_CLK_ENABLE()    __GPIOF_CLK_ENABLE()
/************************************************************/


/** 控制LED燈亮滅的函式，
	* LED低電位亮，設置ON=0，OFF=1
	* 若LED高電位亮，把函式設置成ON=1 ，OFF=0 即可
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* 帶參數之巨集，可像內聯函數一樣使用 */
#define LED0(a)	HAL_GPIO_WritePin(LED0_GPIO_PORT,LED0_PIN,a)

#define LED1(a)	HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)


#define LED2(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)


#define LED3(a)	HAL_GPIO_WritePin(LED3_GPIO_PORT,LED3_PIN,a)


/* 直接操作暫存器的方法控制IO */
#define	digitalHi(p,i)				{p->BSRRL=i;}			  //設置為高電位		
#define digitalLo(p,i)				{p->BSRRH=i;}				//輸出低電位
#define digitalToggle(p,i)		{p->ODR ^=i;}			//輸出反轉狀態


/* 定義控制IO的函式 */

#define LED0_TOGGLE		digitalToggle(LED0_GPIO_PORT,LED0_PIN)
#define LED0_OFF			digitalHi(LED0_GPIO_PORT,LED0_PIN)
#define LED0_ON				digitalLo(LED0_GPIO_PORT,LED0_PIN)

#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF			digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON				digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF			digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON				digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF			digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON				digitalLo(LED3_GPIO_PORT,LED3_PIN)





void LED_GPIO_Config(void);

#endif /* __LED_H */
