#include "vsmt_ball.h"
#include "vsw_ball.h"
#include "vsmt_allsystem.h"
VSMT_Ball::VSMT_Ball(int iID, const QString &sName)
    :VSM_Thread(iID,sName)
{
    Init();
}

void VSMT_Ball::Init()
{
    m_Variants.add_Variant(Var_Ball_PosX_ID,QObject::trUtf8("PosX"),QVariant(double(0)),true,Variant::TOBOTH);
    m_Variants.add_Variant(Var_Ball_PosY_ID,QObject::trUtf8("PosY"),QVariant(double(0)),true,Variant::TOBOTH);
    m_Variants.add_Variant(Var_Ball_SpeedX_ID,QObject::trUtf8("SpeedX"),QVariant(double(10)),true,Variant::TOBOTH);
    m_Variants.add_Variant(Var_Ball_SpeedY_ID,QObject::trUtf8("SpeedY"),QVariant(double(10)),true,Variant::TOBOTH);
    m_Variants.add_Variant(Var_Ball_RangeX_ID,QObject::trUtf8("RangeX"),QVariant(double(100)),true,Variant::TOXML);
    m_Variants.add_Variant(Var_Ball_RangeY_ID,QObject::trUtf8("RangeY"),QVariant(double(100)),true,Variant::TOXML);
    m_Variants.add_Variant(Var_Ball_Radius_ID,QObject::trUtf8("Radius"),QVariant(double(5)),true,Variant::TOBOTH);

    m_Variants.add_Variant(Var_Ball_Color_ID,QObject::trUtf8("Color"),QVariant(uint(0)),true,Variant::TOBOTH);
    m_mMVarState[VarState_Work_ID]=new VSW_Ball(VarState_Work_ID,this);

    VSM_Thread::Init();
}

V_Msg VSMT_Ball::run()
{
    V_Msg msg=VSM_Thread::run();
    if(msg.m_iID==VarMsg_Stop_ID)
    {
       m_gAllSystem.ReadConfig();
       m_gAllSystem.m_bNeedFreshGui=true;
    }
    return msg;
}

