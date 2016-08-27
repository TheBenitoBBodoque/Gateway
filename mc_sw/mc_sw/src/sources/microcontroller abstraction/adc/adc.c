/******************************************************************************
*   Filename:   adc.c
*
*   Description:
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
#include "adc.h"
#include "samv71q21.h"

/******************************************************************************
*   Local Macro Definitions
******************************************************************************/
#define ADC0_PCM ((ADC0_PMC_Type *)0x400E0610)
#define ADC1_PCM ((ADC1_PMC_Type *)0x400E0700)
//#define AFEC0    ((Afec_Type *)0x4003C000U) /**< \brief (AFEC0 ) Base Address */
//#define AFEC1    ((Afec_Type *)0x40064000U) /**< \brief (AFEC1 ) Base Address */
//#define ID_AFEC0 ((uint32)29U)
//#define ID_AFEC1 ((uint32)40U)
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
*   Function: adc_init()
*
*   Description: Service for ADC initialization
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void ADC_init (void)
{
    AFEC0->AFEC_CR = AFEC_CR_SWRST;

    ADC_EnablePeripheral(ADC_CHANNEL_0);

    /* Wait 64 periods of AFE clock */
    /* Set AFE Clock to 1MHz*/
    AFEC0->AFEC_MR = AFEC_MR_TRANSFER(1) | AFEC_MR_TRACKTIM(2) | AFEC_MR_ONE | AFEC_MR_STARTUP(4) | AFEC_MR_PRESCAL(249);

    /* RES - No Average - Set to 12 bit resolution */
    /* TAG -  Appends the channel number to the conversion result in AFEC_LDCR */
    /* STM - Only a single trigger is required to get an averaged value */
    AFEC0->AFEC_EMR = AFEC_EMR_RES(0) | AFEC_EMR_TAG | AFEC_EMR_STM;

    /* AFEC Channel Enable Register */
    AFEC0->AFEC_CHER = 1 << 0;

    /* AFEC Interrupt Enable Register */
    AFEC0->AFEC_IER = AFEC_IER_EOC0;

    /* AFEC Channel Selection Register */
    AFEC0->AFEC_CSELR = AFEC_CSELR_CSEL(1);

    /* AFEC Control Register */
    AFEC0->AFEC_CR = AFEC_CR_START;

    //    NVIC_ClearPendingIRQ(AFEC0_IRQn);
    //    NVIC_EnableIRQ(AFEC0_IRQn);
}

/*****************************************************************************************************
*   Function: AFEC_EnablePeripheral / ADC_ClockEnable
*
*   Description: Enables the PCM for the AFEC.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void ADC_EnablePeripheral (ADC_Channel_Type Channel)
{
    if(Channel == ADC_CHANNEL_0)
    {
        if((ADC0_PCM->PMC_PCSR0 & (((uint32)1U) << ID_AFEC0)) == (((uint32)0U) << ID_AFEC0))
        {
            ADC0_PCM->PMC_PCER0 = 1 << ID_AFEC0;
        }
        else
        {
            /* ADC Clock was already enabled */
        }
    }
    else
    {
        if((ADC1_PCM->PMC_PCSR1 & (((uint32)1U) << (ID_AFEC1-32))) == (((uint32)0U) << (ID_AFEC1-32)))
        {
            ADC1_PCM->PMC_PCER1 = 1 << (ID_AFEC1-32);
        }
        else
        {
            /* ADC Clock was already enabled */
        }
    }
}

void AFEC0_Handler ( void )
{
    volatile uint32 dummy0;
	volatile uint32 dummy1;
	volatile uint32 dummy2;
    volatile uint32 dummy3;
    /* AFEC Interrupt Mask Register */
	dummy0 = AFEC0->AFEC_IMR;
	dummy1 = AFEC0->AFEC_ISR;
	dummy2 = AFEC0->AFEC_CDR;
    dummy3 = AFEC0->AFEC_LCDR;
}
