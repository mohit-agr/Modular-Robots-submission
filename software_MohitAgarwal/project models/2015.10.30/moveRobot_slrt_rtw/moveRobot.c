/*
 * moveRobot.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "moveRobot".
 *
 * Model version              : 1.59
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Mon Nov 02 16:07:37 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "moveRobot_capi.h"
#include "moveRobot.h"
#include "moveRobot_private.h"

/* Block signals (auto storage) */
B_moveRobot_T moveRobot_B;

/* Block states (auto storage) */
DW_moveRobot_T moveRobot_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_moveRobot_T moveRobot_PrevZCX;

/* Real-time model */
RT_MODEL_moveRobot_T moveRobot_M_;
RT_MODEL_moveRobot_T *const moveRobot_M = &moveRobot_M_;

/* Model output function */
static void moveRobot_output(void)
{
  real_T currentTime;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(moveRobot_DW.DelErrorandGetState_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(moveRobot_DW.TriggeredSubsystem1_SubsysRanBC);

  /* Level2 S-Function Block: '<Root>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* Clock: '<Root>/Clock1' */
  moveRobot_B.Clock1 = moveRobot_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  /* MATLAB Function 'MATLAB Function2': '<S3>:1' */
  /* '<S3>:1:3' */
  moveRobot_B.trig = 0.0;

  /* '<S3>:1:4' */
  moveRobot_B.y = 0.0;
  if (moveRobot_B.Clock1 == 5.0) {
    /* '<S3>:1:5' */
    /* '<S3>:1:6' */
    moveRobot_B.trig = 1.0;

    /* '<S3>:1:7' */
    moveRobot_B.y = 90000.0;
  }

  if (moveRobot_B.Clock1 > 5.0) {
    /* '<S3>:1:9' */
    /* '<S3>:1:10' */
    moveRobot_B.trig = 0.0;
  }

  if (moveRobot_B.Clock1 > 15.0) {
    /* '<S3>:1:12' */
    /* '<S3>:1:13' */
    moveRobot_B.trig = 1.0;

    /* '<S3>:1:14' */
    moveRobot_B.y = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* ok to acquire for <S5>/S-Function */
  moveRobot_DW.SFunction_IWORK.AcquireOK = 1;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  moveRobot_B.l = 5.0;

  /* MATLAB Function: '<Root>/MovePos' */
  /* MATLAB Function 'MovePos': '<S4>:1' */
  /* '<S4>:1:4' */
  moveRobot_B.cmd = 176.0;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  moveRobot_B.DataTypeConversion = (real32_T)moveRobot_B.y;

  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  moveRobot_B.CANPack1.ID = 1283U;
  moveRobot_B.CANPack1.Length = 6U;
  moveRobot_B.CANPack1.Extended = 0U;
  moveRobot_B.CANPack1.Remote = 0;
  moveRobot_B.CANPack1.Data[0] = 0;
  moveRobot_B.CANPack1.Data[1] = 0;
  moveRobot_B.CANPack1.Data[2] = 0;
  moveRobot_B.CANPack1.Data[3] = 0;
  moveRobot_B.CANPack1.Data[4] = 0;
  moveRobot_B.CANPack1.Data[5] = 0;
  moveRobot_B.CANPack1.Data[6] = 0;
  moveRobot_B.CANPack1.Data[7] = 0;

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
          real64_T result = moveRobot_B.l;

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
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[0] = moveRobot_B.CANPack1.Data[0] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
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
          real64_T result = moveRobot_B.cmd;

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
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 0)) >> 0)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 1)) >> 1)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 2)) >> 2)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 3)) >> 3)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 4)) >> 4)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 5)) >> 5)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 6)) >> 6)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[1] = moveRobot_B.CANPack1.Data[1] |
                  (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                  (((uint8_T)(1)) << 7)) >> 7)<<7);
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
        real32_T outValue = 0;

        {
          real32_T result = moveRobot_B.DataTypeConversion;

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
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 0)) >> 0)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 1)) >> 1)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 2)) >> 2)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 3)) >> 3)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 4)) >> 4)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 5)) >> 5)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 6)) >> 6)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[2] = moveRobot_B.CANPack1.Data[2] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 7)) >> 7)<<7);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 8)) >> 8)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 9)) >> 9)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 10)) >> 10)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 11)) >> 11)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 12)) >> 12)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 13)) >> 13)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 14)) >> 14)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[3] = moveRobot_B.CANPack1.Data[3] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 15)) >> 15)<<7);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 16)) >> 16)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 17)) >> 17)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 18)) >> 18)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 19)) >> 19)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 20)) >> 20)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 21)) >> 21)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 22)) >> 22)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[4] = moveRobot_B.CANPack1.Data[4] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 23)) >> 23)<<7);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 24)) >> 24)<<0);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 25)) >> 25)<<1);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 26)) >> 26)<<2);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 27)) >> 27)<<3);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 28)) >> 28)<<4);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 29)) >> 29)<<5);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 30)) >> 30)<<6);
              }

              {
                moveRobot_B.CANPack1.Data[5] = moveRobot_B.CANPack1.Data[5] |
                  (uint8_T)((uint8_T)((uint32_T)(tempValue & (uint32_T)
                  (((uint32_T)(1)) << 31)) >> 31)<<7);
              }
            }
          }
        }
      }
    }
  }

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem1' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &moveRobot_PrevZCX.TriggeredSubsystem1_Trig_ZCE,
                     (moveRobot_B.trig));
  if (zcEvent != NO_ZCEVENT) {
    /* Constant: '<S6>/Constant3' */
    moveRobot_B.Constant3 = moveRobot_P.Constant3_Value;

    /* Level2 S-Function Block: '<S6>/Write (v3)1' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = moveRobot_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    moveRobot_DW.TriggeredSubsystem1_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem1' */

  /* Step: '<Root>/Step' */
  currentTime = moveRobot_M->Timing.t[0];
  if (currentTime < moveRobot_P.Step_Time) {
    moveRobot_B.Step = moveRobot_P.Step_Y0;
  } else {
    moveRobot_B.Step = moveRobot_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Outputs for Triggered SubSystem: '<Root>/Del Error and Get State' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &moveRobot_PrevZCX.DelErrorandGetState_Trig_ZCE,
                     (moveRobot_B.Step));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (scanpack): '<S1>/CAN Pack' */
    moveRobot_B.CANPack.ID = 1283U;
    moveRobot_B.CANPack.Length = 2U;
    moveRobot_B.CANPack.Extended = 0U;
    moveRobot_B.CANPack.Remote = 0;
    moveRobot_B.CANPack.Data[0] = 0;
    moveRobot_B.CANPack.Data[1] = 0;
    moveRobot_B.CANPack.Data[2] = 0;
    moveRobot_B.CANPack.Data[3] = 0;
    moveRobot_B.CANPack.Data[4] = 0;
    moveRobot_B.CANPack.Data[5] = 0;
    moveRobot_B.CANPack.Data[6] = 0;
    moveRobot_B.CANPack.Data[7] = 0;

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
            real64_T result = moveRobot_P.Constant1_Value;

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
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack.Data[0] = moveRobot_B.CANPack.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
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
            real64_T result = moveRobot_P.Constant2_Value;

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
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack.Data[1] = moveRobot_B.CANPack.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* MATLAB Function: '<S1>/GetState' */
    /* MATLAB Function 'Del Error and Get State/GetState': '<S7>:1' */
    /* '<S7>:1:4' */
    moveRobot_B.cmd_e = 149.0;

    /* S-Function (scanpack): '<S1>/CAN Pack2' */
    moveRobot_B.CANPack2.ID = 1283U;
    moveRobot_B.CANPack2.Length = 7U;
    moveRobot_B.CANPack2.Extended = 0U;
    moveRobot_B.CANPack2.Remote = 0;
    moveRobot_B.CANPack2.Data[0] = 0;
    moveRobot_B.CANPack2.Data[1] = 0;
    moveRobot_B.CANPack2.Data[2] = 0;
    moveRobot_B.CANPack2.Data[3] = 0;
    moveRobot_B.CANPack2.Data[4] = 0;
    moveRobot_B.CANPack2.Data[5] = 0;
    moveRobot_B.CANPack2.Data[6] = 0;
    moveRobot_B.CANPack2.Data[7] = 0;

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
            real64_T result = moveRobot_P.Constant5_Value;

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
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[0] = moveRobot_B.CANPack2.Data[0] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
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
            real64_T result = moveRobot_B.cmd_e;

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
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[1] = moveRobot_B.CANPack2.Data[1] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
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
            real64_T result = moveRobot_P.Constant6_Value;

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
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[2] = moveRobot_B.CANPack2.Data[2] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 7)) >> 7)<<7);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 8)) >> 8)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 9)) >> 9)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 10)) >> 10)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 11)) >> 11)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 12)) >> 12)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 13)) >> 13)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 14)) >> 14)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[3] = moveRobot_B.CANPack2.Data[3] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 15)) >> 15)<<7);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 16)) >> 16)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 17)) >> 17)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 18)) >> 18)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 19)) >> 19)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 20)) >> 20)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 21)) >> 21)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 22)) >> 22)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[4] = moveRobot_B.CANPack2.Data[4] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 23)) >> 23)<<7);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 24)) >> 24)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 25)) >> 25)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 26)) >> 26)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 27)) >> 27)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 28)) >> 28)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 29)) >> 29)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 30)) >> 30)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[5] = moveRobot_B.CANPack2.Data[5] |
                    (uint8_T)((uint8_T)((uint32_T)(packedValue & (uint32_T)
                    (((uint32_T)(1)) << 31)) >> 31)<<7);
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
          real64_T outValue = 0;

          {
            real64_T result = moveRobot_P.Constant7_Value;

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
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 0)) >> 0)<<0);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 1)) >> 1)<<1);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 2)) >> 2)<<2);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 3)) >> 3)<<3);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 4)) >> 4)<<4);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 5)) >> 5)<<5);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 6)) >> 6)<<6);
                }

                {
                  moveRobot_B.CANPack2.Data[6] = moveRobot_B.CANPack2.Data[6] |
                    (uint8_T)((uint8_T)((uint8_T)(packedValue & (uint8_T)
                    (((uint8_T)(1)) << 7)) >> 7)<<7);
                }
              }
            }
          }
        }
      }
    }

    /* SignalConversion: '<S1>/TmpSignal ConversionAtWrite (v3)2Inport1' */
    moveRobot_B.TmpSignalConversionAtWritev32In[0] = moveRobot_B.CANPack;
    moveRobot_B.TmpSignalConversionAtWritev32In[1] = moveRobot_B.CANPack2;

    /* Constant: '<S1>/Constant4' */
    moveRobot_B.Constant4 = moveRobot_P.Constant4_Value;

    /* Level2 S-Function Block: '<S1>/Write (v3)2' (sg_IO601_write_s_3) */
    {
      SimStruct *rts = moveRobot_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    moveRobot_DW.DelErrorandGetState_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Del Error and Get State' */
}

