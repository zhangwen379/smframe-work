#include "varstate_work_ball.h"
#include "varsm_thread_ball.h"
#include "object.h"
VarState_Work_Ball::VarState_Work_Ball(int iID, VarStateMachine *pParent)
    :VarState_Work(iID,pParent)
{

}

void VarState_Work_Ball::do_Msg(const VarMsg &msg)
{
    switch (msg.m_iID)
    {
    case VarMsg_Ball_FreshPOS:
    {
        VarSM_Thread_Ball* pSM=(VarSM_Thread_Ball*)m_pParent;

        double dPosX=pSM->m_Variants.get_Variant(Var_Ball_PosX_ID)->m_vVar.toDouble();
        double dPosY=pSM->m_Variants.get_Variant(Var_Ball_PosY_ID)->m_vVar.toDouble();

        double dSpdX=pSM->m_Variants.get_Variant(Var_Ball_SpeedX_ID)->m_vVar.toDouble();
        double dSpdY=pSM->m_Variants.get_Variant(Var_Ball_SpeedY_ID)->m_vVar.toDouble();

        double dRangeX=pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar.toDouble();
        double dRangeY=pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar.toDouble();

        double dRadius=pSM->m_Variants.get_Variant(Var_Ball_Radius_ID)->m_vVar.toDouble();

        dPosX+=dSpdX*m_gdProcessTime;
        dPosY+=dSpdY*m_gdProcessTime;

        pSM->m_Variants.get_Variant(Var_Ball_PosX_ID)->m_vVar=dPosX;
        pSM->m_Variants.get_Variant(Var_Ball_PosY_ID)->m_vVar=dPosY;



        if(dPosX+dRadius>dRangeX)
        {
            dSpdX=-fabs(dSpdX);
        }
        if(dPosY+dRadius>dRangeY)
        {
            dSpdY=-fabs(dSpdY);
        }

        if(dPosX-dRadius<0)
        {
            dSpdX=fabs(dSpdX);
        }
        if(dPosY-dRadius<0)
        {
            dSpdY=fabs(dSpdY);
        }


        pSM->m_Variants.get_Variant(Var_Ball_SpeedX_ID)->m_vVar=dSpdX;
        pSM->m_Variants.get_Variant(Var_Ball_SpeedY_ID)->m_vVar=dSpdY;
        break;

    }
    default:
        break;
    }
    VarState_Work::do_Msg(msg);
}

