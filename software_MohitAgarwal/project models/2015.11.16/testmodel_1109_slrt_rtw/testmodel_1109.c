/*
 * testmodel_1109.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.173
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Nov 24 12:20:38 2015
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

/* Model output function */
static void testmodel_1109_output(void)
{
  real_T currentTime;
  uint32_T c;
  int32_T vel1;
  int32_T cur1;
  uint8_T mtmp;
  uint8_T x[4];
  ZCEventType zcEvent;
  int8_T s17_iter;
  int32_T i;
  uint8_T compare_idx_2;
  uint8_T compare_idx_1;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.DefaultConfig_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.GetStatems_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.InitialPosition_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.QuitError_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.PositionControl_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.ForIteratorSubsystem_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel_1109_DW.Velocitycontrol_SubsysRanBC);

  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
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

  /* Outputs for Triggered SubSystem: '<S1>/Velocity control' incorporates:
   *  TriggerPort: '<S11>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.Velocitycontrol_Trig_ZCE,
                     (testmodel_1109_B.Product));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S11>/MATLAB Function1' incorporates:
     *  Constant: '<S1>/Cur'
     */
    /* MATLAB Function 'IO601/Velocity control/MATLAB Function1': '<S28>:1' */
    /* '<S28>:1:4' */
    currentTime = rt_roundd_snf(sin(628.31853071795865 / testmodel_1109_B.Clock)
      * 100.0 + (real_T)testmodel_1109_P.Cur_Value);
    if (currentTime < 4.294967296E+9) {
      if (currentTime >= 0.0) {
        c = (uint32_T)currentTime;
      } else {
        c = 0U;
      }
    } else {
      c = MAX_uint32_T;
    }

    /* '<S28>:1:5' */
    memcpy(&testmodel_1109_B.cur[0], &c, (size_t)4 * sizeof(uint8_T));

    /* End of MATLAB Function: '<S11>/MATLAB Function1' */
    /*  if cp > 0 */
    /*      vel = 90000; */
    /*  else */
    /*      vel = -90000; */
    /*  end */
    /* S-Function (scanpack): '<S11>/CAN Pack' */
    testmodel_1109_B.CANPack.ID = 1283U;
    testmodel_1109_B.CANPack.Length = 8U;
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
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[2] =
                    testmodel_1109_B.CANPack.Data[2] | (uint8_T)((uint8_T)
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
          uint32_T packingValue = 0;

          {
            uint32_T result = (uint32_T) (testmodel_1109_P.vel_Value);

            /* no scaling required */
            packingValue = result;
          }

          {
            {
              int32_T packedValue;
              int32_T scaledValue;
              int32_T* pTemp = (int32_T*)(&(packingValue));
              scaledValue = *pTemp;
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
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[3] =
                    testmodel_1109_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[4] =
                    testmodel_1109_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[5] =
                    testmodel_1109_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[6] =
                    testmodel_1109_B.CANPack.Data[6] | (uint8_T)((uint8_T)
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
            uint32_T result = (uint32_T) (testmodel_1109_B.cur[0]);

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
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack.Data[7] =
                    testmodel_1109_B.CANPack.Data[7] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S11>/CAN Pack1' */
    testmodel_1109_B.CANPack1.ID = 1283U;
    testmodel_1109_B.CANPack1.Length = 5U;
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
            uint32_T result = (uint32_T) (testmodel_1109_B.cur[1]);

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
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[2] =
                    testmodel_1109_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
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
            uint32_T result = (uint32_T) (testmodel_1109_B.cur[2]);

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
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[3] =
                    testmodel_1109_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
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
            uint32_T result = (uint32_T) (testmodel_1109_B.cur[3]);

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
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1.Data[4] =
                    testmodel_1109_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S11>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[0] =
      testmodel_1109_B.CANPack;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[1] =
      testmodel_1109_B.CANPack1;

    /* Constant: '<S11>/Constant' */
    testmodel_1109_B.Constant = testmodel_1109_P.Constant_Value_b;

    /* Level2 S-Function Block: '<S11>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* S-Function (scanpack): '<S11>/CAN Pack2' */
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
            real64_T result = testmodel_1109_P.Constant5_Value_c;

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
            real64_T result = testmodel_1109_P.GetStateCmd_Value_p;

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
            real64_T result = testmodel_1109_P.Constant6_Value_a;

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

    testmodel_1109_DW.Velocitycontrol_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Velocity control' */
  /* ok to acquire for <S8>/S-Function */
  testmodel_1109_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S9>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_j.AcquireOK = 1;

  /* ok to acquire for <S10>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_p.AcquireOK = 1;

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[8];
    sfcnOutputs(rts, 1);
  }

  /* Outputs for Iterator SubSystem: '<S6>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S17>/For Iterator'
   */
  s17_iter = 1;
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

    if (s17_iter <= (currentTime < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                     -currentTime : (int32_T)(int8_T)(uint8_T)currentTime)) {
      testmodel_1109_B.ForIterator = s17_iter;

      /* ok to acquire for <S23>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_f.AcquireOK = 1;

      /* ok to acquire for <S24>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_h.AcquireOK = 1;

      /* ok to acquire for <S25>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_n.AcquireOK = 1;

      /* ok to acquire for <S26>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_h4.AcquireOK = 1;

      /* ok to acquire for <S27>/S-Function */
      testmodel_1109_DW.SFunction_IWORK_o.AcquireOK = 1;
      testmodel_1109_B.IndexVector =
        testmodel_1109_B.Readv3_o1[testmodel_1109_B.ForIterator - 1];

      /* S-Function (scanunpack): '<S17>/CAN Unpack' */
      {
        /* S-Function (scanunpack): '<S17>/CAN Unpack' */
        if ((8 == testmodel_1109_B.IndexVector.Length) &&
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
              /*
               * Signal is not connected or connected to terminator.
               * No unpacking code generated.
               */

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
                    testmodel_1109_B.CANUnpack_o2 = result;
                  }
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 16
               *  length                  = 32
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
                      int32_T unpackedValue = 0;

                      {
                        uint32_T tempValue = (uint32_T) (0);

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            0);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            1);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            2);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            3);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            4);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            5);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            6);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[2]) &
                                        (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            7);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            8);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            9);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            10);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            11);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            12);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            13);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            14);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[3]) &
                                        (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            15);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            16);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            17);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            18);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            19);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            20);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            21);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            22);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[4]) &
                                        (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            23);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            24);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            25);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            26);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            27);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            28);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            29);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            30);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel_1109_B.IndexVector.Data[5]) &
                                        (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            31);
                        }

                        unpackedValue = (int32_T) tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel_1109_B.CANUnpack_o3 = result;
                  }
                }
              }
            }
          }
        }
      }

      /* S-Function (scanunpack): '<S17>/CAN Unpack1' */
      {
        /* S-Function (scanunpack): '<S17>/CAN Unpack1' */
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
              /*
               * Signal is not connected or connected to terminator.
               * No unpacking code generated.
               */

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
          }
        }
      }

      /* S-Function (scanunpack): '<S17>/CAN Unpack2' */
      {
        /* S-Function (scanunpack): '<S17>/CAN Unpack2' */
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

      /* S-Function (scanunpack): '<S17>/CAN Unpack3' */
      {
        /* S-Function (scanunpack): '<S17>/CAN Unpack3' */
        if ((8 == testmodel_1109_B.IndexVector.Length) &&
            (testmodel_1109_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((1795U == testmodel_1109_B.IndexVector.ID) && (0U ==
               testmodel_1109_B.IndexVector.Extended) ) {
            (void) memcpy(&testmodel_1109_B.CANUnpack3[0],
                          testmodel_1109_B.IndexVector.Data,
                          8 * sizeof(uint8_T));
          }
        }
      }

      /* MATLAB Function 'IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function': '<S22>:1' */
      /* '<S22>:1:16' */
      compare_idx_1 = testmodel_1109_B.CANUnpack3[0];
      currentTime = rt_roundd_snf(testmodel_1109_DW.stitched[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_2 = (uint8_T)currentTime;
        } else {
          compare_idx_2 = 0U;
        }
      } else {
        compare_idx_2 = MAX_uint8_T;
      }

      /* '<S22>:1:17' */
      mtmp = 7U;
      if (compare_idx_1 > 7) {
        mtmp = compare_idx_1;
      }

      if (compare_idx_2 > mtmp) {
        mtmp = compare_idx_2;
      }

      testmodel_1109_DW.stitched[0] = mtmp;
      if ((testmodel_1109_B.CANUnpack3[2] == 149) ||
          (testmodel_1109_DW.stitched[1] == 149.0)) {
        /* '<S22>:1:18' */
        if (testmodel_1109_B.CANUnpack3[1] == 132) {
          /* '<S22>:1:19' */
          /* first fragment */
          /* '<S22>:1:20' */
          for (i = 0; i < 6; i++) {
            testmodel_1109_DW.stitched[i + 1] = testmodel_1109_B.CANUnpack3[i +
              2];
          }

          /* cmd 4pos 1vel */
          /* '<S22>:1:21' */
          testmodel_1109_DW.pos[0] = testmodel_1109_B.CANUnpack3[3];
          testmodel_1109_DW.pos[1] = testmodel_1109_B.CANUnpack3[4];
          testmodel_1109_DW.pos[2] = testmodel_1109_B.CANUnpack3[5];
          testmodel_1109_DW.pos[3] = testmodel_1109_B.CANUnpack3[6];

          /* '<S22>:1:22' */
          compare_idx_1 = testmodel_1109_B.CANUnpack3[7];
          if (compare_idx_1 > 127) {
            compare_idx_1 = 127U;
          }

          testmodel_1109_DW.vel[0] = compare_idx_1;
        } else if (testmodel_1109_B.CANUnpack3[1] == 133) {
          /* '<S22>:1:23' */
          /* middle fragment */
          /* '<S22>:1:24' */
          for (i = 0; i < 6; i++) {
            testmodel_1109_DW.stitched[i + 7] = testmodel_1109_B.CANUnpack3[i +
              2];
          }

          /* 3vel 3cur */
          /* '<S22>:1:25' */
          /* '<S22>:1:26' */
          testmodel_1109_DW.vel[1] = testmodel_1109_B.CANUnpack3[2];
          testmodel_1109_DW.cur[0] = testmodel_1109_B.CANUnpack3[5];
          testmodel_1109_DW.vel[2] = testmodel_1109_B.CANUnpack3[3];
          testmodel_1109_DW.cur[1] = testmodel_1109_B.CANUnpack3[6];
          testmodel_1109_DW.vel[3] = testmodel_1109_B.CANUnpack3[4];
          testmodel_1109_DW.cur[2] = testmodel_1109_B.CANUnpack3[7];
        } else if (testmodel_1109_B.CANUnpack3[1] == 134) {
          /* '<S22>:1:27' */
          /* last fragment */
          if (testmodel_1109_DW.stitched[0] > 13.0) {
            /* '<S22>:1:28' */
            /* '<S22>:1:29' */
            testmodel_1109_DW.stitched[13] = testmodel_1109_B.CANUnpack3[2];
            testmodel_1109_DW.stitched[14] = testmodel_1109_B.CANUnpack3[3];
            testmodel_1109_DW.stitched[15] = testmodel_1109_B.CANUnpack3[4];

            /* 1cur 2err */
            /* '<S22>:1:30' */
            testmodel_1109_DW.cur[3] = testmodel_1109_B.CANUnpack3[2];
          } else {
            /* '<S22>:1:32' */
            for (i = 0; i < 5; i++) {
              testmodel_1109_DW.stitched[i + 7] = testmodel_1109_B.CANUnpack3[i
                + 2];
            }

            /* 3vel 2err */
            /* '<S22>:1:33' */
            testmodel_1109_DW.vel[1] = testmodel_1109_B.CANUnpack3[2];
            testmodel_1109_DW.vel[2] = testmodel_1109_B.CANUnpack3[3];
            testmodel_1109_DW.vel[3] = testmodel_1109_B.CANUnpack3[4];
          }
        } else {
          if (testmodel_1109_B.CANUnpack3[1] == 149) {
            /* '<S22>:1:36' */
            /* no fragment */
            /* '<S22>:1:37' */
            for (i = 0; i < 7; i++) {
              testmodel_1109_DW.stitched[i + 1] = testmodel_1109_B.CANUnpack3[i
                + 1];
            }

            /* '<S22>:1:38' */
            testmodel_1109_DW.pos[0] = testmodel_1109_B.CANUnpack3[2];
            testmodel_1109_DW.pos[1] = testmodel_1109_B.CANUnpack3[3];
            testmodel_1109_DW.pos[2] = testmodel_1109_B.CANUnpack3[4];
            testmodel_1109_DW.pos[3] = testmodel_1109_B.CANUnpack3[5];
          }
        }
      }

      /* '<S22>:1:41' */
      /* '<S22>:1:43' */
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[0] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[1]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[1] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[2]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[2] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.pos[3]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[3] = compare_idx_1;
      memcpy(&i, &x[0], (size_t)1 * sizeof(int32_T));

      /* '<S22>:1:44' */
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[0] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[1]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[1] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[2]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[2] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.vel[3]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[3] = compare_idx_1;
      memcpy(&vel1, &x[0], (size_t)1 * sizeof(int32_T));

      /* '<S22>:1:45' */
      currentTime = rt_roundd_snf(testmodel_1109_DW.cur[0]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[0] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.cur[1]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[1] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.cur[2]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[2] = compare_idx_1;
      currentTime = rt_roundd_snf(testmodel_1109_DW.cur[3]);
      if (currentTime < 256.0) {
        if (currentTime >= 0.0) {
          compare_idx_1 = (uint8_T)currentTime;
        } else {
          compare_idx_1 = 0U;
        }
      } else {
        compare_idx_1 = MAX_uint8_T;
      }

      x[3] = compare_idx_1;
      memcpy(&cur1, &x[0], (size_t)1 * sizeof(int32_T));

      /* '<S22>:1:47' */
      /* '<S22>:1:48' */
      /*  vel = 0; */
      /*  pos1 = [0 0 0 0]; */
      /*  vel1 = [0 0 0 0]; */
      /*  if u(2) == hex2dec('84')            %first fragment */
      /*      pos1 = u(4:7); vel1(1) = u(8); */
      /*  elseif u(2) == hex2dec('85')        %middle fragment */
      /*       */
      /*  elseif u(2) == hex2dec('86')        %last fragment */
      /*      vel1(2:4) = u(3:5); */
      /*  elseif u(2) == hex2dec('95')        %no fragment */
      /*      pos1 = u(3:6); */
      /*  end */
      /*   */
      /*  pos = typecast(uint8(pos1), 'uint32'); */
      /*  vel = typecast(uint8(vel1), 'uint32'); */
      /*   */
      memcpy(&testmodel_1109_B.frame[0], &testmodel_1109_DW.stitched[0], sizeof
             (real_T) << 4U);
      testmodel_1109_B.state[0] = i;
      testmodel_1109_B.state[1] = vel1;
      testmodel_1109_B.state[2] = cur1;
      srUpdateBC(testmodel_1109_DW.ForIteratorSubsystem_SubsysRanB);
      s17_iter++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<S6>/For Iterator Subsystem' */

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  testmodel_1109_B.TSamp = testmodel_1109_B.CANUnpack_o3 *
    testmodel_1109_P.TSamp_WtEt;

  /* UnitDelay: '<S3>/UD' */
  testmodel_1109_B.Uk1 = testmodel_1109_DW.UD_DSTATE;

  /* Sum: '<S3>/Diff' */
  testmodel_1109_B.Diff = testmodel_1109_B.TSamp - testmodel_1109_B.Uk1;

  /* ok to acquire for <S19>/S-Function */
  testmodel_1109_DW.SFunction_IWORK_l.AcquireOK = 1;

  /* UnitDelay: '<S16>/Output' */
  testmodel_1109_B.Output = testmodel_1109_DW.Output_DSTATE;

  /* Sum: '<S20>/FixPt Sum1' incorporates:
   *  Constant: '<S20>/FixPt Constant'
   */
  testmodel_1109_B.FixPtSum1 = (uint8_T)((uint8_T)((uint32_T)
    testmodel_1109_B.Output + testmodel_1109_P.FixPtConstant_Value) & 3);

  /* Switch: '<S21>/FixPt Switch' incorporates:
   *  Constant: '<S21>/Constant'
   */
  if (testmodel_1109_B.FixPtSum1 > testmodel_1109_P.WrapToZero_Threshold) {
    testmodel_1109_B.FixPtSwitch = testmodel_1109_P.Constant_Value_f;
  } else {
    testmodel_1109_B.FixPtSwitch = testmodel_1109_B.FixPtSum1;
  }

  /* End of Switch: '<S21>/FixPt Switch' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'IO601/ReadQueueSS/MATLAB Function': '<S18>:1' */
  /* '<S18>:1:3' */
  testmodel_1109_B.noAck = 0.0;

  /* Step: '<S1>/Step2' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step2_Time) {
    testmodel_1109_B.Step2 = testmodel_1109_P.Step2_Y0;
  } else {
    testmodel_1109_B.Step2 = testmodel_1109_P.Step2_YFinal;
  }

  /* End of Step: '<S1>/Step2' */

  /* Outputs for Triggered SubSystem: '<S1>/PositionControl ' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.PositionControl_Trig_ZCE,
                     (testmodel_1109_B.Step2));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S5>/CAN Pack' */
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
            real64_T result = testmodel_1109_P.Constant1_Value_c;

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
            real64_T result = testmodel_1109_P.Constant2_Value_d;

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

    /* Constant: '<S5>/Constant' */
    testmodel_1109_B.Constant_d = testmodel_1109_P.Constant_Value_e;

    /* Level2 S-Function Block: '<S5>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.PositionControl_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/PositionControl ' */

  /* Outputs for Atomic SubSystem: '<S1>/STOP' */
  /* S-Function (scanpack): '<S7>/CAN Pack2' */
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
          real64_T result = testmodel_1109_P.DataLen_Value_k;

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
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[0] =
                  testmodel_1109_B.CANPack2_p.Data[0] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
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
          real64_T result = testmodel_1109_P.GetStateCmd_Value_d;

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
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >> 0)<<
                  0);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >> 1)<<
                  1);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >> 2)<<
                  2);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >> 3)<<
                  3);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >> 4)<<
                  4);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >> 5)<<
                  5);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >> 6)<<
                  6);
              }

              {
                testmodel_1109_B.CANPack2_p.Data[1] =
                  testmodel_1109_B.CANPack2_p.Data[1] | (uint8_T)((uint8_T)
                  ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >> 7)<<
                  7);
              }
            }
          }
        }
      }
    }
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  testmodel_1109_B.Product_l = testmodel_1109_P.Constant1_Value_e * 0.0;

  /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[5];
    sfcnOutputs(rts, 1);
  }

  /* End of Outputs for SubSystem: '<S1>/STOP' */

  /* Step: '<S1>/Step1' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step1_Time) {
    testmodel_1109_B.Step1 = testmodel_1109_P.Step1_Y0;
  } else {
    testmodel_1109_B.Step1 = testmodel_1109_P.Step1_YFinal;
  }

  /* End of Step: '<S1>/Step1' */

  /* Step: '<S4>/Step5' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step5_Time) {
    testmodel_1109_B.Step5 = testmodel_1109_P.Step5_Y0;
  } else {
    testmodel_1109_B.Step5 = testmodel_1109_P.Step5_YFinal;
  }

  /* End of Step: '<S4>/Step5' */

  /* Outputs for Triggered SubSystem: '<S4>/DefaultConfig' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.DefaultConfig_Trig_ZCE,
                     (testmodel_1109_B.Step5));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S12>/CAN Pack1' */
    testmodel_1109_B.CANPack1_m.ID = 1283U;
    testmodel_1109_B.CANPack1_m.Length = 6U;
    testmodel_1109_B.CANPack1_m.Extended = 0U;
    testmodel_1109_B.CANPack1_m.Remote = 0;
    testmodel_1109_B.CANPack1_m.Data[0] = 0;
    testmodel_1109_B.CANPack1_m.Data[1] = 0;
    testmodel_1109_B.CANPack1_m.Data[2] = 0;
    testmodel_1109_B.CANPack1_m.Data[3] = 0;
    testmodel_1109_B.CANPack1_m.Data[4] = 0;
    testmodel_1109_B.CANPack1_m.Data[5] = 0;
    testmodel_1109_B.CANPack1_m.Data[6] = 0;
    testmodel_1109_B.CANPack1_m.Data[7] = 0;

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
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[0] =
                    testmodel_1109_B.CANPack1_m.Data[0] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[1] =
                    testmodel_1109_B.CANPack1_m.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel_1109_P.Constant6_Value;

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
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[2] =
                    testmodel_1109_B.CANPack1_m.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[3] =
                    testmodel_1109_B.CANPack1_m.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[4] =
                    testmodel_1109_B.CANPack1_m.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack1_m.Data[5] =
                    testmodel_1109_B.CANPack1_m.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S12>/CAN Pack' */
    testmodel_1109_B.CANPack_jw.ID = 1283U;
    testmodel_1109_B.CANPack_jw.Length = 6U;
    testmodel_1109_B.CANPack_jw.Extended = 0U;
    testmodel_1109_B.CANPack_jw.Remote = 0;
    testmodel_1109_B.CANPack_jw.Data[0] = 0;
    testmodel_1109_B.CANPack_jw.Data[1] = 0;
    testmodel_1109_B.CANPack_jw.Data[2] = 0;
    testmodel_1109_B.CANPack_jw.Data[3] = 0;
    testmodel_1109_B.CANPack_jw.Data[4] = 0;
    testmodel_1109_B.CANPack_jw.Data[5] = 0;
    testmodel_1109_B.CANPack_jw.Data[6] = 0;
    testmodel_1109_B.CANPack_jw.Data[7] = 0;

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
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[0] =
                    testmodel_1109_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[1] =
                    testmodel_1109_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel_1109_P.Constant5_Value;

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
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[2] =
                    testmodel_1109_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[3] =
                    testmodel_1109_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[4] =
                    testmodel_1109_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel_1109_B.CANPack_jw.Data[5] =
                    testmodel_1109_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S12>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[0] =
      testmodel_1109_B.CANPack1_m;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[1] =
      testmodel_1109_B.CANPack_jw;

    /* Constant: '<S12>/Constant' */
    testmodel_1109_B.Constant_dc = testmodel_1109_P.Constant_Value;

    /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.DefaultConfig_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S4>/DefaultConfig' */

  /* Step: '<S4>/Step1' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step1_Time_g) {
    testmodel_1109_B.Step1_b = testmodel_1109_P.Step1_Y0_m;
  } else {
    testmodel_1109_B.Step1_b = testmodel_1109_P.Step1_YFinal_h;
  }

  /* End of Step: '<S4>/Step1' */

  /* Outputs for Triggered SubSystem: '<S4>/GetState(ms)' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.GetStatems_Trig_ZCE,
                     (testmodel_1109_B.Step1_b));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S13>/CAN Pack2' */
    testmodel_1109_B.CANPack2_b.ID = 1283U;
    testmodel_1109_B.CANPack2_b.Length = 7U;
    testmodel_1109_B.CANPack2_b.Extended = 0U;
    testmodel_1109_B.CANPack2_b.Remote = 0;
    testmodel_1109_B.CANPack2_b.Data[0] = 0;
    testmodel_1109_B.CANPack2_b.Data[1] = 0;
    testmodel_1109_B.CANPack2_b.Data[2] = 0;
    testmodel_1109_B.CANPack2_b.Data[3] = 0;
    testmodel_1109_B.CANPack2_b.Data[4] = 0;
    testmodel_1109_B.CANPack2_b.Data[5] = 0;
    testmodel_1109_B.CANPack2_b.Data[6] = 0;
    testmodel_1109_B.CANPack2_b.Data[7] = 0;

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
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[0] =
                    testmodel_1109_B.CANPack2_b.Data[0] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[1] =
                    testmodel_1109_B.CANPack2_b.Data[1] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[2] =
                    testmodel_1109_B.CANPack2_b.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 10))
                     >> 10)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 11))
                     >> 11)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 12))
                     >> 12)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 13))
                     >> 13)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 14))
                     >> 14)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[3] =
                    testmodel_1109_B.CANPack2_b.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 15))
                     >> 15)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 16))
                     >> 16)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 17))
                     >> 17)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 18))
                     >> 18)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 19))
                     >> 19)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 20))
                     >> 20)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 21))
                     >> 21)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 22))
                     >> 22)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[4] =
                    testmodel_1109_B.CANPack2_b.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 23))
                     >> 23)<<7);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 24))
                     >> 24)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 25))
                     >> 25)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 26))
                     >> 26)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 27))
                     >> 27)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 28))
                     >> 28)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 29))
                     >> 29)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 30))
                     >> 30)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[5] =
                    testmodel_1109_B.CANPack2_b.Data[5] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack2_b.Data[6] =
                    testmodel_1109_B.CANPack2_b.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S13>/Constant1' */
    testmodel_1109_B.Constant1_n = testmodel_1109_P.Constant1_Value_m;

    /* Level2 S-Function Block: '<S13>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.GetStatems_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S4>/GetState(ms)' */

  /* Step: '<S4>/Step3' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step3_Time) {
    testmodel_1109_B.Step3 = testmodel_1109_P.Step3_Y0;
  } else {
    testmodel_1109_B.Step3 = testmodel_1109_P.Step3_YFinal;
  }

  /* End of Step: '<S4>/Step3' */

  /* Outputs for Triggered SubSystem: '<S4>/InitialPosition' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.InitialPosition_Trig_ZCE,
                     (testmodel_1109_B.Step3));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S14>/CAN Pack' */
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

    /* Constant: '<S14>/Constant' */
    testmodel_1109_B.Constant_i = testmodel_1109_P.Constant_Value_a;

    /* Level2 S-Function Block: '<S14>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.InitialPosition_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S4>/InitialPosition' */

  /* Step: '<S4>/Step' */
  currentTime = testmodel_1109_M->Timing.t[1];
  if (currentTime < testmodel_1109_P.Step_Time) {
    testmodel_1109_B.Step = testmodel_1109_P.Step_Y0;
  } else {
    testmodel_1109_B.Step = testmodel_1109_P.Step_YFinal;
  }

  /* End of Step: '<S4>/Step' */

  /* Outputs for Triggered SubSystem: '<S4>/QuitError' incorporates:
   *  TriggerPort: '<S15>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel_1109_PrevZCX.QuitError_Trig_ZCE,
                     (testmodel_1109_B.Step));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S15>/CAN Pack' */
    testmodel_1109_B.CANPack_o.ID = 1283U;
    testmodel_1109_B.CANPack_o.Length = 2U;
    testmodel_1109_B.CANPack_o.Extended = 0U;
    testmodel_1109_B.CANPack_o.Remote = 0;
    testmodel_1109_B.CANPack_o.Data[0] = 0;
    testmodel_1109_B.CANPack_o.Data[1] = 0;
    testmodel_1109_B.CANPack_o.Data[2] = 0;
    testmodel_1109_B.CANPack_o.Data[3] = 0;
    testmodel_1109_B.CANPack_o.Data[4] = 0;
    testmodel_1109_B.CANPack_o.Data[5] = 0;
    testmodel_1109_B.CANPack_o.Data[6] = 0;
    testmodel_1109_B.CANPack_o.Data[7] = 0;

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
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[0] =
                    testmodel_1109_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
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
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel_1109_B.CANPack_o.Data[1] =
                    testmodel_1109_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S15>/Constant1' */
    testmodel_1109_B.Constant1 = testmodel_1109_P.Constant1_Value_i1;

    /* Level2 S-Function Block: '<S15>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel_1109_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    testmodel_1109_DW.QuitError_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S4>/QuitError' */
}

