#ifndef DRZEWO_H
#define DRZEWO_H
#include "obiekt.h"

class CDrzewo :public CObiekt
{
    int wiek;
public:
    CDrzewo(int x=0, int y=0, int wiek=10, int w=10, int h=10, int kontakt=0);
    int update(int x, int y, vector<CObiekt *> &ob, vector<CGObiekt *> &gob, int t);
    int gettyp();
    int getwiek();
};

#endif // DRZEWO_H
