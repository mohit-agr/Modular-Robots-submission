/*
 * testmodel1_1102.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel1_1102".
 *
 * Model version              : 1.94
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Nov 10 13:05:57 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "testmodel1_1102_capi.h"
#include "testmodel1_1102.h"
#include "testmodel1_1102_private.h"

/* Block signals (auto storage) */
B_testmodel1_1102_T testmodel1_1102_B;

/* Block states (auto storage) */
DW_testmodel1_1102_T testmodel1_1102_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_testmodel1_1102_T testmodel1_1102_PrevZCX;

/* Real-time model */
RT_MODEL_testmodel1_1102_T testmodel1_1102_M_;
RT_MODEL_testmodel1_1102_T *const testmodel1_1102_M = &testmodel1_1102_M_;

/* Model output function */
static void testmodel1_1102_output(void)
{
  real_T currentTime;
  ZCEventType zcEvent;
  int8_T s13_iter;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel1_1102_DW.DefaultConfig_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel1_1102_DW.PositionControl1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel1_1102_DW.QuitError_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel1_1102_DW.ForIteratorSubsystem_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(testmodel1_1102_DW.Velocitycontrol_SubsysRanBC);

  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[6];
    sfcnOutputs(rts, 1);
  }

  /* Step: '<S1>/Step4' */
  currentTime = testmodel1_1102_M->Timing.t[0];
  if (currentTime < testmodel1_1102_P.Step4_Time) {
    testmodel1_1102_B.Step4 = testmodel1_1102_P.Step4_Y0;
  } else {
    testmodel1_1102_B.Step4 = testmodel1_1102_P.Step4_YFinal;
  }

  /* End of Step: '<S1>/Step4' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  testmodel1_1102_B.PulseGenerator = (testmodel1_1102_DW.clockTickCounter <
    testmodel1_1102_P.PulseGenerator_Duty) &&
    (testmodel1_1102_DW.clockTickCounter >= 0) ?
    testmodel1_1102_P.PulseGenerator_Amp : 0.0;
  if (testmodel1_1102_DW.clockTickCounter >=
      testmodel1_1102_P.PulseGenerator_Period - 1.0) {
    testmodel1_1102_DW.clockTickCounter = 0;
  } else {
    testmodel1_1102_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Product: '<S1>/Product' */
  testmodel1_1102_B.Product = testmodel1_1102_B.Step4 *
    testmodel1_1102_B.PulseGenerator;

  /* Clock: '<S1>/Clock' */
  testmodel1_1102_B.Clock = testmodel1_1102_M->Timing.t[0];

  /* Outputs for Triggered SubSystem: '<S1>/Velocity control' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel1_1102_PrevZCX.Velocitycontrol_Trig_ZCE,
                     (testmodel1_1102_B.Product));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S12>/MATLAB Function' */
    /* MATLAB Function 'IO601/Velocity control/MATLAB Function': '<S18>:1' */
    /* '<S18>:1:3' */
    testmodel1_1102_B.vel = sin(6.2831853071795862 * testmodel1_1102_B.Clock /
      10.0) * 15000.0;

    /*  if cp > 0 */
    /*      vel = 90000; */
    /*  else */
    /*      vel = -90000; */
    /*  end */

    /* S-Function (scanpack): '<S12>/CAN Pack' */
    testmodel1_1102_B.CANPack.ID = 1283U;
    testmodel1_1102_B.CANPack.Length = 6U;
    testmodel1_1102_B.CANPack.Extended = 0U;
    testmodel1_1102_B.CANPack.Remote = 0;
    testmodel1_1102_B.CANPack.Data[0] = 0;
    testmodel1_1102_B.CANPack.Data[1] = 0;
    testmodel1_1102_B.CANPack.Data[2] = 0;
    testmodel1_1102_B.CANPack.Data[3] = 0;
    testmodel1_1102_B.CANPack.Data[4] = 0;
    testmodel1_1102_B.CANPack.Data[5] = 0;
    testmodel1_1102_B.CANPack.Data[6] = 0;
    testmodel1_1102_B.CANPack.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant1_Value_ml;

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
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[0] =
                    testmodel1_1102_B.CANPack.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant2_Value_n0;

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
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[1] =
                    testmodel1_1102_B.CANPack.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_B.vel;

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
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[2] =
                    testmodel1_1102_B.CANPack.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[3] =
                    testmodel1_1102_B.CANPack.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[4] =
                    testmodel1_1102_B.CANPack.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel1_1102_B.CANPack.Data[5] =
                    testmodel1_1102_B.CANPack.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S12>/CAN Pack2' */
    testmodel1_1102_B.CANPack2.ID = 1283U;
    testmodel1_1102_B.CANPack2.Length = 7U;
    testmodel1_1102_B.CANPack2.Extended = 0U;
    testmodel1_1102_B.CANPack2.Remote = 0;
    testmodel1_1102_B.CANPack2.Data[0] = 0;
    testmodel1_1102_B.CANPack2.Data[1] = 0;
    testmodel1_1102_B.CANPack2.Data[2] = 0;
    testmodel1_1102_B.CANPack2.Data[3] = 0;
    testmodel1_1102_B.CANPack2.Data[4] = 0;
    testmodel1_1102_B.CANPack2.Data[5] = 0;
    testmodel1_1102_B.CANPack2.Data[6] = 0;
    testmodel1_1102_B.CANPack2.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant5_Value_c;

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
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[0] =
                    testmodel1_1102_B.CANPack2.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.GetStateCmd_Value_p;

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
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[1] =
                    testmodel1_1102_B.CANPack2.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant6_Value_a;

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
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[2] =
                    testmodel1_1102_B.CANPack2.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 10))
                     >> 10)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 11))
                     >> 11)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 12))
                     >> 12)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 13))
                     >> 13)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 14))
                     >> 14)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[3] =
                    testmodel1_1102_B.CANPack2.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 15))
                     >> 15)<<7);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 16))
                     >> 16)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 17))
                     >> 17)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 18))
                     >> 18)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 19))
                     >> 19)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 20))
                     >> 20)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 21))
                     >> 21)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 22))
                     >> 22)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[4] =
                    testmodel1_1102_B.CANPack2.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 23))
                     >> 23)<<7);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 24))
                     >> 24)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 25))
                     >> 25)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 26))
                     >> 26)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 27))
                     >> 27)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 28))
                     >> 28)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 29))
                     >> 29)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(packedValue & (uint32_T)(((uint32_T)(1)) << 30))
                     >> 30)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[5] =
                    testmodel1_1102_B.CANPack2.Data[5] | (uint8_T)((uint8_T)
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
            uint32_T result = (uint32_T) (testmodel1_1102_P.position_Value_m);

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
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack2.Data[6] =
                    testmodel1_1102_B.CANPack2.Data[6] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S12>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel1_1102_B.TmpSignalConversionAtWritev3Inp[0] =
      testmodel1_1102_B.CANPack;
    testmodel1_1102_B.TmpSignalConversionAtWritev3Inp[1] =
      testmodel1_1102_B.CANPack2;

    /* Constant: '<S12>/Constant' */
    testmodel1_1102_B.Constant = testmodel1_1102_P.Constant_Value_b;

    /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    testmodel1_1102_DW.Velocitycontrol_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Velocity control' */

  /* Step: '<S1>/Step5' */
  currentTime = testmodel1_1102_M->Timing.t[1];
  if (currentTime < testmodel1_1102_P.Step5_Time) {
    testmodel1_1102_B.Step5 = testmodel1_1102_P.Step5_Y0;
  } else {
    testmodel1_1102_B.Step5 = testmodel1_1102_P.Step5_YFinal;
  }

  /* End of Step: '<S1>/Step5' */

  /* Outputs for Triggered SubSystem: '<S1>/DefaultConfig' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel1_1102_PrevZCX.DefaultConfig_Trig_ZCE,
                     (testmodel1_1102_B.Step5));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S3>/CAN Pack1' */
    testmodel1_1102_B.CANPack1.ID = 1283U;
    testmodel1_1102_B.CANPack1.Length = 6U;
    testmodel1_1102_B.CANPack1.Extended = 0U;
    testmodel1_1102_B.CANPack1.Remote = 0;
    testmodel1_1102_B.CANPack1.Data[0] = 0;
    testmodel1_1102_B.CANPack1.Data[1] = 0;
    testmodel1_1102_B.CANPack1.Data[2] = 0;
    testmodel1_1102_B.CANPack1.Data[3] = 0;
    testmodel1_1102_B.CANPack1.Data[4] = 0;
    testmodel1_1102_B.CANPack1.Data[5] = 0;
    testmodel1_1102_B.CANPack1.Data[6] = 0;
    testmodel1_1102_B.CANPack1.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant3_Value;

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
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[0] =
                    testmodel1_1102_B.CANPack1.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant4_Value;

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
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[1] =
                    testmodel1_1102_B.CANPack1.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant6_Value;

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
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[2] =
                    testmodel1_1102_B.CANPack1.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[3] =
                    testmodel1_1102_B.CANPack1.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[4] =
                    testmodel1_1102_B.CANPack1.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel1_1102_B.CANPack1.Data[5] =
                    testmodel1_1102_B.CANPack1.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanpack): '<S3>/CAN Pack' */
    testmodel1_1102_B.CANPack_jw.ID = 1283U;
    testmodel1_1102_B.CANPack_jw.Length = 6U;
    testmodel1_1102_B.CANPack_jw.Extended = 0U;
    testmodel1_1102_B.CANPack_jw.Remote = 0;
    testmodel1_1102_B.CANPack_jw.Data[0] = 0;
    testmodel1_1102_B.CANPack_jw.Data[1] = 0;
    testmodel1_1102_B.CANPack_jw.Data[2] = 0;
    testmodel1_1102_B.CANPack_jw.Data[3] = 0;
    testmodel1_1102_B.CANPack_jw.Data[4] = 0;
    testmodel1_1102_B.CANPack_jw.Data[5] = 0;
    testmodel1_1102_B.CANPack_jw.Data[6] = 0;
    testmodel1_1102_B.CANPack_jw.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant1_Value;

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
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[0] =
                    testmodel1_1102_B.CANPack_jw.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant2_Value;

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
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[1] =
                    testmodel1_1102_B.CANPack_jw.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant5_Value;

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
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[2] =
                    testmodel1_1102_B.CANPack_jw.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[3] =
                    testmodel1_1102_B.CANPack_jw.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[4] =
                    testmodel1_1102_B.CANPack_jw.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_jw.Data[5] =
                    testmodel1_1102_B.CANPack_jw.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtWrite (v3)Inport1' */
    testmodel1_1102_B.TmpSignalConversionAtWritev3I_j[0] =
      testmodel1_1102_B.CANPack1;
    testmodel1_1102_B.TmpSignalConversionAtWritev3I_j[1] =
      testmodel1_1102_B.CANPack_jw;

    /* Constant: '<S3>/Constant' */
    testmodel1_1102_B.Constant_dc = testmodel1_1102_P.Constant_Value;

    /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    testmodel1_1102_DW.DefaultConfig_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/DefaultConfig' */

  /* Step: '<S1>/Step3' */
  currentTime = testmodel1_1102_M->Timing.t[1];
  if (currentTime < testmodel1_1102_P.Step3_Time) {
    testmodel1_1102_B.Step3 = testmodel1_1102_P.Step3_Y0;
  } else {
    testmodel1_1102_B.Step3 = testmodel1_1102_P.Step3_YFinal;
  }

  /* End of Step: '<S1>/Step3' */

  /* Outputs for Triggered SubSystem: '<S1>/PositionControl 1' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel1_1102_PrevZCX.PositionControl1_Trig_ZCE,
                     (testmodel1_1102_B.Step3));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S6>/CAN Pack' */
    testmodel1_1102_B.CANPack_e.ID = 1283U;
    testmodel1_1102_B.CANPack_e.Length = 6U;
    testmodel1_1102_B.CANPack_e.Extended = 0U;
    testmodel1_1102_B.CANPack_e.Remote = 0;
    testmodel1_1102_B.CANPack_e.Data[0] = 0;
    testmodel1_1102_B.CANPack_e.Data[1] = 0;
    testmodel1_1102_B.CANPack_e.Data[2] = 0;
    testmodel1_1102_B.CANPack_e.Data[3] = 0;
    testmodel1_1102_B.CANPack_e.Data[4] = 0;
    testmodel1_1102_B.CANPack_e.Data[5] = 0;
    testmodel1_1102_B.CANPack_e.Data[6] = 0;
    testmodel1_1102_B.CANPack_e.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant1_Value_i;

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
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[0] =
                    testmodel1_1102_B.CANPack_e.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant2_Value_g;

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
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[1] =
                    testmodel1_1102_B.CANPack_e.Data[1] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant5_Value_d;

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
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[2] =
                    testmodel1_1102_B.CANPack_e.Data[2] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 7)) >>
                     7)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 8)) >>
                     8)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 9)) >>
                     9)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 10)) >>
                     10)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 11)) >>
                     11)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 12)) >>
                     12)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 13)) >>
                     13)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 14)) >>
                     14)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[3] =
                    testmodel1_1102_B.CANPack_e.Data[3] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 15)) >>
                     15)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 16)) >>
                     16)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 17)) >>
                     17)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 18)) >>
                     18)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 19)) >>
                     19)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 20)) >>
                     20)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 21)) >>
                     21)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 22)) >>
                     22)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[4] =
                    testmodel1_1102_B.CANPack_e.Data[4] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 23)) >>
                     23)<<7);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 24)) >>
                     24)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 25)) >>
                     25)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 26)) >>
                     26)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 27)) >>
                     27)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 28)) >>
                     28)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 29)) >>
                     29)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 30)) >>
                     30)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_e.Data[5] =
                    testmodel1_1102_B.CANPack_e.Data[5] | (uint8_T)((uint8_T)
                    ((uint32_T)(tempValue & (uint32_T)(((uint32_T)(1)) << 31)) >>
                     31)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S6>/Constant' */
    testmodel1_1102_B.Constant_i = testmodel1_1102_P.Constant_Value_a;

    /* Level2 S-Function Block: '<S6>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    testmodel1_1102_DW.PositionControl1_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/PositionControl 1' */

  /* Step: '<S1>/Step' */
  currentTime = testmodel1_1102_M->Timing.t[1];
  if (currentTime < testmodel1_1102_P.Step_Time) {
    testmodel1_1102_B.Step = testmodel1_1102_P.Step_Y0;
  } else {
    testmodel1_1102_B.Step = testmodel1_1102_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Outputs for Triggered SubSystem: '<S1>/QuitError' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &testmodel1_1102_PrevZCX.QuitError_Trig_ZCE,
                     (testmodel1_1102_B.Step));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S7>/CAN Pack' */
    testmodel1_1102_B.CANPack_o.ID = 1283U;
    testmodel1_1102_B.CANPack_o.Length = 2U;
    testmodel1_1102_B.CANPack_o.Extended = 0U;
    testmodel1_1102_B.CANPack_o.Remote = 0;
    testmodel1_1102_B.CANPack_o.Data[0] = 0;
    testmodel1_1102_B.CANPack_o.Data[1] = 0;
    testmodel1_1102_B.CANPack_o.Data[2] = 0;
    testmodel1_1102_B.CANPack_o.Data[3] = 0;
    testmodel1_1102_B.CANPack_o.Data[4] = 0;
    testmodel1_1102_B.CANPack_o.Data[5] = 0;
    testmodel1_1102_B.CANPack_o.Data[6] = 0;
    testmodel1_1102_B.CANPack_o.Data[7] = 0;

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
            real64_T result = testmodel1_1102_P.Constant2_Value_n;

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
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[0] =
                    testmodel1_1102_B.CANPack_o.Data[0] | (uint8_T)((uint8_T)
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
            real64_T result = testmodel1_1102_P.Constant3_Value_f;

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
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 0)) >>
                     0)<<0);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 1)) >>
                     1)<<1);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 2)) >>
                     2)<<2);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 3)) >>
                     3)<<3);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 4)) >>
                     4)<<4);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 5)) >>
                     5)<<5);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 6)) >>
                     6)<<6);
                }

                {
                  testmodel1_1102_B.CANPack_o.Data[1] =
                    testmodel1_1102_B.CANPack_o.Data[1] | (uint8_T)((uint8_T)
                    ((uint8_T)(packedValue & (uint8_T)(((uint8_T)(1)) << 7)) >>
                     7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* Constant: '<S7>/Constant1' */
    testmodel1_1102_B.Constant1 = testmodel1_1102_P.Constant1_Value_i1;

    /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    testmodel1_1102_DW.QuitError_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/QuitError' */
  /* ok to acquire for <S9>/S-Function */
  testmodel1_1102_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S15>/S-Function */
  testmodel1_1102_DW.SFunction_IWORK_l.AcquireOK = 1;

  /* Level2 S-Function Block: '<S8>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[7];
    sfcnOutputs(rts, 1);
  }

  /* Outputs for Iterator SubSystem: '<S8>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S13>/For Iterator'
   */
  s13_iter = 1;
  do {
    exitg1 = 0;
    currentTime = testmodel1_1102_B.Readv3_o2;
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

    if (s13_iter <= (currentTime < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                     -currentTime : (int32_T)(int8_T)(uint8_T)currentTime)) {
      testmodel1_1102_B.ForIterator = s13_iter;

      /* ok to acquire for <S16>/S-Function */
      testmodel1_1102_DW.SFunction_IWORK_c.AcquireOK = 1;

      /* ok to acquire for <S17>/S-Function */
      testmodel1_1102_DW.SFunction_IWORK_j.AcquireOK = 1;
      testmodel1_1102_B.IndexVector =
        testmodel1_1102_B.Readv3_o1[testmodel1_1102_B.ForIterator - 1];

      /* S-Function (scanunpack): '<S13>/CAN Unpack' */
      {
        /* S-Function (scanunpack): '<S13>/CAN Unpack' */
        if ((8 == testmodel1_1102_B.IndexVector.Length) &&
            (testmodel1_1102_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((1795U == testmodel1_1102_B.IndexVector.ID) && (0U ==
               testmodel1_1102_B.IndexVector.Extended) ) {
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
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 0)) >> 0)<<0);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 1)) >> 1)<<1);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 2)) >> 2)<<2);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 3)) >> 3)<<3);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 4)) >> 4)<<4);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 5)) >> 5)<<5);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 6)) >> 6)<<6);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[0]) & (uint8_T)
                             ( (uint8_T) (1)<< 7)) >> 7)<<7);
                        }

                        unpackedValue = tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel1_1102_B.CANUnpack_o1 = result;
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
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 0)) >> 0)<<0);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 1)) >> 1)<<1);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 2)) >> 2)<<2);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 3)) >> 3)<<3);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 4)) >> 4)<<4);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 5)) >> 5)<<5);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 6)) >> 6)<<6);
                        }

                        {
                          tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                            ((testmodel1_1102_B.IndexVector.Data[1]) & (uint8_T)
                             ( (uint8_T) (1)<< 7)) >> 7)<<7);
                        }

                        unpackedValue = tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel1_1102_B.CANUnpack_o2 = result;
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
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            0);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            1);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            2);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            3);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            4);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            5);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            6);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            7);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            8);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            9);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            10);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            11);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            12);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            13);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            14);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            15);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            16);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            17);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            18);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            19);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            20);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            21);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            22);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[4])
                                        & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            23);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 0)) >> 0)<<
                            24);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 1)) >> 1)<<
                            25);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 2)) >> 2)<<
                            26);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 3)) >> 3)<<
                            27);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 4)) >> 4)<<
                            28);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 5)) >> 5)<<
                            29);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 6)) >> 6)<<
                            30);
                        }

                        {
                          tempValue = tempValue | (uint32_T)((uint32_T)
                            ((uint32_T)((testmodel1_1102_B.IndexVector.Data[5])
                                        & (uint32_T)( (uint32_T) (1)<< 7)) >> 7)<<
                            31);
                        }

                        unpackedValue = (int32_T) tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel1_1102_B.CANUnpack_o3 = result;
                  }
                }
              }
            }
          }
        }
      }

      /* S-Function (scanunpack): '<S13>/CAN Unpack1' */
      {
        /* S-Function (scanunpack): '<S13>/CAN Unpack1' */
        if ((4 == testmodel1_1102_B.IndexVector.Length) &&
            (testmodel1_1102_B.IndexVector.ID != INVALID_CAN_ID) ) {
          if ((33U == testmodel1_1102_B.IndexVector.ID) && (0U ==
               testmodel1_1102_B.IndexVector.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 0
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
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            0);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            1);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            2);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            3);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            4);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            5);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            6);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[0])
                                        & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            7);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            8);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            9);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            10);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            11);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            12);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            13);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            14);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[1])
                                        & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            15);
                        }

                        unpackedValue = (int16_T) tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel1_1102_B.CANUnpack1_o1 = result;
                  }
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
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
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            0);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            1);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            2);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            3);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            4);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            5);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            6);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[2])
                                        & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            7);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<
                            8);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<
                            9);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<
                            10);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<
                            11);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<
                            12);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<
                            13);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<
                            14);
                        }

                        {
                          tempValue = tempValue | (uint16_T)((uint16_T)
                            ((uint16_T)((testmodel1_1102_B.IndexVector.Data[3])
                                        & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<
                            15);
                        }

                        unpackedValue = (int16_T) tempValue;
                      }

                      outValue = (real64_T) (unpackedValue);
                    }
                  }

                  {
                    real64_T result = (real64_T) outValue;
                    testmodel1_1102_B.CANUnpack1_o2 = result;
                  }
                }
              }
            }
          }
        }
      }

      srUpdateBC(testmodel1_1102_DW.ForIteratorSubsystem_SubsysRanB);
      s13_iter++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<S8>/For Iterator Subsystem' */

  /* Step: '<S1>/Step1' */
  currentTime = testmodel1_1102_M->Timing.t[1];
  if (currentTime < testmodel1_1102_P.Step1_Time) {
    testmodel1_1102_B.Step1 = testmodel1_1102_P.Step1_Y0;
  } else {
    testmodel1_1102_B.Step1 = testmodel1_1102_P.Step1_YFinal;
  }

  /* End of Step: '<S1>/Step1' */

  /* Step: '<S1>/Step2' */
  currentTime = testmodel1_1102_M->Timing.t[1];
  if (currentTime < testmodel1_1102_P.Step2_Time) {
    testmodel1_1102_B.Step2 = testmodel1_1102_P.Step2_Y0;
  } else {
    testmodel1_1102_B.Step2 = testmodel1_1102_P.Step2_YFinal;
  }

  /* End of Step: '<S1>/Step2' */
}

