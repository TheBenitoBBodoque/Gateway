/******************************************************************************
 *   Filename:   Os_Task.c
 *
 *   Description:
 *
 *
 *   Revision History:
 *
 *   Date          CP#           Author
 *   MM-DD-YY      XXXXX:1       Initials   Description of change
 *   -----------   -----------   --------   ------------------------------------
 *   03-01-14       00            SPA        OS Task Initial Release
 *   03-29-14       00            SPA        OS Dispatcher and OSEK functions
 *   03-29-14       00            JMR        Fix Issues found in OS Dispatcher and OSEK functions
 *   05-20-16       00            SPA        Porting the OS Non-Preemtive to ATMEL SAM-V
 ******************************************************************************/

/******************************************************************************
 *   Include Files
 ******************************************************************************/
#include "board.h"
#include "Os_Task.h"
#include "typedefs.h"
//#include "led.h"
#include "dio.h"
#include "samv71q21.h"
#include "adc.h"
/******************************************************************************
 *   Local Macro Definitions
 ******************************************************************************/

/******************************************************************************
 *   Local Type Definitions
 ******************************************************************************/

/******************************************************************************
 *   Local Function Declarations
 ******************************************************************************/

/******************************************************************************
 *   Global Variable Definitions
 ******************************************************************************/
uint32 prueba_PMC_PCR;
/******************************************************************************
 *   Static Variable Definitions
 ******************************************************************************/
static uint8 variable = 0;
static uint8 variable2 = 0;
/******************************************************************************
 *   Global and Static Function Definitions
 ******************************************************************************/

/*****************************************************************************************************                                                                        
 *   Function: Task_1ms
 *
 *   Description: Scheduler task callback function 1ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_1ms)
{

    uint16 index;
    Status_Type Error_Result = E_OK;
    if(variable == 0)
    {
        variable = 1000;
        if(variable2 == 0)
        {
            variable2 = 1;
            prender_led();
            //AFEC_ConvertionStart();
        }
        else
        {
            variable2 = 0;
            apagar_led();
        }
    }
    else
    {
        variable--;;
    }
    Error_Result=TerminateTask();
}

/*****************************************************************************************************                                                                        
 *   Function: Task_4ms
 *
 *   Description: Scheduler task callback function 4ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_4ms)
{
	uint16 index;
	Status_Type Error_Result = E_OK;
	Error_Result=TerminateTask();
}

/*****************************************************************************************************                                                                        
 *   Function: Task_8ms
 *
 *   Description: Scheduler task callback function 8ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_8ms)
{
	uint16 index;
	Status_Type Error_Result = E_OK;
	Error_Result=TerminateTask();
}

/*****************************************************************************************************                                                                        
 *   Function: Task_16ms
 *
 *   Description: Scheduler task callback function 16ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_16ms)
{
	uint16 index;
	Status_Type Error_Result = E_OK;
	TerminateTask();
}

/*****************************************************************************************************                                                                        
 *   Function: Task_32ms
 *
 *   Description: Scheduler task callback function 32ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_32ms)
{
	uint16 index;
	Status_Type Error_Result = E_OK;
	Error_Result=TerminateTask();
}

/*****************************************************************************************************                                                                        
 *   Function: Task_64ms
 *
 *   Description: Scheduler task callback function 64ms
 *
 *   Caveats: Non Reentrant
 *****************************************************************************************************/
TASK (Task_64ms)
{
	uint16 index;
	Status_Type Error_Result = E_OK;

//	PMC->PMC_PCR = PMC_PCR_PID(ID_AFEC0);
//	prueba_PMC_PCR = PMC->PMC_PCR;



	Error_Result=TerminateTask();
}


