/**********************************************************
 * - File: motdrv.hpp
 * - Author: Rubén Padial Allué
 * - Contact: padialruben@gmail.com
 * - Date: 
 * - Revision: 
 **********************************************************/

#ifndef motdrv_defs_hpp
#define motdrv_defs_hpp

/**********************************************************/
/*                        INCLUDES                        */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                        DEFINES                         */
/**********************************************************/
/* General Configuration */
#define BOOL_MOTDRV_GC_I_SCALE_ANALOG(X)          (bool(((X)&0x1)<<0))
#define BOOL_MOTDRV_GC_INTERNAL_RSENSE(X)         (bool(((X)&0x1)<<1))
#define BOOL_MOTDRV_GC_EN_PWM_MODE(X)             (bool(((X)&0x1)<<2))
#define BOOL_MOTDRV_GC_ENC_COMMUNICATION(X)       (bool(((X)&0x1)<<3))
#define BOOL_MOTDRV_GC_SHAFT(X)                   (bool(((X)&0x1)<<4))
#define BOOL_MOTDRV_GC_DIAG0_ERROR(X)             (bool(((X)&0x1)<<5))
#define BOOL_MOTDRV_GC_DIAG0_OTPW(X)              (bool(((X)&0x1)<<6))
#define BOOL_MOTDRV_GC_DIAG0_STALLSTEP(X)         (bool(((X)&0x1)<<7))
#define BOOL_MOTDRV_GC_DIAG1_STALLDIR(X)          (bool(((X)&0x1)<<8))
#define BOOL_MOTDRV_GC_DIAG1_INDEX(X)             (bool(((X)&0x1)<<9))
#define BOOL_MOTDRV_GC_DIAG1_ONSTATE(X)           (bool(((X)&0x1)<<10))
#define BOOL_MOTDRV_GC_DIAG1_STEPS_SKIPPED(X)     (bool(((X)&0x1)<<11))
#define BOOL_MOTDRV_GC_DIAG0_INT_PUSHPULL(X)      (bool(((X)&0x1)<<12))
#define BOOL_MOTDRV_GC_DIAG1_POSCOMP_PUSHPULL(X)  (bool(((X)&0x1)<<13))
#define BOOL_MOTDRV_GC_SMALL_HYSTERESIS(X)        (bool(((X)&0x1)<<14))
#define BOOL_MOTDRV_GC_STOP_ENABLE(X)             (bool(((X)&0x1)<<15))
#define BOOL_MOTDRV_GC_DIRECT_MODE(X)             (bool(((X)&0x1)<<16))
#define BOOL_MOTDRV_GC_TEST_MODE(X)               (bool(((X)&0x1)<<17))

/* Velocity Configuration */
#define U8_MOTDRV_VC_IHOLD(X)                     (uint8_t(((X)&0x1F)<<0)) //
#define U8_MOTDRV_VC_IRUN(X)                      (uint8_t(((X)&0x1F)<<8)) //
#define U8_MOTDRV_VC_IHOLDDELAY(X)                (uint8_t(((X)&0x0F)<<16)) //

#define U32_MOTDRV_VC_TPOWERDOWN(X)               (uint32_t((X)&0x3FF)) //
#define U32_MOTDRV_VC_TPWMTHRS(X)                 (uint32_t((X)&0x3FF)) //
#define U32_MOTDRV_VC_TCOOLTHRS(X)                (uint32_t((X)&0x3FF)) //((0xB)&0x3FF) //
#define U32_MOTDRV_VC_THIGH(X)                    (uint32_t((X)&0x3FF)) //

/* Ramp Generator Configuration */
#define U8_MOTDRV_RGC_RAMPMODE(X)                 (uint8_t((X)&0x03))
#define U32_MOTDRV_RGC_XACTUAL(X)                 (uint32_t(X))
#define U32_MOTDRV_RGC_VACTUAL(X)                 (uint32_t((X)&0x00FFFFFF))
#define U32_MOTDRV_RGC_VSTART(X)                  (uint32_t((X)&0x0003FFFF))
#define U16_MOTDRV_RGC_A1(X)                      (uint16_t((X)&0x0000FFFF))
#define U32_MOTDRV_RGC_V1(X)                      (uint32_t((X)&0x3FF))
#define U16_MOTDRV_RGC_AMAX(X)                    (uint16_t(X))
#define U32_MOTDRV_RGC_VMAX(X)                    (uint32_t((X)&0x007FFFFF))
#define U16_MOTDRV_RGC_DMAX(X)                    (uint16_t(X))
#define U16_MOTDRV_RGC_D1(X)                      (uint16_t(X))
#define U32_MOTDRV_RGC_VSTOP(X)                   (uint32_t((X)&0x0003FFFF))
#define U16_MOTDRV_RGC_TZEROWAIT(X)               (uint16_t(X))
#define U32_MOTDRV_RGC_XTARGET(X)                 (uint32_t(X))
#define U32_MOTDRV_RGC_VDCMIN(X)                  (uint32_t((X)&0x007FFFFF))

