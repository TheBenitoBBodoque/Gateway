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
*   04-24-16       00            SPA        Gateway Initial Release
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "tc_driver.h"
#include "tc.h"
#include "pmc.h"
//#include "samv71q21.h"
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
int8 gpt_init_done = FALSE;
void (*Gpt_Callback_local) (void);

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
void TC0_Handler(void)
{
	volatile uint32_t dummy;

	/* Clear status bit to acknowledge interrupt */
	dummy = TC0->TC_CHANNEL[0].TC_SR;

	if (gpt_init_done == TRUE)
	{
		Gpt_Callback_local();
	}
}


/*****************************************************************************************************
*   Function: _ConfigureTc
*
*   Description: Configure TC0 Periferical.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void _ConfigureTc(void)
{
	uint32_t div;
	uint32_t tcclks;

	/** Enable peripheral clock. */
	//PMC_EnablePeripheral(ID_TC0);
	//PMC->PMC_PCSR0 & ((uint32_t)1 << dwId)) == ((uint32_t)1 << dwId
	pmc_enable_periph_clk(23);
	/** Configure TC for a 4Hz frequency and trigger on RC compare. */
	tc_find_mck_divisor(4, BOARD_MCK, &div, &tcclks, BOARD_MCK);

	tc_init(TC0, 0, tcclks | TC_CMR_CPCTRG);
	TC0->TC_CHANNEL[0].TC_RC = (BOARD_MCK / div) / 4;

	/* Configure and enable interrupt on RC compare */
	NVIC_ClearPendingIRQ(TC0_IRQn);
	NVIC_EnableIRQ(TC0_IRQn);

	TC0->TC_CHANNEL[0].TC_IER = TC_IER_CPCS;

	/** Start the counter if LED1 is enabled. */
	tc_start(TC0, 0);
}

/*****************************************************************************************************
*   Function: Task_1ms
*
*   Description: Interrupt handler for TC0 interrupt.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void tc_driver_init(void)
{
	gpt_init_done = TRUE;
	//Gpt_Callback_local = SchM_OsTick;
	_ConfigureTc();
}
