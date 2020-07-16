
#include "./key/bsp_key.h" 

/**
  * @brief  配置按鍵用到的I/O埠
  * @param  無
  * @retval 無
  */
void Key_GPIO_Config(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	/*開啟按鍵GPIO口的時鐘*/
	KEY1_GPIO_CLK_ENABLE();
	KEY2_GPIO_CLK_ENABLE();
	/*選擇按鍵的接腳*/	
	GPIO_InitStructure.Pin = KEY1_PIN; 
	/*設置接腳為輸入模式*/
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
	/*設置接腳不上拉也不下拉*/
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	/*使用上面的結構體初始化按鍵*/
	HAL_GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	/*選擇按鍵的接腳*/
	GPIO_InitStructure.Pin = KEY2_PIN; 
	/*使用上面的結構體初始化按鍵*/
	HAL_GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);  
}

/**
  * @brief   檢測是否有按鍵按下
  * @param   具體的埠和埠位
  *		@arg GPIOx: x可以是（A...G） 
  *		@arg GPIO_PIN 可以是GPIO_PIN_x（x可以是1...16）
  * @retval  按鍵的狀態
  *		@arg KEY_ON:按鍵按下
  *		@arg KEY_OFF:按鍵沒按下
  */

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)

{			

	/*檢測是否有按鍵按下 */
	if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*等待按鍵釋放 */
		while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
/****************************END OF FILE**************************/
