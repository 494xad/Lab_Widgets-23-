#ifndef area_h
#define area_h

#include "figura.h"

#include <QBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QValidator>
#include <QWidget>

class Area 
: public QWidget // зона прорисовки
{
    int myTimer; // таймер
    float alpha; // угол поворота

public:

    Area(QWidget *parent = 0); // конструктор
    virtual ~Area();
    MyLine *myline; // определение линии
    MyRect *myrect; // определение квадрата

protected:

// обработчики событий для начала рисования, старта, считывания и уничтожения таймера
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};
#endif
