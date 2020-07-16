/**
  ******************************************************************
  * @file    main.c
  * @author  Louis
  * @version  V1.0
  * @date    2020.01.01
  * @Project   GPIO輸出--使用函式庫點亮LED
  ******************************************************************/

	
#include "stm32h7xx.h"
#include "main.h"
#include "./led/bsp_led.h"
#include "bsp_debug_usart.h"
//#include "./delay/core_delay.h"   
__IO uint32_t 			TimingDelay = 0;
GPIO_InitTypeDef  GPIO_InitStruct;

/*
 * 任務控制碼是一個指標，用於指向一個任務，當任務建立好之後，它就具有了一個任務控制碼
 * 以後我們要想操作這個任務都需要通過這個任務控制碼，如果是自身的任務操作自己，那麼
 * 這個控制碼可以為NULL。
 */




static void LED_Task(void* pvParameters);// LED_Task任務實現 
static void LED1_Task(void* pvParameters);// KEY_Task任務實現 


int main(void)
{
	uint32_t i;
	SystemCoreClockUpdate();
	if (SysTick_Config(SystemCoreClock /1000)){ 
    while (1);
  }	
	
	LED_GPIO_Config();
  DEBUG_USART_Config();
	
	

	/* 控制LED燈 */
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
  * @ 函數名  ： LED_Task
  * @ 功能說明： LED_Task任務主體
  * @ 參數    ：   
  * @ 返回值  ： 無
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
