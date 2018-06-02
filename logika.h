#ifndef LOGIKA_H
#define LOGIKA_H

#include <iostream>
#include <vector>
#include "grafika.h"

class CGOrganizm;
class CGWilk;

using namespace std;

class CObiekt
{
    int x; // pozycja obiektu x
    int y; // pozycja obiektu y
public:
    CObiekt(int a=0, int b=0);
    int getx();
    int gety();
    virtual void update()=0;
};

class COrganizm
{
protected:
    int x; // pozycja obiektu x
    int y; // pozycja obiektu y
    int wiek;
    int typ; //1- 2- 3-
public:
    COrganizm(int a=0, int b=0, int w=1, int t=1);
    virtual ~COrganizm()=0;
    int getx();
    int gety();
//    virtual void update()=0; //metoda abstrakcyjna
    virtual void ruch(int a, int b)=0;
};

class CWilk :public COrganizm
{

public:
    CWilk(int a=0, int b=0, int w=1, int t=1);
    ~CWilk();
//    void update();
    void ruch(int a, int b);
};

class COwca :public COrganizm
{

public:
    COwca(int a=0, int b=0, int w=1, int t=1);
    ~COwca();
//    void update();
    void ruch(int a, int b);
};

class CWyspa
{
    int x; // szerokość wyspy
    int y; // wysokość wyspy
    vector<COrganizm*> organizmy;
    vector<CGOrganizm*> gOrganizmy;
public:
    CWyspa(int a=100, int b=100, int c=3);
    ~CWyspa();
    void update();
    void wypiszVector();
    int getx();
    int gety();
    vector<CGOrganizm*> getGO();
};


#endif // LOGIKA_H
