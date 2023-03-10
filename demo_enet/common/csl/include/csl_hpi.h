/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... HPI
* FILENAME...... csl_hpi.h
* DATE CREATED.. Fri Mar 22 11:46:12 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Fri Mar 22 11:46:12 2002 (Automatic generation)
*	 Last Modified:	3 April 2003 canged names to match datasheet sprs166c
*                       revised Feb 2003 and spru620A
*                       24 June 2004 Added descriptions for the registers,
*                                    HGPIODIR1,HGPIODIR2,HGPIODIR3,
*                                    HGPIODAT1,HGPIODAT2,HGPIODAT3
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the HPI module 
*
\*************************************************************************/

#ifndef _CSL_HPI_H_
#define _CSL_HPI_H_


#include <csl_std.h>
#include <csl.h>
#include <csl_chiphal.h>

#if (_HPI_SUPPORT) 

#include <csl_hpihal.h>
#include <csl_hpidat.h>
/*----------------------------------------------------------------*\
*	 HPI scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _HPI_MOD_
  #define IDECL CSLAPI
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
 #endif
#endif

/****************************************\
* HPI global macro declarations
\****************************************/

/* error codes */
#define HPI_ERR_MAJOR		   (ERR_BASE_HPI) 
#define HPI_ERR_ALLOC		   (0x00000000) 
#define HPI_ERR_INVALID_HANDLE  (0x00000001) 

/* ============================================================== */
 /* Make HGPIODAT register values based on symbolic constants  */

/*  HGPIODAT field values  */

	#define HPI_HGPIODAT_HD15_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD15_LOW			(000000u)
	#define HPI_HGPIODAT_HD15_DEFAULT		HPI_HGPIODAT_HD15_LOW

	#define HPI_HGPIODAT_HD14_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD14_LOW			(000000u)
	#define HPI_HGPIODAT_HD14_DEFAULT		HPI_HGPIODAT_HD14_LOW

	#define HPI_HGPIODAT_HD13_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD13_LOW			(000000u)
	#define HPI_HGPIODAT_HD13_DEFAULT		HPI_HGPIODAT_HD13_LOW

	#define HPI_HGPIODAT_HD12_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD12_LOW			(000000u)
	#define HPI_HGPIODAT_HD12_DEFAULT		HPI_HGPIODAT_HD12_LOW

	#define HPI_HGPIODAT_HD11_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD11_LOW			(000000u)
	#define HPI_HGPIODAT_HD11_DEFAULT		HPI_HGPIODAT_HD11_LOW

	#define HPI_HGPIODAT_HD10_HIGH		(0x0001u)
	#define HPI_HGPIODAT_HD10_LOW			(000000u)
	#define HPI_HGPIODAT_HD10_DEFAULT		HPI_HGPIODAT_HD10_LOW

	#define HPI_HGPIODAT_HD9_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD9_LOW			(000000u)
	#define HPI_HGPIODAT_HD9_DEFAULT		HPI_HGPIODAT_HD9_LOW

	#define HPI_HGPIODAT_HD8_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD8_LOW			(000000u)
	#define HPI_HGPIODAT_HD8_DEFAULT		HPI_HGPIODAT_HD8_LOW

	#define HPI_HGPIODAT_HD7_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD7_LOW			(000000u)
	#define HPI_HGPIODAT_HD7_DEFAULT		HPI_HGPIODAT_HD7_LOW

	#define HPI_HGPIODAT_HD6_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD6_LOW			(000000u)
	#define HPI_HGPIODAT_HD6_DEFAULT		HPI_HGPIODAT_HD6_LOW

	#define HPI_HGPIODAT_HD5_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD5_LOW			(000000u)
	#define HPI_HGPIODAT_HD5_DEFAULT		HPI_HGPIODAT_HD5_LOW

	#define HPI_HGPIODAT_HD4_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD4_LOW			(000000u)
	#define HPI_HGPIODAT_HD4_DEFAULT		HPI_HGPIODAT_HD4_LOW

	#define HPI_HGPIODAT_HD3_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD3_LOW			(000000u)
	#define HPI_HGPIODAT_HD3_DEFAULT		HPI_HGPIODAT_HD3_LOW

	#define HPI_HGPIODAT_HD2_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD2_LOW			(000000u)
	#define HPI_HGPIODAT_HD2_DEFAULT		HPI_HGPIODAT_HD2_LOW

	#define HPI_HGPIODAT_HD1_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD1_LOW			(000000u)
	#define HPI_HGPIODAT_HD1_DEFAULT		HPI_HGPIODAT_HD1_LOW

	#define HPI_HGPIODAT_HD0_HIGH			(0x0001u)
	#define HPI_HGPIODAT_HD0_LOW			(000000u)
	#define HPI_HGPIODAT_HD0_DEFAULT		HPI_HGPIODAT_HD0_LOW


#define HPI_HGPIODAT_RMK(hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODAT,HD15,hd15))|\
  ( HPI_FMK(HGPIODAT,HD14,hd14))|\
  ( HPI_FMK(HGPIODAT,HD13,hd13))|\
  ( HPI_FMK(HGPIODAT,HD12,hd12))|\
  ( HPI_FMK(HGPIODAT,HD11,hd11))|\
  ( HPI_FMK(HGPIODAT,HD10,hd10))|\
  ( HPI_FMK(HGPIODAT,HD9,hd9))|\
  ( HPI_FMK(HGPIODAT,HD8,hd8))|\
  ( HPI_FMK(HGPIODAT,HD7,hd7))|\
  ( HPI_FMK(HGPIODAT,HD6,hd6))|\
  ( HPI_FMK(HGPIODAT,HD5,hd5))|\
  ( HPI_FMK(HGPIODAT,HD4,hd4))|\
  ( HPI_FMK(HGPIODAT,HD3,hd3))|\
  ( HPI_FMK(HGPIODAT,HD2,hd2))|\
  ( HPI_FMK(HGPIODAT,HD1,hd1))|\
  ( HPI_FMK(HGPIODAT,HD0,hd0))\
)\
 )

#define HPI_HGPIODAT_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,\
                          hd10_sym,hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,\
                          hd4_sym,hd3_sym,hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODAT,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODAT,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODAT,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODAT,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODAT,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODAT,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODAT,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODAT,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODAT,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODAT,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODAT,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODAT,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODAT,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODAT,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODAT,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODAT,HD0,hd0_sym))\
)\
 )

