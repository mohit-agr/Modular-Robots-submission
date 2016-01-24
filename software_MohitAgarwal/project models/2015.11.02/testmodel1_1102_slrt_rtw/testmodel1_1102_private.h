/*
 * testmodel1_1102_private.h
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

#ifndef RTW_HEADER_testmodel1_1102_private_h_
#define RTW_HEADER_testmodel1_1102_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void sg_IO601_write_s_3(SimStruct *rts);
extern void sg_IO601_setup_s_3(SimStruct *rts);
extern void sg_IO601_read_s_3(SimStruct *rts);

#endif                                 /* RTW_HEADER_testmodel1_1102_private_h_ */
