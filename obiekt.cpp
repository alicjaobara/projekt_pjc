#include "obiekt.h"

bool sprawdzxy0(int x, int y, int w, int h, vector<CObiekt*> ob)
{
    for (int i=0; i<ob.size(); i++)
    {
        if(ob.at(i)->getkontakt()==-1)
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



CObiekt::CObiekt(int x, int y, int w, int h, int kontakt)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->kontakt = kontakt;
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

