/*
 * moveRobot_data.c
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

#include "moveRobot.h"
#include "moveRobot_private.h"

/* Block parameters (auto storage) */
P_moveRobot_T moveRobot_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  139.0,                               /* Expression: 139
                                        * Referenced by: '<S1>/Constant2'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S1>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant7'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Constant4'
                                        */

  /*  Computed Parameter: Writev32_P1_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P2_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P3_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P4_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P5_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P6_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P7_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P8_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */

  /*  Computed Parameter: Writev32_P9_Size
   * Referenced by: '<S1>/Write (v3)2'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S1>/Write (v3)2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Constant3'
                                        */

  /*  Computed Parameter: Writev31_P1_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P2_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P3_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P4_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P5_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P6_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P7_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P8_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P9_Size
   * Referenced by: '<S6>/Write (v3)1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S6>/Write (v3)1'
                                        */

  /*  Computed Parameter: Setupv3_P1_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can1enable
                                        * Referenced by: '<Root>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P2_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can1bus
                                        * Referenced by: '<Root>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P3_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: can1UserBR
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0, 13.0, 2.0 },

  /*  Computed Parameter: Setupv3_P4_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: stdAcc1
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P5_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: extAcc1
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P6_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can2enable
                                        * Referenced by: '<Root>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P7_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can2bus
                                        * Referenced by: '<Root>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P8_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: can2UserBR
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0, 13.0, 2.0 },

  /*  Computed Parameter: Setupv3_P9_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: stdAcc2
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P10_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: extAcc2
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P11_Size
   * Referenced by: '<Root>/Setup (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Setup (v3)'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
};
