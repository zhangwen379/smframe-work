#include "qw_ball.h"
#include "vsmt_allsystem.h"
#include <QPainter>
#include <QStylePainter>
#include "vsmt_ball.h"
#include <QResizeEvent>
#include <QPainterPath>
QW_Ball::QW_Ball(QWidget *parent) : QWidget(parent)
{
    m_BackColor=QColor(200,200,200);
}

void QW_Ball::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    painter.drawPixmap(0,0,m_Pixmap);
}

void QW_Ball::resizeEvent(QResizeEvent * pEvent)
{
    QSize size=pEvent->size();
    VSMT_Ball* pSM=(VSMT_Ball*)m_gAllSystem.get_VarSM_Thread(VSMT_Ball_ID);
    pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar=double(size.width());
    pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar=double(size.height());

}

void QW_Ball::refreshPixmap()
{
    QSize size1=size();
    m_Pixmap=QPixmap(size1);
  //  m_Pixmap.fill(m_BackColor);
    QPainter painter(&m_Pixmap);
    painter.initFrom(this);
    VSMT_Ball* pSM=(VSMT_Ball*)m_gAllSystem.get_VarSM_Thread(VSMT_Ball_ID);
    double dPosX= pSM->m_Variants.get_Variant(Var_Ball_PosX_ID)->m_vVar.toDouble();
    double dPosY= pSM->m_Variants.get_Variant(Var_Ball_PosY_ID)->m_vVar.toDouble();
    pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar=double(size1.width());
    pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar=double(size1.height());
    double dRadius= pSM->m_Variants.get_Variant(Var_Ball_Radius_ID)->m_vVar.toDouble();
    uint uiColor=pSM->m_Variants.get_Variant(Var_Ball_Color_ID)->m_vVar.toUInt();
    QPainterPath path;path.addEllipse(QPointF(dPosX,dPosY),dRadius,dRadius);
    QColor color=Qt::red;
    switch(uiColor)
    {
    case 0: color=Qt::red;break;
    case 1: color=Qt::green;break;
    case 2: color=Qt::blue;break;
    default:break;
    }
    painter.fillPath(path,color);


    update();
}

