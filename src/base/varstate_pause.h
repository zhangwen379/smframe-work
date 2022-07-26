#ifndef VARSTATE_PAUSE_H
#define VARSTATE_PAUSE_H

#include "varstate_idle.h"
class VarState_Pause : public VarState_Idle
{
public:
    VarState_Pause(int iID, VarStateMachine *pParent);
};

#endif // VARSTATE_PAUSE_H
