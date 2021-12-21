/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 18 DEC, 2021                            */
/**********************************************************/
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
	u8 Priority;
	u8 TaskState;
	u16 Periodicity;
	void (*TaskFunc)(void);
}Task_t;

static void voidScheduler(void);


#endif