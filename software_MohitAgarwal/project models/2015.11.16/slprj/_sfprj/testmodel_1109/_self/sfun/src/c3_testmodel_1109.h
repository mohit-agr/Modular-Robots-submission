#ifndef __c3_testmodel_1109_h__
#define __c3_testmodel_1109_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc3_testmodel_1109InstanceStruct
#define typedef_SFc3_testmodel_1109InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_testmodel_1109;
  uint8_T (*c3_cur)[4];
  uint32_T *c3_inp;
  real_T *c3_time;
} SFc3_testmodel_1109InstanceStruct;

#endif                                 /*typedef_SFc3_testmodel_1109InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_testmodel_1109_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_testmodel_1109_get_check_sum(mxArray *plhs[]);
extern void c3_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
