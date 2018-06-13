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

//class CObiekt;
//class CGObiekt;
//class CZajac;
//class COwca;
//class CWilk;
//class CLis;

const int lWilk = 30;
const int lOwca = 50;
const int lZajac = 50;
const int lLis = 30;
const int lDrzewo = 400;
const int lSkala = 5;

class CWyspa
{
    int x; // szerokość wyspy
    int y; // wysokość wyspy
    vector<int> populacja; // ilości organizmów
    vector<CObiekt*> obiekty; // vector wszystkich obiektów
    vector<CGObiekt*> gobiekty; // vector organizmów
public:
    CWyspa(int x=700, int y=550, int lw=lWilk, int lo=lOwca, int ld=lDrzewo, int ls=lSkala, int lz=lZajac, int ll=lLis);
    void update();
    void wypiszVector();
    int getx();
    int gety();
    vector<CGObiekt *> getGO();
    vector<int> getpopulacja();
    ~CWyspa();
};

#endif // WYSPA_H
