#ifndef LIS_H
#define LIS_H
#include "organizm.h"
//class CGObiekt;

class CLis :public COrganizm
{

public:
    CLis(int x=0, int y=0, int typ=1, int wiek=1, int glod=500, int w=10, int h=10, int kontakt=3);
    ~CLis();
    void rozmn(CObiekt *&ob, CGObiekt *&gob);
    void ruch(int a, int b);
    int jedz(int i,int k);
};

#endif // LIS_H