/*  Default HGPIODAT1 register value  */

/* ============================================================== */
 /* Make HGPIODAT1 register values based on symbolic constants  */

/*  HGPIODAT1 field values  */

	#define HPI_HGPIODAT1_HD15_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD15_LOW			(000000u)
	#define HPI_HGPIODAT1_HD15_DEFAULT		HPI_HGPIODAT1_HD15_LOW

	#define HPI_HGPIODAT1_HD14_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD14_LOW			(000000u)
	#define HPI_HGPIODAT1_HD14_DEFAULT		HPI_HGPIODAT1_HD14_LOW

	#define HPI_HGPIODAT1_HD13_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD13_LOW			(000000u)
	#define HPI_HGPIODAT1_HD13_DEFAULT		HPI_HGPIODAT1_HD13_LOW

	#define HPI_HGPIODAT1_HD12_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD12_LOW			(000000u)
	#define HPI_HGPIODAT1_HD12_DEFAULT		HPI_HGPIODAT1_HD12_LOW

	#define HPI_HGPIODAT1_HD11_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD11_LOW			(000000u)
	#define HPI_HGPIODAT1_HD11_DEFAULT		HPI_HGPIODAT1_HD11_LOW

	#define HPI_HGPIODAT1_HD10_HIGH		(0x0001u)
	#define HPI_HGPIODAT1_HD10_LOW			(000000u)
	#define HPI_HGPIODAT1_HD10_DEFAULT		HPI_HGPIODAT1_HD10_LOW

	#define HPI_HGPIODAT1_HD9_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD9_LOW			(000000u)
	#define HPI_HGPIODAT1_HD9_DEFAULT		HPI_HGPIODAT1_HD9_LOW

	#define HPI_HGPIODAT1_HD8_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD8_LOW			(000000u)
	#define HPI_HGPIODAT1_HD8_DEFAULT		HPI_HGPIODAT1_HD8_LOW

	#define HPI_HGPIODAT1_HD7_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD7_LOW			(000000u)
	#define HPI_HGPIODAT1_HD7_DEFAULT		HPI_HGPIODAT1_HD7_LOW

	#define HPI_HGPIODAT1_HD6_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD6_LOW			(000000u)
	#define HPI_HGPIODAT1_HD6_DEFAULT		HPI_HGPIODAT1_HD6_LOW

	#define HPI_HGPIODAT1_HD5_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD5_LOW			(000000u)
	#define HPI_HGPIODAT1_HD5_DEFAULT		HPI_HGPIODAT1_HD5_LOW

	#define HPI_HGPIODAT1_HD4_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD4_LOW			(000000u)
	#define HPI_HGPIODAT1_HD4_DEFAULT		HPI_HGPIODAT1_HD4_LOW

	#define HPI_HGPIODAT1_HD3_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD3_LOW			(000000u)
	#define HPI_HGPIODAT1_HD3_DEFAULT		HPI_HGPIODAT1_HD3_LOW

	#define HPI_HGPIODAT1_HD2_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD2_LOW			(000000u)
	#define HPI_HGPIODAT1_HD2_DEFAULT		HPI_HGPIODAT1_HD2_LOW

	#define HPI_HGPIODAT1_HD1_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD1_LOW			(000000u)
	#define HPI_HGPIODAT1_HD1_DEFAULT		HPI_HGPIODAT1_HD1_LOW

	#define HPI_HGPIODAT1_HD0_HIGH			(0x0001u)
	#define HPI_HGPIODAT1_HD0_LOW			(000000u)
	#define HPI_HGPIODAT1_HD0_DEFAULT		HPI_HGPIODAT1_HD0_LOW


#define HPI_HGPIODAT1_RMK(hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODAT1,HD15,hd15))|\
  ( HPI_FMK(HGPIODAT1,HD14,hd14))|\
  ( HPI_FMK(HGPIODAT1,HD13,hd13))|\
  ( HPI_FMK(HGPIODAT1,HD12,hd12))|\
  ( HPI_FMK(HGPIODAT1,HD11,hd11))|\
  ( HPI_FMK(HGPIODAT1,HD10,hd10))|\
  ( HPI_FMK(HGPIODAT1,HD9,hd9))|\
  ( HPI_FMK(HGPIODAT1,HD8,hd8))|\
  ( HPI_FMK(HGPIODAT1,HD7,hd7))|\
  ( HPI_FMK(HGPIODAT1,HD6,hd6))|\
  ( HPI_FMK(HGPIODAT1,HD5,hd5))|\
  ( HPI_FMK(HGPIODAT1,HD4,hd4))|\
  ( HPI_FMK(HGPIODAT1,HD3,hd3))|\
  ( HPI_FMK(HGPIODAT1,HD2,hd2))|\
  ( HPI_FMK(HGPIODAT1,HD1,hd1))|\
  ( HPI_FMK(HGPIODAT1,HD0,hd0))\
)\
 )

#define HPI_HGPIODAT1_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,\
                          hd10_sym,hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,\
                          hd4_sym,hd3_sym,hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODAT1,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODAT1,HD0,hd0_sym))\
)\
 )




/*  Default HGPIODAT2 register value  */

/* ============================================================== */
 /* Make HGPIODAT2 register values based on symbolic constants  */

