#ifndef __SCHM_H
#define __SCHM_H
/******************************************************************************
*   Filename:   SchM.h
*
*   Description:  
*
*
*   Revision history:
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
#include "typedefs.h"
#include "Os_Task.h"
#include "Os_TaskCfg.h"
#include "Os_TaskM.h"
/******************************************************************************
*   Macro Definitions  
******************************************************************************/

/******************************************************************************
*   Type Definitions
******************************************************************************/

/******************************************************************************
*   External Variables
******************************************************************************/
 
/******************************************************************************
*   Global Function Prototypes  
******************************************************************************/
/* TC0_Handler, function to be called upon timeout of PIT channel 0 */
extern void SchM_OsTick(void);
extern void SchM_Init(const TaskConfigType *SchM_Config);
extern void SchM_DeInit(void);
extern void SchM_Start(void);
extern void SchM_Background(void);
extern void Dispatcher(void);


#endif /*__SCHM_H*/
