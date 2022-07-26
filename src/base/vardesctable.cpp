#include "vardesctable.h"
VarDescTable m_gVarDescMap;
VarDescTable::VarDescTable()
{
}
void VarDescTable::add_VarDesc(int iID, const QStringList &slRange,
                               const QString &sUnit, double dRate, int iPrecise)
{
    m_mVarDesc[iID]=VarDesc(iID,slRange,sUnit,dRate,iPrecise);
}
VarDesc* VarDescTable::get_VarDesc(int iID)
{
    MVARDESC::iterator ii= m_mVarDesc.find(iID);
    if(ii!=m_mVarDesc.end())
    {
        return &(*ii);
    }
    return 0;
}

