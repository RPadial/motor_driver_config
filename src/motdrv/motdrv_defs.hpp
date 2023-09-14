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


/**********************************************************/

/**********************************************************/
/*                    TYPE DEFINITONS                     */
/**********************************************************/

/**********************************************************/

#endif /* motdrv_defs_hpp */
/* END OF FILE */
