#ifndef V_MSGQUEUE_H
#define V_MSGQUEUE_H

#include "variant.h"
#include "v_msg.h"
#include <QList>
typedef QList<V_Msg> LVMSG;
class V_MsgQueue : public Variant
{
public:
    V_MsgQueue();
    LVMSG m_lVarMsg;
public:

};

#endif // V_MSGQUEUE_H
