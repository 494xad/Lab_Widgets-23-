#include "area.h"
#include <QTimerEvent>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200)); // устанавливаем размер зоны, квадрата, линии, и угол поворота (изначально =0)
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(10); // создаём таймер
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // переменная "рисования"
    painter.setPen(Qt::red); // рисование красным цветом
    myline->move(alpha,&painter); // методы рисования
    myrect->move(alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если таймер работает
    {
    alpha=alpha+0.2; // увеличиваем угол
    update(); // и обновляем вид
    }
    else
    QWidget::timerEvent(event);
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // остановка таймера
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
