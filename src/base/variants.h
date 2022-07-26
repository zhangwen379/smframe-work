﻿#ifndef VARIANTS_H
#define VARIANTS_H


#include "thing.h"
#include <QMap>
#include "variant.h"
typedef QMap<int,Variant> VariantMap;

class Variants : public Thing
{
public:
    Variants();
    VariantMap m_mVariantMap;

    void add_Variant(int iID, const QString& sName, const QVariant& vVar, bool bAddDesc, int iSerialStyle);
    Variant *get_Variant(int iID);
    void set_Variant(int iID,const QVariant& vVar);
public:
    int WriteConfig(QDomDocument &doc, QDomElement &root);
    int ReadConfig(QDomElement &root);
};
QDataStream &operator<<(QDataStream &out,Variants& vars);
QDataStream &operator>>(QDataStream &in, Variants& vars);

#endif // VARIANTS_H
