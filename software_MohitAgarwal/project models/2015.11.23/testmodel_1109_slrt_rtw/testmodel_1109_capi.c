/*
 * testmodel_1109_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.200
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Dec 01 13:07:19 2015
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
  { 0, 0, TARGET_STRING("IO601/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("IO601/Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 2, 0, TARGET_STRING("IO601/Data Type Conversion1"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 3, 0, TARGET_STRING("IO601/Data Type Conversion2"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 4, 0, TARGET_STRING("IO601/Discrete-Time Integrator"),
    TARGET_STRING(""), 0, 1, 0, 1, 1 },

  { 5, 0, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("IO601/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("IO601/Read (v3)/p1"),
    TARGET_STRING(""), 0, 2, 1, 0, 1 },

  { 8, 0, TARGET_STRING("IO601/Read (v3)/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("IO601/Step1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 10, 0, TARGET_STRING("IO601/Step2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING("IO601/Step4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("IO601/Step5"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING("IO601/Transport Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 3, TARGET_STRING("IO601/Current control/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 15, 3, TARGET_STRING("IO601/Current control/CAN Pack2"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 16, 3, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING(""), 0, 0, 2, 0, 2 },

  { 17, 4, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 18, 4, TARGET_STRING("IO601/DefaultConfig/CAN Pack"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 19, 4, TARGET_STRING("IO601/DefaultConfig/CAN Pack1"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 20, 0, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 21, 0, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 22, 0, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 23, 8, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 24, 8, TARGET_STRING("IO601/PositionControl /CAN Pack"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 25, 11, TARGET_STRING("IO601/ReadQueueSS/MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 26, 12, TARGET_STRING("IO601/checkACK/MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 27, 1, TARGET_STRING("IO601/Current control/movVel/MATLAB Function1/p1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 28, 1, TARGET_STRING("IO601/Current control/movVel/MATLAB Function1/p2"),
    TARGET_STRING(""), 1, 3, 0, 0, 2 },

  { 29, 2, TARGET_STRING("IO601/Current control/movVel/TC UI32-UI8"),
    TARGET_STRING(""), 0, 4, 3, 0, 2 },

  { 30, 3, TARGET_STRING("IO601/Current control/movVel/CAN Pack1"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 31, 3, TARGET_STRING("IO601/Current control/movVel/CAN Pack2"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 32, 5, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 33, 5, TARGET_STRING("IO601/Initialize/GetState(ms)/CAN Pack2"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 34, 6, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 35, 6, TARGET_STRING("IO601/Initialize/InitialPosition/CAN Pack"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 36, 7, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 37, 7, TARGET_STRING("IO601/Initialize/QuitError/CAN Pack"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 38, 0, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Output"),
    TARGET_STRING(""), 0, 4, 0, 2, 1 },

  { 39, 9, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function1"),
    TARGET_STRING(""), 0, 1, 4, 0, 2 },

  { 40, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/For Iterator"),
    TARGET_STRING(""), 0, 5, 0, 0, 2 },

  { 41, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/Index Vector"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 42, 10, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack2"),
    TARGET_STRING(""), 0, 4, 5, 0, 2 },

  { 43, 10, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack3"),
    TARGET_STRING(""), 0, 4, 6, 0, 2 },

  { 44, 13, TARGET_STRING("IO601/checkACK/STOP/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 45, 13, TARGET_STRING("IO601/checkACK/STOP/CAN Pack2"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 46, 0, TARGET_STRING(
    "IO601/ReadQueueSS/Counter Free-Running/Increment Real World/FixPt Sum1"),
    TARGET_STRING(""), 0, 4, 0, 2, 1 },

  { 47, 0, TARGET_STRING(
    "IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero/FixPt Switch"),
    TARGET_STRING(""), 0, 4, 0, 2, 1 },

  { 48, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/CAN Unpack1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 49, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/CAN Unpack1/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 2 },

  { 50, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/CAN Unpack1/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 2 },

  { 51, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/CAN Unpack1/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 2 },

  { 52, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Detect Change/FixPt Relational Operator"),
    TARGET_STRING(""), 0, 6, 0, 0, 2 },

  { 53, 10, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Detect Change/Delay Input1"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 2 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 54, TARGET_STRING("IO601/Cur"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 55, TARGET_STRING("IO601/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 1, 0, 1 },

  { 56, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 57, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 58, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 59, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 60, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 61, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 62, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 63, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 64, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 65, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 66, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 67, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 68, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 69, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P3"), 0, 7, 0 },

  { 70, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P4"), 0, 7, 0 },

  { 71, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P5"), 0, 7, 0 },

  { 72, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 73, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 74, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P8"), 0, 7, 0 },

  { 75, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P9"), 0, 7, 0 },

  { 76, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P10"), 0, 7, 0 },

  { 77, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 78, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 79, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 80, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 81, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 82, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 83, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 84, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 85, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 86, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 87, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 88, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 89, TARGET_STRING("IO601/Step5"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 90, TARGET_STRING("IO601/Transport Delay"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 91, TARGET_STRING("IO601/Current control/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 92, TARGET_STRING("IO601/Current control/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 93, TARGET_STRING("IO601/Current control/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 94, TARGET_STRING("IO601/Current control/GetState Cmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 95, TARGET_STRING("IO601/Current control/position"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 96, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 97, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 98, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 99, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 100, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 101, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 102, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 103, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 104, TARGET_STRING("IO601/Current control/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 105, TARGET_STRING("IO601/DefaultConfig/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 106, TARGET_STRING("IO601/DefaultConfig/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 107, TARGET_STRING("IO601/DefaultConfig/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 108, TARGET_STRING("IO601/DefaultConfig/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 109, TARGET_STRING("IO601/DefaultConfig/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 110, TARGET_STRING("IO601/DefaultConfig/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 111, TARGET_STRING("IO601/DefaultConfig/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 112, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 113, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 114, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 115, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 116, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 117, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 118, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 119, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 120, TARGET_STRING("IO601/DefaultConfig/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 121, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 122, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 123, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 124, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 125, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 126, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 127, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 128, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 129, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 130, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 131, TARGET_STRING("IO601/PositionControl /Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 132, TARGET_STRING("IO601/PositionControl /Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 133, TARGET_STRING("IO601/PositionControl /Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 134, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 135, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 136, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 137, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 138, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 139, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 140, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 141, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 142, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 143, TARGET_STRING("IO601/Current control/movVel/Cmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 144, TARGET_STRING("IO601/Current control/movVel/D-Len"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 145, TARGET_STRING("IO601/Current control/movVel/D-Len1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 146, TARGET_STRING("IO601/Current control/movVel/FragEn"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 147, TARGET_STRING("IO601/Current control/movVel/FragSt"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 148, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 149, TARGET_STRING("IO601/Initialize/GetState(ms)/DataLen"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 150, TARGET_STRING("IO601/Initialize/GetState(ms)/GetStateCmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 151, TARGET_STRING("IO601/Initialize/GetState(ms)/Time (ms)"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 152, TARGET_STRING("IO601/Initialize/GetState(ms)/states"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 153, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 154, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 155, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 156, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 157, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 158, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 159, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 160, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 161, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 162, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 163, TARGET_STRING("IO601/Initialize/InitialPosition/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 164, TARGET_STRING("IO601/Initialize/InitialPosition/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 165, TARGET_STRING("IO601/Initialize/InitialPosition/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 166, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 167, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 168, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 169, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 170, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 171, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 172, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 173, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 174, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 175, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 176, TARGET_STRING("IO601/Initialize/QuitError/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 177, TARGET_STRING("IO601/Initialize/QuitError/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 178, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 179, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 180, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 181, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 182, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 183, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 184, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 185, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 186, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 187, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero"),
    TARGET_STRING("Threshold"), 4, 0, 2 },

  { 188, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Output"),
    TARGET_STRING("InitialCondition"), 4, 0, 2 },

  { 189, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/ACK_TS"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 190, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/pos"),
    TARGET_STRING("InitialOutput"), 1, 0, 0 },

  { 191, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/vel"),
    TARGET_STRING("InitialOutput"), 1, 0, 0 },

  { 192, TARGET_STRING("IO601/checkACK/STOP/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 193, TARGET_STRING("IO601/checkACK/STOP/DataLen"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 194, TARGET_STRING("IO601/checkACK/STOP/GetStateCmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 195, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 196, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 197, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 198, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 199, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 200, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 201, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 202, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 203, TARGET_STRING("IO601/checkACK/STOP/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 204, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Increment Real World/FixPt Constant"),
    TARGET_STRING("Value"), 4, 0, 2 },

  { 205, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 2 },

  { 206, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/ReadACK/Detect Change"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 207, TARGET_STRING("Ts"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &testmodel_1109_B.Clock,             /* 0: Signal */
  &testmodel_1109_B.DataTypeConversion,/* 1: Signal */
  &testmodel_1109_B.DataTypeConversion1,/* 2: Signal */
  &testmodel_1109_B.DataTypeConversion2,/* 3: Signal */
  &testmodel_1109_B.DiscreteTimeIntegrator,/* 4: Signal */
  &testmodel_1109_B.PulseGenerator,    /* 5: Signal */
  &testmodel_1109_B.Product,           /* 6: Signal */
  &testmodel_1109_B.Readv3_o1[0],      /* 7: Signal */
  &testmodel_1109_B.Readv3_o2,         /* 8: Signal */
  &testmodel_1109_B.Step1,             /* 9: Signal */
  &testmodel_1109_B.Step2,             /* 10: Signal */
  &testmodel_1109_B.Step4,             /* 11: Signal */
  &testmodel_1109_B.Step5,             /* 12: Signal */
  &testmodel_1109_B.TransportDelay,    /* 13: Signal */
  &testmodel_1109_B.Constant_n,        /* 14: Signal */
  &testmodel_1109_B.CANPack2_e,        /* 15: Signal */
  &testmodel_1109_B.Writev3[0],        /* 16: Signal */
  &testmodel_1109_B.Constant_d,        /* 17: Signal */
  &testmodel_1109_B.CANPack_j,         /* 18: Signal */
  &testmodel_1109_B.CANPack1,          /* 19: Signal */
  &testmodel_1109_B.Step,              /* 20: Signal */
  &testmodel_1109_B.Step1_b,           /* 21: Signal */
  &testmodel_1109_B.Step3,             /* 22: Signal */
  &testmodel_1109_B.Constant,          /* 23: Signal */
  &testmodel_1109_B.CANPack,           /* 24: Signal */
  &testmodel_1109_B.noAck,             /* 25: Signal */
  &testmodel_1109_B.stop,              /* 26: Signal */
  &testmodel_1109_B.vel,               /* 27: Signal */
  &testmodel_1109_B.cur,               /* 28: Signal */
  &testmodel_1109_B.y[0],              /* 29: Signal */
  &testmodel_1109_B.CANPack1_n,        /* 30: Signal */
  &testmodel_1109_B.CANPack2_j,        /* 31: Signal */
  &testmodel_1109_B.Constant1_n,       /* 32: Signal */
  &testmodel_1109_B.CANPack2_b,        /* 33: Signal */
  &testmodel_1109_B.Constant_i,        /* 34: Signal */
  &testmodel_1109_B.CANPack_e,         /* 35: Signal */
  &testmodel_1109_B.Constant1,         /* 36: Signal */
  &testmodel_1109_B.CANPack_o,         /* 37: Signal */
  &testmodel_1109_B.Output,            /* 38: Signal */
  &testmodel_1109_B.state[0],          /* 39: Signal */
  &testmodel_1109_B.ForIterator,       /* 40: Signal */
  &testmodel_1109_B.IndexVector,       /* 41: Signal */
  &testmodel_1109_B.CANUnpack2[0],     /* 42: Signal */
  &testmodel_1109_B.CANUnpack3[0],     /* 43: Signal */
  &testmodel_1109_B.Product_h,         /* 44: Signal */
  &testmodel_1109_B.CANPack2,          /* 45: Signal */
  &testmodel_1109_B.FixPtSum1,         /* 46: Signal */
  &testmodel_1109_B.FixPtSwitch,       /* 47: Signal */
  &testmodel_1109_B.CANUnpack1_o1,     /* 48: Signal */
  &testmodel_1109_B.CANUnpack1_o2,     /* 49: Signal */
  &testmodel_1109_B.CANUnpack1_o3,     /* 50: Signal */
  &testmodel_1109_B.CANUnpack1_o4,     /* 51: Signal */
  &testmodel_1109_B.FixPtRelationalOperator,/* 52: Signal */
  &testmodel_1109_B.Uk1,               /* 53: Signal */
  &testmodel_1109_P.Cur_Value,         /* 54: Block Parameter */
  &testmodel_1109_P.DiscreteTimeIntegrator_IC,/* 55: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Amp,/* 56: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Period,/* 57: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Duty,/* 58: Block Parameter */
  &testmodel_1109_P.PulseGenerator_PhaseDelay,/* 59: Block Parameter */
  &testmodel_1109_P.Readv3_P1,         /* 60: Block Parameter */
  &testmodel_1109_P.Readv3_P2,         /* 61: Block Parameter */
  &testmodel_1109_P.Readv3_P3,         /* 62: Block Parameter */
  &testmodel_1109_P.Readv3_P4,         /* 63: Block Parameter */
  &testmodel_1109_P.Readv3_P5,         /* 64: Block Parameter */
  &testmodel_1109_P.Readv3_P6,         /* 65: Block Parameter */
  &testmodel_1109_P.Readv3_P7,         /* 66: Block Parameter */
  &testmodel_1109_P.Setupv3_P1,        /* 67: Block Parameter */
  &testmodel_1109_P.Setupv3_P2,        /* 68: Block Parameter */
  &testmodel_1109_P.Setupv3_P3[0],     /* 69: Block Parameter */
  &testmodel_1109_P.Setupv3_P4[0],     /* 70: Block Parameter */
  &testmodel_1109_P.Setupv3_P5[0],     /* 71: Block Parameter */
  &testmodel_1109_P.Setupv3_P6,        /* 72: Block Parameter */
  &testmodel_1109_P.Setupv3_P7,        /* 73: Block Parameter */
  &testmodel_1109_P.Setupv3_P8[0],     /* 74: Block Parameter */
  &testmodel_1109_P.Setupv3_P9[0],     /* 75: Block Parameter */
  &testmodel_1109_P.Setupv3_P10[0],    /* 76: Block Parameter */
  &testmodel_1109_P.Setupv3_P11,       /* 77: Block Parameter */
  &testmodel_1109_P.Step1_Time,        /* 78: Block Parameter */
  &testmodel_1109_P.Step1_Y0,          /* 79: Block Parameter */
  &testmodel_1109_P.Step1_YFinal,      /* 80: Block Parameter */
  &testmodel_1109_P.Step2_Time,        /* 81: Block Parameter */
  &testmodel_1109_P.Step2_Y0,          /* 82: Block Parameter */
  &testmodel_1109_P.Step2_YFinal,      /* 83: Block Parameter */
  &testmodel_1109_P.Step4_Time,        /* 84: Block Parameter */
  &testmodel_1109_P.Step4_Y0,          /* 85: Block Parameter */
  &testmodel_1109_P.Step4_YFinal,      /* 86: Block Parameter */
  &testmodel_1109_P.Step5_Time,        /* 87: Block Parameter */
  &testmodel_1109_P.Step5_Y0,          /* 88: Block Parameter */
  &testmodel_1109_P.Step5_YFinal,      /* 89: Block Parameter */
  &testmodel_1109_P.TransportDelay_InitOutput,/* 90: Block Parameter */
  &testmodel_1109_P.Constant_Value,    /* 91: Block Parameter */
  &testmodel_1109_P.Constant5_Value,   /* 92: Block Parameter */
  &testmodel_1109_P.Constant6_Value,   /* 93: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value, /* 94: Block Parameter */
  &testmodel_1109_P.position_Value,    /* 95: Block Parameter */
  &testmodel_1109_P.Writev3_P1,        /* 96: Block Parameter */
  &testmodel_1109_P.Writev3_P2,        /* 97: Block Parameter */
  &testmodel_1109_P.Writev3_P3,        /* 98: Block Parameter */
  &testmodel_1109_P.Writev3_P4,        /* 99: Block Parameter */
  &testmodel_1109_P.Writev3_P5,        /* 100: Block Parameter */
  &testmodel_1109_P.Writev3_P6,        /* 101: Block Parameter */
  &testmodel_1109_P.Writev3_P7,        /* 102: Block Parameter */
  &testmodel_1109_P.Writev3_P8,        /* 103: Block Parameter */
  &testmodel_1109_P.Writev3_P9,        /* 104: Block Parameter */
  &testmodel_1109_P.Constant_Value_a,  /* 105: Block Parameter */
  &testmodel_1109_P.Constant1_Value,   /* 106: Block Parameter */
  &testmodel_1109_P.Constant2_Value,   /* 107: Block Parameter */
  &testmodel_1109_P.Constant3_Value,   /* 108: Block Parameter */
  &testmodel_1109_P.Constant4_Value,   /* 109: Block Parameter */
  &testmodel_1109_P.Constant5_Value_k, /* 110: Block Parameter */
  &testmodel_1109_P.Constant6_Value_k, /* 111: Block Parameter */
  &testmodel_1109_P.Writev3_P1_h,      /* 112: Block Parameter */
  &testmodel_1109_P.Writev3_P2_f,      /* 113: Block Parameter */
  &testmodel_1109_P.Writev3_P3_j,      /* 114: Block Parameter */
  &testmodel_1109_P.Writev3_P4_o,      /* 115: Block Parameter */
  &testmodel_1109_P.Writev3_P5_b,      /* 116: Block Parameter */
  &testmodel_1109_P.Writev3_P6_c,      /* 117: Block Parameter */
  &testmodel_1109_P.Writev3_P7_d,      /* 118: Block Parameter */
  &testmodel_1109_P.Writev3_P8_f,      /* 119: Block Parameter */
  &testmodel_1109_P.Writev3_P9_h,      /* 120: Block Parameter */
  &testmodel_1109_P.Step_Time,         /* 121: Block Parameter */
  &testmodel_1109_P.Step_Y0,           /* 122: Block Parameter */
  &testmodel_1109_P.Step_YFinal,       /* 123: Block Parameter */
  &testmodel_1109_P.Step1_Time_g,      /* 124: Block Parameter */
  &testmodel_1109_P.Step1_Y0_m,        /* 125: Block Parameter */
  &testmodel_1109_P.Step1_YFinal_h,    /* 126: Block Parameter */
  &testmodel_1109_P.Step3_Time,        /* 127: Block Parameter */
  &testmodel_1109_P.Step3_Y0,          /* 128: Block Parameter */
  &testmodel_1109_P.Step3_YFinal,      /* 129: Block Parameter */
  &testmodel_1109_P.Constant_Value_e,  /* 130: Block Parameter */
  &testmodel_1109_P.Constant1_Value_c, /* 131: Block Parameter */
  &testmodel_1109_P.Constant2_Value_d, /* 132: Block Parameter */
  &testmodel_1109_P.Constant5_Value_ks,/* 133: Block Parameter */
  &testmodel_1109_P.Writev3_P1_d,      /* 134: Block Parameter */
  &testmodel_1109_P.Writev3_P2_b,      /* 135: Block Parameter */
  &testmodel_1109_P.Writev3_P3_h,      /* 136: Block Parameter */
  &testmodel_1109_P.Writev3_P4_g,      /* 137: Block Parameter */
  &testmodel_1109_P.Writev3_P5_n,      /* 138: Block Parameter */
  &testmodel_1109_P.Writev3_P6_f,      /* 139: Block Parameter */
  &testmodel_1109_P.Writev3_P7_e,      /* 140: Block Parameter */
  &testmodel_1109_P.Writev3_P8_h,      /* 141: Block Parameter */
  &testmodel_1109_P.Writev3_P9_i,      /* 142: Block Parameter */
  &testmodel_1109_P.Cmd_Value,         /* 143: Block Parameter */
  &testmodel_1109_P.DLen_Value,        /* 144: Block Parameter */
  &testmodel_1109_P.DLen1_Value,       /* 145: Block Parameter */
  &testmodel_1109_P.FragEn_Value,      /* 146: Block Parameter */
  &testmodel_1109_P.FragSt_Value,      /* 147: Block Parameter */
  &testmodel_1109_P.Constant1_Value_m, /* 148: Block Parameter */
  &testmodel_1109_P.DataLen_Value,     /* 149: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value_n,/* 150: Block Parameter */
  &testmodel_1109_P.Timems_Value,      /* 151: Block Parameter */
  &testmodel_1109_P.states_Value,      /* 152: Block Parameter */
  &testmodel_1109_P.Writev3_P1_p,      /* 153: Block Parameter */
  &testmodel_1109_P.Writev3_P2_h,      /* 154: Block Parameter */
  &testmodel_1109_P.Writev3_P3_n,      /* 155: Block Parameter */
  &testmodel_1109_P.Writev3_P4_b,      /* 156: Block Parameter */
  &testmodel_1109_P.Writev3_P5_a,      /* 157: Block Parameter */
  &testmodel_1109_P.Writev3_P6_l,      /* 158: Block Parameter */
  &testmodel_1109_P.Writev3_P7_de,     /* 159: Block Parameter */
  &testmodel_1109_P.Writev3_P8_n,      /* 160: Block Parameter */
  &testmodel_1109_P.Writev3_P9_g,      /* 161: Block Parameter */
  &testmodel_1109_P.Constant_Value_ay, /* 162: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i, /* 163: Block Parameter */
  &testmodel_1109_P.Constant2_Value_g, /* 164: Block Parameter */
  &testmodel_1109_P.Constant5_Value_d, /* 165: Block Parameter */
  &testmodel_1109_P.Writev3_P1_o,      /* 166: Block Parameter */
  &testmodel_1109_P.Writev3_P2_e,      /* 167: Block Parameter */
  &testmodel_1109_P.Writev3_P3_g,      /* 168: Block Parameter */
  &testmodel_1109_P.Writev3_P4_j,      /* 169: Block Parameter */
  &testmodel_1109_P.Writev3_P5_e,      /* 170: Block Parameter */
  &testmodel_1109_P.Writev3_P6_p,      /* 171: Block Parameter */
  &testmodel_1109_P.Writev3_P7_m,      /* 172: Block Parameter */
  &testmodel_1109_P.Writev3_P8_c,      /* 173: Block Parameter */
  &testmodel_1109_P.Writev3_P9_n,      /* 174: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i1,/* 175: Block Parameter */
  &testmodel_1109_P.Constant2_Value_n, /* 176: Block Parameter */
  &testmodel_1109_P.Constant3_Value_f, /* 177: Block Parameter */
  &testmodel_1109_P.Writev3_P1_k,      /* 178: Block Parameter */
  &testmodel_1109_P.Writev3_P2_k,      /* 179: Block Parameter */
  &testmodel_1109_P.Writev3_P3_l,      /* 180: Block Parameter */
  &testmodel_1109_P.Writev3_P4_e,      /* 181: Block Parameter */
  &testmodel_1109_P.Writev3_P5_j,      /* 182: Block Parameter */
  &testmodel_1109_P.Writev3_P6_d,      /* 183: Block Parameter */
  &testmodel_1109_P.Writev3_P7_j,      /* 184: Block Parameter */
  &testmodel_1109_P.Writev3_P8_k,      /* 185: Block Parameter */
  &testmodel_1109_P.Writev3_P9_k,      /* 186: Block Parameter */
  &testmodel_1109_P.WrapToZero_Threshold,/* 187: Mask Parameter */
  &testmodel_1109_P.Output_InitialCondition,/* 188: Block Parameter */
  &testmodel_1109_P.ACK_TS_Y0,         /* 189: Block Parameter */
  &testmodel_1109_P.pos_Y0,            /* 190: Block Parameter */
  &testmodel_1109_P.vel_Y0,            /* 191: Block Parameter */
  &testmodel_1109_P.Constant1_Value_e, /* 192: Block Parameter */
  &testmodel_1109_P.DataLen_Value_k,   /* 193: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value_d,/* 194: Block Parameter */
  &testmodel_1109_P.Writev3_P1_j,      /* 195: Block Parameter */
  &testmodel_1109_P.Writev3_P2_i,      /* 196: Block Parameter */
  &testmodel_1109_P.Writev3_P3_f,      /* 197: Block Parameter */
  &testmodel_1109_P.Writev3_P4_bx,     /* 198: Block Parameter */
  &testmodel_1109_P.Writev3_P5_ag,     /* 199: Block Parameter */
  &testmodel_1109_P.Writev3_P6_b,      /* 200: Block Parameter */
  &testmodel_1109_P.Writev3_P7_b,      /* 201: Block Parameter */
  &testmodel_1109_P.Writev3_P8_nf,     /* 202: Block Parameter */
  &testmodel_1109_P.Writev3_P9_m,      /* 203: Block Parameter */
  &testmodel_1109_P.FixPtConstant_Value,/* 204: Block Parameter */
  &testmodel_1109_P.Constant_Value_f,  /* 205: Block Parameter */
  &testmodel_1109_P.DetectChange_vinit,/* 206: Mask Parameter */
  &testmodel_1109_P.Ts,                /* 207: Model Parameter */
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

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "numeric", "CAN_DATATYPE", 0, 0, sizeof(CAN_DATATYPE), SS_STRUCT, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
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

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  37,                                  /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  4,                                   /* 7 */
  1,                                   /* 8 */
  2,                                   /* 9 */
  8,                                   /* 10 */
  1,                                   /* 11 */
  7,                                   /* 12 */
  1                                    /* 13 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.004, 1.024, 1.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[0],
    rtwCAPI_FIX_UNIFORM_SCALING, 32, -8, 1 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[0],
    rtwCAPI_FIX_UNIFORM_SCALING, 2, 0, 0 }
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
  { rtBlockSignals, 54,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 153,
    rtModelParameters, 1 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 994381667U,
    2288331823U,
    1918311963U,
    3431819818U },
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
