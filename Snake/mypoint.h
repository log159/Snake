#ifndef MYPOINT_H
#define MYPOINT_H


class MyPoint
{
public:
    MyPoint(int x=0,int y=0);
    void setPoint(int x,int y);
    int getX();
    int getY();
    void operator=(const MyPoint & point)
    {
        this->m_X=point.m_X;
        this->m_Y=point.m_Y;
    }
    bool operator==(const MyPoint & point)
    {
        return (this->m_X==point.m_X&&this->m_Y==point.m_Y);
    }

private:
    int m_X;
    int m_Y;


};

#endif // MYPOINT_H
