#include "mylabel.h"
#include<QDebug>
#include<QLabel>
#include<QString>
#include<QEvent>
#include<QMouseEvent>
mylabel::mylabel(QWidget *parent)
    : QLabel{parent}
{
    // setMouseTracking(true);

}
void mylabel::enterEvent(QEnterEvent *event)
{

    qDebug()<<"鼠标进入了";
}
void mylabel::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开了";
}
void mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()&Qt::LeftButton)
    {
        QString str = QString("鼠标移动了 x=%1 , y=%2 ").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }

}
void mylabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()== Qt::LeftButton)
    {
        QString str = QString("鼠标按下了 x=%1 , y=%2 ").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }

}
void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标松开了";
}

bool  mylabel::event(QEvent * e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ev = static_cast<QMouseEvent * >(e);
        QString str = QString("event 函数鼠标按下了 x=%1 , y=%2 ").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
        return true;//用户自己处理不分发
    }
    //其他事件交给父类处理
    return QLabel::event(e);
}

