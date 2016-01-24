/*
 * testmodel_1109_data.c
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

#include "testmodel_1109.h"
#include "testmodel_1109_private.h"

/* Block parameters (auto storage) */
P_testmodel_1109_T testmodel_1109_P = {
  0.004,                               /* Variable: Ts
                                        * Referenced by: '<S1>/Transport Delay'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S26>/Delay Input1'
                                        */
  3U,                                  /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S23>/FixPt Switch'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S3>/Constant'
                                        */
  9.0,                                 /* Expression: 9
                                        * Referenced by: '<S13>/D-Len'
                                        */
  132.0,                               /* Expression: hex2dec('84')
                                        * Referenced by: '<S13>/FragSt'
                                        */
  181.0,                               /* Expression: hex2dec('B5')
                                        * Referenced by: '<S13>/Cmd'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S13>/D-Len1'
                                        */
  134.0,                               /* Expression: hex2dec('86')
                                        * Referenced by: '<S13>/FragEn'
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
  1.0,                                 /* Expression: status
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
                                        * Referenced by: '<S3>/Constant5'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S3>/GetState Cmd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant6'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S4>/Constant3'
                                        */
  181.0,                               /* Expression: hex2dec('B5')
                                        * Referenced by: '<S4>/Constant4'
                                        */
  15000.0,                             /* Expression: 15000
                                        * Referenced by: '<S4>/Constant6'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S4>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S4>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S4>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_a
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_h
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_d
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_b
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_k
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_d
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_d
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_e
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S4>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_p
   * Referenced by: '<S4>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S4>/Write (v3)'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S16>/DataLen'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S16>/GetStateCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Time (ms)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_o
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_a
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_p
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_k
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_p
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_b
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_g
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S16>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_o
   * Referenced by: '<S16>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S16>/Write (v3)'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S17>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S17>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_g
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_c
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_i
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_i
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_f
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_m
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_i
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_l
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S17>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_h
   * Referenced by: '<S17>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S17>/Write (v3)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant2'
                                        */
  139.0,                               /* Expression: 139
                                        * Referenced by: '<S18>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_p
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_f
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_a
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_g
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d3
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_b
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_o
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_d
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S18>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_a
   * Referenced by: '<S18>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S18>/Write (v3)'
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

  /*  Computed Parameter: Writev3_P1_Size_b
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_aa
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_c
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_m
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_i
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_p0
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_e
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_k
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S6>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_b
   * Referenced by: '<S6>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S6>/Write (v3)'
                                        */
  0.0,                                 /* Computed Parameter: ACK_TS_Y0
                                        * Referenced by: '<S20>/ACK_TS'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S29>/DataLen'
                                        */
  145.0,                               /* Expression: hex2dec('91')
                                        * Referenced by: '<S29>/GetStateCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S29>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_j
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_g
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_d1
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_bm
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_is
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_j
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_by
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_b
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S29>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_l
   * Referenced by: '<S29>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S29>/Write (v3)'
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
  14.0,                                /* Expression: 14
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
  1.0,                                 /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Transport Delay'
                                        */

  /*  Computed Parameter: Readv3_P1_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  37.0,                                /* Expression: depth1
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P2_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: depth2
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P3_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: outputFormat
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P4_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port1
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P5_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: port2
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P6_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  0.004,                               /* Expression: sampletime
                                        * Referenced by: '<S1>/Read (v3)'
                                        */

  /*  Computed Parameter: Readv3_P7_Size
   * Referenced by: '<S1>/Read (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S1>/Read (v3)'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<S1>/Step5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step5'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S1>/Step2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Step1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Step1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Step3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Step'
                                        */
  0,                                   /* Computed Parameter: pos_Y0
                                        * Referenced by: '<S20>/pos'
                                        */
  0,                                   /* Computed Parameter: vel_Y0
                                        * Referenced by: '<S20>/vel'
                                        */
  1500,                                /* Computed Parameter: Cur_Value
                                        * Referenced by: '<S1>/Cur'
                                        */
  0,                                   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  1U,                                  /* Computed Parameter: position_Value
                                        * Referenced by: '<S3>/position'
                                        */
  3U,                                  /* Computed Parameter: states_Value
                                        * Referenced by: '<S16>/states'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S22>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S19>/Output'
                                        */
  0U                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S23>/Constant'
                                        */
};
