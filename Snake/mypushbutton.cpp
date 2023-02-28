#include "mypushbutton.h"

MyPushButton::MyPushButton(QString str,int w,int h,int s)
{
    this->setText(str);
    this->setFont(QFont("宋体", s));
    this->m_InitWidth=w;
    this->m_InitHeight=h;
    this->setFixedSize(m_InitWidth,m_InitHeight);
    //设置不规则样式
    this->setFlat(true);

}

void MyPushButton::enterEvent(QEvent *)
{
    this->setStyleSheet("color: blue");
}

void MyPushButton::leaveEvent(QEvent *)
{
    this->setStyleSheet("color: black");
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    this->setStyleSheet("QPushButton{color:blue; background-color:transparent;}");
    this->zoom();

    QPushButton::mousePressEvent(e);
}

void MyPushButton::keyPressEvent(QKeyEvent *e)
{
    QWidget::keyPressEvent(e);
}

void MyPushButton::keyReleaseEvent(QKeyEvent *e)
{
    QWidget::keyPressEvent(e);
}

void MyPushButton::zoom()
{
    //创建动画对象
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    //动画间隔
    animation->setDuration(200);
    //开始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+20,this->width(),this->height()));
    //设置动画曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行后销毁
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    //创建动画对象
    QPropertyAnimation * animation2=new QPropertyAnimation(this,"geometry");
    //动画间隔
    animation2->setDuration(200);
    //开始位置
    animation2->setStartValue(QRect(this->x(),this->y()+20,this->width(),this->height()));
    //结束位置
    animation2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置动画曲线
    animation2->setEasingCurve(QEasingCurve::OutBounce);
    //执行后销毁
    animation2->start(QAbstractAnimation::DeleteWhenStopped);
}

