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

void motdrv_microstepConf(uint8_t CS)
{
   com_write(MSLUT0, U32_MOTDRV_MDC_MSLUT_0(U32_MOTDRV_MDC_MSLUT_0_DEF), CS);
   com_write(MSLUT1, U32_MOTDRV_MDC_MSLUT_1(U32_MOTDRV_MDC_MSLUT_1_DEF), CS);
   com_write(MSLUT2, U32_MOTDRV_MDC_MSLUT_2(U32_MOTDRV_MDC_MSLUT_2_DEF), CS);
   com_write(MSLUT3, U32_MOTDRV_MDC_MSLUT_3(U32_MOTDRV_MDC_MSLUT_3_DEF), CS);
   com_write(MSLUT4, U32_MOTDRV_MDC_MSLUT_4(U32_MOTDRV_MDC_MSLUT_4_DEF), CS);
   com_write(MSLUT5, U32_MOTDRV_MDC_MSLUT_5(U32_MOTDRV_MDC_MSLUT_5_DEF), CS);
   com_write(MSLUT6, U32_MOTDRV_MDC_MSLUT_6(U32_MOTDRV_MDC_MSLUT_6_DEF), CS);
   com_write(MSLUT7, U32_MOTDRV_MDC_MSLUT_7(U32_MOTDRV_MDC_MSLUT_7_DEF), CS);
   com_write(MSLUTSEL, U32_MOTDRV_MDC_MSLUTSEL(U32_MOTDRV_MDC_MSLUTSEL_DEF), CS);
   com_write(MSLUTSTART,U16_MOTDRV_MDC_MSLUTSTART(U16_MOTDRV_MDC_MSLUTSTART_DEF), CS);
}

