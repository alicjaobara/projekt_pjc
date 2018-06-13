#include "drzewo.h"

CDrzewo::CDrzewo(int x, int y, int wiek, int w, int h, int kontakt):CObiekt(x,y,w,h,kontakt)
{
    this->wiek=wiek;
}

int CDrzewo::update(int x, int y, vector<CObiekt *>& ob, vector<CGObiekt *>& gob, int t)
{
    wiek++;
    if (wiek >= 4*life)
    {
        return t;
    }
    else
    {
        int l=rand()%1000;
        if (l%200 == 0) //rośnie
        {
            int xo,yo;
            int l2=rand()%3;
            do
            {
                switch (l2) {
                case 0:
                    xo=this->x+5;
                    yo=this->y+5;
                    break;
                case 1:
                    xo=this->x+5;
                    yo=this->y-5;
                    break;
                case 2:
                    xo=this->x-5;
                    yo=this->y+5;
                    break;
                case 3:
                    xo=this->x-5;
                    yo=this->y-5;
                    break;
                default:
                    break;
                }
            }
            while (!sprawdzxy0(xo, yo, w, h, ob));
            if (xo >= x-w) xo = x-w;
            else if (xo < 0) xo = 0;
            if (yo >= y-h) yo = y-h;
            else if (yo < 0) yo = 0;
            CObiekt *wsk = new CDrzewo(xo,yo,1);
            CGObiekt *gwsk = new CGDrzewo(wsk);
            ob.push_back(wsk);
            gob.push_back(gwsk);
        }
        return -1;
    }
}

int CDrzewo::gettyp()
{
    return 0;
}

int CDrzewo::getwiek()
{
    return wiek;
}


