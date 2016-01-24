/*
 * testmodel_1109.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.217
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Dec 11 15:33:14 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "testmodel_1109_capi.h"
#include "testmodel_1109.h"
#include "testmodel_1109_private.h"

/* Block signals (auto storage) */
B_testmodel_1109_T testmodel_1109_B;

/* Block states (auto storage) */
DW_testmodel_1109_T testmodel_1109_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_testmodel_1109_T testmodel_1109_PrevZCX;

/* Real-time model */
RT_MODEL_testmodel_1109_T testmodel_1109_M_;
RT_MODEL_testmodel_1109_T *const testmodel_1109_M = &testmodel_1109_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S28>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != previousState) {
      if (previousState == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)curState == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S28>/Counter' */
  return retVal;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspcount2): '<S28>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != previousState) {
      if (previousState == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)curState == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S28>/Counter' */
  return retVal;
}

/* Model output function */
static void testmodel_1109_output(void)
{
  real_T currentTime;
  int32_T c1;
  int32_T vel1;
  uint8_T x[4];
  ZCEventType zcEvent;
  int8_T s26_iter;
  boolean_T zcEvent_0;
  uint8_T tmp;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.JKFlipFlop_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.CANSend_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.DefaultConfig_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.GetStatems_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.InitialPosition_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.QuitError_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.ForIteratorSubsystem_SubsysRanB);

  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[6];
    sfcnOutputs(rts, 1);
  }

  /* Clock: '<S1>/Clock' */
  testmodel_1109_B.Clock = testmodel_1109_M->Timing.t[0];

  /* Step: '<S1>/Step4' */
  currentTime = testmodel_1109_M->Timing.t[0];
  if (currentTime < testmodel_1109_P.Step4_Time) {
    testmodel_1109_B.Step4 = testmodel_1109_P.Step4_Y0;
  } else {
    testmodel_1109_B.Step4 = testmodel_1109_P.Step4_YFinal;
  }

  /* End of Step: '<S1>/Step4' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  testmodel_1109_B.PulseGenerator = (testmodel_1109_DW.clockTickCounter <
    testmodel_1109_P.PulseGenerator_Duty) && (testmodel_1109_DW.clockTickCounter
    >= 0) ? testmodel_1109_P.PulseGenerator_Amp : 0.0;
  if (testmodel_1109_DW.clockTickCounter >=
      testmodel_1109_P.PulseGenerator_Period - 1.0) {
    testmodel_1109_DW.clockTickCounter = 0;
  } else {
    testmodel_1109_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Product: '<S1>/Product' */
  testmodel_1109_B.Product = testmodel_1109_B.Step4 *
    testmodel_1109_B.PulseGenerator;

  /* S-Function (sdspcount2): '<S1>/Counter' */
  testmodel_1109_B.Counter_o2 = false;
  if (MWDSP_EPH_R_D(testmodel_1109_B.Product,
                    &testmodel_1109_DW.Counter_ClkEphState) != 0U) {
    if (testmodel_1109_DW.Counter_Count_p < ((uint16_T)5000U)) {
      testmodel_1109_DW.Counter_Count_p++;
    } else {
      testmodel_1109_DW.Counter_Count_p = 0U;
    }
  }

  testmodel_1109_B.Counter_o1 = testmodel_1109_DW.Counter_Count_p;
  if (testmodel_1109_DW.Counter_Count_p == testmodel_1109_P.Counter_HitValue_e)
  {
    testmodel_1109_B.Counter_o2 = true;
  }

  /* End of S-Function (sdspcount2): '<S1>/Counter' */

  /* Outputs for Triggered SubSystem: '<S1>/CANSend' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.CANSend_Trig_ZCE,
                     (testmodel_1109_B.Product));
  if (zcEvent != NO_ZCEVENT) {
    /* ok to acquire for <S18>/S-Function */
    testmodel_1109_DW.SFunction_IWORK_i.AcquireOK = 1;

    /* MATLAB Function: '<S19>/MATLAB Function1' incorporates:
     *  Constant: '<S3>/Cur'
     */
    /* MATLAB Function 'IO601/CANSend/movVel/MATLAB Function1': '<S21>:1' */
    if (testmodel_1109_P.Cur_Value > 0) {
      /* '<S21>:1:4' */
      /* '<S21>:1:5' */
      testmodel_1109_B.vel = 90000;
    } else {
      /* '<S21>:1:7' */
      testmodel_1109_B.vel = -90000;
    }

    /* '<S21>:1:9' */
    if (testmodel_1109_P.Cur_Value < 0) {
      c1 = testmodel_1109_P.Cur_Value;
      if (c1 <= MIN_int32_T) {
        c1 = MAX_int32_T;
      } else {
        c1 = -c1;
      }
    } else {
      c1 = testmodel_1109_P.Cur_Value;
    }

    /* '<S21>:1:10' */
    if (c1 < 0) {
      c1 = 0;
    }

    testmodel_1109_B.cur = (uint32_T)c1;

    /* End of MATLAB Function: '<S19>/MATLAB Function1' */

    /* MATLAB Function: '<S19>/TC UI32-UI8' */
    /* MATLAB Function 'IO601/CANSend/movVel/TC UI32-UI8': '<S22>:1' */
    /* '<S22>:1:3' */
    memcpy(&testmodel_1109_B.y_e[0], &testmodel_1109_B.cur, (size_t)4 * sizeof
           (uint8_T));

    /* S-Function (scanpack): '<S19>/CAN Pack1' */
    testmodel_1109_B.CANPack1_n.ID = 1283U;
    testmodel_1109_B.CANPack1_n.Length = 8U;
    testmodel_1109_B.CANPack1_n.Extended = 0U;
    testmodel_1109_B.CANPack1_n.Remote = 0;
    testmodel_1109_B.CANPack1_n.Data[0] = 0;
    testmodel_1109_B.CANPack1_n.Data[1] = 0;
    testmodel_1109_B.CANPack1_n.Data[2] = 0;
    testmodel_1109_B.CANPack1_n.Data[3] = 0;
    testmodel_1109_B.CANPack1_n.Data[4] = 0;
    testmodel_1109_B.CANPack1_n.Data[5] = 0;
    testmodel_1109_B.CANPack1_n.Data[6] = 0;
    testmodel_1109_B.CANPack1_n.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.DLen_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[0] =
                    testmodel_1109_B.CANPack1_n.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.FragSt_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[1] =
                    testmodel_1109_B.CANPack1_n.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Cmd_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[2] =
                    testmodel_1109_B.CANPack1_n.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 24
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          int32_T packingValue = 0;

          {
            int32_T result = (int32_T) (testmodel_1109_B.vel);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              int32_T packedValue;
              int32_T scaledValue;
              scaledValue = (int32_T) (packingValue);
              if (scaledValue > (int32_T) (2147483647)) {
                packedValue = 2147483647;
              } else if (scaledValue < (int32_T)((-(2147483647)-1))) {
                packedValue = (-(2147483647)-1);
              } else {
                packedValue = (int32_T) (scaledValue);
              }

              {
                /* The following cast from int32_T to uint32_T is intetional for bit copy. */
                uint32_T tempValue = (uint32_T) (packedValue);

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[3] =
                    testmodel_1109_B.CANPack1_n.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[4] =
                    testmodel_1109_B.CANPack1_n.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[5] =
                    testmodel_1109_B.CANPack1_n.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[6] =
                    testmodel_1109_B.CANPack1_n.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 56
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_B.y_e[0]);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_n.Data[7] =
                    testmodel_1109_B.CANPack1_n.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S19>/CAN Pack2' */
    testmodel_1109_B.CANPack2_j.ID = 1283U;
    testmodel_1109_B.CANPack2_j.Length = 5U;
    testmodel_1109_B.CANPack2_j.Extended = 0U;
    testmodel_1109_B.CANPack2_j.Remote = 0;
    testmodel_1109_B.CANPack2_j.Data[0] = 0;
    testmodel_1109_B.CANPack2_j.Data[1] = 0;
    testmodel_1109_B.CANPack2_j.Data[2] = 0;
    testmodel_1109_B.CANPack2_j.Data[3] = 0;
    testmodel_1109_B.CANPack2_j.Data[4] = 0;
    testmodel_1109_B.CANPack2_j.Data[5] = 0;
    testmodel_1109_B.CANPack2_j.Data[6] = 0;
    testmodel_1109_B.CANPack2_j.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.DLen1_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[0] =
                    testmodel_1109_B.CANPack2_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.FragEn_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[1] =
                    testmodel_1109_B.CANPack2_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_B.y_e[1]);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[2] =
                    testmodel_1109_B.CANPack2_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 24
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_B.y_e[2]);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[3] =
                    testmodel_1109_B.CANPack2_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 4 ------------------
       *  startBit                = 32
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_B.y_e[3]);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_j.Data[4] =
                    testmodel_1109_B.CANPack2_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[0] =
      testmodel_1109_B.CANPack1_n;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[1] =
      testmodel_1109_B.CANPack2_j;

    /* Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport1' */
    testmodel_1109_B.TmpLatchAtJKFlipFlopInport1 =
      testmodel_1109_DW.TmpLatchAtJKFlipFlopInport1_Pre;

    /* Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport2' */
    testmodel_1109_B.TmpLatchAtJKFlipFlopInport2 =
      testmodel_1109_DW.TmpLatchAtJKFlipFlopInport2_Pre;

    /* SignalConversion: '<S15>/HiddenBuf_InsertedFor_J-K Flip-Flop_at_inport_2' */
    testmodel_1109_B.HiddenBuf_InsertedFor_JKFlipFlo =
      testmodel_1109_B.Counter_o2;

    /* Outputs for Triggered SubSystem: '<S15>/J-K Flip-Flop' incorporates:
     *  TriggerPort: '<S20>/Trigger'
     */
    zcEvent_0 = ((!testmodel_1109_B.HiddenBuf_InsertedFor_JKFlipFlo) &&
                 (testmodel_1109_PrevZCX.JKFlipFlop_Trig_ZCE != ZERO_ZCSIG));
    if (zcEvent_0) {
      /* Memory: '<S20>/Memory' */
      testmodel_1109_B.Memory = testmodel_1109_DW.Memory_PreviousInput;

      /* CombinatorialLogic: '<S20>/Logic' */
      zcEvent_0 = testmodel_1109_B.Memory;
      c1 = zcEvent_0;
      zcEvent_0 = testmodel_1109_B.TmpLatchAtJKFlipFlopInport1;
      c1 = (int32_T)(((uint32_T)c1 << 1) + zcEvent_0);
      zcEvent_0 = testmodel_1109_B.TmpLatchAtJKFlipFlopInport2;
      c1 = (int32_T)(((uint32_T)c1 << 1) + zcEvent_0);
      testmodel_1109_B.Logic[0U] = testmodel_1109_P.Logic_table[(uint32_T)c1];
      testmodel_1109_B.Logic[1U] = testmodel_1109_P.Logic_table[c1 + 8U];

      /* SignalConversion: '<S20>/OutportBufferFor!Q' */
      testmodel_1109_B.OutportBufferForQ = testmodel_1109_B.Logic[1];

      /* Update for Memory: '<S20>/Memory' */
      testmodel_1109_DW.Memory_PreviousInput = testmodel_1109_B.Logic[0];
      testmodel_1109_DW.JKFlipFlop_SubsysRanBC = 4;
    }

    testmodel_1109_PrevZCX.JKFlipFlop_Trig_ZCE =
      testmodel_1109_B.HiddenBuf_InsertedFor_JKFlipFlo;

    /* End of Outputs for SubSystem: '<S15>/J-K Flip-Flop' */

    /* Product: '<S3>/Product2' incorporates:
     *  Constant: '<S3>/SendVel'
     */
    testmodel_1109_B.Product2 = testmodel_1109_P.SendVel_Value * (real_T)
      testmodel_1109_B.OutportBufferForQ;

    /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* S-Function (scanpack): '<S17>/CAN Pack2' */
    testmodel_1109_B.CANPack2_p.ID = 1283U;
    testmodel_1109_B.CANPack2_p.Length = 2U;
    testmodel_1109_B.CANPack2_p.Extended = 0U;
    testmodel_1109_B.CANPack2_p.Remote = 0;
    testmodel_1109_B.CANPack2_p.Data[0] = 0;
    testmodel_1109_B.CANPack2_p.Data[1] = 0;
    testmodel_1109_B.CANPack2_p.Data[2] = 0;
    testmodel_1109_B.CANPack2_p.Data[3] = 0;
    testmodel_1109_B.CANPack2_p.Data[4] = 0;
    testmodel_1109_B.CANPack2_p.Data[5] = 0;
    testmodel_1109_B.CANPack2_p.Data[6] = 0;
    testmodel_1109_B.CANPack2_p.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.DataLen_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[0] =
                    testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.StopCmd_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_p.Data[1] =
                    testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/SendStop'
     */
    testmodel_1109_B.Product_b = testmodel_1109_P.SendStop_Value * (real_T)
      testmodel_1109_B.Counter_o2;

    /* Level2 S-Function Block: '<S3>/Write (v3)1' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Constant: '<S3>/Cur'
     */
    /* MATLAB Function 'IO601/CANSend/MATLAB Function': '<S16>:1' */
    /* '<S16>:1:4' */
    currentTime = rt_roundd_snf(sin(157.07963267948966 / testmodel_1109_B.Clock)
      * (real_T)testmodel_1109_P.Cur_Value);
    if (currentTime < 2.147483648E+9) {
      if (currentTime >= -2.147483648E+9) {
        c1 = (int32_T)currentTime;
      } else {
        c1 = MIN_int32_T;
      }
    } else {
      c1 = MAX_int32_T;
    }

    testmodel_1109_B.y = c1;

    /* End of MATLAB Function: '<S3>/MATLAB Function' */
    /* S-Function (scanpack): '<S14>/CAN Pack2' */
    testmodel_1109_B.CANPack2_e.ID = 1283U;
    testmodel_1109_B.CANPack2_e.Length = 7U;
    testmodel_1109_B.CANPack2_e.Extended = 0U;
    testmodel_1109_B.CANPack2_e.Remote = 0;
    testmodel_1109_B.CANPack2_e.Data[0] = 0;
    testmodel_1109_B.CANPack2_e.Data[1] = 0;
    testmodel_1109_B.CANPack2_e.Data[2] = 0;
    testmodel_1109_B.CANPack2_e.Data[3] = 0;
    testmodel_1109_B.CANPack2_e.Data[4] = 0;
    testmodel_1109_B.CANPack2_e.Data[5] = 0;
    testmodel_1109_B.CANPack2_e.Data[6] = 0;
    testmodel_1109_B.CANPack2_e.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant5_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[0] =
                    testmodel_1109_B.CANPack2_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.GetStateCmd_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[1] =
                    testmodel_1109_B.CANPack2_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant6_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint32_T packedValue;
              if (outValue > (real64_T)(4294967295U)) {
                packedValue = (uint32_T) 4294967295U;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint32_T) 0;
              } else {
                packedValue = (uint32_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[2] =
                    testmodel_1109_B.CANPack2_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 10))
                     >> 10)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 11))
                     >> 11)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 12))
                     >> 12)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 13))
                     >> 13)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 14))
                     >> 14)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[3] =
                    testmodel_1109_B.CANPack2_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 15))
                     >> 15)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 16))
                     >> 16)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 17))
                     >> 17)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 18))
                     >> 18)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 19))
                     >> 19)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 20))
                     >> 20)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 21))
                     >> 21)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 22))
                     >> 22)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[4] =
                    testmodel_1109_B.CANPack2_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 23))
                     >> 23)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 24))
                     >> 24)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 25))
                     >> 25)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 26))
                     >> 26)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 27))
                     >> 27)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 28))
                     >> 28)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 29))
                     >> 29)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 30))
                     >> 30)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[5] =
                    testmodel_1109_B.CANPack2_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 31))
                     >> 31)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 48
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_P.position_Value);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_e.Data[6] =
                    testmodel_1109_B.CANPack2_e.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Update for Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport1' */
    testmodel_1109_DW.TmpLatchAtJKFlipFlopInport1_Pre =
      testmodel_1109_B.Counter_o2;

    /* Update for Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport2' */
    testmodel_1109_DW.TmpLatchAtJKFlipFlopInport2_Pre =
      testmodel_1109_B.Counter_o2;
    testmodel_1109_DW.CANSend_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/CANSend' */
  /* ok to acquire for <S8>/S-Function */
  testmodel_1109_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S9>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_c.AcquireOK = 1;

  /* ok to acquire for <S10>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_b.AcquireOK = 1;

  /* ok to acquire for <S11>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* ok to acquire for <S12>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_bv.AcquireOK = 1;

  /* ok to acquire for <S13>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_oz.AcquireOK = 1;

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
    sfcnOutputs(rts, 1);
  }

  /* Outputs for Iterator SubSystem: '<S7>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S26>/For Iterator'
   */
  s26_iter = 1;
  do {
    exitg1 = 0;
    currentTime = testmodel_1109_B.Readv3_o2;
    if (currentTime < 0.0) {
      currentTime = ceil(currentTime);
    } else {
      currentTime = floor(currentTime);
    }

    if (rtIsNaN(currentTime) || rtIsInf(currentTime)) {
      currentTime = 0.0;
    } else {
      currentTime = fmod(currentTime, 256.0);
    }

    if (s26_iter <= (currentTime < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                     -currentTime : (int32_T)(int8_T)(uint8_T)currentTime)) {
      testmodel_1109_B.ForIterator = s26_iter;
      testmodel_1109_B.IndexVector =
        testmodel_1109_B.Readv3_o1[testmodel_1109_B.ForIterator - 1];

      /* S-Function (scanunpack): '<S26>/CAN Unpack2' */
      {
        /* S-Function (scanunpack): '<S26>/CAN Unpack2' */
        if ((8 == testmodel_1109_B.IndexVector.Length) &&
            (testmodel_1109_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((1795U == testmodel_1109_B.IndexVector.ID) && (0U ==
               testmodel_1109_B.IndexVector.Extended) ) {
            (void) memcpy(&testmodel_1109_B.CANUnpack2[0],
                          testmodel_1109_B.IndexVector.Data,
                          8 * sizeof(uint8_T));
          }
        }
      }

      /* S-Function (scanunpack): '<S26>/CAN Unpack3' */
      {
        /* S-Function (scanunpack): '<S26>/CAN Unpack3' */
        if ((7 == testmodel_1109_B.IndexVector.Length) &&
            (testmodel_1109_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((1795U == testmodel_1109_B.IndexVector.ID) && (0U ==
               testmodel_1109_B.IndexVector.Extended) ) {
            (void) memcpy(&testmodel_1109_B.CANUnpack3[0],
                          testmodel_1109_B.IndexVector.Data,
                          7 * sizeof(uint8_T));
          }
        }
      }

      /* MATLAB Function 'IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function1': '<S27>:1' */
      if (testmodel_1109_B.CANUnpack2[2] == 149) {
        /* '<S27>:1:14' */
        /* '<S27>:1:15' */
        /* '<S27>:1:16' */
        testmodel_1109_DW.pos[0] = testmodel_1109_B.CANUnpack2[3];
        testmodel_1109_DW.pos[1] = testmodel_1109_B.CANUnpack2[4];
        testmodel_1109_DW.pos[2] = testmodel_1109_B.CANUnpack2[5];
        testmodel_1109_DW.pos[3] = testmodel_1109_B.CANUnpack2[6];
        if (testmodel_1109_B.CANUnpack2[0] > 8) {
          /* '<S27>:1:17' */
          /* '<S27>:1:18' */
          testmodel_1109_DW.vel[0] = testmodel_1109_B.CANUnpack2[7];

          /* '<S27>:1:19' */
          testmodel_1109_DW.vel[1] = testmodel_1109_B.CANUnpack3[2];
          testmodel_1109_DW.vel[2] = testmodel_1109_B.CANUnpack3[3];
          testmodel_1109_DW.vel[3] = testmodel_1109_B.CANUnpack3[4];
        }
      }

      /* '<S27>:1:22' */
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[0] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[1]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[1] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[2]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[2] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[3]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[3] = tmp;
      memcpy(&c1, &x[0], (size_t)1 * sizeof(int32_T));

      /* '<S27>:1:23' */
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[0] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[1]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[1] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[2]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[2] = tmp;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[3]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          tmp = (uint8_T)currentTime;
        } else {
          tmp = 0U;
        }
      } else {
        tmp = MAX_uint8_T;
      }

      x[3] = tmp;
      memcpy(&vel1, &x[0], (size_t)1 * sizeof(int32_T));

      /* '<S27>:1:25' */
      testmodel_1109_B.state[0] = c1;
      testmodel_1109_B.state[1] = vel1;
      testmodel_1109_B.OutportBufferForpos = testmodel_1109_B.state[0];
      testmodel_1109_B.OutportBufferForvel = testmodel_1109_B.state[1];

      /* ok to acquire for <S30>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_d.AcquireOK = 1;

      /* ok to acquire for <S31>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_h.AcquireOK = 1;

      /* S-Function (scanunpack): '<S28>/CAN Unpack1' */
      {
        /* S-Function (scanunpack): '<S28>/CAN Unpack1' */
        if ((4 == testmodel_1109_B.IndexVector.Length) &&
            (testmodel_1109_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((1795U == testmodel_1109_B.IndexVector.ID) && (0U ==
               testmodel_1109_B.IndexVector.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 0
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                {
                  real64_T outValue = 0;

                  {
                    {
                      uint8_T unpackedValue = 0;

                      {
                        uint8_T tempValue = (uint8_T) (0);

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 0)) >> 0)<<0);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 1)) >> 1)<<1);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 2)) >> 2)<<2);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 3)) >> 3)<<3);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 4)) >> 4)<<4);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 5)) >> 5)<<5);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 6)) >> 6)<<6);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[0]) & (uint8_T)(
                            (uint8_T) (1)<< 7)) >> 7)<<7);
                        }

                        unpackedValue = tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel_1109_B.CANUnpack1_o1 = result;
                  }
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 8
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                {
                  real64_T outValue = 0;

                  {
                    {
                      uint8_T unpackedValue = 0;

                      {
                        uint8_T tempValue = (uint8_T) (0);

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 0)) >> 0)<<0);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 1)) >> 1)<<1);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 2)) >> 2)<<2);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 3)) >> 3)<<3);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 4)) >> 4)<<4);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 5)) >> 5)<<5);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 6)) >> 6)<<6);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel_1109_B.IndexVector.Data[1]) & (uint8_T)(
                            (uint8_T) (1)<< 7)) >> 7)<<7);
                        }

                        unpackedValue = tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel_1109_B.CANUnpack1_o2 = result;
                  }
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 16
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                {
                  real64_T outValue = 0;

                  {
                    {
                      int16_T unpackedValue = 0;

                      {
                        uint16_T tempValue = (uint16_T) (0);

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            0);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            1);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            2);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            3);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            4);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            5);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            6);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            7);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            8);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            9);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            10);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            11);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            12);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            13);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            14);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            15);
                        }

                        unpackedValue = (int16_T) tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel_1109_B.CANUnpack1_o3 = result;
                  }
                }
              }
            }

            /* Extract the Timestamp */
            testmodel_1109_B.CANUnpack1_o4 =
              testmodel_1109_B.IndexVector.Timestamp;
          }
        }
      }

      testmodel_1109_B.Uk1_k = testmodel_1109_DW.DelayInput1_DSTATE_h;
      testmodel_1109_B.FixPtRelationalOperator_k =
        (testmodel_1109_B.CANUnpack1_o4 > testmodel_1109_B.Uk1_k);
      testmodel_1109_B.Counter_o2_i = false;
      if (MWDSP_EPH_R_D(0.0, &testmodel_1109_DW.Counter_RstEphState) != 0U) {
        testmodel_1109_DW.Counter_Count = testmodel_1109_P.Counter_InitialCount;
      }

      if (MWDSP_EPH_R_B(testmodel_1109_B.FixPtRelationalOperator_k,
                        &testmodel_1109_DW.Counter_ClkEphState_g) != 0U) {
        if (testmodel_1109_DW.Counter_Count < 500000U) {
          testmodel_1109_DW.Counter_Count++;
        } else {
          testmodel_1109_DW.Counter_Count = 0U;
        }
      }

      testmodel_1109_B.Counter_o1_i = testmodel_1109_DW.Counter_Count;
      if (testmodel_1109_DW.Counter_Count == testmodel_1109_P.Counter_HitValue)
      {
        testmodel_1109_B.Counter_o2_i = true;
      }

      testmodel_1109_B.DataTypeConversion =
        testmodel_1109_B.FixPtRelationalOperator_k;
      testmodel_1109_DW.DelayInput1_DSTATE_h = testmodel_1109_B.CANUnpack1_o4;
      srUpdateBC(testmodel_1109_DW.ForIteratorSubsystem_SubsysRanB);
      s26_iter++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<S7>/For Iterator Subsystem' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  testmodel_1109_B.PulseGenerator1 = (testmodel_1109_DW.clockTickCounter_g <
    testmodel_1109_P.PulseGenerator1_Duty) &&
    (testmodel_1109_DW.clockTickCounter_g >= 0) ?
    testmodel_1109_P.PulseGenerator1_Amp : 0.0;
  if (testmodel_1109_DW.clockTickCounter_g >=
      testmodel_1109_P.PulseGenerator1_Period - 1.0) {
    testmodel_1109_DW.clockTickCounter_g = 0;
  } else {
    testmodel_1109_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

  /* S-Function (sdspcount2): '<S1>/Counter1' */
  testmodel_1109_B.Counter1_o2 = false;
  if (MWDSP_EPH_R_D(testmodel_1109_B.PulseGenerator1,
                    &testmodel_1109_DW.Counter1_RstEphState) != 0U) {
    testmodel_1109_DW.Counter1_Count = testmodel_1109_P.Counter1_InitialCount;
  }

  if (MWDSP_EPH_R_D(testmodel_1109_B.Counter_o1_i,
                    &testmodel_1109_DW.Counter1_ClkEphState) != 0U) {
    if (testmodel_1109_DW.Counter1_Count < ((uint16_T)5000U)) {
      testmodel_1109_DW.Counter1_Count++;
    } else {
      testmodel_1109_DW.Counter1_Count = 0U;
    }
  }

  testmodel_1109_B.Counter1_o1 = testmodel_1109_DW.Counter1_Count;
  if (testmodel_1109_DW.Counter1_Count == testmodel_1109_P.Counter1_HitValue) {
    testmodel_1109_B.Counter1_o2 = true;
  }

  /* End of S-Function (sdspcount2): '<S1>/Counter1' */

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  testmodel_1109_B.DiscreteTimeIntegrator =
    testmodel_1109_DW.DiscreteTimeIntegrator_DSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  testmodel_1109_B.DataTypeConversion_m = (int32_T)
    (testmodel_1109_B.DiscreteTimeIntegrator * 274877907LL >> 36);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  testmodel_1109_B.DataTypeConversion1 = testmodel_1109_B.OutportBufferForpos;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  testmodel_1109_B.DataTypeConversion2 = testmodel_1109_B.OutportBufferForvel;

  /* Sum: '<S1>/Subtract' */
  testmodel_1109_B.Subtract = testmodel_1109_B.Counter_o1 -
    testmodel_1109_B.Counter_o1_i;

  /* TransportDelay: '<S1>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = testmodel_1109_M->Timing.t[0];
    real_T tMinusDelay = simTime - (testmodel_1109_P.Ts * 10.0);
    testmodel_1109_B.TransportDelay = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      testmodel_1109_DW.TransportDelay_IWORK.CircularBufSize,
      &testmodel_1109_DW.TransportDelay_IWORK.Last,
      testmodel_1109_DW.TransportDelay_IWORK.Tail,
      testmodel_1109_DW.TransportDelay_IWORK.Head,
      testmodel_1109_P.TransportDelay_InitOutput,
      0,
      0);
  }

  /* Step: '<S1>/Step5' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step5_Time) {
    testmodel_1109_B.Step5 = testmodel_1109_P.Step5_Y0;
  } else {
    testmodel_1109_B.Step5 = testmodel_1109_P.Step5_YFinal;
  }

  /* End of Step: '<S1>/Step5' */

  /* Outputs for Triggered SubSystem: '<S1>/DefaultConfig' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.DefaultConfig_Trig_ZCE,
                     (testmodel_1109_B.Step5));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S4>/CAN Pack1' */
    testmodel_1109_B.CANPack1.ID = 1283U;
    testmodel_1109_B.CANPack1.Length = 6U;
    testmodel_1109_B.CANPack1.Extended = 0U;
    testmodel_1109_B.CANPack1.Remote = 0;
    testmodel_1109_B.CANPack1.Data[0] = 0;
    testmodel_1109_B.CANPack1.Data[1] = 0;
    testmodel_1109_B.CANPack1.Data[2] = 0;
    testmodel_1109_B.CANPack1.Data[3] = 0;
    testmodel_1109_B.CANPack1.Data[4] = 0;
    testmodel_1109_B.CANPack1.Data[5] = 0;
    testmodel_1109_B.CANPack1.Data[6] = 0;
    testmodel_1109_B.CANPack1.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant3_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[0] =
                    testmodel_1109_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant4_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[1] =
                    testmodel_1109_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant6_Value_k;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              int32_T packedValue;
              int32_T scaledValue;
              scaledValue = (int32_T) (outValue);
              if (scaledValue > (int32_T) (2147483647)) {
                packedValue = 2147483647;
              } else if (scaledValue < (int32_T)((-(2147483647)-1))) {
                packedValue = (-(2147483647)-1);
              } else {
                packedValue = (int32_T) (scaledValue);
              }

              {
                /* The following cast from int32_T to uint32_T is intetional for bit copy. */
                uint32_T tempValue = (uint32_T) (packedValue);

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[5] =
                    testmodel_1109_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S4>/CAN Pack' */
    testmodel_1109_B.CANPack_j.ID = 1283U;
    testmodel_1109_B.CANPack_j.Length = 6U;
    testmodel_1109_B.CANPack_j.Extended = 0U;
    testmodel_1109_B.CANPack_j.Remote = 0;
    testmodel_1109_B.CANPack_j.Data[0] = 0;
    testmodel_1109_B.CANPack_j.Data[1] = 0;
    testmodel_1109_B.CANPack_j.Data[2] = 0;
    testmodel_1109_B.CANPack_j.Data[3] = 0;
    testmodel_1109_B.CANPack_j.Data[4] = 0;
    testmodel_1109_B.CANPack_j.Data[5] = 0;
    testmodel_1109_B.CANPack_j.Data[6] = 0;
    testmodel_1109_B.CANPack_j.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant1_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[0] =
                    testmodel_1109_B.CANPack_j.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant2_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[1] =
                    testmodel_1109_B.CANPack_j.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant5_Value_k;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              int32_T packedValue;
              int32_T scaledValue;
              scaledValue = (int32_T) (outValue);
              if (scaledValue > (int32_T) (2147483647)) {
                packedValue = 2147483647;
              } else if (scaledValue < (int32_T)((-(2147483647)-1))) {
                packedValue = (-(2147483647)-1);
              } else {
                packedValue = (int32_T) (scaledValue);
              }

              {
                /* The following cast from int32_T to uint32_T is intetional for bit copy. */
                uint32_T tempValue = (uint32_T) (packedValue);

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[2] =
                    testmodel_1109_B.CANPack_j.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[3] =
                    testmodel_1109_B.CANPack_j.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[4] =
                    testmodel_1109_B.CANPack_j.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack_j.Data[5] =
                    testmodel_1109_B.CANPack_j.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S4>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[0] =
      testmodel_1109_B.CANPack1;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[1] =
      testmodel_1109_B.CANPack_j;

    /* Constant: '<S4>/Constant' */
    testmodel_1109_B.Constant_d = testmodel_1109_P.Constant_Value;

    /* Level2 S-Function Block: '<S4>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.DefaultConfig_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/DefaultConfig' */

  /* UnitDelay: '<S5>/Delay Input1' */
  testmodel_1109_B.Uk1 = testmodel_1109_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S5>/FixPt Relational Operator' */
  testmodel_1109_B.FixPtRelationalOperator = (uint8_T)(0.0 >
    testmodel_1109_B.Uk1);

  /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  testmodel_1109_B.PulseGenerator2 = (testmodel_1109_DW.clockTickCounter_c <
    testmodel_1109_P.PulseGenerator2_Duty) &&
    (testmodel_1109_DW.clockTickCounter_c >= 0) ?
    testmodel_1109_P.PulseGenerator2_Amp : 0.0;
  if (testmodel_1109_DW.clockTickCounter_c >=
      testmodel_1109_P.PulseGenerator2_Period - 1.0) {
    testmodel_1109_DW.clockTickCounter_c = 0;
  } else {
    testmodel_1109_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

  /* Step: '<S1>/Step1' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step1_Time) {
    testmodel_1109_B.Step1 = testmodel_1109_P.Step1_Y0;
  } else {
    testmodel_1109_B.Step1 = testmodel_1109_P.Step1_YFinal;
  }

  /* End of Step: '<S1>/Step1' */

  /* Step: '<S6>/Step1' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step1_Time_g) {
    testmodel_1109_B.Step1_b = testmodel_1109_P.Step1_Y0_m;
  } else {
    testmodel_1109_B.Step1_b = testmodel_1109_P.Step1_YFinal_h;
  }

  /* End of Step: '<S6>/Step1' */

  /* Outputs for Triggered SubSystem: '<S6>/GetState(ms)' incorporates:
   *  TriggerPort: '<S23>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.GetStatems_Trig_ZCE,
                     (testmodel_1109_B.Step1_b));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S23>/CAN Pack2' */
    testmodel_1109_B.CANPack2.ID = 1283U;
    testmodel_1109_B.CANPack2.Length = 7U;
    testmodel_1109_B.CANPack2.Extended = 0U;
    testmodel_1109_B.CANPack2.Remote = 0;
    testmodel_1109_B.CANPack2.Data[0] = 0;
    testmodel_1109_B.CANPack2.Data[1] = 0;
    testmodel_1109_B.CANPack2.Data[2] = 0;
    testmodel_1109_B.CANPack2.Data[3] = 0;
    testmodel_1109_B.CANPack2.Data[4] = 0;
    testmodel_1109_B.CANPack2.Data[5] = 0;
    testmodel_1109_B.CANPack2.Data[6] = 0;
    testmodel_1109_B.CANPack2.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.DataLen_Value_c;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[0] =
                    testmodel_1109_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.GetStateCmd_Value_n;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[1] =
                    testmodel_1109_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Timems_Value;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint32_T packedValue;
              if (outValue > (real64_T)(4294967295U)) {
                packedValue = (uint32_T) 4294967295U;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint32_T) 0;
              } else {
                packedValue = (uint32_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[2] =
                    testmodel_1109_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 10))
                     >> 10)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 11))
                     >> 11)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 12))
                     >> 12)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 13))
                     >> 13)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 14))
                     >> 14)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[3] =
                    testmodel_1109_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 15))
                     >> 15)<<7);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 16))
                     >> 16)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 17))
                     >> 17)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 18))
                     >> 18)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 19))
                     >> 19)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 20))
                     >> 20)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 21))
                     >> 21)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 22))
                     >> 22)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[4] =
                    testmodel_1109_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 23))
                     >> 23)<<7);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 24))
                     >> 24)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 25))
                     >> 25)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 26))
                     >> 26)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 27))
                     >> 27)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 28))
                     >> 28)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 29))
                     >> 29)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 30))
                     >> 30)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[5] =
                    testmodel_1109_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 31))
                     >> 31)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 3 ------------------
       *  startBit                = 48
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_P.states_Value);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (packingValue > (uint8_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (packingValue < (uint8_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (packingValue);
              }

              {
                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2.Data[6] =
                    testmodel_1109_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S23>/Constant1' */
    testmodel_1109_B.Constant1_n = testmodel_1109_P.Constant1_Value_m;

    /* Level2 S-Function Block: '<S23>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.GetStatems_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S6>/GetState(ms)' */

  /* Step: '<S6>/Step3' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step3_Time) {
    testmodel_1109_B.Step3 = testmodel_1109_P.Step3_Y0;
  } else {
    testmodel_1109_B.Step3 = testmodel_1109_P.Step3_YFinal;
  }

  /* End of Step: '<S6>/Step3' */

  /* Outputs for Triggered SubSystem: '<S6>/InitialPosition' incorporates:
   *  TriggerPort: '<S24>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.InitialPosition_Trig_ZCE,
                     (testmodel_1109_B.Step3));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S24>/CAN Pack' */
    testmodel_1109_B.CANPack_e.ID = 1283U;
    testmodel_1109_B.CANPack_e.Length = 6U;
    testmodel_1109_B.CANPack_e.Extended = 0U;
    testmodel_1109_B.CANPack_e.Remote = 0;
    testmodel_1109_B.CANPack_e.Data[0] = 0;
    testmodel_1109_B.CANPack_e.Data[1] = 0;
    testmodel_1109_B.CANPack_e.Data[2] = 0;
    testmodel_1109_B.CANPack_e.Data[3] = 0;
    testmodel_1109_B.CANPack_e.Data[4] = 0;
    testmodel_1109_B.CANPack_e.Data[5] = 0;
    testmodel_1109_B.CANPack_e.Data[6] = 0;
    testmodel_1109_B.CANPack_e.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant1_Value_i;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[0] =
                    testmodel_1109_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant2_Value_g;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[1] =
                    testmodel_1109_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 2 ------------------
       *  startBit                = 16
       *  length                  = 32
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = SIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant5_Value_d;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              int32_T packedValue;
              int32_T scaledValue;
              scaledValue = (int32_T) (outValue);
              if (scaledValue > (int32_T) (2147483647)) {
                packedValue = 2147483647;
              } else if (scaledValue < (int32_T)((-(2147483647)-1))) {
                packedValue = (-(2147483647)-1);
              } else {
                packedValue = (int32_T) (scaledValue);
              }

              {
                /* The following cast from int32_T to uint32_T is intetional for bit copy. */
                uint32_T tempValue = (uint32_T) (packedValue);

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[2] =
                    testmodel_1109_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[3] =
                    testmodel_1109_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[4] =
                    testmodel_1109_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack_e.Data[5] =
                    testmodel_1109_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S24>/Constant' */
    testmodel_1109_B.Constant = testmodel_1109_P.Constant_Value_a;

    /* Level2 S-Function Block: '<S24>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.InitialPosition_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S6>/InitialPosition' */

  /* Step: '<S6>/Step' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step_Time) {
    testmodel_1109_B.Step = testmodel_1109_P.Step_Y0;
  } else {
    testmodel_1109_B.Step = testmodel_1109_P.Step_YFinal;
  }

  /* End of Step: '<S6>/Step' */

  /* Outputs for Triggered SubSystem: '<S6>/QuitError' incorporates:
   *  TriggerPort: '<S25>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.QuitError_Trig_ZCE,
                     (testmodel_1109_B.Step));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S25>/CAN Pack' */
    testmodel_1109_B.CANPack.ID = 1283U;
    testmodel_1109_B.CANPack.Length = 2U;
    testmodel_1109_B.CANPack.Extended = 0U;
    testmodel_1109_B.CANPack.Remote = 0;
    testmodel_1109_B.CANPack.Data[0] = 0;
    testmodel_1109_B.CANPack.Data[1] = 0;
    testmodel_1109_B.CANPack.Data[2] = 0;
    testmodel_1109_B.CANPack.Data[3] = 0;
    testmodel_1109_B.CANPack.Data[4] = 0;
    testmodel_1109_B.CANPack.Data[5] = 0;
    testmodel_1109_B.CANPack.Data[6] = 0;
    testmodel_1109_B.CANPack.Data[7] = 0;

    {
      /* --------------- START Packing signal 0 ------------------
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant2_Value_n;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[0] =
                    testmodel_1109_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }

      /* --------------- START Packing signal 1 ------------------
       *  startBit                = 8
       *  length                  = 8
       *  desiredSignalByteLayout = LITTLEENDIAN
       *  dataType                = UNSIGNED
       *  factor                  = 1.0
       *  offset                  = 0.0
       *  minimum                 = 0.0
       *  maximum                 = 0.0
       * -----------------------------------------------------------------------*/
      {
        {
          real64_T outValue = 0;

          {
            real64_T result = testmodel_1109_P.Constant3_Value_f;

            /* no scaling required */
            outValue = result;
          }

          {
            {
              uint8_T packedValue;
              if (outValue > (real64_T)(255)) {
                packedValue = (uint8_T) 255;
              } else if (outValue < (real64_T)(0)) {
                packedValue = (uint8_T) 0;
              } else {
                packedValue = (uint8_T) (outValue);
              }

              {
                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[1] =
                    testmodel_1109_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S25>/Constant1' */
    testmodel_1109_B.Constant1 = testmodel_1109_P.Constant1_Value_i1;

    /* Level2 S-Function Block: '<S25>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.QuitError_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S6>/QuitError' */
}

/* Model update function */
static void testmodel_1109_update(void)
{
  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  testmodel_1109_DW.DiscreteTimeIntegrator_DSTATE +=
    testmodel_1109_B.OutportBufferForvel;

  /* Update for TransportDelay: '<S1>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = testmodel_1109_M->Timing.t[0];
    testmodel_1109_DW.TransportDelay_IWORK.Head =
      ((testmodel_1109_DW.TransportDelay_IWORK.Head <
        (testmodel_1109_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
       (testmodel_1109_DW.TransportDelay_IWORK.Head+1) : 0);
    if (testmodel_1109_DW.TransportDelay_IWORK.Head ==
        testmodel_1109_DW.TransportDelay_IWORK.Tail) {
      testmodel_1109_DW.TransportDelay_IWORK.Tail =
        ((testmodel_1109_DW.TransportDelay_IWORK.Tail <
          (testmodel_1109_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
         (testmodel_1109_DW.TransportDelay_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[testmodel_1109_DW.TransportDelay_IWORK.Head] = simTime;
    (*uBuffer)[testmodel_1109_DW.TransportDelay_IWORK.Head] =
      testmodel_1109_B.Product;
  }

  /* Update for UnitDelay: '<S5>/Delay Input1' */
  testmodel_1109_DW.DelayInput1_DSTATE = 0.0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++testmodel_1109_M->Timing.clockTick0)) {
    ++testmodel_1109_M->Timing.clockTickH0;
  }

  testmodel_1109_M->Timing.t[0] = testmodel_1109_M->Timing.clockTick0 *
    testmodel_1109_M->Timing.stepSize0 + testmodel_1109_M->Timing.clockTickH0 *
    testmodel_1109_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.004s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++testmodel_1109_M->Timing.clockTick1)) {
      ++testmodel_1109_M->Timing.clockTickH1;
    }

    testmodel_1109_M->Timing.t[1] = testmodel_1109_M->Timing.clockTick1 *
      testmodel_1109_M->Timing.stepSize1 + testmodel_1109_M->Timing.clockTickH1 *
      testmodel_1109_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void testmodel_1109_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  testmodel_1109_DW.clockTickCounter = -2500;

  /* Start for Triggered SubSystem: '<S1>/CANSend' */

  /* S-Function Block: <S18>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(11)) == 0) {
      if ((i = rl32eDefScope(11,2)) != 0) {
        printf("Error creating scope 11\n");
      } else {
        rl32eAddSignal(11, rl32eGetSignalNo("ck"));
        rl32eSetScope(11, 4, 12500);
        rl32eSetScope(11, 5, 0);
        rl32eSetScope(11, 6, 1);
        rl32eSetScope(11, 0, 0);
        rl32eSetScope(11, 3, rl32eGetSignalNo("ck"));
        rl32eSetScope(11, 1, 0.0);
        rl32eSetScope(11, 2, 0);
        rl32eSetScope(11, 9, 0);
        rl32eSetTargetScope(11, 1, 2.0);
        rl32eSetTargetScope(11, 11, -0.0);
        rl32eSetTargetScope(11, 10, 0.0);
        xpceScopeAcqOK(11, &testmodel_1109_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(11);
    }
  }

  /* Start for Triggered SubSystem: '<S15>/J-K Flip-Flop' */
  /* VirtualOutportStart for Outport: '<S20>/Q' */
  testmodel_1109_B.Logic[0] = testmodel_1109_P.Q_Y0;

  /* VirtualOutportStart for Outport: '<S20>/!Q' */
  testmodel_1109_B.OutportBufferForQ = testmodel_1109_P.Q_Y0_a;

  /* End of Start for SubSystem: '<S15>/J-K Flip-Flop' */
  /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Write (v3)1' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("IO601/Data Type Conversion1"));
        rl32eAddSignal(3, rl32eGetSignalNo("IO601/Data Type Conversion"));
        rl32eAddSignal(3, rl32eGetSignalNo("IO601/Data Type Conversion2"));
        rl32eSetScope(3, 4, 12500);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("IO601/Data Type Conversion1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 2.0);
        rl32eSetTargetScope(3, 11, -20000.0);
        rl32eSetTargetScope(3, 10, 20000.0);
        xpceScopeAcqOK(3, &testmodel_1109_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("IO601/Counter/p1"));
        rl32eSetScope(2, 4, 12500);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("IO601/Counter/p1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 2.0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 0.0);
        xpceScopeAcqOK(2, &testmodel_1109_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("IO601/Data Type Conversion1"));
        rl32eAddSignal(1, rl32eGetSignalNo("IO601/Data Type Conversion"));
        rl32eSetScope(1, 4, 12500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "pos_vel.dat", 1, 512, 0, 536870912);
        rl32eSetScope (1, 10, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("IO601/Data Type Conversion1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1, &testmodel_1109_DW.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S11>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,3)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Counter/p1"));
        rl32eSetScope(4, 4, 12500);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        xpceFSScopeSet(4, "impulse.dat", 1, 512, 0, 536870912);
        rl32eSetScope (4, 10, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Counter/p1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        xpceScopeAcqOK(4, &testmodel_1109_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S12>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,3)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("IO601/Subtract"));
        rl32eSetScope(6, 4, 12500);
        rl32eSetScope(6, 5, 0);
        rl32eSetScope(6, 6, 1);
        rl32eSetScope(6, 0, 0);
        xpceFSScopeSet(6, "ackdiff.dat", 1, 512, 0, 536870912);
        rl32eSetScope (6, 10, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("IO601/Subtract"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 9, 0);
        xpceScopeAcqOK(6, &testmodel_1109_DW.SFunction_IWORK_bv.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* S-Function Block: <S13>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Counter/p1"));
        rl32eSetScope(7, 4, 12500);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 1);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Counter/p1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 2.0);
        rl32eSetTargetScope(7, 11, -20000.0);
        rl32eSetTargetScope(7, 10, 20000.0);
        xpceScopeAcqOK(7, &testmodel_1109_DW.SFunction_IWORK_oz.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Iterator SubSystem: '<S7>/For Iterator Subsystem' */

  /*-----------S-Function Block: <S26>/CAN Unpack2 -----------------*/

  /*-----------S-Function Block: <S26>/CAN Unpack3 -----------------*/

  /* S-Function Block: <S30>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,3)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Detect Increase/FixPt Relational Operator"));
        rl32eSetScope(5, 4, 12500);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        xpceFSScopeSet(5, "impulse1.dat", 1, 512, 0, 536870912);
        rl32eSetScope (5, 10, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Detect Increase/FixPt Relational Operator"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        xpceScopeAcqOK(5, &testmodel_1109_DW.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* S-Function Block: <S31>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(10)) == 0) {
      if ((i = rl32eDefScope(10,2)) != 0) {
        printf("Error creating scope 10\n");
      } else {
        rl32eAddSignal(10, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Data Type Conversion"));
        rl32eAddSignal(10, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Counter/p1"));
        rl32eSetScope(10, 4, 12500);
        rl32eSetScope(10, 5, 0);
        rl32eSetScope(10, 6, 1);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Data Type Conversion"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 9, 0);
        rl32eSetTargetScope(10, 1, 2.0);
        rl32eSetTargetScope(10, 11, 0.0);
        rl32eSetTargetScope(10, 10, 0.0);
        xpceScopeAcqOK(10, &testmodel_1109_DW.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /*-----------S-Function Block: <S28>/CAN Unpack1 -----------------*/

  /* End of Start for SubSystem: '<S7>/For Iterator Subsystem' */

  /* InitializeConditions for Iterator SubSystem: '<S7>/For Iterator Subsystem' */
  /* InitializeConditions for MATLAB Function: '<S26>/MATLAB Function1' */
  testmodel_1109_DW.pos[0] = 0.0;
  testmodel_1109_DW.vel[0] = 0.0;
  testmodel_1109_DW.pos[1] = 0.0;
  testmodel_1109_DW.vel[1] = 0.0;
  testmodel_1109_DW.pos[2] = 0.0;
  testmodel_1109_DW.vel[2] = 0.0;
  testmodel_1109_DW.pos[3] = 0.0;
  testmodel_1109_DW.vel[3] = 0.0;

  /* InitializeConditions for UnitDelay: '<S29>/Delay Input1' */
  testmodel_1109_DW.DelayInput1_DSTATE_h = testmodel_1109_P.DetectIncrease_vinit;

  /* InitializeConditions for S-Function (sdspcount2): '<S28>/Counter' */
  testmodel_1109_DW.Counter_ClkEphState_g = 5U;
  testmodel_1109_DW.Counter_RstEphState = 5U;
  testmodel_1109_DW.Counter_Count = testmodel_1109_P.Counter_InitialCount;

  /* End of InitializeConditions for SubSystem: '<S7>/For Iterator Subsystem' */

  /* Start for Iterator SubSystem: '<S7>/For Iterator Subsystem' */
  /* VirtualOutportStart for Outport: '<S26>/ACK_TS' */
  testmodel_1109_B.Counter_o1_i = testmodel_1109_P.ACK_TS_Y0;

  /* VirtualOutportStart for Outport: '<S26>/pos' */
  testmodel_1109_B.OutportBufferForpos = testmodel_1109_P.pos_Y0;

  /* VirtualOutportStart for Outport: '<S26>/vel' */
  testmodel_1109_B.OutportBufferForvel = testmodel_1109_P.vel_Y0;

  /* End of Start for SubSystem: '<S7>/For Iterator Subsystem' */

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  testmodel_1109_DW.clockTickCounter_g = -2500;

  /* Start for TransportDelay: '<S1>/Transport Delay' */
  {
    real_T *pBuffer = &testmodel_1109_DW.TransportDelay_RWORK.TUbufferArea[0];
    testmodel_1109_DW.TransportDelay_IWORK.Tail = 0;
    testmodel_1109_DW.TransportDelay_IWORK.Head = 0;
    testmodel_1109_DW.TransportDelay_IWORK.Last = 0;
    testmodel_1109_DW.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = testmodel_1109_P.TransportDelay_InitOutput;
    pBuffer[1024] = testmodel_1109_M->Timing.t[0];
    testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    testmodel_1109_DW.TransportDelay_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [1024];
  }

  /* Start for Constant: '<S4>/Constant' */
  testmodel_1109_B.Constant_d = testmodel_1109_P.Constant_Value;

  /* Level2 S-Function Block: '<S4>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/DefaultConfig' */

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  testmodel_1109_DW.clockTickCounter_c = -2500;

  /* Start for Constant: '<S23>/Constant1' */
  testmodel_1109_B.Constant1_n = testmodel_1109_P.Constant1_Value_m;

  /* Level2 S-Function Block: '<S23>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S6>/GetState(ms)' */
  /* Start for Constant: '<S24>/Constant' */
  testmodel_1109_B.Constant = testmodel_1109_P.Constant_Value_a;

  /* Level2 S-Function Block: '<S24>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S6>/InitialPosition' */
  /* Start for Constant: '<S25>/Constant1' */
  testmodel_1109_B.Constant1 = testmodel_1109_P.Constant1_Value_i1;

  /* Level2 S-Function Block: '<S25>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S6>/QuitError' */
  testmodel_1109_PrevZCX.JKFlipFlop_Trig_ZCE = ZERO_ZCSIG;
  testmodel_1109_PrevZCX.CANSend_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.DefaultConfig_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.GetStatems_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.InitialPosition_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.QuitError_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for S-Function (sdspcount2): '<S1>/Counter' */
  testmodel_1109_DW.Counter_ClkEphState = 5U;
  testmodel_1109_DW.Counter_Count_p = testmodel_1109_P.Counter_InitialCount_h;

  /* InitializeConditions for Triggered SubSystem: '<S1>/CANSend' */
  /* InitializeConditions for Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport1' */
  testmodel_1109_DW.TmpLatchAtJKFlipFlopInport1_Pre =
    testmodel_1109_P.TmpLatchAtJKFlipFlopInport1_X0;

  /* InitializeConditions for Memory: '<S15>/TmpLatchAtJ-K Flip-FlopInport2' */
  testmodel_1109_DW.TmpLatchAtJKFlipFlopInport2_Pre =
    testmodel_1109_P.TmpLatchAtJKFlipFlopInport2_X0;

  /* InitializeConditions for Triggered SubSystem: '<S15>/J-K Flip-Flop' */
  /* InitializeConditions for Memory: '<S20>/Memory' */
  testmodel_1109_DW.Memory_PreviousInput = testmodel_1109_P.Memory_X0;

  /* End of InitializeConditions for SubSystem: '<S15>/J-K Flip-Flop' */
  /* End of InitializeConditions for SubSystem: '<S1>/CANSend' */

  /* InitializeConditions for S-Function (sdspcount2): '<S1>/Counter1' */
  testmodel_1109_DW.Counter1_ClkEphState = 5U;
  testmodel_1109_DW.Counter1_RstEphState = 5U;
  testmodel_1109_DW.Counter1_Count = testmodel_1109_P.Counter1_InitialCount;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  testmodel_1109_DW.DiscreteTimeIntegrator_DSTATE =
    testmodel_1109_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S5>/Delay Input1' */
  testmodel_1109_DW.DelayInput1_DSTATE = testmodel_1109_P.DetectIncrease_vinit_k;
}

/* Model terminate function */
static void testmodel_1109_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<S1>/CANSend' */

  /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Write (v3)1' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/CANSend' */

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<S1>/DefaultConfig' */

  /* Level2 S-Function Block: '<S4>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/DefaultConfig' */

  /* Terminate for Triggered SubSystem: '<S6>/GetState(ms)' */

  /* Level2 S-Function Block: '<S23>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S6>/GetState(ms)' */

  /* Terminate for Triggered SubSystem: '<S6>/InitialPosition' */

  /* Level2 S-Function Block: '<S24>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S6>/InitialPosition' */

  /* Terminate for Triggered SubSystem: '<S6>/QuitError' */

  /* Level2 S-Function Block: '<S25>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S6>/QuitError' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  testmodel_1109_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  testmodel_1109_update();
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
  testmodel_1109_initialize();
}

void MdlTerminate(void)
{
  testmodel_1109_terminate();
}

/* Registration function */
RT_MODEL_testmodel_1109_T *testmodel_1109(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testmodel_1109_M, 0,
                sizeof(RT_MODEL_testmodel_1109_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&testmodel_1109_M->solverInfo,
                          &testmodel_1109_M->Timing.simTimeStep);
    rtsiSetTPtr(&testmodel_1109_M->solverInfo, &rtmGetTPtr(testmodel_1109_M));
    rtsiSetStepSizePtr(&testmodel_1109_M->solverInfo,
                       &testmodel_1109_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&testmodel_1109_M->solverInfo, (&rtmGetErrorStatus
      (testmodel_1109_M)));
    rtsiSetRTModelPtr(&testmodel_1109_M->solverInfo, testmodel_1109_M);
  }

  rtsiSetSimTimeStep(&testmodel_1109_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&testmodel_1109_M->solverInfo,"FixedStepDiscrete");
  testmodel_1109_M->solverInfoPtr = (&testmodel_1109_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = testmodel_1109_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    testmodel_1109_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    testmodel_1109_M->Timing.sampleTimes =
      (&testmodel_1109_M->Timing.sampleTimesArray[0]);
    testmodel_1109_M->Timing.offsetTimes =
      (&testmodel_1109_M->Timing.offsetTimesArray[0]);

    /* task periods */
    testmodel_1109_M->Timing.sampleTimes[0] = (0.0);
    testmodel_1109_M->Timing.sampleTimes[1] = (0.004);

    /* task offsets */
    testmodel_1109_M->Timing.offsetTimes[0] = (0.0);
    testmodel_1109_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(testmodel_1109_M, &testmodel_1109_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = testmodel_1109_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    testmodel_1109_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(testmodel_1109_M, 50.0);
  testmodel_1109_M->Timing.stepSize0 = 0.004;
  testmodel_1109_M->Timing.stepSize1 = 0.004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    testmodel_1109_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(testmodel_1109_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(testmodel_1109_M->rtwLogInfo, (NULL));
    rtliSetLogT(testmodel_1109_M->rtwLogInfo, "tout");
    rtliSetLogX(testmodel_1109_M->rtwLogInfo, "");
    rtliSetLogXFinal(testmodel_1109_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(testmodel_1109_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(testmodel_1109_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(testmodel_1109_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(testmodel_1109_M->rtwLogInfo, 1);
    rtliSetLogY(testmodel_1109_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(testmodel_1109_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(testmodel_1109_M->rtwLogInfo, (NULL));
  }

  testmodel_1109_M->solverInfoPtr = (&testmodel_1109_M->solverInfo);
  testmodel_1109_M->Timing.stepSize = (0.004);
  rtsiSetFixedStepSize(&testmodel_1109_M->solverInfo, 0.004);
  rtsiSetSolverMode(&testmodel_1109_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  testmodel_1109_M->ModelData.blockIO = ((void *) &testmodel_1109_B);
  (void) memset(((void *) &testmodel_1109_B), 0,
                sizeof(B_testmodel_1109_T));

  {
    int32_T i;
    for (i = 0; i < 37; i++) {
      testmodel_1109_B.Readv3_o1[i] = CAN_DATATYPE_GROUND;
    }

    testmodel_1109_B.IndexVector = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_e = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2 = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack1 = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_j = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[0] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[1] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack1_n = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2_j = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[0] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[1] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2_p = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2_e = CAN_DATATYPE_GROUND;
  }

  /* parameters */
  testmodel_1109_M->ModelData.defaultParam = ((real_T *)&testmodel_1109_P);

  /* states (dwork) */
  testmodel_1109_M->ModelData.dwork = ((void *) &testmodel_1109_DW);
  (void) memset((void *)&testmodel_1109_DW, 0,
                sizeof(DW_testmodel_1109_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  testmodel_1109_InitializeDataMapInfo(testmodel_1109_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &testmodel_1109_M->NonInlinedSFcns.sfcnInfo;
    testmodel_1109_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(testmodel_1109_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &testmodel_1109_M->Sizes.numSampTimes);
    testmodel_1109_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (testmodel_1109_M)[0]);
    testmodel_1109_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (testmodel_1109_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,testmodel_1109_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(testmodel_1109_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(testmodel_1109_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (testmodel_1109_M));
    rtssSetStepSizePtr(sfcnInfo, &testmodel_1109_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(testmodel_1109_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &testmodel_1109_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &testmodel_1109_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &testmodel_1109_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &testmodel_1109_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &testmodel_1109_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &testmodel_1109_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &testmodel_1109_M->solverInfoPtr);
  }

  testmodel_1109_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&testmodel_1109_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  8*sizeof(SimStruct));
    testmodel_1109_M->childSfunctions =
      (&testmodel_1109_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        testmodel_1109_M->childSfunctions[i] =
          (&testmodel_1109_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: testmodel_1109/<S3>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               testmodel_1109_B.TmpSignalConversionAtWritev3I_j);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Product2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/CANSend/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_d5[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_d5[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S3>/Write (v3)1 (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack2_p);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Product_b);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)1");
      ssSetPath(rts, "testmodel_1109/IO601/CANSend/Write (v3)1");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev31_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev31_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev31_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev31_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev31_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev31_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev31_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev31_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev31_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev31_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev31_IWORK[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S4>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               testmodel_1109_B.TmpSignalConversionAtWritev3Inp);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant_d);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/DefaultConfig/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_a);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_h);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_d);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_b);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_k);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_d);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_d);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_e);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_p);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_l[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_l[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S23>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant1_n);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Initialize/GetState(ms)/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_a);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_k);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_d);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_p);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_b);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_g);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_o);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_p[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S24>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack_e);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts,
                "testmodel_1109/IO601/Initialize/InitialPosition/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_i);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_f);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_m);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_i);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_l);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_h);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_d[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S25>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Initialize/QuitError/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_p);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_f);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_a);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_g);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_d3);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_b);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_o);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_d);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_a);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel_1109/<S1>/Setup (v3) (sg_IO601_setup_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* path info */
      ssSetModelName(rts, "Setup (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Setup (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Setupv3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Setupv3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Setupv3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Setupv3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Setupv3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Setupv3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Setupv3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Setupv3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Setupv3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)testmodel_1109_P.Setupv3_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)testmodel_1109_P.Setupv3_P11_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Setupv3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Setupv3_IWORK[0]);
      }

      /* registration */
      sg_IO601_setup_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: testmodel_1109/<S1>/Read (v3) (sg_IO601_read_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 37);
          ssSetOutputPortSignal(rts, 0, ((CAN_DATATYPE *)
            testmodel_1109_B.Readv3_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &testmodel_1109_B.Readv3_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Read (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Read (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Readv3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Readv3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Readv3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Readv3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Readv3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Readv3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Readv3_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Readv3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel_1109_DW.Readv3_IWORK[0]);
      }

      /* registration */
      sg_IO601_read_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  testmodel_1109_M->Sizes.numContStates = (0);/* Number of continuous states */
  testmodel_1109_M->Sizes.numY = (0);  /* Number of model outputs */
  testmodel_1109_M->Sizes.numU = (0);  /* Number of model inputs */
  testmodel_1109_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  testmodel_1109_M->Sizes.numSampTimes = (2);/* Number of sample times */
  testmodel_1109_M->Sizes.numBlocks = (116);/* Number of blocks */
  testmodel_1109_M->Sizes.numBlockIO = (68);/* Number of block outputs */
  testmodel_1109_M->Sizes.numBlockPrms = (332);/* Sum of parameter "widths" */
  return testmodel_1109_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
