#include "symulacja.h"

CSymulacja::CSymulacja()
{
    wyspa = new CWyspa(300, 300, 10);
    gwyspa = new CGWyspa(wyspa);
}

void CSymulacja::start()
{
    wyspa = new CWyspa(300, 300, 10);
}

void CSymulacja::update()
{
    wyspa->update();
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


