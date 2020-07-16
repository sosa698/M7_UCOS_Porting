
#include "bsp_debug_usart.h"

UART_HandleTypeDef UartHandle;
extern uint8_t ucTemp;  
 /**
  * @brief  DEBUG_USART GPIO �t�m,�u�@�Ҧ��t�m�C115200 8-N-1
  * @param  �L
  * @retval �L
  */  
void DEBUG_USART_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;
        
    DEBUG_USART_RX_GPIO_CLK_ENABLE();
    DEBUG_USART_TX_GPIO_CLK_ENABLE();
    
    /* �t�m��C��1������*/
		RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
		RCC_PeriphClkInit.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
		HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);
    /* �P���C��1���� */
    DEBUG_USART_CLK_ENABLE();

    /* �t�mTx���}���ƥΥ\��  */
    GPIO_InitStruct.Pin = DEBUG_USART_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = DEBUG_USART_TX_AF;
    HAL_GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStruct);
    
    /* �t�mRx���}���ƥΥ\�� */
    GPIO_InitStruct.Pin = DEBUG_USART_RX_PIN;
    GPIO_InitStruct.Alternate = DEBUG_USART_RX_AF;
    HAL_GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStruct); 
    
    /* �t�m��DEBUG_USART �Ҧ� */
    UartHandle.Instance = DEBUG_USART;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
    UartHandle.Init.OneBitSampling = UART_ONEBIT_SAMPLING_DISABLED;
    UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    HAL_UART_Init(&UartHandle);

    /*��C��1���_��l�� */
    HAL_NVIC_SetPriority(DEBUG_USART_IRQ, 6, 0);
    HAL_NVIC_EnableIRQ(DEBUG_USART_IRQ);
    /*�t�m��C�𱵦����_ */
    __HAL_UART_ENABLE_IT(&UartHandle,UART_IT_RXNE);  
}


/*****************  �o�e�r�� **********************/
void Usart_SendString(uint8_t *str)
{
	unsigned int k=0;
  do 
  {
      HAL_UART_Transmit( &UartHandle,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
  
}

int fputc(int ch, FILE *f)
{
	/* �o�e�@�Ӧ줸�ո�ƨ��C��DEBUG_USART */
	HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 1000);	
	
	return (ch);
}

///���w�Vc�w���scanf���C��DEBUG_USART�A���g�V��i�ϥ�scanf�Bgetchar�����
int fgetc(FILE *f)
{
		
	int ch;
	HAL_UART_Receive(&UartHandle, (uint8_t *)&ch, 1, 1000);	
	return (ch);
}
/*********************************************END OF FILE**********************/