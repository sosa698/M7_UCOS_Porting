/**
  ******************************************************************
  * @file    bsp_led.c
  * @author  Louis
  * @version V1.0
  * @date    2020.01.01
  * @brief   led���Ψ�Ƥ���
  ******************************************************************
  */  
  
#include "./led/bsp_led.h"   

 /**
  * @brief  ��l�Ʊ���LED��IO
  * @param  �L
  * @retval �L
  */
void LED_GPIO_Config(void)
{		
	/*�w�q�@��GPIO_InitTypeDef���������c��*/
	GPIO_InitTypeDef  GPIO_InitStruct;

	/*�}��LED������GPIO�~�]����*/
	LED0_GPIO_CLK_ENABLE();
	LED1_GPIO_CLK_ENABLE();
	LED2_GPIO_CLK_ENABLE();
	LED3_GPIO_CLK_ENABLE();

	/*��ܭn���GPIO���}*/															   
	GPIO_InitStruct.Pin = LED0_PIN;	

	/*�]�m���}����X������������X*/
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  

	/*�]�m���}���W�ԼҦ�*/
	GPIO_InitStruct.Pull  = GPIO_PULLUP;

	/*�]�m���}�t�v�����t */   
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; 

	/*�եΨ禡�w�A�ϥΤW���t�m��GPIO_InitStructure��l��GPIO*/
	HAL_GPIO_Init(LED0_GPIO_PORT, &GPIO_InitStruct);	

		/*��ܭn���GPIO���}*/															   
	GPIO_InitStruct.Pin = LED1_PIN;	
	HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);

	/*��ܭn���GPIO���}*/															   
	GPIO_InitStruct.Pin = LED2_PIN;	
	HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);	
	

	/*��ܭn���GPIO���}*/															   
	GPIO_InitStruct.Pin = LED3_PIN;	
	HAL_GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);	

		
}
/*********************************************END OF FILE**********************/
