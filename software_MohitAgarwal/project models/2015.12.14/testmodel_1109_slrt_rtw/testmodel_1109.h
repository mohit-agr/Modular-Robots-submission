/*
 * testmodel_1109.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.224
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Mon Dec 21 11:15:01 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testmodel_1109_h_
#define RTW_HEADER_testmodel_1109_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef testmodel_1109_COMMON_INCLUDES_
# define testmodel_1109_COMMON_INCLUDES_
#include <string.h>
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "can_message.h"
#endif                                 /* testmodel_1109_COMMON_INCLUDES_ */

#include "testmodel_1109_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_testmodel_1109         RT_MODEL_testmodel_1109_T

/* Definition for use in the target main file */
#define testmodel_1109_rtModel         RT_MODEL_testmodel_1109_T

/* user code (top of export header file) */
#include "can_message.h"
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  CAN_DATATYPE TmpSignalConversionAtWritev3Inp[2];/* '<S1>/CANSend' */
  CAN_DATATYPE Readv3_o1[40];          /* '<S1>/Read (v3)' */
  CAN_DATATYPE IndexVector;            /* '<S8>/Index Vector' */
  CAN_DATATYPE CANPack;                /* '<S19>/CAN Pack' */
  CAN_DATATYPE CANPack_e;              /* '<S18>/CAN Pack' */
  CAN_DATATYPE CANPack2;               /* '<S17>/CAN Pack2' */
  CAN_DATATYPE CANPack1;               /* '<S5>/CAN Pack1' */
  CAN_DATATYPE CANPack_j;              /* '<S5>/CAN Pack' */
  CAN_DATATYPE TmpSignalConversionAtWritev3I_j[2];
  CAN_DATATYPE CANPack2_p;             /* '<S12>/CAN Pack2' */
  CAN_DATATYPE CANPack1_n;             /* '<S13>/CAN Pack1' */
  CAN_DATATYPE CANPack2_j;             /* '<S13>/CAN Pack2' */
  CAN_DATATYPE CANPack2_e;             /* '<S11>/CAN Pack2' */
  real_T Step4;                        /* '<S1>/Step4' */
  real_T DataTypeConversion4;          /* '<S1>/Data Type Conversion4' */
  real_T PulseGenerator;               /* '<S1>/Pulse Generator' */
  real_T Product;                      /* '<S1>/Product' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T Writev3[2];                   /* '<S1>/Write (v3)' */
  real_T Readv3_o2;                    /* '<S1>/Read (v3)' */
  real_T DataTypeConversion3[2];       /* '<S1>/Data Type Conversion3' */
  real_T Product1[2];                  /* '<S1>/Product1' */
  real_T Step5;                        /* '<S1>/Step5' */
  real_T Step1;                        /* '<S6>/Step1' */
  real_T Step3;                        /* '<S6>/Step3' */
  real_T Step;                         /* '<S6>/Step' */
  real_T ReadACK_o1;                   /* '<S8>/ReadACK' */
  real_T ReadACK_o2;                   /* '<S8>/ReadACK' */
  real_T ReadACK_o3;                   /* '<S8>/ReadACK' */
  real_T ReadACK_o4;                   /* '<S8>/ReadACK' */
  real_T Uk1;                          /* '<S23>/Delay Input1' */
  real_T Counter1_o1;                  /* '<S21>/Counter1' */
  real_T DataTypeConversion1;          /* '<S21>/Data Type Conversion1' */
  real_T Constant1;                    /* '<S19>/Constant1' */
  real_T Constant;                     /* '<S18>/Constant' */
  real_T Constant1_n;                  /* '<S17>/Constant1' */
  real_T Constant_d;                   /* '<S5>/Constant' */
  real_T Product_b;                    /* '<S3>/Product' */
  int32_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  int32_T DataTypeConversion1_k;       /* '<S1>/Data Type Conversion1' */
  int32_T DataTypeConversion2;         /* '<S1>/Data Type Conversion2' */
  int32_T OutportBufferForpos;
  int32_T OutportBufferForvel;
  int32_T state[2];                    /* '<S8>/MATLAB Function1' */
  int32_T vel;                         /* '<S13>/MATLAB Function1' */
  uint32_T cur;                        /* '<S13>/MATLAB Function1' */
  int32_T DiscreteTimeIntegrator;      /* '<S1>/Discrete-Time Integrator' */
  int8_T ForIterator;                  /* '<S8>/For Iterator' */
  uint8_T CANUnpack2[8];               /* '<S8>/CAN Unpack2' */
  uint8_T CANUnpack3[7];               /* '<S8>/CAN Unpack3' */
  uint8_T y[4];                        /* '<S13>/TC UI32-UI8' */
  boolean_T TmpLatchAtJKFlipFlopInport1;
  boolean_T TmpLatchAtJKFlipFlopInport2;
  boolean_T Memory;                    /* '<S1>/Memory' */
  boolean_T Compare[2];                /* '<S4>/Compare' */
  boolean_T FixPtRelationalOperator;   /* '<S23>/FixPt Relational Operator' */
  boolean_T Counter1_o2;               /* '<S21>/Counter1' */
  boolean_T Memory_m;                  /* '<S20>/Memory' */
  boolean_T Logic[2];                  /* '<S20>/Logic' */
  boolean_T OutportBufferForQ;
} B_testmodel_1109_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S23>/Delay Input1' */
  real_T pos[4];                       /* '<S8>/MATLAB Function1' */
  real_T vel[4];                       /* '<S8>/MATLAB Function1' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint32_T Counter1_ClkEphState;       /* '<S21>/Counter1' */
  uint32_T Counter1_RstEphState;       /* '<S21>/Counter1' */
  int_T Setupv3_IWORK[2];              /* '<S1>/Setup (v3)' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S9>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_b;                 /* '<S10>/S-Function' */

  int_T Writev3_IWORK[4];              /* '<S1>/Write (v3)' */
  int_T Readv3_IWORK[3];               /* '<S1>/Read (v3)' */
  int_T CANUnpack2_ModeSignalID;       /* '<S8>/CAN Unpack2' */
  int_T CANUnpack2_StatusPortID;       /* '<S8>/CAN Unpack2' */
  int_T CANUnpack3_ModeSignalID;       /* '<S8>/CAN Unpack3' */
  int_T CANUnpack3_StatusPortID;       /* '<S8>/CAN Unpack3' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_p;                 /* '<S24>/S-Function' */

  int_T ReadACK_ModeSignalID;          /* '<S8>/ReadACK' */
  int_T ReadACK_StatusPortID;          /* '<S8>/ReadACK' */
  int_T CANPack_ModeSignalID;          /* '<S19>/CAN Pack' */
  int_T Writev3_IWORK_e[4];            /* '<S19>/Write (v3)' */
  int_T CANPack_ModeSignalID_e;        /* '<S18>/CAN Pack' */
  int_T Writev3_IWORK_d[4];            /* '<S18>/Write (v3)' */
  int_T CANPack2_ModeSignalID;         /* '<S17>/CAN Pack2' */
  int_T Writev3_IWORK_p[4];            /* '<S17>/Write (v3)' */
  int_T CANPack1_ModeSignalID;         /* '<S5>/CAN Pack1' */
  int_T CANPack_ModeSignalID_b;        /* '<S5>/CAN Pack' */
  int_T Writev3_IWORK_l[4];            /* '<S5>/Write (v3)' */
  int_T CANPack2_ModeSignalID_j;       /* '<S12>/CAN Pack2' */
  int_T Writev31_IWORK[4];             /* '<S3>/Write (v3)1' */
  int_T CANPack1_ModeSignalID_c;       /* '<S13>/CAN Pack1' */
  int_T CANPack2_ModeSignalID_p;       /* '<S13>/CAN Pack2' */
  int_T CANPack2_ModeSignalID_k;       /* '<S11>/CAN Pack2' */
  uint16_T Counter1_Count;             /* '<S21>/Counter1' */
  int8_T JKFlipFlop_SubsysRanBC;       /* '<S7>/J-K Flip-Flop' */
  int8_T ReadQueueSS_SubsysRanBC;      /* '<S1>/ReadQueueSS' */
  int8_T DefaultConfig_SubsysRanBC;    /* '<S1>/DefaultConfig' */
  int8_T GetStatems_SubsysRanBC;       /* '<S6>/GetState(ms)' */
  int8_T InitialPosition_SubsysRanBC;  /* '<S6>/InitialPosition' */
  int8_T QuitError_SubsysRanBC;        /* '<S6>/QuitError' */
  boolean_T TmpLatchAtJKFlipFlopInport1_Pre;/* synthesized block */
  boolean_T TmpLatchAtJKFlipFlopInport2_Pre;/* synthesized block */
  boolean_T Memory_PreviousInput;      /* '<S1>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S20>/Memory' */
} DW_testmodel_1109_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState JKFlipFlop_Trig_ZCE;      /* '<S7>/J-K Flip-Flop' */
  ZCSigState QuitError_Trig_ZCE;       /* '<S6>/QuitError' */
  ZCSigState InitialPosition_Trig_ZCE; /* '<S6>/InitialPosition' */
  ZCSigState GetStatems_Trig_ZCE;      /* '<S6>/GetState(ms)' */
  ZCSigState DefaultConfig_Trig_ZCE;   /* '<S1>/DefaultConfig' */
} PrevZCX_testmodel_1109_T;