/* Model update function */
static void testmodel_1109_update(void)
{
  /* Update for UnitDelay: '<S3>/UD' */
  testmodel_1109_DW.UD_DSTATE = testmodel_1109_B.TSamp;

  /* Update for UnitDelay: '<S16>/Output' */
  testmodel_1109_DW.Output_DSTATE = testmodel_1109_B.FixPtSwitch;

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
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  testmodel_1109_DW.clockTickCounter = -2500;

  /* Start for Constant: '<S11>/Constant' */
  testmodel_1109_B.Constant = testmodel_1109_P.Constant_Value_b;

  /* Level2 S-Function Block: '<S11>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[6];
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
        rl32eAddSignal(3, rl32eGetSignalNo("IO601/Discrete Derivative/Diff"));
        rl32eSetScope(3, 4, 12500);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("IO601/Discrete Derivative/Diff"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 2.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 0.0);
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
    if ((i = rl32eScopeExists(12)) == 0) {
      if ((i = rl32eDefScope(12,2)) != 0) {
        printf("Error creating scope 12\n");
      } else {
        rl32eAddSignal(12, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p3"));
        rl32eSetTargetScopeSigFt(12,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p3"),"%15.6f");
        rl32eSetScope(12, 4, 12500);
        rl32eSetScope(12, 5, 0);
        rl32eSetScope(12, 6, 1);
        rl32eSetScope(12, 0, 0);
        rl32eSetScope(12, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p3"));
        rl32eSetScope(12, 1, 0.0);
        rl32eSetScope(12, 2, 0);
        rl32eSetScope(12, 9, 0);
        rl32eSetTargetScope(12, 1, 0.0);
        rl32eSetTargetScope(12, 11, 0.0);
        rl32eSetTargetScope(12, 10, 0.0);
        xpceScopeAcqOK(12, &testmodel_1109_DW.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(12);
    }
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"));
        rl32eSetScope(2, 4, 12500);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 2.0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 0.0);
        xpceScopeAcqOK(2, &testmodel_1109_DW.SFunction_IWORK_p.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Iterator SubSystem: '<S6>/For Iterator Subsystem' */

  /* S-Function Block: <S23>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"),"%15.6f");
        rl32eSetScope(1, 4, 12500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -90000.0);
        rl32eSetTargetScope(1, 10, 90000.0);
        xpceScopeAcqOK(1, &testmodel_1109_DW.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S24>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(10)) == 0) {
      if ((i = rl32eDefScope(10,2)) != 0) {
        printf("Error creating scope 10\n");
      } else {
        rl32eAddSignal(10, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p2"));
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p2"),"%15.6f");
        rl32eSetScope(10, 4, 12500);
        rl32eSetScope(10, 5, 0);
        rl32eSetScope(10, 6, 1);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p2"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 9, 0);
        rl32eSetTargetScope(10, 1, 0.0);
        rl32eSetTargetScope(10, 11, -90000.0);
        rl32eSetTargetScope(10, 10, 90000.0);
        xpceScopeAcqOK(10, &testmodel_1109_DW.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* S-Function Block: <S25>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(31)) == 0) {
      if ((i = rl32eDefScope(31,2)) != 0) {
        printf("Error creating scope 31\n");
      } else {
        rl32eAddSignal(31, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p2/s1"));
        rl32eAddSignal(31, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p2/s2"));
        rl32eAddSignal(31, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p2/s3"));
        rl32eSetScope(31, 4, 12500);
        rl32eSetScope(31, 5, 0);
        rl32eSetScope(31, 6, 1);
        rl32eSetScope(31, 0, 0);
        rl32eSetScope(31, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p2/s1"));
        rl32eSetScope(31, 1, 0.0);
        rl32eSetScope(31, 2, 0);
        rl32eSetScope(31, 9, 0);
        rl32eSetTargetScope(31, 1, 2.0);
        rl32eSetTargetScope(31, 11, -90000.0);
        rl32eSetTargetScope(31, 10, 90000.0);
        xpceScopeAcqOK(31, &testmodel_1109_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(31);
    }
  }

  /* S-Function Block: <S26>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(33)) == 0) {
      if ((i = rl32eDefScope(33,2)) != 0) {
        printf("Error creating scope 33\n");
      } else {
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s1"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s2"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s3"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s4"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s5"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s6"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s7"));
        rl32eAddSignal(33, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s8"));
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s1"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s4"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s5"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s6"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s7"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(33,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s8"),
          "%15.6f");
        rl32eSetScope(33, 4, 12500);
        rl32eSetScope(33, 5, 0);
        rl32eSetScope(33, 6, 1);
        rl32eSetScope(33, 0, 0);
        rl32eSetScope(33, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s1"));
        rl32eSetScope(33, 1, 0.0);
        rl32eSetScope(33, 2, 0);
        rl32eSetScope(33, 9, 0);
        rl32eSetTargetScope(33, 1, 0.0);
        rl32eSetTargetScope(33, 11, -90000.0);
        rl32eSetTargetScope(33, 10, 90000.0);
        xpceScopeAcqOK(33, &testmodel_1109_DW.SFunction_IWORK_h4.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(33);
    }
  }

  /* S-Function Block: <S27>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(34)) == 0) {
      if ((i = rl32eDefScope(34,2)) != 0) {
        printf("Error creating scope 34\n");
      } else {
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s9"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s10"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s11"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s12"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s13"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s14"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s15"));
        rl32eAddSignal(34, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s16"));
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s9"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s10"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s11"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s12"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s13"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s14"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s15"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(34,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s16"),
          "%15.6f");
        rl32eSetScope(34, 4, 12500);
        rl32eSetScope(34, 5, 0);
        rl32eSetScope(34, 6, 1);
        rl32eSetScope(34, 0, 0);
        rl32eSetScope(34, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1/s9"));
        rl32eSetScope(34, 1, 0.0);
        rl32eSetScope(34, 2, 0);
        rl32eSetScope(34, 9, 0);
        rl32eSetTargetScope(34, 1, 0.0);
        rl32eSetTargetScope(34, 11, -90000.0);
        rl32eSetTargetScope(34, 10, 90000.0);
        xpceScopeAcqOK(34, &testmodel_1109_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(34);
    }
  }

  /*-----------S-Function Block: <S17>/CAN Unpack -----------------*/

  /*-----------S-Function Block: <S17>/CAN Unpack1 -----------------*/

  /*-----------S-Function Block: <S17>/CAN Unpack2 -----------------*/

  /*-----------S-Function Block: <S17>/CAN Unpack3 -----------------*/

  /* End of Start for SubSystem: '<S6>/For Iterator Subsystem' */

  /* InitializeConditions for Iterator SubSystem: '<S6>/For Iterator Subsystem' */
  /* InitializeConditions for MATLAB Function: '<S17>/MATLAB Function' */
  memset(&testmodel_1109_DW.stitched[0], 0, sizeof(real_T) << 4U);
  testmodel_1109_DW.pos[0] = 0.0;
  testmodel_1109_DW.vel[0] = 0.0;
  testmodel_1109_DW.cur[0] = 0.0;
  testmodel_1109_DW.pos[1] = 0.0;
  testmodel_1109_DW.vel[1] = 0.0;
  testmodel_1109_DW.cur[1] = 0.0;
  testmodel_1109_DW.pos[2] = 0.0;
  testmodel_1109_DW.vel[2] = 0.0;
  testmodel_1109_DW.cur[2] = 0.0;
  testmodel_1109_DW.pos[3] = 0.0;
  testmodel_1109_DW.vel[3] = 0.0;
  testmodel_1109_DW.cur[3] = 0.0;

  /* End of InitializeConditions for SubSystem: '<S6>/For Iterator Subsystem' */

  /* Start for Iterator SubSystem: '<S6>/For Iterator Subsystem' */
  /* VirtualOutportStart for Outport: '<S17>/Out 1' */
  testmodel_1109_B.CANUnpack_o3 = testmodel_1109_P.Out1_Y0;

  /* VirtualOutportStart for Outport: '<S17>/Out 2' */
  testmodel_1109_B.CANUnpack1_o3 = testmodel_1109_P.Out2_Y0;

  /* End of Start for SubSystem: '<S6>/For Iterator Subsystem' */

  /* S-Function Block: <S19>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(21)) == 0) {
      if ((i = rl32eDefScope(21,2)) != 0) {
        printf("Error creating scope 21\n");
      } else {
        rl32eAddSignal(21, rl32eGetSignalNo("IO601/Read (v3)/p2"));
        rl32eSetTargetScopeSigFt(21,rl32eGetSignalNo("IO601/Read (v3)/p2"),
          "%15.6f");
        rl32eSetScope(21, 4, 12500);
        rl32eSetScope(21, 5, 0);
        rl32eSetScope(21, 6, 1);
        rl32eSetScope(21, 0, 0);
        rl32eSetScope(21, 3, rl32eGetSignalNo("IO601/Read (v3)/p2"));
        rl32eSetScope(21, 1, 0.0);
        rl32eSetScope(21, 2, 0);
        rl32eSetScope(21, 9, 0);
        rl32eSetTargetScope(21, 1, 0.0);
        rl32eSetTargetScope(21, 11, 0.0);
        rl32eSetTargetScope(21, 10, 0.0);
        xpceScopeAcqOK(21, &testmodel_1109_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(21);
    }
  }

  /* Start for Constant: '<S5>/Constant' */
  testmodel_1109_B.Constant_d = testmodel_1109_P.Constant_Value_e;

  /* Level2 S-Function Block: '<S5>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/PositionControl ' */

  /* Start for Atomic SubSystem: '<S1>/STOP' */

  /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/STOP' */

  /* Start for Constant: '<S12>/Constant' */
  testmodel_1109_B.Constant_dc = testmodel_1109_P.Constant_Value;

  /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S4>/DefaultConfig' */
  /* Start for Constant: '<S13>/Constant1' */
  testmodel_1109_B.Constant1_n = testmodel_1109_P.Constant1_Value_m;

  /* Level2 S-Function Block: '<S13>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S4>/GetState(ms)' */
  /* Start for Constant: '<S14>/Constant' */
  testmodel_1109_B.Constant_i = testmodel_1109_P.Constant_Value_a;

  /* Level2 S-Function Block: '<S14>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S4>/InitialPosition' */
  /* Start for Constant: '<S15>/Constant1' */
  testmodel_1109_B.Constant1 = testmodel_1109_P.Constant1_Value_i1;

  /* Level2 S-Function Block: '<S15>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S4>/QuitError' */
  testmodel_1109_PrevZCX.DefaultConfig_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.GetStatems_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.InitialPosition_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.QuitError_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.PositionControl_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel_1109_PrevZCX.Velocitycontrol_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  testmodel_1109_DW.UD_DSTATE = testmodel_1109_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S16>/Output' */
  testmodel_1109_DW.Output_DSTATE = testmodel_1109_P.Output_InitialCondition;
}

