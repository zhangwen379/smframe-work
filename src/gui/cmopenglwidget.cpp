#include "cmopenglwidget.h"

#include <QPainter>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QColor>
#include "qw_ball.h"
#include "vsmt_allsystem.h"
#include <QPainter>
#include <QStylePainter>
#include "vsmt_ball.h"
#include <QResizeEvent>
#include <QPainterPath>
CMOPenGLWidget::CMOPenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
, m_device(0)
{

}

CMOPenGLWidget::~CMOPenGLWidget()
{
    delete m_device;
}

void CMOPenGLWidget::initializeGL()
{
    //makeCurrent();
    initializeOpenGLFunctions();

    glClearColor(0.75, 0.75, 0.75, 1);


    if (!m_device)
        m_device = new QOpenGLPaintDevice;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_device->setSize(size());
}

void CMOPenGLWidget::resizeGL(int w, int h)
{
    QSize size=QSize(w,h);
    VSMT_Ball* pSM=(VSMT_Ball*)m_gAllSystem.get_VarSM_Thread(VSMT_Ball_ID);
    pSM->m_Variants.get_Variant(Var_Ball_RangeX_ID)->m_vVar=double(size.width());
    pSM->m_Variants.get_Variant(Var_Ball_RangeY_ID)->m_vVar=double(size.height());


}

void CMOPenGLWidget::paintGL()
{

    time.StartTime();
    QPainter painter(this);//m_device
    painter.drawPixmap(0,0,m_Pixmap);

    time.StopTime();
    painter.drawText(rect(),Qt::AlignBottom,QString::number(1.0/time.GetTime(),'f',3));

}


void CMOPenGLWidget::refreshPixmap()
{
    makeCurrent();
    QSize size1=size();
    m_Pixmap=QPixmap(size1);
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