/* Model update function */
static void moveRobot_update(void)
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
  if (!(++moveRobot_M->Timing.clockTick0)) {
    ++moveRobot_M->Timing.clockTickH0;
  }

  moveRobot_M->Timing.t[0] = moveRobot_M->Timing.clockTick0 *
    moveRobot_M->Timing.stepSize0 + moveRobot_M->Timing.clockTickH0 *
    moveRobot_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++moveRobot_M->Timing.clockTick1)) {
      ++moveRobot_M->Timing.clockTickH1;
    }

    moveRobot_M->Timing.t[1] = moveRobot_M->Timing.clockTick1 *
      moveRobot_M->Timing.stepSize1 + moveRobot_M->Timing.clockTickH1 *
      moveRobot_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void moveRobot_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Data Type Conversion"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Data Type Conversion"),
          "%15.6f");
        rl32eSetScope(1, 4, 250);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 2);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Data Type Conversion"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 1);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &moveRobot_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for Triggered SubSystem: '<Root>/Triggered Subsystem1' */
  /* Start for Constant: '<S6>/Constant3' */
  moveRobot_B.Constant3 = moveRobot_P.Constant3_Value;

  /* Level2 S-Function Block: '<S6>/Write (v3)1' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/Triggered Subsystem1' */
  /* Start for Constant: '<S1>/Constant4' */
  moveRobot_B.Constant4 = moveRobot_P.Constant4_Value;

  /* Level2 S-Function Block: '<S1>/Write (v3)2' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/Del Error and Get State' */
  moveRobot_PrevZCX.DelErrorandGetState_Trig_ZCE = UNINITIALIZED_ZCSIG;
  moveRobot_PrevZCX.TriggeredSubsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
