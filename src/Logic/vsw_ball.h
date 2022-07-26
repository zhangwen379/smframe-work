#ifndef VSW_BALL_H
#define VSW_BALL_H
#include "logic.h"
#include "vs_work.h"
class VSW_Ball : public VS_Work
{
public:
    VSW_Ball(int iID,V_StateMachine* pParent);
public:
    void do_Msg(const V_Msg& msg);
};

#endif // VSW_BALL_H
