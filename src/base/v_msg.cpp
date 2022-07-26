#include "v_msg.h"
#include "vardesctable.h"

V_Msg::V_Msg(int iID)
    :Variant(iID)
{
    Init();
}

void V_Msg::Init()
{
    m_pInput=0;
    m_ppOutput=0;
}

