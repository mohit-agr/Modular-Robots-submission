/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testmodel_1109_sfun.h"
#include "c4_testmodel_1109.h"
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
static const char * c4_debug_family_names[13] = { "compare", "pos1", "vel1",
  "cur1", "nargin", "nargout", "inp", "frame", "state", "stitched", "pos", "vel",
  "cur" };

/* Function Declarations */
static void initialize_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void initialize_params_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance);
static void enable_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void disable_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance);
static void set_sim_state_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void sf_gateway_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void mdl_start_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void c4_chartstep_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void initSimStructsc4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c4_b_cur, const char_T *c4_identifier, boolean_T *c4_svPtr,
  real_T c4_y[4]);
static void c4_b_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr, real_T c4_y[4]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_stitched, const char_T *c4_identifier,
  boolean_T *c4_svPtr, real_T c4_y[16]);
static void c4_d_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr, real_T c4_y[16]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_state, const char_T *c4_identifier,
  int32_T c4_y[3]);
static void c4_f_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  int32_T c4_y[3]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_g_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_frame, const char_T *c4_identifier, real_T
  c4_y[16]);
static void c4_h_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[16]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_i_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_j_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_k_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[3]);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static int32_T c4_typecast(SFc4_testmodel_1109InstanceStruct *chartInstance,
  uint8_T c4_x[4]);
static uint8_T c4_l_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_testmodel_1109, const char_T *
  c4_identifier);
static uint8_T c4_m_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_testmodel_1109InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_testmodel_1109InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_testmodel_1109(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_stitched_not_empty = false;
  chartInstance->c4_pos_not_empty = false;
  chartInstance->c4_vel_not_empty = false;
  chartInstance->c4_cur_not_empty = false;
  chartInstance->c4_is_active_c4_testmodel_1109 = 0U;
}

static void initialize_params_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_testmodel_1109
  (SFc4_testmodel_1109InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_u;
  const mxArray *c4_h_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(7, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_frame, 0, 0U, 1U,
    0U, 2, 1, 16), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", *chartInstance->c4_state, 6, 0U, 1U,
    0U, 2, 1, 3), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  if (!chartInstance->c4_cur_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", chartInstance->c4_cur, 0, 0U, 1U,
      0U, 2, 1, 4), false);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_e_y = NULL;
  if (!chartInstance->c4_cur_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", chartInstance->c4_pos, 0, 0U, 1U,
      0U, 2, 1, 4), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_f_y = NULL;
  if (!chartInstance->c4_stitched_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", chartInstance->c4_stitched, 0, 0U,
      1U, 0U, 2, 1, 16), false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_g_y = NULL;
  if (!chartInstance->c4_cur_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", chartInstance->c4_vel, 0, 0U, 1U,
      0U, 2, 1, 4), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_testmodel_1109;
  c4_u = c4_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[16];
  int32_T c4_i0;
  int32_T c4_iv0[3];
  int32_T c4_i1;
  real_T c4_dv1[4];
  int32_T c4_i2;
  real_T c4_dv2[4];
  int32_T c4_i3;
  real_T c4_dv3[16];
  int32_T c4_i4;
  real_T c4_dv4[4];
  int32_T c4_i5;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("frame", c4_u,
    0)), "frame", c4_dv0);
  for (c4_i0 = 0; c4_i0 < 16; c4_i0++) {
    (*chartInstance->c4_frame)[c4_i0] = c4_dv0[c4_i0];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("state", c4_u,
    1)), "state", c4_iv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*chartInstance->c4_state)[c4_i1] = c4_iv0[c4_i1];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("cur", c4_u, 2)),
                      "cur", &chartInstance->c4_cur_not_empty, c4_dv1);
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    chartInstance->c4_cur[c4_i2] = c4_dv1[c4_i2];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("pos", c4_u, 3)),
                      "pos", &chartInstance->c4_pos_not_empty, c4_dv2);
  for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
    chartInstance->c4_pos[c4_i3] = c4_dv2[c4_i3];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("stitched",
    c4_u, 4)), "stitched", &chartInstance->c4_stitched_not_empty, c4_dv3);
  for (c4_i4 = 0; c4_i4 < 16; c4_i4++) {
    chartInstance->c4_stitched[c4_i4] = c4_dv3[c4_i4];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("vel", c4_u, 5)),
                      "vel", &chartInstance->c4_vel_not_empty, c4_dv4);
  for (c4_i5 = 0; c4_i5 < 4; c4_i5++) {
    chartInstance->c4_vel[c4_i5] = c4_dv4[c4_i5];
  }

  chartInstance->c4_is_active_c4_testmodel_1109 = c4_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c4_testmodel_1109",
       c4_u, 6)), "is_active_c4_testmodel_1109");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_testmodel_1109(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  for (c4_i6 = 0; c4_i6 < 8; c4_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_inp)[c4_i6], 0U, 1U, 0U,
                          chartInstance->c4_sfEvent, false);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_testmodel_1109(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testmodel_1109MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i7 = 0; c4_i7 < 16; c4_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_frame)[c4_i7], 1U, 1U, 0U,
                          chartInstance->c4_sfEvent, false);
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c4_state)[c4_i8], 2U, 1U, 0U,
                          chartInstance->c4_sfEvent, false);
  }
}

