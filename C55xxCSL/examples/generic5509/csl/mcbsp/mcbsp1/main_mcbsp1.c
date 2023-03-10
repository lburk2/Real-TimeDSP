/*
 * Copyright (C) 2003 Texas Instruments Incorporated
 * All Rights Reserved
 */
/*
 *---------main_mcbsp1.c---------
 * In this example, the MCBSP is configured in digital loopback
 * mode, with 32 bit data transfer, in multi-frame mode, using                                                   
 * sample rate generator to sync frames                        
 */
#include <stdio.h>

#include <csl_mcbsp.h>
#include <csl_irq.h>

//---------Global constants---------
#define N       10

//---------Global data definition---------

  MCBSP_Config ConfigLoopBack32= {
  MCBSP_SPCR1_RMK(
    MCBSP_SPCR1_DLB_ON,                    /* DLB    = 1 */
    MCBSP_SPCR1_RJUST_RZF,                 /* RJUST  = 0 */
    MCBSP_SPCR1_CLKSTP_DISABLE,            /* CLKSTP = 0 */
    MCBSP_SPCR1_DXENA_NA,                  /* DXENA  = 0 */
    MCBSP_SPCR1_ABIS_DISABLE,              /* ABIS   = 0 */
    MCBSP_SPCR1_RINTM_RRDY,                /* RINTM  = 0 */
    0,                                     /* RSYNCER = 0 */
    MCBSP_SPCR1_RRST_DISABLE               /* RRST   = 0 */
   ),
    MCBSP_SPCR2_RMK(
    MCBSP_SPCR2_FREE_NO,                   /* FREE   = 0 */
    MCBSP_SPCR2_SOFT_NO,                   /* SOFT   = 0 */
    MCBSP_SPCR2_FRST_RESET,                /* FRST   = 0 */
    MCBSP_SPCR2_GRST_RESET,                /* GRST   = 0 */
    MCBSP_SPCR2_XINTM_XRDY,                /* XINTM  = 0 */
    0,                                     /* XSYNCER = N/A */
    MCBSP_SPCR2_XRST_DISABLE               /* XRST   = 0 */
   ),
  MCBSP_RCR1_RMK( 
  MCBSP_RCR1_RFRLEN1_OF(0),                /* RFRLEN1 = 0 */
  MCBSP_RCR1_RWDLEN1_32BIT                 /* RWDLEN1 = 5 */
  ),
 MCBSP_RCR2_RMK(    
    MCBSP_RCR2_RPHASE_SINGLE,              /* RPHASE  = 0 */
    MCBSP_RCR2_RFRLEN2_OF(0),              /* RFRLEN2 = 0 */
    MCBSP_RCR2_RWDLEN2_8BIT,               /* RWDLEN2 = 0 */
    MCBSP_RCR2_RCOMPAND_MSB,               /* RCOMPAND = 0 */
    MCBSP_RCR2_RFIG_YES,                   /* RFIG    = 0 */
    MCBSP_RCR2_RDATDLY_2BIT                /* RDATDLY = 0 */
    ),  
   MCBSP_XCR1_RMK(    
    MCBSP_XCR1_XFRLEN1_OF(0),              /* XFRLEN1 = 0 */ 
    MCBSP_XCR1_XWDLEN1_32BIT               /* XWDLEN1 = 5 */
    
 ),   
 MCBSP_XCR2_RMK(   
    MCBSP_XCR2_XPHASE_SINGLE,              /* XPHASE  = 0 */
    MCBSP_XCR2_XFRLEN2_OF(0),              /* XFRLEN2 = 0 */
    MCBSP_XCR2_XWDLEN2_8BIT,               /* XWDLEN2 = 0 */
    MCBSP_XCR2_XCOMPAND_MSB,               /* XCOMPAND = 0 */
    MCBSP_XCR2_XFIG_YES,                   /* XFIG    = 0 */
    MCBSP_XCR2_XDATDLY_2BIT                /* XDATDLY = 0 */
  ),            
 MCBSP_SRGR1_RMK( 
   MCBSP_SRGR1_FWID_OF(1),                /* FWID    = 1 */
   MCBSP_SRGR1_CLKGDV_OF(1)               /* CLKGDV  = 1 */
 ),   
 MCBSP_SRGR2_RMK(  
    MCBSP_SRGR2_GSYNC_FREE,                /* FREE    = 0 */
    MCBSP_SRGR2_CLKSP_RISING,              /* CLKSP   = 0 */
    MCBSP_SRGR2_CLKSM_INTERNAL,            /* CLKSM   = 1 */
    MCBSP_SRGR2_FSGM_DXR2XSR,              /* FSGM    = 0 */
    MCBSP_SRGR2_FPER_OF(15)                /* FPER    = 0 */
 ),  
 MCBSP_MCR1_DEFAULT,
 MCBSP_MCR2_DEFAULT, 
 MCBSP_PCR_RMK(
   MCBSP_PCR_IDLEEN_RESET,                 /* IDLEEN   = 0   */
   MCBSP_PCR_XIOEN_SP,                     /* XIOEN    = 0   */
   MCBSP_PCR_RIOEN_SP,                     /* RIOEN    = 0   */
   MCBSP_PCR_FSXM_INTERNAL,                /* FSXM     = 1   */
   MCBSP_PCR_FSRM_EXTERNAL,                /* FSRM     = 0   */
   MCBSP_PCR_CLKXM_OUTPUT,                 /* CLKXM    = 1   */
   MCBSP_PCR_CLKRM_INPUT,                  /* CLKRM    = 0   */
   MCBSP_PCR_SCLKME_NO,                    /* SCLKME   = 0   */
   0,                                      /* DXSTAT = N/A   */
   MCBSP_PCR_FSXP_ACTIVEHIGH,              /* FSXP     = 0   */
   MCBSP_PCR_FSRP_ACTIVEHIGH,              /* FSRP     = 0   */
   MCBSP_PCR_CLKXP_RISING,                 /* CLKXP    = 0   */
   MCBSP_PCR_CLKRP_FALLING                 /* CLKRP    = 0   */
 ),
 MCBSP_RCERA_DEFAULT, 
 MCBSP_RCERB_DEFAULT, 
 MCBSP_RCERC_DEFAULT, 
 MCBSP_RCERD_DEFAULT, 
 MCBSP_RCERE_DEFAULT, 
 MCBSP_RCERF_DEFAULT, 
 MCBSP_RCERG_DEFAULT, 
 MCBSP_RCERH_DEFAULT, 
 MCBSP_XCERA_DEFAULT,
 MCBSP_XCERB_DEFAULT,
 MCBSP_XCERC_DEFAULT,
 MCBSP_XCERD_DEFAULT,  
 MCBSP_XCERE_DEFAULT,
 MCBSP_XCERF_DEFAULT,  
 MCBSP_XCERG_DEFAULT,
 MCBSP_XCERH_DEFAULT
};     

