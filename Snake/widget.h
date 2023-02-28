#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"config.h"
#include<QPushButton>
#include"gameplay.h"
#include"mypushbutton.h"
#include <QPainter>
#include <QTime>
#include <QTimer>
#include "gameend.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    MyPushButton * m_GameStartBut;//开始按钮指针

    GamePlay * m_GameWindow;//游戏界面指针

    GameEnd * m_GameWinWindow;//游戏胜利

    GameEnd * m_GameOverWindow;//游戏失败

    QTimer * m_An_Timer;

    int an_XU,an_YU,an_XD,an_YD;

    int m_XU,m_YU,m_XD,m_YD;

    double an_Zoom;

    void newAn();

    void paintEvent(QPaintEvent *);

    Widget(QWidget *parent = 0);

    ~Widget();
};

#endif // WIDGET_H
