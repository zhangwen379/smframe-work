#ifndef OBJECT_H
#define OBJECT_H
#include "base.h"
extern double m_gdProcessTime;
class Object
{
public:
    Object();
    virtual ~Object();
    //ID用于向人类输出识别
    int m_iID;
    // XYZ向坐标与速度
    double m_dspeedX;
    double m_dposX;

    double m_dspeedY;
    double m_dposY;

    double m_dspeedZ;
    double m_dposZ;
    // 物体质量
    double m_dmass;
    // 通过万有引力公式和牛顿第三定律加速度公式以及矢量分解公式计算单位时间内物质移动特性。
    //引力的相互作用

    void drew(Object* pobject);
};

#endif // OBJECT_H
