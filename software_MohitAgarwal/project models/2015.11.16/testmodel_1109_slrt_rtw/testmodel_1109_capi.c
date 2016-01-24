/*
 * testmodel_1109_capi.c
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

  { 1, 0, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("IO601/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("IO601/Read (v3)/p1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 4, 0, TARGET_STRING("IO601/Read (v3)/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("IO601/Step1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("IO601/Step2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("IO601/Step4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("IO601/Discrete Derivative/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("IO601/Discrete Derivative/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 10, 0, TARGET_STRING("IO601/Discrete Derivative/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 12, 0, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 14, 0, TARGET_STRING("IO601/Initialize/Step5"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 15, 5, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 16, 5, TARGET_STRING("IO601/PositionControl /CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 17, 8, TARGET_STRING("IO601/ReadQueueSS/MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 9, TARGET_STRING("IO601/STOP/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 19, 9, TARGET_STRING("IO601/STOP/CAN Pack2"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 20, 10, TARGET_STRING("IO601/Velocity control/MATLAB Function1"),
    TARGET_STRING(""), 0, 2, 2, 0, 2 },

  { 21, 11, TARGET_STRING("IO601/Velocity control/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 22, 11, TARGET_STRING("IO601/Velocity control/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 23, 11, TARGET_STRING("IO601/Velocity control/CAN Pack1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 24, 11, TARGET_STRING("IO601/Velocity control/CAN Pack2"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 25, 1, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 26, 1, TARGET_STRING("IO601/Initialize/DefaultConfig/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 27, 1, TARGET_STRING("IO601/Initialize/DefaultConfig/CAN Pack1"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 28, 2, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 29, 2, TARGET_STRING("IO601/Initialize/GetState(ms)/CAN Pack2"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 30, 3, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 31, 3, TARGET_STRING("IO601/Initialize/InitialPosition/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 32, 4, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 33, 4, TARGET_STRING("IO601/Initialize/QuitError/CAN Pack"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 34, 0, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Output"),
    TARGET_STRING(""), 0, 2, 0, 1, 1 },

  { 35, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p1"),
    TARGET_STRING(""), 0, 0, 3, 0, 2 },

  { 36, 6, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/MATLAB Function/p2"),
    TARGET_STRING(""), 1, 3, 4, 0, 2 },

  { 37, 7, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/For Iterator"),
    TARGET_STRING(""), 0, 4, 0, 0, 2 },

  { 38, 7, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Index Vector"),
    TARGET_STRING(""), 0, 1, 0, 0, 2 },

  { 39, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 40, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 2 },

  { 41, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 2 },

  { 42, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 43, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 2 },

  { 44, 7, TARGET_STRING(
    "IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack1/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 2 },

  { 45, 7, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack2"),
    TARGET_STRING(""), 0, 2, 5, 0, 2 },

  { 46, 7, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/CAN Unpack3"),
    TARGET_STRING(""), 0, 2, 5, 0, 2 },

  { 47, 0, TARGET_STRING(
    "IO601/ReadQueueSS/Counter Free-Running/Increment Real World/FixPt Sum1"),
    TARGET_STRING(""), 0, 2, 0, 1, 1 },

  { 48, 0, TARGET_STRING(
    "IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero/FixPt Switch"),
    TARGET_STRING(""), 0, 2, 0, 1, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 49, TARGET_STRING("IO601/Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 50, TARGET_STRING("IO601/Cur"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 51, TARGET_STRING("IO601/vel "),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 52, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 53, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 54, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 55, TARGET_STRING("IO601/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 56, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 57, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 58, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 59, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 60, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 61, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 62, TARGET_STRING("IO601/Read (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 63, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 64, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 65, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P3"), 0, 6, 0 },

  { 66, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P4"), 0, 6, 0 },

  { 67, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P5"), 0, 6, 0 },

  { 68, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 69, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 70, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P8"), 0, 6, 0 },

  { 71, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P9"), 0, 6, 0 },

  { 72, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P10"), 0, 6, 0 },

  { 73, TARGET_STRING("IO601/Setup (v3)"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 74, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 75, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 76, TARGET_STRING("IO601/Step1"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 77, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 78, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 79, TARGET_STRING("IO601/Step2"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 80, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 81, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 82, TARGET_STRING("IO601/Step4"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 83, TARGET_STRING("IO601/Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 84, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 85, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 86, TARGET_STRING("IO601/Initialize/Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 87, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 88, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 89, TARGET_STRING("IO601/Initialize/Step1"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 90, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 91, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 92, TARGET_STRING("IO601/Initialize/Step3"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 93, TARGET_STRING("IO601/Initialize/Step5"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 94, TARGET_STRING("IO601/Initialize/Step5"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 95, TARGET_STRING("IO601/Initialize/Step5"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 96, TARGET_STRING("IO601/PositionControl /Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 97, TARGET_STRING("IO601/PositionControl /Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 98, TARGET_STRING("IO601/PositionControl /Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 99, TARGET_STRING("IO601/PositionControl /Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 100, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 101, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 102, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 103, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 104, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 105, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 106, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 107, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 108, TARGET_STRING("IO601/PositionControl /Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 109, TARGET_STRING("IO601/STOP/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 110, TARGET_STRING("IO601/STOP/DataLen"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 111, TARGET_STRING("IO601/STOP/GetStateCmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 112, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 113, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 114, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 115, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 116, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 117, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 118, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 119, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 120, TARGET_STRING("IO601/STOP/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 121, TARGET_STRING("IO601/Velocity control/Cmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 122, TARGET_STRING("IO601/Velocity control/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 123, TARGET_STRING("IO601/Velocity control/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 124, TARGET_STRING("IO601/Velocity control/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 125, TARGET_STRING("IO601/Velocity control/D-Len"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 126, TARGET_STRING("IO601/Velocity control/D-Len1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 127, TARGET_STRING("IO601/Velocity control/FragEn"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 128, TARGET_STRING("IO601/Velocity control/FragSt"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 129, TARGET_STRING("IO601/Velocity control/GetState Cmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 130, TARGET_STRING("IO601/Velocity control/position"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 131, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 132, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 133, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 134, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 135, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 136, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 137, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 138, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 139, TARGET_STRING("IO601/Velocity control/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 140, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 141, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 142, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 143, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 144, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 145, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 146, TARGET_STRING("IO601/Initialize/DefaultConfig/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 147, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 148, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 149, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 150, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 151, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 152, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 153, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 154, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 155, TARGET_STRING("IO601/Initialize/DefaultConfig/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 156, TARGET_STRING("IO601/Initialize/GetState(ms)/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 157, TARGET_STRING("IO601/Initialize/GetState(ms)/DataLen"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 158, TARGET_STRING("IO601/Initialize/GetState(ms)/GetStateCmd"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 159, TARGET_STRING("IO601/Initialize/GetState(ms)/Time (ms)"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 160, TARGET_STRING("IO601/Initialize/GetState(ms)/states"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 161, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 162, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 163, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 164, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 165, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 166, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 167, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 168, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 169, TARGET_STRING("IO601/Initialize/GetState(ms)/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 170, TARGET_STRING("IO601/Initialize/InitialPosition/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 171, TARGET_STRING("IO601/Initialize/InitialPosition/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 172, TARGET_STRING("IO601/Initialize/InitialPosition/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 173, TARGET_STRING("IO601/Initialize/InitialPosition/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 174, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 175, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 176, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 177, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 178, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 179, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 180, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 181, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 182, TARGET_STRING("IO601/Initialize/InitialPosition/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 183, TARGET_STRING("IO601/Initialize/QuitError/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 184, TARGET_STRING("IO601/Initialize/QuitError/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 185, TARGET_STRING("IO601/Initialize/QuitError/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 186, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 187, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 188, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 189, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 190, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 191, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 192, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 193, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 194, TARGET_STRING("IO601/Initialize/QuitError/Write (v3)"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 195, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero"),
    TARGET_STRING("Threshold"), 2, 0, 1 },

  { 196, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Output"),
    TARGET_STRING("InitialCondition"), 2, 0, 1 },

  { 197, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Out 1"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 198, TARGET_STRING("IO601/ReadQueueSS/For Iterator Subsystem/Out 2"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 199, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Increment Real World/FixPt Constant"),
    TARGET_STRING("Value"), 2, 0, 1 },

  { 200, TARGET_STRING("IO601/ReadQueueSS/Counter Free-Running/Wrap To Zero/Constant"),
    TARGET_STRING("Value"), 2, 0, 1 },

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
  &testmodel_1109_B.Clock,             /* 0: Signal */
  &testmodel_1109_B.PulseGenerator,    /* 1: Signal */
  &testmodel_1109_B.Product,           /* 2: Signal */
  &testmodel_1109_B.Readv3_o1[0],      /* 3: Signal */
  &testmodel_1109_B.Readv3_o2,         /* 4: Signal */
  &testmodel_1109_B.Step1,             /* 5: Signal */
  &testmodel_1109_B.Step2,             /* 6: Signal */
  &testmodel_1109_B.Step4,             /* 7: Signal */
  &testmodel_1109_B.Diff,              /* 8: Signal */
  &testmodel_1109_B.TSamp,             /* 9: Signal */
  &testmodel_1109_B.Uk1,               /* 10: Signal */
  &testmodel_1109_B.Step,              /* 11: Signal */
  &testmodel_1109_B.Step1_b,           /* 12: Signal */
  &testmodel_1109_B.Step3,             /* 13: Signal */
  &testmodel_1109_B.Step5,             /* 14: Signal */
  &testmodel_1109_B.Constant_d,        /* 15: Signal */
  &testmodel_1109_B.CANPack_j,         /* 16: Signal */
  &testmodel_1109_B.noAck,             /* 17: Signal */
  &testmodel_1109_B.Product_l,         /* 18: Signal */
  &testmodel_1109_B.CANPack2_p,        /* 19: Signal */
  &testmodel_1109_B.cur[0],            /* 20: Signal */
  &testmodel_1109_B.Constant,          /* 21: Signal */
  &testmodel_1109_B.CANPack,           /* 22: Signal */
  &testmodel_1109_B.CANPack1,          /* 23: Signal */
  &testmodel_1109_B.CANPack2,          /* 24: Signal */
  &testmodel_1109_B.Constant_dc,       /* 25: Signal */
  &testmodel_1109_B.CANPack_jw,        /* 26: Signal */
  &testmodel_1109_B.CANPack1_m,        /* 27: Signal */
  &testmodel_1109_B.Constant1_n,       /* 28: Signal */
  &testmodel_1109_B.CANPack2_b,        /* 29: Signal */
  &testmodel_1109_B.Constant_i,        /* 30: Signal */
  &testmodel_1109_B.CANPack_e,         /* 31: Signal */
  &testmodel_1109_B.Constant1,         /* 32: Signal */
  &testmodel_1109_B.CANPack_o,         /* 33: Signal */
  &testmodel_1109_B.Output,            /* 34: Signal */
  &testmodel_1109_B.frame[0],          /* 35: Signal */
  &testmodel_1109_B.state[0],          /* 36: Signal */
  &testmodel_1109_B.ForIterator,       /* 37: Signal */
  &testmodel_1109_B.IndexVector,       /* 38: Signal */
  &testmodel_1109_B.CANUnpack_o1,      /* 39: Signal */
  &testmodel_1109_B.CANUnpack_o2,      /* 40: Signal */
  &testmodel_1109_B.CANUnpack_o3,      /* 41: Signal */
  &testmodel_1109_B.CANUnpack1_o1,     /* 42: Signal */
  &testmodel_1109_B.CANUnpack1_o2,     /* 43: Signal */
  &testmodel_1109_B.CANUnpack1_o3,     /* 44: Signal */
  &testmodel_1109_B.CANUnpack2[0],     /* 45: Signal */
  &testmodel_1109_B.CANUnpack3[0],     /* 46: Signal */
  &testmodel_1109_B.FixPtSum1,         /* 47: Signal */
  &testmodel_1109_B.FixPtSwitch,       /* 48: Signal */
  &testmodel_1109_P.DiscreteDerivative_ICPrevScaled,/* 49: Mask Parameter */
  &testmodel_1109_P.Cur_Value,         /* 50: Block Parameter */
  &testmodel_1109_P.vel_Value,         /* 51: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Amp,/* 52: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Period,/* 53: Block Parameter */
  &testmodel_1109_P.PulseGenerator_Duty,/* 54: Block Parameter */
  &testmodel_1109_P.PulseGenerator_PhaseDelay,/* 55: Block Parameter */
  &testmodel_1109_P.Readv3_P1,         /* 56: Block Parameter */
  &testmodel_1109_P.Readv3_P2,         /* 57: Block Parameter */
  &testmodel_1109_P.Readv3_P3,         /* 58: Block Parameter */
  &testmodel_1109_P.Readv3_P4,         /* 59: Block Parameter */
  &testmodel_1109_P.Readv3_P5,         /* 60: Block Parameter */
  &testmodel_1109_P.Readv3_P6,         /* 61: Block Parameter */
  &testmodel_1109_P.Readv3_P7,         /* 62: Block Parameter */
  &testmodel_1109_P.Setupv3_P1,        /* 63: Block Parameter */
  &testmodel_1109_P.Setupv3_P2,        /* 64: Block Parameter */
  &testmodel_1109_P.Setupv3_P3[0],     /* 65: Block Parameter */
  &testmodel_1109_P.Setupv3_P4[0],     /* 66: Block Parameter */
  &testmodel_1109_P.Setupv3_P5[0],     /* 67: Block Parameter */
  &testmodel_1109_P.Setupv3_P6,        /* 68: Block Parameter */
  &testmodel_1109_P.Setupv3_P7,        /* 69: Block Parameter */
  &testmodel_1109_P.Setupv3_P8[0],     /* 70: Block Parameter */
  &testmodel_1109_P.Setupv3_P9[0],     /* 71: Block Parameter */
  &testmodel_1109_P.Setupv3_P10[0],    /* 72: Block Parameter */
  &testmodel_1109_P.Setupv3_P11,       /* 73: Block Parameter */
  &testmodel_1109_P.Step1_Time,        /* 74: Block Parameter */
  &testmodel_1109_P.Step1_Y0,          /* 75: Block Parameter */
  &testmodel_1109_P.Step1_YFinal,      /* 76: Block Parameter */
  &testmodel_1109_P.Step2_Time,        /* 77: Block Parameter */
  &testmodel_1109_P.Step2_Y0,          /* 78: Block Parameter */
  &testmodel_1109_P.Step2_YFinal,      /* 79: Block Parameter */
  &testmodel_1109_P.Step4_Time,        /* 80: Block Parameter */
  &testmodel_1109_P.Step4_Y0,          /* 81: Block Parameter */
  &testmodel_1109_P.Step4_YFinal,      /* 82: Block Parameter */
  &testmodel_1109_P.TSamp_WtEt,        /* 83: Block Parameter */
  &testmodel_1109_P.Step_Time,         /* 84: Block Parameter */
  &testmodel_1109_P.Step_Y0,           /* 85: Block Parameter */
  &testmodel_1109_P.Step_YFinal,       /* 86: Block Parameter */
  &testmodel_1109_P.Step1_Time_g,      /* 87: Block Parameter */
  &testmodel_1109_P.Step1_Y0_m,        /* 88: Block Parameter */
  &testmodel_1109_P.Step1_YFinal_h,    /* 89: Block Parameter */
  &testmodel_1109_P.Step3_Time,        /* 90: Block Parameter */
  &testmodel_1109_P.Step3_Y0,          /* 91: Block Parameter */
  &testmodel_1109_P.Step3_YFinal,      /* 92: Block Parameter */
  &testmodel_1109_P.Step5_Time,        /* 93: Block Parameter */
  &testmodel_1109_P.Step5_Y0,          /* 94: Block Parameter */
  &testmodel_1109_P.Step5_YFinal,      /* 95: Block Parameter */
  &testmodel_1109_P.Constant_Value_e,  /* 96: Block Parameter */
  &testmodel_1109_P.Constant1_Value_c, /* 97: Block Parameter */
  &testmodel_1109_P.Constant2_Value_d, /* 98: Block Parameter */
  &testmodel_1109_P.Constant5_Value_k, /* 99: Block Parameter */
  &testmodel_1109_P.Writev3_P1_d,      /* 100: Block Parameter */
  &testmodel_1109_P.Writev3_P2_b,      /* 101: Block Parameter */
  &testmodel_1109_P.Writev3_P3_h,      /* 102: Block Parameter */
  &testmodel_1109_P.Writev3_P4_g,      /* 103: Block Parameter */
  &testmodel_1109_P.Writev3_P5_n,      /* 104: Block Parameter */
  &testmodel_1109_P.Writev3_P6_f,      /* 105: Block Parameter */
  &testmodel_1109_P.Writev3_P7_e,      /* 106: Block Parameter */
  &testmodel_1109_P.Writev3_P8_h,      /* 107: Block Parameter */
  &testmodel_1109_P.Writev3_P9_i,      /* 108: Block Parameter */
  &testmodel_1109_P.Constant1_Value_e, /* 109: Block Parameter */
  &testmodel_1109_P.DataLen_Value_k,   /* 110: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value_d,/* 111: Block Parameter */
  &testmodel_1109_P.Writev3_P1_j,      /* 112: Block Parameter */
  &testmodel_1109_P.Writev3_P2_i,      /* 113: Block Parameter */
  &testmodel_1109_P.Writev3_P3_f,      /* 114: Block Parameter */
  &testmodel_1109_P.Writev3_P4_bx,     /* 115: Block Parameter */
  &testmodel_1109_P.Writev3_P5_ag,     /* 116: Block Parameter */
  &testmodel_1109_P.Writev3_P6_b,      /* 117: Block Parameter */
  &testmodel_1109_P.Writev3_P7_b,      /* 118: Block Parameter */
  &testmodel_1109_P.Writev3_P8_nf,     /* 119: Block Parameter */
  &testmodel_1109_P.Writev3_P9_m,      /* 120: Block Parameter */
  &testmodel_1109_P.Cmd_Value,         /* 121: Block Parameter */
  &testmodel_1109_P.Constant_Value_b,  /* 122: Block Parameter */
  &testmodel_1109_P.Constant5_Value_c, /* 123: Block Parameter */
  &testmodel_1109_P.Constant6_Value_a, /* 124: Block Parameter */
  &testmodel_1109_P.DLen_Value,        /* 125: Block Parameter */
  &testmodel_1109_P.DLen1_Value,       /* 126: Block Parameter */
  &testmodel_1109_P.FragEn_Value,      /* 127: Block Parameter */
  &testmodel_1109_P.FragSt_Value,      /* 128: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value_p,/* 129: Block Parameter */
  &testmodel_1109_P.position_Value,    /* 130: Block Parameter */
  &testmodel_1109_P.Writev3_P1_kn,     /* 131: Block Parameter */
  &testmodel_1109_P.Writev3_P2_j,      /* 132: Block Parameter */
  &testmodel_1109_P.Writev3_P3_j,      /* 133: Block Parameter */
  &testmodel_1109_P.Writev3_P4_o,      /* 134: Block Parameter */
  &testmodel_1109_P.Writev3_P5_g,      /* 135: Block Parameter */
  &testmodel_1109_P.Writev3_P6_i,      /* 136: Block Parameter */
  &testmodel_1109_P.Writev3_P7_c,      /* 137: Block Parameter */
  &testmodel_1109_P.Writev3_P8_l,      /* 138: Block Parameter */
  &testmodel_1109_P.Writev3_P9_h,      /* 139: Block Parameter */
  &testmodel_1109_P.Constant_Value,    /* 140: Block Parameter */
  &testmodel_1109_P.Constant1_Value,   /* 141: Block Parameter */
  &testmodel_1109_P.Constant2_Value,   /* 142: Block Parameter */
  &testmodel_1109_P.Constant3_Value,   /* 143: Block Parameter */
  &testmodel_1109_P.Constant4_Value,   /* 144: Block Parameter */
  &testmodel_1109_P.Constant5_Value,   /* 145: Block Parameter */
  &testmodel_1109_P.Constant6_Value,   /* 146: Block Parameter */
  &testmodel_1109_P.Writev3_P1,        /* 147: Block Parameter */
  &testmodel_1109_P.Writev3_P2,        /* 148: Block Parameter */
  &testmodel_1109_P.Writev3_P3,        /* 149: Block Parameter */
  &testmodel_1109_P.Writev3_P4,        /* 150: Block Parameter */
  &testmodel_1109_P.Writev3_P5,        /* 151: Block Parameter */
  &testmodel_1109_P.Writev3_P6,        /* 152: Block Parameter */
  &testmodel_1109_P.Writev3_P7,        /* 153: Block Parameter */
  &testmodel_1109_P.Writev3_P8,        /* 154: Block Parameter */
  &testmodel_1109_P.Writev3_P9,        /* 155: Block Parameter */
  &testmodel_1109_P.Constant1_Value_m, /* 156: Block Parameter */
  &testmodel_1109_P.DataLen_Value,     /* 157: Block Parameter */
  &testmodel_1109_P.GetStateCmd_Value, /* 158: Block Parameter */
  &testmodel_1109_P.Timems_Value,      /* 159: Block Parameter */
  &testmodel_1109_P.states_Value,      /* 160: Block Parameter */
  &testmodel_1109_P.Writev3_P1_p,      /* 161: Block Parameter */
  &testmodel_1109_P.Writev3_P2_h,      /* 162: Block Parameter */
  &testmodel_1109_P.Writev3_P3_n,      /* 163: Block Parameter */
  &testmodel_1109_P.Writev3_P4_b,      /* 164: Block Parameter */
  &testmodel_1109_P.Writev3_P5_a,      /* 165: Block Parameter */
  &testmodel_1109_P.Writev3_P6_l,      /* 166: Block Parameter */
  &testmodel_1109_P.Writev3_P7_d,      /* 167: Block Parameter */
  &testmodel_1109_P.Writev3_P8_n,      /* 168: Block Parameter */
  &testmodel_1109_P.Writev3_P9_g,      /* 169: Block Parameter */
  &testmodel_1109_P.Constant_Value_a,  /* 170: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i, /* 171: Block Parameter */
  &testmodel_1109_P.Constant2_Value_g, /* 172: Block Parameter */
  &testmodel_1109_P.Constant5_Value_d, /* 173: Block Parameter */
  &testmodel_1109_P.Writev3_P1_o,      /* 174: Block Parameter */
  &testmodel_1109_P.Writev3_P2_e,      /* 175: Block Parameter */
  &testmodel_1109_P.Writev3_P3_g,      /* 176: Block Parameter */
  &testmodel_1109_P.Writev3_P4_j,      /* 177: Block Parameter */
  &testmodel_1109_P.Writev3_P5_e,      /* 178: Block Parameter */
  &testmodel_1109_P.Writev3_P6_p,      /* 179: Block Parameter */
  &testmodel_1109_P.Writev3_P7_m,      /* 180: Block Parameter */
  &testmodel_1109_P.Writev3_P8_c,      /* 181: Block Parameter */
  &testmodel_1109_P.Writev3_P9_n,      /* 182: Block Parameter */
  &testmodel_1109_P.Constant1_Value_i1,/* 183: Block Parameter */
  &testmodel_1109_P.Constant2_Value_n, /* 184: Block Parameter */
  &testmodel_1109_P.Constant3_Value_f, /* 185: Block Parameter */
  &testmodel_1109_P.Writev3_P1_k,      /* 186: Block Parameter */
  &testmodel_1109_P.Writev3_P2_k,      /* 187: Block Parameter */
  &testmodel_1109_P.Writev3_P3_l,      /* 188: Block Parameter */
  &testmodel_1109_P.Writev3_P4_e,      /* 189: Block Parameter */
  &testmodel_1109_P.Writev3_P5_j,      /* 190: Block Parameter */
  &testmodel_1109_P.Writev3_P6_d,      /* 191: Block Parameter */
  &testmodel_1109_P.Writev3_P7_j,      /* 192: Block Parameter */
  &testmodel_1109_P.Writev3_P8_k,      /* 193: Block Parameter */
  &testmodel_1109_P.Writev3_P9_k,      /* 194: Block Parameter */
  &testmodel_1109_P.WrapToZero_Threshold,/* 195: Mask Parameter */
  &testmodel_1109_P.Output_InitialCondition,/* 196: Block Parameter */
  &testmodel_1109_P.Out1_Y0,           /* 197: Block Parameter */
  &testmodel_1109_P.Out2_Y0,           /* 198: Block Parameter */
  &testmodel_1109_P.FixPtConstant_Value,/* 199: Block Parameter */
  &testmodel_1109_P.Constant_Value_f,  /* 200: Block Parameter */
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

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
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

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  37,                                  /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  4,                                   /* 5 */
  1,                                   /* 6 */
  16,                                  /* 7 */
  1,                                   /* 8 */
  3,                                   /* 9 */
  8,                                   /* 10 */
  1                                    /* 11 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.004, 1.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[0],
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
  { rtBlockSignals, 49,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 152,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2603035873U,
    1865340938U,
    2893590318U,
    233094515U },
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
