#include "mypoint.h"


MyPoint::MyPoint(int x, int y)
{
    this->setPoint(x,y);
}

void MyPoint::setPoint(int x, int y)
{
    m_X=x;
    m_Y=y;
}

int MyPoint::getX()
{
    return m_X;
}

int MyPoint::getY()
{
    return m_Y;
}


