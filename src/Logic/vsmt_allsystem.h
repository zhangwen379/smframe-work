#ifndef VSMT_ALLSYSTEM_H
#define VSMT_ALLSYSTEM_H

#include "vsm_thread.h"
#include <QMap>
typedef QMap<int,VSM_Thread*> MVarSM_Thread;
class VSMT_AllSystem : public VSM_Thread
{
public:
    VSMT_AllSystem();
    VSMT_AllSystem(int iID,const QString& sName);
    ~VSMT_AllSystem();
    MVarSM_Thread m_mVarSM_Thread;
    VSM_Thread *get_VarSM_Thread(int iID);
    void add_VarSM_Thread(int iID,VSM_Thread* pSM);
    V_Msg run();

    void WriteConfig();
    void ReadConfig();

    void WriteFile();
    void ReadFile();

    QString m_FileName;

    void pushBack_Msg(int iID,const V_Msg &msg);
    void pushFront_Msg(int iID,const V_Msg &msg);
    bool    m_bNeedFreshGui;
public:
    void Init();
};
extern VSMT_AllSystem m_gAllSystem;

#endif // VSMT_ALLSYSTEM_H
