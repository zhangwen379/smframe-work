#ifndef VARIANT_H
#define VARIANT_H

#include "state.h"
#include <QVariant>
#include <QDomDocument>
#include <QDataStream>
#define Make_IDNAME(id) (#id)
class Variant : public State
{
public:
    enum
    {
      TONONE=0,
      TOXML=1,
      TOFILE=2,
      TOBOTH= TOXML|TOFILE,
    };
    Variant();
    Variant(int iID);
    Variant(int iID,const QString& sName);
    Variant(int iID,const QString& sName, const QVariant& vVar,int iSerialStyle);
    bool isVariantValid();
    int m_iSerialStyle;
    int m_iID;
    QString m_sName;
    QVariant m_vVar;
    bool WriteConfig(QDomDocument &doc, QDomElement &root);
    bool ReadConfig(QDomElement &root);
    QDomElement AppandRootDom(QDomDocument &doc, QString& name, QDomElement &root);
    QDomElement AppandValueDom(QDomDocument &doc, QString &name, QString &value, QDomElement &root);
};

QDataStream &operator<<(QDataStream &out,const Variant& var);
QDataStream &operator>>(QDataStream &in, Variant& var);
#endif // VARIANT_H
