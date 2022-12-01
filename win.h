#ifndef WIN_H
#define WIN_H

#include "area.h"

#include <QBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QValidator>
#include <QWidget>

class Win : public QWidget // класс окна
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn; // кнопка 
    QPushButton * stop; // кнопка

public:
    Win(); // само окно
};

#endif // WIN_H
