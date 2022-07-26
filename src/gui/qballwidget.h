#ifndef QBALLWIDGET_H
#define QBALLWIDGET_H

#include <QWidget>
#include <QPixmap>
class QBallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBallWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *pEvent);
public:

    QPixmap m_Pixmap;
    void refreshPixmap();
    QColor m_BackColor;
signals:

public slots:
};

#endif // QBALLWIDGET_H
