#include "varsm_thread_ball.h"
#include "varstate_work_ball.h"
VarSM_Thread_Ball::VarSM_Thread_Ball(int iID, const QString &sName)
    :VarSM_Thread(iID,sName)
{
    Init();
}

void VarSM_Thread_Ball::Init()
{
    m_Variants.add_Variant(Var_Ball_PosX_ID,QObject::trUtf8("PosX"),QVariant(double(0)),true,true);
    m_Variants.add_Variant(Var_Ball_PosY_ID,QObject::trUtf8("PosY"),QVariant(double(0)),true,true);
    m_Variants.add_Variant(Var_Ball_SpeedX_ID,QObject::trUtf8("SpeedX"),QVariant(double(10)),true,true);
    m_Variants.add_Variant(Var_Ball_SpeedY_ID,QObject::trUtf8("SpeedY"),QVariant(double(10)),true,true);
    m_Variants.add_Variant(Var_Ball_RangeX_ID,QObject::trUtf8("RangeX"),QVariant(double(100)),true,false);
    m_Variants.add_Variant(Var_Ball_RangeY_ID,QObject::trUtf8("RangeY"),QVariant(double(100)),true,false);
    m_Variants.add_Variant(Var_Ball_Radius_ID,QObject::trUtf8("Radius"),QVariant(double(5)),true,true);

    m_mMVarState[VarState_Work_ID]=new VarState_Work_Ball(VarState_Work_ID,this);

    VarSM_Thread::Init();
}