void motdrv_chopconfConf(uint8_t CS)
{
  uint32_t u32_chopconf = 0;

  u32_chopconf = (BOOL_MOTDRV_MDC_CHOPCONF_DISS2G(BOOL_MOTDRV_MDC_CHOPCONF_DISS2G_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_DEDGE(BOOL_MOTDRV_MDC_CHOPCONF_DEDGE_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_INTPOL(BOOL_MOTDRV_MDC_CHOPCONF_INTPOL_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_MRES_3(BOOL_MOTDRV_MDC_CHOPCONF_MRES_3_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_MRES_2(BOOL_MOTDRV_MDC_CHOPCONF_MRES_2_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_MRES_1(BOOL_MOTDRV_MDC_CHOPCONF_MRES_1_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_MRES_0(BOOL_MOTDRV_MDC_CHOPCONF_MRES_0_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_SYNC_3(BOOL_MOTDRV_MDC_CHOPCONF_SYNC_3_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_SYNC_2(BOOL_MOTDRV_MDC_CHOPCONF_SYNC_2_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_SYNC_1(BOOL_MOTDRV_MDC_CHOPCONF_SYNC_1_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_SYNC_0(BOOL_MOTDRV_MDC_CHOPCONF_SYNC_0_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_VHIGHCHM(BOOL_MOTDRV_MDC_CHOPCONF_VHIGHCHM_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_VHIGHFS(BOOL_MOTDRV_MDC_CHOPCONF_VHIGHFS_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_VSENSE(BOOL_MOTDRV_MDC_CHOPCONF_VSENSE_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TBL_1(BOOL_MOTDRV_MDC_CHOPCONF_TBL_1_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TBL_2(BOOL_MOTDRV_MDC_CHOPCONF_TBL_2_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_CHM(BOOL_MOTDRV_MDC_CHOPCONF_CHM_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_RNDTF(BOOL_MOTDRV_MDC_CHOPCONF_RNDTF_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_DISFDCC(BOOL_MOTDRV_MDC_CHOPCONF_DISFDCC_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_FD3(BOOL_MOTDRV_MDC_CHOPCONF_FD3_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HEND_3(BOOL_MOTDRV_MDC_CHOPCONF_HEND_3_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HEND_2(BOOL_MOTDRV_MDC_CHOPCONF_HEND_2_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HEND_1(BOOL_MOTDRV_MDC_CHOPCONF_HEND_1_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HEND_0(BOOL_MOTDRV_MDC_CHOPCONF_HEND_0_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_2(BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_2_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_1(BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_1_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_0(BOOL_MOTDRV_MDC_CHOPCONF_HSTRT_0_DEF) \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TOFF_3(BOOL_MOTDRV_MDC_CHOPCONF_TOFF_3_DEF)  \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TOFF_2(BOOL_MOTDRV_MDC_CHOPCONF_TOFF_2_DEF)  \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TOFF_1(BOOL_MOTDRV_MDC_CHOPCONF_TOFF_1_DEF)  \
                  | BOOL_MOTDRV_MDC_CHOPCONF_TOFF_0(BOOL_MOTDRV_MDC_CHOPCONF_TOFF_0_DEF)
                 );

   com_write(CHOPCONF, u32_chopconf, CS);
}

void motdrv_coolconfConf(uint8_t CS)
{
  uint32_t u32_coolconf = 0;
 
  u32_coolconf = (BOOL_MOTDRV_MDC_COOLCONF_SFILT(BOOL_MOTDRV_MDC_COOLCONF_SFILT_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_6(BOOL_MOTDRV_MDC_COOLCONF_SGT_6_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_5(BOOL_MOTDRV_MDC_COOLCONF_SGT_5_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_4(BOOL_MOTDRV_MDC_COOLCONF_SGT_4_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_3(BOOL_MOTDRV_MDC_COOLCONF_SGT_3_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_2(BOOL_MOTDRV_MDC_COOLCONF_SGT_2_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_1(BOOL_MOTDRV_MDC_COOLCONF_SGT_1_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SGT_0(BOOL_MOTDRV_MDC_COOLCONF_SGT_0_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEIMIN(BOOL_MOTDRV_MDC_COOLCONF_SEIMIN_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEDN_1(BOOL_MOTDRV_MDC_COOLCONF_SEDN_1_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEDN_0(BOOL_MOTDRV_MDC_COOLCONF_SEDN_0_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMAX_3(BOOL_MOTDRV_MDC_COOLCONF_SEMAX_3_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMAX_2(BOOL_MOTDRV_MDC_COOLCONF_SEMAX_2_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMAX_1(BOOL_MOTDRV_MDC_COOLCONF_SEMAX_1_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMAX_0(BOOL_MOTDRV_MDC_COOLCONF_SEMAX_0_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEUP_1(BOOL_MOTDRV_MDC_COOLCONF_SEUP_1_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEUP_0(BOOL_MOTDRV_MDC_COOLCONF_SEUP_0_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMIN_3(BOOL_MOTDRV_MDC_COOLCONF_SEMIN_3_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMIN_2(BOOL_MOTDRV_MDC_COOLCONF_SEMIN_2_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMIN_1(BOOL_MOTDRV_MDC_COOLCONF_SEMIN_1_DEF) \
                  | BOOL_MOTDRV_MDC_COOLCONF_SEMIN_0(BOOL_MOTDRV_MDC_COOLCONF_SEMIN_0_DEF)
                 );

   com_write(COOLCONF, u32_coolconf, CS);
}

void motdrv_pwmconfConf(uint8_t CS)
{
  uint32_t u32_pwmconf = 0;
 
  u32_pwmconf = (BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_1(BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_1_DEF) \
                  | BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_0(BOOL_MOTDRV_MDC_PWMCONF_FREEWHEEL_0_DEF) \
                  | BOOL_MOTDRV_MDC_PWMCONF_PWM_SYMMETRIC(BOOL_MOTDRV_MDC_PWMCONF_PWM_SYMMETRIC_DEF) \
                  | BOOL_MOTDRV_MDC_PWMCONF_PWM_AUTOSCALE(BOOL_MOTDRV_MDC_PWMCONF_PWM_AUTOSCALE_DEF) \
                  | BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_1(BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_1_DEF) \
                  | BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_0(BOOL_MOTDRV_MDC_PWMCONF_PWM_FREQ_0_DEF) \
                  | U8_MOTDRV_MDC_PWMCONF_PWM_GRAD(U8_MOTDRV_MDC_PWMCONF_PWM_GRAD_DEF) \
                  | U8_MOTDRV_MDC_PWMCONF_PWM_AMPL(U8_MOTDRV_MDC_PWMCONF_PWM_AMPL_DEF) \
                 );

   com_write(PWMCONF, u32_pwmconf, CS);
}


void motdrv_motDrvConf(uint8_t CS)
{
  motdrv_microstepConf(CS);
  motdrv_chopconfConf(CS);
  motdrv_coolconfConf(CS);
  motdrv_pwmconfConf(CS);
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
  /* Motor Driver Config */
  motdrv_motDrvConf(SPI_CS);
  /* WRITE_ACCESS */

  DEBUG_PRINTLN("motdrv initialized.");

  
}

void motdrv_task(void)
{ 

}
/**********************************************************/

/* END OF FILE */
