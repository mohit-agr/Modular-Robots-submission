#ifndef __c2_testmodel_1109_h__
#define __c2_testmodel_1109_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc2_testmodel_1109InstanceStruct
#define typedef_SFc2_testmodel_1109InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_testmodel_1109;
  real_T c2_stitched[12];
  boolean_T c2_stitched_not_empty;
  real_T c2_pos[4];
  boolean_T c2_pos_not_empty;
  real_T c2_vel[4];
  boolean_T c2_vel_not_empty;
  uint8_T (*c2_inp1)[8];
  int32_T (*c2_state)[2];
  uint8_T (*c2_inp2)[7];
} SFc2_testmodel_1109InstanceStruct;

#endif                                 /*typedef_SFc2_testmodel_1109InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_testmodel_1109_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_testmodel_1109_get_check_sum(mxArray *plhs[]);
extern void c2_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
