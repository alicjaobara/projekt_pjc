#include "symulacja.h"

CSymulacja::CSymulacja()
{

}

void CSymulacja::start()
{
    wyspa = new CWyspa();
    gwyspa = new CGWyspa(wyspa);
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
//    delete gwyspa;
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


