#ifndef FIRST_WINDOW_H
#define FIRST_WINDOW_H

#include <QDialog>

namespace Ui {
class First_window;
}

class First_window : public QDialog
{
    Q_OBJECT

public:
    explicit First_window(QWidget *parent = nullptr);
    ~First_window();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::First_window *ui;
};

#endif