/*  HGPIODAT2 field values  */

	#define HPI_HGPIODAT2_HD15_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD15_LOW			(000000u)
	#define HPI_HGPIODAT2_HD15_DEFAULT		HPI_HGPIODAT2_HD15_LOW

	#define HPI_HGPIODAT2_HD14_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD14_LOW			(000000u)
	#define HPI_HGPIODAT2_HD14_DEFAULT		HPI_HGPIODAT2_HD14_LOW

	#define HPI_HGPIODAT2_HD13_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD13_LOW			(000000u)
	#define HPI_HGPIODAT2_HD13_DEFAULT		HPI_HGPIODAT2_HD13_LOW

	#define HPI_HGPIODAT2_HD12_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD12_LOW			(000000u)
	#define HPI_HGPIODAT2_HD12_DEFAULT		HPI_HGPIODAT2_HD12_LOW

	#define HPI_HGPIODAT2_HD11_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD11_LOW			(000000u)
	#define HPI_HGPIODAT2_HD11_DEFAULT		HPI_HGPIODAT2_HD11_LOW

	#define HPI_HGPIODAT2_HD10_HIGH		(0x0001u)
	#define HPI_HGPIODAT2_HD10_LOW			(000000u)
	#define HPI_HGPIODAT2_HD10_DEFAULT		HPI_HGPIODAT2_HD10_LOW

	#define HPI_HGPIODAT2_HD9_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD9_LOW			(000000u)
	#define HPI_HGPIODAT2_HD9_DEFAULT		HPI_HGPIODAT2_HD9_LOW

	#define HPI_HGPIODAT2_HD8_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD8_LOW			(000000u)
	#define HPI_HGPIODAT2_HD8_DEFAULT		HPI_HGPIODAT2_HD8_LOW

	#define HPI_HGPIODAT2_HD7_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD7_LOW			(000000u)
	#define HPI_HGPIODAT2_HD7_DEFAULT		HPI_HGPIODAT2_HD7_LOW

	#define HPI_HGPIODAT2_HD6_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD6_LOW			(000000u)
	#define HPI_HGPIODAT2_HD6_DEFAULT		HPI_HGPIODAT2_HD6_LOW

	#define HPI_HGPIODAT2_HD5_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD5_LOW			(000000u)
	#define HPI_HGPIODAT2_HD5_DEFAULT		HPI_HGPIODAT2_HD5_LOW

	#define HPI_HGPIODAT2_HD4_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD4_LOW			(000000u)
	#define HPI_HGPIODAT2_HD4_DEFAULT		HPI_HGPIODAT2_HD4_LOW

	#define HPI_HGPIODAT2_HD3_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD3_LOW			(000000u)
	#define HPI_HGPIODAT2_HD3_DEFAULT		HPI_HGPIODAT2_HD3_LOW

	#define HPI_HGPIODAT2_HD2_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD2_LOW			(000000u)
	#define HPI_HGPIODAT2_HD2_DEFAULT		HPI_HGPIODAT2_HD2_LOW

	#define HPI_HGPIODAT2_HD1_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD1_LOW			(000000u)
	#define HPI_HGPIODAT2_HD1_DEFAULT		HPI_HGPIODAT2_HD1_LOW

	#define HPI_HGPIODAT2_HD0_HIGH			(0x0001u)
	#define HPI_HGPIODAT2_HD0_LOW			(000000u)
	#define HPI_HGPIODAT2_HD0_DEFAULT		HPI_HGPIODAT2_HD0_LOW


#define HPI_HGPIODAT2_RMK(hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODAT2,HD15,hd15))|\
  ( HPI_FMK(HGPIODAT2,HD14,hd14))|\
  ( HPI_FMK(HGPIODAT2,HD13,hd13))|\
  ( HPI_FMK(HGPIODAT2,HD12,hd12))|\
  ( HPI_FMK(HGPIODAT2,HD11,hd11))|\
  ( HPI_FMK(HGPIODAT2,HD10,hd10))|\
  ( HPI_FMK(HGPIODAT2,HD9,hd9))|\
  ( HPI_FMK(HGPIODAT2,HD8,hd8))|\
  ( HPI_FMK(HGPIODAT2,HD7,hd7))|\
  ( HPI_FMK(HGPIODAT2,HD6,hd6))|\
  ( HPI_FMK(HGPIODAT2,HD5,hd5))|\
  ( HPI_FMK(HGPIODAT2,HD4,hd4))|\
  ( HPI_FMK(HGPIODAT2,HD3,hd3))|\
  ( HPI_FMK(HGPIODAT2,HD2,hd2))|\
  ( HPI_FMK(HGPIODAT2,HD1,hd1))|\
  ( HPI_FMK(HGPIODAT2,HD0,hd0))\
)\
 )

#define HPI_HGPIODAT2_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,\
                          hd10_sym,hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,\
                          hd4_sym,hd3_sym,hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODAT2,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODAT2,HD0,hd0_sym))\
)\
 )



/*  Default HGPIODAT3 register value  */

/* ============================================================== */
 /* Make HGPIODAT3 register values based on symbolic constants  */

/*  HGPIODAT3 field values  */

	#define HPI_HGPIODAT3_HD15_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD15_LOW			(000000u)
	#define HPI_HGPIODAT3_HD15_DEFAULT		HPI_HGPIODAT3_HD15_LOW

	#define HPI_HGPIODAT3_HD14_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD14_LOW			(000000u)
	#define HPI_HGPIODAT3_HD14_DEFAULT		HPI_HGPIODAT3_HD14_LOW

	#define HPI_HGPIODAT3_HD13_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD13_LOW			(000000u)
	#define HPI_HGPIODAT3_HD13_DEFAULT		HPI_HGPIODAT3_HD13_LOW

	#define HPI_HGPIODAT3_HD12_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD12_LOW			(000000u)
	#define HPI_HGPIODAT3_HD12_DEFAULT		HPI_HGPIODAT3_HD12_LOW

	#define HPI_HGPIODAT3_HD11_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD11_LOW			(000000u)
	#define HPI_HGPIODAT3_HD11_DEFAULT		HPI_HGPIODAT3_HD11_LOW

	#define HPI_HGPIODAT3_HD10_HIGH		(0x0001u)
	#define HPI_HGPIODAT3_HD10_LOW			(000000u)
	#define HPI_HGPIODAT3_HD10_DEFAULT		HPI_HGPIODAT3_HD10_LOW

	#define HPI_HGPIODAT3_HD9_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD9_LOW			(000000u)
	#define HPI_HGPIODAT3_HD9_DEFAULT		HPI_HGPIODAT3_HD9_LOW

	#define HPI_HGPIODAT3_HD8_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD8_LOW			(000000u)
	#define HPI_HGPIODAT3_HD8_DEFAULT		HPI_HGPIODAT3_HD8_LOW

	#define HPI_HGPIODAT3_HD7_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD7_LOW			(000000u)
	#define HPI_HGPIODAT3_HD7_DEFAULT		HPI_HGPIODAT3_HD7_LOW

	#define HPI_HGPIODAT3_HD6_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD6_LOW			(000000u)
	#define HPI_HGPIODAT3_HD6_DEFAULT		HPI_HGPIODAT3_HD6_LOW

	#define HPI_HGPIODAT3_HD5_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD5_LOW			(000000u)
	#define HPI_HGPIODAT3_HD5_DEFAULT		HPI_HGPIODAT3_HD5_LOW

	#define HPI_HGPIODAT3_HD4_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD4_LOW			(000000u)
	#define HPI_HGPIODAT3_HD4_DEFAULT		HPI_HGPIODAT3_HD4_LOW

	#define HPI_HGPIODAT3_HD3_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD3_LOW			(000000u)
	#define HPI_HGPIODAT3_HD3_DEFAULT		HPI_HGPIODAT3_HD3_LOW

	#define HPI_HGPIODAT3_HD2_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD2_LOW			(000000u)
	#define HPI_HGPIODAT3_HD2_DEFAULT		HPI_HGPIODAT3_HD2_LOW

	#define HPI_HGPIODAT3_HD1_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD1_LOW			(000000u)
	#define HPI_HGPIODAT3_HD1_DEFAULT		HPI_HGPIODAT3_HD1_LOW

	#define HPI_HGPIODAT3_HD0_HIGH			(0x0001u)
	#define HPI_HGPIODAT3_HD0_LOW			(000000u)
	#define HPI_HGPIODAT3_HD0_DEFAULT		HPI_HGPIODAT3_HD0_LOW


