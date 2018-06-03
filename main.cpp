#include <iostream>
#include <vector>
using namespace std;
#include "mainwindow.h"
#include "logika.h"
#include "symulacja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
