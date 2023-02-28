#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>
#include"mypoint.h"
#include"config.h"
#include<QPropertyAnimation>
#include<QEvent>
#include<QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    int m_InitWidth;
    int m_InitHeight;
    MyPushButton(QString str,int w,int h,int s);

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void zoom();

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
