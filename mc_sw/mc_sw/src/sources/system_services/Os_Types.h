#ifndef __OS_TYPES_H
#define __OS_TYPES_H
/******************************************************************************
*   Filename:   Os_Types.h
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
/******************************************************************************
*   Macro Definitions  
******************************************************************************/

#ifndef TASK
#define TASK(taskID) void taskID(void)
#endif

#define DeclareTask(taskID) extern TASK(taskID)

/******************************************************************************
*   Type Definitions
******************************************************************************/
/* Identifies a task state */
typedef uint8 TaskStateType;

/* Identifies a task, commonly associated with the TaskID */
typedef uint16 TaskType;

/* Reference to a variable of type TaskOffsetType */
typedef uint16 TaskOffsetType;

/* Reference to a variable of type TaskMaskType */
typedef uint16 TaskMaskType;

/* Reference to a variable of type TaskStackSize */
typedef uint16 TaskStackSize;

/* Reference to a variable of type TaskRelDeadline */
typedef uint16 TaskRelDeadline;

/* Reference to a variable of type TaskType */
typedef TaskType* TaskRefType;

/* Reference to a variable of type TaskStateType */
typedef TaskStateType* TaskStateRefType;

typedef enum
{
   TASK_1MS = 0,
   TASK_4MS,
   TASK_8MS,
   TASK_16MS,
   TASK_32MS,
   TASK_64MS,
   MAX_NUM_TASK
}TaskID;

typedef enum
{
   PRIORITY_0 = 0,
   PRIORITY_1,
   PRIORITY_2,
   PRIORITY_3,
   PRIORITY_4,
   PRIORITY_5,
   MAX_PRIORITY
}TaskPriority;

typedef enum
{
   E_OK = 0,
   E_OS_ACCESS,
   E_OS_CALLEVEL,
   E_OS_ID,
   E_OS_LIMIT,
   E_OS_NOFUNC,
   E_OS_RESOURCE,
   E_OS_STATE,
   E_OS_VALUE
}Status_Type;

typedef enum 
{
   SUSPENDED = 0,
   READY,
   RUNNING
}TaskStates;

typedef struct
{
  uint16 StartAddress;
  uint16 EndAddress;
}StackInformation;

typedef struct
{
  uint16 Relative;
  uint16 Absolute;
}TaskDeadline;

typedef struct
{
  TaskID              Task_ID;
  TaskPriority        Task_Priority;
  TaskStates          Task_State;
  StackInformation    Stack_Information;
  TaskDeadline        Task_Deadline;
}Task_Control_Block;

typedef struct
{
  TaskID              Task_ID;
  TaskPriority        Task_Priority;
  TaskMaskType        Mask;
  TaskOffsetType      Offset;
  TaskStackSize       Size;
  TaskRelDeadline     RelDeadline;
  void(*TaskCallback)(void);
}Task_Descriptor;



/******************************************************************************
*   External Variables
******************************************************************************/
 
/******************************************************************************
*   Global Function Prototypes  
******************************************************************************/
#endif /*__OS_TYPES_H*/
