#ifndef VARSM_THREAD_H
#define VARSM_THREAD_H

#include "logic.h"
#include "varstatemachine.h"
class VarSM_Thread : public VarStateMachine
{
public:
    VarSM_Thread();
    VarSM_Thread(int iID,const QString& sName);
    ~VarSM_Thread();
public:
    HANDLE CreateThread();
    HANDLE m_ThreadHandle;
    void pushBack_Msg(int iStateID,const VarMsg& msg);
    void pushFront_Msg(int iStateID,const VarMsg& msg);
    bool m_bExit;
protected:
    void Init();
};

#endif // VARSM_THREAD_H
