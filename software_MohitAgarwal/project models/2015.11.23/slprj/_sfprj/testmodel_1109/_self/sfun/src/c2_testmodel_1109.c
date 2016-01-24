/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testmodel_1109_sfun.h"
#include "c2_testmodel_1109.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testmodel_1109_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[10] = { "pos1", "vel1", "nargin",
  "nargout", "inp1", "inp2", "state", "stitched", "pos", "vel" };

/* Function Declarations */
static void initialize_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void initialize_params_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance);
static void enable_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void disable_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance);
static void set_sim_state_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void sf_gateway_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void mdl_start_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void initSimStructsc2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c2_b_vel, const char_T *c2_identifier, boolean_T *c2_svPtr,
  real_T c2_y[4]);
static void c2_b_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr, real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_stitched, const char_T *c2_identifier,
  boolean_T *c2_svPtr, real_T c2_y[12]);
static void c2_d_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr, real_T c2_y[12]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_state, const char_T *c2_identifier,
  int32_T c2_y[2]);
static void c2_f_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int32_T c2_y[2]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_h_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static int32_T c2_typecast(SFc2_testmodel_1109InstanceStruct *chartInstance,
  uint8_T c2_x[4]);
static uint8_T c2_i_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testmodel_1109, const char_T *
  c2_identifier);
static uint8_T c2_j_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_testmodel_1109InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_testmodel_1109InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_testmodel_1109(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_stitched_not_empty = false;
  chartInstance->c2_pos_not_empty = false;
  chartInstance->c2_vel_not_empty = false;
  chartInstance->c2_is_active_c2_testmodel_1109 = 0U;
}

static void initialize_params_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_testmodel_1109
  (SFc2_testmodel_1109InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_state, 6, 0U, 1U,
    0U, 2, 1, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  if (!chartInstance->c2_vel_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_pos, 0, 0U, 1U,
      0U, 2, 1, 4), false);
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_d_y = NULL;
  if (!chartInstance->c2_stitched_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", chartInstance->c2_stitched, 0, 0U,
      1U, 0U, 2, 1, 12), false);
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_e_y = NULL;
  if (!chartInstance->c2_vel_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", chartInstance->c2_vel, 0, 0U, 1U,
      0U, 2, 1, 4), false);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_testmodel_1109;
  c2_u = c2_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_iv0[2];
  int32_T c2_i0;
  real_T c2_dv0[4];
  int32_T c2_i1;
  real_T c2_dv1[12];
  int32_T c2_i2;
  real_T c2_dv2[4];
  int32_T c2_i3;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("state", c2_u,
    0)), "state", c2_iv0);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    (*chartInstance->c2_state)[c2_i0] = c2_iv0[c2_i0];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("pos", c2_u, 1)),
                      "pos", &chartInstance->c2_pos_not_empty, c2_dv0);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    chartInstance->c2_pos[c2_i1] = c2_dv0[c2_i1];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("stitched",
    c2_u, 2)), "stitched", &chartInstance->c2_stitched_not_empty, c2_dv1);
  for (c2_i2 = 0; c2_i2 < 12; c2_i2++) {
    chartInstance->c2_stitched[c2_i2] = c2_dv1[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("vel", c2_u, 3)),
                      "vel", &chartInstance->c2_vel_not_empty, c2_dv2);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    chartInstance->c2_vel[c2_i3] = c2_dv2[c2_i3];
  }

  chartInstance->c2_is_active_c2_testmodel_1109 = c2_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_testmodel_1109",
       c2_u, 4)), "is_active_c2_testmodel_1109");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_testmodel_1109(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  uint8_T c2_b_inp1[8];
  int32_T c2_i7;
  uint8_T c2_b_inp2[7];
  uint32_T c2_debug_family_var_map[10];
  int32_T c2_pos1;
  int32_T c2_vel1;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_b_state[2];
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  real_T c2_d0;
  uint8_T c2_u0;
  uint8_T c2_uv0[4];
  int32_T c2_i14;
  real_T c2_d1;
  uint8_T c2_u1;
  uint8_T c2_uv1[4];
  int32_T c2_i15;
  int32_T c2_i16;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 7; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_inp2)[c2_i4], 1U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i5 = 0; c2_i5 < 8; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_inp1)[c2_i5], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i6 = 0; c2_i6 < 8; c2_i6++) {
    c2_b_inp1[c2_i6] = (*chartInstance->c2_inp1)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 7; c2_i7++) {
    c2_b_inp2[c2_i7] = (*chartInstance->c2_inp2)[c2_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_pos1, 0U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_vel1, 1U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_f_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_f_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_inp1, 4U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_inp2, 5U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_state, 6U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_stitched, 7U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_pos, 8U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_vel, 9U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_stitched_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
    for (c2_i8 = 0; c2_i8 < 12; c2_i8++) {
      chartInstance->c2_stitched[c2_i8] = 0.0;
    }

    chartInstance->c2_stitched_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
    for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
      chartInstance->c2_pos[c2_i9] = 0.0;
    }

    chartInstance->c2_pos_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
    for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
      chartInstance->c2_vel[c2_i10] = 0.0;
    }

    chartInstance->c2_vel_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c2_b_inp1[2],
        149.0, -1, 0U, (real_T)c2_b_inp1[2] == 149.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    chartInstance->c2_stitched[0] = (real_T)c2_b_inp1[0];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
      chartInstance->c2_pos[c2_i11] = (real_T)c2_b_inp1[c2_i11 + 3];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, (real_T)c2_b_inp1[0],
          8.0, -1, 4U, (real_T)c2_b_inp1[0] > 8.0))) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
      chartInstance->c2_vel[0] = (real_T)c2_b_inp1[7];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
      for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
        chartInstance->c2_vel[c2_i12 + 1] = (real_T)c2_b_inp2[c2_i12 + 2];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_d0 = muDoubleScalarRound(chartInstance->c2_pos[c2_i13]);
    if (c2_d0 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c2_d0 >= 0.0)) {
        c2_u0 = (uint8_T)c2_d0;
      } else {
        c2_u0 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_d0 >= 256.0)) {
      c2_u0 = MAX_uint8_T;
    } else {
      c2_u0 = 0U;
    }

    c2_uv0[c2_i13] = c2_u0;
  }

  c2_pos1 = c2_typecast(chartInstance, c2_uv0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    c2_d1 = muDoubleScalarRound(chartInstance->c2_vel[c2_i14]);
    if (c2_d1 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 1, 1, c2_d1 >= 0.0)) {
        c2_u1 = (uint8_T)c2_d1;
      } else {
        c2_u1 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c2_d1 >= 256.0)) {
      c2_u1 = MAX_uint8_T;
    } else {
      c2_u1 = 0U;
    }

    c2_uv1[c2_i14] = c2_u1;
  }

  c2_vel1 = c2_typecast(chartInstance, c2_uv1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_b_state[0] = c2_pos1;
  c2_b_state[1] = c2_vel1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    (*chartInstance->c2_state)[c2_i15] = c2_b_state[c2_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testmodel_1109MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_state)[c2_i16], 2U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_testmodel_1109(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i17;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i17 = 0; c2_i17 < 4; c2_i17++) {
    c2_u[c2_i17] = (*(real_T (*)[4])c2_inData)[c2_i17];
  }

  c2_y = NULL;
  if (!chartInstance->c2_vel_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c2_b_vel, const char_T *c2_identifier, boolean_T *c2_svPtr,
  real_T c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vel), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_b_vel);
}