#define HPI_HGPIODAT3_RMK(hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODAT3,HD15,hd15))|\
  ( HPI_FMK(HGPIODAT3,HD14,hd14))|\
  ( HPI_FMK(HGPIODAT3,HD13,hd13))|\
  ( HPI_FMK(HGPIODAT3,HD12,hd12))|\
  ( HPI_FMK(HGPIODAT3,HD11,hd11))|\
  ( HPI_FMK(HGPIODAT3,HD10,hd10))|\
  ( HPI_FMK(HGPIODAT3,HD9,hd9))|\
  ( HPI_FMK(HGPIODAT3,HD8,hd8))|\
  ( HPI_FMK(HGPIODAT3,HD7,hd7))|\
  ( HPI_FMK(HGPIODAT3,HD6,hd6))|\
  ( HPI_FMK(HGPIODAT3,HD5,hd5))|\
  ( HPI_FMK(HGPIODAT3,HD4,hd4))|\
  ( HPI_FMK(HGPIODAT3,HD3,hd3))|\
  ( HPI_FMK(HGPIODAT3,HD2,hd2))|\
  ( HPI_FMK(HGPIODAT3,HD1,hd1))|\
  ( HPI_FMK(HGPIODAT3,HD0,hd0))\
)\
 )

#define HPI_HGPIODAT3_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,\
                          hd10_sym,hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,\
                          hd4_sym,hd3_sym,hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODAT3,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODAT3,HD0,hd0_sym))\
)\
 )

 
/*  Default HGPIODDIR register value  */


/* ============================================================== */
 /* Make HGPIODIR register values based on symbolic constants  */

/*  HGPIODIR field values  */
	#define HPI_HGPIODIR_HD15_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD15_INPUT			(000000u)
	#define HPI_HGPIODIR_HD15_DEFAULT		HPI_HGPIODIR_HD15_INPUT

	#define HPI_HGPIODIR_HD14_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD14_INPUT			(000000u)
	#define HPI_HGPIODIR_HD14_DEFAULT		HPI_HGPIODIR_HD14_INPUT

	#define HPI_HGPIODIR_HD13_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD13_INPUT			(000000u)
	#define HPI_HGPIODIR_HD13_DEFAULT		HPI_HGPIODIR_HD13_INPUT

	#define HPI_HGPIODIR_HD12_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD12_INPUT			(000000u)
	#define HPI_HGPIODIR_HD12_DEFAULT		HPI_HGPIODIR_HD12_INPUT

	#define HPI_HGPIODIR_HD11_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD11_INPUT			(000000u)
	#define HPI_HGPIODIR_HD11_DEFAULT		HPI_HGPIODIR_HD11_INPUT

	#define HPI_HGPIODIR_HD10_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD10_INPUT			(000000u)
	#define HPI_HGPIODIR_HD10_DEFAULT		HPI_HGPIODIR_HD10_INPUT

	#define HPI_HGPIODIR_HD9_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD9_INPUT			(000000u)
	#define HPI_HGPIODIR_HD9_DEFAULT		HPI_HGPIODIR_HD9_INPUT

	#define HPI_HGPIODIR_HD8_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD8_INPUT			(000000u)
	#define HPI_HGPIODIR_HD8_DEFAULT		HPI_HGPIODIR_HD8_INPUT

	#define HPI_HGPIODIR_HD7_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD7_INPUT			(000000u)
	#define HPI_HGPIODIR_HD7_DEFAULT		HPI_HGPIODIR_HD7_INPUT

	#define HPI_HGPIODIR_HD6_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD6_INPUT			(000000u)
	#define HPI_HGPIODIR_HD6_DEFAULT		HPI_HGPIODIR_HD6_INPUT

	#define HPI_HGPIODIR_HD5_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD5_INPUT			(000000u)
	#define HPI_HGPIODIR_HD5_DEFAULT		HPI_HGPIODIR_HD5_INPUT

	#define HPI_HGPIODIR_HD4_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD4_INPUT			(000000u)
	#define HPI_HGPIODIR_HD4_DEFAULT		HPI_HGPIODIR_HD4_INPUT

	#define HPI_HGPIODIR_HD3_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD3_INPUT			(000000u)
	#define HPI_HGPIODIR_HD3_DEFAULT		HPI_HGPIODIR_HD3_INPUT

	#define HPI_HGPIODIR_HD2_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD2_INPUT			(000000u)
	#define HPI_HGPIODIR_HD2_DEFAULT		HPI_HGPIODIR_HD2_INPUT

	#define HPI_HGPIODIR_HD1_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD1_INPUT			(000000u)
	#define HPI_HGPIODIR_HD1_DEFAULT		HPI_HGPIODIR_HD1_INPUT

	#define HPI_HGPIODIR_HD0_OUPUT			(0x0001u)
	#define HPI_HGPIODIR_HD0_INPUT			(000000u)
	#define HPI_HGPIODIR_HD0_DEFAULT		HPI_HGPIODIR_HD0_INPUT


