/******************************************************************************
*   Filename:   typedefs.h
*
*   Description: Variable types and common macros
*
*
*   Revision History:
*
*                             
*   Date          #Change       Author
*   MM-DD-YY      Number:       Initials   Description of change
*   -----------   -----------   --------   ------------------------------------
*   03-01-14       00            SPA        OS Task Initial Release
*   05-20-16       00            SPA        Porting the OS Non-Preemtive to ATMEL SAM-V
******************************************************************************/


#ifndef TYPEDEFS_H        /*prevent duplicated includes*/ 
#define    TYPEDEFS_H    

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/
typedef unsigned  char        u8; /*unsigned 8 bit definition */ 
typedef unsigned  short       u16; /*unsigned 16 bit definition*/ 
typedef unsigned  long        u32; /*unsigned 32 bit definition*/
typedef signed    char        s8; /*signed 8 bit definition */ 
typedef short                 s16; /*signed 16 bit definition*/ 
typedef long   int            s32; /*signed 32 bit definition*/


typedef unsigned  char        UINT8; /*unsigned 8 bit definition */ 
typedef unsigned  short       UINT16; /*unsigned 16 bit definition*/ 
typedef unsigned  long        UINT32; /*unsigned 32 bit definition*/ 
typedef signed    char        INT8; /*signed 8 bit definition */ 
typedef short                 INT16; /*signed 16 bit definition*/ 
typedef long      int         INT32; /*signed 32 bit definition*/        

typedef unsigned  char        uint8; /*unsigned 8 bit definition */ 
typedef unsigned  short       uint16; /*unsigned 16 bit definition*/ 
typedef unsigned  long        uint32; /*unsigned 32 bit definition*/ 
typedef signed    char        int8; /*signed 8 bit definition */ 
typedef short                 int16; /*signed 16 bit definition*/ 
typedef long      int         int32; /*signed 32 bit definition*/                                    

typedef  volatile  unsigned  char       VUINT8; /*unsigned 8 bit definition */ 
typedef  volatile  unsigned  short      VUINT16; /*unsigned 16 bit definition*/ 
typedef  volatile  unsigned  long       VUINT32; /*unsigned 32 bit definition*/ 
typedef  volatile  signed    char       VINT8; /*signed 8 bit definition */ 
typedef  volatile  short       VINT16;       /*signed 16 bit definition*/ 
typedef  volatile  long   int  VINT32;       /*signed 32 bit definition*/ 

typedef  volatile  unsigned  char       vuint8; /*unsigned 8 bit definition */ 
typedef  volatile  unsigned  short      vuint16; /*unsigned 16 bit definition*/ 
typedef  volatile  unsigned  long       vuint132; /*unsigned 32 bit definition*/ 
typedef  volatile  signed    char       vint8; /*signed 8 bit definition */ 
typedef  volatile  short       vint16;       /*signed 16 bit definition*/ 
typedef  volatile  long   int  vint32;       /*signed 32 bit definition*/ 

//typedef  unsigned   char; /*unsigned 8 bit definition for S-Record support */ 

/*type used for callback function*/
//	typedef  void  ( * tCallbackFunction )( void  );

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/* Common Constants */
#ifndef ON
	#define    ON     1u
#endif

#ifndef OFF
	#define    OFF    0u
#endif

#ifndef TRUE
	#define    TRUE    1u
#endif

#ifndef FALSE
	#define    FALSE    0u
#endif

#ifndef PASS
	#define    PASS    0u
#endif

#ifndef FAIL
	#define    FAIL    1u
#endif

#ifndef SET
	#define    SET    1u
#endif

#ifndef CLEAR
	#define    CLEAR    0u
#endif

#ifndef YES
	#define    YES    1u
#endif

#ifndef NO
	#define    NO     0u
#endif

#ifndef DISABLED
	#define 	 DISABLED  0u
#endif

#ifndef ENABLE
	#define 	 ENABLE 1u
#endif

#ifndef NULL
  #define    NULL    ( ( void * ) 0 )
#endif


/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

#endif                                     /* TYPEDEFS_H */ 