#include "win.h"

Win::Win()
{
    setWindowTitle("Заголовок окна"); // заголовок окна
    area = new Area(this);
    btn = new QPushButton("Завершить",this ); // кнопка "Завершить"
    stop = new QPushButton("Остановить", this);

    QVBoxLayout *layout = new QVBoxLayout(this); // вертикальный компоновщик для зоны прорисовки и кнопок
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); // сигнал при нажатии кнопок
//    connect(stop, &QPushButton::clicked, area, &Area::hideEvent );
};
