#include "win.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win w; // создание окна с приложением
    w.show();
    return a.exec(); // запуск цикла обработки сообщений
}