static void mdl_start_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_chartstep_c4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  int32_T c4_i9;
  uint8_T c4_b_inp[8];
  uint32_T c4_debug_family_var_map[13];
  uint8_T c4_compare[3];
  int32_T c4_pos1;
  int32_T c4_vel1;
  int32_T c4_cur1;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_b_frame[16];
  int32_T c4_b_state[3];
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  real_T c4_d0;
  uint8_T c4_u0;
  int32_T c4_i14;
  uint8_T c4_varargin_1[3];
  uint8_T c4_mtmp;
  int32_T c4_ix;
  int32_T c4_b_ix;
  uint8_T c4_a;
  uint8_T c4_b;
  boolean_T c4_p;
  uint8_T c4_b_mtmp;
  uint8_T c4_maxval;
  int32_T c4_i15;
  int32_T c4_i16;
  uint8_T c4_u1;
  int32_T c4_i17;
  real_T c4_hoistedGlobal[4];
  const mxArray *c4_y = NULL;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  const mxArray *c4_c_y = NULL;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  real_T c4_d1;
  uint8_T c4_u2;
  uint8_T c4_uv0[4];
  int32_T c4_i30;
  real_T c4_d2;
  uint8_T c4_u3;
  uint8_T c4_uv1[4];
  int32_T c4_i31;
  real_T c4_d3;
  uint8_T c4_u4;
  uint8_T c4_uv2[4];
  int32_T c4_i32;
  int32_T c4_i33;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  for (c4_i9 = 0; c4_i9 < 8; c4_i9++) {
    c4_b_inp[c4_i9] = (*chartInstance->c4_inp)[c4_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_compare, 0U, c4_h_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_pos1, 1U, c4_g_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vel1, 2U, c4_g_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_cur1, 3U, c4_g_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 4U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 5U, c4_f_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_inp, 6U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_frame, 7U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_state, 8U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_stitched, 9U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_pos, 10U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_vel, 11U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_cur, 12U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_stitched_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
    for (c4_i10 = 0; c4_i10 < 16; c4_i10++) {
      chartInstance->c4_stitched[c4_i10] = 0.0;
    }

    chartInstance->c4_stitched_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
    for (c4_i11 = 0; c4_i11 < 4; c4_i11++) {
      chartInstance->c4_pos[c4_i11] = 0.0;
    }

    chartInstance->c4_pos_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
    for (c4_i12 = 0; c4_i12 < 4; c4_i12++) {
      chartInstance->c4_vel[c4_i12] = 0.0;
    }

    chartInstance->c4_vel_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
    for (c4_i13 = 0; c4_i13 < 4; c4_i13++) {
      chartInstance->c4_cur[c4_i13] = 0.0;
    }

    chartInstance->c4_cur_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_compare[0] = 7U;
  c4_compare[1] = c4_b_inp[0];
  c4_d0 = muDoubleScalarRound(chartInstance->c4_stitched[0]);
  if (c4_d0 < 256.0) {
    if (CV_SATURATION_EVAL(4, 0, 3, 1, c4_d0 >= 0.0)) {
      c4_u0 = (uint8_T)c4_d0;
    } else {
      c4_u0 = 0U;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c4_d0 >= 256.0)) {
    c4_u0 = MAX_uint8_T;
  } else {
    c4_u0 = 0U;
  }

  c4_compare[2] = c4_u0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_varargin_1[c4_i14] = c4_compare[c4_i14];
  }

  c4_mtmp = c4_varargin_1[0];
  for (c4_ix = 2; c4_ix < 4; c4_ix++) {
    c4_b_ix = c4_ix - 1;
    c4_a = c4_varargin_1[c4_b_ix];
    c4_b = c4_mtmp;
    c4_p = (c4_a > c4_b);
    if (c4_p) {
      c4_mtmp = c4_varargin_1[c4_b_ix];
    }
  }

  c4_b_mtmp = c4_mtmp;
  c4_maxval = c4_b_mtmp;
  chartInstance->c4_stitched[0] = (real_T)c4_maxval;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c4_b_inp[2],
        149.0, -1, 0U, (real_T)c4_b_inp[2] == 149.0))) {
    guard1 = true;
  } else if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1,
               chartInstance->c4_stitched[1], 149.0, -1, 0U,
               chartInstance->c4_stitched[1] == 149.0))) {
    guard1 = true;
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 1, true);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
    if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, (real_T)c4_b_inp[1],
          132.0, -1, 0U, (real_T)c4_b_inp[1] == 132.0))) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
      for (c4_i15 = 0; c4_i15 < 6; c4_i15++) {
        chartInstance->c4_stitched[c4_i15 + 1] = (real_T)c4_b_inp[c4_i15 + 2];
      }

      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
      for (c4_i16 = 0; c4_i16 < 4; c4_i16++) {
        chartInstance->c4_pos[c4_i16] = (real_T)c4_b_inp[c4_i16 + 3];
      }

      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
      c4_u1 = c4_b_inp[7];
      if (CV_SATURATION_EVAL(4, 0, 4, 0, c4_u1 > 127)) {
        c4_u1 = 127U;
      }

      chartInstance->c4_vel[0] = (real_T)(int8_T)c4_u1;
      sf_mex_printf("%s =\\n", "vel");
      for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
        c4_hoistedGlobal[c4_i17] = chartInstance->c4_vel[c4_i17];
      }

      c4_y = NULL;
      sf_mex_assign(&c4_y, sf_mex_create("y", c4_hoistedGlobal, 0, 0U, 1U, 0U, 2,
        1, 4), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, (real_T)c4_b_inp[1],
            133.0, -1, 0U, (real_T)c4_b_inp[1] == 133.0))) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
        for (c4_i18 = 0; c4_i18 < 6; c4_i18++) {
          chartInstance->c4_stitched[c4_i18 + 7] = (real_T)c4_b_inp[c4_i18 + 2];
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
        for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
          chartInstance->c4_vel[c4_i19 + 1] = (real_T)c4_b_inp[c4_i19 + 2];
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
        for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
          chartInstance->c4_cur[c4_i20] = (real_T)c4_b_inp[c4_i20 + 5];
        }

        sf_mex_printf("%s =\\n", "cur");
        for (c4_i21 = 0; c4_i21 < 4; c4_i21++) {
          c4_hoistedGlobal[c4_i21] = chartInstance->c4_cur[c4_i21];
        }

        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_hoistedGlobal, 0, 0U, 1U,
          0U, 2, 1, 4), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_b_y);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
        if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, (real_T)c4_b_inp[1],
              134.0, -1, 0U, (real_T)c4_b_inp[1] == 134.0))) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
          if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5,
                chartInstance->c4_stitched[0], 13.0, -1, 4U,
                chartInstance->c4_stitched[0] > 13.0))) {
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
            for (c4_i22 = 0; c4_i22 < 3; c4_i22++) {
              chartInstance->c4_stitched[c4_i22 + 13] = (real_T)c4_b_inp[c4_i22
                + 2];
            }

            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
            chartInstance->c4_cur[3] = (real_T)c4_b_inp[2];
          } else {
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
            for (c4_i23 = 0; c4_i23 < 5; c4_i23++) {
              chartInstance->c4_stitched[c4_i23 + 7] = (real_T)c4_b_inp[c4_i23 +
                2];
            }

            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
            for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
              chartInstance->c4_vel[c4_i24 + 1] = (real_T)c4_b_inp[c4_i24 + 2];
            }

            sf_mex_printf("%s =\\n", "vel");
            for (c4_i25 = 0; c4_i25 < 4; c4_i25++) {
              c4_hoistedGlobal[c4_i25] = chartInstance->c4_vel[c4_i25];
            }

            c4_c_y = NULL;
            sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_hoistedGlobal, 0, 0U,
              1U, 0U, 2, 1, 4), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c4_c_y);
          }
        } else {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
          if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, (real_T)c4_b_inp
                [1], 149.0, -1, 0U, (real_T)c4_b_inp[1] == 149.0))) {
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
            for (c4_i26 = 0; c4_i26 < 7; c4_i26++) {
              chartInstance->c4_stitched[c4_i26 + 1] = (real_T)c4_b_inp[c4_i26 +
                1];
            }

            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
            for (c4_i27 = 0; c4_i27 < 4; c4_i27++) {
              chartInstance->c4_pos[c4_i27] = (real_T)c4_b_inp[c4_i27 + 2];
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
  for (c4_i28 = 0; c4_i28 < 16; c4_i28++) {
    c4_b_frame[c4_i28] = chartInstance->c4_stitched[c4_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  for (c4_i29 = 0; c4_i29 < 4; c4_i29++) {
    c4_d1 = muDoubleScalarRound(chartInstance->c4_pos[c4_i29]);
    if (c4_d1 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c4_d1 >= 0.0)) {
        c4_u2 = (uint8_T)c4_d1;
      } else {
        c4_u2 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c4_d1 >= 256.0)) {
      c4_u2 = MAX_uint8_T;
    } else {
      c4_u2 = 0U;
    }

    c4_uv0[c4_i29] = c4_u2;
  }

  c4_pos1 = c4_typecast(chartInstance, c4_uv0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  for (c4_i30 = 0; c4_i30 < 4; c4_i30++) {
    c4_d2 = muDoubleScalarRound(chartInstance->c4_vel[c4_i30]);
    if (c4_d2 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 1, 1, c4_d2 >= 0.0)) {
        c4_u3 = (uint8_T)c4_d2;
      } else {
        c4_u3 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c4_d2 >= 256.0)) {
      c4_u3 = MAX_uint8_T;
    } else {
      c4_u3 = 0U;
    }

    c4_uv1[c4_i30] = c4_u3;
  }

  c4_vel1 = c4_typecast(chartInstance, c4_uv1);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
  for (c4_i31 = 0; c4_i31 < 4; c4_i31++) {
    c4_d3 = muDoubleScalarRound(chartInstance->c4_cur[c4_i31]);
    if (c4_d3 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 2, 1, c4_d3 >= 0.0)) {
        c4_u4 = (uint8_T)c4_d3;
      } else {
        c4_u4 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 2, 0, c4_d3 >= 256.0)) {
      c4_u4 = MAX_uint8_T;
    } else {
      c4_u4 = 0U;
    }

    c4_uv2[c4_i31] = c4_u4;
  }

  c4_cur1 = c4_typecast(chartInstance, c4_uv2);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 48);
  c4_b_state[0] = c4_pos1;
  c4_b_state[1] = c4_vel1;
  c4_b_state[2] = c4_cur1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i32 = 0; c4_i32 < 16; c4_i32++) {
    (*chartInstance->c4_frame)[c4_i32] = c4_b_frame[c4_i32];
  }

  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    (*chartInstance->c4_state)[c4_i33] = c4_b_state[c4_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_testmodel_1109(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i34;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i34 = 0; c4_i34 < 4; c4_i34++) {
    c4_u[c4_i34] = (*(real_T (*)[4])c4_inData)[c4_i34];
  }

  c4_y = NULL;
  if (!chartInstance->c4_cur_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c4_b_cur, const char_T *c4_identifier, boolean_T *c4_svPtr,
  real_T c4_y[4])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_cur), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_cur);
}

