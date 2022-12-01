#include "win.h"

Win::Win(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("возведение в квадрат"); //заголовок

    
    frame = new QFrame(this); // рамка находящаяся в левой части
	frame->setFrameShadow(QFrame::Raised);
	frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число:", this); // надпись "Введите число"
    inputEdit = new QLineEdit("", this); // строка для ввода чисел
    outputLabel = new QLabel("Результат:", this); // надпись "Результат: "
    outputEdit = new QLineEdit("", this); // строка для вывода ответа
    nextButton = new QPushButton("Следующее", this); // кнопка "Следующее"
    exitButton = new QPushButton("Выход", this); // кнопка "Выход"


    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // вертикальный компоновщик, в котором содержатся элементы из левой части окна
	vLayout1->addWidget(inputLabel);
	vLayout1->addWidget(inputEdit);
	vLayout1->addWidget(outputLabel);
	vLayout1->addWidget(outputEdit);
	vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout(); // вертикальный компоновщик, в котором содержатся элементы из правой части окна
	vLayout2->addWidget(nextButton);
	vLayout2->addWidget(exitButton);
	vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this); // горизонтальный компоновщик, объединяющий два вертикальных компоновщика
	hLayout->addWidget(frame);
	hLayout->addLayout(vLayout2);

	begin();

    connect(exitButton, &QPushButton::clicked, this, &Win::close); // настройки кнопки выхода
    connect(nextButton, &QPushButton::clicked, this, &Win::begin); // настройки кнопки "следующее"
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc); // настройки поля для ввода числа
}
void Win::begin()
{
    inputEdit->clear(); // сначала поле ввода нужно очистить
    nextButton->setEnabled(false); // и сделать кнопку "следующее" неактивной
    nextButton->setDefault(false);
    inputEdit->setEnabled(true); // а окно для ввода делаем активным
    outputLabel->setVisible(false); // надпись "результат" в какой-то момент становится видимой
    outputEdit->setVisible(false); // и окошко для ответа тоже
    outputEdit->setEnabled(false); // но при этом оно становится неактивным
    inputEdit->setFocus(); //для удобства фокус сразу ставится на окно для ввода
}

void Win::calc()
{
	bool Ok = true;
	float r, a;

    QString str = inputEdit->text(); // вводимое число считывается в переменную
    a = str.toDouble(&Ok); // и оно преобразуется в значение типа double

	if (Ok)
	{
        r = a * a; // r- переменная для ответа

        str.setNum(r); // строка устанавливается в печатное представление числа

        outputEdit->setText(str); // вывод ответа, содержащегося в переменной str
        inputEdit->setEnabled(false); // также как и в функции выше, устанавливаются все необходимые сеттеры для видимости/активности полей
		outputLabel->setVisible(true);
		outputEdit->setVisible(true);
		nextButton->setDefault(true);
		nextButton->setEnabled(true);
		nextButton->setFocus();
	}
    else if (!str.isEmpty()) // проверка вводимой строки
	{
		QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
		msgBox.exec();
	}
}
