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
//    QRect screenGeometry = QApplication::desktop()->screenGeometry();
//    w.resize(screenGeometry.width(), screenGeometry.height());
//    w.showNormal();
    w.setWindowState(Qt::WindowMaximized);
//    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();

    return a.exec();
}
