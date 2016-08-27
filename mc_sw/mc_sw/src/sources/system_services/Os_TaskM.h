#ifndef __OS_TASKM_H_
#define __OS_TASKM_H_
/******************************************************************************
*   Filename:   Os_TaskM.h
*
*   Description:  
*
*
*   Revision history:
*
*   Date          CP#           Author     
*   MM-DD-YY      XXXXX:1       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   03-29-14       00            SPA        OS Dispatcher and OSEK functions
*   03-29-14       00            JMR        Fix Issues found in OS Dispatcher and OSEK functions
*   05-20-16       00            SPA        Porting the OS Non-Preemtive to ATMEL SAM-V
******************************************************************************/
#include "Os_Task.h"

/******************************************************************************
*   Macro Definitions  
******************************************************************************/

/******************************************************************************
*   Type Definitions
******************************************************************************/

/******************************************************************************
*   External Variables
******************************************************************************/
extern uint16 TaskExecuted_ID; 
/******************************************************************************
*   Global Function Prototypes  
******************************************************************************/

extern Status_Type ActivateTask(TaskType taskID);
extern Status_Type TerminateTask (void);
extern Status_Type GetTaskID(TaskRefType taskIDRef);
extern Status_Type GetTaskState(TaskType taskID, TaskStateRefType stateRef);

#endif /*__OS_TASKM_H_*/
