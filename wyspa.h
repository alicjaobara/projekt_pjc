#ifndef WYSPA_H
#define WYSPA_H

#include <iostream>
#include <vector>
#include "obiekt.h"
#include "grafika.h"
#include "stale.h"

#include "zajac.h"
#include "wilk.h"
#include "lis.h"
#include "owca.h"
#include "skala.h"
#include "drzewo.h"

using namespace std;

const int lWilk = 20;
const int lOwca = 40;
const int lZajac = 40;
const int lLis = 20;
const int lDrzewo = 300;
const int lSkala = 5;

class CWyspa
{
    int x; // szerokość wyspy
    int y; // wysokość wyspy
    vector<int> populacja; // ilości organizmów
    vector<CObiekt*> obiekty; // vector wszystkich obiektów
    vector<CGObiekt*> gobiekty; // vector organizmów
public:
    CWyspa(int x=500, int y=350, int lw=lWilk, int lo=lOwca, int ld=lDrzewo, int ls=lSkala, int lz=lZajac, int ll=lLis);
    void update();
    int getx();
    int gety();
    vector<CGObiekt *> getGO();
    vector<int> getpopulacja();
    ~CWyspa();
};

#endif // WYSPA_H
