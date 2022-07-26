#include "varstate_work_allsystem.h"

VarState_Work_AllSystem::VarState_Work_AllSystem(int iID, VarStateMachine *pParent)
    :VarState_Work( iID,  pParent)
{

}

void VarState_Work_AllSystem::do_Msg(const VarMsg &msg)
{

    VarState_Work::do_Msg(msg);
}

