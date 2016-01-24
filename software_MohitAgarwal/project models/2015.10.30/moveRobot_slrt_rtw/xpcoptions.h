#ifndef __moveRobot_XPCOPTIONS_H___
#define __moveRobot_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "moveRobot.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_moveRobot_T))
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
void moveRobot_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_moveRobot_T *
  const moveRobot_M)
{
  real_T ratio = newBaseRateStepSize / 1.0;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  moveRobot_M->Timing.stepSize0 = moveRobot_M->Timing.stepSize0 * ratio;
  moveRobot_M->Timing.stepSize1 = moveRobot_M->Timing.stepSize1 * ratio;
  moveRobot_M->Timing.stepSize = moveRobot_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  moveRobot_ChangeStepSize(stepSize, moveRobot_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(moveRobot_M, errMsg);
}

#endif                                 /* __moveRobot_XPCOPTIONS_H___ */
