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

    //do spr
//    COrganizm *o, *w;
//    o = new COwca();
//    w = new CWilk();

//    for(int i=0;i<10;++i)
//    {

//        cout<<o->getx()<<" "<<o->gety()<<endl;
//        o->ruch();

//        cout<<w->getx()<<" "<<w->gety()<<endl;
//        w->ruch();
//    }

//    delete o;
//    delete w;


//    CWyspa *wysp = new CWyspa();
//    wysp->wypiszVector();
//    wysp->update();
//    wysp->wypiszVector();
//    delete wysp;

    return 0;
}
