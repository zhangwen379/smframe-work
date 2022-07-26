#ifndef STATE_H
#define STATE_H

#include "thing.h"
class State : public Thing
{
public:
    State();

    //状态的组件
    Thing* m_pThings;
    //状态机的相互作用，作为作用力相互作用的延申
    void action(State* pState);

};

#endif // STATE_H
