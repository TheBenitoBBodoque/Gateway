#ifndef __OS_TASKCFG_H
#define __OS_TASKCFG_H
/******************************************************************************
*   Filename:   Os_TaskCfg.h
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
*   03-29-14       00            EBA        Fix more issues
*   05-20-16       00            SPA        Porting the OS Non-Preemtive to ATMEL SAM-V
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "Os_Types.h"

/******************************************************************************
*   Macro Definitions  
******************************************************************************/
/* Task mask definition */
#define MASK_1MS   ((uint16)(0x0001)) /* 0000 0001 */
#define MASK_4MS   ((uint16)(0x0007)) /* 0000 0111 */
#define MASK_8MS   ((uint16)(0x000F)) /* 0000 1111 */
#define MASK_16MS  ((uint16)(0x001F)) /* 0001 1111 */
#define MASK_32MS  ((uint16)(0x003F)) /* 0011 1111 */
#define MASK_64MS  ((uint16)(0x007F)) /* 0111 1111 */

/* Task mask offset */
#define OFFSET_00  ((uint16)(0))
#define OFFSET_01  ((uint16)(1))
#define OFFSET_03  ((uint16)(3))
#define OFFSET_05  ((uint16)(5))
#define OFFSET_07  ((uint16)(7))
#define OFFSET_11  ((uint16)(11))
#define OFFSET_13  ((uint16)(13))

/* Defines to be used for the OS tick and Scheduler flags*/
#define SCHM_OSTICK_ENABLED     (1u)
#define SCHEDULER_ENABLED       (1u)
#define SCHM_OSTICK_DISABLED    (0u)
#define SCHEDULER_DISABLED      (0u)

#define CNF_MAXTASKQUEUE ((uint16)(5))
/******************************************************************************
*   Type Definitions
******************************************************************************/
typedef struct
{
   TaskID TaskNumberConfig;
   const Task_Descriptor *ptr_Task;  
}TaskConfigType;

/******************************************************************************
*   External Variables
******************************************************************************/
extern const TaskConfigType TaskConfigInitial[];
extern uint16 DispacherArray[MAX_PRIORITY][CNF_MAXTASKQUEUE];
extern Task_Control_Block TaskControlBlock[MAX_NUM_TASK];
/******************************************************************************
*   Global Function Prototypes  
******************************************************************************/

#endif /*__OS_TASKCFG_H*/
