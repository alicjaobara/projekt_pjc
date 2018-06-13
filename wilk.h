#ifndef WILK_H
#define WILK_H
#include "organizm.h"

//class CGObiekt;

class CWilk :public COrganizm
{
public:
    CWilk(int x=0, int y=0, int typ=1, int wiek=1, int glod=500, int w=10, int h=10, int kontakt=5);
    void ruch(int a, int b);
    void rozmn(CObiekt *&ob, CGObiekt *&gob);
    ~CWilk();
    int jedz(int i, int k);
};

#endif // WILK_H
