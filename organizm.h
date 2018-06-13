#ifndef ORGANIZM_H
#define ORGANIZM_H

#include "obiekt.h"
//#include <vector>
//#include "grafika.h"
//#include "stale.h"

class CObiekt;
class CGObiekt;

const int rWilk = 7;
const int rOwca = 4;
const int rZajac = 5;
const int rLis = 5;

class COrganizm :public CObiekt
{
protected:
    int wiek;
    int typ; //1- 2- 3-
    int glod;
public:
    COrganizm(int x=0, int y=0, int typ=0, int wiek=1, int glod=50, int w=10, int h=10, int kontakt=1);
    virtual int update(int x, int y, vector<CObiekt *> &ob, vector<CGObiekt *> &gob, int t);
    virtual void ruch(int a, int b)=0;
    virtual void rozmn(CObiekt *&ob, CGObiekt *&gob)=0;
    virtual int jedz(int i,int k)=0;
    int gettyp();
    int getwiek();
    virtual ~COrganizm()=0;
};

#endif // ORGANIZM_H
