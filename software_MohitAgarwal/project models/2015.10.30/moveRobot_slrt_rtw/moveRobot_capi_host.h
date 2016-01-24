#ifndef _RTW_HEADER_moveRobot_cap_host_h__
#define _RTW_HEADER_moveRobot_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} moveRobot_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void moveRobot_host_InitializeDataMapInfo(moveRobot_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* _RTW_HEADER_moveRobot_cap_host_h__ */

/* EOF: moveRobot_capi_host.h */
