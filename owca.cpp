#include "owca.h"

COwca::COwca(int x, int y, int typ, int wiek, int glod , int w, int h, int kontakt):COrganizm(x, y, typ, wiek, glod, w, h, kontakt)
{

}

void COwca::ruch(int a, int b)
{
    int l=rand()%2;
    if (l==0)
        x += rand()% (2*rOwca+1) - rOwca;
    else
        y += rand()% (2*rOwca+1) - rOwca;

    if (x >= a-w) x = a-w;
    else if (x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

int COwca::jedz(int i, int k)
{
    if(k==0)
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

COwca::~COwca()
{

}

void COwca::rozmn(CObiekt *&ob, CGObiekt *&gob)
{
    int l=rand()%100;
    if (l%5 == 0)
    {
        CObiekt *tmp= new COwca(x,y,rand()%2+1,1);
        CGObiekt *gtmp= new CGOwca(tmp);
        ob=tmp;
        gob=gtmp;
    }
    else
    {
        ob = NULL;
        gob = NULL;
    }
}
