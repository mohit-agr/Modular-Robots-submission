/*
 * testmodel_1109_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.111
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Nov 17 16:22:33 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testmodel_1109.h"
#include "testmodel_1109_private.h"

/* Block parameters (auto storage) */
P_testmodel_1109_T testmodel_1109_P = {
  3U,                                  /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S18>/FixPt Switch'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Constant3'
                                        */
  181.0,                               /* Expression: hex2dec('B5')
                                        * Referenced by: '<S3>/Constant4'
                                        */
  15000.0,                             /* Expression: 15000
                                        * Referenced by: '<S3>/Constant6'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S3>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S3>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S3>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size
   * Referenced by: '<S3>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S3>/Write (v3)'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S4>/DataLen'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S4>/GetStateCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Time (ms)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_o
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_a
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_p
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_k
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_p
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_b
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_g
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_o
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S4>/Write (v3)'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S5>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S5>/Constant2'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S5>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_b
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_aa
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_c
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_m
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_i
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_p0
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_e
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_k
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S5>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_b
   * Referenced by: '<S5>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S5>/Write (v3)'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S6>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_g
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_c
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_i
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_i
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_f
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_m
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_i
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_l
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_h
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S6>/Write (v3)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  139.0,                               /* Expression: 139
                                        * Referenced by: '<S7>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_p
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_f
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_a
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_g
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d3
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_b
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_o
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_d
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S7>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_a
   * Referenced by: '<S7>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S7>/Write (v3)'
                                        */
  0.0,                                 /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S14>/Out 1'
                                        */
  0.0,                                 /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S14>/Out 2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/DataLen'
                                        */
  145.0,                               /* Expression: hex2dec('91')
                                        * Referenced by: '<S9>/GetStateCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_j
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_g
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_d
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_b
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_is
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_j
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_by
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_b
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S9>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_l
   * Referenced by: '<S9>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S9>/Write (v3)'
                                        */
  9.0,                                 /* Expression: 9
                                        * Referenced by: '<S12>/D-Len'
                                        */
  132.0,                               /* Expression: hex2dec('84')
                                        * Referenced by: '<S12>/FragSt'
                                        */
  181.0,                               /* Expression: hex2dec('B5')
                                        * Referenced by: '<S12>/Cmd'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S12>/D-Len1'
                                        */
  134.0,                               /* Expression: hex2dec('86')
                                        * Referenced by: '<S12>/FragEn'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S12>/Constant5'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S12>/GetState Cmd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant6'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S12>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_e
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_p
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_dd
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_o
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_k
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_d
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_el
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_bf
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_p
   * Referenced by: '<S12>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S12>/Write (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P1_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can1enable
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P2_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can1bus
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P3_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: can1UserBR
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0, 5.0, 2.0 },

  /*  Computed Parameter: Setupv3_P4_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: stdAcc1
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P5_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: extAcc1
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P6_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can2enable
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P7_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: can2bus
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */

  /*  Computed Parameter: Setupv3_P8_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: can2UserBR
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0, 5.0, 2.0 },

  /*  Computed Parameter: Setupv3_P9_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: stdAcc2
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P10_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 4.0 },

  /*  Expression: extAcc2
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Setupv3_P11_Size
   * Referenced by: '<S1>/Setup (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S1>/Setup (v3)'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S1>/Step4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  10.0,                                /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  1.0000000000000002,                  /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */

  /*  Computed Parameter: Readv3_P1_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: depth1
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P2_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: depth2
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P3_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputFormat
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P4_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port1
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P5_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: port2
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P6_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S8>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P7_Size
   * Referenced by: '<S8>/Read (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S8>/Read (v3)'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S1>/Step5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step5'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S1>/Step3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step1'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S1>/Step2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step2'
                                        */
  1U,                                  /* Computed Parameter: position_Value
                                        * Referenced by: '<S4>/position'
                                        */
  0U,                                  /* Computed Parameter: velocity_Value
                                        * Referenced by: '<S4>/velocity'
                                        */
  0U,                                  /* Computed Parameter: current_Value
                                        * Referenced by: '<S4>/current'
                                        */
  1U,                                  /* Computed Parameter: position_Value_m
                                        * Referenced by: '<S12>/position'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S17>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S13>/Output'
                                        */
  0U                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S18>/Constant'
                                        */
};
