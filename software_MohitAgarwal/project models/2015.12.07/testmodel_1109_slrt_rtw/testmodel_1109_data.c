/*
 * testmodel_1109_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "testmodel_1109".
 *
 * Model version              : 1.217
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Dec 11 15:33:14 2015
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
  0.0,                                 /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S29>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease_vinit_k
                                        * Referenced by: '<S5>/Delay Input1'
                                        */
  32U,                                 /* Mask Parameter: Counter_HitValue
                                        * Referenced by: '<S28>/Counter'
                                        */
  0U,                                  /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S28>/Counter'
                                        */
  500U,                                /* Mask Parameter: Counter_HitValue_e
                                        * Referenced by: '<S1>/Counter'
                                        */
  500U,                                /* Mask Parameter: Counter1_HitValue
                                        * Referenced by: '<S1>/Counter1'
                                        */
  0U,                                  /* Mask Parameter: Counter_InitialCount_h
                                        * Referenced by: '<S1>/Counter'
                                        */
  0U,                                  /* Mask Parameter: Counter1_InitialCount
                                        * Referenced by: '<S1>/Counter1'
                                        */
  9.0,                                 /* Expression: 9
                                        * Referenced by: '<S19>/D-Len'
                                        */
  132.0,                               /* Expression: hex2dec('84')
                                        * Referenced by: '<S19>/FragSt'
                                        */
  181.0,                               /* Expression: hex2dec('B5')
                                        * Referenced by: '<S19>/Cmd'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S19>/D-Len1'
                                        */
  134.0,                               /* Expression: hex2dec('86')
                                        * Referenced by: '<S19>/FragEn'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S3>/SendVel'
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/DataLen'
                                        */
  145.0,                               /* Expression: hex2dec('91')
                                        * Referenced by: '<S17>/StopCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/SendStop'
                                        */

  /*  Computed Parameter: Writev31_P1_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P2_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P3_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P4_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P5_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P6_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P7_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P8_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */

  /*  Computed Parameter: Writev31_P9_Size
   * Referenced by: '<S3>/Write (v3)1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S3>/Write (v3)1'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S14>/Constant5'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S14>/GetState Cmd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant6'
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
                                        * Referenced by: '<S23>/DataLen'
                                        */
  149.0,                               /* Expression: hex2dec('95')
                                        * Referenced by: '<S23>/GetStateCmd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Time (ms)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_o
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_a
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_p
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_k
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_p
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_b
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_g
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S23>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_o
   * Referenced by: '<S23>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S23>/Write (v3)'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S24>/Constant1'
                                        */
  176.0,                               /* Expression: hex2dec('B0')
                                        * Referenced by: '<S24>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_g
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_c
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_i
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_i
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_f
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_m
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_i
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_l
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S24>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_h
   * Referenced by: '<S24>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S24>/Write (v3)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/Constant2'
                                        */
  139.0,                               /* Expression: 139
                                        * Referenced by: '<S25>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/Constant1'
                                        */

  /*  Computed Parameter: Writev3_P1_Size_p
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: id
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P2_Size_f
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: status
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P3_Size_a
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: inputType
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P4_Size_g
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: maxMsg
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P5_Size_d3
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P6_Size_b
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initarray
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P7_Size_o
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: termarray
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P8_Size_d
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S25>/Write (v3)'
                                        */

  /*  Computed Parameter: Writev3_P9_Size_a
   * Referenced by: '<S25>/Write (v3)'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S25>/Write (v3)'
                                        */
  0.0,                                 /* Computed Parameter: ACK_TS_Y0
                                        * Referenced by: '<S26>/ACK_TS'
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  5.0000000000000009,                  /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Transport Delay'
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  50.0,                                /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  5.0000000000000009,                  /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Pulse Generator2'
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
                                        * Referenced by: '<S6>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Step1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S6>/Step3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Step3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  -1300,                               /* Computed Parameter: Cur_Value
                                        * Referenced by: '<S3>/Cur'
                                        */
  0,                                   /* Computed Parameter: pos_Y0
                                        * Referenced by: '<S26>/pos'
                                        */
  0,                                   /* Computed Parameter: vel_Y0
                                        * Referenced by: '<S26>/vel'
                                        */
  0,                                   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  1U,                                  /* Computed Parameter: position_Value
                                        * Referenced by: '<S14>/position'
                                        */
  3U,                                  /* Computed Parameter: states_Value
                                        * Referenced by: '<S23>/states'
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S20>/Q'
                                        */
  1,                                   /* Expression: ~initial_condition
                                        * Referenced by: '<S20>/!Q'
                                        */
  0,                                   /* Expression: initial_condition
                                        * Referenced by: '<S20>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S20>/Logic'
   */
  { 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
  0,                                   /* Computed Parameter: TmpLatchAtJKFlipFlopInport1_X0
                                        * Referenced by: synthesized block
                                        */
  0                                    /* Computed Parameter: TmpLatchAtJKFlipFlopInport2_X0
                                        * Referenced by: synthesized block
                                        */
};
