/******************************************************************************
*   Filename:   clock.c
*
*   Description: This file is the abstraction for the PMC peripheral.
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
#include "clock.h"
#include <sysclk.h>

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

/******************************************************************************
*   Static Variable Definitions
******************************************************************************/

/******************************************************************************
*   Global and Static Function Definitions
******************************************************************************/

/*****************************************************************************************************
*   Function: Task_1ms
*
*   Description: Interrupt handler for TC0 interrupt.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void clock_init (void)
{
    //uint8 variable;
    /* PMC System Clock Enable Register */
    /* The 3 to 20Mhz Crystal Oscillator is enabled */
    /* The 3 to 20Mhz Crystal Oscillator Bypass */
    /* The 3 to 20Mhz Crystal Oscillator Start-up Time */
    /* MOSCSEL : Main Clock Oscillator Selection - 3 to 20Mhz Crystal Oscillator*/
//    PMC->CKGR_MOR |= CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCXTBY | CKGR_MOR_MOSCXTST(15) | CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL;
//    while(!(PMC->PMC_SR & PMC_SR_MOSCXTS));
//
//    /* PMC->CKGR_MCFR = 0; */
//
//    PMC->PMC_MCKR = PMC_MCKR_CSS(PMC_MCKR_CSS_MAIN_CLK);
//
//    PMC->PMC_PCR =

    sysclk_init();
}
