#ifndef VARSTATE_IDLE_H
#define VARSTATE_IDLE_H

#include "varstate.h"
class VarState_Idle : public VarState
{
public:
    VarState_Idle(int iID,VarStateMachine* pParent);
};

#endif // VARSTATE_IDLE_H
