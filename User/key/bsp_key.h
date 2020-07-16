#ifndef __KEY_H
#define	__KEY_H

#include "stm32h7xx.h"
#include "main.h"
//���}�w�q
/*******************************************************/
#define KEY1_PIN                  GPIO_PIN_0                 
#define KEY1_GPIO_PORT            GPIOA                      
#define KEY1_GPIO_CLK_ENABLE()    __GPIOA_CLK_ENABLE()

#define KEY2_PIN                  GPIO_PIN_13                 
#define KEY2_GPIO_PORT            GPIOC                      
#define KEY2_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
/*******************************************************/

 /** ������U�иm����
	* ������U�����q��A�]�m KEY_ON=1�A KEY_OFF=0
	* �Y������U���C�q��A��禡�]�m��KEY_ON=0 �AKEY_OFF=1 �Y�i
	*/
#define KEY_ON	1
#define KEY_OFF	0

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /* __LED_H */
