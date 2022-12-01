#ifndef WIN_H
#define WIN_H

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Counter : public QLineEdit
{
	Q_OBJECT

public:
	Counter(const QString &contents, QWidget *parent = nullptr) : QLineEdit(contents, parent) {}

signals:
    void tick_signal();// сигнал, вызываемый при счёте кратном пяти

public slots:
	void add_one()
	{
        QString str = text();
        int r = str.toInt(); // перевод введенного числа из строки в int

        if (r != 0 && r % 5 == 0) // вызов сигнала, если число кратно 5
        {
            emit tick_signal();
        }

        r++; // +1 в графе "счёт по 5"

		str.setNum(r);
        setText(str); // вывод результата
	}
};

class Win : public QWidget
{
	Q_OBJECT

protected:
    QLabel *label1, *label2; // надписи
    Counter *edit1, *edit2; // числа
    QPushButton *calcbutton; // кнопки
	QPushButton *exitbutton;

public:
    Win(QWidget *parent = nullptr); // окно
};

#endif // WIN_H