static void c2_b_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr, real_T c2_y[4])
{
  real_T c2_dv3[4];
  int32_T c2_i18;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                  4);
    for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
      c2_y[c2_i18] = c2_dv3[c2_i18];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_vel;
  const char_T *c2_identifier;
  boolean_T *c2_svPtr;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i19;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_b_vel = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_svPtr = &chartInstance->c2_vel_not_empty;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_vel), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_b_vel);
  for (c2_i19 = 0; c2_i19 < 4; c2_i19++) {
    (*(real_T (*)[4])c2_outData)[c2_i19] = c2_y[c2_i19];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i20;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i20 = 0; c2_i20 < 12; c2_i20++) {
    c2_u[c2_i20] = (*(real_T (*)[12])c2_inData)[c2_i20];
  }

  c2_y = NULL;
  if (!chartInstance->c2_stitched_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 12),
                  false);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_stitched, const char_T *c2_identifier,
  boolean_T *c2_svPtr, real_T c2_y[12])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_stitched), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_b_stitched);
}

static void c2_d_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T *c2_svPtr, real_T c2_y[12])
{
  real_T c2_dv4[12];
  int32_T c2_i21;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                  12);
    for (c2_i21 = 0; c2_i21 < 12; c2_i21++) {
      c2_y[c2_i21] = c2_dv4[c2_i21];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_stitched;
  const char_T *c2_identifier;
  boolean_T *c2_svPtr;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[12];
  int32_T c2_i22;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_b_stitched = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_svPtr = &chartInstance->c2_stitched_not_empty;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_stitched), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_b_stitched);
  for (c2_i22 = 0; c2_i22 < 12; c2_i22++) {
    (*(real_T (*)[12])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  int32_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_u[c2_i23] = (*(int32_T (*)[2])c2_inData)[c2_i23];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 6, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_state, const char_T *c2_identifier,
  int32_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_state);
}

