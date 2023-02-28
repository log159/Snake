#include "food.h"

Food::Food()
{
    memset(arr,0,sizeof(arr));
    srand((unsigned)time(NULL));
    int tempW=rand()%(GAME_WIDTH-3)+3;
    int tempH=rand()%(GAME_HEIGHT-3)+3;
    m_Point.setPoint(tempW,tempH);
    m_NoFood=false;

}
void Food::giveFood(QList<MyPoint> &v)
{
    memset(arr,0,sizeof(arr));
    for(auto it=v.begin();it!=v.end();++it)
    {
        arr[it->getY()][it->getX()]=1;
    }
    MyPoint p;
    for(int i=0;i<GAME_HEIGHT;++i)
    {
        for(int j=0;j<GAME_WIDTH;++j)
        {
            if(arr[i][j]==0)
            {
                p.setPoint(j,i);
                m_PointArr[this->m_EffPointSum]=p;
                ++m_EffPointSum;
            }
        }
    }
    if(m_EffPointSum==0){m_NoFood=true;return;}
    p=m_PointArr[rand()%m_EffPointSum];
    MyPoint initP;
    for(auto&val:m_PointArr){val=initP;}
    m_EffPointSum=0;
    this->m_Point=p;
}
