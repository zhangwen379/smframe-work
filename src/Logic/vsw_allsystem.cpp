#include "vsw_allsystem.h"
#include "vsmt_allsystem.h"
VSW_AllSystem::VSW_AllSystem(int iID, V_StateMachine *pParent)
    :VS_Work( iID,  pParent)
{

}

void VSW_AllSystem::do_Msg(const V_Msg &msg)
{
    VS_Work::do_Msg(msg);
}

