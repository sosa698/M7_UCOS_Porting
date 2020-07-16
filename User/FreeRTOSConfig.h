/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "stm32h7xx.h"
#include "bsp_debug_usart.h"


//�w�藍�P���sĶ���եΤ��P��stdint.h���
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

//�_��
#define vAssertCalled(char,int) printf("Error:%s,%d\r\n",char,int)
#define configASSERT(x) if((x)==0) vAssertCalled(__FILE__,__LINE__)

/************************************************************************
 *               FreeRTOS��¦�t�m�t�m�ﶵ 
 *********************************************************************/
/* �m1�GRTOS�ϥηm�����ի׾��F�m0�GRTOS�ϥΨ�@���ի׾��]�ɶ����^
 * 
 * �`�G�b�h�u�޲z����W�A�@�~�t�Υi�H�����m�����M��@����ءC
 * ��@���@�~�t�άO���ȥD������CPU��A������U�@�ӥ��ȡC
 * ���Ȥ������ɾ��������M�󥿦b�B�檺���ȡC
 */
#define configUSE_PREEMPTION					  1

//1�m��ɶ����ի�(�w�]���m�઺)
#define configUSE_TIME_SLICING					1		

/* �Y�ǹB��FreeRTOS���w�馳��ؤ�k��ܤU�@�ӭn���檺���ȡG
 * �q�Τ�k�M�S�w��w�骺��k�]�H�U²�١��S���k���^�C
 * 
 * �q�Τ�k�G
 *      1.configUSE_PORT_OPTIMISED_TASK_SELECTION �� 0 �Ϊ̵w�餣�䴩�o�دS���k�C
 *      2.�i�H�Ω�Ҧ�FreeRTOS�䴩���w��
 *      3.������C��{�A�Ĳv���C��S���k�C
 *      4.���j��n�D����̤j�i���u�����Ǽƥ�
 * �S���k�G
 *      1.�����NconfigUSE_PORT_OPTIMISED_TASK_SELECTION�]�m��1�C
 *      2.�̿�@�өΦh�ӯS�w�[�c���J�s���O�]�@��O�����p��e�m�r�����s[CLZ]���O�^�C
 *      3.��q�Τ�k�󰪮�
 *      4.�@��j��w�̤j�i���u�����Ǽƥج�32
 * �@��O�w��p��e�m�r�����s���O�A�p�G�ҨϥΪ��AMCU�S���o�ǵw����O���ܦ��������ӳ]�m��0�I
 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	        1                       
                                                                        
/* �m1�G�m��C�\��tickless�Ҧ��F�m0�G�O���t�θ`��]tick�^���_�@���B��
 * ���]�}�ҧC�\�Ӫ��ܥi��|�ɭP�U���X�{���D�A�]���{���b�ίv��,�i�ΥH�U��k�ѨM
 * 
 * �U����k�G
 *      1.�N�}�o�����`�s���n
 *      2.�����w����A�I���U�������P�}���w����
 *     
 *      1.�q�L���u�U�N BOOT 0 �����q��(3.3V)
 *      2.���s�W�q�A�U��
 *    
 * 			1.�ϥ�FlyMcu�����@�U�����A�M��i��U��
 *			STMISP -> �M������(z)
 */
#define configUSE_TICKLESS_IDLE													0   

/*
 * �g�J��ڪ�CPU���֮����W�v�A�]�N�OCPU���O�����W�v�A�q�`�٬�Fclk
 * Fclk���ѵ�CPU���֪������H���A�ڭ̩һ���cpu�D�W�� XX MHz�A
 * �N�O�����o�Ӯ����H���A�������A1/Fclk�Y��cpu�����g���F
 */
#define configCPU_CLOCK_HZ						  (SystemCoreClock)

//RTOS�t�θ`�礤�_���W�v�C�Y�@���_�����ơA�C�����_RTOS���|�i����Ƚի�
#define configTICK_RATE_HZ						  (( TickType_t )1000)

