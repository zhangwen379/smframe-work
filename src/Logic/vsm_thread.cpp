#include "vsm_thread.h"
#include <QDebug>

VSM_Thread::VSM_Thread()
{
}

VSM_Thread::VSM_Thread(int iID, const QString &sName)
    :V_StateMachine(iID, sName)
{
}

VSM_Thread::~VSM_Thread()
{
    m_bExit=true;
    while(::ResumeThread(m_ThreadHandle));
    ::WaitForSingleObject(m_ThreadHandle,1000);
}

DWORD WINAPI ThreadRun(LPVOID lpVoid)
{
    VSM_Thread* pStateMachine=(VSM_Thread*)lpVoid;
    while(!pStateMachine->m_bExit)
    {
        try
        {
           V_Msg msg= pStateMachine->run();
           if(msg.m_iID==0)
           {
               ::SuspendThread(pStateMachine->m_ThreadHandle);
           }
        }
        catch(QString& s)
        {
            qDebug()<<s;
        }
    }
    return 0;
}
HANDLE VSM_Thread::CreateThread()
{
    DWORD threadId;
    m_ThreadHandle=::CreateThread(NULL, 0,	ThreadRun, (LPVOID)this, 0, &threadId);
    Q_ASSERT(m_ThreadHandle);
    return m_ThreadHandle;

}

void VSM_Thread::pushBack_Msg(int iStateID, const V_Msg &msg)
{
    V_State *pState=0;
    if(!iStateID)
    {
        pState=get_VarState(m_iStateID);
    }
    else
    {
        pState=get_VarState(iStateID);

    }Q_ASSERT(pState);
    pState->pushback_Msg(msg);
    while(::ResumeThread(m_ThreadHandle));
}

void VSM_Thread::pushFront_Msg(int iStateID, const V_Msg &msg)
{
    V_State *pState=get_VarState(iStateID);
    if(!pState)
    {
        pState=get_VarState(m_iStateID);
    }
    pState->pushfront_Msg(msg);
    while(::ResumeThread(m_ThreadHandle));
}

void VSM_Thread::Init()
{
    CreateThread();
    m_bExit=false;
    V_StateMachine::Init();
}

