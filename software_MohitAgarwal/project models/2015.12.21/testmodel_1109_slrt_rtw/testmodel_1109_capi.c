/*
 * testmodel_1109_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.228
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Dec 22 11:17:16 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "testmodel_1109_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "testmodel_1109.h"
#include "testmodel_1109_capi.h"
#include "testmodel_1109_private.h"
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
  { 0, 0, TARGET_STRING("IO601/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("IO601/Data Type Conversion1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("IO601/Data Type Conversion2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("IO601/Data Type Conversion3"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 4, 0, TARGET_STRING("IO601/Data Type Conversion4"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 5, 0, TARGET_STRING("IO601/Data Type Conversion5"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 6, 0, TARGET_STRING("IO601/Discrete-Time Integrator"),
    TARGET_STRING(""), 0, 0, 0, 1, 0 },

  { 7, 0, TARGET_STRING("IO601/Memory"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 8, 0, TARGET_STRING("IO601/Product1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 9, 0, TARGET_STRING("IO601/Product2"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 10, 0, TARGET_STRING("IO601/Counter1/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 11, 0, TARGET_STRING("IO601/Counter1/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 1 },

  { 12, 0, TARGET_STRING("IO601/Counter2/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 13, 0, TARGET_STRING("IO601/Counter2/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 1 },

  { 14, 0, TARGET_STRING("IO601/Read (v3)/p1"),
    TARGET_STRING(""), 0, 3, 2, 0, 0 },

  { 15, 0, TARGET_STRING("IO601/Read (v3)/p2"),
    TARGET_STRING(""), 1, 1, 0, 0, 0 },

  { 16, 0, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 17, 0, TARGET_STRING("IO601/Step1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 18, 0, TARGET_STRING("IO601/Step4"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 19, 0, TARGET_STRING("IO601/Step5"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 20, 3, TARGET_STRING("IO601/CANSend/Product"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 21, 0, TARGET_STRING("IO601/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 22, 4, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 23, 4, TARGET_STRING("IO601/DefaultConfig/CAN Pack"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 24, 4, TARGET_STRING("IO601/DefaultConfig/CAN Pack1"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 25, 0, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 26, 0, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 27, 0, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 28, 10, TARGET_STRING("IO601/ReadQueueSS/MATLAB Function1"),
    TARGET_STRING(""), 0, 0, 3, 0, 2 },

  { 29, 11, TARGET_STRING("IO601/ReadQueueSS/Data Type Conversion1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 30, 11, TARGET_STRING("IO601/ReadQueueSS/Data Type Conversion2"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 31, 11, TARGET_STRING("IO601/ReadQueueSS/For Iterator"),
    TARGET_STRING(""), 0, 4, 0, 0, 2 },

  { 32, 11, TARGET_STRING("IO601/ReadQueueSS/Index Vector"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 33, 11, TARGET_STRING("IO601/ReadQueueSS/CAN Unpack2"),
    TARGET_STRING(""), 0, 5, 4, 0, 2 },

  { 34, 11, TARGET_STRING("IO601/ReadQueueSS/CAN Unpack3"),
    TARGET_STRING(""), 0, 5, 5, 0, 2 },

  { 35, 11, TARGET_STRING("IO601/ReadQueueSS/Counter/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 36, 11, TARGET_STRING("IO601/ReadQueueSS/Counter/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 2 },

  { 37, 11, TARGET_STRING("IO601/ReadQueueSS/Counter1/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 38, 11, TARGET_STRING("IO601/ReadQueueSS/Counter1/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 2 },

  { 39, 11, TARGET_STRING("IO601/ReadQueueSS/ReadACK/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 40, 11, TARGET_STRING("IO601/ReadQueueSS/ReadACK/p2"),
    TARGET_STRING(""), 1, 1, 0, 0, 2 },

  { 41, 11, TARGET_STRING("IO601/ReadQueueSS/ReadACK/p3"),
    TARGET_STRING(""), 2, 1, 0, 0, 2 },

  { 42, 11, TARGET_STRING("IO601/ReadQueueSS/ReadACK/p4"),
    TARGET_STRING(""), 3, 1, 0, 0, 2 },

  { 43, 3, TARGET_STRING("IO601/CANSend/STOP/CAN Pack2"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 44, 1, TARGET_STRING("IO601/CANSend/movVel/MATLAB Function1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 45, 1, TARGET_STRING("IO601/CANSend/movVel/MATLAB Function1/p2"),
    TARGET_STRING(""), 1, 6, 0, 0, 0 },

  { 46, 2, TARGET_STRING("IO601/CANSend/movVel/TC UI32-UI8"),
    TARGET_STRING(""), 0, 5, 6, 0, 0 },

  { 47, 3, TARGET_STRING("IO601/CANSend/movVel/CAN Pack1"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 48, 3, TARGET_STRING("IO601/CANSend/movVel/CAN Pack2"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 49, 3, TARGET_STRING("IO601/CANSend/movVel/CAN Pack3"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 50, 5, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 51, 5, TARGET_STRING("IO601/Initialize/GetState(ms)/CAN Pack2"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 52, 6, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 53, 6, TARGET_STRING("IO601/Initialize/InitialPosition/CAN Pack"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 54, 7, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 55, 7, TARGET_STRING("IO601/Initialize/QuitError/CAN Pack"),
    TARGET_STRING(""), 0, 3, 0, 0, 2 },

  { 56, 8, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/Logic"),
    TARGET_STRING(""), 0, 2, 7, 0, 2 },

  { 57, 8, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/Memory"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 58, 11, TARGET_STRING("IO601/ReadQueueSS/CountACK/Data Type Conversion1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 59, 11, TARGET_STRING("IO601/ReadQueueSS/CountACK/Counter1/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 60, 11, TARGET_STRING("IO601/ReadQueueSS/CountACK/Counter1/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 2 },

  { 61, 11, TARGET_STRING(
    "IO601/ReadQueueSS/Detect Increase/FixPt Relational Operator"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 62, 11, TARGET_STRING("IO601/ReadQueueSS/Detect Increase/Delay Input1"),
    TARGET_STRING("U(k-1)"), 0, 1, 0, 0, 2 },

  { 63, 11, TARGET_STRING(
    "IO601/ReadQueueSS/CountACK/Detect Increase/FixPt Relational Operator"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 64, 11, TARGET_STRING(
    "IO601/ReadQueueSS/CountACK/Detect Increase/Delay Input1"),
    TARGET_STRING("U(k-1)"), 0, 1, 0, 0, 2 },

  { 65, 9, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/Logic"),
    TARGET_STRING(""), 0, 2, 7, 0, 2 },

  { 66, 9, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/Memory"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 67, TARGET_STRING("IO601/J-K Flip-Flop1"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 68, TARGET_STRING("IO601/SendOut"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 69, TARGET_STRING("IO601/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 1 },

  { 70, TARGET_STRING("IO601/Memory"),
    TARGET_STRING("X0"), 2, 0, 0 },

  { 71, TARGET_STRING("IO601/Counter1"),
    TARGET_STRING("InitialCount"), 5, 0, 0 },

  { 72, TARGET_STRING("IO601/Counter1"),
    TARGET_STRING("HitValue"), 5, 0, 0 },

  { 73, TARGET_STRING("IO601/Counter2"),
    TARGET_STRING("InitialCount"), 5, 0, 0 },

  { 74, TARGET_STRING("IO601/Counter2"),
    TARGET_STRING("HitValue"), 5, 0, 0 },

  { 75, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 76, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 77, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 78, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 79, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 80, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 81, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 82, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 83, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 84, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P3"), 1, 8, 0 },

  { 85, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P4"), 1, 8, 0 },

  { 86, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P5"), 1, 8, 0 },

  { 87, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 88, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 89, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P8"), 1, 8, 0 },

  { 90, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P9"), 1, 8, 0 },

  { 91, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P10"), 1, 8, 0 },

  { 92, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P11"), 1, 0, 0 },

  { 93, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 94, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 95, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 96, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 97, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 98, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 99, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 100, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 101, TARGET_STRING("IO601/Write (v3)"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 102, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 103, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 104, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 105, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 106, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 107, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 108, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 109, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 110, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 111, TARGET_STRING("IO601/CANSend/Cur"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 112, TARGET_STRING("IO601/CANSend/SendStop"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 113, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 114, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 115, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 116, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 117, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 118, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 119, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 120, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 121, TARGET_STRING("IO601/CANSend/Write (v3)1"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 122, TARGET_STRING("IO601/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 123, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 124, TARGET_STRING("IO601/DefaultConfig/Constant1"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 125, TARGET_STRING("IO601/DefaultConfig/Constant2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 126, TARGET_STRING("IO601/DefaultConfig/Constant3"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 127, TARGET_STRING("IO601/DefaultConfig/Constant4"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 128, TARGET_STRING("IO601/DefaultConfig/Constant5"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 129, TARGET_STRING("IO601/DefaultConfig/Constant6"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 130, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 131, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 132, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 133, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 134, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 135, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 136, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 137, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 138, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 139, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 140, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 141, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 142, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 143, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 144, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 145, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Time"), 1, 0, 0 },

  { 146, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Before"), 1, 0, 0 },

  { 147, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("After"), 1, 0, 0 },

  { 148, TARGET_STRING("IO601/ReadQueueSS/pos"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 149, TARGET_STRING("IO601/ReadQueueSS/vel"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 150, TARGET_STRING("IO601/ReadQueueSS/STOP"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 151, TARGET_STRING("IO601/ReadQueueSS/ackrecd"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 152, TARGET_STRING("IO601/ReadQueueSS/SendStop"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 153, TARGET_STRING("IO601/ReadQueueSS/Detect Increase"),
    TARGET_STRING("vinit"), 1, 0, 0 },

  { 154, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 155, TARGET_STRING("IO601/ReadQueueSS/Counter"),
    TARGET_STRING("InitialCount"), 5, 0, 0 },

  { 156, TARGET_STRING("IO601/ReadQueueSS/Counter"),
    TARGET_STRING("HitValue"), 5, 0, 0 },

  { 157, TARGET_STRING("IO601/ReadQueueSS/Counter1"),
    TARGET_STRING("InitialCount"), 5, 0, 0 },

  { 158, TARGET_STRING("IO601/ReadQueueSS/Counter1"),
    TARGET_STRING("HitValue"), 5, 0, 0 },

  { 159, TARGET_STRING("IO601/CANSend/STOP/DataLen"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 160, TARGET_STRING("IO601/CANSend/STOP/StopCmd"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 161, TARGET_STRING("IO601/CANSend/movVel/Cmd"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 162, TARGET_STRING("IO601/CANSend/movVel/Constant5"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 163, TARGET_STRING("IO601/CANSend/movVel/Constant6"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 164, TARGET_STRING("IO601/CANSend/movVel/D-Len"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 165, TARGET_STRING("IO601/CANSend/movVel/D-Len1"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 166, TARGET_STRING("IO601/CANSend/movVel/FragEn"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 167, TARGET_STRING("IO601/CANSend/movVel/FragSt"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 168, TARGET_STRING("IO601/CANSend/movVel/GetState Cmd"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 169, TARGET_STRING("IO601/CANSend/movVel/position"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 170, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 171, TARGET_STRING("IO601/Initialize/GetState(ms)/DataLen"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 172, TARGET_STRING("IO601/Initialize/GetState(ms)/GetStateCmd"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 173, TARGET_STRING("IO601/Initialize/GetState(ms)/Time (ms)"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 174, TARGET_STRING("IO601/Initialize/GetState(ms)/states"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 175, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 176, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 177, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 178, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 179, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 180, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 181, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 182, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 183, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 184, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 185, TARGET_STRING("IO601/Initialize/InitialPosition/Constant1"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 186, TARGET_STRING("IO601/Initialize/InitialPosition/Constant2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 187, TARGET_STRING("IO601/Initialize/InitialPosition/Constant5"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 188, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 189, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 190, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 191, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 192, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 193, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 194, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 195, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 196, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 197, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 198, TARGET_STRING("IO601/Initialize/QuitError/Constant2"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 199, TARGET_STRING("IO601/Initialize/QuitError/Constant3"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 200, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P1"), 1, 0, 0 },

  { 201, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P2"), 1, 0, 0 },

  { 202, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P3"), 1, 0, 0 },

  { 203, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P4"), 1, 0, 0 },

  { 204, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P5"), 1, 0, 0 },

  { 205, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P6"), 1, 0, 0 },

  { 206, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P7"), 1, 0, 0 },

  { 207, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P8"), 1, 0, 0 },

  { 208, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P9"), 1, 0, 0 },

  { 209, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/Q"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 210, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/!Q"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 211, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/Logic"),
    TARGET_STRING("TruthTable"), 2, 9, 0 },

  { 212, TARGET_STRING("IO601/J-K Flip-Flop1/J-K Flip-Flop/Memory"),
    TARGET_STRING("X0"), 2, 0, 0 },

  { 213, TARGET_STRING("IO601/ReadQueueSS/CountACK/Detect Increase"),
    TARGET_STRING("vinit"), 1, 0, 0 },

  { 214, TARGET_STRING("IO601/ReadQueueSS/CountACK/Counter1"),
    TARGET_STRING("InitialCount"), 7, 0, 0 },

  { 215, TARGET_STRING("IO601/ReadQueueSS/CountACK/Counter1"),
    TARGET_STRING("HitValue"), 7, 0, 0 },

  { 216, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/Q"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 217, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/!Q"),
    TARGET_STRING("InitialOutput"), 2, 0, 0 },

  { 218, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/Logic"),
    TARGET_STRING("TruthTable"), 2, 9, 0 },

  { 219, TARGET_STRING("IO601/ReadQueueSS/J-K Flip-Flop/J-K Flip-Flop/Memory"),
    TARGET_STRING("X0"), 2, 0, 0 },

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
  &testmodel_1109_B.DataTypeConversion,/* 0: Signal */
  &testmodel_1109_B.DataTypeConversion1_k,/* 1: Signal */
  &testmodel_1109_B.DataTypeConversion2_m,/* 2: Signal */
  &testmodel_1109_B.DataTypeConversion3[0],/* 3: Signal */
  &testmodel_1109_B.DataTypeConversion4,/* 4: Signal */
  &testmodel_1109_B.DataTypeConversion5,/* 5: Signal */
  &testmodel_1109_B.DiscreteTimeIntegrator,/* 6: Signal */
  &testmodel_1109_B.Memory,            /* 7: Signal */
  &testmodel_1109_B.Product1[0],       /* 8: Signal */
  &testmodel_1109_B.Product2,          /* 9: Signal */
  &testmodel_1109_B.Counter1_o1,       /* 10: Signal */
  &testmodel_1109_B.Counter1_o2,       /* 11: Signal */
  &testmodel_1109_B.Counter2_o1,       /* 12: Signal */
  &testmodel_1109_B.Counter2_o2,       /* 13: Signal */
  &testmodel_1109_B.Readv3_o1[0],      /* 14: Signal */
  &testmodel_1109_B.Readv3_o2,         /* 15: Signal */
  &testmodel_1109_B.Writev3[0],        /* 16: Signal */
  &testmodel_1109_B.Step1,             /* 17: Signal */
  &testmodel_1109_B.Step4,             /* 18: Signal */
  &testmodel_1109_B.Step5,             /* 19: Signal */
  &testmodel_1109_B.Product,           /* 20: Signal */
  &testmodel_1109_B.Compare[0],        /* 21: Signal */
  &testmodel_1109_B.Constant_d,        /* 22: Signal */
  &testmodel_1109_B.CANPack_j,         /* 23: Signal */
  &testmodel_1109_B.CANPack1,          /* 24: Signal */
  &testmodel_1109_B.Step,              /* 25: Signal */
  &testmodel_1109_B.Step1_b,           /* 26: Signal */
  &testmodel_1109_B.Step3,             /* 27: Signal */
  &testmodel_1109_B.state[0],          /* 28: Signal */
  &testmodel_1109_B.DataTypeConversion1_i,/* 29: Signal */
  &testmodel_1109_B.DataTypeConversion2,/* 30: Signal */
  &testmodel_1109_B.ForIterator,       /* 31: Signal */
  &testmodel_1109_B.IndexVector,       /* 32: Signal */
  &testmodel_1109_B.CANUnpack2[0],     /* 33: Signal */
  &testmodel_1109_B.CANUnpack3[0],     /* 34: Signal */
  &testmodel_1109_B.Counter_o1,        /* 35: Signal */
  &testmodel_1109_B.Counter_o2,        /* 36: Signal */
  &testmodel_1109_B.Counter1_o1_a,     /* 37: Signal */
  &testmodel_1109_B.Counter1_o2_b,     /* 38: Signal */
  &testmodel_1109_B.ReadACK_o1,        /* 39: Signal */
  &testmodel_1109_B.ReadACK_o2,        /* 40: Signal */
  &testmodel_1109_B.ReadACK_o3,        /* 41: Signal */
  &testmodel_1109_B.ReadACK_o4,        /* 42: Signal */
  &testmodel_1109_B.CANPack2_p,        /* 43: Signal */
  &testmodel_1109_B.vel,               /* 44: Signal */
  &testmodel_1109_B.cur,               /* 45: Signal */
  &testmodel_1109_B.y[0],              /* 46: Signal */
  &testmodel_1109_B.CANPack1_n,        /* 47: Signal */
  &testmodel_1109_B.CANPack2_j,        /* 48: Signal */
  &testmodel_1109_B.CANPack3,          /* 49: Signal */
  &testmodel_1109_B.Constant1_n,       /* 50: Signal */
  &testmodel_1109_B.CANPack2,          /* 51: Signal */
  &testmodel_1109_B.Constant,          /* 52: Signal */
  &testmodel_1109_B.CANPack_e,         /* 53: Signal */
  &testmodel_1109_B.Constant1,         /* 54: Signal */
  &testmodel_1109_B.CANPack,           /* 55: Signal */
  &testmodel_1109_B.JKFlipFlop.Logic[0],/* 56: Signal */
  &testmodel_1109_B.JKFlipFlop.Memory, /* 57: Signal */
  &testmodel_1109_B.DataTypeConversion1,/* 58: Signal */
  &testmodel_1109_B.Counter1_o1_m,     /* 59: Signal */
  &testmodel_1109_B.Counter1_o2_f,     /* 60: Signal */
  &testmodel_1109_B.FixPtRelationalOperator_k,/* 61: Signal */
  &testmodel_1109_B.Uk1_n,             /* 62: Signal */
  &testmodel_1109_B.FixPtRelationalOperator,/* 63: Signal */
  &testmodel_1109_B.Uk1,               /* 64: Signal */
  &testmodel_1109_B.JKFlipFlop_l.Logic[0],/* 65: Signal */
  &testmodel_1109_B.JKFlipFlop_l.Memory,/* 66: Signal */
  &testmodel_1109_P.JKFlipFlop_initial_condition_a,/* 67: Mask Parameter */
  &testmodel_1109_P.SendOut_Value,     /* 68: Block Parameter */
  &testmodel_1109_P.DiscreteTimeIntegrator_IC,/* 69: Block Parameter */
  &testmodel_1109_P.Memory_X0,         /* 70: Block Parameter */
  &testmodel_1109_P.Counter1_InitialCount_d,/* 71: Block Parameter */
  &testmodel_1109_P.Counter1_HitValue_nf,/* 72: Block Parameter */
  &testmodel_1109_P.Counter2_InitialCount,/* 73: Block Parameter */
  &testmodel_1109_P.Counter2_HitValue, /* 74: Block Parameter */
  &testmodel_1109_P.Readv3_P1,         /* 75: Block Parameter */
  &testmodel_1109_P.Readv3_P2,         /* 76: Block Parameter */
  &testmodel_1109_P.Readv3_P3,         /* 77: Block Parameter */
  &testmodel_1109_P.Readv3_P4,         /* 78: Block Parameter */
  &testmodel_1109_P.Readv3_P5,         /* 79: Block Parameter */
  &testmodel_1109_P.Readv3_P6,         /* 80: Block Parameter */
  &testmodel_1109_P.Readv3_P7,         /* 81: Block Parameter */
  &testmodel_1109_P.Setupv3_P1,        /* 82: Block Parameter */
  &testmodel_1109_P.Setupv3_P2,        /* 83: Block Parameter */
  &testmodel_1109_P.Setupv3_P3[0],     /* 84: Block Parameter */
  &testmodel_1109_P.Setupv3_P4[0],     /* 85: Block Parameter */
  &testmodel_1109_P.Setupv3_P5[0],     /* 86: Block Parameter */
  &testmodel_1109_P.Setupv3_P6,        /* 87: Block Parameter */
  &testmodel_1109_P.Setupv3_P7,        /* 88: Block Parameter */
  &testmodel_1109_P.Setupv3_P8[0],     /* 89: Block Parameter */
  &testmodel_1109_P.Setupv3_P9[0],     /* 90: Block Parameter */
  &testmodel_1109_P.Setupv3_P10[0],    /* 91: Block Parameter */
  &testmodel_1109_P.Setupv3_P11,       /* 92: Block Parameter */
  &testmodel_1109_P.Writev3_P1_kn,     /* 93: Block Parameter */
  &testmodel_1109_P.Writev3_P2_j,      /* 94: Block Parameter */
  &testmodel_1109_P.Writev3_P3_j,      /* 95: Block Parameter */
  &testmodel_1109_P.Writev3_P4_o,      /* 96: Block Parameter */
  &testmodel_1109_P.Writev3_P5_g,      /* 97: Block Parameter */
  &testmodel_1109_P.Writev3_P6_i,      /* 98: Block Parameter */
  &testmodel_1109_P.Writev3_P7_c,      /* 99: Block Parameter */
  &testmodel_1109_P.Writev3_P8_l,      /* 100: Block Parameter */
  &testmodel_1109_P.Writev3_P9_h,      /* 101: Block Parameter */
  &testmodel_1109_P.Step1_Time,        /* 102: Block Parameter */
  &testmodel_1109_P.Step1_Y0,          /* 103: Block Parameter */
  &testmodel_1109_P.Step1_YFinal,      /* 104: Block Parameter */
  &testmodel_1109_P.Step4_Time,        /* 105: Block Parameter */
  &testmodel_1109_P.Step4_Y0,          /* 106: Block Parameter */
  &testmodel_1109_P.Step4_YFinal,      /* 107: Block Parameter */
  &testmodel_1109_P.Step5_Time,        /* 108: Block Parameter */
  &testmodel_1109_P.Step5_Y0,          /* 109: Block Parameter */
  &testmodel_1109_P.Step5_YFinal,      /* 110: Block Parameter */
  &testmodel_1109_P.Cur_Value,         /* 111: Block Parameter */
  &testmodel_1109_P.SendStop_Value,    /* 112: Block Parameter */
  &testmodel_1109_P.Writev31_P1,       /* 113: Block Parameter */
  &testmodel_1109_P.Writev31_P2,       /* 114: Block Parameter */
  &testmodel_1109_P.Writev31_P3,       /* 115: Block Parameter */
  &testmodel_1109_P.Writev31_P4,       /* 116: Block Parameter */
  &testmodel_1109_P.Writev31_P5,       /* 117: Block Parameter */
  &testmodel_1109_P.Writev31_P6,       /* 118: Block Parameter */
  &testmodel_1109_P.Writev31_P7,       /* 119: Block Parameter */
  &testmodel_1109_P.Writev31_P8,       /* 120: Block Parameter */
  &testmodel_1109_P.Writev31_P9,       /* 121: Block Parameter */
  &testmodel_1109_P.Constant_Value_j,  /* 122: Block Parameter */
  &testmodel_1109_P.Constant_Value,    /* 123: Block Parameter */
  &testmodel_1109_P.Constant1_Value,   /* 124: Block Parameter */
  &testmodel_1109_P.Constant2_Value,   /* 125: Block Parameter */
  &testmodel_1109_P.Constant3_Value,   /* 126: Block Parameter */
  &testmodel_1109_P.Constant4_Value,   /* 127: Block Parameter */
  &testmodel_1109_P.Constant5_Value_k, /* 128: Block Parameter */
  &testmodel_1109_P.Constant6_Value_k, /* 129: Block Parameter */
  &testmodel_1109_P.Writev3_P1,        /* 130: Block Parameter */
  &testmodel_1109_P.Writev3_P2,        /* 131: Block Parameter */
  &testmodel_1109_P.Writev3_P3,        /* 132: Block Parameter */
  &testmodel_1109_P.Writev3_P4,        /* 133: Block Parameter */
  &testmodel_1109_P.Writev3_P5,        /* 134: Block Parameter */
  &testmodel_1109_P.Writev3_P6,        /* 135: Block Parameter */
  &testmodel_1109_P.Writev3_P7,        /* 136: Block Parameter */
  &testmodel_1109_P.Writev3_P8,        /* 137: Block Parameter */
  &testmodel_1109_P.Writev3_P9,        /* 138: Block Parameter */
  &testmodel_1109_P.Step_Time,         /* 139: Block Parameter */
  &testmodel_1109_P.Step_Y0,           /* 140: Block Parameter */
  &testmodel_1109_P.Step_YFinal,       /* 141: Block Parameter */
  &testmodel_1109_P.Step1_Time_g,      /* 142: Block Parameter */
  &testmodel_1109_P.Step1_Y0_m,        /* 143: Block Parameter */
  &testmodel_1109_P.Step1_YFinal_h,    /* 144: Block Parameter */
  &testmodel_1109_P.Step3_Time,        /* 145: Block Parameter */
  &testmodel_1109_P.Step3_Y0,          /* 146: Block Parameter */
  &testmodel_1109_P.Step3_YFinal,      /* 147: Block Parameter */
  &testmodel_1109_P.pos_Y0,            /* 148: Block Parameter */
  &testmodel_1109_P.vel_Y0,            /* 149: Block Parameter */
  &testmodel_1109_P.STOP_Y0,           /* 150: Block Parameter */
  &testmodel_1109_P.ackrecd_Y0,        /* 151: Block Parameter */
  &testmodel_1109_P.SendStop_Y0,       /* 152: Block Parameter */
  &testmodel_1109_P.DetectIncrease_vinit_e,/* 153: Mask Parameter */
  &testmodel_1109_P.JKFlipFlop_initial_condition,/* 154: Mask Parameter */
  &testmodel_1109_P.Counter_InitialCount,/* 155: Block Parameter */
  &testmodel_1109_P.Counter_HitValue,  /* 156: Block Parameter */
  &testmodel_1109_P.Counter1_InitialCount_a,/* 157: Block Parameter */
  &testmodel_1109_P.Counter1_HitValue_n,/* 158: Block Parameter */
  &testmodel_1109_P.DataLen_Value,     /* 159: Block Parameter */
  &testmodel_1109_P.StopCmd_Value,     /* 160: Block Parameter */
  &testmodel_1109_P.Cmd_Value,         /* 161: Block Parameter */
  &testmodel_1109_P.Constant5_Value,   /* 162: Block Parameter */
  &testmodel_1109_P.Constant6_Value,   /* 163: Block Parameter */
  &testmodel_1109_P.DLen_Value,        /* 164: Block Parameter */
  &testmodel_1109_P.DLen1_Value,       /* 165: Block Parameter */
  &testmodel_1109_P.FragEn_Value,      /* 166: Block Parameter */
  &testmodel_1109_P.FragSt_Value,      /* 167: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value, /* 168: Block Parameter */
  &testmodel_1109_P.position_Value,    /* 169: Block Parameter */
  &testmodel_1109_P.Constant1_Value_m, /* 170: Block Parameter */
  &testmodel_1109_P.DataLen_Value_c,   /* 171: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value_n,/* 172: Block Parameter */
  &testmodel_1109_P.Timems_Value,      /* 173: Block Parameter */
  &testmodel_1109_P.states_Value,      /* 174: Block Parameter */
  &testmodel_1109_P.Writev3_P1_p,      /* 175: Block Parameter */
  &testmodel_1109_P.Writev3_P2_h,      /* 176: Block Parameter */
  &testmodel_1109_P.Writev3_P3_n,      /* 177: Block Parameter */
  &testmodel_1109_P.Writev3_P4_b,      /* 178: Block Parameter */
  &testmodel_1109_P.Writev3_P5_a,      /* 179: Block Parameter */
  &testmodel_1109_P.Writev3_P6_l,      /* 180: Block Parameter */
  &testmodel_1109_P.Writev3_P7_d,      /* 181: Block Parameter */
  &testmodel_1109_P.Writev3_P8_n,      /* 182: Block Parameter */
  &testmodel_1109_P.Writev3_P9_g,      /* 183: Block Parameter */
  &testmodel_1109_P.Constant_Value_a,  /* 184: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i, /* 185: Block Parameter */
  &testmodel_1109_P.Constant2_Value_g, /* 186: Block Parameter */
  &testmodel_1109_P.Constant5_Value_d, /* 187: Block Parameter */
  &testmodel_1109_P.Writev3_P1_o,      /* 188: Block Parameter */
  &testmodel_1109_P.Writev3_P2_e,      /* 189: Block Parameter */
  &testmodel_1109_P.Writev3_P3_g,      /* 190: Block Parameter */
  &testmodel_1109_P.Writev3_P4_j,      /* 191: Block Parameter */
  &testmodel_1109_P.Writev3_P5_e,      /* 192: Block Parameter */
  &testmodel_1109_P.Writev3_P6_p,      /* 193: Block Parameter */
  &testmodel_1109_P.Writev3_P7_m,      /* 194: Block Parameter */
  &testmodel_1109_P.Writev3_P8_c,      /* 195: Block Parameter */
  &testmodel_1109_P.Writev3_P9_n,      /* 196: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i1,/* 197: Block Parameter */
  &testmodel_1109_P.Constant2_Value_n, /* 198: Block Parameter */
  &testmodel_1109_P.Constant3_Value_f, /* 199: Block Parameter */
  &testmodel_1109_P.Writev3_P1_k,      /* 200: Block Parameter */
  &testmodel_1109_P.Writev3_P2_k,      /* 201: Block Parameter */
  &testmodel_1109_P.Writev3_P3_l,      /* 202: Block Parameter */
  &testmodel_1109_P.Writev3_P4_e,      /* 203: Block Parameter */
  &testmodel_1109_P.Writev3_P5_j,      /* 204: Block Parameter */
  &testmodel_1109_P.Writev3_P6_d,      /* 205: Block Parameter */
  &testmodel_1109_P.Writev3_P7_j,      /* 206: Block Parameter */
  &testmodel_1109_P.Writev3_P8_k,      /* 207: Block Parameter */
  &testmodel_1109_P.Writev3_P9_k,      /* 208: Block Parameter */
  &testmodel_1109_P.JKFlipFlop.Q_Y0,   /* 209: Block Parameter */
  &testmodel_1109_P.JKFlipFlop.Q_Y0_a, /* 210: Block Parameter */
  &testmodel_1109_P.JKFlipFlop.Logic_table[0],/* 211: Block Parameter */
  &testmodel_1109_P.JKFlipFlop.Memory_X0,/* 212: Block Parameter */
  &testmodel_1109_P.DetectIncrease_vinit,/* 213: Mask Parameter */
  &testmodel_1109_P.Counter1_InitialCount,/* 214: Block Parameter */
  &testmodel_1109_P.Counter1_HitValue, /* 215: Block Parameter */
  &testmodel_1109_P.JKFlipFlop_l.Q_Y0, /* 216: Block Parameter */
  &testmodel_1109_P.JKFlipFlop_l.Q_Y0_a,/* 217: Block Parameter */
  &testmodel_1109_P.JKFlipFlop_l.Logic_table[0],/* 218: Block Parameter */
  &testmodel_1109_P.JKFlipFlop_l.Memory_X0,/* 219: Block Parameter */
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
  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "numeric", "CAN_DATATYPE", 0, 0, sizeof(CAN_DATATYPE), SS_STRUCT, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 }
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

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1,                                   /* 3 */
  40,                                  /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  2,                                   /* 7 */
  8,                                   /* 8 */
  1,                                   /* 9 */
  7,                                   /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  4,                                   /* 13 */
  2,                                   /* 14 */
  1,                                   /* 15 */
  8,                                   /* 16 */
  2                                    /* 17 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.004, 0.0, 1.024
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    rtwCAPI_FIX_UNIFORM_SCALING, 32, -8, 1 }
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

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
  { rtBlockSignals, 67,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 153,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3843417541U,
    2037663714U,
    2396073549U,
    2093025096U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  testmodel_1109_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void testmodel_1109_InitializeDataMapInfo(RT_MODEL_testmodel_1109_T *const
  testmodel_1109_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(testmodel_1109_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(testmodel_1109_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(testmodel_1109_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(testmodel_1109_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(testmodel_1109_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  testmodel_1109_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (testmodel_1109_M);
  testmodel_1109_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_testmodel_1109_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(testmodel_1109_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(testmodel_1109_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(testmodel_1109_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void testmodel_1109_host_InitializeDataMapInfo
    (testmodel_1109_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: testmodel_1109_capi.c */
