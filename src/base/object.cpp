#include "object.h"
double m_gdProcessTime=0.01;
Object::Object()
{

    m_dspeedX=0;
    m_dposX=0;

    m_dspeedY=0;
    m_dposY=0;

    m_dspeedZ=0;
    m_dposZ=0;

    m_dmass=0;
}

Object::~Object()
{

}

void Object::drew(Object *pobject)
{
    pobject;
}
