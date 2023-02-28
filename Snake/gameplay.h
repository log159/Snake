#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include "config.h"
#include "mypushbutton.h"
#include <QPainter>
#include <snake.h>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <mypoint.h>
#include <QDebug>
#include <QString>
#include"food.h"
class GamePlay : public QWidget
{
    Q_OBJECT
public:
    MyPushButton *m_BackWidget;

    Snake m_Snake;

    Food m_Food;

    bool eatFood=false;

    QTimer * gameTimer;

    void gameRun();

    void isEat();

    void keyPressEvent(QKeyEvent *event);//键盘事件按下

    void paintEvent(QPaintEvent *);//绘图


    explicit GamePlay(QWidget *parent = nullptr);
signals:

    void gameWin();

    void gameOver();

public slots:
};

#endif // GAMEPLAY_H
