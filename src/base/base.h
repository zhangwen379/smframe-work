#ifndef BASE_H
#define BASE_H

#include <QFile>
#include <QTextStream>
#ifdef QT_DEBUG
#define MQT_THROW_STR(s) \
    do  \
    {   QString s1;        \
        s1=QObject::trUtf8(" %1.\n\n Debug:\nfile:%2,line:%3,fun:%4").\
        arg(s).arg(__FILE__).arg(__LINE__).arg(__FUNCTION__);\
        QFile file("log.txt");\
        if(file.open(QIODevice::WriteOnly))\
        {QTextStream stream(&file);stream<<s1;}\
        throw((s));\
    }while (0);
#else
#define MQT_THROW_STR(s)  throw(s);
#endif

#define UNUSED(p) do{p;}while(0);
#define DEQUAL0(f) (((f)>-0.0001)&&((f)<0.0001))
#define OUTOFRANGE(d,min,max)	((d)>=(max)||(d)<(min))

enum VarID
{
    reserve_ID=0,
    VarState_Work_ID,
    VarState_Pause_ID,
    VarState_Idle_ID,
    VarMsg_Start_ID,
    VarMsg_Pause_ID,
    VarMsg_Stop_ID,
    max_VarID,
};

#include "vardesctable.h"
#endif // BASE_H