#define HPI_HGPIODIR_RMK(hd15,hd14,hd13,hd12,hd11,hd10,hd9,hd8,\
                         hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODIR,HD15,hd15))|\
  ( HPI_FMK(HGPIODIR,HD14,hd14))|\
  ( HPI_FMK(HGPIODIR,HD13,hd13))|\
  ( HPI_FMK(HGPIODIR,HD12,hd12))|\
  ( HPI_FMK(HGPIODIR,HD11,hd11))|\
  ( HPI_FMK(HGPIODIR,HD10,hd10))|\
  ( HPI_FMK(HGPIODIR,HD9,hd9))|\
  ( HPI_FMK(HGPIODIR,HD8,hd8))|\
  ( HPI_FMK(HGPIODIR,HD7,hd7))|\
  ( HPI_FMK(HGPIODIR,HD6,hd6))|\
  ( HPI_FMK(HGPIODIR,HD5,hd5))|\
  ( HPI_FMK(HGPIODIR,HD4,hd4))|\
  ( HPI_FMK(HGPIODIR,HD3,hd3))|\
  ( HPI_FMK(HGPIODIR,HD2,hd2))|\
  ( HPI_FMK(HGPIODIR,HD1,hd1))|\
  ( HPI_FMK(HGPIODIR,HD0,hd0))\
)\
 )

#define HPI_HGPIODIR_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,hd10_sym,\
                          hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,hd4_sym,hd3_sym,\
                          hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODIR,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODIR,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODIR,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODIR,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODIR,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODIR,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODIR,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODIR,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODIR,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODIR,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODIR,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODIR,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODIR,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODIR,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODIR,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODIR,HD0,hd0_sym))\
)\
 )

/*  Default HGPIODIR register value  */



 /* ============================================================== */
 /* Make HGPIODIR1 register values based on symbolic constants  */

/*  HGPIODIR1 field values  */
	#define HPI_HGPIODIR1_HD15_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD15_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD15_DEFAULT		HPI_HGPIODIR1_HD15_INPUT

	#define HPI_HGPIODIR1_HD14_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD14_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD14_DEFAULT		HPI_HGPIODIR1_HD14_INPUT

	#define HPI_HGPIODIR1_HD13_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD13_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD13_DEFAULT		HPI_HGPIODIR1_HD13_INPUT

	#define HPI_HGPIODIR1_HD12_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD12_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD12_DEFAULT		HPI_HGPIODIR1_HD12_INPUT

	#define HPI_HGPIODIR1_HD11_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD11_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD11_DEFAULT		HPI_HGPIODIR1_HD11_INPUT

	#define HPI_HGPIODIR1_HD10_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD10_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD10_DEFAULT		HPI_HGPIODIR1_HD10_INPUT

	#define HPI_HGPIODIR1_HD9_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD9_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD9_DEFAULT		HPI_HGPIODIR1_HD9_INPUT

	#define HPI_HGPIODIR1_HD8_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD8_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD8_DEFAULT		HPI_HGPIODIR1_HD8_INPUT

	#define HPI_HGPIODIR1_HD7_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD7_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD7_DEFAULT		HPI_HGPIODIR1_HD7_INPUT

	#define HPI_HGPIODIR1_HD6_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD6_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD6_DEFAULT		HPI_HGPIODIR1_HD6_INPUT

	#define HPI_HGPIODIR1_HD5_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD5_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD5_DEFAULT		HPI_HGPIODIR1_HD5_INPUT

	#define HPI_HGPIODIR1_HD4_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD4_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD4_DEFAULT		HPI_HGPIODIR1_HD4_INPUT

	#define HPI_HGPIODIR1_HD3_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD3_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD3_DEFAULT		HPI_HGPIODIR1_HD3_INPUT

	#define HPI_HGPIODIR1_HD2_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD2_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD2_DEFAULT		HPI_HGPIODIR1_HD2_INPUT

	#define HPI_HGPIODIR1_HD1_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD1_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD1_DEFAULT		HPI_HGPIODIR1_HD1_INPUT

	#define HPI_HGPIODIR1_HD0_OUPUT			(0x0001u)
	#define HPI_HGPIODIR1_HD0_INPUT			(000000u)
	#define HPI_HGPIODIR1_HD0_DEFAULT		HPI_HGPIODIR1_HD0_INPUT


#define HPI_HGPIODIR1_RMK(hd15,hd14,hd13,hd12,hd11,hd10,hd9,hd8,\
                         hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODIR1,HD15,hd15))|\
  ( HPI_FMK(HGPIODIR1,HD14,hd14))|\
  ( HPI_FMK(HGPIODIR1,HD13,hd13))|\
  ( HPI_FMK(HGPIODIR1,HD12,hd12))|\
  ( HPI_FMK(HGPIODIR1,HD11,hd11))|\
  ( HPI_FMK(HGPIODIR1,HD10,hd10))|\
  ( HPI_FMK(HGPIODIR1,HD9,hd9))|\
  ( HPI_FMK(HGPIODIR1,HD8,hd8))|\
  ( HPI_FMK(HGPIODIR1,HD7,hd7))|\
  ( HPI_FMK(HGPIODIR1,HD6,hd6))|\
  ( HPI_FMK(HGPIODIR1,HD5,hd5))|\
  ( HPI_FMK(HGPIODIR1,HD4,hd4))|\
  ( HPI_FMK(HGPIODIR1,HD3,hd3))|\
  ( HPI_FMK(HGPIODIR1,HD2,hd2))|\
  ( HPI_FMK(HGPIODIR1,HD1,hd1))|\
  ( HPI_FMK(HGPIODIR1,HD0,hd0))\
)\
 )

#define HPI_HGPIODIR1_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,hd10_sym,\
                          hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,hd4_sym,hd3_sym,\
                          hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODIR1,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODIR1,HD0,hd0_sym))\
)\
 )

/*  Default HGPIODIR1 register value  */


 /* ============================================================== */
 /* Make HGPIODIR2 register values based on symbolic constants  */