static void c4_b_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr, real_T c4_y[4])
{
  real_T c4_dv5[4];
  int32_T c4_i35;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv5, 1, 0, 0U, 1, 0U, 2, 1,
                  4);
    for (c4_i35 = 0; c4_i35 < 4; c4_i35++) {
      c4_y[c4_i35] = c4_dv5[c4_i35];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_cur;
  const char_T *c4_identifier;
  boolean_T *c4_svPtr;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[4];
  int32_T c4_i36;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_b_cur = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_svPtr = &chartInstance->c4_cur_not_empty;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_cur), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_cur);
  for (c4_i36 = 0; c4_i36 < 4; c4_i36++) {
    (*(real_T (*)[4])c4_outData)[c4_i36] = c4_y[c4_i36];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i37;
  real_T c4_u[16];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i37 = 0; c4_i37 < 16; c4_i37++) {
    c4_u[c4_i37] = (*(real_T (*)[16])c4_inData)[c4_i37];
  }

  c4_y = NULL;
  if (!chartInstance->c4_stitched_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 16),
                  false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_stitched, const char_T *c4_identifier,
  boolean_T *c4_svPtr, real_T c4_y[16])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_stitched), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_stitched);
}

static void c4_d_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr, real_T c4_y[16])
{
  real_T c4_dv6[16];
  int32_T c4_i38;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                  16);
    for (c4_i38 = 0; c4_i38 < 16; c4_i38++) {
      c4_y[c4_i38] = c4_dv6[c4_i38];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_stitched;
  const char_T *c4_identifier;
  boolean_T *c4_svPtr;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[16];
  int32_T c4_i39;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_b_stitched = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_svPtr = &chartInstance->c4_stitched_not_empty;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_stitched), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_stitched);
  for (c4_i39 = 0; c4_i39 < 16; c4_i39++) {
    (*(real_T (*)[16])c4_outData)[c4_i39] = c4_y[c4_i39];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i40;
  int32_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i40 = 0; c4_i40 < 3; c4_i40++) {
    c4_u[c4_i40] = (*(int32_T (*)[3])c4_inData)[c4_i40];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 6, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_state, const char_T *c4_identifier,
  int32_T c4_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_state);
}

