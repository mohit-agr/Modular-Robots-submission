#ifndef __testmodel_1109_XPCOPTIONS_H___
#define __testmodel_1109_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "testmodel_1109.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_testmodel_1109_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void testmodel_1109_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_testmodel_1109_T *const testmodel_1109_M)
{
  real_T ratio = newBaseRateStepSize / 0.01;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  testmodel_1109_M->Timing.stepSize0 = testmodel_1109_M->Timing.stepSize0 *
    ratio;
  testmodel_1109_M->Timing.stepSize1 = testmodel_1109_M->Timing.stepSize1 *
    ratio;
  testmodel_1109_M->Timing.stepSize = testmodel_1109_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  testmodel_1109_ChangeStepSize(stepSize, testmodel_1109_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(testmodel_1109_M, errMsg);
}

#endif                                 /* __testmodel_1109_XPCOPTIONS_H___ */
