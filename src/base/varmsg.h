#ifndef VARMSG_H
#define VARMSG_H

#include "variant.h"
class VarMsg : public Variant
{
public:
    VarMsg(int iID);
    void* m_pInput;
    void** m_ppOutput;
private:
    void Init();
};

#endif // VARMSG_H
