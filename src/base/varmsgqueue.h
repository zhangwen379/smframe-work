#ifndef VARMSGQUEUE_H
#define VARMSGQUEUE_H

#include "variant.h"
#include "varmsg.h"
#include <QList>
typedef QList<VarMsg> LVARMSG;
class VarMsgQueue : public Thing
{
public:
    VarMsgQueue();
    LVARMSG m_lVarMsg;
public:

};

#endif // VARMSGQUEUE_H
