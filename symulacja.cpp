#include "symulacja.h"

CSymulacja::CSymulacja()
{
    wyspa = new CWyspa();
    gwyspa = new CGWyspa(wyspa);
}

void CSymulacja::start()
{
//    wyspa = new CWyspa();
}

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
}

CWyspa *CSymulacja::getwyspa()
{
    return wyspa;
}

CGWyspa *CSymulacja::getgwyspa()
{
    return gwyspa;
}


