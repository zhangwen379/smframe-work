#include "cprecisetime.h"

CPreciseTime::CPreciseTime()
{
    QueryPerformanceFrequency(&tc);
    t1.QuadPart=t2.QuadPart=0;
    m_bstart=false;
    m_lastTime=0;
}

CPreciseTime::~CPreciseTime()
{

}

double CPreciseTime::GetTime()
{
    if (!tc.QuadPart)
    {
        return 0;
    }
    if (m_bstart)
    {
        QueryPerformanceCounter(&t2);
    }
    return double(t2.QuadPart-t1.QuadPart)/tc.QuadPart;
}

void CPreciseTime::StartTime()
{
    if(!m_bstart)
    {
        QueryPerformanceCounter(&t2);
        t1.QuadPart=t2.QuadPart;
    }
    m_bstart=true;
}

void CPreciseTime::StopTime()
{
    QueryPerformanceCounter(&t2);
    m_bstart=false;
    m_lastTime=GetTime();
}

QString CPreciseTime::FormatTime()
{
	QString str;
	int TM=(int)GetTime();
	if(TM>3600)
	{
	str=QString::fromUtf8("%1:%2:%3").arg(TM/3600).arg((TM%3600)/60).arg(TM%60);
	}
	else
	{
	str=QString::fromUtf8("00:%1:%2").arg(TM/60).arg(TM%60);
	}
    return str;
}

