#include "qballwidget.h"
#include "varsm_thread_allsystem.h"
#include <QPainter>
#include <QStylePainter>
#include "varsm_thread_ball.h"
#include <QResizeEvent>
QBallWidget::QBallWidget(QWidget *parent) : QWidget(parent)
{
    m_BackColor=QColor(200,200,200);
}

void QBallWidget::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    painter.drawPixmap(0,0,m_Pixmap);
}

void QBallWidget::resizeEvent(QResizeEvent * pEvent)
{
    QSize size=pEvent->size();
    VarSM_Thread_Ball* pSM=(VarSM_Thread_Ball*)m_gAllSystem.get_VarSM_Thread(VarSM_Ball_ID);
    pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar=double(size.width());
    pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar=double(size.height());

}

void QBallWidget::refreshPixmap()
{
    QSize size1=size();
    m_Pixmap=QPixmap(size1);
  //  m_Pixmap.fill(m_BackColor);

    QPainter painter(&m_Pixmap);
    painter.initFrom(this);
    VarSM_Thread_Ball* pSM=(VarSM_Thread_Ball*)m_gAllSystem.get_VarSM_Thread(VarSM_Ball_ID);
    double dPosX= pSM->m_Variants.get_Variant(Var_Ball_PosX_ID)->m_vVar.toDouble();
    double dPosY= pSM->m_Variants.get_Variant(Var_Ball_PosY_ID)->m_vVar.toDouble();
    pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar=double(size1.width());
    pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar=double(size1.height());
    double dRadius= pSM->m_Variants.get_Variant(Var_Ball_Radius_ID)->m_vVar.toDouble();
    painter.drawEllipse(QPointF(dPosX,dPosY),dRadius,dRadius);


    update();
}

