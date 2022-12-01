#ifndef figura_h
#define figura_h

#include <QBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QValidator>
#include <QWidget>
#include <QPainter>

class Figura
{
protected:
    int x, y, halflen, dx, dy, r; // координаты
    virtual void draw(QPainter *Painter) = 0; // метод рисования

public:
    Figura(int X,int Y,int Halflen):
    x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter); // метод поворота
    virtual ~Figura() = default;
};

class MyLine:
public Figura // класс линии
{
protected:
    void draw(QPainter *Painter) override;

public:
    virtual ~MyLine() = default;
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyRect:
public Figura // класс круга
{
protected:
    void draw(QPainter *Painter) override;

public:
    virtual ~MyRect() = default;
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};

#endif
