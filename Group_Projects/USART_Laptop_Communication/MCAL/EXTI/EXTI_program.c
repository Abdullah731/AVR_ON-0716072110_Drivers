#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*Global_pvInt0NotificationFunction)(void) = NULL;

void EXTI_voidIntInit(void)
{
    #if   EXTI_INT0_ENABLE == ENABLE
            /*Enable INT0*/
            SET_BIT(GICR, GICR_INT0);
            /*Set INT0 Sense Control*/
            #if   EXTI_INT0_SENSE_CTRL == FALLING_EDGE
                    SET_BIT(MCUCR, MCUCR_ISC01);
                    CLR_BIT(MCUCR, MCUCR_ISC00);
            #elif EXTI_INT0_SENSE_CTRL == RISING_EDGE
            		SET_BIT(MCUCR, MCUCR_ISC01);
                    SET_BIT(MCUCR, MCUCR_ISC00);
            #elif EXTI_INT0_SENSE_CTRL == ON_CHANGE
            		CLR_BIT(MCUCR, MCUCR_ISC01);
                    SET_BIT(MCUCR, MCUCR_ISC00);
            #elif EXTI_INT0_SENSE_CTRL == LOW_LEVEL
                	CLR_BIT(MCUCR, MCUCR_ISC01);
                    CLR_BIT(MCUCR, MCUCR_ISC00);
            #else
                #error "EXTI_INT0_SENSE_CTRL Error Configuration"
            #endif
            
    #elif EXTI_INT0_ENABLE == DISABLE
            CLR_BIT(GICR, GICR_INT0);
    #else
        #error "EXTI_INT0_ENABLE Error Configuration"
    #endif
    
    
    #if   EXTI_INT1_ENABLE == ENABLE
            SET_BIT(GICR, GICR_INT1);
    #elif EXTI_INT1_ENABLE == DISABLE
            CLR_BIT(GICR, GICR_INT1);
    #else
        #error "EXTI_INT1_ENABLE Error Configuration"
    #endif
    
    #if   EXTI_INT2_ENABLE == ENABLE
            SET_BIT(GICR, GICR_INT2);
    #elif EXTI_INT2_ENABLE == DISABLE
            CLR_BIT(GICR, GICR_INT2);
    #else
        #error "EXTI_INT2_ENABLE Error Configuration"
    #endif
}


void EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		break;
		
		case RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		break;
		
		case ON_CHANGE:
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);	
		break;
		
		case LOW_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);	
		break;
		
		default:
			// Error To Be Displayed
		break;
	}
}

void EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
		
		case RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		break;
		
		case ON_CHANGE:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);	
		break;
		
		case LOW_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);	
		break;
		
		default:
			// Error To Be Displayed
		break;
	}
}

void EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
		break;
		
		case RISING_EDGE:
			SET_BIT(MCUCSR, MCUCSR_ISC2);
		break;
		
		default:
			// Error To Be Displayed
		break;
	}
}



/****
void EXTI_voidSetIntSenseControl(u8 Copy_u8InterruptID, u8 Copy_u8SenseControl)
{
	switch(Copy_u8InterruptID)
	{
		case INT0:
			
		break;
		
		case INT1:
		
		break;
		
		case INT2:
		break;
		
		default:
		break;

	}
}
***/

void EXTI_voidInt0Control(u8 Copy_u8Int0State)
{
	switch(Copy_u8Int0State)
	{
		case ENABLE:
			SET_BIT(GICR, GICR_INT0);
		break;
		
		case DISABLE:
			CLR_BIT(GICR, GICR_INT0);
		break;
		
		default:
		
		break;
	}
}

void EXTI_voidInt1Control(u8 Copy_u8Int1State)
{
	switch(Copy_u8Int1State)
	{
		case ENABLE:
			SET_BIT(GICR, GICR_INT1);
		break;
		
		case DISABLE:
			CLR_BIT(GICR, GICR_INT1);
		break;
		
		default:
		
		break;
	}
}

void EXTI_voidInt2Control(u8 Copy_u8Int2State)
{
	switch(Copy_u8Int2State)
	{
		case ENABLE:
			SET_BIT(GICR, GICR_INT2);
		break;
		
		case DISABLE:
			CLR_BIT(GICR, GICR_INT2);
		break;
		
		default:
		
		break;
	}
}



void EXTI_voidInt0SetCallBack(void (*Copy_pvNotificationFunction)(void))
{
    Global_pvInt0NotificationFunction = Copy_pvNotificationFunction;
}

/*ISR For INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    if(Global_pvInt0NotificationFunction != NULL)
    {
        Global_pvInt0NotificationFunction();
    }
    else
    {
        /*Do Nothing*/
    }
}