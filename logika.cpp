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


