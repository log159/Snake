#ifndef FOOD_H
#define FOOD_H

#include"mypoint.h"
#include<QList>
#include"config.h"
#include<ctime>
#include<iostream>
class Food
{
public:
    MyPoint m_Point;

    bool arr[GAME_HEIGHT][GAME_WIDTH];

    MyPoint m_PointArr[GAME_WIDTH*GAME_HEIGHT+10];

    int m_EffPointSum=0;

    bool m_NoFood;

    void giveFood(QList<MyPoint>&v);

    Food();
};

#endif // FOOD_H