/* Backward compatible GRT Identifiers */
#define rtB                            testmodel_1109_B
#define BlockIO                        B_testmodel_1109_T
#define rtP                            testmodel_1109_P
#define Parameters                     P_testmodel_1109_T
#define rtDWork                        testmodel_1109_DW
#define D_Work                         DW_testmodel_1109_T
#define rtPrevZCSigState               testmodel_1109_PrevZCX
#define PrevZCSigStates                PrevZCX_testmodel_1109_T

/* Parameters (auto storage) */
struct P_testmodel_1109_T_ {
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S23>/Delay Input1'
                                        */
  uint16_T Counter1_HitValue;          /* Mask Parameter: Counter1_HitValue
                                        * Referenced by: '<S21>/Counter1'
                                        */
  uint16_T Counter1_InitialCount;      /* Mask Parameter: Counter1_InitialCount
                                        * Referenced by: '<S21>/Counter1'
                                        */
  real_T DataLen_Value;                /* Expression: 1
                                        * Referenced by: '<S12>/DataLen'
                                        */
  real_T StopCmd_Value;                /* Expression: hex2dec('91')
                                        * Referenced by: '<S12>/StopCmd'
                                        */
  real_T SendStop_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/SendStop'
                                        */
  real_T Writev31_P1_Size[2];          /* Computed Parameter: Writev31_P1_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P1;                  /* Expression: id
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P2_Size[2];          /* Computed Parameter: Writev31_P2_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P2;                  /* Expression: status
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P3_Size[2];          /* Computed Parameter: Writev31_P3_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P3;                  /* Expression: inputType
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P4_Size[2];          /* Computed Parameter: Writev31_P4_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P4;                  /* Expression: maxMsg
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P5_Size[2];          /* Computed Parameter: Writev31_P5_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P5;                  /* Expression: port
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P6_Size[2];          /* Computed Parameter: Writev31_P6_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P6;                  /* Expression: initarray
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P7_Size[2];          /* Computed Parameter: Writev31_P7_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P7;                  /* Expression: termarray
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P8_Size[2];          /* Computed Parameter: Writev31_P8_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P8;                  /* Expression: sampletime
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P9_Size[2];          /* Computed Parameter: Writev31_P9_Size
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T Writev31_P9;                  /* Expression: pciSlot
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  real_T DLen_Value;                   /* Expression: 9
                                        * Referenced by: '<S13>/D-Len'
                                        */
  real_T FragSt_Value;                 /* Expression: hex2dec('84')
                                        * Referenced by: '<S13>/FragSt'
                                        */
  real_T Cmd_Value;                    /* Expression: hex2dec('B5')
                                        * Referenced by: '<S13>/Cmd'
                                        */
  real_T DLen1_Value;                  /* Expression: 3
                                        * Referenced by: '<S13>/D-Len1'
                                        */
  real_T FragEn_Value;                 /* Expression: hex2dec('86')
                                        * Referenced by: '<S13>/FragEn'
                                        */
  real_T Constant5_Value;              /* Expression: 6
                                        * Referenced by: '<S11>/Constant5'
                                        */
  real_T GetStateCmd_Value;            /* Expression: hex2dec('95')
                                        * Referenced by: '<S11>/GetState Cmd'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant6'
                                        */
  real_T Constant3_Value;              /* Expression: 5
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: hex2dec('B5')
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T Constant6_Value_k;            /* Expression: 15000
                                        * Referenced by: '<S5>/Constant6'
                                        */
  real_T Constant1_Value;              /* Expression: 5
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec('B0')
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant5_Value_k;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Writev3_P1_Size[2];           /* Computed Parameter: Writev3_P1_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P1;                   /* Expression: id
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P2_Size[2];           /* Computed Parameter: Writev3_P2_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P2;                   /* Expression: status
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P3_Size[2];           /* Computed Parameter: Writev3_P3_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P3;                   /* Expression: inputType
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P4_Size[2];           /* Computed Parameter: Writev3_P4_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P4;                   /* Expression: maxMsg
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P5_Size[2];           /* Computed Parameter: Writev3_P5_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P5;                   /* Expression: port
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P6_Size[2];           /* Computed Parameter: Writev3_P6_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P6;                   /* Expression: initarray
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P7_Size[2];           /* Computed Parameter: Writev3_P7_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P7;                   /* Expression: termarray
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P8_Size[2];           /* Computed Parameter: Writev3_P8_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P8;                   /* Expression: sampletime
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P9_Size[2];           /* Computed Parameter: Writev3_P9_Size
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T Writev3_P9;                   /* Expression: pciSlot
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  real_T DataLen_Value_c;              /* Expression: 6
                                        * Referenced by: '<S17>/DataLen'
                                        */
  real_T GetStateCmd_Value_n;          /* Expression: hex2dec('95')
                                        * Referenced by: '<S17>/GetStateCmd'
                                        */
  real_T Timems_Value;                 /* Expression: 1
                                        * Referenced by: '<S17>/Time (ms)'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Writev3_P1_Size_o[2];         /* Computed Parameter: Writev3_P1_Size_o
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P1_p;                 /* Expression: id
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P2_Size_a[2];         /* Computed Parameter: Writev3_P2_Size_a
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P2_h;                 /* Expression: status
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P3_Size_p[2];         /* Computed Parameter: Writev3_P3_Size_p
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P3_n;                 /* Expression: inputType
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P4_Size_k[2];         /* Computed Parameter: Writev3_P4_Size_k
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P4_b;                 /* Expression: maxMsg
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P5_Size_d[2];         /* Computed Parameter: Writev3_P5_Size_d
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P5_a;                 /* Expression: port
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P6_Size_p[2];         /* Computed Parameter: Writev3_P6_Size_p
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P6_l;                 /* Expression: initarray
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P7_Size_b[2];         /* Computed Parameter: Writev3_P7_Size_b
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P7_d;                 /* Expression: termarray
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P8_Size_g[2];         /* Computed Parameter: Writev3_P8_Size_g
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P8_n;                 /* Expression: sampletime
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P9_Size_o[2];         /* Computed Parameter: Writev3_P9_Size_o
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Writev3_P9_g;                 /* Expression: pciSlot
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  real_T Constant1_Value_i;            /* Expression: 5
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: hex2dec('B0')
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Constant5_Value_d;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant5'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Writev3_P1_Size_g[2];         /* Computed Parameter: Writev3_P1_Size_g
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P1_o;                 /* Expression: id
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P2_Size_c[2];         /* Computed Parameter: Writev3_P2_Size_c
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P2_e;                 /* Expression: status
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P3_Size_i[2];         /* Computed Parameter: Writev3_P3_Size_i
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P3_g;                 /* Expression: inputType
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P4_Size_i[2];         /* Computed Parameter: Writev3_P4_Size_i
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P4_j;                 /* Expression: maxMsg
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P5_Size_f[2];         /* Computed Parameter: Writev3_P5_Size_f
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P5_e;                 /* Expression: port
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P6_Size_m[2];         /* Computed Parameter: Writev3_P6_Size_m
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P6_p;                 /* Expression: initarray
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P7_Size_i[2];         /* Computed Parameter: Writev3_P7_Size_i
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P7_m;                 /* Expression: termarray
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P8_Size_l[2];         /* Computed Parameter: Writev3_P8_Size_l
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P8_c;                 /* Expression: sampletime
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P9_Size_h[2];         /* Computed Parameter: Writev3_P9_Size_h
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Writev3_P9_n;                 /* Expression: pciSlot
                                        * Referenced by: '<S18>/Write (v3)'
                                        */
  real_T Constant2_Value_n;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Constant3_Value_f;            /* Expression: 139
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Constant1_Value_i1;           /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Writev3_P1_Size_p[2];         /* Computed Parameter: Writev3_P1_Size_p
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P1_k;                 /* Expression: id
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P2_Size_f[2];         /* Computed Parameter: Writev3_P2_Size_f
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P2_k;                 /* Expression: status
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P3_Size_a[2];         /* Computed Parameter: Writev3_P3_Size_a
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P3_l;                 /* Expression: inputType
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P4_Size_g[2];         /* Computed Parameter: Writev3_P4_Size_g
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P4_e;                 /* Expression: maxMsg
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P5_Size_d3[2];        /* Computed Parameter: Writev3_P5_Size_d3
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P5_j;                 /* Expression: port
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P6_Size_b[2];         /* Computed Parameter: Writev3_P6_Size_b
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P6_d;                 /* Expression: initarray
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P7_Size_o[2];         /* Computed Parameter: Writev3_P7_Size_o
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P7_j;                 /* Expression: termarray
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P8_Size_d[2];         /* Computed Parameter: Writev3_P8_Size_d
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P8_k;                 /* Expression: sampletime
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P9_Size_a[2];         /* Computed Parameter: Writev3_P9_Size_a
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Writev3_P9_k;                 /* Expression: pciSlot
                                        * Referenced by: '<S19>/Write (v3)'
                                        */
  real_T Setupv3_P1_Size[2];           /* Computed Parameter: Setupv3_P1_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P1;                   /* Expression: can1enable
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P2_Size[2];           /* Computed Parameter: Setupv3_P2_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P2;                   /* Expression: can1bus
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P3_Size[2];           /* Computed Parameter: Setupv3_P3_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P3[4];                /* Expression: can1UserBR
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P4_Size[2];           /* Computed Parameter: Setupv3_P4_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P4[4];                /* Expression: stdAcc1
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P5_Size[2];           /* Computed Parameter: Setupv3_P5_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P5[4];                /* Expression: extAcc1
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P6_Size[2];           /* Computed Parameter: Setupv3_P6_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P6;                   /* Expression: can2enable
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P7_Size[2];           /* Computed Parameter: Setupv3_P7_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P7;                   /* Expression: can2bus
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P8_Size[2];           /* Computed Parameter: Setupv3_P8_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P8[4];                /* Expression: can2UserBR
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P9_Size[2];           /* Computed Parameter: Setupv3_P9_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P9[4];                /* Expression: stdAcc2
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P10_Size[2];          /* Computed Parameter: Setupv3_P10_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P10[4];               /* Expression: extAcc2
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P11_Size[2];          /* Computed Parameter: Setupv3_P11_Size
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T Setupv3_P11;                  /* Expression: pciSlot
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  real_T SendOut_Value;                /* Expression: 2
                                        * Referenced by: '<S1>/SendOut'
                                        */
  real_T Step4_Time;                   /* Expression: 14
                                        * Referenced by: '<S1>/Step4'
                                        */
  real_T Step4_Y0;                     /* Expression: 1
                                        * Referenced by: '<S1>/Step4'
                                        */
  real_T Step4_YFinal;                 /* Expression: 0
                                        * Referenced by: '<S1>/Step4'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 10
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T Writev3_P1_Size_e[2];         /* Computed Parameter: Writev3_P1_Size_e
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P1_kn;                /* Expression: id
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P2_Size_p[2];         /* Computed Parameter: Writev3_P2_Size_p
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P2_j;                 /* Expression: status
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P3_Size_d[2];         /* Computed Parameter: Writev3_P3_Size_d
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P3_j;                 /* Expression: inputType
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P4_Size_o[2];         /* Computed Parameter: Writev3_P4_Size_o
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P4_o;                 /* Expression: maxMsg
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P5_Size_k[2];         /* Computed Parameter: Writev3_P5_Size_k
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P5_g;                 /* Expression: port
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P6_Size_d[2];         /* Computed Parameter: Writev3_P6_Size_d
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P6_i;                 /* Expression: initarray
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P7_Size_e[2];         /* Computed Parameter: Writev3_P7_Size_e
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P7_c;                 /* Expression: termarray
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P8_Size_b[2];         /* Computed Parameter: Writev3_P8_Size_b
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P8_l;                 /* Expression: sampletime
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P9_Size_p[2];         /* Computed Parameter: Writev3_P9_Size_p
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Writev3_P9_h;                 /* Expression: pciSlot
                                        * Referenced by: '<S1>/Write (v3)'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Readv3_P1_Size[2];            /* Computed Parameter: Readv3_P1_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P1;                    /* Expression: depth1
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P2_Size[2];            /* Computed Parameter: Readv3_P2_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P2;                    /* Expression: depth2
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P3_Size[2];            /* Computed Parameter: Readv3_P3_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P3;                    /* Expression: outputFormat
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P4_Size[2];            /* Computed Parameter: Readv3_P4_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P4;                    /* Expression: port1
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P5_Size[2];            /* Computed Parameter: Readv3_P5_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P5;                    /* Expression: port2
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P6_Size[2];            /* Computed Parameter: Readv3_P6_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P6;                    /* Expression: sampletime
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P7_Size[2];            /* Computed Parameter: Readv3_P7_Size
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Readv3_P7;                    /* Expression: pciSlot
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  real_T Step5_Time;                   /* Expression: 15
                                        * Referenced by: '<S1>/Step5'
                                        */
  real_T Step5_Y0;                     /* Expression: 0
                                        * Referenced by: '<S1>/Step5'
                                        */
  real_T Step5_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S1>/Step5'
                                        */
  real_T Step1_Time;                   /* Expression: 2
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step3_Time;                   /* Expression: 2
                                        * Referenced by: '<S6>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<S6>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S6>/Step3'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  int32_T Cur_Value;                   /* Computed Parameter: Cur_Value
                                        * Referenced by: '<S3>/Cur'
                                        */
  int32_T pos_Y0;                      /* Computed Parameter: pos_Y0
                                        * Referenced by: '<S8>/pos'
                                        */
  int32_T vel_Y0;                      /* Computed Parameter: vel_Y0
                                        * Referenced by: '<S8>/vel'
                                        */
  int32_T DiscreteTimeIntegrator_IC;   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  uint8_T position_Value;              /* Computed Parameter: position_Value
                                        * Referenced by: '<S11>/position'
                                        */
  uint8_T states_Value;                /* Computed Parameter: states_Value
                                        * Referenced by: '<S17>/states'
                                        */
  boolean_T Q_Y0;                      /* Expression: initial_condition
                                        * Referenced by: '<S20>/Q'
                                        */
  boolean_T Q_Y0_a;                    /* Expression: ~initial_condition
                                        * Referenced by: '<S20>/!Q'
                                        */
  boolean_T Memory_X0;                 /* Expression: initial_condition
                                        * Referenced by: '<S20>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S20>/Logic'
                                        */
  boolean_T STOP_Y0;                   /* Computed Parameter: STOP_Y0
                                        * Referenced by: '<S8>/STOP'
                                        */
  boolean_T TmpLatchAtJKFlipFlopInport1_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                            * Referenced by: synthesized block
                                            */
  boolean_T TmpLatchAtJKFlipFlopInport2_X0;/* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                            * Referenced by: synthesized block
                                            */
  boolean_T Memory_X0_e;               /* Computed Parameter: Memory_X0_e
                                        * Referenced by: '<S1>/Memory'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testmodel_1109_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[8];
    SimStruct *childSFunctionPtrs[8];
    struct _ssBlkInfo2 blkInfo2[8];
    struct _ssSFcnModelMethods2 methods2[8];
    struct _ssSFcnModelMethods3 methods3[8];
    struct _ssStatesInfo2 statesInfo2[8];
    ssPeriodicStatesInfo periodicStatesInfo[8];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_testmodel_1109_T testmodel_1109_P;

/* Block signals (auto storage) */
extern B_testmodel_1109_T testmodel_1109_B;

/* Block states (auto storage) */
extern DW_testmodel_1109_T testmodel_1109_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_testmodel_1109_T testmodel_1109_PrevZCX;

/*====================*
 * External functions *
 *====================*/
extern testmodel_1109_rtModel *testmodel_1109(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  testmodel_1109_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_testmodel_1109_T *const testmodel_1109_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'testmodel_1109'
 * '<S1>'   : 'testmodel_1109/IO601'
 * '<S2>'   : 'testmodel_1109/info'
 * '<S3>'   : 'testmodel_1109/IO601/CANSend'
 * '<S4>'   : 'testmodel_1109/IO601/Compare To Zero'
 * '<S5>'   : 'testmodel_1109/IO601/DefaultConfig'
 * '<S6>'   : 'testmodel_1109/IO601/Initialize'
 * '<S7>'   : 'testmodel_1109/IO601/J-K Flip-Flop1'
 * '<S8>'   : 'testmodel_1109/IO601/ReadQueueSS'
 * '<S9>'   : 'testmodel_1109/IO601/Scope '
 * '<S10>'  : 'testmodel_1109/IO601/Scope 2'
 * '<S11>'  : 'testmodel_1109/IO601/CANSend/GetState (once)'
 * '<S12>'  : 'testmodel_1109/IO601/CANSend/STOP'
 * '<S13>'  : 'testmodel_1109/IO601/CANSend/movVel'
 * '<S14>'  : 'testmodel_1109/IO601/CANSend/sin(Cur)'
 * '<S15>'  : 'testmodel_1109/IO601/CANSend/movVel/MATLAB Function1'
 * '<S16>'  : 'testmodel_1109/IO601/CANSend/movVel/TC UI32-UI8'
 * '<S17>'  : 'testmodel_1109/IO601/Initialize/GetState(ms)'
 * '<S18>'  : 'testmodel_1109/IO601/Initialize/InitialPosition'
 * '<S19>'  : 'testmodel_1109/IO601/Initialize/QuitError'
 * '<S20>'  : 'testmodel_1109/IO601/J-K Flip-Flop1/J-K Flip-Flop'
 * '<S21>'  : 'testmodel_1109/IO601/ReadQueueSS/CountACK'
 * '<S22>'  : 'testmodel_1109/IO601/ReadQueueSS/MATLAB Function1'
 * '<S23>'  : 'testmodel_1109/IO601/ReadQueueSS/CountACK/Detect Increase'
 * '<S24>'  : 'testmodel_1109/IO601/ReadQueueSS/CountACK/Scope 3'
 */
#endif                                 /* RTW_HEADER_testmodel_1109_h_ */
