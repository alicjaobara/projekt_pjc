#include <iostream>
#include <vector>
using namespace std;
#include "mainwindow.h"
#include "obiekt.h"
#include "symulacja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
