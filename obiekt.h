#ifndef LOGIKA_H
#define LOGIKA_H

//#include <iostream>
#include <vector>
#include "grafika.h"
//#include "stale.h"

class CGObiekt;
//class CGWilk;

const int life = 10000;

using namespace std;

class CObiekt
{
protected:
    int x; // pozycja obiektu x lewy
    int y; // pozycja obiektu y góra
    int w; // szerokość obiektu (x)
    int h; // wysokość obiektu (y)
    int kontakt;
public:
    CObiekt(int x=0, int y=0, int w=1, int h=1, int kontakt=0);
    int getx();
    int gety();
    int getw();
    int geth();
    int getkontakt();
    virtual int getwiek()=0;
    virtual int gettyp()=0;
    virtual int update(int a, int b, vector<CObiekt *> &ob, vector<CGObiekt *> &gob, int t)=0;
    virtual ~CObiekt()=0;
};

//bool sprawdzxy(int x, int y, int w, int h, vector<CObiekt*> ob);
bool sprawdzxy0(int x, int y, int w, int h, vector<CObiekt*> ob);


#endif // LOGIKA_H