static void c4_f_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  int32_T c4_y[3])
{
  int32_T c4_iv1[3];
  int32_T c4_i41;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_iv1, 1, 6, 0U, 1, 0U, 2, 1, 3);
  for (c4_i41 = 0; c4_i41 < 3; c4_i41++) {
    c4_y[c4_i41] = c4_iv1[c4_i41];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_state;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y[3];
  int32_T c4_i42;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_b_state = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_state);
  for (c4_i42 = 0; c4_i42 < 3; c4_i42++) {
    (*(int32_T (*)[3])c4_outData)[c4_i42] = c4_y[c4_i42];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i43;
  real_T c4_u[16];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i43 = 0; c4_i43 < 16; c4_i43++) {
    c4_u[c4_i43] = (*(real_T (*)[16])c4_inData)[c4_i43];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 16), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_g_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_frame, const char_T *c4_identifier, real_T
  c4_y[16])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_frame), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_frame);
}

static void c4_h_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[16])
{
  real_T c4_dv7[16];
  int32_T c4_i44;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv7, 1, 0, 0U, 1, 0U, 2, 1, 16);
  for (c4_i44 = 0; c4_i44 < 16; c4_i44++) {
    c4_y[c4_i44] = c4_dv7[c4_i44];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_frame;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[16];
  int32_T c4_i45;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_b_frame = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_frame), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_frame);
  for (c4_i45 = 0; c4_i45 < 16; c4_i45++) {
    (*(real_T (*)[16])c4_outData)[c4_i45] = c4_y[c4_i45];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i46;
  uint8_T c4_u[8];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i46 = 0; c4_i46 < 8; c4_i46++) {
    c4_u[c4_i46] = (*(uint8_T (*)[8])c4_inData)[c4_i46];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 1, 8), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_i_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d4;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d4, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d4;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_j_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i47;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i47, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i47;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_cur1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_cur1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_cur1), &c4_thisId);
  sf_mex_destroy(&c4_cur1);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i48;
  uint8_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i48 = 0; c4_i48 < 3; c4_i48++) {
    c4_u[c4_i48] = (*(uint8_T (*)[3])c4_inData)[c4_i48];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_k_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint8_T c4_y[3])
{
  uint8_T c4_uv3[3];
  int32_T c4_i49;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv3, 1, 3, 0U, 1, 0U, 2, 1, 3);
  for (c4_i49 = 0; c4_i49 < 3; c4_i49++) {
    c4_y[c4_i49] = c4_uv3[c4_i49];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_compare;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y[3];
  int32_T c4_i50;
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c4_compare = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_compare), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_compare);
  for (c4_i50 = 0; c4_i50 < 3; c4_i50++) {
    (*(uint8_T (*)[3])c4_outData)[c4_i50] = c4_y[c4_i50];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_testmodel_1109_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static int32_T c4_typecast(SFc4_testmodel_1109InstanceStruct *chartInstance,
  uint8_T c4_x[4])
{
  int32_T c4_y;
  (void)chartInstance;
  memcpy(&c4_y, &c4_x[0], (size_t)1 * sizeof(int32_T));
  return c4_y;
}

static uint8_T c4_l_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_testmodel_1109, const char_T *
  c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_testmodel_1109), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_testmodel_1109);
  return c4_y;
}