#define BOOL_MOTDRV_RGC_SW_MODE_EN_SOFTSTOP(X)       (bool(((X)&0x1)<<11))
#define BOOL_MOTDRV_RGC_SW_MODE_SG_STOP(X)           (bool(((X)&0x1)<<10))
#define BOOL_MOTDRV_RGC_SW_MODE_EN_LATCHENCODER(X)   (bool(((X)&0x1)<<9))
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_INACTIVE(X)  (bool(((X)&0x1)<<8))
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_ACTIVE(X)    (bool(((X)&0x1)<<7))
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_INACTIVE(X)  (bool(((X)&0x1)<<6))
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_ACTIVE(X)    (bool(((X)&0x1)<<5))
#define BOOL_MOTDRV_RGC_SW_MODE_SWAP_LR(X)           (bool(((X)&0x1)<<4))
#define BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_R(X)        (bool(((X)&0x1)<<3))
#define BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_L(X)        (bool(((X)&0x1)<<2))
#define BOOL_MOTDRV_RGC_SW_MODE_STOP_R_ENABLE(X)     (bool(((X)&0x1)<<1))
#define BOOL_MOTDRV_RGC_SW_MODE_STOP_L_ENABLE(X)     (bool(((X)&0x1)<<0))

/* Encoder Configuration */
/* ENCMODE */ 
#define BOOL_MOTDRV_EC_ENCMODE_ENC_SEL_DECIMAL(X) (bool(((X)&0x1)<<10))
#define BOOL_MOTDRV_EC_ENCMODE_LATCH_X_ACT(X)     (bool(((X)&0x1)<<9))
#define BOOL_MOTDRV_EC_ENCMODE_CLR_ENC_X(X)       (bool(((X)&0x1)<<8))
#define BOOL_MOTDRV_EC_ENCMODE_NEG_EDGE(X)        (bool(((X)&0x1)<<7))
#define BOOL_MOTDRV_EC_ENCMODE_POS_EDGE(X)        (bool(((X)&0x1)<<6))
#define BOOL_MOTDRV_EC_ENCMODE_CLR_ONCE(X)        (bool(((X)&0x1)<<5))
#define BOOL_MOTDRV_EC_ENCMODE_CLR_CONT(X)        (bool(((X)&0x1)<<4))
#define BOOL_MOTDRV_EC_ENCMODE_IGNORE_AB(X)       (bool(((X)&0x1)<<3))
#define BOOL_MOTDRV_EC_ENCMODE_POL_N(X)           (bool(((X)&0x1)<<2))
#define BOOL_MOTDRV_EC_ENCMODE_POL_B(X)           (bool(((X)&0x1)<<1))
#define BOOL_MOTDRV_EC_ENCMODE_POL_A(X)           (bool(((X)&0x1)<<0))

#define U32_MOTDRV_EC_X_ENC(X)                    (uint32_t(X))
#define U32_MOTDRV_EC_ENC_CONST(X)                (uint32_t(X))

