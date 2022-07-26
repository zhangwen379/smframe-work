#include "varmsg.h"
#include "vardesctable.h"

VarMsg::VarMsg(int iID)
    :Variant(iID)
{
    Init();
}

void VarMsg::Init()
{
    m_pInput=0;
    m_ppOutput=0;
}