/* Model terminate function */
static void testmodel_1109_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<S1>/Velocity control' */

  /* Level2 S-Function Block: '<S11>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/Velocity control' */

  /* Level2 S-Function Block: '<S1>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<S1>/PositionControl ' */

  /* Level2 S-Function Block: '<S5>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/PositionControl ' */

  /* Terminate for Atomic SubSystem: '<S1>/STOP' */

  /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/STOP' */

  /* Terminate for Triggered SubSystem: '<S4>/DefaultConfig' */

  /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S4>/DefaultConfig' */

  /* Terminate for Triggered SubSystem: '<S4>/GetState(ms)' */

  /* Level2 S-Function Block: '<S13>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S4>/GetState(ms)' */

  /* Terminate for Triggered SubSystem: '<S4>/InitialPosition' */

  /* Level2 S-Function Block: '<S14>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S4>/InitialPosition' */

  /* Terminate for Triggered SubSystem: '<S4>/QuitError' */

  /* Level2 S-Function Block: '<S15>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel_1109_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S4>/QuitError' */
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

    testmodel_1109_B.CANPack = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack1 = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[0] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3Inp[1] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2 = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2_p = CAN_DATATYPE_GROUND;
    testmodel_1109_B.IndexVector = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_j = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_o = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_e = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack2_b = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack1_m = CAN_DATATYPE_GROUND;
    testmodel_1109_B.CANPack_jw = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[0] = CAN_DATATYPE_GROUND;
    testmodel_1109_B.TmpSignalConversionAtWritev3I_j[1] = CAN_DATATYPE_GROUND;
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

  testmodel_1109_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&testmodel_1109_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    testmodel_1109_M->childSfunctions =
      (&testmodel_1109_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        testmodel_1109_M->childSfunctions[i] =
          (&testmodel_1109_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: testmodel_1109/<S12>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant_dc);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Initialize/DefaultConfig/Write (v3)");
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
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_l[0]);

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

    /* Level2 S-Function Block: testmodel_1109/<S13>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack2_b);
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn1.params;
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
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_pr[0]);

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
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_pr[0]);
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

    /* Level2 S-Function Block: testmodel_1109/<S14>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack_e);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant_i);
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn2.params;
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

    /* Level2 S-Function Block: testmodel_1109/<S15>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack_o);
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn3.params;
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
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_e[0]);

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
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_e[0]);
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

    /* Level2 S-Function Block: testmodel_1109/<S5>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack_j);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
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
      ssSetPath(rts, "testmodel_1109/IO601/PositionControl /Write (v3)");
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
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_aa);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_c);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_i);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_p0);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_e);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_k);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_b);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_k[0]);

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
        ssSetDWork(rts, 0, &testmodel_1109_DW.Writev3_IWORK_k[0]);
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

    /* Level2 S-Function Block: testmodel_1109/<S7>/Write (v3) (sg_IO601_write_s_3) */
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
          ssSetInputPortSignal(rts, 0, &testmodel_1109_B.CANPack2_p);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Product_l);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/STOP/Write (v3)");
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
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_d);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_b);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_is);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_by);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_b);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_l);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK_p[0]);

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

    /* Level2 S-Function Block: testmodel_1109/<S11>/Write (v3) (sg_IO601_write_s_3) */
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

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

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
          ssSetInputPortSignal(rts, 1, &testmodel_1109_B.Constant);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel_1109/IO601/Velocity control/Write (v3)");
      ssSetRTModel(rts,testmodel_1109_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel_1109_P.Writev3_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel_1109_P.Writev3_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel_1109_P.Writev3_P3_Size_dd);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel_1109_P.Writev3_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel_1109_P.Writev3_P5_Size_k);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel_1109_P.Writev3_P6_Size_d);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel_1109_P.Writev3_P7_Size_el);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel_1109_P.Writev3_P8_Size_bf);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel_1109_P.Writev3_P9_Size_p);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel_1109_DW.Writev3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn6.dWorkAux;
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.params;
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn7.dWorkAux;
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
      SimStruct *rts = testmodel_1109_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = testmodel_1109_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = testmodel_1109_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = testmodel_1109_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel_1109_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, testmodel_1109_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel_1109_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel_1109_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel_1109_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel_1109_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &testmodel_1109_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn8.params;
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
          &testmodel_1109_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel_1109_M->NonInlinedSFcns.Sfcn8.dWorkAux;
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
  testmodel_1109_M->Sizes.numBlocks = (111);/* Number of blocks */
  testmodel_1109_M->Sizes.numBlockIO = (51);/* Number of block outputs */
  testmodel_1109_M->Sizes.numBlockPrms = (332);/* Sum of parameter "widths" */
  return testmodel_1109_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
