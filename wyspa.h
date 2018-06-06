#ifndef WYSPA_H
#define WYSPA_H

#include <iostream>
#include <vector>
#include "logika.h"
#include "grafika.h"
#include "stale.h"

using namespace std;

class CObiekt;
class CGObiekt;

class CWyspa
{
    int x; // szerokość wyspy
    int y; // wysokość wyspy

    vector<int> populacja;
    vector<CObiekt*> obiekty;
    vector<CGObiekt*> gobiekty;
public:
    CWyspa(int a=sWyspa, int b=sWyspa, int lw=lWilk, int lo=lOwca, int ld=lDrzewo, int ls=lSkala);
    void update();
    void wypiszVector();
    int getx();
    int gety();
    vector<CGObiekt *> getGO();
    vector<int> getpopulacja();
    ~CWyspa();
};

#endif // WYSPA_H
