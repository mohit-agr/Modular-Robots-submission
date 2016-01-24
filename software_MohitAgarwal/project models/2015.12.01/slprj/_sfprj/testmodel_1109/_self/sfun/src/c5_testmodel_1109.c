/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testmodel_1109_sfun.h"
#include "c5_testmodel_1109.h"
#include <string.h>
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
static const char * c5_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void initialize_params_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance);
static void enable_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void disable_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance);
static void set_sim_state_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void sf_gateway_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void mdl_start_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void initSimStructsc5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c5_b_y, const char_T *c5_identifier, uint8_T c5_c_y[4]);
static void c5_b_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  uint8_T c5_b_y[4]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testmodel_1109, const char_T *
  c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_testmodel_1109InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_testmodel_1109InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_testmodel_1109(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_testmodel_1109 = 0U;
}

static void initialize_params_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_testmodel_1109
  (SFc5_testmodel_1109InstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_d_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(2, 1), false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", *chartInstance->c5_y, 3, 0U, 1U, 0U,
    2, 1, 4), false);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_testmodel_1109;
  c5_b_u = c5_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 1, c5_d_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_b_u;
  uint8_T c5_uv0[4];
  int32_T c5_i0;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_b_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("y", c5_b_u, 0)),
                      "y", c5_uv0);
  for (c5_i0 = 0; c5_i0 < 4; c5_i0++) {
    (*chartInstance->c5_y)[c5_i0] = c5_uv0[c5_i0];
  }

  chartInstance->c5_is_active_c5_testmodel_1109 = c5_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c5_testmodel_1109",
       c5_b_u, 1)), "is_active_c5_testmodel_1109");
  sf_mex_destroy(&c5_b_u);
  c5_update_debugger_state_c5_testmodel_1109(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  uint32_T c5_hoistedGlobal;
  uint32_T c5_b_u;
  uint32_T c5_debug_family_var_map[4];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  uint8_T c5_b_y[4];
  uint32_T c5_x;
  int32_T c5_i1;
  int32_T c5_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c5_u, 0U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *chartInstance->c5_u;
  c5_b_u = c5_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_u, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_x = c5_b_u;
  memcpy(&c5_b_y[0], &c5_x, (size_t)4 * sizeof(uint8_T));
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i1 = 0; c5_i1 < 4; c5_i1++) {
    (*chartInstance->c5_y)[c5_i1] = c5_b_y[c5_i1];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testmodel_1109MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i2 = 0; c5_i2 < 4; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_y)[c5_i2], 1U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }
}

static void mdl_start_c5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_testmodel_1109(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i3;
  uint8_T c5_b_u[4];
  const mxArray *c5_b_y = NULL;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i3 = 0; c5_i3 < 4; c5_i3++) {
    c5_b_u[c5_i3] = (*(uint8_T (*)[4])c5_inData)[c5_i3];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 3, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct *chartInstance,
  const mxArray *c5_b_y, const char_T *c5_identifier, uint8_T c5_c_y[4])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_b_y);
}

static void c5_b_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  uint8_T c5_b_y[4])
{
  uint8_T c5_uv1[4];
  int32_T c5_i4;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_uv1, 1, 3, 0U, 1, 0U, 2, 1,
                4);
  for (c5_i4 = 0; c5_i4 < 4; c5_i4++) {
    c5_b_y[c5_i4] = c5_uv1[c5_i4];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_c_y[4];
  int32_T c5_i5;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_b_y);
  for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
    (*(uint8_T (*)[4])c5_outData)[c5_i5] = c5_c_y[c5_i5];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint32_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(uint32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(real_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout),
    &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_testmodel_1109_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(int32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_b_y;
  int32_T c5_i6;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_i6, 1, 6, 0U, 0, 0U, 0);
  c5_b_y = c5_i6;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_b_y;
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testmodel_1109, const char_T *
  c5_identifier)
{
  uint8_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_testmodel_1109), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_testmodel_1109);
  return c5_b_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_testmodel_1109InstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_u0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void init_dsm_address_info(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_testmodel_1109InstanceStruct
  *chartInstance)
{
  chartInstance->c5_u = (uint32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_y = (uint8_T (*)[4])ssGetOutputPortSignal_wrapper
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

void sf_c5_testmodel_1109_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1428655410U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3255636928U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2718985916U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3252076977U);
}

mxArray* sf_c5_testmodel_1109_get_post_codegen_info(void);
mxArray *sf_c5_testmodel_1109_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9NW5KBdYRORrLal87U7IFB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c5_testmodel_1109_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_testmodel_1109_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_testmodel_1109_jit_fallback_info(void)
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

mxArray *sf_c5_testmodel_1109_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_testmodel_1109_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_testmodel_1109(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_testmodel_1109\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_testmodel_1109_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_testmodel_1109InstanceStruct *chartInstance =
      (SFc5_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testmodel_1109MachineNumber_,
           5,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,73);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
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
    SFc5_testmodel_1109InstanceStruct *chartInstance =
      (SFc5_testmodel_1109InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c5_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "saCEvrJwny0SIwsCixYcKzB";
}

static void sf_opaque_initialize_c5_testmodel_1109(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar);
  initialize_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_testmodel_1109(void *chartInstanceVar)
{
  enable_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_testmodel_1109(void *chartInstanceVar)
{
  disable_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_testmodel_1109(void *chartInstanceVar)
{
  sf_gateway_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_testmodel_1109(SimStruct* S)
{
  return get_sim_state_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_testmodel_1109(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c5_testmodel_1109(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_testmodel_1109InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testmodel_1109_optimization_info();
    }

    finalize_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
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
  initSimStructsc5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_testmodel_1109(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_testmodel_1109((SFc5_testmodel_1109InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c5_testmodel_1109(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testmodel_1109_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 5);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2468408201U));
  ssSetChecksum1(S,(1432615479U));
  ssSetChecksum2(S,(3339347497U));
  ssSetChecksum3(S,(1052513505U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_testmodel_1109(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_testmodel_1109(SimStruct *S)
{
  SFc5_testmodel_1109InstanceStruct *chartInstance;
  chartInstance = (SFc5_testmodel_1109InstanceStruct *)utMalloc(sizeof
    (SFc5_testmodel_1109InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_testmodel_1109InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_testmodel_1109;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_testmodel_1109;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_testmodel_1109;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_testmodel_1109;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_testmodel_1109;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_testmodel_1109;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_testmodel_1109;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_testmodel_1109;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_testmodel_1109;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_testmodel_1109;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_testmodel_1109;
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
  mdl_start_c5_testmodel_1109(chartInstance);
}

void c5_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_testmodel_1109(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_testmodel_1109(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_testmodel_1109(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_testmodel_1109_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
