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

/* TODO : SPA2 - Remove this line of code later - Begin */
#define PMC_PCR_GCLKEN (0x1u << 29) /**< \brief (PMC_PCR) Generic Clock Enable */

#define PMC_PCR_GLKCSS_Pos 8
#define PMC_PCR_GLKCSS_Msk (0x7u << PMC_PCR_GLKCSS_Pos) /**< \brief (PMC_PCR) Generic Clock Source Selection */
#define PMC_PCR_GCLKCSS(value) ((PMC_PCR_GLKCSS_Msk & ((value) << PMC_PCR_GLKCSS_Pos)))
/* TODO : SPA2 - Remove this line of code later - End */

//#define AFEC0    ((Afec_Type *)0x4003C000U) /**< \brief (AFEC0 ) Base Address */
//#define AFEC1    ((Afec_Type *)0x40064000U) /**< \brief (AFEC1 ) Base Address */
//#define ID_AFEC0 ((uint32)29U)
//#define ID_AFEC1 ((uint32)40U)
#define MAX_NUM_DATA 4
/******************************************************************************
*   Local Type Definitions
******************************************************************************/

/******************************************************************************
*   Local Function Declarations
******************************************************************************/
void Process_Callback(void);
static uint32 afec_get_interrupt_status_custom(Afec *const afec);
static uint32 afec_get_data_value(Afec *const afec);
static void adc_buffer(uint32 adc_raw_value);
/******************************************************************************
*   Global Variable Definitions
******************************************************************************/

uint32 adc_values[MAX_NUM_DATA] = {0,0,0,0};
uint8 adc_address_space = 0;
/******************************************************************************
*   Static Variable Definitions
******************************************************************************/

/******************************************************************************
*   Global and Static Function Definitions
******************************************************************************/

///*****************************************************************************************************
//*   Function: adc_init()
//*
//*   Description: Service for ADC initialization
//*
//*   Caveats: Non Reentrant
//*****************************************************************************************************/
//void ADC_init (void)
//{
//    AFEC0->AFEC_CR = AFEC_CR_SWRST;
//
//    ADC_EnablePeripheral_GLCK();
//    ADC_EnablePeripheral_MCK(ADC_CHANNEL_0);
//
//    /* Wait 64 periods of AFE clock */
//    /* Set AFE Clock to 1MHz*/
//    AFEC0->AFEC_MR = AFEC_MR_TRANSFER(0) | AFEC_MR_TRACKTIM(1) | AFEC_MR_ONE | AFEC_MR_STARTUP(4) | AFEC_MR_PRESCAL(2);
//
//    /* RES - No Average - Set to 12 bit resolution */
//    /* TAG -  Appends the channel number to the conversion result in AFEC_LDCR */
//    /* STM - Only a single trigger is required to get an averaged value */
//    AFEC0->AFEC_EMR = AFEC_EMR_RES(0) /* | AFEC_EMR_TAG */ | AFEC_EMR_STM | AFEC_EMR_CMPMODE(AFEC_EMR_CMPMODE_HIGH);
//
//    /* AFEC Channel Enable Register */
//    AFEC0->AFEC_CHER = 1 << 0;
//
//    /* AFEC Interrupt Enable Register */
//    //AFEC0->AFEC_IER = AFEC_IER_EOC0;
//
//    /* AFEC Channel Selection Register */
//    //AFEC0->AFEC_CSELR = AFEC_CSELR_CSEL(1);
//
//    /* AFEC Control Register */
//    AFEC0->AFEC_CR = AFEC_CR_START;
//
//    NVIC_DisableIRQ(AFEC0_IRQn);
//    NVIC_ClearPendingIRQ(AFEC0_IRQn);
//    NVIC_SetPriority(AFEC0_IRQn,2);
//    NVIC_EnableIRQ(AFEC0_IRQn);
//    AFEC0->AFEC_IER = AFEC_IER_EOC0 /* | AFEC_IER_DRDY */;
//}

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

    //ADC_EnablePeripheral_GLCK();
    ADC_EnablePeripheral_MCK(ADC_CHANNEL_0);

    /* Wait 64 periods of AFE clock */
    /* Set AFE Clock to 1MHz*/
    AFEC0->AFEC_MR = AFEC_MR_TRANSFER(15) | AFEC_MR_TRACKTIM(15) | AFEC_MR_ONE | AFEC_MR_STARTUP(4) | AFEC_MR_PRESCAL(125) /*| TAG */;

    /* RES - No Average - Set to 12 bit resolution */
    /* TAG -  Appends the channel number to the conversion result in AFEC_LDCR */
    /* STM - Only a single trigger is required to get an averaged value */
    AFEC0->AFEC_EMR = AFEC_EMR_RES(0) | AFEC_EMR_CMPSEL(0) | AFEC_EMR_CMPMODE(AFEC_EMR_CMPMODE_IN) | AFEC_EMR_TAG;

    /* AFEC Channel Enable Register */
    AFEC0->AFEC_CHER = AFEC_CHER_CH3;

    AFEC0->AFEC_CWR = AFEC_CWR_LOWTHRES(0) | AFEC_CWR_HIGHTHRES(0xFFFF);

    /* AFEC Interrupt Enable Register */
    //AFEC0->AFEC_IER = AFEC_IER_EOC0;

    /* AFEC Channel Selection Register */
    //AFEC0->AFEC_CSELR = AFEC_CSELR_CSEL(1);

