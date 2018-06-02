#include "logika.h"

CObiekt::CObiekt(int a, int b)
{
    cout<<"CObiekt"<<endl;
    x=a;
    y=b;
}

int CObiekt::getx()
{
    return x;
}

int CObiekt::gety()
{
    return y;
}

COrganizm::COrganizm(int a, int b, int w, int t)
{
    cout<<"COrganizm"<<endl;
    x=a;
    y=b;
    wiek=w;
    typ=t;
}

COrganizm::~COrganizm()
{
    cout<<"~COrganizm"<<endl;
}

int COrganizm::getx()
{
    return x;
}

int COrganizm::gety()
{
    return y;
}

CWilk::CWilk(int a, int b, int w, int t):COrganizm(a, b, w, t)
{
    cout<<"CWilk"<<endl;
}

CWilk::~CWilk()
{
    cout<<"~CWilk"<<endl;
}

void CWilk::ruch(int a, int b)
{
    x += rand()% 20 - 10; //od -10 do 10
    if (x >= a-5) x = a-5;
    else if(x < 0) x = 0;
    y += rand()% 20 - 10; //od -10 do 10
    if (y >= b-5) y = b-5;
    else if (y < 0) y = 0;
}

COwca::COwca(int a, int b, int w, int t):COrganizm(a, b, w, t)
{
    cout<<"COwca"<<endl;
}

COwca::~COwca()
{
    cout<<"~COwca"<<endl;
}

void COwca::ruch(int a, int b)
{
    x += rand()% 10 - 5; //od -5 do 5
    if (x >= a-5) x = a-5;
    else if(x < 0) x = 0;
    y += rand()% 10 - 5; //od -5 do 5
    if (y >= b-5) y = b-5;
    else if (y < 0) y = 0;
}

CWyspa::CWyspa(int a, int b, int c)
{
    cout<<"CWyspa"<<endl;
    x = a;
    y = b;

    //vector y
    for(int i=0; i<c; i++)
    {
        cout<<"vec "<<i<<endl;
        COrganizm *wsk = new CWilk(rand()%x,rand()%y);
        organizmy.push_back(wsk);
        CGOrganizm *gwsk = new CGWilk(wsk);
        gOrganizmy.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;
        wsk = new COwca(rand()%x,rand()%y);
        organizmy.push_back(wsk);
        gwsk = new CGOwca(wsk);
        gOrganizmy.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;
    }
}

CWyspa::~CWyspa()
{
    cout<<"~CWyspa"<<endl;
    for(int i=0; i<organizmy.size(); i++)
    {
        cout<<"des "<<i<<endl;
        if(!organizmy.empty())
            delete organizmy.at(i);
        else cout<<"error"<<endl;
    }
    for(int i=0; i<gOrganizmy.size(); i++)
    {
        cout<<"des "<<i<<endl;
        if(!gOrganizmy.empty())
            delete gOrganizmy.at(i);
        else cout<<"error"<<endl;
    }
}

void CWyspa::update()
{
    cout<<"wyspa update"<<endl;
    for(int i=0; i<organizmy.size(); i++)
    {
        organizmy.at(i)->ruch(x,y);
        gOrganizmy.at(i)->update();
    }

    cout<<"wyspa update end"<<endl;
}

void CWyspa::wypiszVector()
{
    cout<<"org"<<endl;
    for(int i=0; i<organizmy.size(); i++)
    {
        cout<<i<<"- x: "<<organizmy.at(i)->getx()<<" y: "<<organizmy.at(i)->gety()<<endl;
    }
    cout<<"gOrg"<<endl;
    for(int i=0; i<organizmy.size(); i++)
    {
        cout<<i<<"- x: "<<gOrganizmy.at(i)->getOrgnizm()->getx()<<" y: "<<gOrganizmy.at(i)->getOrgnizm()->gety()<<endl;
    }
}

int CWyspa::getx()
{
    return x;
}

int CWyspa::gety()
{
    return y;
}

vector<CGOrganizm *> CWyspa::getGO()
{
    return gOrganizmy;
}




