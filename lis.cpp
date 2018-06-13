#include "lis.h"

CLis::CLis(int x, int y, int typ, int wiek, int glod, int w, int h, int kontakt):COrganizm(x, y, typ, wiek,  glod, w, h, kontakt)
{

}

CLis::~CLis()
{

}

void CLis::rozmn(CObiekt *&ob, CGObiekt *&gob)
{
    int l=rand()%100;
    if (l%5 == 0)
    {
        CObiekt *tmp = new CLis(x,y,rand()%2+1,1);
        CGObiekt *gtmp = new CGLis(tmp);
        ob = tmp;
        gob = gtmp;
    }
    else
    {
        ob = NULL;
        gob = NULL;
    }
}

void CLis::ruch(int a, int b)
{
    x += rand()% (2*rLis+1) - rLis;
    y += rand()% (2*rLis+1) - rLis;

    if (x >= a-w) x = a-w;
    else if (x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

int CLis::jedz(int i, int k)
{
    if(k!=0)
    {
        if(glod<=1000)
        {
            glod+=200;
            return i;
        }
        else
            return -1;
    }
    else return -1;
}
