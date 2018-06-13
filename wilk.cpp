#include "wilk.h"

CWilk::CWilk(int x, int y, int typ, int wiek, int glod, int w, int h, int kontakt):COrganizm(x, y, typ, wiek, glod, w, h, kontakt)
{

}

void CWilk::ruch(int a, int b)
{
    x += rand()% (2*rWilk+1) - rWilk;
    y += rand()% (2*rWilk+1) - rWilk;

    if (x >= a-w) x = a-w;
    else if (x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

void CWilk::rozmn(CObiekt *&ob, CGObiekt *&gob)
{
    int l=rand()%100;
    if (l%5 == 0)
    {
        CObiekt *tmp= new CWilk(x,y,rand()%2+1,1);
        CGObiekt *gtmp= new CGWilk(tmp);
        ob=tmp;
        gob=gtmp;
    }
    else
    {
        ob = NULL;
        gob = NULL;
    }
}

CWilk::~CWilk()
{

}

int CWilk::jedz(int i,int k)
{
    if(k!=0)
    {
        if(glod<=2000)
        {
            glod+=200;
            return i;
        }
        else
            return -1;
    }
    else return -1;
}