static void c2_f_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int32_T c2_y[2])
{
  int32_T c2_iv1[2];
  int32_T c2_i24;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_iv1, 1, 6, 0U, 1, 0U, 2, 1, 2);
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_y[c2_i24] = c2_iv1[c2_i24];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_state;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y[2];
  int32_T c2_i25;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_b_state = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_state);
  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    (*(int32_T (*)[2])c2_outData)[c2_i25] = c2_y[c2_i25];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i26;
  uint8_T c2_u[7];
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i26 = 0; c2_i26 < 7; c2_i26++) {
    c2_u[c2_i26] = (*(uint8_T (*)[7])c2_inData)[c2_i26];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i27;
  uint8_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i27 = 0; c2_i27 < 8; c2_i27++) {
    c2_u[c2_i27] = (*(uint8_T (*)[8])c2_inData)[c2_i27];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_h_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i28;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i28, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i28;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_vel1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c2_vel1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_vel1), &c2_thisId);
  sf_mex_destroy(&c2_vel1);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_testmodel_1109_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static int32_T c2_typecast(SFc2_testmodel_1109InstanceStruct *chartInstance,
  uint8_T c2_x[4])
{
  int32_T c2_y;
  (void)chartInstance;
  memcpy(&c2_y, &c2_x[0], (size_t)1 * sizeof(int32_T));
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testmodel_1109, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_testmodel_1109), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_testmodel_1109);
  return c2_y;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u2, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_testmodel_1109InstanceStruct
  *chartInstance)
{
  chartInstance->c2_inp1 = (uint8_T (*)[8])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_state = (int32_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_inp2 = (uint8_T (*)[7])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_testmodel_1109_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2366655235U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1457212602U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2080844223U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2415787625U);
}

mxArray* sf_c2_testmodel_1109_get_post_codegen_info(void);
mxArray *sf_c2_testmodel_1109_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kk8wDd58ltlRKWySObugRH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_testmodel_1109_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_testmodel_1109_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_testmodel_1109_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("memcpy");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_testmodel_1109_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_testmodel_1109_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_testmodel_1109(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[7],T\"state\",},{M[4],M[0],T\"pos\",S'l','i','p'{{M1x2[89 92],M[0],}}},{M[4],M[0],T\"stitched\",S'l','i','p'{{M1x2[68 76],M[0],}}},{M[4],M[0],T\"vel\",S'l','i','p'{{M1x2[105 108],M[0],}}},{M[8],M[0],T\"is_active_c2_testmodel_1109\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_testmodel_1109_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testmodel_1109InstanceStruct *chartInstance =
      (SFc2_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testmodel_1109MachineNumber_,
           2,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_testmodel_1109MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testmodel_1109MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testmodel_1109MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inp1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inp2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"state");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,3,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,496);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,411,-1,421);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,449,-1,459);
        _SFD_CV_INIT_EML_IF(0,1,0,111,131,-1,204);
        _SFD_CV_INIT_EML_IF(0,1,1,206,233,-1,394);
        _SFD_CV_INIT_EML_IF(0,1,2,298,312,-1,390);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,209,233,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,301,312,-1,4);

        {
          unsigned int dimVector[1];
          dimVector[0]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testmodel_1109MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testmodel_1109InstanceStruct *chartInstance =
      (SFc2_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_inp1);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c2_state);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_inp2);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sZCIiSrxJxSPz7QZQ4QUlmF";
}

static void sf_opaque_initialize_c2_testmodel_1109(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar);
  initialize_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_testmodel_1109(void *chartInstanceVar)
{
  enable_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_testmodel_1109(void *chartInstanceVar)
{
  disable_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_testmodel_1109(void *chartInstanceVar)
{
  sf_gateway_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_testmodel_1109(SimStruct* S)
{
  return get_sim_state_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_testmodel_1109(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_testmodel_1109(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_testmodel_1109InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testmodel_1109_optimization_info();
    }

    finalize_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_testmodel_1109(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_testmodel_1109((SFc2_testmodel_1109InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_testmodel_1109(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testmodel_1109_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2200625182U));
  ssSetChecksum1(S,(4096275857U));
  ssSetChecksum2(S,(3133571405U));
  ssSetChecksum3(S,(3790639663U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_testmodel_1109(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_testmodel_1109(SimStruct *S)
{
  SFc2_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc2_testmodel_1109InstanceStruct *)utMalloc(sizeof
    (SFc2_testmodel_1109InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_testmodel_1109InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_testmodel_1109;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_testmodel_1109;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_testmodel_1109;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_testmodel_1109;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_testmodel_1109;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_testmodel_1109;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_testmodel_1109;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_testmodel_1109;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_testmodel_1109;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_testmodel_1109;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_testmodel_1109;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_testmodel_1109(chartInstance);
}

void c2_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_testmodel_1109(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_testmodel_1109(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_testmodel_1109(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_testmodel_1109_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
