#include "varstate.h"
#include <QMutexLocker>

VarState::VarState(int iID, VarStateMachine *pParent)
    :Variant(iID)
{
    m_pParent=pParent;
}

void VarState::pushback_Msg(const VarMsg &msg)
{
    QMutexLocker locker(&mutex);
    m_VarMsgQueue.m_lVarMsg.push_back(msg);
}

void VarState::pushfront_Msg(const VarMsg &msg)
{
    QMutexLocker locker(&mutex);
    m_VarMsgQueue.m_lVarMsg.push_front(msg);
}


VarMsg VarState::popfront_Msg()
{
    QMutexLocker locker(&mutex);
    VarMsg msgFront(0);
    if(!m_VarMsgQueue.m_lVarMsg.isEmpty())
    {
       msgFront=m_VarMsgQueue.m_lVarMsg.front();
       m_VarMsgQueue.m_lVarMsg.pop_front();
    }
    return msgFront;
}

void VarState::clear_Msg()
{
    QMutexLocker locker(&mutex);
    m_VarMsgQueue.m_lVarMsg.clear();
}

void VarState::do_Msg(const VarMsg &msg)
{
    UNUSED(msg);
    switch(msg.m_iID)
    {
    case VarMsg_Stop_ID:
    {
        clear_Msg();
    }
    }
}

