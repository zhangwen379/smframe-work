#ifndef CPRECISETIME_H
#define CPRECISETIME_H

#include <windows.h>
#include <time.h>
#include <QString>
class CPreciseTime
{
public:
    CPreciseTime();
    virtual ~CPreciseTime();
    LARGE_INTEGER t1,t2,tc;
    bool m_bstart;
    double GetTime();	//second
    void StartTime();
    void StopTime();
    QString FormatTime();
    double m_lastTime;
};

#endif // CPRECISETIME_H
