#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(WINDOW_NAME);
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    QImage image(QSize(10,10),QImage::Format_ARGB32);
    image.fill(Qt::transparent);
     QPixmap tempPixmap = QPixmap::fromImage(image);
    this->setWindowIcon(QIcon(tempPixmap));

    m_An_Timer=new QTimer(this);
    connect(m_An_Timer,&QTimer::timeout,[=](){
        this->newAn();
    });
    m_GameStartBut=new MyPushButton("游戏开始",200,200*0.618-30,30);
    m_GameStartBut->setParent(this);
    m_GameStartBut->move((WINDOW_WIDTH-m_GameStartBut->width())*0.5,WINDOW_HEIGHT*0.5);
    m_GameStartBut->show();

    m_GameWinWindow=new GameEnd("GAME WIN",1);
    m_GameWinWindow->hide();
    m_GameOverWindow=new GameEnd("GAME OVER",0);
    m_GameOverWindow->hide();


    connect(m_GameStartBut,&MyPushButton::clicked,[=](){
        m_GameWindow=new GamePlay();//游戏场景

        m_GameStartBut->hide();
        m_GameWindow->move(this->x(),this->y());
        //执行动画效果 执行完后前往下一个场景
        m_An_Timer->start(3);
        QTimer::singleShot(300,this,[=](){
            this->hide();
            m_GameWindow->show();
        });

        connect(m_GameWindow,&GamePlay::gameWin,[=](){
            m_GameWindow->hide();
            m_GameWinWindow->move(m_GameWindow->x(),m_GameWindow->y());
            m_GameWinWindow->show();
            delete m_GameWindow;
            m_GameWindow=nullptr;
        });
        connect(m_GameWindow,&GamePlay::gameOver,[=](){
            m_GameWindow->hide();
            m_GameOverWindow->move(m_GameWindow->x(),m_GameWindow->y());
            m_GameOverWindow->show();
            delete m_GameWindow;
            m_GameWindow=nullptr;
        });
    });

    GameEnd*GE;
    for(int i=0;i<2;++i)
    {
        GE=(i==0?m_GameWinWindow:m_GameOverWindow);
        connect(GE,&GameEnd::newGame,[=](){
            m_GameWindow=new GamePlay();//游戏场景
            GE->hide();
            m_GameWindow->move(GE->x(),GE->y());
            m_GameWindow->show();
            connect(m_GameWindow,&GamePlay::gameWin,[=](){
                m_GameWindow->hide();
                m_GameWinWindow->move(m_GameWindow->x(),m_GameWindow->y());
                m_GameWinWindow->show();
                delete m_GameWindow;
                m_GameWindow=nullptr;
            });
            connect(m_GameWindow,&GamePlay::gameOver,[=](){
                m_GameWindow->hide();
                m_GameOverWindow->move(m_GameWindow->x(),m_GameWindow->y());
                m_GameOverWindow->show();
                delete m_GameWindow;
                m_GameWindow=nullptr;
            });
        });
    }

    an_XU=m_GameStartBut->x();
    an_YU=m_GameStartBut->y();
    an_XD=m_GameStartBut->x();
    an_YD=m_GameStartBut->y()+m_GameStartBut->height();
    an_Zoom=-0.1f;
    m_XU=WINDOW_WIDTH*(1.f-an_Zoom)+an_XU*an_Zoom;
    m_YU=WINDOW_HEIGHT*(1.f-an_Zoom)+an_YU*an_Zoom;
    m_XD=WINDOW_WIDTH*(1.f-an_Zoom)+an_XD*an_Zoom;
    m_YD=an_YD*an_Zoom;


}
void Widget::newAn()
{
    static bool needInit=true;
    if(needInit){an_Zoom=1.f;needInit=false;}

    m_XU=WINDOW_WIDTH*(1.f-an_Zoom)+an_XU*an_Zoom;
    m_YU=WINDOW_HEIGHT*(1.f-an_Zoom)+an_YU*an_Zoom;
    m_XD=WINDOW_WIDTH*(1.f-an_Zoom)+an_XD*an_Zoom;
    m_YD=an_YD*an_Zoom;
    an_Zoom-=0.01;

    if(an_Zoom<=-0.1f){
        m_An_Timer->stop();
        needInit=true;
    }
    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawText(WINDOW_WIDTH-100,WINDOW_HEIGHT-20,QString(VERSION));
    painter.drawLine(m_XU,m_YU,m_XD,m_YD);
    painter.drawLine(WINDOW_WIDTH-m_XU,m_YU,WINDOW_WIDTH-m_XD,m_YD);
    painter.drawLine(m_XU,m_YU,WINDOW_WIDTH-m_XU,m_YU);
    painter.drawLine(m_XD,m_YD,WINDOW_WIDTH-m_XD,m_YD);



}
Widget::~Widget()
{

}
