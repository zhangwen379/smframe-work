#ifndef VARSTATE_H
#define VARSTATE_H

#include "variant.h"
#include "varmsgqueue.h"
#include <QMutex>
class VarStateMachine;
class VarState : public Variant
{
public:
    VarState(int iID,VarStateMachine* pParent);
    VarMsgQueue m_VarMsgQueue;
    VarStateMachine* m_pParent;
public:
    QMutex mutex;
    void pushback_Msg(const VarMsg& msg);
    void pushfront_Msg(const VarMsg& msg);
    VarMsg popfront_Msg();
    void clear_Msg();
public:
    virtual void do_Msg(const VarMsg& msg);

};

#endif // VARSTATE_H
