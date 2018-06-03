#include "logika.h"

bool sprawdzxy(int x, int y, int w, int h, vector<CObiekt*> ob)
{
    for (int i=0; i<ob.size(); i++)
    {
        int obx = ob.at(i)->getx();
        int oby = ob.at(i)->gety();
        int obxm = ob.at(i)->getx() + ob.at(i)->getw();
        int obym = ob.at(i)->gety() + ob.at(i)->geth();
        if (((x>=obx && x<=obxm) || ((x+w)>=obx && (x+w)<=obxm)) && ((y>=oby && y<=obym) || ((y+h)>=oby && (y+h)<=obym)))
            return true; //prawda jak sie nie zgadza
        else return false;
    }
}

CObiekt::CObiekt(int a, int b, int c, int d, int k)
{
    x=a;
    y=b;
    w=c;
    h=d;
    kontakt=k;
}

int CObiekt::getx()
{
    return x;
}

int CObiekt::gety()
{
    return y;
}

int CObiekt::getw()
{
    return w;
}

int CObiekt::geth()
{
    return h;
}

CObiekt::~CObiekt()
{

}

CDrzewo::CDrzewo(int a, int b, int c, int d, int w, int k):CObiekt(a,b,c,d,k)
{
    wiek=w;
}

int CDrzewo::update(int a, int b, vector<CObiekt *> ob, int t)
{
    wiek++;
    if (wiek >=200)
        return t;
    return -1;
}

CSkala::CSkala(int a, int b, int c, int d, int k):CObiekt(a,b,c,d,k)
{

}

int CSkala::update(int a, int b, vector<CObiekt *> ob, int t)
{
    return -1;
}

COrganizm::COrganizm(int a, int b, int c, int d, int w, int t, int k):CObiekt(a,b,c,d,k)
{
    wiek=w;
    typ=t;
}

int COrganizm::update(int a, int b, vector<CObiekt *> ob, int t)
{
    ruch(a,b);
    for (int i=0 ; i<ob.size(); i++)
    {
//        if(i!=t)
        {
            int obx = ob.at(i)->getx();
            int oby = ob.at(i)->gety();
            int obxm = ob.at(i)->getx() + ob.at(i)->getw();
            int obym = ob.at(i)->gety() + ob.at(i)->geth();

            while(((x>=obx && x<=obxm) || ((x+w)>=obx && (x+w)<=obxm)) && ((y>=oby && y<=obym) || ((y+h)>=oby && (y+h)<=obym)))
            {
                //            cout<<"x: "<<x<<" y: "<<y<<endl;
                //            cout<<"xm: "<<x+w<<" ym: "<<y+h<<endl;
                //            cout<<"obx: "<<obx<<" oby: "<<oby<<endl;
                //            cout<<"obxm: "<<obxm<<" obym: "<<obym<<endl;
                if (ob.at(i)->kontakt == 0) //to trzeba się odsunąć
                {
                    cout<<"i "<<i<<"-";
                    cout<<"x: "<<ob.at(i)->getx()<<" y: "<<ob.at(i)->gety()<<endl;
                    this->ruch(a,b);
                    cout<<"x: "<<ob.at(i)->getx()<<" y: "<<ob.at(i)->gety()<<endl;
                }
                else
                {
                    int z=ob.at(i)->kontakt - kontakt;
                    if(z == 0)
                    {
                        //rozmnazaj może
                        return -1;
                    }
                    else
                    {
                        if(z < 0)
                            return i;//to zabij
                        else
                            return t; // on zabił
                    }
                }
            }
        }
    }
}

COrganizm::~COrganizm()
{

}


CWilk::CWilk(int a, int b, int c, int d, int w, int t, int k):COrganizm(a, b, c, d, w, t, k)
{

}

