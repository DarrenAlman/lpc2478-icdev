/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include "target_serial.h"
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "sample.h"


#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include <target_cfg1_out.h>

const uint32_t TOPPERS_cfg_magic_number = 0x12345678;
const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const unsigned_t TOPPERS_cfg_CHAR_BIT = CHAR_BIT;
const unsigned_t TOPPERS_cfg_CHAR_MAX = CHAR_MAX;
const unsigned_t TOPPERS_cfg_CHAR_MIN = CHAR_MIN;
const unsigned_t TOPPERS_cfg_SCHAR_MAX = SCHAR_MAX;
const unsigned_t TOPPERS_cfg_SHRT_MAX = SHRT_MAX;
const unsigned_t TOPPERS_cfg_INT_MAX = INT_MAX;
const unsigned_t TOPPERS_cfg_LONG_MAX = LONG_MAX;

const unsigned_t TOPPERS_cfg_TA_NULL = TA_NULL;
const unsigned_t TOPPERS_cfg_TA_ACT = TA_ACT;
const unsigned_t TOPPERS_cfg_TA_TPRI = TA_TPRI;
const unsigned_t TOPPERS_cfg_TA_MPRI = TA_MPRI;
const unsigned_t TOPPERS_cfg_TA_WMUL = TA_WMUL;
const unsigned_t TOPPERS_cfg_TA_CLR = TA_CLR;
const unsigned_t TOPPERS_cfg_TA_STA = TA_STA;
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = TA_NONKERNEL;
const unsigned_t TOPPERS_cfg_TA_ENAINT = TA_ENAINT;
const unsigned_t TOPPERS_cfg_TA_EDGE = TA_EDGE;
const signed_t TOPPERS_cfg_TMIN_TPRI = TMIN_TPRI;
const signed_t TOPPERS_cfg_TMAX_TPRI = TMAX_TPRI;
const signed_t TOPPERS_cfg_TMIN_DPRI = TMIN_DPRI;
const signed_t TOPPERS_cfg_TMAX_DPRI = TMAX_DPRI;
const signed_t TOPPERS_cfg_TMIN_MPRI = TMIN_MPRI;
const signed_t TOPPERS_cfg_TMAX_MPRI = TMAX_MPRI;
const signed_t TOPPERS_cfg_TMIN_ISRPRI = TMIN_ISRPRI;
const signed_t TOPPERS_cfg_TMAX_ISRPRI = TMAX_ISRPRI;
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = TMAX_MAXSEM;
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = TMAX_RELTIM;
const signed_t TOPPERS_cfg_TMIN_INTPRI = TMIN_INTPRI;
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = 
#if defined(OMIT_INITIALIZE_INTERRUPT)
1;
#else
0;
#endif
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = 
#if defined(OMIT_INITIALIZE_EXCEPTION)
1;
#else
0;
#endif
const unsigned_t TOPPERS_cfg_sizeof_ID = sizeof(ID);
const unsigned_t TOPPERS_cfg_sizeof_uint_t = sizeof(uint_t);
const unsigned_t TOPPERS_cfg_sizeof_SIZE = sizeof(SIZE);
const unsigned_t TOPPERS_cfg_sizeof_ATR = sizeof(ATR);
const unsigned_t TOPPERS_cfg_sizeof_PRI = sizeof(PRI);
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_VP = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = sizeof(intptr_t);
const unsigned_t TOPPERS_cfg_sizeof_FP = sizeof(FP);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = sizeof(TINIB);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = offsetof(TINIB,tskatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = offsetof(TINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = offsetof(TINIB,ipriority);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = offsetof(TINIB,stksz);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = offsetof(TINIB,stk);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texatr = offsetof(TINIB,texatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texrtn = offsetof(TINIB,texrtn);
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = sizeof(SEMINIB);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = offsetof(SEMINIB,sematr);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = offsetof(SEMINIB,isemcnt);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = offsetof(SEMINIB,maxsem);
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = sizeof(FLGPTN);
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = sizeof(FLGINIB);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = offsetof(FLGINIB,flgatr);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = offsetof(FLGINIB,iflgptn);
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = sizeof(DTQINIB);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = offsetof(DTQINIB,dtqatr);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = offsetof(DTQINIB,dtqcnt);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = offsetof(DTQINIB,p_dtqmb);
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = sizeof(PDQINIB);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = offsetof(PDQINIB,pdqatr);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = offsetof(PDQINIB,pdqcnt);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = offsetof(PDQINIB,maxdpri);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = offsetof(PDQINIB,p_pdqmb);
const unsigned_t TOPPERS_cfg_sizeof_MBXINIB = sizeof(MBXINIB);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_mbxatr = offsetof(MBXINIB,mbxatr);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_maxmpri = offsetof(MBXINIB,maxmpri);
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = sizeof(MPFINIB);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = offsetof(MPFINIB,mpfatr);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = offsetof(MPFINIB,blkcnt);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = offsetof(MPFINIB,blksz);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = offsetof(MPFINIB,mpf);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = offsetof(MPFINIB,p_mpfmb);
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = sizeof(CYCINIB);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = offsetof(CYCINIB,cycatr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = offsetof(CYCINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cychdr = offsetof(CYCINIB,cychdr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = offsetof(CYCINIB,cyctim);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = offsetof(CYCINIB,cycphs);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = offsetof(ALMINIB,almatr);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = offsetof(ALMINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almhdr = offsetof(ALMINIB,almhdr);
const unsigned_t TOPPERS_cfg_sizeof_INHNO = sizeof(INHNO);
const unsigned_t TOPPERS_cfg_sizeof_INTNO = sizeof(INTNO);
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = sizeof(EXCNO);
const unsigned_t TOPPERS_cfg_TA_HIGHLEVEL = TA_HIGHLEVEL;
const unsigned_t TOPPERS_cfg_TA_POSEDGE = TA_POSEDGE;
const unsigned_t TOPPERS_cfg_TA_LOWLEVEL = TA_LOWLEVEL;


/* #include "target_timer.h" */

#line 10 "../../target/at91skyeye_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_0 = 0;
const unsigned_t TOPPERS_cfg_valueof_iniatr_0 = ( TA_NULL ); 
#line 11 "../../target/at91skyeye_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
const unsigned_t TOPPERS_cfg_valueof_teratr_1 = ( TA_NULL ); 
#line 12 "../../target/at91skyeye_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
const unsigned_t TOPPERS_cfg_valueof_inhno_2 = ( INHNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_inhatr_2 = ( TA_NULL ); 
#line 13 "../../target/at91skyeye_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
const unsigned_t TOPPERS_cfg_valueof_intno_3 = ( INTNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_intatr_3 = ( TA_ENAINT|INTATR_TIMER ); const signed_t TOPPERS_cfg_valueof_intpri_3 = ( INTPRI_TIMER ); /* #include "syssvc/syslog.h" */

#line 10 "../../syssvc/syslog.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
const unsigned_t TOPPERS_cfg_valueof_iniatr_4 = ( TA_NULL ); /* #include "syssvc/banner.h" */

#line 10 "../../syssvc/banner.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include "target_serial.h" */

#line 10 "../../target/at91skyeye_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
const unsigned_t TOPPERS_cfg_valueof_iniatr_6 = ( TA_NULL ); 
#line 11 "../../target/at91skyeye_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
const unsigned_t TOPPERS_cfg_valueof_inhno_7 = ( INHNO_SIO ); const unsigned_t TOPPERS_cfg_valueof_inhatr_7 = ( TA_NULL ); 
#line 12 "../../target/at91skyeye_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
const unsigned_t TOPPERS_cfg_valueof_intno_8 = ( INTNO_SIO ); const unsigned_t TOPPERS_cfg_valueof_intatr_8 = ( INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_8 = ( INTPRI_SIO ); /* #include "syssvc/serial.h" */

#line 13 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
const unsigned_t TOPPERS_cfg_valueof_iniatr_9 = ( TA_NULL ); 
#line 15 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#define SERIAL_RCV_SEM1	(<>)

#line 15 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_10 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_10 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_10 = ( 1 ); 
#line 16 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#define SERIAL_SND_SEM1	(<>)

#line 16 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_11 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_11 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_11 = ( 1 ); 
#if TNUM_PORT >= 2

#line 18 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#define SERIAL_RCV_SEM2	(<>)

#line 18 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_12 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_12 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_12 = ( 1 ); 
#line 19 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#define SERIAL_SND_SEM2	(<>)

#line 19 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_13 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_13 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_13 = ( 1 ); 
#endif 

#if TNUM_PORT >= 3

#line 22 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#define SERIAL_RCV_SEM3	(<>)

#line 22 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_14 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_14 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_14 = ( 1 ); 
#line 23 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#define SERIAL_SND_SEM3	(<>)

#line 23 "../../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_15 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_15 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_15 = ( 1 ); 
#endif 
/* #include "syssvc/logtask.h" */

#line 10 "../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#define LOGTASK	(<>)

#line 10 "../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_16 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_16 = ( LOGTASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_16 = ( LOGTASK_STACK_SIZE ); 
#line 12 "../../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
const unsigned_t TOPPERS_cfg_valueof_teratr_17 = ( TA_NULL ); /* #include "sample.h" */

#line 15 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#define TASK1	(<>)

#line 15 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_18 = ( TA_NULL ); const signed_t TOPPERS_cfg_valueof_itskpri_18 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_18 = ( STACK_SIZE ); 
#line 16 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
#define TASK2	(<>)

#line 16 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_19 = ( TA_NULL ); const signed_t TOPPERS_cfg_valueof_itskpri_19 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_19 = ( STACK_SIZE ); 
#line 17 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
#define TASK3	(<>)

#line 17 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_20 = ( TA_NULL ); const signed_t TOPPERS_cfg_valueof_itskpri_20 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_20 = ( STACK_SIZE ); 
#line 18 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
#define MAIN_TASK	(<>)

#line 18 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_21 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_21 = ( MAIN_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_21 = ( STACK_SIZE ); 
#line 19 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
#define SEM1	(<>)

#line 19 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_22 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_22 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_22 = ( 1 ); 
#line 20 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
#define SEM2	(<>)

#line 20 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_23 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_23 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_23 = ( 1 ); 
#line 21 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
#define SEM3	(<>)

#line 21 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_24 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_24 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_24 = ( 1 ); 
#line 22 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
const unsigned_t TOPPERS_cfg_valueof_texatr_25 = ( TA_NULL ); 
#line 23 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
const unsigned_t TOPPERS_cfg_valueof_texatr_26 = ( TA_NULL ); 
#line 24 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
const unsigned_t TOPPERS_cfg_valueof_texatr_27 = ( TA_NULL ); 
#line 25 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#define CYCHDR1	(<>)

#line 25 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_28 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_cyctim_28 = ( 2000 ); const unsigned_t TOPPERS_cfg_valueof_cycphs_28 = ( 0 ); 
#line 26 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#define ALMHDR1	(<>)

#line 26 "sample.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_29 = ( TA_NULL ); 
#ifdef CPUEXC1

#line 28 "sample.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
const unsigned_t TOPPERS_cfg_valueof_excno_30 = ( CPUEXC1 ); const unsigned_t TOPPERS_cfg_valueof_excatr_30 = ( TA_NULL ); 
#endif 
