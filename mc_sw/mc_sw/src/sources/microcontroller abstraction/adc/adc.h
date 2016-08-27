#ifndef __ADC_H
#define __ADC_H
/******************************************************************************
*   Filename:   adc.h
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

/******************************************************************************
*   Type Definitions
******************************************************************************/
typedef struct {
    volatile uint32       PMC_PCER0;      /**< \brief (Pmc Offset: 0x0010) Peripheral Clock Enable Register 0 */
    volatile uint32       PMC_PCDR0;      /**< \brief (Pmc Offset: 0x0014) Peripheral Clock Disable Register 0 */
    volatile const uint32 PMC_PCSR0;      /**< \brief (Pmc Offset: 0x0018) Peripheral Clock Status Register 0 */
}ADC0_PMC_Type;

typedef struct {
    volatile uint32       PMC_PCER1;      /**< \brief (Pmc Offset: 0x0100) Peripheral Clock Enable Register 1 */
    volatile uint32       PMC_PCDR1;      /**< \brief (Pmc Offset: 0x0104) Peripheral Clock Disable Register 1 */
    volatile const uint32 PMC_PCSR1;      /**< \brief (Pmc Offset: 0x0108) Peripheral Clock Status Register 1 */
}ADC1_PMC_Type;

typedef struct{
    /* Byte 1 */
    volatile uint32 TRGEN     :1;
    volatile uint32 TRGSEL    :3;
    volatile uint32 reserved2 :1;
    volatile uint32 SLEEP     :1;
    volatile uint32 FWUP      :1;
    volatile uint32 FREERUN   :1;
    /* Byte 2 */
    volatile uint32 PRESCAL   :8;
    /* Byte 3 */
    volatile uint32 STARTUP   :4;
    volatile uint32 reserved1 :3;
    volatile uint32 ONE       :1;
	/* Byte 4 */
	volatile uint32 TRACKTIM  :4;
	volatile uint32 TRANSFER  :2;
	volatile uint32 reserved0 :1;
	volatile uint32 USEQ      :1;
}AFEC_MR_s;

typedef struct{
    /* Byte 1 */
    volatile uint32 CMPMODE   :2;
    volatile uint32 reserved6 :1;
    volatile uint32 CMPSEL    :5;
    /* Byte 2 */
    volatile uint32 reserved5 :1;
    volatile uint32 CMPALL    :1;
    volatile uint32 reserved4 :2;
    volatile uint32 CMPFILTER :2;
    volatile uint32 reserved3 :2;
    /* Byte 3 */
    volatile uint32 RES       :3;
    volatile uint32 reserved2 :5;
	/* Byte 4 */
    volatile uint32 TAG       :1;
    volatile uint32 STM       :1;
    volatile uint32 reserved1 :2;
    volatile uint32 SIGNMODE  :2;
    volatile uint32 reserved0 :2;
}AFEC_EMR_s;


//typedef struct {
//  volatile uint32       AFEC_CR;       /**< \brief (Afec Offset: 0x00) AFEC Control Register */
//  volatile AFEC_MR_s    AFEC_MR;       /**< \brief (Afec Offset: 0x04) AFEC Mode Register */
//  volatile AFEC_EMR_s   AFEC_EMR;      /**< \brief (Afec Offset: 0x08) AFEC Extended Mode Register */
//  volatile uint32       AFEC_SEQ1R;    /**< \brief (Afec Offset: 0x0C) AFEC Channel Sequence 1 Register */
//  volatile uint32       AFEC_SEQ2R;    /**< \brief (Afec Offset: 0x10) AFEC Channel Sequence 2 Register */
//  volatile uint32       AFEC_CHER;     /**< \brief (Afec Offset: 0x14) AFEC Channel Enable Register */
//  volatile uint32       AFEC_CHDR;     /**< \brief (Afec Offset: 0x18) AFEC Channel Disable Register */
//  volatile const uint32 AFEC_CHSR;     /**< \brief (Afec Offset: 0x1C) AFEC Channel Status Register */
//  volatile const uint32 AFEC_LCDR;     /**< \brief (Afec Offset: 0x20) AFEC Last Converted Data Register */
//  volatile uint32       AFEC_IER;      /**< \brief (Afec Offset: 0x24) AFEC Interrupt Enable Register */
//  volatile uint32       AFEC_IDR;      /**< \brief (Afec Offset: 0x28) AFEC Interrupt Disable Register */
//  volatile const uint32 AFEC_IMR;      /**< \brief (Afec Offset: 0x2C) AFEC Interrupt Mask Register */
//  volatile const uint32 AFEC_ISR;      /**< \brief (Afec Offset: 0x30) AFEC Interrupt Status Register */
//  volatile const uint32 Reserved1[6];
//  volatile const uint32 AFEC_OVER;     /**< \brief (Afec Offset: 0x4C) AFEC Overrun Status Register */
//  volatile uint32       AFEC_CWR;      /**< \brief (Afec Offset: 0x50) AFEC Compare Window Register */
//  volatile uint32       AFEC_CGR;      /**< \brief (Afec Offset: 0x54) AFEC Channel Gain Register */
//  volatile const uint32 Reserved2[2];
//  volatile uint32       AFEC_DIFFR;    /**< \brief (Afec Offset: 0x60) AFEC Channel Differential Register */
//  volatile uint32       AFEC_CSELR;    /**< \brief (Afec Offset: 0x64) AFEC Channel Selection Register */
//  volatile const uint32 AFEC_CDR;      /**< \brief (Afec Offset: 0x68) AFEC Channel Data Register */
//  volatile uint32       AFEC_COCR;     /**< \brief (Afec Offset: 0x6C) AFEC Channel Offset Compensation Register */
//  volatile uint32       AFEC_TEMPMR;   /**< \brief (Afec Offset: 0x70) AFEC Temperature Sensor Mode Register */
//  volatile uint32       AFEC_TEMPCWR;  /**< \brief (Afec Offset: 0x74) AFEC Temperature Compare Window Register */
//  volatile const uint32 Reserved3[7];
//  volatile uint32       AFEC_ACR;      /**< \brief (Afec Offset: 0x94) AFEC Analog Control Register */
//  volatile const uint32 Reserved4[2];
//  volatile uint32       AFEC_SHMR;     /**< \brief (Afec Offset: 0xA0) AFEC Sample & Hold Mode Register */
//  volatile const uint32 Reserved5[11];
//  volatile uint32       AFEC_COSR;     /**< \brief (Afec Offset: 0xD0) AFEC Correction Select Register */
//  volatile uint32       AFEC_CVR;      /**< \brief (Afec Offset: 0xD4) AFEC Correction Values Register */
//  volatile uint32       AFEC_CECR;     /**< \brief (Afec Offset: 0xD8) AFEC Channel Error Correction Register */
//  volatile const uint32 Reserved6[2];
//  volatile uint32       AFEC_WPMR;     /**< \brief (Afec Offset: 0xE4) AFEC Write Protection Mode Register */
//  volatile const uint32 AFEC_WPSR;     /**< \brief (Afec Offset: 0xE8) AFEC Write Protection Status Register */
//} Afec_Type;

typedef enum
{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1
}ADC_Channel_Type;
/******************************************************************************
*   External Variables
******************************************************************************/

/******************************************************************************
*   Global Function Prototypes
******************************************************************************/
void ADC_init (void);
void ADC_EnablePeripheral (ADC_Channel_Type Channel);

#endif /*__ADC_H*/