void CWilk::ruch(int a, int b)
{
    x += rand()% 21 - 10; //od -10 do 10
    y += rand()% 21 - 10; //od -10 do 10

    if (x >= a-w) x = a-w;
    else if(x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

CWilk::~CWilk()
{

}

COwca::COwca(int a, int b, int c, int d, int w, int t, int k):COrganizm(a, b, c, d, w, t, k)
{

}

void COwca::ruch(int a, int b)
{
    x += rand()% 11 - 5; //od -5 do 5
    y += rand()% 11 - 5; //od -5 do 5

    if (x >= a-w) x = a-w;
    else if(x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

COwca::~COwca()
{

}


CWyspa::CWyspa(int a, int b, int c)
{
    x = a;
    y = b;

    //vector y
    for(int i=0; i<c; i++)
    {
        CObiekt *wsk = new CWilk(rand()%(x+1-sWilkw),rand()%(y+1-sWilkh));
        if (!obiekty.empty())
            while (sprawdzxy(wsk->getx(), wsk->gety(), wsk->getw(),wsk->geth(),obiekty))
                wsk = new CWilk(rand()%(x+1-sWilkw),rand()%(y+1-sWilkh));
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGWilk(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;

        wsk = new CDrzewo(rand()%(x+1-sDrzewow),rand()%(y+1-sDrzewoh));
        if (!obiekty.empty())
            while (sprawdzxy(wsk->getx(), wsk->gety(), wsk->getw(),wsk->geth(),obiekty))
                wsk = new CDrzewo(rand()%(x+1-sDrzewow),rand()%(y+1-sDrzewoh));
        obiekty.push_back(wsk);
        gwsk = new CGDrzewo(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;

        wsk = new CSkala(rand()%(x+1-sSkalaw),rand()%(y+1-sSkalah));
        if (!obiekty.empty())
            while (sprawdzxy(wsk->getx(), wsk->gety(), wsk->getw(),wsk->geth(),obiekty))
                wsk = new CSkala(rand()%(x+1-sSkalaw),rand()%(y+1-sSkalah));
        obiekty.push_back(wsk);
        gwsk = new CGSkala(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;

    }
    for(int i=0; i<5*c; i++)
    {
        CObiekt *wsk = new COwca(rand()%(x+1-sOwcaw),rand()%(y+1-sOwcah));
        if (!obiekty.empty())
            while (sprawdzxy(wsk->getx(), wsk->gety(), wsk->getw(),wsk->geth(),obiekty))
                wsk = new COwca(rand()%(x+1-sOwcaw),rand()%(y+1-sOwcah));
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGOwca(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;
    }
}

CWyspa::~CWyspa()
{
    for(int i=0; i<obiekty.size(); i++)
    {
        delete obiekty.at(i);
    }
    for(int i=0; i<gobiekty.size(); i++)
    {
        delete gobiekty.at(i);
    }
}

void CWyspa::update()
{
    for(int i=0; i<obiekty.size(); i++)
    {
        cout<<"obiekt "<< i<<" size("<<obiekty.size()<<")"<<endl;
        int z = obiekty.at(i)->update(x,y,obiekty,i);
        if (z!=-1)
        {
//            gobiekty.at(i)->update(); // tak tylko żeby widzieć (chyba)
            CObiekt *wsk=obiekty.at(z);
            obiekty.erase(obiekty.begin()+z);
            delete wsk;
            CGObiekt *gwsk=gobiekty.at(z);
            gobiekty.erase(gobiekty.begin()+z);
            delete gwsk;
        }
        else
        {
            gobiekty.at(i)->update();
        }
    }
}

void CWyspa::wypiszVector()
{
    cout<<"org"<<endl;
    for(int i=0; i<obiekty.size(); i++)
    {
        cout<<i<<"- x: "<<obiekty.at(i)->getx()<<" y: "<<obiekty.at(i)->gety()<<endl;
    }
    cout<<"gOrg"<<endl;
    for(int i=0; i<gobiekty.size(); i++)
    {
        cout<<i<<"- x: "<<gobiekty.at(i)->getObiekt()->getx()<<" y: "<<gobiekty.at(i)->getObiekt()->gety()<<endl;
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

vector<CGObiekt *> CWyspa::getGO()
{
    return gobiekty;
}

