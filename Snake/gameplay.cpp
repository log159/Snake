#include "gameplay.h"

GamePlay::GamePlay(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(WINDOW_NAME);
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    QImage image(QSize(10,10),QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPixmap tempPixmap = QPixmap::fromImage(image);
    this->setWindowIcon(QIcon(tempPixmap));

    gameTimer=new QTimer(this);
    gameTimer->start(100);
    QTimer::singleShot(500,this,[=](){

        connect(gameTimer,QTimer::timeout,[=](){
            gameRun();
        });
    });

    setFocusPolicy(Qt::NoFocus);


}

void GamePlay::gameRun()
{

    m_Snake.nextSnake();

    isEat();

    if(!this->eatFood)
    {
        m_Snake.eraseTail();
    }
    this->eatFood=false;

    update();

    if(m_Snake.m_CantCon)
    {
        emit gameOver();
    }
    if(m_Food.m_NoFood)
    {
        emit gameWin();
    }
}

void GamePlay::isEat()
{
    if(m_Snake.m_Head==m_Food.m_Point)
    {
        this->eatFood=true;
        m_Food.giveFood(m_Snake.m_Body);
    }
}

void GamePlay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;pen.setStyle(Qt::NoPen);
    QBrush brush;brush.setColor(QColor(0,255,0,120));brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);painter.setBrush(brush);
    for(auto it=m_Snake.m_Body.begin();it!=m_Snake.m_Body.end();++it)
    {
        painter.drawRect(it->getX()*GAME_STEP,it->getY()*GAME_STEP,GAME_STEP,GAME_STEP);
    }
    brush.setColor(QColor(255,0,0,120));
    painter.setBrush(brush);
    if(m_Food.m_NoFood==false)
    {
        painter.drawRect(m_Food.m_Point.getX()*GAME_STEP,m_Food.m_Point.getY()*GAME_STEP,GAME_STEP,GAME_STEP);
    }
    painter.setPen(QPen(QColor(79,79,79,80)));
    //竖线
    for(int i=0;i<=GAME_WIDTH;++i)
    {
        painter.drawLine(i*GAME_STEP,0,i*GAME_STEP,GAME_HEIGHT*GAME_STEP);
    }
    //横线
    for(int i=0;i<=GAME_HEIGHT;++i)
    {
        painter.drawLine(0,i*GAME_STEP,GAME_WIDTH*GAME_STEP,i*GAME_STEP);
    }
}
void GamePlay::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:if(m_Snake.m_Direction=='s'){return;}m_Snake.m_Direction='w';
    case Qt::Key_W:if(m_Snake.m_Direction=='s'){return;}m_Snake.m_Direction='w';break;

    case Qt::Key_Left:if(m_Snake.m_Direction=='d'){return;}m_Snake.m_Direction='a';
    case Qt::Key_A:if(m_Snake.m_Direction=='d'){return;}m_Snake.m_Direction='a';break;

    case Qt::Key_Down:if(m_Snake.m_Direction=='w'){return;}m_Snake.m_Direction='s';
    case Qt::Key_S:if(m_Snake.m_Direction=='w'){return;}m_Snake.m_Direction='s';break;

    case Qt::Key_Right:if(m_Snake.m_Direction=='a'){return;}m_Snake.m_Direction='d';
    case Qt::Key_D:if(m_Snake.m_Direction=='a'){return;}m_Snake.m_Direction='d';break;
    default:break;
    }

}


