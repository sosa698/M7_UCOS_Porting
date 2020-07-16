/**
  ******************************************************************
  * @file    main.c
  * @author  Louis
  * @version  V1.0
  * @date    2020.01.01
  * @Project   GPIO��X--�ϥΨ禡�w�I�GLED
  ******************************************************************/

	
#include "stm32h7xx.h"
#include "main.h"
#include "./led/bsp_led.h"
#include "bsp_debug_usart.h"
//#include "./delay/core_delay.h"   
__IO uint32_t 			TimingDelay = 0;
GPIO_InitTypeDef  GPIO_InitStruct;

/*
 * ���ȱ���X�O�@�ӫ��СA�Ω���V�@�ӥ��ȡA����ȫإߦn����A���N�㦳�F�@�ӥ��ȱ���X
 * �H��ڭ̭n�Q�ާ@�o�ӥ��ȳ��ݭn�q�L�o�ӥ��ȱ���X�A�p�G�O�ۨ������Ⱦާ@�ۤv�A����
 * �o�ӱ���X�i�H��NULL�C
 */




static void LED_Task(void* pvParameters);// LED_Task���ȹ�{ 
static void LED1_Task(void* pvParameters);// KEY_Task���ȹ�{ 


int main(void)
{
	uint32_t i;
	SystemCoreClockUpdate();
	if (SysTick_Config(SystemCoreClock /1000)){ 
    while (1);
  }	
	
	LED_GPIO_Config();
  DEBUG_USART_Config();
	
	

	/* ����LED�O */
	while (1){
		LED0( ON );
		printf("LED_Task Running,LED_ON\r\n");
		for(i=0;i<1000000;i++);
		LED0( OFF );     
		printf("LED_Task Running,LED_OFF\r\n");
		for(i=0;i<1000000;i++);
	}

}



/**********************************************************************
  * @ ��ƦW  �G LED_Task
  * @ �\�໡���G LED_Task���ȥD��
  * @ �Ѽ�    �G   
  * @ ��^��  �G �L
  ********************************************************************/
static void LED_Task(void* parameter)
{	
  while (1)
  {	
    LED0( ON );
    printf("LED_Task Running,LED_ON\r\n");
    
    LED0( OFF );     
    printf("LED_Task Running,LED_OFF\r\n");

  }
}

static void LED1_Task(void* parameter)
{	
  while (1)
  {	
    LED1( ON );
    printf("LED_Task Running,LED1_ON\r\n");
    
    LED1( OFF );     
    printf("LED_Task Running,LED1_OFF\r\n");
  }
}




/****************************END OF FILE***************************/
