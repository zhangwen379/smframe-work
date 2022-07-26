#ifndef VARSTATE_WORK_ALLSYSTEM_H
#define VARSTATE_WORK_ALLSYSTEM_H

#include "varstate_work.h"
class VarState_Work_AllSystem : public VarState_Work
{
public:
    VarState_Work_AllSystem(int iID, VarStateMachine *pParent);

    void do_Msg(const VarMsg& msg);
};

#endif // VARSTATE_WORK_ALLSYSTEM_H
