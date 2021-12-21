/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 18 DEC, 2021                            */
/**********************************************************/



Task_t SystemTasks[NUM_SYSTEM_TASKS] = {{NULL}};

void RTOS_voidInit(void)
{
	/*Set Callback Timer 0*/
	TIMERS_voidTimer0CTCSetCallBackFunction(&voidScheduler);
	/*Set The Compare Match Value To Be 125, To Make A CTC Event Every 1msec*/
	TIMERS_voidTimer0SetCompareMatchValue(125);
	/*Enable Global Interrupt*/
	GIE_voidEnableGlobalInterrupt();
	/*Initiate Timer0*/
	TIMERS_voidTimer0Init();
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void))
{
	SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunc    = Copy_pvTaskFunc;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}

#define SUSPEND		0
#define READY		1


void RTOS_voidChangeState(u8 Copy_u8Priority, u8 Copy_u8TaskState)
{
	SystemTasks[Copy_u8Priority].TaskState = Copy_u8TaskState;
}

static void voidScheduler(void)
{
	static u32 Local_u32TickCounter = 0;
	Local_u32TickCounter++;
	u8 Local_u8LoopCounter;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUM_SYSTEM_TASKS; Local_u8LoopCounter++)
	{
		if(SystemTasks[Local_u8LoopCounter].TaskState != SUSPEND)
		{
			if((Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity) == 0)
			{
					/*Invoke The Task Function*/
					if(SystemTasks[Local_u8LoopCounter].TaskFunc != NULL)
					{
						SystemTasks[Local_u8LoopCounter].TaskFunc();
					}
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
}