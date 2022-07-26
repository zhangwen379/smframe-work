#ifndef VARSM_THREAD_BALL_H
#define VARSM_THREAD_BALL_H
#include "logic.h"
#include "varsm_thread.h"
#include "variant.h"
#include "variants.h"
class VarSM_Thread_Ball : public VarSM_Thread
{
public:
    VarSM_Thread_Ball(int iID, const QString &sName);
protected:
    void Init();

};

#endif // VARSM_THREAD_BALL_H