/*  HGPIODIR2 field values  */
	#define HPI_HGPIODIR2_HD15_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD15_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD15_DEFAULT		HPI_HGPIODIR2_HD15_INPUT

	#define HPI_HGPIODIR2_HD14_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD14_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD14_DEFAULT		HPI_HGPIODIR2_HD14_INPUT

	#define HPI_HGPIODIR2_HD13_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD13_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD13_DEFAULT		HPI_HGPIODIR2_HD13_INPUT

	#define HPI_HGPIODIR2_HD12_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD12_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD12_DEFAULT		HPI_HGPIODIR2_HD12_INPUT

	#define HPI_HGPIODIR2_HD11_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD11_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD11_DEFAULT		HPI_HGPIODIR2_HD11_INPUT

	#define HPI_HGPIODIR2_HD10_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD10_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD10_DEFAULT		HPI_HGPIODIR2_HD10_INPUT

	#define HPI_HGPIODIR2_HD9_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD9_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD9_DEFAULT		HPI_HGPIODIR2_HD9_INPUT

	#define HPI_HGPIODIR2_HD8_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD8_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD8_DEFAULT		HPI_HGPIODIR2_HD8_INPUT

	#define HPI_HGPIODIR2_HD7_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD7_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD7_DEFAULT		HPI_HGPIODIR2_HD7_INPUT

	#define HPI_HGPIODIR2_HD6_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD6_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD6_DEFAULT		HPI_HGPIODIR2_HD6_INPUT

	#define HPI_HGPIODIR2_HD5_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD5_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD5_DEFAULT		HPI_HGPIODIR2_HD5_INPUT

	#define HPI_HGPIODIR2_HD4_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD4_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD4_DEFAULT		HPI_HGPIODIR2_HD4_INPUT

	#define HPI_HGPIODIR2_HD3_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD3_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD3_DEFAULT		HPI_HGPIODIR2_HD3_INPUT

	#define HPI_HGPIODIR2_HD2_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD2_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD2_DEFAULT		HPI_HGPIODIR2_HD2_INPUT

	#define HPI_HGPIODIR2_HD1_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD1_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD1_DEFAULT		HPI_HGPIODIR2_HD1_INPUT

	#define HPI_HGPIODIR2_HD0_OUPUT			(0x0001u)
	#define HPI_HGPIODIR2_HD0_INPUT			(000000u)
	#define HPI_HGPIODIR2_HD0_DEFAULT		HPI_HGPIODIR2_HD0_INPUT


#define HPI_HGPIODIR2_RMK(hd15,hd14,hd13,hd12,hd11,hd10,hd9,hd8,\
                         hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODIR2,HD15,hd15))|\
  ( HPI_FMK(HGPIODIR2,HD14,hd14))|\
  ( HPI_FMK(HGPIODIR2,HD13,hd13))|\
  ( HPI_FMK(HGPIODIR2,HD12,hd12))|\
  ( HPI_FMK(HGPIODIR2,HD11,hd11))|\
  ( HPI_FMK(HGPIODIR2,HD10,hd10))|\
  ( HPI_FMK(HGPIODIR2,HD9,hd9))|\
  ( HPI_FMK(HGPIODIR2,HD8,hd8))|\
  ( HPI_FMK(HGPIODIR2,HD7,hd7))|\
  ( HPI_FMK(HGPIODIR2,HD6,hd6))|\
  ( HPI_FMK(HGPIODIR2,HD5,hd5))|\
  ( HPI_FMK(HGPIODIR2,HD4,hd4))|\
  ( HPI_FMK(HGPIODIR2,HD3,hd3))|\
  ( HPI_FMK(HGPIODIR2,HD2,hd2))|\
  ( HPI_FMK(HGPIODIR2,HD1,hd1))|\
  ( HPI_FMK(HGPIODIR2,HD0,hd0))\
)\
 )

#define HPI_HGPIODIR2_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,hd10_sym,\
                          hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,hd4_sym,hd3_sym,\
                          hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODIR2,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODIR2,HD0,hd0_sym))\
)\
 )

/*  Default HGPIODIR2 register value  */

 /* ============================================================== */
 /* Make HGPIODIR3 register values based on symbolic constants  */

/*  HGPIODIR3 field values  */
	#define HPI_HGPIODIR3_HD15_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD15_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD15_DEFAULT		HPI_HGPIODIR3_HD15_INPUT

	#define HPI_HGPIODIR3_HD14_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD14_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD14_DEFAULT		HPI_HGPIODIR3_HD14_INPUT

	#define HPI_HGPIODIR3_HD13_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD13_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD13_DEFAULT		HPI_HGPIODIR3_HD13_INPUT

	#define HPI_HGPIODIR3_HD12_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD12_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD12_DEFAULT		HPI_HGPIODIR3_HD12_INPUT

	#define HPI_HGPIODIR3_HD11_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD11_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD11_DEFAULT		HPI_HGPIODIR3_HD11_INPUT

	#define HPI_HGPIODIR3_HD10_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD10_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD10_DEFAULT		HPI_HGPIODIR3_HD10_INPUT

	#define HPI_HGPIODIR3_HD9_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD9_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD9_DEFAULT		HPI_HGPIODIR3_HD9_INPUT

	#define HPI_HGPIODIR3_HD8_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD8_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD8_DEFAULT		HPI_HGPIODIR3_HD8_INPUT

	#define HPI_HGPIODIR3_HD7_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD7_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD7_DEFAULT		HPI_HGPIODIR3_HD7_INPUT

	#define HPI_HGPIODIR3_HD6_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD6_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD6_DEFAULT		HPI_HGPIODIR3_HD6_INPUT

	#define HPI_HGPIODIR3_HD5_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD5_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD5_DEFAULT		HPI_HGPIODIR3_HD5_INPUT

	#define HPI_HGPIODIR3_HD4_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD4_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD4_DEFAULT		HPI_HGPIODIR3_HD4_INPUT

	#define HPI_HGPIODIR3_HD3_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD3_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD3_DEFAULT		HPI_HGPIODIR3_HD3_INPUT

	#define HPI_HGPIODIR3_HD2_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD2_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD2_DEFAULT		HPI_HGPIODIR3_HD2_INPUT

	#define HPI_HGPIODIR3_HD1_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD1_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD1_DEFAULT		HPI_HGPIODIR3_HD1_INPUT

	#define HPI_HGPIODIR3_HD0_OUPUT			(0x0001u)
	#define HPI_HGPIODIR3_HD0_INPUT			(000000u)
	#define HPI_HGPIODIR3_HD0_DEFAULT		HPI_HGPIODIR3_HD0_INPUT


