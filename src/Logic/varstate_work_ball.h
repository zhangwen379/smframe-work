#ifndef VARSTATE_WORK_BALL_H
#define VARSTATE_WORK_BALL_H
#include "logic.h"
#include "varstate_work.h"
class VarState_Work_Ball : public VarState_Work
{
public:
    VarState_Work_Ball(int iID,VarStateMachine* pParent);
public:
    void do_Msg(const VarMsg& msg);
};

#endif // VARSTATE_WORK_BALL_H
