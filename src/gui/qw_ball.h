#ifndef QW_BALL_H
#define QW_BALL_H

#include <QWidget>
#include <QPixmap>
class QW_Ball : public QWidget
{
    Q_OBJECT
public:
    explicit QW_Ball(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *pEvent);
public:
    QPixmap m_Pixmap;
    void refreshPixmap();
    QColor m_BackColor;
signals:

public slots:
};

#endif // QW_BALL_H
