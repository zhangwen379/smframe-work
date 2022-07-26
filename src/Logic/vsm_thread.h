#ifndef VSM_THREAD_H
#define VSM_THREAD_H

#include "logic.h"
#include "v_statemachine.h"
class VSM_Thread : public V_StateMachine
{
public:
    VSM_Thread();
    VSM_Thread(int iID,const QString& sName);
    ~VSM_Thread();
public:
    HANDLE CreateThread();
    HANDLE m_ThreadHandle;
    void pushBack_Msg(int iStateID,const V_Msg& msg);
    void pushFront_Msg(int iStateID,const V_Msg& msg);
    bool m_bExit;
protected:
    void Init();
};

#endif // VARSM_THREAD_H
