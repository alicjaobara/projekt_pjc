#include "symulacja.h"

CSymulacja::CSymulacja()
{
    wyspa = new CWyspa(200, 200, 5);

}

void CSymulacja::start()
{
    wyspa = new CWyspa(200, 200, 5);
}

void CSymulacja::update()
{
    cout<<"sym update"<<endl;
    //    Sleep(1000);
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