/* Motor Driver Configuration */
/* Microstepping Control */
#define U32_MOTDRV_MDC_MSLUT_0(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_1(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_2(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_3(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_4(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_5(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_6(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUT_7(X)                  (uint32_t(X))
#define U32_MOTDRV_MDC_MSLUTSEL(X)                 (uint32_t(X))
#define U16_MOTDRV_MDC_MSLUTSTART(X)               (uint16_t(X))
/* CHOPCONF */
#define BOOL_MOTDRV_MDC_CHOPCONF_DISS2G(X)         (bool(((X)&0x1)<<30))
#define BOOL_MOTDRV_MDC_CHOPCONF_DEDGE(X)          (bool(((X)&0x1)<<29))
#define BOOL_MOTDRV_MDC_CHOPCONF_INTPOL(X)         (bool(((X)&0x1)<<28))
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_3(X)         (bool(((X)&0x1)<<27))
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_2(X)         (bool(((X)&0x1)<<26))
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_1(X)         (bool(((X)&0x1)<<25))
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_0(X)         (bool(((X)&0x1)<<24))
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_3(X)         (bool(((X)&0x1)<<23))
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_2(X)         (bool(((X)&0x1)<<22))
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_1(X)         (bool(((X)&0x1)<<21))
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_0(X)         (bool(((X)&0x1)<<20))
#define BOOL_MOTDRV_MDC_CHOPCONF_VHIGHCHM(X)       (bool(((X)&0x1)<<19))
#define BOOL_MOTDRV_MDC_CHOPCONF_VHIGHFS(X)        (bool(((X)&0x1)<<18))
#define BOOL_MOTDRV_MDC_CHOPCONF_VSENSE(X)         (bool(((X)&0x1)<<17))
#define BOOL_MOTDRV_MDC_CHOPCONF_TBL_1(X)          (bool(((X)&0x1)<<16))
#define BOOL_MOTDRV_MDC_CHOPCONF_TBL_2(X)          (bool(((X)&0x1)<<15))
#define BOOL_MOTDRV_MDC_CHOPCONF_CHM(X)            (bool(((X)&0x1)<<14))
#define BOOL_MOTDRV_MDC_CHOPCONF_RNDTF(X)          (bool(((X)&0x1)<<13))
#define BOOL_MOTDRV_MDC_CHOPCONF_DISFDCC(X)        (bool(((X)&0x1)<<12))
#define BOOL_MOTDRV_MDC_CHOPCONF_FD3(X)            (bool(((X)&0x1)<<11))
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_3(X)         (bool(((X)&0x1)<<10))
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_2(X)         (bool(((X)&0x1)<<9))
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_1(X)         (bool(((X)&0x1)<<8))
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_0(X)         (bool(((X)&0x1)<<7))
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_2(X)        (bool(((X)&0x1)<<6))
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_1(X)        (bool(((X)&0x1)<<5))
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_0(X)        (bool(((X)&0x1)<<4))
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_3(X)         (bool(((X)&0x1)<<3))
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_2(X)         (bool(((X)&0x1)<<2))
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_1(X)         (bool(((X)&0x1)<<1))
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_0(X)         (bool(((X)&0x1)<<0))
/* COOLCONF */
#define BOOL_MOTDRV_MDC_COOLCONF_SFILT(X)          (bool(((X)&0x1)<<24))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_6(X)          (bool(((X)&0x1)<<22))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_5(X)          (bool(((X)&0x1)<<21))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_4(X)          (bool(((X)&0x1)<<20))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_3(X)          (bool(((X)&0x1)<<19))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_2(X)          (bool(((X)&0x1)<<18))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_1(X)          (bool(((X)&0x1)<<17))
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_0(X)          (bool(((X)&0x1)<<16))
#define BOOL_MOTDRV_MDC_COOLCONF_SEIMIN(X)         (bool(((X)&0x1)<<15))
#define BOOL_MOTDRV_MDC_COOLCONF_SEDN_1(X)         (bool(((X)&0x1)<<14))
#define BOOL_MOTDRV_MDC_COOLCONF_SEDN_0(X)         (bool(((X)&0x1)<<13))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_3(X)        (bool(((X)&0x1)<<11))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_2(X)        (bool(((X)&0x1)<<10))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_1(X)        (bool(((X)&0x1)<<9))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_0(X)        (bool(((X)&0x1)<<8))
#define BOOL_MOTDRV_MDC_COOLCONF_SEUP_1(X)         (bool(((X)&0x1)<<6))
#define BOOL_MOTDRV_MDC_COOLCONF_SEUP_0(X)         (bool(((X)&0x1)<<5))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_3(X)        (bool(((X)&0x1)<<3))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_2(X)        (bool(((X)&0x1)<<2))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_1(X)        (bool(((X)&0x1)<<1))
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_0(X)        (bool(((X)&0x1)<<0))
/* PWMCONF */
#define BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_1(X)     (uint32_t(((X)&0x1)<<21))
#define BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_0(X)     (uint32_t(((X)&0x1)<<20))
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_SYMMETRIC(X)   (uint32_t(((X)&0x1)<<19))
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_AUTOSCALE(X)   (uint32_t(((X)&0x1)<<18))
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_1(X)      (uint32_t(((X)&0x1)<<17))
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_0(X)      (uint32_t(((uint8_t(X))&0x1)<<16))
#define U8_MOTDRV_MDC_PWMCONF_PWM_GRAD(X)          (uint8_t(X)<<8)
#define U8_MOTDRV_MDC_PWMCONF_PWM_AMPL(X)          (uint8_t(X)<<0)


