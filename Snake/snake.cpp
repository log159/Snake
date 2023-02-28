#include "snake.h"

Snake::Snake()
{
    this->m_Head.setPoint(3,0);
    m_Head.setPoint(2,0);
    m_Body.push_back(MyPoint(0,0));
    m_Body.push_back(MyPoint(1,0));
    m_Body.push_back(MyPoint(2,0));
    m_Direction='d';//初始方向向右
}

void Snake::nextSnake()
{
    int tempX,tempY;
    tempX=m_Head.getX();
    tempY=m_Head.getY();
    if(m_Direction=='w'){--tempY;}
    else if(m_Direction=='a'){--tempX;}
    else if(m_Direction=='s'){++tempY;}
    else if(m_Direction=='d'){++tempX;}

    if(tempX<0||tempY<0||tempX>=GAME_WIDTH||tempY==GAME_HEIGHT)
    {
        m_CantCon=true;
        return;
    }
    for(QList<MyPoint>::iterator val = m_Body.begin()+1;val!=m_Body.end()-1;++val)
    {
        if(val->getX()==tempX&&val->getY()==tempY)
        {
            m_CantCon=true;
            return;
        }
    }
    MyPoint nextHead(tempX,tempY);
    m_Body.push_back(nextHead);
    m_Head=nextHead;

}

void Snake::eraseTail()
{
    m_Body.erase(m_Body.begin());
}
