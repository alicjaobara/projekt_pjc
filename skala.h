#ifndef SKALA_H
#define SKALA_H
#include "obiekt.h"

class CSkala :public CObiekt
{
public:
    CSkala(int x=0, int y=0, int w=20, int h=20, int wiek=10, int kontakt=-1);
    int update(int x, int y, vector<CObiekt *> &ob, vector<CGObiekt *> &gob, int t);
    int gettyp();
    int getwiek();
};

#endif // SKALA_H
