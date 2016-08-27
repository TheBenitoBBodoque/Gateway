/******************************************************************************
*   Filename:   main.c
*
*   Description: main.c
*
* Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
*
*
*
*   Revision History:
*
*   Date          CP#           Author
*   MM-DD-YY      XXXXX:1       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   03-01-16       00            SPA        Gateway Initial Release
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "board.h"
#include "led.h"
#include "samv71_xplained_ultra.h"
#include "SchM.h"
#include "pio.h"

#include "samv71q21.h"
//#include "sam_gpio.h"
#include <asf.h>

#include "Os_Task.h"
#include "clock.h"
#include "adc.h"
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

/******************************************************************************
*   Static Variable Definitions
******************************************************************************/

/******************************************************************************
*   Global and Static Function Definitions
******************************************************************************/

/*****************************************************************************************************
*   Function: main
*
*   Description: main()
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
int main (void)
{
    /* Disable watchdog */
    WDT->WDT_MR = WDT_MR_WDDIS;

    cpu_irq_disable();

    /* Enable I and D cache */
    SCB_EnableICache();
    SCB_EnableDCache();

    /* Enhanced Embedded Flash Controller (EEFC) - Configuration*/
    /* Power Management Controller (PMC) - Configuration */
    clock_init();

    /* Commented but needed in a near future when something needs to be configured */
    //board_init();

    /* DIO - Configure Input and Output */
    dio_init();

    /* ADC */
    ADC_init();

    cpu_irq_enable();

    /* Insert application code here, after the board has been initialized. */
    SchM_Init(TaskConfigInitial);
    SchM_Start();

}