static uint8_T c4_m_emlrt_marshallIn(SFc4_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u5;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u5, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u5;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_testmodel_1109InstanceStruct
  *chartInstance)
{
  chartInstance->c4_inp = (uint8_T (*)[8])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_frame = (real_T (*)[16])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_state = (int32_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c4_testmodel_1109_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3376601770U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2774165303U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1269550999U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3861928296U);
}

mxArray* sf_c4_testmodel_1109_get_post_codegen_info(void);
mxArray *sf_c4_testmodel_1109_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Fl7crw61umzFNnAgLyVf6G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(16);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_testmodel_1109_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_testmodel_1109_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_testmodel_1109_jit_fallback_info(void)
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

mxArray *sf_c4_testmodel_1109_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_testmodel_1109_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_testmodel_1109(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"frame\",},{M[1],M[7],T\"state\",},{M[4],M[0],T\"cur\",S'l','i','p'{{M1x2[117 120],M[0],}}},{M[4],M[0],T\"pos\",S'l','i','p'{{M1x2[85 88],M[0],}}},{M[4],M[0],T\"stitched\",S'l','i','p'{{M1x2[64 72],M[0],}}},{M[4],M[0],T\"vel\",S'l','i','p'{{M1x2[101 104],M[0],}}},{M[8],M[0],T\"is_active_c4_testmodel_1109\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_testmodel_1109_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_testmodel_1109InstanceStruct *chartInstance =
      (SFc4_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testmodel_1109MachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"inp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"frame");
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
        _SFD_CV_INIT_EML(0,1,1,0,7,0,5,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1800);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,1168,-1,1178);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,1208,-1,1218);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,1248,-1,1258);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,259,-1,270);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,525,-1,537);
        _SFD_CV_INIT_EML_IF(0,1,0,123,143,-1,237);
        _SFD_CV_INIT_EML_IF(0,1,1,301,359,-1,1129);
        _SFD_CV_INIT_EML_IF(0,1,2,364,390,542,572);
        _SFD_CV_INIT_EML_IF(0,1,3,542,572,716,1125);
        _SFD_CV_INIT_EML_IF(0,1,4,716,746,1004,1125);
        _SFD_CV_INIT_EML_IF(0,1,5,777,796,892,998);
        _SFD_CV_INIT_EML_IF(0,1,6,1004,1034,-1,1034);

        {
          static int condStart[] = { 305, 332 };

          static int condEnd[] = { 326, 358 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,304,359,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,305,326,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,332,358,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,367,390,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,549,572,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,723,746,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,780,796,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,1011,1034,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 8U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 16U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
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
    SFc4_testmodel_1109InstanceStruct *chartInstance =
      (SFc4_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c4_inp);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c4_frame);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c4_state);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sUYgwWq1d1sdy5xW3XbyWQH";
}

