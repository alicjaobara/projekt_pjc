﻿#ifndef LOGIKA_H
#define LOGIKA_H

#include <iostream>
#include <vector>
#include "grafika.h"
#include "stale.h"

class CGObiekt;
//class CGWilk;

using namespace std;



class CObiekt
{
protected:
    int x; // pozycja obiektu x lewy
    int y; // pozycja obiektu y góra
    int w; // szerokość obiektu (x)
    int h; // wysokość obiektu (y)
public:
    int kontakt;
    CObiekt(int a=0, int b=0, int c=1, int d=1,int k=0);
    int getx();
    int gety();
    int getw();
    int geth();
    virtual int update(int a, int b, vector<CObiekt*> ob, int t)=0;
    virtual ~CObiekt()=0;
};

class CDrzewo :public CObiekt
{
    int wiek;
public:
    CDrzewo(int a=0, int b=0, int c=sDrzewow, int d=sDrzewoh, int w=10, int k=0);
    int update(int a, int b, vector<CObiekt*> ob, int t);
    int kontakt();
};

class CSkala :public CObiekt
{
public:
    CSkala(int a=0, int b=0, int c=sSkalaw, int d=sSkalah, int k=0);
    int update(int a, int b, vector<CObiekt*> ob, int t);
};

class COrganizm :public CObiekt
{
protected:
    int wiek;
    int typ; //1- 2- 3-
//    int atak;
public:
    COrganizm(int a=0, int b=0, int c=1, int d=1, int w=10, int t=1, int k=0);
    virtual int update(int a, int b, vector<CObiekt*> ob, int t);
    virtual void ruch(int a, int b)=0;
    virtual ~COrganizm()=0;
};

class CWilk :public COrganizm
{
public:
    CWilk(int a=0, int b=0, int c=sWilkw, int d=sWilkh, int w=1, int t=1, int k=5);
//    int update(int a, int b, vector<CObiekt*> ob, int t);
    void ruch(int a, int b);
    ~CWilk();
};

class COwca :public COrganizm
{

public:
    COwca(int a=0, int b=0, int c=sOwcaw, int d=sOwcah, int w=1, int t=1, int k=1);
    ~COwca();
//    int update(int a, int b, vector<CObiekt*> ob, int t);
    void ruch(int a, int b);
};

class CWyspa
{
    int x; // szerokość wyspy
    int y; // wysokość wyspy
    vector<CObiekt*> obiekty;
    vector<CGObiekt*> gobiekty;
public:
    CWyspa(int a=sWyspa, int b=sWyspa, int c=10);
    void update();
    void wypiszVector();
    int getx();
    int gety();
    vector<CGObiekt *> getGO();
    ~CWyspa();
};

bool sprawdzxy(int x, int y, int w, int h, vector<CObiekt*> ob);


#endif // LOGIKA_H
