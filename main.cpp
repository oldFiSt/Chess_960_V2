#include "mainwindow.h"
#include "first_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    First_window w_2;
    w_2.show();
    return a.exec();
}
