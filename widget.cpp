#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QPushButton>
#include <QMouseEvent>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1=startTimer(1000);//1.间隔 毫秒
    id2=startTimer(2000);//1.间隔 毫秒
    QTimer * time = new QTimer(this);
    time->start(500);
    static int num = 1;
    connect(time,&QTimer::timeout,[=](){ui->label_4->setText(QString::number(num++));});
    connect(ui->btn,&QPushButton::clicked,[=](){time->stop();});

    //安装事件过滤器 步骤一
    ui->label->installEventFilter(this);
    //步骤二 重写

}
void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==id1)
    {static int num = 1;
    ui->label_2->setText(QString::number(num++));
    }
    if(e->timerId()==id2)
    {
    static int num2 = 1;
    ui->label_3->setText(QString::number(num2++));
    }
}
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->label)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev = static_cast<QMouseEvent * >(e);
            QString str = QString("event 事件过滤器鼠标按下了 x=%1 , y=%2 ").arg(ev->x()).arg(ev->y());
            qDebug()<<str;
            return true;//用户自己处理不分发
        }
    }
}
Widget::~Widget()
{
    delete ui;
}
