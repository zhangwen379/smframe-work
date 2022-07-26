#include "varstatemachine.h"
#include "varstate_idle.h"
#include "varstate_pause.h"
#include "varstate_work.h"

VarStateMachine::~VarStateMachine()
{
    MVarState::iterator ii=m_mMVarState.begin();
    for(;ii!=m_mMVarState.end();ii++)
    {
        VarState* pVarState=ii.value();
        if(pVarState)
        {
            delete pVarState;pVarState=0;
        }
    }
}

VarState *VarStateMachine::get_VarState(int iStateID)
{
    MVarState::iterator ii=m_mMVarState.find(iStateID);
    if(ii!=m_mMVarState.end())
    {return ii.value();}
    return 0;
}
VarStateMachine::VarStateMachine()
{

}

VarStateMachine::VarStateMachine(int iID, const QString &sName)
    :Variant(iID,sName)
{

}

VarMsg VarStateMachine::run()
{
    VarState *pState=get_VarState(m_iStateID);
    Q_ASSERT(pState);
    VarMsg msg= pState->popfront_Msg();
    if(msg.m_iID==0)
    {
        return msg;
    }
    try
    {
        pState->do_Msg(msg);
    }
    catch(QString &s)
    {
        if(m_iStateID==VarState_Work_ID)
        {
            pState->pushfront_Msg(msg);
            m_iStateID=VarState_Pause_ID;
        }
        else
        {
            pState->clear_Msg();
        }
        throw(s);
    }
    switch(msg.m_iID)
    {
    case VarMsg_Start_ID:
    {
        if(m_iStateID==VarState_Idle_ID||
                m_iStateID==VarState_Pause_ID)
        {
            m_iStateID=VarState_Work_ID;
        }
        break;
    }
    case VarMsg_Pause_ID:
    {
        if(m_iStateID==VarState_Work_ID)
        {
            m_iStateID=VarState_Pause_ID;
        }
        break;
    }
    case VarMsg_Stop_ID:
    {
        m_iStateID=VarState_Idle_ID;
        break;
    }
    }
    return msg;
}

void VarStateMachine::WriteConfig(QDomDocument &doc, QDomElement &root)
{
    QDomElement elem=AppandRootDom(doc,m_sName,root);
    m_Variants.WriteConfig(doc,elem);
}

void VarStateMachine::ReadConfig(QDomElement &root)
{
     m_Variants.ReadConfig(root);
}

void VarStateMachine::Init()
{
    m_iStateID=VarState_Idle_ID;
    if(!get_VarState(VarState_Idle_ID))
    {m_mMVarState[VarState_Idle_ID]=new VarState_Idle(VarState_Idle_ID,this);}
    if(!get_VarState(VarState_Pause_ID))
    {m_mMVarState[VarState_Pause_ID]=new VarState_Pause(VarState_Pause_ID,this);}
    if(!get_VarState(VarState_Work_ID))
    {m_mMVarState[VarState_Work_ID]=new VarState_Work(VarState_Work_ID,this);}
}

QDataStream &operator<<(QDataStream &out, VarStateMachine &varSM)
{
    out<<varSM.m_Variants;
    return out;
}

QDataStream &operator>>(QDataStream &in, VarStateMachine &varSM)
{

    in>>varSM.m_Variants;
    return in;
}
