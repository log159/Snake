#ifndef SNAKE_H
#define SNAKE_H
#include"mypoint.h"
#include"config.h"
#include <QList>
#include<QObject>
#include<QDebug>
class Snake
{
public:
    MyPoint m_Head;//头坐标

    QList<MyPoint>m_Body;//所有坐标

    char m_Direction;//方向 w s a d

    void nextSnake();

    void eraseTail();

    bool m_CantCon=false;

    Snake();



};

#endif // SNAKE_H
