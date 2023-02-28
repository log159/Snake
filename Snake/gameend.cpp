#include "gameend.h"

GameEnd::GameEnd(QString str,int end)
{
    this->setWindowTitle(WINDOW_NAME);
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    QImage image(QSize(10,10),QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPixmap tempPixmap = QPixmap::fromImage(image);
    this->setWindowIcon(QIcon(tempPixmap));
     m_Label=new QLabel(this);
     m_Label->setFixedSize(this->width(),this->height());
     m_Label->move(0,0);
     QFont font;
     font.setFamily("楷体");
     font.setPointSize(50);
     m_Label->setFont(font);
     m_Label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
     m_Label->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透效果
     QPalette pe;
     if(end)
     {
         //绿色
         pe.setColor(QPalette::WindowText,Qt::green);
         m_Label->setPalette(pe);
     }
     else
     {
         //红色
         pe.setColor(QPalette::WindowText,Qt::red);
         m_Label->setPalette(pe);
     }

     m_Label->setText(str);
     m_Label->show();

     m_But=new MyPushButton("再来一局",170,80,20);
     m_But->setParent(this);
     m_But->move(this->width()-m_But->width(),this->height()-m_But->height());
     m_But->show();
     connect(m_But,&MyPushButton::clicked,[=](){
         emit newGame();
     });



}