/* Model update function */
static void testmodel1_1102_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++testmodel1_1102_M->Timing.clockTick0)) {
    ++testmodel1_1102_M->Timing.clockTickH0;
  }

  testmodel1_1102_M->Timing.t[0] = testmodel1_1102_M->Timing.clockTick0 *
    testmodel1_1102_M->Timing.stepSize0 + testmodel1_1102_M->Timing.clockTickH0 *
    testmodel1_1102_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++testmodel1_1102_M->Timing.clockTick1)) {
      ++testmodel1_1102_M->Timing.clockTickH1;
    }

    testmodel1_1102_M->Timing.t[1] = testmodel1_1102_M->Timing.clockTick1 *
      testmodel1_1102_M->Timing.stepSize1 +
      testmodel1_1102_M->Timing.clockTickH1 *
      testmodel1_1102_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void testmodel1_1102_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  testmodel1_1102_DW.clockTickCounter = -10000;

  /* Start for Constant: '<S12>/Constant' */
  testmodel1_1102_B.Constant = testmodel1_1102_P.Constant_Value_b;

  /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/Velocity control' */
  /* Start for Constant: '<S3>/Constant' */
  testmodel1_1102_B.Constant_dc = testmodel1_1102_P.Constant_Value;

  /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/DefaultConfig' */
  /* Start for Constant: '<S4>/Constant1' */
  testmodel1_1102_B.Constant1_n = testmodel1_1102_P.Constant1_Value_m;

  /* Level2 S-Function Block: '<S4>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/GetState1ms' */
  /* Start for Constant: '<S5>/Constant' */
  testmodel1_1102_B.Constant_d = testmodel1_1102_P.Constant_Value_e;

  /* Level2 S-Function Block: '<S5>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/PositionControl ' */
  /* Start for Constant: '<S6>/Constant' */
  testmodel1_1102_B.Constant_i = testmodel1_1102_P.Constant_Value_a;

  /* Level2 S-Function Block: '<S6>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/PositionControl 1' */
  /* Start for Constant: '<S7>/Constant1' */
  testmodel1_1102_B.Constant1 = testmodel1_1102_P.Constant1_Value_i1;

  /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S1>/QuitError' */

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"));
        rl32eSetScope(4, 4, 10000);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 2.0);
        rl32eSetTargetScope(4, 11, -90000.0);
        rl32eSetTargetScope(4, 10, 90000.0);
        xpceScopeAcqOK(4, &testmodel1_1102_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S15>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("IO601/ReadQueueSS/Read (v3)/p2"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo(
          "IO601/ReadQueueSS/Read (v3)/p2"),"%15.6f");
        rl32eSetScope(1, 4, 1000);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("IO601/ReadQueueSS/Read (v3)/p2"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &testmodel1_1102_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Level2 S-Function Block: '<S8>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Iterator SubSystem: '<S8>/For Iterator Subsystem' */

  /* S-Function Block: <S16>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p1"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p1"),"%15.6f");
        rl32eSetScope(3, 4, 1000);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 0.0);
        xpceScopeAcqOK(3, &testmodel1_1102_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S17>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"),"%15.6f");
        rl32eSetScope(2, 4, 1000);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo(
          "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 0.0);
        xpceScopeAcqOK(2, &testmodel1_1102_DW.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /*-----------S-Function Block: <S13>/CAN Unpack -----------------*/

  /*-----------S-Function Block: <S13>/CAN Unpack1 -----------------*/

  /* VirtualOutportStart for Outport: '<S13>/Out 1' */
  testmodel1_1102_B.CANUnpack_o3 = testmodel1_1102_P.Out1_Y0;

  /* VirtualOutportStart for Outport: '<S13>/Out 2' */
  testmodel1_1102_B.CANUnpack1_o1 = testmodel1_1102_P.Out2_Y0;
  testmodel1_1102_B.CANUnpack1_o2 = testmodel1_1102_P.Out2_Y0;

  /* End of Start for SubSystem: '<S8>/For Iterator Subsystem' */
  testmodel1_1102_PrevZCX.DefaultConfig_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel1_1102_PrevZCX.GetState1ms_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel1_1102_PrevZCX.PositionControl_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel1_1102_PrevZCX.PositionControl1_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel1_1102_PrevZCX.QuitError_Trig_ZCE = UNINITIALIZED_ZCSIG;
  testmodel1_1102_PrevZCX.Velocitycontrol_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
static void testmodel1_1102_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<S1>/Velocity control' */

  /* Level2 S-Function Block: '<S12>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/Velocity control' */

  /* Terminate for Triggered SubSystem: '<S1>/DefaultConfig' */

  /* Level2 S-Function Block: '<S3>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/DefaultConfig' */

  /* Terminate for Triggered SubSystem: '<S1>/GetState1ms' */

  /* Level2 S-Function Block: '<S4>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/GetState1ms' */

  /* Terminate for Triggered SubSystem: '<S1>/PositionControl ' */

  /* Level2 S-Function Block: '<S5>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/PositionControl ' */

  /* Terminate for Triggered SubSystem: '<S1>/PositionControl 1' */

  /* Level2 S-Function Block: '<S6>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/PositionControl 1' */

  /* Terminate for Triggered SubSystem: '<S1>/QuitError' */

  /* Level2 S-Function Block: '<S7>/Write (v3)' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S1>/QuitError' */

  /* Level2 S-Function Block: '<S8>/Read (v3)' (sg_IO601_read_s_3) */
  {
    SimStruct *rts = testmodel1_1102_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  testmodel1_1102_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  testmodel1_1102_update();
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
  testmodel1_1102_initialize();
}

void MdlTerminate(void)
{
  testmodel1_1102_terminate();
}

/* Registration function */
RT_MODEL_testmodel1_1102_T *testmodel1_1102(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testmodel1_1102_M, 0,
                sizeof(RT_MODEL_testmodel1_1102_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&testmodel1_1102_M->solverInfo,
                          &testmodel1_1102_M->Timing.simTimeStep);
    rtsiSetTPtr(&testmodel1_1102_M->solverInfo, &rtmGetTPtr(testmodel1_1102_M));
    rtsiSetStepSizePtr(&testmodel1_1102_M->solverInfo,
                       &testmodel1_1102_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&testmodel1_1102_M->solverInfo, (&rtmGetErrorStatus
      (testmodel1_1102_M)));
    rtsiSetRTModelPtr(&testmodel1_1102_M->solverInfo, testmodel1_1102_M);
  }

  rtsiSetSimTimeStep(&testmodel1_1102_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&testmodel1_1102_M->solverInfo,"FixedStepDiscrete");
  testmodel1_1102_M->solverInfoPtr = (&testmodel1_1102_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = testmodel1_1102_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    testmodel1_1102_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    testmodel1_1102_M->Timing.sampleTimes =
      (&testmodel1_1102_M->Timing.sampleTimesArray[0]);
    testmodel1_1102_M->Timing.offsetTimes =
      (&testmodel1_1102_M->Timing.offsetTimesArray[0]);

    /* task periods */
    testmodel1_1102_M->Timing.sampleTimes[0] = (0.0);
    testmodel1_1102_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    testmodel1_1102_M->Timing.offsetTimes[0] = (0.0);
    testmodel1_1102_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(testmodel1_1102_M, &testmodel1_1102_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = testmodel1_1102_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    testmodel1_1102_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(testmodel1_1102_M, 50.0);
  testmodel1_1102_M->Timing.stepSize0 = 0.001;
  testmodel1_1102_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    testmodel1_1102_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(testmodel1_1102_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(testmodel1_1102_M->rtwLogInfo, (NULL));
    rtliSetLogT(testmodel1_1102_M->rtwLogInfo, "tout");
    rtliSetLogX(testmodel1_1102_M->rtwLogInfo, "");
    rtliSetLogXFinal(testmodel1_1102_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(testmodel1_1102_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(testmodel1_1102_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(testmodel1_1102_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(testmodel1_1102_M->rtwLogInfo, 1);
    rtliSetLogY(testmodel1_1102_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(testmodel1_1102_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(testmodel1_1102_M->rtwLogInfo, (NULL));
  }

  testmodel1_1102_M->solverInfoPtr = (&testmodel1_1102_M->solverInfo);
  testmodel1_1102_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&testmodel1_1102_M->solverInfo, 0.001);
  rtsiSetSolverMode(&testmodel1_1102_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  testmodel1_1102_M->ModelData.blockIO = ((void *) &testmodel1_1102_B);
  (void) memset(((void *) &testmodel1_1102_B), 0,
                sizeof(B_testmodel1_1102_T));

  {
    int32_T i;
    for (i = 0; i < 50; i++) {
      testmodel1_1102_B.Readv3_o1[i] = CAN_DATATYPE_GROUND;
    }

    testmodel1_1102_B.CANPack = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack2 = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.TmpSignalConversionAtWritev3Inp[0] = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.TmpSignalConversionAtWritev3Inp[1] = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.IndexVector = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack_o = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack_e = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack_j = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack2_b = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack1 = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.CANPack_jw = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.TmpSignalConversionAtWritev3I_j[0] = CAN_DATATYPE_GROUND;
    testmodel1_1102_B.TmpSignalConversionAtWritev3I_j[1] = CAN_DATATYPE_GROUND;
  }

  /* parameters */
  testmodel1_1102_M->ModelData.defaultParam = ((real_T *)&testmodel1_1102_P);

  /* states (dwork) */
  testmodel1_1102_M->ModelData.dwork = ((void *) &testmodel1_1102_DW);
  (void) memset((void *)&testmodel1_1102_DW, 0,
                sizeof(DW_testmodel1_1102_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  testmodel1_1102_InitializeDataMapInfo(testmodel1_1102_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &testmodel1_1102_M->NonInlinedSFcns.sfcnInfo;
    testmodel1_1102_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(testmodel1_1102_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &testmodel1_1102_M->Sizes.numSampTimes);
    testmodel1_1102_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (testmodel1_1102_M)[0]);
    testmodel1_1102_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (testmodel1_1102_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,testmodel1_1102_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(testmodel1_1102_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(testmodel1_1102_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (testmodel1_1102_M));
    rtssSetStepSizePtr(sfcnInfo, &testmodel1_1102_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(testmodel1_1102_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &testmodel1_1102_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &testmodel1_1102_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &testmodel1_1102_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &testmodel1_1102_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &testmodel1_1102_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &testmodel1_1102_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &testmodel1_1102_M->solverInfoPtr);
  }

  testmodel1_1102_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&testmodel1_1102_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  8*sizeof(SimStruct));
    testmodel1_1102_M->childSfunctions =
      (&testmodel1_1102_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        testmodel1_1102_M->childSfunctions[i] =
          (&testmodel1_1102_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: testmodel1_1102/<S3>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               testmodel1_1102_B.TmpSignalConversionAtWritev3I_j);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant_dc);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/DefaultConfig/Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK_l[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK_l[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
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

    /* Level2 S-Function Block: testmodel1_1102/<S4>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel1_1102_B.CANPack2_b);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant1_n);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/GetState1ms/Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size_a);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size_k);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size_d);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size_p);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size_b);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size_g);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size_o);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK_p[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, rtInf);
      ssSetOffsetTime(rts, 0, 0);
      sfcnTsMap[0] = -2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel1_1102/<S5>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel1_1102_B.CANPack_j);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant_d);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/PositionControl /Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size_aa);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size_c);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size_i);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size_p0);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size_e);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size_k);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size_b);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK_k[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK_k[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, rtInf);
      ssSetOffsetTime(rts, 0, 0);
      sfcnTsMap[0] = -2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: testmodel1_1102/<S6>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel1_1102_B.CANPack_e);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant_i);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/PositionControl 1/Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size_i);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size_f);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size_m);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size_i);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size_l);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size_h);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK_d[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
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

    /* Level2 S-Function Block: testmodel1_1102/<S7>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &testmodel1_1102_B.CANPack_o);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/QuitError/Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size_p);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size_f);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size_a);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size_g);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size_d3);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size_b);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size_o);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size_d);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size_a);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK_e[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
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

    /* Level2 S-Function Block: testmodel1_1102/<S12>/Write (v3) (sg_IO601_write_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               testmodel1_1102_B.TmpSignalConversionAtWritev3Inp);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &testmodel1_1102_B.Constant);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/Velocity control/Write (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Writev3_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Writev3_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Writev3_P3_Size_d);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Writev3_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Writev3_P5_Size_k);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Writev3_P6_Size_d);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Writev3_P7_Size_el);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Writev3_P8_Size_b);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Writev3_P9_Size_p);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Writev3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Writev3_IWORK[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
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

    /* Level2 S-Function Block: testmodel1_1102/<S1>/Setup (v3) (sg_IO601_setup_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* path info */
      ssSetModelName(rts, "Setup (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/Setup (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Setupv3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Setupv3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Setupv3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Setupv3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Setupv3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Setupv3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Setupv3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)testmodel1_1102_P.Setupv3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)testmodel1_1102_P.Setupv3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)testmodel1_1102_P.Setupv3_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)testmodel1_1102_P.Setupv3_P11_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Setupv3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Setupv3_IWORK[0]);
      }

      /* registration */
      sg_IO601_setup_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: testmodel1_1102/<S8>/Read (v3) (sg_IO601_read_s_3) */
    {
      SimStruct *rts = testmodel1_1102_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = testmodel1_1102_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = testmodel1_1102_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = testmodel1_1102_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &testmodel1_1102_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, testmodel1_1102_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &testmodel1_1102_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &testmodel1_1102_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &testmodel1_1102_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &testmodel1_1102_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 50);
          ssSetOutputPortSignal(rts, 0, ((CAN_DATATYPE *)
            testmodel1_1102_B.Readv3_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &testmodel1_1102_B.Readv3_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Read (v3)");
      ssSetPath(rts, "testmodel1_1102/IO601/ReadQueueSS/Read (v3)");
      ssSetRTModel(rts,testmodel1_1102_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)testmodel1_1102_P.Readv3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)testmodel1_1102_P.Readv3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)testmodel1_1102_P.Readv3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)testmodel1_1102_P.Readv3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)testmodel1_1102_P.Readv3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)testmodel1_1102_P.Readv3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)testmodel1_1102_P.Readv3_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &testmodel1_1102_DW.Readv3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &testmodel1_1102_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &testmodel1_1102_DW.Readv3_IWORK[0]);
      }

      /* registration */
      sg_IO601_read_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
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
  testmodel1_1102_M->Sizes.numContStates = (0);/* Number of continuous states */
  testmodel1_1102_M->Sizes.numY = (0); /* Number of model outputs */
  testmodel1_1102_M->Sizes.numU = (0); /* Number of model inputs */
  testmodel1_1102_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  testmodel1_1102_M->Sizes.numSampTimes = (2);/* Number of sample times */
  testmodel1_1102_M->Sizes.numBlocks = (79);/* Number of blocks */
  testmodel1_1102_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  testmodel1_1102_M->Sizes.numBlockPrms = (290);/* Sum of parameter "widths" */
  return testmodel1_1102_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