//    NVIC_DisableIRQ(AFEC0_IRQn);
//    NVIC_ClearPendingIRQ(AFEC0_IRQn);
//    NVIC_SetPriority(AFEC0_IRQn,2);
//    NVIC_EnableIRQ(AFEC0_IRQn);
//    AFEC0->AFEC_IER = AFEC_IER_EOC3 | AFEC_IER_DRDY;
}

void AFEC_ConvertionStart (void)
{
    /* AFEC Control Register */
    AFEC0->AFEC_CR = AFEC_CR_START;
}
/*****************************************************************************************************
*   Function: ADC_EnablePeripheral_MCK
*
*   Description: Enables the PCM for the AFEC.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void ADC_EnablePeripheral_MCK (ADC_Channel_Type Channel)
{
    if(Channel == ADC_CHANNEL_0)
    {
        if((PMC->PMC_PCSR0 & (((uint32)1U) << ID_AFEC0)) == (((uint32)0U) << ID_AFEC0))
        {
            PMC->PMC_PCER0 = 1 << ID_AFEC0;
        }
        else
        {
            /* ADC Clock was already enabled */
        }
    }
    else
    {
//        if((PMC->PMC_PCSR1 & (((uint32)1U) << (ID_AFEC1-32))) == (((uint32)0U) << (ID_AFEC1-32)))
//        {
//            PMC-->PMC_PCER1 = 1 << (ID_AFEC1-32);
//        }
//        else
//        {
//            /* ADC Clock was already enabled */
//        }
    }
}

/*****************************************************************************************************
*   Function: ADC_EnablePeripheral_GLCK
*
*   Description: Enables the PCM for the AFEC with specific sourse clock.
*
*   Caveats: Non Reentrant
*****************************************************************************************************/
void ADC_EnablePeripheral_GLCK (void)
{

    PMC->PMC_PCR = PMC_PCR_PID(ID_AFEC0) | PMC_PCR_GCLKCSS(0) | PMC_PCR_CMD | PMC_PCR_GCLKEN ;
}

volatile uint32 dummy0 = 0;
volatile uint32 dummy1 = 0;
volatile uint32 dummy2 = 0;
volatile uint32 dummy3 = 0;

uint32 nuevodato;

void AFEC0_Handler ( void )
{
    Process_Callback();
}



void Process_Callback (void)
{
    volatile uint32 status;
    volatile uint32 data = 0;
    status = afec_get_interrupt_status_custom(AFEC0);
    if (status == 0x08)
    {
        data = 1;
    }
    data = afec_get_data_value(AFEC0);
    adc_buffer(data);

    AFEC0->AFEC_CSELR = 3;
    dummy2 = AFEC0->AFEC_CDR;
}

static uint32 afec_get_interrupt_status_custom(Afec *const afec)
{
    return afec->AFEC_ISR;
}

static uint32 afec_get_data_value(Afec *const afec)
{
	return afec->AFEC_LCDR;
}

static void adc_buffer(uint32 adc_raw_value)
{
	adc_values[adc_address_space] = adc_raw_value;
	adc_address_space++;
	if (adc_address_space >= MAX_NUM_DATA)
	{
	    adc_address_space = 0;
	}
}
