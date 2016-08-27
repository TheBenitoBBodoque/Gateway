/******************************************************************************
*   Filename:   systick.c
*
*   Description: This is the HAL for the Systick peripheral.
*
*
*   Revision History:
*
*   Date          CP#           Author
*   MM-DD-YY      XXXXX:1       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   05-08-16       00            SPA        Gateway Initial Release
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "samv71q21.h"
#include "core_cm7.h"
#include "systick.h"
#include "dio.h"

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
volatile uint8 systick_timming;
/******************************************************************************
*   Static Variable Definitions
******************************************************************************/

/******************************************************************************
*   Global and Static Function Definitions
******************************************************************************/
void (*Systick_Callback_local) (void);
/*****************************************************************************************************
*   Function: systick_init
*
*   Description: Systick Initialization
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void systick_init (void(*func_ptr)(void))
{
    Systick_Callback_local =  func_ptr;
}

void systick_driver_init (void)
{
    /* 6250 for .5ms or 12500 for 1ms timebase with the processor running at 100Mhz*/
    SysTick_Config(12500);
}

void SysTick_Handler( void )
{
    SCB->ICSR |= SCB_ICSR_PENDSTCLR_Msk;

    /* TODO : SPA2 -  Prueba que el systick esta configurado correctamente - Begin */
    if(systick_timming == 0)
    {
        systick_timming = 1;
        prender_led();
    }
    else
    {
        systick_timming = 0;
        apagar_led();
    }
    /* TODO : SPA2 -  Prueba que el systick esta configurado correctamente - End */
    Systick_Callback_local();
}