static void moveRobot_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Setup (v3)' (sg_IO601_setup_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for Triggered SubSystem: '<Root>/Triggered Subsystem1' */

  /* Level2 S-Function Block: '<S6>/Write (v3)1' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/Triggered Subsystem1' */

  /* Terminate for Triggered SubSystem: '<Root>/Del Error and Get State' */

  /* Level2 S-Function Block: '<S1>/Write (v3)2' (sg_IO601_write_s_3) */
  {
    SimStruct *rts = moveRobot_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/Del Error and Get State' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  moveRobot_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  moveRobot_update();
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
  moveRobot_initialize();
}

void MdlTerminate(void)
{
  moveRobot_terminate();
}

/* Registration function */
RT_MODEL_moveRobot_T *moveRobot(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)moveRobot_M, 0,
                sizeof(RT_MODEL_moveRobot_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&moveRobot_M->solverInfo,
                          &moveRobot_M->Timing.simTimeStep);
    rtsiSetTPtr(&moveRobot_M->solverInfo, &rtmGetTPtr(moveRobot_M));
    rtsiSetStepSizePtr(&moveRobot_M->solverInfo, &moveRobot_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&moveRobot_M->solverInfo, (&rtmGetErrorStatus
      (moveRobot_M)));
    rtsiSetRTModelPtr(&moveRobot_M->solverInfo, moveRobot_M);
  }

  rtsiSetSimTimeStep(&moveRobot_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&moveRobot_M->solverInfo,"FixedStepDiscrete");
  moveRobot_M->solverInfoPtr = (&moveRobot_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = moveRobot_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    moveRobot_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    moveRobot_M->Timing.sampleTimes = (&moveRobot_M->Timing.sampleTimesArray[0]);
    moveRobot_M->Timing.offsetTimes = (&moveRobot_M->Timing.offsetTimesArray[0]);

    /* task periods */
    moveRobot_M->Timing.sampleTimes[0] = (0.0);
    moveRobot_M->Timing.sampleTimes[1] = (1.0);

    /* task offsets */
    moveRobot_M->Timing.offsetTimes[0] = (0.0);
    moveRobot_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(moveRobot_M, &moveRobot_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = moveRobot_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    moveRobot_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(moveRobot_M, 20.0);
  moveRobot_M->Timing.stepSize0 = 1.0;
  moveRobot_M->Timing.stepSize1 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    moveRobot_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(moveRobot_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(moveRobot_M->rtwLogInfo, (NULL));
    rtliSetLogT(moveRobot_M->rtwLogInfo, "tout");
    rtliSetLogX(moveRobot_M->rtwLogInfo, "");
    rtliSetLogXFinal(moveRobot_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(moveRobot_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(moveRobot_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(moveRobot_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(moveRobot_M->rtwLogInfo, 1);
    rtliSetLogY(moveRobot_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(moveRobot_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(moveRobot_M->rtwLogInfo, (NULL));
  }

  moveRobot_M->solverInfoPtr = (&moveRobot_M->solverInfo);
  moveRobot_M->Timing.stepSize = (1.0);
  rtsiSetFixedStepSize(&moveRobot_M->solverInfo, 1.0);
  rtsiSetSolverMode(&moveRobot_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  moveRobot_M->ModelData.blockIO = ((void *) &moveRobot_B);
  (void) memset(((void *) &moveRobot_B), 0,
                sizeof(B_moveRobot_T));

  {
    moveRobot_B.CANPack1 = CAN_DATATYPE_GROUND;
    moveRobot_B.CANPack = CAN_DATATYPE_GROUND;
    moveRobot_B.CANPack2 = CAN_DATATYPE_GROUND;
    moveRobot_B.TmpSignalConversionAtWritev32In[0] = CAN_DATATYPE_GROUND;
    moveRobot_B.TmpSignalConversionAtWritev32In[1] = CAN_DATATYPE_GROUND;
  }

  /* parameters */
  moveRobot_M->ModelData.defaultParam = ((real_T *)&moveRobot_P);

  /* states (dwork) */
  moveRobot_M->ModelData.dwork = ((void *) &moveRobot_DW);
  (void) memset((void *)&moveRobot_DW, 0,
                sizeof(DW_moveRobot_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  moveRobot_InitializeDataMapInfo(moveRobot_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &moveRobot_M->NonInlinedSFcns.sfcnInfo;
    moveRobot_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(moveRobot_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &moveRobot_M->Sizes.numSampTimes);
    moveRobot_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(moveRobot_M)[0]);
    moveRobot_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(moveRobot_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,moveRobot_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(moveRobot_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(moveRobot_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(moveRobot_M));
    rtssSetStepSizePtr(sfcnInfo, &moveRobot_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(moveRobot_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &moveRobot_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &moveRobot_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &moveRobot_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &moveRobot_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &moveRobot_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &moveRobot_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &moveRobot_M->solverInfoPtr);
  }

  moveRobot_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&moveRobot_M->NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    moveRobot_M->childSfunctions =
      (&moveRobot_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    moveRobot_M->childSfunctions[0] =
      (&moveRobot_M->NonInlinedSFcns.childSFunctions[0]);
    moveRobot_M->childSfunctions[1] =
      (&moveRobot_M->NonInlinedSFcns.childSFunctions[1]);
    moveRobot_M->childSfunctions[2] =
      (&moveRobot_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: moveRobot/<S1>/Write (v3)2 (sg_IO601_write_s_3) */
    {
      SimStruct *rts = moveRobot_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = moveRobot_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = moveRobot_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = moveRobot_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &moveRobot_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, moveRobot_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &moveRobot_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &moveRobot_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &moveRobot_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &moveRobot_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &moveRobot_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               moveRobot_B.TmpSignalConversionAtWritev32In);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &moveRobot_B.Constant4);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)2");
      ssSetPath(rts, "moveRobot/Del Error and Get State/Write (v3)2");
      ssSetRTModel(rts,moveRobot_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &moveRobot_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)moveRobot_P.Writev32_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)moveRobot_P.Writev32_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)moveRobot_P.Writev32_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)moveRobot_P.Writev32_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)moveRobot_P.Writev32_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)moveRobot_P.Writev32_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)moveRobot_P.Writev32_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)moveRobot_P.Writev32_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)moveRobot_P.Writev32_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &moveRobot_DW.Writev32_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &moveRobot_DW.Writev32_IWORK[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 1.0);
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

    /* Level2 S-Function Block: moveRobot/<S6>/Write (v3)1 (sg_IO601_write_s_3) */
    {
      SimStruct *rts = moveRobot_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = moveRobot_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = moveRobot_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = moveRobot_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &moveRobot_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, moveRobot_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &moveRobot_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &moveRobot_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &moveRobot_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &moveRobot_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &moveRobot_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &moveRobot_B.CANPack1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &moveRobot_B.Constant3);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write (v3)1");
      ssSetPath(rts, "moveRobot/Triggered Subsystem1/Write (v3)1");
      ssSetRTModel(rts,moveRobot_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &moveRobot_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)moveRobot_P.Writev31_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)moveRobot_P.Writev31_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)moveRobot_P.Writev31_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)moveRobot_P.Writev31_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)moveRobot_P.Writev31_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)moveRobot_P.Writev31_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)moveRobot_P.Writev31_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)moveRobot_P.Writev31_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)moveRobot_P.Writev31_P9_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &moveRobot_DW.Writev31_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &moveRobot_DW.Writev31_IWORK[0]);
      }

      /* registration */
      sg_IO601_write_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 1.0);
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

    /* Level2 S-Function Block: moveRobot/<Root>/Setup (v3) (sg_IO601_setup_s_3) */
    {
      SimStruct *rts = moveRobot_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = moveRobot_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = moveRobot_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = moveRobot_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &moveRobot_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, moveRobot_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &moveRobot_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &moveRobot_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &moveRobot_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &moveRobot_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* path info */
      ssSetModelName(rts, "Setup (v3)");
      ssSetPath(rts, "moveRobot/Setup (v3)");
      ssSetRTModel(rts,moveRobot_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &moveRobot_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)moveRobot_P.Setupv3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)moveRobot_P.Setupv3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)moveRobot_P.Setupv3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)moveRobot_P.Setupv3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)moveRobot_P.Setupv3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)moveRobot_P.Setupv3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)moveRobot_P.Setupv3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)moveRobot_P.Setupv3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)moveRobot_P.Setupv3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)moveRobot_P.Setupv3_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)moveRobot_P.Setupv3_P11_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &moveRobot_DW.Setupv3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &moveRobot_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &moveRobot_DW.Setupv3_IWORK[0]);
      }

      /* registration */
      sg_IO601_setup_s_3(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 1.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  moveRobot_M->Sizes.numContStates = (0);/* Number of continuous states */
  moveRobot_M->Sizes.numY = (0);       /* Number of model outputs */
  moveRobot_M->Sizes.numU = (0);       /* Number of model inputs */
  moveRobot_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  moveRobot_M->Sizes.numSampTimes = (2);/* Number of sample times */
  moveRobot_M->Sizes.numBlocks = (29); /* Number of blocks */
  moveRobot_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  moveRobot_M->Sizes.numBlockPrms = (115);/* Sum of parameter "widths" */
  return moveRobot_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
