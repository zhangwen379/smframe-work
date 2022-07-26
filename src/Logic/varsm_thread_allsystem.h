#ifndef VARSM_THREAD_ALLSYSTEM_H
#define VARSM_THREAD_ALLSYSTEM_H

#include "varsm_thread.h"
#include <QMap>
typedef QMap<int,VarSM_Thread*> MVarSM_Thread;
class VarSM_Thread_AllSystem : public VarSM_Thread
{
public:
    VarSM_Thread_AllSystem();
    VarSM_Thread_AllSystem(int iID,const QString& sName);
    ~VarSM_Thread_AllSystem();
    MVarSM_Thread m_mVarSM_Thread;
    VarSM_Thread *get_VarSM_Thread(int iID);
    void add_VarSM_Thread(int iID,VarSM_Thread* pSM);
    VarMsg run();

    void WriteConfig();
    void ReadConfig();

    void WriteFile();
    void ReadFile();

    QString m_FileName;

    void pushBack_Msg(int iID,const VarMsg &msg);
    void pushFront_Msg(int iID,const VarMsg &msg);
public:
    void Init();
};
extern VarSM_Thread_AllSystem m_gAllSystem;

#endif // VARSM_THREAD_ALLSYSTEM_H
