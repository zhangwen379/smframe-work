#ifndef VARDESCTABLE_H
#define VARDESCTABLE_H

#include "thing.h"
#include "vardesc.h"
#include <QMap>
#define make_keyname(id)    (#id)
typedef QMap<int,VarDesc> MVARDESC;
class VarDescTable : public Thing
{
public:
    VarDescTable();
    MVARDESC m_mVarDesc;
    VarDesc* get_VarDesc(int iID);
    void add_VarDesc(int iID,const QStringList& slRange=QStringList(),
                            const QString &sUnit=QString(),double dRate=1,int iPrecise=3);
};
extern VarDescTable m_gVarDescMap;
#endif // VARDESCTABLE_H