#define HPI_HGPIODIR3_RMK(hd15,hd14,hd13,hd12,hd11,hd10,hd9,hd8,\
                         hd7,hd6,hd5,hd4,hd3,hd2,hd1,hd0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIODIR3,HD15,hd15))|\
  ( HPI_FMK(HGPIODIR3,HD14,hd14))|\
  ( HPI_FMK(HGPIODIR3,HD13,hd13))|\
  ( HPI_FMK(HGPIODIR3,HD12,hd12))|\
  ( HPI_FMK(HGPIODIR3,HD11,hd11))|\
  ( HPI_FMK(HGPIODIR3,HD10,hd10))|\
  ( HPI_FMK(HGPIODIR3,HD9,hd9))|\
  ( HPI_FMK(HGPIODIR3,HD8,hd8))|\
  ( HPI_FMK(HGPIODIR3,HD7,hd7))|\
  ( HPI_FMK(HGPIODIR3,HD6,hd6))|\
  ( HPI_FMK(HGPIODIR3,HD5,hd5))|\
  ( HPI_FMK(HGPIODIR3,HD4,hd4))|\
  ( HPI_FMK(HGPIODIR3,HD3,hd3))|\
  ( HPI_FMK(HGPIODIR3,HD2,hd2))|\
  ( HPI_FMK(HGPIODIR3,HD1,hd1))|\
  ( HPI_FMK(HGPIODIR3,HD0,hd0))\
)\
 )

#define HPI_HGPIODIR3_RMKS(hd15_sym,hd14_sym,hd13_sym,hd12_sym,hd11_sym,hd10_sym,\
                          hd9_sym,hd8_sym,hd7_sym,hd6_sym,hd5_sym,hd4_sym,hd3_sym,\
                          hd2_sym,hd1_sym,hd0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIODIR3,HD15,hd15_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD14,hd14_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD13,hd13_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD12,hd12_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD11,hd11_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD10,hd10_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD9,hd9_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD8,hd8_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD7,hd7_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD6,hd6_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD5,hd5_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD4,hd4_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD3,hd3_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD2,hd2_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD1,hd1_sym))|\
  ( HPI_FMKS(HGPIODIR3,HD0,hd0_sym))\
)\
 )

/*  Default HGPIODIR3 register value  */

/* ============================================================== */
 /* Make HGPIOEN register values based on symbolic constants  */

/*  HGPIOEN field values  */
	#define HPI_HGPIOEN_EN12_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN12_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN12_DEFAULT		HPI_HGPIOEN_EN12_DISABLE

	#define HPI_HGPIOEN_EN11_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN11_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN11_DEFAULT		HPI_HGPIOEN_EN11_DISABLE

	#define HPI_HGPIOEN_EN8_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN8_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN8_DEFAULT		HPI_HGPIOEN_EN8_DISABLE

	#define HPI_HGPIOEN_EN7_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN7_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN7_DEFAULT		HPI_HGPIOEN_EN7_DISABLE

	#define HPI_HGPIOEN_EN6_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN6_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN6_DEFAULT		HPI_HGPIOEN_EN6_DISABLE

	#define HPI_HGPIOEN_EN4_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN4_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN4_DEFAULT		HPI_HGPIOEN_EN4_DISABLE

	#define HPI_HGPIOEN_EN2_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN2_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN2_DEFAULT		HPI_HGPIOEN_EN2_DISABLE

	#define HPI_HGPIOEN_EN1_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN1_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN1_DEFAULT		HPI_HGPIOEN_EN1_DISABLE

	#define HPI_HGPIOEN_EN0_ENABLE			(0x0001u)
	#define HPI_HGPIOEN_EN0_DISABLE			(000000u)
	#define HPI_HGPIOEN_EN0_DEFAULT		HPI_HGPIOEN_EN0_DISABLE


#define HPI_HGPIOEN_RMK(en12,en11,en8,en7,en6,en4,en2,en1,en0)\
 ((Uint16) ( \
  ( HPI_FMK(HGPIOEN,EN12,en12))|\
  ( HPI_FMK(HGPIOEN,EN11,en11))|\
  ( HPI_FMK(HGPIOEN,EN8,en8))|\
  ( HPI_FMK(HGPIOEN,EN7,en7))|\
  ( HPI_FMK(HGPIOEN,EN6,en6))|\
  ( HPI_FMK(HGPIOEN,EN4,en4))|\
  ( HPI_FMK(HGPIOEN,EN2,en2))|\
  ( HPI_FMK(HGPIOEN,EN1,en1))|\
  ( HPI_FMK(HGPIOEN,EN0,en0))\
)\
 )

#define HPI_HGPIOEN_RMKS(en12_sym,en11_sym,en8_sym,en7_sym,\
                         en6_sym,en4_sym,en2_sym,en1_sym,en0_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HGPIOEN,EN12,en12_sym))|\
  ( HPI_FMKS(HGPIOEN,EN11,en11_sym))|\
  ( HPI_FMKS(HGPIOEN,EN8,en8_sym))|\
  ( HPI_FMKS(HGPIOEN,EN7,en7_sym))|\
  ( HPI_FMKS(HGPIOEN,EN6,en6_sym))|\
  ( HPI_FMKS(HGPIOEN,EN4,en4_sym))|\
  ( HPI_FMKS(HGPIOEN,EN2,en2_sym))|\
  ( HPI_FMKS(HGPIOEN,EN1,en1_sym))|\
  ( HPI_FMKS(HGPIOEN,EN0,en0_sym))\
)\
 )

/*  Default HGPIOEN register value  */

/* ============================================================== */
 /* Make HPIAR register values based on symbolic constants  */

/*  HPIAR field values  */

	#define HPI_HPIAR_HPIAR_OF(x)			((Uint16)(x))
      #define HPI_HPIAR_HPIAR_DEFAULT                (0x0000u)

#define HPI_HPIAR_RMK(hpiar)\
 ((Uint16) ( \
  ( HPI_FMK(HPIAR,HPIAR,hpiar))\
)\
 )

#define HPI_HPIAR_RMKS(hpiar_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HPIAR,HPIAR,hpiar_sym))\
)\
 )

/*  Default HPIAR register value  */

/* ============================================================== */
 /* Make HPIAW register values based on symbolic constants  */

/*  HPIAW field values  */

	#define HPI_HPIAW_HPIAW_OF(x)			((Uint16)(x))
      #define HPI_HPIAW_HPIAW_DEFAULT                (0x0000u)

#define HPI_HPIAW_RMK(hpiaw)\
 ((Uint16) ( \
  ( HPI_FMK(HPIAW,HPIAW,hpiaw))\
)\
 )