static void sf_opaque_initialize_c4_testmodel_1109(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar);
  initialize_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_testmodel_1109(void *chartInstanceVar)
{
  enable_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_testmodel_1109(void *chartInstanceVar)
{
  disable_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_testmodel_1109(void *chartInstanceVar)
{
  sf_gateway_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_testmodel_1109(SimStruct* S)
{
  return get_sim_state_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_testmodel_1109(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_testmodel_1109(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_testmodel_1109InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testmodel_1109_optimization_info();
    }

    finalize_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
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
  initSimStructsc4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_testmodel_1109(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_testmodel_1109((SFc4_testmodel_1109InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_testmodel_1109(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testmodel_1109_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1347190256U));
  ssSetChecksum1(S,(150190832U));
  ssSetChecksum2(S,(2249274207U));
  ssSetChecksum3(S,(3009808713U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_testmodel_1109(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_testmodel_1109(SimStruct *S)
{
  SFc4_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc4_testmodel_1109InstanceStruct *)utMalloc(sizeof
    (SFc4_testmodel_1109InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_testmodel_1109InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_testmodel_1109;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_testmodel_1109;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_testmodel_1109;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_testmodel_1109;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_testmodel_1109;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_testmodel_1109;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_testmodel_1109;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_testmodel_1109;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_testmodel_1109;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_testmodel_1109;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_testmodel_1109;
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
  mdl_start_c4_testmodel_1109(chartInstance);
}

void c4_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_testmodel_1109(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_testmodel_1109(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_testmodel_1109(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_testmodel_1109_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
