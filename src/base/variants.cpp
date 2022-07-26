﻿#include "variants.h"
#include "vardesctable.h"
Variants::Variants()
{

}

void Variants::add_Variant(int iID, const QString &sName,
                           const QVariant &vVar,bool bAddDesc,bool bNeedSerial )
{
    m_mVariantMap[iID]=Variant(iID, sName, vVar,bNeedSerial);
    if(bAddDesc)
    {
        m_gVarDescMap.add_VarDesc(iID);
    }
}

Variant *Variants::get_Variant(int iID)
{
    VariantMap::iterator ii=m_mVariantMap.find(iID);
    if(ii!=m_mVariantMap.end())
    {
        return &(*ii);
    }
    Q_ASSERT(0);
    return 0;
}

void Variants::set_Variant(int iID, const QVariant &vVar)
{
    VariantMap::iterator ii=m_mVariantMap.find(iID);
    if(ii!=m_mVariantMap.end())
    {
        if(ii->m_vVar!=vVar)
        {
            ii->m_vVar=vVar;
            //数据库写入
        }
    }
    else
    {
        Q_ASSERT(0);
    }
}

void Variants::WriteConfig(QDomDocument &doc, QDomElement &root)
{
    VariantMap::iterator ii=m_mVariantMap.begin( );
    for(;ii!=m_mVariantMap.end();ii++)
    {
         ii->WriteConfig(doc,root);
    }
}

void Variants::ReadConfig(QDomElement &root)
{
    VariantMap::iterator ii=m_mVariantMap.begin( );
    QDomNodeList List= root.childNodes();
    int iIndex=0;
    for(;ii!=m_mVariantMap.end();ii++)
    {
         ii->ReadConfig(List.at(iIndex).toElement());
         iIndex++;
    }
}

QDataStream &operator<<(QDataStream &out, Variants &vars)
{
    VariantMap::iterator ii=vars.m_mVariantMap.begin( );
    for(;ii!=vars.m_mVariantMap.end();ii++)
    {
         out<<(*ii);
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, Variants &vars)
{
    VariantMap::iterator ii=vars.m_mVariantMap.begin( );
    for(;ii!=vars.m_mVariantMap.end();ii++)
    {
         in>>(*ii);
    }
    return in;
}
