#include "first_window.h"
#include "second_window.h"
#include "ui_first_window.h"
#include "QMessageBox"

First_window::First_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::First_window)
{
    ui->setupUi(this);
}

First_window::~First_window()
{
    delete ui;
}

void First_window::on_pushButton_clicked()
{
    Second_window secondWindow;
    secondWindow.setModal(true);
    this->hide();
    secondWindow.exec();
    this->show();
}

void First_window::on_pushButton_2_clicked()
{
    Second_window secondWindow;
    secondWindow.setModal(true);
    QMessageBox::information(this, "Ошибка", "Данная функция находится в разработке ");
    // this->hide();
    // secondWindow.exec();
    // this->show();

}

void First_window::on_pushButton_3_clicked()
{
    Second_window secondWindow;
    secondWindow.setModal(true);
    QMessageBox::information(this, "Правила", "<b>Генерация начального расположения:</b> <br> 1. Короли должны стоять между ладьями ♜ ♛ ♜ "
                                              "<br> 2. Слоны должны быть на полях разного цвета "
                                              "<br> 3. 960 возможных начальных позиций (отсюда название)"
                                              "                            <h4>Условия для рокировки:</h4>  "
                                              "•Король и ладья не двигались с начала партии "
                                              "<br>•Все поля между начальной и конечной позицией свободны"
                                              "<br>•Король не проходит через битые поля"
                                              "<br>•Король не находится под шахом"
                                              "                          <h4>Остальные правила:</h4>"
                                              "Ходы фигур — как в классических шахматах"
                                              "<br>Взятие на проходе — разрешено"
                                              "<br>Превращение пешки — разрешено"
                                              "<br>Шах и мат — цель игры");
    // this->hide();
    // secondWindow.exec();
    // this->show();

}



