#ifndef MYLABEL_H
#define MYLABEL_H
#include <QEvent>
#include <QWidget>
#include<QLabel>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);

    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *ev) ;
    void mousePressEvent(QMouseEvent *ev) ;
    void mouseReleaseEvent(QMouseEvent *ev) ;
    bool event(QEvent * e);

signals:
};

#endif // MYLABEL_H
