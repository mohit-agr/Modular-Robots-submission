/*
 * testmodel1_1102_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "testmodel1_1102_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "testmodel1_1102.h"
#include "testmodel1_1102_capi.h"
#include "testmodel1_1102_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("IO601/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("IO601/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("IO601/Step"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 4, 0, TARGET_STRING("IO601/Step1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("IO601/Step2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("IO601/Step3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("IO601/Step4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("IO601/Step5"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 1, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 10, 1, TARGET_STRING("IO601/DefaultConfig/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 11, 1, TARGET_STRING("IO601/DefaultConfig/CAN Pack1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 12, 2, TARGET_STRING("IO601/GetState1ms/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 13, 2, TARGET_STRING("IO601/GetState1ms/Bitwise Operator"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 14, 2, TARGET_STRING("IO601/GetState1ms/CAN Pack2"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 15, 3, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 16, 3, TARGET_STRING("IO601/PositionControl /CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 17, 4, TARGET_STRING("IO601/PositionControl 1/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 18, 4, TARGET_STRING("IO601/PositionControl 1/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 19, 5, TARGET_STRING("IO601/QuitError/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 20, 5, TARGET_STRING("IO601/QuitError/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 21, 0, TARGET_STRING("IO601/ReadQueueSS/Read (v3)/p1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 22, 0, TARGET_STRING("IO601/ReadQueueSS/Read (v3)/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 23, 7, TARGET_STRING("IO601/Velocity control/MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 24, 8, TARGET_STRING("IO601/Velocity control/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 25, 8, TARGET_STRING("IO601/Velocity control/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 26, 8, TARGET_STRING("IO601/Velocity control/CAN Pack2"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 27, 6, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/For Iterator"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 28, 6, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Index Vector"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 29, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 30, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 2 },

  { 31, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 2 },

  { 32, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 33, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 2 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 34, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 35, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 36, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 37, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 38, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 39, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 40, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P3"), 0, 2, 0 },

  { 41, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P4"), 0, 2, 0 },

  { 42, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P5"), 0, 2, 0 },

  { 43, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 44, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 45, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P8"), 0, 2, 0 },

  { 46, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P9"), 0, 2, 0 },

  { 47, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P10"), 0, 2, 0 },

  { 48, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 49, TARGET_STRING("IO601/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 50, TARGET_STRING("IO601/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 51, TARGET_STRING("IO601/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 52, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 53, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 54, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 55, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 56, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 57, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 58, TARGET_STRING("IO601/Step3"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 59, TARGET_STRING("IO601/Step3"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 60, TARGET_STRING("IO601/Step3"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 61, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 62, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 63, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 64, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 65, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 66, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 67, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 68, TARGET_STRING("IO601/DefaultConfig/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 69, TARGET_STRING("IO601/DefaultConfig/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 70, TARGET_STRING("IO601/DefaultConfig/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 71, TARGET_STRING("IO601/DefaultConfig/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 72, TARGET_STRING("IO601/DefaultConfig/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 73, TARGET_STRING("IO601/DefaultConfig/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 74, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 75, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 76, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 77, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 78, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 79, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 80, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 81, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 82, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 83, TARGET_STRING("IO601/GetState1ms/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 84, TARGET_STRING("IO601/GetState1ms/DataLen"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 85, TARGET_STRING("IO601/GetState1ms/GetStateCmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 86, TARGET_STRING("IO601/GetState1ms/Time (ms)"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 87, TARGET_STRING("IO601/GetState1ms/current"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 88, TARGET_STRING("IO601/GetState1ms/position"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 89, TARGET_STRING("IO601/GetState1ms/velocity"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 90, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 91, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 92, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 93, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 94, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 95, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 96, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 97, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 98, TARGET_STRING("IO601/GetState1ms/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 99, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 100, TARGET_STRING("IO601/PositionControl /Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 101, TARGET_STRING("IO601/PositionControl /Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 102, TARGET_STRING("IO601/PositionControl /Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 103, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 104, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 105, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 106, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 107, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 108, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 109, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 110, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 111, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 112, TARGET_STRING("IO601/PositionControl 1/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 113, TARGET_STRING("IO601/PositionControl 1/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 114, TARGET_STRING("IO601/PositionControl 1/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 115, TARGET_STRING("IO601/PositionControl 1/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 116, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 117, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 118, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 119, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 120, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 121, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 122, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 123, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 124, TARGET_STRING("IO601/PositionControl 1/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 125, TARGET_STRING("IO601/QuitError/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 126, TARGET_STRING("IO601/QuitError/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 127, TARGET_STRING("IO601/QuitError/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 128, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 129, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 130, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 131, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 132, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 133, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 134, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 135, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 136, TARGET_STRING("IO601/QuitError/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 137, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 138, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 139, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 140, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 141, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 142, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 143, TARGET_STRING("IO601/ReadQueueSS/Read (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 144, TARGET_STRING("IO601/Velocity control/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 145, TARGET_STRING("IO601/Velocity control/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 146, TARGET_STRING("IO601/Velocity control/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 147, TARGET_STRING("IO601/Velocity control/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 148, TARGET_STRING("IO601/Velocity control/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 149, TARGET_STRING("IO601/Velocity control/GetState Cmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 150, TARGET_STRING("IO601/Velocity control/position"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 151, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 152, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 153, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 154, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 155, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 156, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 157, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 158, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 159, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 160, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Out 1"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 161, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Out 2"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &testmodel1_1102_B.Clock,            /* 0: Signal */
  &testmodel1_1102_B.PulseGenerator,   /* 1: Signal */
  &testmodel1_1102_B.Product,          /* 2: Signal */
  &testmodel1_1102_B.Step,             /* 3: Signal */
  &testmodel1_1102_B.Step1,            /* 4: Signal */
  &testmodel1_1102_B.Step2,            /* 5: Signal */
  &testmodel1_1102_B.Step3,            /* 6: Signal */
  &testmodel1_1102_B.Step4,            /* 7: Signal */
  &testmodel1_1102_B.Step5,            /* 8: Signal */
  &testmodel1_1102_B.Constant_dc,      /* 9: Signal */
  &testmodel1_1102_B.CANPack_jw,       /* 10: Signal */
  &testmodel1_1102_B.CANPack1,         /* 11: Signal */
  &testmodel1_1102_B.Constant1_n,      /* 12: Signal */
  &testmodel1_1102_B.BitwiseOperator,  /* 13: Signal */
  &testmodel1_1102_B.CANPack2_b,       /* 14: Signal */
  &testmodel1_1102_B.Constant_d,       /* 15: Signal */
  &testmodel1_1102_B.CANPack_j,        /* 16: Signal */
  &testmodel1_1102_B.Constant_i,       /* 17: Signal */
  &testmodel1_1102_B.CANPack_e,        /* 18: Signal */
  &testmodel1_1102_B.Constant1,        /* 19: Signal */
  &testmodel1_1102_B.CANPack_o,        /* 20: Signal */
  &testmodel1_1102_B.Readv3_o1[0],     /* 21: Signal */
  &testmodel1_1102_B.Readv3_o2,        /* 22: Signal */
  &testmodel1_1102_B.vel,              /* 23: Signal */
  &testmodel1_1102_B.Constant,         /* 24: Signal */
  &testmodel1_1102_B.CANPack,          /* 25: Signal */
  &testmodel1_1102_B.CANPack2,         /* 26: Signal */
  &testmodel1_1102_B.ForIterator,      /* 27: Signal */
  &testmodel1_1102_B.IndexVector,      /* 28: Signal */
  &testmodel1_1102_B.CANUnpack_o1,     /* 29: Signal */
  &testmodel1_1102_B.CANUnpack_o2,     /* 30: Signal */
  &testmodel1_1102_B.CANUnpack_o3,     /* 31: Signal */
  &testmodel1_1102_B.CANUnpack1_o1,    /* 32: Signal */
  &testmodel1_1102_B.CANUnpack1_o2,    /* 33: Signal */
  &testmodel1_1102_P.PulseGenerator_Amp,/* 34: Block Parameter */
  &testmodel1_1102_P.PulseGenerator_Period,/* 35: Block Parameter */
  &testmodel1_1102_P.PulseGenerator_Duty,/* 36: Block Parameter */
  &testmodel1_1102_P.PulseGenerator_PhaseDelay,/* 37: Block Parameter */
  &testmodel1_1102_P.Setupv3_P1,       /* 38: Block Parameter */
  &testmodel1_1102_P.Setupv3_P2,       /* 39: Block Parameter */
  &testmodel1_1102_P.Setupv3_P3[0],    /* 40: Block Parameter */
  &testmodel1_1102_P.Setupv3_P4[0],    /* 41: Block Parameter */
  &testmodel1_1102_P.Setupv3_P5[0],    /* 42: Block Parameter */
  &testmodel1_1102_P.Setupv3_P6,       /* 43: Block Parameter */
  &testmodel1_1102_P.Setupv3_P7,       /* 44: Block Parameter */
  &testmodel1_1102_P.Setupv3_P8[0],    /* 45: Block Parameter */
  &testmodel1_1102_P.Setupv3_P9[0],    /* 46: Block Parameter */
  &testmodel1_1102_P.Setupv3_P10[0],   /* 47: Block Parameter */
  &testmodel1_1102_P.Setupv3_P11,      /* 48: Block Parameter */
  &testmodel1_1102_P.Step_Time,        /* 49: Block Parameter */
  &testmodel1_1102_P.Step_Y0,          /* 50: Block Parameter */
  &testmodel1_1102_P.Step_YFinal,      /* 51: Block Parameter */
  &testmodel1_1102_P.Step1_Time,       /* 52: Block Parameter */
  &testmodel1_1102_P.Step1_Y0,         /* 53: Block Parameter */
  &testmodel1_1102_P.Step1_YFinal,     /* 54: Block Parameter */
  &testmodel1_1102_P.Step2_Time,       /* 55: Block Parameter */
  &testmodel1_1102_P.Step2_Y0,         /* 56: Block Parameter */
  &testmodel1_1102_P.Step2_YFinal,     /* 57: Block Parameter */
  &testmodel1_1102_P.Step3_Time,       /* 58: Block Parameter */
  &testmodel1_1102_P.Step3_Y0,         /* 59: Block Parameter */
  &testmodel1_1102_P.Step3_YFinal,     /* 60: Block Parameter */
  &testmodel1_1102_P.Step4_Time,       /* 61: Block Parameter */
  &testmodel1_1102_P.Step4_Y0,         /* 62: Block Parameter */
  &testmodel1_1102_P.Step4_YFinal,     /* 63: Block Parameter */
  &testmodel1_1102_P.Step5_Time,       /* 64: Block Parameter */
  &testmodel1_1102_P.Step5_Y0,         /* 65: Block Parameter */
  &testmodel1_1102_P.Step5_YFinal,     /* 66: Block Parameter */
  &testmodel1_1102_P.Constant_Value,   /* 67: Block Parameter */
  &testmodel1_1102_P.Constant1_Value,  /* 68: Block Parameter */
  &testmodel1_1102_P.Constant2_Value,  /* 69: Block Parameter */
  &testmodel1_1102_P.Constant3_Value,  /* 70: Block Parameter */
  &testmodel1_1102_P.Constant4_Value,  /* 71: Block Parameter */
  &testmodel1_1102_P.Constant5_Value,  /* 72: Block Parameter */
  &testmodel1_1102_P.Constant6_Value,  /* 73: Block Parameter */
  &testmodel1_1102_P.Writev3_P1,       /* 74: Block Parameter */
  &testmodel1_1102_P.Writev3_P2,       /* 75: Block Parameter */
  &testmodel1_1102_P.Writev3_P3,       /* 76: Block Parameter */
  &testmodel1_1102_P.Writev3_P4,       /* 77: Block Parameter */
  &testmodel1_1102_P.Writev3_P5,       /* 78: Block Parameter */
  &testmodel1_1102_P.Writev3_P6,       /* 79: Block Parameter */
  &testmodel1_1102_P.Writev3_P7,       /* 80: Block Parameter */
  &testmodel1_1102_P.Writev3_P8,       /* 81: Block Parameter */
  &testmodel1_1102_P.Writev3_P9,       /* 82: Block Parameter */
  &testmodel1_1102_P.Constant1_Value_m,/* 83: Block Parameter */
  &testmodel1_1102_P.DataLen_Value,    /* 84: Block Parameter */
  &testmodel1_1102_P.GetStateCmd_Value,/* 85: Block Parameter */
  &testmodel1_1102_P.Timems_Value,     /* 86: Block Parameter */
  &testmodel1_1102_P.current_Value,    /* 87: Block Parameter */
  &testmodel1_1102_P.position_Value,   /* 88: Block Parameter */
  &testmodel1_1102_P.velocity_Value,   /* 89: Block Parameter */
  &testmodel1_1102_P.Writev3_P1_p,     /* 90: Block Parameter */
  &testmodel1_1102_P.Writev3_P2_h,     /* 91: Block Parameter */
  &testmodel1_1102_P.Writev3_P3_n,     /* 92: Block Parameter */
  &testmodel1_1102_P.Writev3_P4_b,     /* 93: Block Parameter */
  &testmodel1_1102_P.Writev3_P5_a,     /* 94: Block Parameter */
  &testmodel1_1102_P.Writev3_P6_l,     /* 95: Block Parameter */
  &testmodel1_1102_P.Writev3_P7_d,     /* 96: Block Parameter */
  &testmodel1_1102_P.Writev3_P8_n,     /* 97: Block Parameter */
  &testmodel1_1102_P.Writev3_P9_g,     /* 98: Block Parameter */
  &testmodel1_1102_P.Constant_Value_e, /* 99: Block Parameter */
  &testmodel1_1102_P.Constant1_Value_c,/* 100: Block Parameter */
  &testmodel1_1102_P.Constant2_Value_d,/* 101: Block Parameter */
  &testmodel1_1102_P.Constant5_Value_k,/* 102: Block Parameter */
  &testmodel1_1102_P.Writev3_P1_d,     /* 103: Block Parameter */
  &testmodel1_1102_P.Writev3_P2_b,     /* 104: Block Parameter */
  &testmodel1_1102_P.Writev3_P3_h,     /* 105: Block Parameter */
  &testmodel1_1102_P.Writev3_P4_g,     /* 106: Block Parameter */
  &testmodel1_1102_P.Writev3_P5_n,     /* 107: Block Parameter */
  &testmodel1_1102_P.Writev3_P6_f,     /* 108: Block Parameter */
  &testmodel1_1102_P.Writev3_P7_e,     /* 109: Block Parameter */
  &testmodel1_1102_P.Writev3_P8_h,     /* 110: Block Parameter */
  &testmodel1_1102_P.Writev3_P9_i,     /* 111: Block Parameter */
  &testmodel1_1102_P.Constant_Value_a, /* 112: Block Parameter */
  &testmodel1_1102_P.Constant1_Value_i,/* 113: Block Parameter */
  &testmodel1_1102_P.Constant2_Value_g,/* 114: Block Parameter */
  &testmodel1_1102_P.Constant5_Value_d,/* 115: Block Parameter */
  &testmodel1_1102_P.Writev3_P1_o,     /* 116: Block Parameter */
  &testmodel1_1102_P.Writev3_P2_e,     /* 117: Block Parameter */
  &testmodel1_1102_P.Writev3_P3_g,     /* 118: Block Parameter */
  &testmodel1_1102_P.Writev3_P4_j,     /* 119: Block Parameter */
  &testmodel1_1102_P.Writev3_P5_e,     /* 120: Block Parameter */
  &testmodel1_1102_P.Writev3_P6_p,     /* 121: Block Parameter */
  &testmodel1_1102_P.Writev3_P7_m,     /* 122: Block Parameter */
  &testmodel1_1102_P.Writev3_P8_c,     /* 123: Block Parameter */
  &testmodel1_1102_P.Writev3_P9_n,     /* 124: Block Parameter */
  &testmodel1_1102_P.Constant1_Value_i1,/* 125: Block Parameter */
  &testmodel1_1102_P.Constant2_Value_n,/* 126: Block Parameter */
  &testmodel1_1102_P.Constant3_Value_f,/* 127: Block Parameter */
  &testmodel1_1102_P.Writev3_P1_k,     /* 128: Block Parameter */
  &testmodel1_1102_P.Writev3_P2_k,     /* 129: Block Parameter */
  &testmodel1_1102_P.Writev3_P3_l,     /* 130: Block Parameter */
  &testmodel1_1102_P.Writev3_P4_e,     /* 131: Block Parameter */
  &testmodel1_1102_P.Writev3_P5_j,     /* 132: Block Parameter */
  &testmodel1_1102_P.Writev3_P6_d,     /* 133: Block Parameter */
  &testmodel1_1102_P.Writev3_P7_j,     /* 134: Block Parameter */
  &testmodel1_1102_P.Writev3_P8_k,     /* 135: Block Parameter */
  &testmodel1_1102_P.Writev3_P9_k,     /* 136: Block Parameter */
  &testmodel1_1102_P.Readv3_P1,        /* 137: Block Parameter */
  &testmodel1_1102_P.Readv3_P2,        /* 138: Block Parameter */
  &testmodel1_1102_P.Readv3_P3,        /* 139: Block Parameter */
  &testmodel1_1102_P.Readv3_P4,        /* 140: Block Parameter */
  &testmodel1_1102_P.Readv3_P5,        /* 141: Block Parameter */
  &testmodel1_1102_P.Readv3_P6,        /* 142: Block Parameter */
  &testmodel1_1102_P.Readv3_P7,        /* 143: Block Parameter */
  &testmodel1_1102_P.Constant_Value_b, /* 144: Block Parameter */
  &testmodel1_1102_P.Constant1_Value_ml,/* 145: Block Parameter */
  &testmodel1_1102_P.Constant2_Value_n0,/* 146: Block Parameter */
  &testmodel1_1102_P.Constant5_Value_c,/* 147: Block Parameter */
  &testmodel1_1102_P.Constant6_Value_a,/* 148: Block Parameter */
  &testmodel1_1102_P.GetStateCmd_Value_p,/* 149: Block Parameter */
  &testmodel1_1102_P.position_Value_m, /* 150: Block Parameter */
  &testmodel1_1102_P.Writev3_P1_kn,    /* 151: Block Parameter */
  &testmodel1_1102_P.Writev3_P2_j,     /* 152: Block Parameter */
  &testmodel1_1102_P.Writev3_P3_j,     /* 153: Block Parameter */
  &testmodel1_1102_P.Writev3_P4_o,     /* 154: Block Parameter */
  &testmodel1_1102_P.Writev3_P5_g,     /* 155: Block Parameter */
  &testmodel1_1102_P.Writev3_P6_i,     /* 156: Block Parameter */
  &testmodel1_1102_P.Writev3_P7_c,     /* 157: Block Parameter */
  &testmodel1_1102_P.Writev3_P8_l,     /* 158: Block Parameter */
  &testmodel1_1102_P.Writev3_P9_h,     /* 159: Block Parameter */
  &testmodel1_1102_P.Out1_Y0,          /* 160: Block Parameter */
  &testmodel1_1102_P.Out2_Y0,          /* 161: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "numeric", "CAN_DATATYPE", 0, 0, sizeof(CAN_DATATYPE), SS_STRUCT, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  50,                                  /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  4                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 },

  { (NULL), (NULL), -1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 34,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 128,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1537379164U,
    1539643840U,
    4034872165U,
    785044480U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  testmodel1_1102_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void testmodel1_1102_InitializeDataMapInfo(RT_MODEL_testmodel1_1102_T *const
  testmodel1_1102_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(testmodel1_1102_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(testmodel1_1102_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(testmodel1_1102_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(testmodel1_1102_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(testmodel1_1102_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  testmodel1_1102_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (testmodel1_1102_M);
  testmodel1_1102_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_testmodel1_1102_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(testmodel1_1102_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(testmodel1_1102_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(testmodel1_1102_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void testmodel1_1102_host_InitializeDataMapInfo
    (testmodel1_1102_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: testmodel1_1102_capi.c */
