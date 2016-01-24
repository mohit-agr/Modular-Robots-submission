#ifndef __c4_testmodel_1109_h__
#define __c4_testmodel_1109_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc4_testmodel_1109InstanceStruct
#define typedef_SFc4_testmodel_1109InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_testmodel_1109;
  real_T c4_stitched[16];
  boolean_T c4_stitched_not_empty;
  real_T c4_pos[4];
  boolean_T c4_pos_not_empty;
  real_T c4_vel[4];
  boolean_T c4_vel_not_empty;
  real_T c4_cur[4];
  boolean_T c4_cur_not_empty;
  uint8_T (*c4_inp)[8];
  real_T (*c4_frame)[16];
  int32_T (*c4_state)[3];
} SFc4_testmodel_1109InstanceStruct;

#endif                                 /*typedef_SFc4_testmodel_1109InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_testmodel_1109_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_testmodel_1109_get_check_sum(mxArray *plhs[]);
extern void c4_testmodel_1109_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