/* Define a MCBSP_Handle object to be used with MCBSP_open function */
MCBSP_Handle mhMcbsp;
Uint32 xmt[N], rcv[N];
volatile Uint16 XfrCnt = 0;
Uint16 err = 0;
Uint16 old_intm;
Uint16 rcvEventId, xmtEventId;

//---------Function prototypes---------

/* Reference start of interrupt vector table   */
/* This symbol is defined in file, vectors.s55 */
extern void VECSTART(void);

// Interrupt Service Routine Prototypes
interrupt void writeIsr(void); 
interrupt void readIsr(void);

void taskFxn(void);

//---------main routine---------  
void main(void)
{
    Uint16 i;

    /* Initialize CSL library - This is REQUIRED !!! */
    CSL_init();
    
    /* Set IVPD/IVPH to start of interrupt vector location */
    IRQ_setVecs((Uint32)(&VECSTART));

    for (i = 0; i <= N - 1; i++) {  
        xmt[i] = ((Uint32)i << 17) + i;
        rcv[i] = 0;
    }

    /* Call function to effect transfer */
    taskFxn();
}

void taskFxn(void)
{
    Uint16 i;

    old_intm = IRQ_globalDisable();
  
    /* Open MCBSP Port 0 and set registers to their power on defaults */
    mhMcbsp = MCBSP_open(MCBSP_PORT0, MCBSP_OPEN_RESET);   

    /* Get EventId's associated with MCBSP Port 0 receive and transmit */
    /* The event Id's are used to communicate with the CSL interrupt   */
    /* module functions.                                               */
    rcvEventId = MCBSP_getRcvEventId(mhMcbsp);
    xmtEventId = MCBSP_getXmtEventId(mhMcbsp);
   
    /* Clear any pending receive or transmit interrupts */
    IRQ_clear(rcvEventId);           
    IRQ_clear(xmtEventId);
       
    /* Place address of interrupt service routines at */
    /* associated vector location  */
    IRQ_plug(rcvEventId, &readIsr);            
    IRQ_plug(xmtEventId, &writeIsr);
   
    /* Write values from configuration structure to MCBSP control regs */
    MCBSP_config(mhMcbsp, &ConfigLoopBack32); 

    /* Enable the MCBSP receive and transmit interrupts */
    IRQ_enable(rcvEventId);          
    IRQ_enable(xmtEventId);

   /* Start Sample Rate Generator and Frame Sync */
   MCBSP_start(mhMcbsp, 
               MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 
               0x300
               );

    /* Enable MCBSP transmit and receive */
    MCBSP_start(mhMcbsp, 
                MCBSP_RCV_START | MCBSP_XMIT_START, 
                0
               );
   
   /* Prime MCBSP transmit */
    while(!MCBSP_xrdy(mhMcbsp)){
      ;
    }
    MCBSP_write32(mhMcbsp,xmt[XfrCnt]);
    
	/* Enable all masked interrupts */
   	IRQ_globalEnable();
 
    /* Wait for transfer of data */
    while (XfrCnt < 10) {
        ;
    }
   
    /*------------------------------------------*\
     * Compare values 
    \*------------------------------------------*/   
    for(i = 0; i <= N - 1; i++){
        if (rcv[i] != xmt[i]){
            ++err;
            break;
       }
    }

    printf ("%s\n",err?"TEST FAILED" : "TEST PASSED");

    /* Restore old value of INTM */
    IRQ_globalRestore(old_intm);
    
    /* We're done with MCBSP, so close it */
    MCBSP_close(mhMcbsp);                     
}

interrupt void writeIsr(void)
{
    /*
     * Disable this ISR's interrupt before the write to the McBSP
     * since another interrupt will be generated as soon as the write
     * completes, which happens very quickly due to the loopback to
     * the McBSP receive.
     */
    IRQ_disable(xmtEventId);     
    MCBSP_write32(mhMcbsp,xmt[XfrCnt]);
}

interrupt void readIsr(void)
{
    rcv[XfrCnt] = MCBSP_read32(mhMcbsp);
    ++XfrCnt;
  
    if (XfrCnt == N) {
        IRQ_disable(rcvEventId);
        IRQ_disable(xmtEventId);
        MCBSP_reset(mhMcbsp);
    } 
    else {
        IRQ_enable(xmtEventId); 
    }
}
