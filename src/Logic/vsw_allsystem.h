#ifndef VSW_ALLSYSTEM_H
#define VSW_ALLSYSTEM_H

#include "vs_work.h"
class VSW_AllSystem : public VS_Work
{
public:
    VSW_AllSystem(int iID, V_StateMachine *pParent);

    void do_Msg(const V_Msg& msg);
};

#endif // VSW_ALLSYSTEM_H
