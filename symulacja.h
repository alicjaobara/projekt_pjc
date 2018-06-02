#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QTimer>
#include "logika.h"

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

};

#endif // SYMULACJA_H
