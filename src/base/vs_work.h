#ifndef VS_WORK_H
#define VS_WORK_H

#include "v_state.h"
class VS_Work : public V_State
{
public:
    VS_Work(int iID, V_StateMachine *pParent);
};

#endif // VS_WORK_H
