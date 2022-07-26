#ifndef VSMT_BALL_H
#define VSMT_BALL_H
#include "logic.h"
#include "vsm_thread.h"
#include "variant.h"
#include "variants.h"
class VSMT_Ball : public VSM_Thread
{
public:
    VSMT_Ball(int iID, const QString &sName);
protected:
    void Init();
    V_Msg run();
};

#endif // VSMT_BALL_H
