/******************************************************************************
*   Filename:   Os_TaskCfg.c 
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
*   03-29-14       00            EBA        Fix more issues
*   05-20-16       00            SPA        Porting the OS Non-Preemtive to ATMEL SAM-V
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/ 
#include "board.h"
#include "Os_TaskCfg.h"
#include "Os_Task.h"
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
const Task_Descriptor TaskInitial[]=
{
  {TASK_1MS, PRIORITY_5, MASK_1MS, OFFSET_00,0,0,Task_1ms},
  {TASK_4MS, PRIORITY_4, MASK_4MS, OFFSET_01,0,0,Task_4ms},
  {TASK_8MS, PRIORITY_2, MASK_8MS, OFFSET_03,0,0,Task_8ms},
  {TASK_16MS,PRIORITY_3,MASK_16MS, OFFSET_05,0,0,Task_16ms},
  {TASK_32MS,PRIORITY_0,MASK_32MS, OFFSET_07,0,0,Task_32ms},
  {TASK_64MS,PRIORITY_0,MASK_64MS, OFFSET_11,0,0,Task_64ms}  
};

const TaskConfigType TaskConfigInitial[]=
{
  {
    sizeof(TaskInitial)/sizeof(TaskInitial[0]), 
    &TaskInitial[0U]
  }
};

uint16 DispacherArray[MAX_PRIORITY][CNF_MAXTASKQUEUE];

Task_Control_Block TaskControlBlock[MAX_NUM_TASK];
 
/******************************************************************************
*   Static Variable Definitions
******************************************************************************/

/******************************************************************************
*   Global and Static Function Definitions
******************************************************************************/ 
