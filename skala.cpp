#include "skala.h"

CSkala::CSkala(int x, int y, int w, int h, int wiek, int kontakt):CObiekt(x,y,w,h,kontakt)
{

}

int CSkala::update(int x, int y, vector<CObiekt *>& ob, vector<CGObiekt *>& gob, int t)
{
    return -1;
}

int CSkala::gettyp()
{
    return 0;
}

int CSkala::getwiek()
{
    return 0;
}
