#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QTimer>
#include "wyspa.h"

class CSymulacja
{
private:

    CWyspa *wyspa;
    CGWyspa *gwyspa;

public:
    CSymulacja();
    void start();

    ~CSymulacja();
    CWyspa* getwyspa();
    CGWyspa* getgwyspa();

public slots:
    void update();
    vector<int> getpopulacja();

};

#endif // SYMULACJA_H
