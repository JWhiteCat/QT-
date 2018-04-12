#include "mainwindow.h"
#include"dialog1.h"
#include"dialog2.h"
#include"dialog3.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
