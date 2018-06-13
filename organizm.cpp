#include "organizm.h"



COrganizm::COrganizm(int x, int y, int typ, int wiek, int glod, int w, int h, int kontakt):CObiekt(x,y,w,h,kontakt)
{
    this->wiek = wiek;
    this->typ = typ;
    this->glod = glod;
}

int COrganizm::update(int a, int b, vector<CObiekt *>& ob, vector<CGObiekt *>& gob, int t)
{
    glod--;
    wiek++;
    if (wiek >= life)
    {
        return t; //umieram ze strosci
    }
    else if (glod <= 0)
    {
        return t; //umieram z glodu
    }
    else
    {
        int xp = x;
        int yp = y;
        ruch(a,b);
        while(!sprawdzxy0(x,y,w,h,ob))
        {
            x = xp;
            y = yp;
            ruch(a,b);
        }
        for (int i=0 ; i<ob.size(); i++)
        {
            //            if(i!=t)
            {
                int obx = ob.at(i)->getx();
                int oby = ob.at(i)->gety();
                int obxm = ob.at(i)->getx() + ob.at(i)->getw();
                int obym = ob.at(i)->gety() + ob.at(i)->geth();

                if(((x>=obx && x<=obxm) || ((x+w)>=obx && (x+w)<=obxm)) && ((y>=oby && y<=obym) || ((y+h)>=oby && (y+h)<=obym)))
                {
                    if(ob.at(i)->getkontakt()==0) //drzewo
                    {
                        int j=jedz(i, 0);
                        return j;
                    }

                    int z = ob.at(i)->getkontakt() - kontakt;
                    if(z == 0)
                    {
                        if (((typ==1 && ob.at(i)->gettyp()==2) || (typ==2 && ob.at(i)->gettyp()==1)) && wiek>=life/5 && ob.at(i)->getwiek()>=life/5)
                        {
                            CObiekt *wsk=NULL;
                            CGObiekt *gwsk=NULL;
                            rozmn(wsk,gwsk);
                            if (wsk!=NULL)
                            {
                                ob.push_back(wsk);
                                gob.push_back(gwsk);
                            }
                        }
                        return -1;
                    }
                    else
                    {
                        if(z < 1)
                        {
                            int j=jedz(i, 1);
                            return j; // to zabij
                        }
                        else
                        {
//                            if (z!=1)
//                            {
//                                return t; // on zabił
//                            }
//                            else
                                return -1;
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

int COrganizm::getwiek()
{
    return wiek;
}

COrganizm::~COrganizm()
{

}
