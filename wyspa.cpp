#include "wyspa.h"

CWyspa::CWyspa(int a, int b, int lw, int lo, int ld, int ls)
{
    x = a;
    y = b;
    populacja.push_back(lw);
    populacja.push_back(lo);
    populacja.push_back(ld);
    populacja.push_back(ls);

    //    populacja.at(0) = lw;
    //    populacja.at(1) = lo;
    //    populacja.at(2) = ld;
    //    populacja.at(3) = ls;

    //vector y
    for(int i=0; i<lw; i++)
    {
        int xo = rand()%(x+1-sWilkw);
        int yo = rand()%(y+1-sWilkh);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, sWilkw, sWilkh, obiekty))
            {
                xo = rand()%(x+1-sWilkw);
                yo = rand()%(y+1-sWilkh);
            }
        }
        CObiekt *wsk = new CWilk(xo,yo,rand()%2+1,rand()%(life+1)+1);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGWilk(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;
    }
    for(int i=0; i<ld; i++)
    {
        int xo = rand()%(x+1-sDrzewow);
        int yo = rand()%(y+1-sDrzewoh);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, sDrzewow,sDrzewoh,obiekty))
            {
                xo = rand()%(x+1-sDrzewow);
                yo = rand()%(y+1-sDrzewoh);
            }
        }
        CObiekt *wsk = new CDrzewo(xo,yo);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGDrzewo(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;
    }
    for(int i=0; i<ls; i++)
    {
        int xo = rand()%(x+1-sSkalaw);
        int yo = rand()%(y+1-sSkalah);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, sSkalaw,sSkalah,obiekty))
            {
                xo = rand()%(x+1-sSkalaw);
                yo = rand()%(y+1-sSkalah);
            }
        }
        CObiekt *wsk = new CSkala(xo,yo);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGSkala(wsk);
        gobiekty.push_back(gwsk);
        wsk=NULL;
        gwsk=NULL;

    }
    for(int i=0; i<lo; i++)
    {
        int xo = rand()%(x+1-sOwcaw);
        int yo = rand()%(y+1-sOwcah);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, sOwcaw, sOwcah, obiekty))
            {
                xo = rand()%(x+1-sOwcaw);
                yo = rand()%(y+1-sOwcah);
            }
        }

        CObiekt *wsk = new COwca(xo,yo,rand()%2+1,rand()%(life/2+1)+1);
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
        int z = obiekty.at(i)->update(x,y,obiekty,gobiekty,i);
        if (z!=-1)
        {
            i--; // bo usówa i-ty element i wtedy i+1 jest i-ty i go już nie robi więc trzeba i--
            //            gobiekty.at(i)->update(); // tak tylko żeby widzieć (chyba)
            cout<<"z: "<<z<<endl;
            CObiekt *wsk=obiekty.at(z);
            delete wsk;
            obiekty.erase(obiekty.begin()+z);

            CGObiekt *gwsk=gobiekty.at(z);
            gobiekty.erase(gobiekty.begin()+z);
            delete gwsk;
        }
        else
        {
            gobiekty.at(i)->update();
        }
    }
    int ld=0, ls=0, lo=0, lw=0;
    for(int i=0; i<obiekty.size(); i++)
    {
        int k = obiekty.at(i)->getkontakt();
        switch (k) {
        case 0:
            ld++;
            break;
        case -1:
            ls++;
            break;
        case 1:
            lo++;
            break;
        case 5:
            lw++;
            break;
        default:
            break;
        }
    }
//    cout<<lw<<" "<<lo<<" "<<ld<<" "<<ls<<endl;
    populacja.at(0)=(lw);
    populacja.at(1)=(lo);
    populacja.at(2)=(ld);
    populacja.at(3)=(ls);
//    cout<<populacja.at(0)<<" "<<populacja.at(1)<<" "<<populacja.at(2)<<" "<<populacja.at(3)<<endl;

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

vector<int> CWyspa::getpopulacja()
{
    return populacja;
}

