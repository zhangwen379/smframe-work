#ifndef VS_IDLE_H
#define VS_IDLE_H

#include "v_state.h"
class VS_Idle : public V_State
{
public:
    VS_Idle(int iID,V_StateMachine* pParent);
};

#endif // VS_IDLE_H
