#ifndef _RTW_HEADER_testmodel1_1102_cap_host_h__
#define _RTW_HEADER_testmodel1_1102_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} testmodel1_1102_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void testmodel1_1102_host_InitializeDataMapInfo
    (testmodel1_1102_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* _RTW_HEADER_testmodel1_1102_cap_host_h__ */

/* EOF: testmodel1_1102_capi_host.h */