/**********************************************************/
/*                    DEFAULT VALUES                      */
/**********************************************************/
/* General Configuration */
#define BOOL_MOTDRV_GC_I_SCALE_ANALOG_DEF          (false)  // Normal operation, use internal reference voltage
#define BOOL_MOTDRV_GC_INTERNAL_RSENSE_DEF         (false)  // Normal operation.
#define BOOL_MOTDRV_GC_EN_PWM_MODE_DEF             (false)  // 
#define BOOL_MOTDRV_GC_ENC_COMMUNICATION_DEF       (false)  // 
#define BOOL_MOTDRV_GC_SHAFT_DEF                   (false)  // 
#define BOOL_MOTDRV_GC_DIAG0_ERROR_DEF             (false)  // 
#define BOOL_MOTDRV_GC_DIAG0_OTPW_DEF              (false)  // 
#define BOOL_MOTDRV_GC_DIAG0_STALLSTEP_DEF         (false)  // 
#define BOOL_MOTDRV_GC_DIAG1_STALLDIR_DEF          (false)  // 
#define BOOL_MOTDRV_GC_DIAG1_INDEX_DEF             (false)  // 
#define BOOL_MOTDRV_GC_DIAG1_ONSTATE_DEF           (false)  // 
#define BOOL_MOTDRV_GC_DIAG1_STEPS_SKIPPED_DEF     (false)  // 
#define BOOL_MOTDRV_GC_DIAG0_INT_PUSHPULL_DEF      (false)  // SWN_DIAG0 is open collector output (active low)
#define BOOL_MOTDRV_GC_DIAG1_POSCOMP_PUSHPULL_DEF  (false)  // SWP_DIAG1 is open collector output (active low)
#define BOOL_MOTDRV_GC_SMALL_HYSTERESIS_DEF        (false)  // Hysteresis for step frequency comparison is 1/16
#define BOOL_MOTDRV_GC_STOP_ENABLE_DEF             (false)  // Normal operation.
#define BOOL_MOTDRV_GC_DIRECT_MODE_DEF             (false)  // Normal operation.
#define BOOL_MOTDRV_GC_TEST_MODE_DEF               (false)  // Normal operation.

/* Velocity Configuration */
#define U8_MOTDRV_VC_IHOLD_DEF                     ((0x0)) //
#define U8_MOTDRV_VC_IRUN_DEF                      ((0xF)) // 16/32
#define U8_MOTDRV_VC_IHOLDDELAY_DEF                ((0x0)) //

#define U32_MOTDRV_VC_TPOWERDOWN_DEF               (0x0) //
#define U32_MOTDRV_VC_TPWMTHRS_DEF                 (0x0) //
#define U32_MOTDRV_VC_TCOOLTHRS_DEF                (uint32_t(83886)) //((0xB)&0x3FF) //
#define U32_MOTDRV_VC_THIGH_DEF                    ((0x2000)&0x3FF) //

/* Ramp Generator Configuration */
/*
 * RAMPMODE
 * 0: Positioning mode (using all A, D and V parameters)
 * 1: Velocity mode to positive VMAX (using AMAX acceleration)
 * 2: Velocity mode to negative VMAX (using AMAX acceleration)
 * 3: Hold mode (velocity remains unchanged, unless stop event occurs)
 */
#define U8_MOTDRV_RGC_RAMPMODE_DEF                 ((0x0)&0x03)
#define U32_MOTDRV_RGC_XACTUAL_DEF                 (0x0)
#define U32_MOTDRV_RGC_VACTUAL_DEF                 ((0x0)&0x00FFFFFF)
#define U32_MOTDRV_RGC_VSTART_DEF                  ((0x0)&0x0003FFFF)
#define U16_MOTDRV_RGC_A1_DEF                      ((0x0)&0x0000FFFF)
#define U32_MOTDRV_RGC_V1_DEF                      ((0x0)&0x3FF)
#define U16_MOTDRV_RGC_AMAX_DEF                    (uint16_t(2880)) // (0x0B40)
#define U32_MOTDRV_RGC_VMAX_DEF                    ((uint32_t(800))&0x007FFFFF) // (0x320)
#define U16_MOTDRV_RGC_DMAX_DEF                    (uint16_t(2880)) // (0x0B40)
#define U16_MOTDRV_RGC_D1_DEF                      (uint16_t(1)) // (0x1))
#define U32_MOTDRV_RGC_VSTOP_DEF                   ((uint32_t(13))&0x0003FFFF) // (0xD)
#define U16_MOTDRV_RGC_TZEROWAIT_DEF               (0x0)
#define U32_MOTDRV_RGC_XTARGET_DEF                 (0x0)
#define U32_MOTDRV_RGC_VDCMIN_DEF                  ((0x0)&0x007FFFFF)
/* SW_MODE_DEF */
#define BOOL_MOTDRV_RGC_SW_MODE_EN_SOFTSTOP_DEF      (false)
#define BOOL_MOTDRV_RGC_SW_MODE_SG_STOP_DEF          (false)
#define BOOL_MOTDRV_RGC_SW_MODE_EN_LATCHENCODER_DEF  (false)
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_INACTIVE_DEF (false)
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_ACTIVE_DEF   (false)
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_INACTIVE_DEF (false)
#define BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_ACTIVE_DEF   (false)
#define BOOL_MOTDRV_RGC_SW_MODE_SWAP_LR_DEF          (false)
#define BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_R_DEF       (false)
#define BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_L_DEF       (false)
#define BOOL_MOTDRV_RGC_SW_MODE_STOP_R_ENABLE_DEF    (false)
#define BOOL_MOTDRV_RGC_SW_MODE_STOP_L_ENABLE_DEF    (false)

