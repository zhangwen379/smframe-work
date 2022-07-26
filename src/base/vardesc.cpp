#include "vardesc.h"
#include <QDomElement>
#include "base.h"

VarDesc::VarDesc()
{

}

VarDesc::VarDesc(int iID)
{
    m_iID=iID;
}

VarDesc::VarDesc(int iID,
                 const QStringList& slRange,
                 const QString &sUnit,
                 double dRate,
                 int iPrecise)
{
      m_iID=iID;
      m_slRange=slRange;
      m_sUnit=sUnit;
      m_dRate=dRate;
      m_iPrecise=iPrecise;
}
static void WriteDom(QDomDocument &doc,QString sElement,QString  sText,QDomElement &root)
{
    QDomElement elem;QDomText text;
    elem=doc.createElement(sElement);
    text = doc.createTextNode(sText);
    elem.appendChild(text);
    root.appendChild(elem);
}
void VarDesc::WriteConfig(QDomDocument &doc, QDomElement &root)
{
    int iID=root.attribute("ID").toInt();
    if(iID!=m_iID)
    {
        QString strErrMsg=QObject::tr("Write Variant desc err,need ID=%1,get ID=%2")
                .arg(m_iID).arg(iID);
        MQT_THROW_STR(strErrMsg);
    }
    int iRangeSize=m_slRange.size();
    WriteDom(doc,QObject::tr("RangeNum"),QString::number(iRangeSize),root);
    for(int i=0;i<iRangeSize;i++)
    {
        QString sName=QObject::tr("Range%1").arg(i);
        WriteDom(doc,sName,m_slRange[i],root);
    }
    WriteDom(doc,QObject::tr("Unit"),m_sUnit,root);
    WriteDom(doc,QObject::tr("Rate"),QString::number(m_dRate,'g',3),root);
    WriteDom(doc,QObject::tr("Precise"),QString::number(m_iPrecise),root);
}



void VarDesc::ReadConfig(QDomElement &root,int iStartNode)
{
    int iID=root.attribute("ID").toInt();
    if(iID!=m_iID)
    {
        QString strErrMsg=QObject::tr("Read Variant desc err,need ID=%1,get ID=%2")
                .arg(m_iID).arg(iID);
        MQT_THROW_STR(strErrMsg);
    }
    QDomNodeList List =  root.childNodes();
    int iSize=List.size();
    if(iSize<4+iStartNode)
    {
        QString strErrMsg=QObject::tr("Read Variant desc err,ID=%1,too less desc=%2")
                .arg(m_iID).arg(iSize);
        MQT_THROW_STR(strErrMsg);
    }
    int iRangeSize = List.at(iStartNode).firstChild().nodeValue().toInt();
    if(iSize<4+iRangeSize+iStartNode)
    {
        QString strErrMsg=QObject::tr("Read Variant desc err,ID=%1,too less desc=%2")
                .arg(m_iID).arg(iSize);
        MQT_THROW_STR(strErrMsg);
    }
    m_slRange.clear();
    for(int i=0;i<iRangeSize;i++)
    {
        m_slRange.push_back(List.at(1+i+iStartNode).firstChild().nodeValue());
    }
    m_sUnit=List.at(1+iRangeSize+iStartNode).firstChild().nodeValue();
    m_dRate=List.at(2+iRangeSize+iStartNode).firstChild().nodeValue().toDouble();
    m_iPrecise=List.at(3+iRangeSize+iStartNode).firstChild().nodeValue().toInt();
}

