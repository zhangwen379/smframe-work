#ifndef VSI_PAUSE_H
#define VSI_PAUSE_H

#include "vs_idle.h"
class VSI_Pause : public VS_Idle
{
public:
    VSI_Pause(int iID, V_StateMachine *pParent);
};

#endif // VSI_PAUSE_H
