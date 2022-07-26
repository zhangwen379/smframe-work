#ifndef VARSTATEMACHINE_H
#define VARSTATEMACHINE_H

#include "variant.h"
#include "variants.h"
#include "varstate.h"
#include <QMap>
typedef QMap<int, VarState*> MVarState;
class VarStateMachine : public Variant
{
public:
    VarStateMachine();
    VarStateMachine(int iID,const QString& sName);
    virtual ~VarStateMachine();

    Variants m_Variants;

    MVarState m_mMVarState;
    VarState *get_VarState(int iStateID);
    int m_iStateID;
    virtual VarMsg run();

    void WriteConfig(QDomDocument &doc, QDomElement &root);
    void ReadConfig(QDomElement &root);
protected:
    virtual void Init();
};
QDataStream &operator<<(QDataStream &out,VarStateMachine& varSM);
QDataStream &operator>>(QDataStream &in, VarStateMachine& varSM);

#endif // VARSTATEMACHINE_H
