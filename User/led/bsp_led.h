#ifndef __LED_H
#define	__LED_H

#include "stm32h7xx.h"

//���}�w�q
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


/** ����LED�O�G�����禡�A
	* LED�C�q��G�A�]�mON=0�AOFF=1
	* �YLED���q��G�A��禡�]�m��ON=1 �AOFF=0 �Y�i
	*/
#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

/* �a�ѼƤ������A�i�����p��Ƥ@�˨ϥ� */
#define LED0(a)	HAL_GPIO_WritePin(LED0_GPIO_PORT,LED0_PIN,a)

#define LED1(a)	HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)


#define LED2(a)	HAL_GPIO_WritePin(LED2_GPIO_PORT,LED2_PIN,a)


#define LED3(a)	HAL_GPIO_WritePin(LED3_GPIO_PORT,LED3_PIN,a)


/* �����ާ@�Ȧs������k����IO */
#define	digitalHi(p,i)				{p->BSRRL=i;}			  //�]�m�����q��		
#define digitalLo(p,i)				{p->BSRRH=i;}				//��X�C�q��
#define digitalToggle(p,i)		{p->ODR ^=i;}			//��X���બ�A


/* �w�q����IO���禡 */

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
