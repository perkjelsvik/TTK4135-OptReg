/*
 * Task_10_2.c
 *
 * Code generation for model "Task_10_2".
 *
 * Model version              : 1.170
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Feb 22 12:16:58 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Task_10_2.h"
#include "Task_10_2_private.h"
#include "Task_10_2_dt.h"

/* Block signals (auto storage) */
B_Task_10_2_T Task_10_2_B;

/* Continuous states */
X_Task_10_2_T Task_10_2_X;

/* Block states (auto storage) */
DW_Task_10_2_T Task_10_2_DW;

/* Real-time model */
RT_MODEL_Task_10_2_T Task_10_2_M_;
RT_MODEL_Task_10_2_T *const Task_10_2_M = &Task_10_2_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Task_10_2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Task_10_2_output(void)
{
  /* local block i/o variables */
  real_T rtb_Backgain;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T *lastU;
  real_T rtb_Gain1_idx_4;
  real_T rtb_Gain1_idx_5;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    /* set solver stop time */
    if (!(Task_10_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Task_10_2_M->solverInfo,
                            ((Task_10_2_M->Timing.clockTickH0 + 1) *
        Task_10_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Task_10_2_M->solverInfo,
                            ((Task_10_2_M->Timing.clockTick0 + 1) *
        Task_10_2_M->Timing.stepSize0 + Task_10_2_M->Timing.clockTickH0 *
        Task_10_2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Task_10_2_M)) {
    Task_10_2_M->Timing.t[0] = rtsiGetT(&Task_10_2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: Task_10_2/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Task_10_2_DW.HILReadEncoderTimebase_Task, 1,
        &Task_10_2_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          Task_10_2_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          Task_10_2_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          Task_10_2_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S4>/Travel: Count to rad' */
    Task_10_2_B.TravelCounttorad = Task_10_2_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S11>/Gain' */
    Task_10_2_B.Gain = Task_10_2_P.Gain_Gain * Task_10_2_B.TravelCounttorad;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/travel_offset [deg]'
     */
    Task_10_2_B.Sum2 = Task_10_2_B.Gain - Task_10_2_P.travel_offsetdeg_Value;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++Task_10_2_DW.ToFile_IWORK.Decimation % 1) &&
          (Task_10_2_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) Task_10_2_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          Task_10_2_DW.ToFile_IWORK.Decimation = 0;
          u[0] = Task_10_2_M->Timing.t[1];
          u[1] = Task_10_2_B.Sum2;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(Task_10_2_M,
                              "Error writing to MAT-file travel_10_2.mat");
            return;
          }

          if (((++Task_10_2_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file travel_10_2.mat.\n");
          }
        }
      }
    }
  }

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += Task_10_2_P.TravelTransferFcn_C *
    Task_10_2_X.TravelTransferFcn_CSTATE;
  rtb_Backgain += Task_10_2_P.TravelTransferFcn_D * Task_10_2_B.TravelCounttorad;

  /* Gain: '<S12>/Gain' */
  Task_10_2_B.Gain_d = Task_10_2_P.Gain_Gain_l * rtb_Backgain;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    /* Gain: '<S4>/Pitch: Count to rad' */
    Task_10_2_B.PitchCounttorad = Task_10_2_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S8>/Gain' */
    Task_10_2_B.Gain_i = Task_10_2_P.Gain_Gain_a * Task_10_2_B.PitchCounttorad;
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += Task_10_2_P.PitchTransferFcn_C *
    Task_10_2_X.PitchTransferFcn_CSTATE;
  rtb_Backgain += Task_10_2_P.PitchTransferFcn_D * Task_10_2_B.PitchCounttorad;

  /* Gain: '<S9>/Gain' */
  Task_10_2_B.Gain_b = Task_10_2_P.Gain_Gain_ae * rtb_Backgain;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    /* Gain: '<S4>/Elevation: Count to rad' */
    Task_10_2_B.ElevationCounttorad = Task_10_2_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;

    /* Gain: '<S6>/Gain' */
    Task_10_2_B.Gain_e = Task_10_2_P.Gain_Gain_lv *
      Task_10_2_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    Task_10_2_B.Sum = Task_10_2_B.Gain_e + Task_10_2_P.elavation_offsetdeg_Value;
  }

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += Task_10_2_P.ElevationTransferFcn_C *
    Task_10_2_X.ElevationTransferFcn_CSTATE;
  rtb_Backgain += Task_10_2_P.ElevationTransferFcn_D *
    Task_10_2_B.ElevationCounttorad;

  /* Gain: '<S7>/Gain' */
  Task_10_2_B.Gain_dg = Task_10_2_P.Gain_Gain_n * rtb_Backgain;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1_idx_4 = Task_10_2_P.Gain1_Gain * Task_10_2_B.Sum;
  rtb_Gain1_idx_5 = Task_10_2_P.Gain1_Gain * Task_10_2_B.Gain_dg;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) Task_10_2_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Task_10_2_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = Task_10_2_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = Task_10_2_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Task_10_2_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Backgain = pDataValues[currTimeIndex];
        } else {
          rtb_Backgain = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Backgain = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<Root>/pitch_ref'
   *  Constant: '<S5>/Vd_bias'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S5>/K_pd'
   *  Gain: '<S5>/K_pp'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum3'
   */
  Task_10_2_B.Sum_k = ((Task_10_2_P.pitch_ref_Value - Task_10_2_P.Gain1_Gain *
                        Task_10_2_B.Gain_i) * Task_10_2_P.K_pp -
                       (Task_10_2_P.Gain1_Gain * Task_10_2_B.Gain_b +
                        rtb_Backgain) * Task_10_2_P.K_pd) + Task_10_2_P.Vd_ff;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
  }

  /* Integrator: '<S3>/Integrator'
   *
   * Regarding '<S3>/Integrator':
   *  Limited Integrator
   */
  if (Task_10_2_X.Integrator_CSTATE >= Task_10_2_P.Integrator_UpperSat ) {
    Task_10_2_X.Integrator_CSTATE = Task_10_2_P.Integrator_UpperSat;
  } else if (Task_10_2_X.Integrator_CSTATE <= (Task_10_2_P.Integrator_LowerSat) )
  {
    Task_10_2_X.Integrator_CSTATE = (Task_10_2_P.Integrator_LowerSat);
  }

  rtb_Backgain = Task_10_2_X.Integrator_CSTATE;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<Root>/elevation_ref'
   */
  rtb_Gain1_idx_4 = Task_10_2_P.elevation_ref_Value - rtb_Gain1_idx_4;

  /* Sum: '<S3>/Sum2' incorporates:
   *  Constant: '<S3>/Vs_bias'
   *  Gain: '<S3>/K_ed'
   *  Gain: '<S3>/K_ep'
   *  Sum: '<S3>/Sum1'
   */
  Task_10_2_B.Sum2_c = ((Task_10_2_P.K_ep * rtb_Gain1_idx_4 + rtb_Backgain) -
                        Task_10_2_P.K_ed * rtb_Gain1_idx_5) + Task_10_2_P.Vs_ff;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Backgain = (Task_10_2_B.Sum2_c - Task_10_2_B.Sum_k) *
    Task_10_2_P.Backgain_Gain;

  /* Gain: '<S3>/K_ei' */
  Task_10_2_B.K_ei = Task_10_2_P.K_ei * rtb_Gain1_idx_4;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
  }

  /* Derivative: '<S4>/Derivative' */
  if ((Task_10_2_DW.TimeStampA >= Task_10_2_M->Timing.t[0]) &&
      (Task_10_2_DW.TimeStampB >= Task_10_2_M->Timing.t[0])) {
    rtb_Gain1_idx_4 = 0.0;
  } else {
    rtb_Gain1_idx_4 = Task_10_2_DW.TimeStampA;
    lastU = &Task_10_2_DW.LastUAtTimeA;
    if (Task_10_2_DW.TimeStampA < Task_10_2_DW.TimeStampB) {
      if (Task_10_2_DW.TimeStampB < Task_10_2_M->Timing.t[0]) {
        rtb_Gain1_idx_4 = Task_10_2_DW.TimeStampB;
        lastU = &Task_10_2_DW.LastUAtTimeB;
      }
    } else {
      if (Task_10_2_DW.TimeStampA >= Task_10_2_M->Timing.t[0]) {
        rtb_Gain1_idx_4 = Task_10_2_DW.TimeStampB;
        lastU = &Task_10_2_DW.LastUAtTimeB;
      }
    }

    rtb_Gain1_idx_4 = (Task_10_2_B.PitchCounttorad - *lastU) /
      (Task_10_2_M->Timing.t[0] - rtb_Gain1_idx_4);
  }

  /* End of Derivative: '<S4>/Derivative' */

  /* Gain: '<S10>/Gain' */
  Task_10_2_B.Gain_l = Task_10_2_P.Gain_Gain_a1 * rtb_Gain1_idx_4;
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
  }

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (rtb_Backgain > Task_10_2_P.BackmotorSaturation_UpperSat) {
    Task_10_2_B.BackmotorSaturation = Task_10_2_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < Task_10_2_P.BackmotorSaturation_LowerSat) {
    Task_10_2_B.BackmotorSaturation = Task_10_2_P.BackmotorSaturation_LowerSat;
  } else {
    Task_10_2_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Gain1_idx_4 = (Task_10_2_B.Sum_k + Task_10_2_B.Sum2_c) *
    Task_10_2_P.Frontgain_Gain;

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (rtb_Gain1_idx_4 > Task_10_2_P.FrontmotorSaturation_UpperSat) {
    Task_10_2_B.FrontmotorSaturation = Task_10_2_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Gain1_idx_4 < Task_10_2_P.FrontmotorSaturation_LowerSat) {
    Task_10_2_B.FrontmotorSaturation = Task_10_2_P.FrontmotorSaturation_LowerSat;
  } else {
    Task_10_2_B.FrontmotorSaturation = rtb_Gain1_idx_4;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: Task_10_2/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      Task_10_2_DW.HILWriteAnalog_Buffer[0] = Task_10_2_B.FrontmotorSaturation;
      Task_10_2_DW.HILWriteAnalog_Buffer[1] = Task_10_2_B.BackmotorSaturation;
      result = hil_write_analog(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILWriteAnalog_channels, 2,
        &Task_10_2_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void Task_10_2_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S4>/Derivative' */
  if (Task_10_2_DW.TimeStampA == (rtInf)) {
    Task_10_2_DW.TimeStampA = Task_10_2_M->Timing.t[0];
    lastU = &Task_10_2_DW.LastUAtTimeA;
  } else if (Task_10_2_DW.TimeStampB == (rtInf)) {
    Task_10_2_DW.TimeStampB = Task_10_2_M->Timing.t[0];
    lastU = &Task_10_2_DW.LastUAtTimeB;
  } else if (Task_10_2_DW.TimeStampA < Task_10_2_DW.TimeStampB) {
    Task_10_2_DW.TimeStampA = Task_10_2_M->Timing.t[0];
    lastU = &Task_10_2_DW.LastUAtTimeA;
  } else {
    Task_10_2_DW.TimeStampB = Task_10_2_M->Timing.t[0];
    lastU = &Task_10_2_DW.LastUAtTimeB;
  }

  *lastU = Task_10_2_B.PitchCounttorad;

  /* End of Update for Derivative: '<S4>/Derivative' */
  if (rtmIsMajorTimeStep(Task_10_2_M)) {
    rt_ertODEUpdateContinuousStates(&Task_10_2_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Task_10_2_M->Timing.clockTick0)) {
    ++Task_10_2_M->Timing.clockTickH0;
  }

  Task_10_2_M->Timing.t[0] = rtsiGetSolverStopTime(&Task_10_2_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Task_10_2_M->Timing.clockTick1)) {
      ++Task_10_2_M->Timing.clockTickH1;
    }

    Task_10_2_M->Timing.t[1] = Task_10_2_M->Timing.clockTick1 *
      Task_10_2_M->Timing.stepSize1 + Task_10_2_M->Timing.clockTickH1 *
      Task_10_2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Task_10_2_derivatives(void)
{
  XDot_Task_10_2_T *_rtXdot;
  _rtXdot = ((XDot_Task_10_2_T *) Task_10_2_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += Task_10_2_P.TravelTransferFcn_A *
    Task_10_2_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += Task_10_2_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += Task_10_2_P.PitchTransferFcn_A *
    Task_10_2_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += Task_10_2_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += Task_10_2_P.ElevationTransferFcn_A *
    Task_10_2_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += Task_10_2_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( Task_10_2_X.Integrator_CSTATE <= (Task_10_2_P.Integrator_LowerSat) );
    usat = ( Task_10_2_X.Integrator_CSTATE >= Task_10_2_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (Task_10_2_B.K_ei > 0)) ||
        (usat && (Task_10_2_B.K_ei < 0)) ) {
      ((XDot_Task_10_2_T *) Task_10_2_M->ModelData.derivs)->Integrator_CSTATE =
        Task_10_2_B.K_ei;
    } else {
      /* in saturation */
      ((XDot_Task_10_2_T *) Task_10_2_M->ModelData.derivs)->Integrator_CSTATE =
        0.0;
    }
  }
}

/* Model initialize function */
void Task_10_2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Task_10_2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Task_10_2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Task_10_2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Task_10_2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
      return;
    }

    if ((Task_10_2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Task_10_2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Task_10_2_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Task_10_2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Task_10_2_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_analog_input_chan, 8U,
        &Task_10_2_DW.HILInitialize_AIMinimums[0],
        &Task_10_2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_analog_output && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Task_10_2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Task_10_2_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Task_10_2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Task_10_2_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_analog_output_cha, 8U,
        &Task_10_2_DW.HILInitialize_AOMinimums[0],
        &Task_10_2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Task_10_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Task_10_2_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_analog_output_cha, 8U,
        &Task_10_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if (Task_10_2_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Task_10_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Task_10_2_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Task_10_2_DW.HILInitialize_Card,
         Task_10_2_P.HILInitialize_analog_output_cha, 8U,
         &Task_10_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Task_10_2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Task_10_2_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &Task_10_2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Task_10_2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Task_10_2_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_encoder_channels, 8U,
        &Task_10_2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Task_10_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Task_10_2_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Task_10_2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Task_10_2_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &Task_10_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Task_10_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            Task_10_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Task_10_2_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Task_10_2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            Task_10_2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              Task_10_2_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Task_10_2_DW.HILInitialize_Card,
          &Task_10_2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Task_10_2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Task_10_2_DW.HILInitialize_Card,
          &Task_10_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Task_10_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Task_10_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Task_10_2_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Task_10_2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Task_10_2_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &Task_10_2_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Task_10_2_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &Task_10_2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Task_10_2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Task_10_2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &Task_10_2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Task_10_2_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Task_10_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Task_10_2_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_pwm_channels, 8U,
        &Task_10_2_DW.HILInitialize_POSortedFreqs[0],
        &Task_10_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if ((Task_10_2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Task_10_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Task_10_2_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Task_10_2_DW.HILInitialize_Card,
        Task_10_2_P.HILInitialize_pwm_channels, 8U,
        &Task_10_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }

    if (Task_10_2_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &Task_10_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Task_10_2_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Task_10_2_DW.HILInitialize_Card, Task_10_2_P.HILInitialize_pwm_channels,
         8U, &Task_10_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: Task_10_2/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Task_10_2_DW.HILInitialize_Card,
      Task_10_2_P.HILReadEncoderTimebase_samples_,
      Task_10_2_P.HILReadEncoderTimebase_channels, 3,
      &Task_10_2_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "travel_10_2.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Task_10_2_M, "Error creating .mat file travel_10_2.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(Task_10_2_M,
                        "Error writing mat file header to file travel_10_2.mat");
      return;
    }

    Task_10_2_DW.ToFile_IWORK.Count = 0;
    Task_10_2_DW.ToFile_IWORK.Decimation = -1;
    Task_10_2_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877560492152,
      0.52359877559658, 0.5235987755963144, 0.523598775597127,
      0.52359877559838952, 0.52359877559892432, 0.52359877559818269,
      0.52359877559813284, 0.5235987755995074, 0.5235987755932846,
      0.52359877558203516, 0.52359877559764556, 0.32964137432221624,
      -0.082196001871919083, -0.39016112360817312, -0.52359876713918663,
      -0.52359877501020946, -0.52359877532483412, -0.52359877540779232,
      -0.52359877544266786, -0.5235987754767053, -0.52359877559909884,
      -0.52359877552351786, -0.52359877559675272, -0.49033480137339214,
      -0.40501810220583878, -0.32447064600782055, -0.25079691812539884,
      -0.18530825612631663, -0.12865850709370216, -0.080975612492148533,
      -0.0419847296057214, -0.011118927457899686, 0.012384708953694748,
      0.029404351613447437, 0.040867863499640965, 0.047701489407297182,
      0.050791460320879819, 0.050956921794605058, 0.048932496148544578,
      0.045358794673558654, 0.040779278162935022, 0.035641996809331777,
      0.030304903853048411, 0.025043615742538536, 0.020060673067316365,
      0.015495532360574956, 0.011434682863740782, 0.0079214304676537752,
      0.0049650210056268072, 0.0025488859582608156, 0.00063788557755636139,
      -0.00081550163945945679, -0.001866036853366845, -0.0025715773399364555,
      -0.00298985297555696, -0.0031760653567461882, -0.0031812021804378914,
      -0.0030509565872365719, -0.0028251436352461088, -0.0025375124571477381,
      -0.0022158616951640209, -0.001882376452771677, -0.0015541163937290653,
      -0.0012435960885860775, -0.00095940975324972837, -0.00070686278577379049,
      -0.00048858175238366576, -0.00030508257007408779, -0.0001552835309878674,
      -3.695552644086322E-5, 5.2893584255749592E-5, 0.00011769996101076955,
      0.00016108699401117346, 0.00018666577177118082, 0.00019788667789750024,
      0.00019793537837916374, 0.00018966628876805866, 0.00017556677219923678,
      0.00015774572365545025, 0.00013794076512525609, 0.00011753894536965197,
      9.76065545511491E-5, 7.8924387407652824E-5, 6.2025489079698659E-5,
      4.7233074769393639E-5, 3.4696916179710258E-5, 2.4427029603288667E-5,
      1.6323984560809348E-5, 1.0205585662481058E-5, 5.83007602874037E-6,
      2.9163823701282081E-6, 1.1622799268600771E-6, 2.6169138172908884E-7,
      -7.7414313320392282E-8, -1.1308256891304961E-7, -4.6748396551471663E-8,
      2.3191605735608632E-13, 2.3131336931668928E-13, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0 } ;

    Task_10_2_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    Task_10_2_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    Task_10_2_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  Task_10_2_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  Task_10_2_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  Task_10_2_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  Task_10_2_X.Integrator_CSTATE = Task_10_2_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  Task_10_2_DW.TimeStampA = (rtInf);
  Task_10_2_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void Task_10_2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Task_10_2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Task_10_2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Task_10_2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Task_10_2_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Task_10_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Task_10_2_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Task_10_2_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (Task_10_2_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Task_10_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Task_10_2_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Task_10_2_DW.HILInitialize_Card
                         , Task_10_2_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Task_10_2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Task_10_2_DW.HILInitialize_AOVoltages[0]
                         , &Task_10_2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Task_10_2_DW.HILInitialize_Card,
            Task_10_2_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &Task_10_2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Task_10_2_DW.HILInitialize_Card,
            Task_10_2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &Task_10_2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Task_10_2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Task_10_2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Task_10_2_DW.HILInitialize_Card);
    hil_close(Task_10_2_DW.HILInitialize_Card);
    Task_10_2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) Task_10_2_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "travel_10_2.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Task_10_2_M, "Error closing MAT-file travel_10_2.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Task_10_2_M,
                          "Error reopening MAT-file travel_10_2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, Task_10_2_DW.ToFile_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(Task_10_2_M,
                          "Error writing header for ans to MAT-file travel_10_2.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Task_10_2_M, "Error closing MAT-file travel_10_2.mat");
        return;
      }

      Task_10_2_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Task_10_2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Task_10_2_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Task_10_2_initialize();
}

