/**********************************************************
 * - File: motdrv.cpp
 * - Author: Rubén Padial Allué
 * - Contact: padialruben@gmail.com
 * - Date: 
 * - Revision: 
 **********************************************************/

/**********************************************************/
/*                        INCLUDES                        */
/**********************************************************/
#include "motdrv.hpp"
#include <com.hpp>

/**********************************************************/

/**********************************************************/
/*                    GLOBAL VARIABLES                    */
/**********************************************************/

/**********************************************************/

/**********************************************************/
/*                     LOCAL FUNCTIONS                    */
/**********************************************************/
void motdrv_generalConf(uint8_t CS)
{
  uint32_t u32_gconfig = 0;
  u32_gconfig = (BOOL_MOTDRV_GC_I_SCALE_ANALOG(BOOL_MOTDRV_GC_I_SCALE_ANALOG_DEF) \ 
                  | BOOL_MOTDRV_GC_INTERNAL_RSENSE(BOOL_MOTDRV_GC_INTERNAL_RSENSE_DEF) \ 
                  | BOOL_MOTDRV_GC_EN_PWM_MODE(BOOL_MOTDRV_GC_EN_PWM_MODE_DEF) \ 
                  | BOOL_MOTDRV_GC_ENC_COMMUNICATION(BOOL_MOTDRV_GC_ENC_COMMUNICATION_DEF) \
                  | BOOL_MOTDRV_GC_SHAFT(BOOL_MOTDRV_GC_SHAFT_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG0_ERROR(BOOL_MOTDRV_GC_DIAG0_ERROR_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG0_OTPW(BOOL_MOTDRV_GC_DIAG0_OTPW_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG0_STALLSTEP(BOOL_MOTDRV_GC_DIAG0_STALLSTEP_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG1_STALLDIR(BOOL_MOTDRV_GC_DIAG1_STALLDIR_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG1_INDEX(BOOL_MOTDRV_GC_DIAG1_INDEX_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG1_ONSTATE(BOOL_MOTDRV_GC_DIAG1_ONSTATE_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG1_STEPS_SKIPPED(BOOL_MOTDRV_GC_DIAG1_STEPS_SKIPPED_DEF) \ 
                  | BOOL_MOTDRV_GC_DIAG0_INT_PUSHPULL(BOOL_MOTDRV_GC_DIAG0_INT_PUSHPULL_DEF) \
                  | BOOL_MOTDRV_GC_DIAG1_POSCOMP_PUSHPULL(BOOL_MOTDRV_GC_DIAG1_POSCOMP_PUSHPULL_DEF) \ 
                  | BOOL_MOTDRV_GC_SMALL_HYSTERESIS(BOOL_MOTDRV_GC_SMALL_HYSTERESIS_DEF) \ 
                  | BOOL_MOTDRV_GC_STOP_ENABLE(BOOL_MOTDRV_GC_STOP_ENABLE_DEF) \ 
                  | BOOL_MOTDRV_GC_DIRECT_MODE(BOOL_MOTDRV_GC_DIRECT_MODE_DEF) \ 
                  | BOOL_MOTDRV_GC_TEST_MODE(BOOL_MOTDRV_GC_TEST_MODE_DEF)
                );

  com_write(GCONF, u32_gconfig, CS);
}

void motdrv_velocityConf(uint8_t CS)
{
  uint16_t u16_ihold_irun = 0;
  u16_ihold_irun = (U8_MOTDRV_VC_IHOLD(U8_MOTDRV_VC_IHOLD_DEF) \
                     | U8_MOTDRV_VC_IRUN(U8_MOTDRV_VC_IRUN_DEF) \
                     | U8_MOTDRV_VC_IHOLDDELAY(U8_MOTDRV_VC_IHOLDDELAY_DEF) 
                    );
   com_write(IHOLD_IRUN, u16_ihold_irun, CS);
   com_write(TPOWERDOWN, U32_MOTDRV_VC_TPOWERDOWN(U32_MOTDRV_VC_TPOWERDOWN_DEF), CS);
   com_write(TPWMTHRS, U32_MOTDRV_VC_TPWMTHRS(U32_MOTDRV_VC_TPWMTHRS_DEF), CS);
   com_write(TCOOLTHRS, U32_MOTDRV_VC_TCOOLTHRS(U32_MOTDRV_VC_TCOOLTHRS_DEF), CS);
   com_write(THIGH, U32_MOTDRV_VC_THIGH(U32_MOTDRV_VC_THIGH_DEF), CS);
}

void motdrv_rampGenConf(uint8_t CS)
{
  uint16_t u16_sw_mode = 0;
  u16_sw_mode = (BOOL_MOTDRV_RGC_SW_MODE_EN_SOFTSTOP(BOOL_MOTDRV_RGC_SW_MODE_EN_SOFTSTOP_DEF) \
                 | BOOL_MOTDRV_RGC_SW_MODE_SG_STOP(BOOL_MOTDRV_RGC_SW_MODE_SG_STOP_DEF) \         
                 | BOOL_MOTDRV_RGC_SW_MODE_EN_LATCHENCODER(BOOL_MOTDRV_RGC_SW_MODE_EN_LATCHENCODER_DEF) \ 
                 | BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_INACTIVE(BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_INACTIVE_DEF) \
                 | BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_ACTIVE(BOOL_MOTDRV_RGC_SW_MODE_LATCH_R_ACTIVE_DEF) \  
                 | BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_INACTIVE(BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_INACTIVE_DEF) \
                 | BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_ACTIVE(BOOL_MOTDRV_RGC_SW_MODE_LATCH_L_ACTIVE_DEF) \  
                 | BOOL_MOTDRV_RGC_SW_MODE_SWAP_LR(BOOL_MOTDRV_RGC_SW_MODE_SWAP_LR_DEF) \         
                 | BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_R(BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_R_DEF) \      
                 | BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_L(BOOL_MOTDRV_RGC_SW_MODE_POL_STOP_L_DEF) \      
                 | BOOL_MOTDRV_RGC_SW_MODE_STOP_R_ENABLE(BOOL_MOTDRV_RGC_SW_MODE_STOP_R_ENABLE_DEF) \   
                 | BOOL_MOTDRV_RGC_SW_MODE_STOP_L_ENABLE(BOOL_MOTDRV_RGC_SW_MODE_STOP_L_ENABLE_DEF)    
                    );
   com_write(RAMPMODE, U8_MOTDRV_RGC_RAMPMODE(U8_MOTDRV_RGC_RAMPMODE_DEF), CS);
   com_write(XACTUAL, U32_MOTDRV_RGC_XACTUAL(U32_MOTDRV_RGC_XACTUAL_DEF), CS);
   com_write(VACTUAL, U32_MOTDRV_RGC_VACTUAL(U32_MOTDRV_RGC_VACTUAL_DEF), CS);
   com_write(VSTART, U32_MOTDRV_RGC_VSTART(U32_MOTDRV_RGC_VSTART_DEF), CS);
   com_write(A_1, U16_MOTDRV_RGC_A1(U16_MOTDRV_RGC_A1_DEF), CS);
   com_write(V_1, U32_MOTDRV_RGC_V1(U32_MOTDRV_RGC_V1_DEF), CS);
   com_write(AMAX, U16_MOTDRV_RGC_AMAX(U16_MOTDRV_RGC_AMAX_DEF), CS);
   com_write(VMAX, U32_MOTDRV_RGC_VMAX(U32_MOTDRV_RGC_VMAX_DEF), CS);
   com_write(DMAX, U16_MOTDRV_RGC_DMAX(U16_MOTDRV_RGC_DMAX_DEF), CS);
   com_write(D_1, U16_MOTDRV_RGC_D1(U16_MOTDRV_RGC_D1_DEF), CS);
   com_write(VSTOP, U32_MOTDRV_RGC_VSTOP(U32_MOTDRV_RGC_VSTOP_DEF), CS);
   com_write(TZEROWAIT, U16_MOTDRV_RGC_TZEROWAIT(U16_MOTDRV_RGC_TZEROWAIT_DEF), CS);
   com_write(XTARGET, U32_MOTDRV_RGC_XTARGET(U32_MOTDRV_RGC_XTARGET_DEF), CS);
   com_write(VDCMIN, U32_MOTDRV_RGC_VDCMIN(U32_MOTDRV_RGC_VDCMIN_DEF), CS);
   com_write(SW_MODE, u16_sw_mode, CS);
}

void motdrv_encConf(uint8_t CS)
{
  uint16_t u16_encmode = 0;
  u16_encmode = (BOOL_MOTDRV_EC_ENCMODE_ENC_SEL_DECIMAL(BOOL_MOTDRV_EC_ENCMODE_ENC_SEL_DECIMAL_DEF) \
                 | BOOL_MOTDRV_EC_ENCMODE_LATCH_X_ACT(BOOL_MOTDRV_EC_ENCMODE_LATCH_X_ACT_DEF) \ 
                 | BOOL_MOTDRV_EC_ENCMODE_CLR_ENC_X(BOOL_MOTDRV_EC_ENCMODE_CLR_ENC_X_DEF) \
                 | BOOL_MOTDRV_EC_ENCMODE_NEG_EDGE(BOOL_MOTDRV_EC_ENCMODE_NEG_EDGE_DEF) \  
                 | BOOL_MOTDRV_EC_ENCMODE_POS_EDGE(BOOL_MOTDRV_EC_ENCMODE_POS_EDGE_DEF) \
                 | BOOL_MOTDRV_EC_ENCMODE_CLR_ONCE(BOOL_MOTDRV_EC_ENCMODE_CLR_ONCE_DEF) \  
                 | BOOL_MOTDRV_EC_ENCMODE_CLR_CONT(BOOL_MOTDRV_EC_ENCMODE_CLR_CONT_DEF) \
                 | BOOL_MOTDRV_EC_ENCMODE_IGNORE_AB(BOOL_MOTDRV_EC_ENCMODE_IGNORE_AB_DEF) \  
                 | BOOL_MOTDRV_EC_ENCMODE_POL_N(BOOL_MOTDRV_EC_ENCMODE_POL_N_DEF) \  
                 | BOOL_MOTDRV_EC_ENCMODE_POL_B(BOOL_MOTDRV_EC_ENCMODE_POL_B_DEF) \   
                 | BOOL_MOTDRV_EC_ENCMODE_POL_A(BOOL_MOTDRV_EC_ENCMODE_POL_A_DEF)   
                );
   com_write(X_ENC, U32_MOTDRV_EC_X_ENC(U32_MOTDRV_EC_X_ENC_DEF), CS);
   com_write(ENC_CONST, U32_MOTDRV_EC_ENC_CONST(U32_MOTDRV_EC_ENC_CONST_DEF), CS);
   com_write(ENCMODE, u16_encmode, CS);
}

/**********************************************************/

/**********************************************************/
/*                    GLOBAL FUNCTIONS                    */
/**********************************************************/
void motdrv_init()
{
  /* General Config */
  motdrv_generalConf(SPI_CS);
  /* Velocity Config */
  motdrv_velocityConf(SPI_CS);
  /* RAMP Generator Config */
  motdrv_rampGenConf(SPI_CS);
  /* Encoder Config */
  motdrv_encConf(SPI_CS);
  /* Microstepping Control Config */
  /* CHOPCONF */
  /* COOLCONF */
  /* DRV_STATUS (R) */
  /* PWMCONF */
  /* WRITE_ACCESS */

  DEBUG_PRINTLN("motdrv initialized.");

  
}

void motdrv_task(void)
{ 

}
/**********************************************************/

/* END OF FILE */
