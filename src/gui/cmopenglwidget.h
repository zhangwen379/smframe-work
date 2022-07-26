#ifndef CMOPENGLWIDGET_H
#define CMOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QOpenGLFunctions>
#include "cprecisetime.h"
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

#include <QPixmap>
class CMOPenGLWidget : public QOpenGLWidget , protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit CMOPenGLWidget(QWidget *parent = 0);
    ~CMOPenGLWidget();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    QOpenGLPaintDevice *m_device;


    CPreciseTime time;
    QPixmap m_Pixmap;
    QColor m_BackColor;

    void refreshPixmap();
signals:

public slots:
};

#endif // CMOPENGLWIDGET_H
