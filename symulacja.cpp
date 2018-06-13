#include "symulacja.h"

CSymulacja::CSymulacja()
{
//    wyspa = new CWyspa();
//    gwyspa = new CGWyspa(wyspa);
}

void CSymulacja::start()
{
    wyspa = new CWyspa();
    gwyspa = new CGWyspa(wyspa);
}

//void CSymulacja::start(int x, int y, int lw, int lo, int ld, int ls, int lz, int ll)
//{
//    delete wyspa;
//    delete gwyspa;
//    wyspa = new CWyspa(x,y,lw,lo,ld,ls,lz,ll);
//    gwyspa = new CGWyspa(wyspa);

//    //    wyspa = new CWyspa();
//    //    gwyspa = new CGWyspa(wyspa);
//}

void CSymulacja::update()
{
    wyspa->update();
}

vector<int> CSymulacja::getpopulacja()
{
    return wyspa->getpopulacja();
}

CSymulacja::~CSymulacja()
{
    delete wyspa;
    delete gwyspa;
}

CWyspa *CSymulacja::getwyspa()
{
    return wyspa;
}

CGWyspa *CSymulacja::getgwyspa()
{
    return gwyspa;
}

int CSymulacja::getx()
{
    return wyspa->getx();
}

int CSymulacja::gety()
{
    return wyspa->gety();
}


