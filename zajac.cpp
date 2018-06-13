#include "zajac.h"

CZajac::CZajac(int x, int y, int typ, int wiek, int glod, int w, int h, int kontakt):COrganizm(x, y, typ, wiek, glod, w, h, kontakt)
{

}

void CZajac::ruch(int a, int b)
{
    int l=rand()%2;
    if (l==0)
        x += rand()% (2*rZajac+1) - rZajac;
    else
        y += rand()% (2*rZajac+1) - rZajac;

    if (x >= a-w) x = a-w;
    else if (x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

int CZajac::jedz(int i, int k)
{
    if(k==0)
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

CZajac::~CZajac()
{

}

void CZajac::rozmn(CObiekt *&ob, CGObiekt *&gob)
{
    int l=rand()%100;
    if (l%2 == 0)
    {
        CObiekt *tmp= new CZajac(x,y,rand()%2+1,1);
        CGObiekt *gtmp= new CGZajac(tmp);
        ob=tmp;
        gob=gtmp;
    }
    else
    {
        ob = NULL;
        gob = NULL;
    }
}
