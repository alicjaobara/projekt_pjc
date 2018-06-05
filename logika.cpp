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
        {
            return false; //fałsz jak sie nie zgadza
        }
    }
    return true;
}

bool sprawdzxy0(int x, int y, int w, int h, vector<CObiekt*> ob)
{
    for (int i=0; i<ob.size(); i++)
    {
        if(ob.at(i)->getkontakt()==0 || ob.at(i)->getkontakt()==-1)
        {
            int obx = ob.at(i)->getx();
            int oby = ob.at(i)->gety();
            int obxm = ob.at(i)->getx() + ob.at(i)->getw();
            int obym = ob.at(i)->gety() + ob.at(i)->geth();
            if (((x>=obx && x<=obxm) || ((x+w)>=obx && (x+w)<=obxm)) && ((y>=oby && y<=obym) || ((y+h)>=oby && (y+h)<=obym)))
            {
                return false; //fałsz jak sie nie zgadza
            }
        }
    }
    return true;
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

int CObiekt::getkontakt()
{
    return kontakt;
}

CObiekt::~CObiekt()
{

}

CDrzewo::CDrzewo(int a, int b, int c, int d, int w, int k):CObiekt(a,b,c,d,k)
{
    wiek=w;
}

int CDrzewo::update(int a, int b, vector<CObiekt *>& ob, vector<CGObiekt *>& gob,int t)
{
//    wiek++;
//    if (wiek >= 4*life)
//    {
//        return t;
//    }
//    else
//    {
        //        int l=rand()%1000;
        //        if (l%200 == 0) //rośnie
        //        {
        //            w++;
        //            h++;
        //            return -3;
        //        }
        return -1;
//    }
}

int CDrzewo::gettyp()
{
    return 0;
}

CSkala::CSkala(int a, int b, int c, int d, int k):CObiekt(a,b,c,d,k)
{

}

int CSkala::update(int a, int b, vector<CObiekt *>& ob, vector<CGObiekt *>& gob,int t)
{
    return -1;
}

int CSkala::gettyp()
{
    return 0;
}

COrganizm::COrganizm(int a, int b, int t, int w, int c, int d, int k):CObiekt(a,b,c,d,k)
{
    wiek=w;
    typ=t;
}

int COrganizm::update(int a, int b, vector<CObiekt *>& ob, vector<CGObiekt *>& gob,int t)
{
    wiek++;
    if (wiek >= life)
    {
        return t;
    }
    else
    {
        int xp=x;
        int yp=y;

        ruch(a,b);
        while(!sprawdzxy0(x,y,w,h,ob))
        {
            x=xp;
            y=yp;
            ruch(a,b);
        }

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

                    int z=ob.at(i)->getkontakt() - kontakt;
                    if(z == 0)
                    {
                        if ((typ==1 && ob.at(i)->gettyp()==2) || (typ==2 && ob.at(i)->gettyp()==1))
                        {//rozmnazaj może
                            cout<<"roz "<<kontakt<<endl;
                            int l=rand()%100;
                            if (l%10 == 0)
                            {
                                CObiekt *wsk;
                                CGObiekt *gwsk;

                                switch (kontakt)
                                {
                                case 1:
                                    wsk = new COwca(x,y,rand()%2+1,1);
                                    gwsk = new CGOwca(wsk);
                                    break;
                                case 5:
                                    wsk = new CWilk(x,y,rand()%2+1,1);
                                    gwsk = new CGWilk(wsk);
                                    break;
                                default:
                                    break;
                                }
                                ob.push_back(wsk);
                                gob.push_back(gwsk); //trzeba to jeszce dodać do g view
                                wsk=NULL;
                                gwsk=NULL;
                            }
                        }
                        return -1;
                    }
                    else
                    {
                        if(z < 0)
                        {
                            return i;//to zabij
                        }
                        else
                        {
                            return t; // on zabił
                        }
                    }
                }
            }
        }
    }
}

int COrganizm::gettyp()
{
    return typ;
}

COrganizm::~COrganizm()
{

}


CWilk::CWilk(int a, int b, int t, int w, int c, int d, int k):COrganizm(a, b, t, w, c, d, k)
{

}

void CWilk::ruch(int a, int b)
{

    x += rand()% (2*rWilk+1) - rWilk; //od -10 do 10
    y += rand()% (2*rWilk+1) - rWilk; //od -10 do 10

    if (x >= a-w) x = a-w;
    else if(x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

CWilk::~CWilk()
{

}

COwca::COwca(int a, int b, int t, int w, int c, int d, int k):COrganizm(a, b, t, w, c, d, k)
{

}

void COwca::ruch(int a, int b)
{
    x += rand()% (2*rOwca+1) - rOwca; //od -5 do 5
    y += rand()% (2*rOwca+1) - rOwca; //od -5 do 5

    if (x >= a-w) x = a-w;
    else if(x < 0) x = 0;
    if (y >= b-h) y = b-h;
    else if (y < 0) y = 0;
}

COwca::~COwca()
{

}


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

