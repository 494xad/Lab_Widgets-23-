#include "figura.h"
#include <math.h>
#include <QPainter>

void Figura::move(float Alpha,QPainter *Painter) // перемещение фигуры
{
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);
    draw(Painter);
}
void MyLine::draw(QPainter *Painter) // функция рисования линии (через метод move базового класса)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}
void MyRect::draw(QPainter *Painter) // функция рисования квадрата
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
