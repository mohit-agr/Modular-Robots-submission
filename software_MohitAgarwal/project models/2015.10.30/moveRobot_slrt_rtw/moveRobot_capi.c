/*
 * moveRobot_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "moveRobot_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "moveRobot.h"
#include "moveRobot_capi.h"
#include "moveRobot_private.h"
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
  { 0, 3, TARGET_STRING("MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 4, TARGET_STRING("MATLAB Function2/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 4, TARGET_STRING("MATLAB Function2/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 3, 5, TARGET_STRING("MovePos"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("Clock1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("Data Type Conversion"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 6, 0, TARGET_STRING("CAN Pack1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 7, 0, TARGET_STRING("Step"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 8, 1, TARGET_STRING("Del Error and Get State/GetState"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 9, 2, TARGET_STRING("Del Error and Get State/Constant4"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 10, 2, TARGET_STRING("Del Error and Get State/CAN Pack"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 11, 2, TARGET_STRING("Del Error and Get State/CAN Pack2"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 12, 6, TARGET_STRING("Triggered Subsystem1/Constant3"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 13, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 14, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 15, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P3"), 0, 1, 0 },

  { 16, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P4"), 0, 1, 0 },

  { 17, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P5"), 0, 1, 0 },

  { 18, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 19, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 20, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P8"), 0, 1, 0 },

  { 21, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P9"), 0, 1, 0 },

  { 22, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 23, TARGET_STRING("Setup (v3)"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 24, TARGET_STRING("Step"),
    TARGET_STRING("Time"), 0, 0, 0 },

  { 25, TARGET_STRING("Step"),
    TARGET_STRING("Before"), 0, 0, 0 },

  { 26, TARGET_STRING("Step"),
    TARGET_STRING("After"), 0, 0, 0 },

  { 27, TARGET_STRING("Del Error and Get State/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 28, TARGET_STRING("Del Error and Get State/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 29, TARGET_STRING("Del Error and Get State/Constant4"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 30, TARGET_STRING("Del Error and Get State/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 31, TARGET_STRING("Del Error and Get State/Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 32, TARGET_STRING("Del Error and Get State/Constant7"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 33, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 34, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 35, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 36, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 37, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 38, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 39, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 40, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 41, TARGET_STRING("Del Error and Get State/Write (v3)2"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 42, TARGET_STRING("Triggered Subsystem1/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 43, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 44, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 45, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 46, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 47, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 48, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 49, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 50, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 51, TARGET_STRING("Triggered Subsystem1/Write (v3)1"),
    TARGET_STRING("P9"), 0, 0, 0 },

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
  &moveRobot_B.l,                      /* 0: Signal */
  &moveRobot_B.y,                      /* 1: Signal */
  &moveRobot_B.trig,                   /* 2: Signal */
  &moveRobot_B.cmd,                    /* 3: Signal */
  &moveRobot_B.Clock1,                 /* 4: Signal */
  &moveRobot_B.DataTypeConversion,     /* 5: Signal */
  &moveRobot_B.CANPack1,               /* 6: Signal */
  &moveRobot_B.Step,                   /* 7: Signal */
  &moveRobot_B.cmd_e,                  /* 8: Signal */
  &moveRobot_B.Constant4,              /* 9: Signal */
  &moveRobot_B.CANPack,                /* 10: Signal */
  &moveRobot_B.CANPack2,               /* 11: Signal */
  &moveRobot_B.Constant3,              /* 12: Signal */
  &moveRobot_P.Setupv3_P1,             /* 13: Block Parameter */
  &moveRobot_P.Setupv3_P2,             /* 14: Block Parameter */
  &moveRobot_P.Setupv3_P3[0],          /* 15: Block Parameter */
  &moveRobot_P.Setupv3_P4[0],          /* 16: Block Parameter */
  &moveRobot_P.Setupv3_P5[0],          /* 17: Block Parameter */
  &moveRobot_P.Setupv3_P6,             /* 18: Block Parameter */
  &moveRobot_P.Setupv3_P7,             /* 19: Block Parameter */
  &moveRobot_P.Setupv3_P8[0],          /* 20: Block Parameter */
  &moveRobot_P.Setupv3_P9[0],          /* 21: Block Parameter */
  &moveRobot_P.Setupv3_P10[0],         /* 22: Block Parameter */
  &moveRobot_P.Setupv3_P11,            /* 23: Block Parameter */
  &moveRobot_P.Step_Time,              /* 24: Block Parameter */
  &moveRobot_P.Step_Y0,                /* 25: Block Parameter */
  &moveRobot_P.Step_YFinal,            /* 26: Block Parameter */
  &moveRobot_P.Constant1_Value,        /* 27: Block Parameter */
  &moveRobot_P.Constant2_Value,        /* 28: Block Parameter */
  &moveRobot_P.Constant4_Value,        /* 29: Block Parameter */
  &moveRobot_P.Constant5_Value,        /* 30: Block Parameter */
  &moveRobot_P.Constant6_Value,        /* 31: Block Parameter */
  &moveRobot_P.Constant7_Value,        /* 32: Block Parameter */
  &moveRobot_P.Writev32_P1,            /* 33: Block Parameter */
  &moveRobot_P.Writev32_P2,            /* 34: Block Parameter */
  &moveRobot_P.Writev32_P3,            /* 35: Block Parameter */
  &moveRobot_P.Writev32_P4,            /* 36: Block Parameter */
  &moveRobot_P.Writev32_P5,            /* 37: Block Parameter */
  &moveRobot_P.Writev32_P6,            /* 38: Block Parameter */
  &moveRobot_P.Writev32_P7,            /* 39: Block Parameter */
  &moveRobot_P.Writev32_P8,            /* 40: Block Parameter */
  &moveRobot_P.Writev32_P9,            /* 41: Block Parameter */
  &moveRobot_P.Constant3_Value,        /* 42: Block Parameter */
  &moveRobot_P.Writev31_P1,            /* 43: Block Parameter */
  &moveRobot_P.Writev31_P2,            /* 44: Block Parameter */
  &moveRobot_P.Writev31_P3,            /* 45: Block Parameter */
  &moveRobot_P.Writev31_P4,            /* 46: Block Parameter */
  &moveRobot_P.Writev31_P5,            /* 47: Block Parameter */
  &moveRobot_P.Writev31_P6,            /* 48: Block Parameter */
  &moveRobot_P.Writev31_P7,            /* 49: Block Parameter */
  &moveRobot_P.Writev31_P8,            /* 50: Block Parameter */
  &moveRobot_P.Writev31_P9,            /* 51: Block Parameter */
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

  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 },

  { "numeric", "CAN_DATATYPE", 0, 0, sizeof(CAN_DATATYPE), SS_STRUCT, 0, 0 }
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

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  4                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  1.0, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
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
  { rtBlockSignals, 13,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 39,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2557694093U,
    2921503060U,
    3682169794U,
    2395990669U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  moveRobot_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void moveRobot_InitializeDataMapInfo(RT_MODEL_moveRobot_T *const moveRobot_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(moveRobot_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(moveRobot_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(moveRobot_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(moveRobot_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(moveRobot_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  moveRobot_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (moveRobot_M);
  moveRobot_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_moveRobot_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(moveRobot_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(moveRobot_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(moveRobot_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void moveRobot_host_InitializeDataMapInfo(moveRobot_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: moveRobot_capi.c */
