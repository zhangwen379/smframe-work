#include "variant.h"
#include "vardesctable.h"

bool Variant::isVariantValid()
{
    QVariant::Type type=m_vVar.type();
    return (type==QVariant::Int||
            type==QVariant::UInt||
            type==QVariant::Double||
            type==QVariant::String);
}
Variant::Variant()
{

}

Variant::Variant(int iID)
{
    m_iID=iID;
    m_iSerialStyle=TONONE;
}

Variant::Variant(int iID, const QString &sName)
{
    m_iID=iID;
    m_sName=sName;
    m_iSerialStyle=TONONE;
}

Variant::Variant(int iID, const QString& sName, const QVariant &vVar, int iSerialStyle)
{
    m_iSerialStyle=iSerialStyle;
    m_iID=iID;
    m_vVar=vVar;
    m_sName=sName;
    Q_ASSERT(isVariantValid());
}

QDomElement Variant::AppandValueDom(QDomDocument &doc,QString& name,QString & value, QDomElement &root)
{
    QDomElement domname;QDomText domvalue;
    domname=doc.createElement(name);
    domvalue = doc.createTextNode(value);
    domname.appendChild(domvalue);
    root.appendChild(domname);
    return domname;
}
bool Variant::WriteConfig(QDomDocument &doc, QDomElement &root)
{
    if(!(m_iSerialStyle&&TOXML)) return false;
    Q_ASSERT(isVariantValid());
    QDomElement elem=AppandRootDom(doc,m_sName,root);
    elem.setAttribute("ID",m_iID);
    AppandValueDom(doc,QObject::trUtf8("Value"),m_vVar.toString(),elem);
    VarDesc* pDesc=m_gVarDescMap.get_VarDesc(m_iID);
    if(pDesc)
    {
        QVariant::Type type1= m_vVar.type();
        if(type1!=QVariant::UInt&&type1!=QVariant::String
                &&!pDesc->m_slRange.size())
        {
            pDesc->m_slRange.push_back("-100000");
            pDesc->m_slRange.push_back("100000");
        }
      pDesc->WriteConfig(doc,elem);
    }
    return true;
}

bool Variant::ReadConfig(QDomElement &elem)
{
    if(!(m_iSerialStyle&&TOXML)) return false;
    int iID=elem.attribute("ID").toInt();
    if(iID!=m_iID)
    {
        QString strErrMsg=QObject::tr("Write Variant value err,need ID=%1,get ID=%2")
                .arg(m_iID).arg(iID);
        MQT_THROW_STR(strErrMsg);
    }
    QDomNodeList List =  elem.childNodes();
    int iSize=List.size();
    if(!iSize)
    {
        QString strErrMsg=QObject::tr("Read Variant  err,ID=%1,too less node,node count=%2")
                .arg(m_iID).arg(iSize);
        MQT_THROW_STR(strErrMsg);
    }
    QString value=List.at(0).firstChild().nodeValue();
    switch(m_vVar.type())
    {
        case QVariant::Int: m_vVar=QVariant(value.toInt());break;
        case QVariant::UInt:m_vVar=QVariant(value.toUInt());break;
        case QVariant::Double:m_vVar=QVariant(value.toDouble());break;
        case QVariant::String:m_vVar=QVariant(value);break;
        default: Q_ASSERT(0);
    }
    VarDesc* pDesc=m_gVarDescMap.get_VarDesc(m_iID);
    if(pDesc)
    {
        pDesc->ReadConfig(elem,1);
    }
    return true;
}

QDomElement Variant::AppandRootDom(QDomDocument &doc,QString& name, QDomElement &root)
{
    QDomElement elem=doc.createElement(name);
    elem.setAttribute("ID",m_iID);
    root.appendChild(elem);
    return elem;
}

QDataStream &operator<<(QDataStream &out, const Variant &var)
{
    if(var.m_iSerialStyle&&Variant::TOFILE)
    {
        out<<var.m_vVar;
    }
    return out;
}

QDataStream &operator>>(QDataStream &in, Variant &var)
{
    if(var.m_iSerialStyle&&Variant::TOFILE)
    {
        in>>var.m_vVar;
    }
    return in;
}
