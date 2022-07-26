#ifndef VARDESC_H
#define VARDESC_H

#include "object.h"
#include <QVariant>
#include <QString>
#include <QDomDocument>

class VarDesc : public Object
{
public:
    VarDesc();
    VarDesc(int iID);
    VarDesc(int iID,const QStringList& slRange,
            const QString &sUnit,double dRate,int iPrecise);
    int m_iID;
    QStringList m_slRange;
    QString m_sUnit;
    double m_dRate;
    int m_iPrecise;
    void WriteConfig(QDomDocument &doc, QDomElement &root);
    void ReadConfig(QDomElement &root, int iStartNode);
};

#endif // VARDESC_H