void MdlTerminate(void)
{
  Task_10_2_terminate();
}

/* Registration function */
RT_MODEL_Task_10_2_T *Task_10_2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Task_10_2_P.Integrator_UpperSat = rtInf;
  Task_10_2_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Task_10_2_M, 0,
                sizeof(RT_MODEL_Task_10_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Task_10_2_M->solverInfo,
                          &Task_10_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Task_10_2_M->solverInfo, &rtmGetTPtr(Task_10_2_M));
    rtsiSetStepSizePtr(&Task_10_2_M->solverInfo, &Task_10_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Task_10_2_M->solverInfo, &Task_10_2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Task_10_2_M->solverInfo, (real_T **)
                         &Task_10_2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Task_10_2_M->solverInfo,
      &Task_10_2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Task_10_2_M->solverInfo, (&rtmGetErrorStatus
      (Task_10_2_M)));
    rtsiSetRTModelPtr(&Task_10_2_M->solverInfo, Task_10_2_M);
  }

  rtsiSetSimTimeStep(&Task_10_2_M->solverInfo, MAJOR_TIME_STEP);
  Task_10_2_M->ModelData.intgData.f[0] = Task_10_2_M->ModelData.odeF[0];
  Task_10_2_M->ModelData.contStates = ((real_T *) &Task_10_2_X);
  rtsiSetSolverData(&Task_10_2_M->solverInfo, (void *)
                    &Task_10_2_M->ModelData.intgData);
  rtsiSetSolverName(&Task_10_2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Task_10_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Task_10_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Task_10_2_M->Timing.sampleTimes = (&Task_10_2_M->Timing.sampleTimesArray[0]);
    Task_10_2_M->Timing.offsetTimes = (&Task_10_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Task_10_2_M->Timing.sampleTimes[0] = (0.0);
    Task_10_2_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Task_10_2_M->Timing.offsetTimes[0] = (0.0);
    Task_10_2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Task_10_2_M, &Task_10_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Task_10_2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Task_10_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Task_10_2_M, 35.0);
  Task_10_2_M->Timing.stepSize0 = 0.002;
  Task_10_2_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Task_10_2_M->Sizes.checksums[0] = (3914096180U);
  Task_10_2_M->Sizes.checksums[1] = (1227664117U);
  Task_10_2_M->Sizes.checksums[2] = (243780236U);
  Task_10_2_M->Sizes.checksums[3] = (1981965167U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Task_10_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Task_10_2_M->extModeInfo,
      &Task_10_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Task_10_2_M->extModeInfo, Task_10_2_M->Sizes.checksums);
    rteiSetTPtr(Task_10_2_M->extModeInfo, rtmGetTPtr(Task_10_2_M));
  }

  Task_10_2_M->solverInfoPtr = (&Task_10_2_M->solverInfo);
  Task_10_2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Task_10_2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Task_10_2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Task_10_2_M->ModelData.blockIO = ((void *) &Task_10_2_B);

  {
    Task_10_2_B.TravelCounttorad = 0.0;
    Task_10_2_B.Gain = 0.0;
    Task_10_2_B.Sum2 = 0.0;
    Task_10_2_B.Gain_d = 0.0;
    Task_10_2_B.PitchCounttorad = 0.0;
    Task_10_2_B.Gain_i = 0.0;
    Task_10_2_B.Gain_b = 0.0;
    Task_10_2_B.ElevationCounttorad = 0.0;
    Task_10_2_B.Gain_e = 0.0;
    Task_10_2_B.Sum = 0.0;
    Task_10_2_B.Gain_dg = 0.0;
    Task_10_2_B.Sum_k = 0.0;
    Task_10_2_B.Sum2_c = 0.0;
    Task_10_2_B.K_ei = 0.0;
    Task_10_2_B.Gain_l = 0.0;
    Task_10_2_B.BackmotorSaturation = 0.0;
    Task_10_2_B.FrontmotorSaturation = 0.0;
  }

  /* parameters */
  Task_10_2_M->ModelData.defaultParam = ((real_T *)&Task_10_2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Task_10_2_X;
    Task_10_2_M->ModelData.contStates = (x);
    (void) memset((void *)&Task_10_2_X, 0,
                  sizeof(X_Task_10_2_T));
  }

  /* states (dwork) */
  Task_10_2_M->ModelData.dwork = ((void *) &Task_10_2_DW);
  (void) memset((void *)&Task_10_2_DW, 0,
                sizeof(DW_Task_10_2_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Task_10_2_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  Task_10_2_DW.TimeStampA = 0.0;
  Task_10_2_DW.LastUAtTimeA = 0.0;
  Task_10_2_DW.TimeStampB = 0.0;
  Task_10_2_DW.LastUAtTimeB = 0.0;
  Task_10_2_DW.HILWriteAnalog_Buffer[0] = 0.0;
  Task_10_2_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Task_10_2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Task_10_2_M->Sizes.numContStates = (4);/* Number of continuous states */
  Task_10_2_M->Sizes.numY = (0);       /* Number of model outputs */
  Task_10_2_M->Sizes.numU = (0);       /* Number of model inputs */
  Task_10_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Task_10_2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Task_10_2_M->Sizes.numBlocks = (60); /* Number of blocks */
  Task_10_2_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  Task_10_2_M->Sizes.numBlockPrms = (143);/* Sum of parameter "widths" */
  return Task_10_2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
