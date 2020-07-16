
#include "./key/bsp_key.h" 

/**
  * @brief  �t�m����Ψ쪺I/O��
  * @param  �L
  * @retval �L
  */
void Key_GPIO_Config(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	/*�}�ҫ���GPIO�f������*/
	KEY1_GPIO_CLK_ENABLE();
	KEY2_GPIO_CLK_ENABLE();
	/*��ܫ��䪺���}*/	
	GPIO_InitStructure.Pin = KEY1_PIN; 
	/*�]�m���}����J�Ҧ�*/
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
	/*�]�m���}���W�Ԥ]���U��*/
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	/*�ϥΤW�������c���l�ƫ���*/
	HAL_GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	/*��ܫ��䪺���}*/
	GPIO_InitStructure.Pin = KEY2_PIN; 
	/*�ϥΤW�������c���l�ƫ���*/
	HAL_GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);  
}

/**
  * @brief   �˴��O�_��������U
  * @param   ���骺��M���
  *		@arg GPIOx: x�i�H�O�]A...G�^ 
  *		@arg GPIO_PIN �i�H�OGPIO_PIN_x�]x�i�H�O1...16�^
  * @retval  ���䪺���A
  *		@arg KEY_ON:������U
  *		@arg KEY_OFF:����S���U
  */

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)

{			

	/*�˴��O�_��������U */
	if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*���ݫ������� */
		while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
/****************************END OF FILE**************************/
