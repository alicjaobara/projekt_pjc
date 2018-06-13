#include "wyspa.h"

bool sprawdzxy(int x, int y, int w, int h, vector<CObiekt*> ob)
{
    for (int i=0; i<ob.size(); i++)
    {
        if (ob.at(i)->getkontakt()!=0)
        {
            int obx = ob.at(i)->getx();
            int oby = ob.at(i)->gety();
            int obxm = ob.at(i)->getx() + ob.at(i)->getw();
            int obym = ob.at(i)->gety() + ob.at(i)->geth();
            if (((x>=obx && x<=obxm) || ((x+w)>=obx && (x+w)<=obxm)) && ((y>=oby && y<=obym) || ((y+h)>=oby && (y+h)<=obym)))
            {
                return false; //fałsz jak na siebie nachodzą
            }
        }
    }
    return true;
}

CWyspa::CWyspa(int x, int y, int lw, int lo, int ld, int ls, int lz, int ll)
{
    this->x = x;
    this->y = y;
    populacja.push_back(lw);
    populacja.push_back(lo);
    populacja.push_back(ld);
    populacja.push_back(ls);
    populacja.push_back(lz);
    populacja.push_back(ll);
    populacja.push_back(lw+lo+ld+ls+lz+ll);
    for(int i=0; i<ls; i++)
    {
        int xo = rand()%(x+1-20);
        int yo = rand()%(y+1-20);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, 20, 20, obiekty))
            {
                xo = rand()%(x+1-20);
                yo = rand()%(y+1-20);
            }
        }
        CObiekt *wsk = new CSkala(xo,yo);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGSkala(wsk);
        gobiekty.push_back(gwsk);
    }
    for(int i=0; i<ld; i++)
    {
        int xo = rand()%(x+1-10);
        int yo = rand()%(y+1-10);
        if (!obiekty.empty())
        {
            while (!sprawdzxy0(xo, yo, 10, 10, obiekty))
            {
                xo = rand()%(x+1-10);
                yo = rand()%(y+1-10);
            }
        }
        CObiekt *wsk = new CDrzewo(xo,yo);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGDrzewo(wsk);
        gobiekty.push_back(gwsk);
    }
    for(int i=0; i<lw; i++)
    {
        int xo = rand()%(x+1-10);
        int yo = rand()%(y+1-10);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, 10, 10, obiekty))
            {
                xo = rand()%(x+1-10);
                yo = rand()%(y+1-10);
            }
        }
        CObiekt *wsk = new CWilk(xo,yo,rand()%2+1,rand()%(life+1)+1);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGWilk(wsk);
        gobiekty.push_back(gwsk);
    }


    for(int i=0; i<lo; i++)
    {
        int xo = rand()%(x+1-10);
        int yo = rand()%(y+1-10);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, 10, 10, obiekty))
            {
                xo = rand()%(x+1-10);
                yo = rand()%(y+1-10);
            }
        }
        CObiekt *wsk = new COwca(xo,yo,rand()%2+1,rand()%(life/2+1)+1);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGOwca(wsk);
        gobiekty.push_back(gwsk);
    }
    for(int i=0; i<lz; i++)
    {
        int xo = rand()%(x+1-10);
        int yo = rand()%(y+1-10);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, 10, 10, obiekty))
            {
                xo = rand()%(x+1-10);
                yo = rand()%(y+1-10);
            }
        }
        CObiekt *wsk = new CZajac(xo,yo,rand()%2+1,rand()%(life/2+1)+1);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGZajac(wsk);
        gobiekty.push_back(gwsk);
    }
    for(int i=0; i<ll; i++)
    {
        int xo = rand()%(x+1-10);
        int yo = rand()%(y+1-10);
        if (!obiekty.empty())
        {
            while (!sprawdzxy(xo, yo, 10, 10, obiekty))
            {
                xo = rand()%(x+1-10);
                yo = rand()%(y+1-10);
            }
        }
        CObiekt *wsk = new CLis(xo,yo,rand()%2+1,rand()%(life/2+1)+1);
        obiekty.push_back(wsk);
        CGObiekt *gwsk = new CGLis(wsk);
        gobiekty.push_back(gwsk);
    }
}

CWyspa::~CWyspa()
{
    for(int i=0; i<obiekty.size(); i++)
    {
        delete obiekty.at(i);
    }
//    obiekty.empty();
//    for(int i=0; i<gobiekty.size(); i++)
//    {
//        delete gobiekty.at(i);
//    }
}

void CWyspa::update()
{
    for(int i=0; i<obiekty.size(); i++)
    {
        int z = obiekty.at(i)->update(x, y, obiekty, gobiekty, i);
        if (z!=-1)
        {
            cout<<"p ";
            i--;
            CObiekt *wsk = obiekty.at(z);
            delete wsk;
            obiekty.erase(obiekty.begin()+z);
            CGObiekt *gwsk = gobiekty.at(z);
            gobiekty.erase(gobiekty.begin()+z);
            delete gwsk;
            cout<<"k"<<endl;
        }
        else
        {
            gobiekty.at(i)->update();
        }
    }
    int ld=0, ls=0, lo=0, lw=0, lz=0, ll=0;
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
        case 2:
            lo++;
            break;
        case 1:
            lz++;
            break;
        case 3:
            ll++;
            break;
        case 5:
            lw++;
            break;
        default:
            break;
        }
    }
    populacja.at(0)=(lw);
    populacja.at(1)=(lo);
    populacja.at(2)=(ld);
    populacja.at(3)=(ls);
    populacja.at(4)=(lz);
    populacja.at(5)=(ll);
    populacja.at(6)=(lw+lo+ld+ls+lz+ll);
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