//�i�ϥΪ��̤j�u������
#define configMAX_PRIORITIES					  (32)

//�Ŷ����ȨϥΪ����|�j�p
#define configMINIMAL_STACK_SIZE				((unsigned short)128)
  
//���ȦW�r�r�����
#define configMAX_TASK_NAME_LEN					(16)

 //�t�θ`��p�ƾ��ܼƸ�������A1��ܬ�16�줸�L�Ÿ���ΡA0��ܬ�32�줸�L�Ÿ����
#define configUSE_16_BIT_TICKS					0                      

//�Ŷ����ȩ��CPU�ϥ��v����L�P�u�����Ǫ��Τ����
#define configIDLE_SHOULD_YIELD					1           

//�ҥΦ�C
#define configUSE_QUEUE_SETS					  0    

//�}�ҥ��ȳq���\��A�w�]�}��
#define configUSE_TASK_NOTIFICATIONS    1   

//�ϥΤ����H���q
#define configUSE_MUTEXES						    0    

//�ϥλ��j�����H���q                                            
#define configUSE_RECURSIVE_MUTEXES			0   

//��1�ɨϥέp�ƫH���q
#define configUSE_COUNTING_SEMAPHORES		0

/* �]�m�i�H���U���H���q�M�T����C�Ӽ� */
#define configQUEUE_REGISTRY_SIZE				10                                 
                                                                       
#define configUSE_APPLICATION_TASK_TAG		  0                       
                      

/*****************************************************************
              FreeRTOS�P�O����ӽЦ����t�m�ﶵ                                               
*****************************************************************/
//�䴩�ʺA�O����ӽ�
#define configSUPPORT_DYNAMIC_ALLOCATION        1    
//�䴩�R�A�O����
#define configSUPPORT_STATIC_ALLOCATION					0					
//�t�ΩҦ��`����j�p
#define configTOTAL_HEAP_SIZE					((size_t)(36*1024))    


/***************************************************************
             FreeRTOS�PHook��Ʀ������t�m�ﶵ                                            
**************************************************************/
/* �m1�G�ϥΪŶ�Hook�]Idle Hook������^�I��ơ^�F�m0�G�����Ŷ�Hook
 * 
 * �Ŷ�����Hook�O�@�Ө�ơA�o�Ө�ƥѨϥΪ̨ӹ�{�A
 * FreeRTOS�W�w�F��ƪ��W�r�M�ѼơGvoid vApplicationIdleHook(void )�A
 * �o�Ө�Ʀb�C�ӪŶ����ȶg�����|�Q�ե�
 * ���w�g�R����RTOS���ȡA�Ŷ����ȥi�H������t�����̪����|�O����C
 * �]�������O�ҪŶ����ȥi�H�QCPU����
 * �ϥΪŶ�Hook��Ƴ]�mCPU�i�J�ٹq�Ҧ��O�ܱ`����
 * ���i�H�եη|�ް_�Ŷ����Ȫ��몺API���
 */
#define configUSE_IDLE_HOOK						0      

/* �m1�G�ϥήɶ���Hook�]Tick Hook�^�F�m0�G�����ɶ���Hook
 * 
 * 
 * �ɶ���Hook�O�@�Ө�ơA�o�Ө�ƥѨϥΪ̨ӹ�{�A
 * FreeRTOS�W�w�F��ƪ��W�r�M�ѼơGvoid vApplicationTickHook(void )
 * �ɶ������_�i�H�g���ʪ��ե�
 * ��ƥ����D�`�u�p�A����j�q�ϥΰ��|�A
 * ����եΥH��FromISR" �� "FROM_ISR��������API���
 */
 /*xTaskIncrementTick��ƬO�bxPortSysTickHandler���_��Ƥ��Q�եΪ��C�]���AvApplicationTickHook()��ư��檺�ɶ������ܵu�~��*/
#define configUSE_TICK_HOOK						0           

//�ϥΰO����ӽХ��Ѩ��
#define configUSE_MALLOC_FAILED_HOOK			0 

