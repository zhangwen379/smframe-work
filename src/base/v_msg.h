#ifndef V_MSG_H
#define V_MSG_H

#include "variant.h"
class V_Msg : public Variant
{
public:
    V_Msg(int iID);
    void* m_pInput;
    void** m_ppOutput;
private:
    void Init();
};

#endif // V_MSG_H