/* Encoder Configuration */
/* ENCMODE */ 
#define BOOL_MOTDRV_EC_ENCMODE_ENC_SEL_DECIMAL_DEF  (false)
#define BOOL_MOTDRV_EC_ENCMODE_LATCH_X_ACT_DEF      (false)
#define BOOL_MOTDRV_EC_ENCMODE_CLR_ENC_X_DEF        (false)
#define BOOL_MOTDRV_EC_ENCMODE_NEG_EDGE_DEF         (false)
#define BOOL_MOTDRV_EC_ENCMODE_POS_EDGE_DEF         (false)
#define BOOL_MOTDRV_EC_ENCMODE_CLR_ONCE_DEF         (false)
#define BOOL_MOTDRV_EC_ENCMODE_CLR_CONT_DEF         (false)
#define BOOL_MOTDRV_EC_ENCMODE_IGNORE_AB_DEF        (false)
#define BOOL_MOTDRV_EC_ENCMODE_POL_N_DEF            (false)
#define BOOL_MOTDRV_EC_ENCMODE_POL_B_DEF            (false)
#define BOOL_MOTDRV_EC_ENCMODE_POL_A_DEF            (false)

#define U32_MOTDRV_EC_X_ENC_DEF                     (0x0)
#define U32_MOTDRV_EC_ENC_CONST_DEF                 (0x0)

/* Motor Driver Configuration */
/* Microstepping Control */
#define U32_MOTDRV_MDC_MSLUT_0_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_1_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_2_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_3_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_4_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_5_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_6_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUT_7_DEF                  (0x0)
#define U32_MOTDRV_MDC_MSLUTSEL_DEF                 (0x0)
#define U16_MOTDRV_MDC_MSLUTSTART_DEF               (247<<16)
/* CHOPCONF */
#define BOOL_MOTDRV_MDC_CHOPCONF_DISS2G_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_DEDGE_DEF          (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_INTPOL_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_3_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_2_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_1_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_MRES_0_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_3_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_2_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_1_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_SYNC_0_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_VHIGHCHM_DEF       (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_VHIGHFS_DEF        (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_VSENSE_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TBL_1_DEF          (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TBL_2_DEF          (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_CHM_DEF            (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_RNDTF_DEF          (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_DISFDCC_DEF        (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_FD3_DEF            (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_3_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_2_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_1_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HEND_0_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_2_DEF        (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_1_DEF        (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_0_DEF        (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_3_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_2_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_1_DEF         (false)
#define BOOL_MOTDRV_MDC_CHOPCONF_TOFF_0_DEF         (false)
/* COOLCONF */
#define BOOL_MOTDRV_MDC_COOLCONF_SFILT_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_6_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_5_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_4_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_3_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_2_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_1_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SGT_0_DEF          (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEIMIN_DEF         (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEDN_1_DEF         (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEDN_0_DEF         (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_3_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_2_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_1_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMAX_0_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEUP_1_DEF         (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEUP_0_DEF         (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_3_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_2_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_1_DEF        (false)
#define BOOL_MOTDRV_MDC_COOLCONF_SEMIN_0_DEF        (false)
/* PWMCONF */
#define BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_1_DEF     (false)
#define BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_0_DEF     (false)
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_SYMMETRIC_DEF   (false)
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_AUTOSCALE_DEF   (true)
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_1_DEF      (false)
#define BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_0_DEF      (0x1)
#define U8_MOTDRV_MDC_PWMCONF_PWM_GRAD_DEF          (4)
#define U8_MOTDRV_MDC_PWMCONF_PWM_AMPL_DEF          (128)



/**********************************************************/

/**********************************************************/
/*                    TYPE DEFINITONS                     */
/**********************************************************/

/**********************************************************/

#endif /* motdrv_defs_hpp */
/* END OF FILE */
