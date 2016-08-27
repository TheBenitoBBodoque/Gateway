/******************************************************************************
*   Filename:   dio.c
*
*   Description: This file is the abstraction for the PMC peripheral.
*
*   Revision History:
*
*   Date          CP#           Author
*   MM-DD-YY      XXXXX:1       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   08-23-16       00            SPA        Gateway Initial Release
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "samv71q21.h"
#include "ioport.h"
#include "pio.h"
#include "samv71_xplained_ultra.h"
#include "ioport_pio.h"
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
*   Function: Task_1ms
*
*   Description: Interrupt handler for TC0 interrupt.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void dio_init (void)
{
    /* Configure the pins connected to LED as output and set their
     * default initial state to high (LED off).
     */
    ioport_set_pin_dir(LED0_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(LED0_GPIO, LED0_INACTIVE_LEVEL);
    ioport_set_pin_dir(LED1_GPIO, IOPORT_DIR_OUTPUT);
    ioport_set_pin_level(LED1_GPIO, LED0_INACTIVE_LEVEL);

    /* Configure Push Button pins */
    ioport_set_pin_input_mode(GPIO_PUSH_BUTTON_1, GPIO_PUSH_BUTTON_1_FLAGS,
            GPIO_PUSH_BUTTON_1_SENSE);
}

void prender_led (void)
{
    ioport_set_pin_level(LED1_GPIO, LED1_ACTIVE_LEVEL);
}

void apagar_led (void)
{
    ioport_set_pin_level(LED1_GPIO, LED1_INACTIVE_LEVEL);
}
