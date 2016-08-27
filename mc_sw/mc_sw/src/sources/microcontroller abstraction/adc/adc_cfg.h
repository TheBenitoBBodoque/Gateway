#ifndef __ADC_CFG_H
#define __ADC_CFG_H
/******************************************************************************
*   Filename:   Os_Task.h
*
*   Description:
*
*
*   Revision history:
*
*   Date          CP#           Author
*   MM-DD-YY      XXXXX:1       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   05-08-16       00            SPA        Gateway Initial Release
******************************************************************************/

/******************************************************************************
*   Include Files
******************************************************************************/
#include "typedefs.h"

/******************************************************************************
*   Macro Definitions
******************************************************************************/
/* AFEC Mode Register */
/* ONE: one */
#define ONE ((uint8)1U)
/******************************************************************************
*   Type Definitions
******************************************************************************/

/* AFEC_CR: AFEC Control Register */
/* SWRST: Software Reset */
typedef enum
{
	NO_EFFECT_RESET,
	RESET_THE_AFEC_SIMULATING_A_HARDWARE_RESET
}adc_software_reset;

/* START: Start Conversion */
typedef enum
{
	NO_EFFECT_AFE_CONVERSION,
	ANALOG_FRONT_END_CONVERSION_BEGIN
}adc_start_convertion;


/* AFEC_MR: AFEC Mode Register */
/* TRGEN: Trigger Enable */
typedef enum
{
	HARDWARE_TRIGGERS_DISABLED,
	HARDWARE_TRIGGER_ENABLED
}adc_trigger_enable;

/* TRGSEL: Trigger Selection */
typedef enum
{
	AFEC_TRIG0,
	AFEC_TRIG1,
	AFEC_TRIG2,
	AFEC_TRIG3,
	AFEC_TRIG4,
	AFEC_TRIG5,
	AFEC_TRIG6,
	RESERVED_7
}adc_trigger_selection;

/* SLEEP: Sleep Mode */
typedef enum{
	NORMAL,
	SLEEP
}adc_sleep_mode;

/* FWUP: Fast Wake-up */
typedef enum
{
	FWUP_OFF,
	FWUP_ON
}adc_fast_wake_up;

/* FREERUN: Free Run Mode */
typedef enum
{
	NORMAL_MODE,
	FREE_RUN_MODE
}adc_free_run_mode;

/* PRESCAL: Prescaler Rate Selection */
typedef uint8 adc_prescal_type;

/* STARTUP: Start-up Time */
typedef enum
{
	SUT_O,
	SUT_8,
	SUT_16,
	SUT_24,
	SUT_64,
	SUT_80,
	SUT_96,
	SUT_112,
	SUT_512,
	SUT_576,
	SUT_640,
	SUT_704,
	SUT_768,
	SUT_832,
	SUT_896,
	SUT_960
}adc_start_up_time;

/* USEQ: User Sequence Enable */
/* Pending */


/* AFEC_EMR: AFEC Extended Mode Register */

/******************************************************************************
*   External Variables
******************************************************************************/

/******************************************************************************
*   Global Function Prototypes
******************************************************************************/

#endif /*__ADC_CFG_H*/
