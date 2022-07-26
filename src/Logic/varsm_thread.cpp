#include "varsm_thread.h"
#include <QDebug>

VarSM_Thread::VarSM_Thread()
{
}

VarSM_Thread::VarSM_Thread(int iID, const QString &sName)
    :VarStateMachine(iID, sName)
{
}

VarSM_Thread::~VarSM_Thread()
{
    m_bExit=true;
    while(::ResumeThread(m_ThreadHandle));
    ::WaitForSingleObject(m_ThreadHandle,1000);
}

DWORD WINAPI ThreadRun(LPVOID lpVoid)
{
    VarSM_Thread* pStateMachine=(VarSM_Thread*)lpVoid;
    while(!pStateMachine->m_bExit)
    {
        try
        {
           VarMsg msg= pStateMachine->run();
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
HANDLE VarSM_Thread::CreateThread()
{
    DWORD threadId;
    m_ThreadHandle=::CreateThread(NULL, 0,	ThreadRun, (LPVOID)this, 0, &threadId);
    Q_ASSERT(m_ThreadHandle);
    return m_ThreadHandle;

}

void VarSM_Thread::pushBack_Msg(int iStateID, const VarMsg &msg)
{
    VarState *pState=0;
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

void VarSM_Thread::pushFront_Msg(int iStateID, const VarMsg &msg)
{
    VarState *pState=get_VarState(iStateID);
    if(!pState)
    {
        pState=get_VarState(m_iStateID);
    }
    pState->pushfront_Msg(msg);
    while(::ResumeThread(m_ThreadHandle));
}

void VarSM_Thread::Init()
{
    CreateThread();
    m_bExit=false;
    VarStateMachine::Init();
}

