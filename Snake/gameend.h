#ifndef GAMEEND_H
#define GAMEEND_H

#include <QWidget>
#include <QLabel>
#include "mypushbutton.h"
#include <QString>
class GameEnd : public QWidget
{
    Q_OBJECT
public:
    // 0 Over 1 Win
    QLabel * m_Label;

    MyPushButton * m_But;

    GameEnd(QString str,int end);

signals:
    void newGame();

public slots:
};

#endif // GAMEEND_H
