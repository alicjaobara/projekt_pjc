#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QTimer>
//#include "wyspa.h"
#include "gwyspa.h"

class CSymulacja
{
private:
    CWyspa *wyspa;
    CGWyspa *gwyspa;
public:
    CSymulacja();
//    CSymulacja(int x, int y, int lw, int lo, int ld, int ls, int lz, int ll);
    void start();
//    void start(int x, int y, int lw, int lo, int ld, int ls, int lz, int ll);
    ~CSymulacja();
    CWyspa* getwyspa();
    CGWyspa* getgwyspa();
    int getx();
    int gety();
public slots:
    void update();
    vector<int> getpopulacja();
};

#endif // SYMULACJA_H