#define HPI_HPIAW_RMKS(hpiaw_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HPIAW,HPIAW,hpiaw_sym))\
)\
 )

/*  Default HPIAW register value  */

/* ============================================================== */
 /* Make HPIC register values based on symbolic constants  */

/*  HPIC field values  */

	#define HPI_HPIC_HPIASEL_READ_ADDRESS			(0x0001u)
	#define HPI_HPIC_HPIASEL_WRITE_ADDRESS			(000000u)
	#define HPI_HPIC_HPIASEL_DEFAULT		HPI_HPIC_HPIASEL_WRITE_ADDRESS


	#define HPI_HPIC_DUALHPIA_ON			(0x0001u)
	#define HPI_HPIC_DUALHPIA_OFF			(000000u)
	#define HPI_HPIC_DUALHPIA_DEFAULT		HPI_HPIC_DUALHPIA_OFF

	#define HPI_HPIC_BOBSTAT_LEAST_SIGNIFICANT			(0x0001u)
	#define HPI_HPIC_BOBSTAT_MOST_SIGNIFICANT			(000000u)
	#define HPI_HPIC_BOBSTAT_DEFAULT		HPI_HPIC_BOBSTAT_MOST_SIGNIFICANT

	#define HPI_HPIC_HPIRST_FIFO_RESET			(0x0001u)
	#define HPI_HPIC_HPIRST_FIFO_NOT_RESET			(000000u)

	#define HPI_HPIC_FETCH_ON			(0x0001u)
	#define HPI_HPIC_FETCH_OFF			(000000u)
	#define HPI_HPIC_FETCH_DEFAULT		HPI_HPIC_FETCH_OFF

	#define HPI_HPIC_HRDY_ON			(0x0001u)
	#define HPI_HPIC_HRDY_OFF			(000000u)
	#define HPI_HPIC_HRDY_DEFAULT		HPI_HPIC_HRDY_OFF

	#define HPI_HPIC_HINT_ON			(0x0001u)
	#define HPI_HPIC_HINT_OFF			(000000u)
	#define HPI_HPIC_HINT_DEFAULT		HPI_HPIC_HINT_OFF

	#define HPI_HPIC_DSPINT_ON			(0x0001u)
	#define HPI_HPIC_DSPINT_OFF			(000000u)
	#define HPI_HPIC_DSPINT_DEFAULT		HPI_HPIC_DSPINT_OFF

	#define HPI_HPIC_BOB_LEAST_SIGNIFICANT_FIRST			(0x0001u)
	#define HPI_HPIC_BOB_MOST_SIGNIFICANT_FIRST			(000000u)
	#define HPI_HPIC_BOB_DEFAULT		HPI_HPIC_BOB_MOST_SIGNIFICANT_FIRST


#define HPI_HPIC_RMK(hpiasel,dualhpia,bobstat,hpirst,hint,bob)\
 ((Uint16) ( \
  ( HPI_FMK(HPIC,HPIASEL,hpiasel))|\
  ( HPI_FMK(HPIC,DUALHPIA,dualhpia))|\
  ( HPI_FMK(HPIC,BOBSTAT,bobstat))|\
  ( HPI_FMK(HPIC,HPIRST,hpirst))|\
  ( HPI_FMK(HPIC,HINT,hint))|\
  ( HPI_FMK(HPIC,BOB,bob))\
)\
 )

#define HPI_HPIC_RMKS(hpiasel_sym,dualhpia_sym,bobstat_sym,hpirst_sym,hint_sym,bob_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(HPIC,HPIASEL,hpiasel_sym))|\
  ( HPI_FMKS(HPIC,DUALHPIA,dualhpia_sym))|\
  ( HPI_FMKS(HPIC,BOBSTAT,bobstat_sym))|\
  ( HPI_FMKS(HPIC,HPIRST,hpirst_sym))|\
  ( HPI_FMKS(HPIC,HINT,hint_sym))|\
  ( HPI_FMKS(HPIC,BOB,bob_sym))\
)\
 )

/*  Default HPIC register value  */

/* ============================================================== */
 /* Make PIDLSW register values based on symbolic constants  */

/*  PIDLSW field values  */


/*  Default PIDLSW register value  */

/* ============================================================== */
 /* Make PIDMSW register values based on symbolic constants  */

/*  PIDMSW field values  */
/*  Default PIDMSW register value  */

/* ============================================================== */
 /* Make PWREMU register values based on symbolic constants  */

/*  PWREMU field values  */

	#define HPI_HPWREMU_SOFT_OFF			(000000u)
	#define HPI_HPWREMU_SOFT_ON			(0x0001u)
	#define HPI_HPWREMU_SOFT_DEFAULT		HPI_HPWREMU_SOFT_OFF

	#define HPI_HPWREMU_FREE_ON			(0x0001u)
	#define HPI_HPWREMU_FREE_OFF			(000000u)
	#define HPI_HPWREMU_FREE_DEFAULT		HPI_HPWREMU_FREE_OFF


#define HPI_HPWREMU_RMK(soft,free)\
 ((Uint16) ( \
  ( HPI_FMK(PWREMU,SOFT,soft))|\
  ( HPI_FMK(PWREMU,FREE,free))\
)\
 )

#define HPI_HPWREMU_RMKS(soft_sym,free_sym)\
 ((Uint16) ( \
  ( HPI_FMKS(PWREMU,SOFT,soft_sym))|\
  ( HPI_FMKS(PWREMU,FREE,free_sym))\
)\
 )

/*  Default PWREMU register value  */

/*************************************************\
 HPI global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 hpwremu;
	Uint16 hgpioen;
	Uint16 hgpiodir;
	Uint16 hpic;
} HPI_Config;

/*************************************************\
* HPI global variable declarations
\*************************************************/


/*************************************************\
* HPI global function declarations
\*************************************************/

CSLAPI void HPI_config(HPI_Config *myConfig);
CSLAPI void HPI_getConfig(HPI_Config *myConfig);

/*************************************************\
* HPI inline function declarations
\*************************************************/


#ifdef USEDEFS


#endif /*USEDEFS */

#else
    #ifndef _HPI_MOD_
	  #error HPI Hal Module Not Supported on Specified Target
    #endif
#endif  /* _HPI_SUPPORT  */

#endif  /* _CSL_HPIHAL_H  */

/******************************************************************************\
*     
*      End of csl_hpi.h 
*
\******************************************************************************/
