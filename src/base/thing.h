#ifndef THING_H
#define THING_H

#include "object.h"
extern double m_gdTouchDisThres;
class Thing : public Object
{
public:
    Thing();
    // 物体组成
    Object* m_pOjects;
    //作用力的相互作用，作为引力作用的延申
    void doing(Thing* pThing);
};

#endif // THING_H