/*
 * �j��0�ɱҥΰ��|�����˴��\��A�p�G�ϥΦ��\�� 
 * �ϥΪ̥������Ѥ@�Ӵ̷��XHook��ơA�p�G�ϥΪ���
 * ���ȥi�H��1�Ϊ�2�A�]������ش̷��X�˴���k */
#define configCHECK_FOR_STACK_OVERFLOW			0   


/********************************************************************
          FreeRTOS�P����ɶ��M���Ȫ��A�����������t�m�ﶵ   
**********************************************************************/
//�ҥΰ���ɶ��έp�\��
#define configGENERATE_RUN_TIME_STATS	        0             
 //�ҥε�ı�Ƹ��ܽո�
#define configUSE_TRACE_FACILITY				      0    
/* �P�禡configUSE_TRACE_FACILITY�P�ɬ�1�ɷ|�sĶ�U��3�Ө��
 * prvWriteNameToBuffer()
 * vTaskList(),
 * vTaskGetRunTimeStats()
*/
#define configUSE_STATS_FORMATTING_FUNCTIONS	1                       
                                                                        
                                                                        
/********************************************************************
                FreeRTOS�P��{�������t�m�ﶵ                                                
*********************************************************************/
//�ҥΨ�{�A�ҥΨ�{�H�ᥲ���K�[��croutine.c
#define configUSE_CO_ROUTINES 			          0                 
//��{�������u�����Ǽƥ�
#define configMAX_CO_ROUTINE_PRIORITIES       ( 2 )                   


/***********************************************************************
                FreeRTOS�P�n��p�ɾ��������t�m�ﶵ      
**********************************************************************/
 //�ҥγn��p�ɾ�
#define configUSE_TIMERS				            0                              
//�n��p�ɾ��u������
#define configTIMER_TASK_PRIORITY		        (configMAX_PRIORITIES-1)        
//�n��p�ɾ���C����
#define configTIMER_QUEUE_LENGTH		        10                               
//�n��p�ɾ����Ȱ��|�j�p
#define configTIMER_TASK_STACK_DEPTH	      (configMINIMAL_STACK_SIZE*2)    

/************************************************************
            FreeRTOS�i���ưt�m�ﶵ                                                     
************************************************************/
#define INCLUDE_xTaskGetSchedulerState       1                       
#define INCLUDE_vTaskPrioritySet		         1
#define INCLUDE_uxTaskPriorityGet		         1
#define INCLUDE_vTaskDelete				           1
#define INCLUDE_vTaskCleanUpResources	       1
#define INCLUDE_vTaskSuspend			           1
#define INCLUDE_vTaskDelayUntil			         1
#define INCLUDE_vTaskDelay				           1
#define INCLUDE_eTaskGetState			           1
#define INCLUDE_xTimerPendFunctionCall	     0
//#define INCLUDE_xTaskGetCurrentTaskHandle       1
//#define INCLUDE_uxTaskGetStackHighWaterMark     0
//#define INCLUDE_xTaskGetIdleTaskHandle          0


/******************************************************************
            FreeRTOS�P���_�������t�m�ﶵ                                                 
******************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif
//���_�̧C�u������
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15     

//�t�Υi�޲z���̰����_�u������
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5 

#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )	/* 240 */

#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )


/****************************************************************
            FreeRTOS�P���_�A�Ȩ�Ʀ������t�m�ﶵ                         
****************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler


/* �H�U���ϥ�Percepio Tracealyzer�ݭn���F��A���ݭn�ɱN configUSE_TRACE_FACILITY �w�q�� 0 */
#if ( configUSE_TRACE_FACILITY == 1 )
#include "trcRecorder.h"
#define INCLUDE_xTaskGetCurrentTaskHandle           1   // �ҥΤ@�ӥi���ơ]�Ө�ƳQ Trace�{���X�ϥΡA�w�]�ӭȬ�0 ��ܤ��Ρ^
#endif


#endif /* FREERTOS_CONFIG_H */

