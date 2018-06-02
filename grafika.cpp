#include "grafika.h"

CGWyspa::CGWyspa(CWyspa *w)
{
    cout<<"CGWyspa"<<endl;
    wyspa=w;
}

QRectF CGWyspa::boundingRect() const
{
    return QRectF(0,0,wyspa->getx(),wyspa->gety());
}

void CGWyspa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawRect(rect);
}

CGWyspa::~CGWyspa()
{
    cout<<"~CGWyspa"<<endl;
    delete wyspa;
}

CGOrganizm::CGOrganizm(COrganizm *o,  QColor c)
{
    cout<<"CGOrganizm"<<endl;
    organizm = o;
    x=organizm->getx();
    y=organizm->gety();
    color = c;
    setPos(x,y);
}

QRectF CGOrganizm::boundingRect() const
{
    return QRectF(0,0,5,5);
}

void CGOrganizm::update()
{
    cout<<"update CGOrganizm"<<endl;
    x=organizm->getx();
    y=organizm->gety();
    setPos(x,y);
}

COrganizm *CGOrganizm::getOrgnizm()
{
    return organizm;
}

CGOrganizm::~CGOrganizm()
{

    delete organizm;
    cout<<"~CGOrganizm"<<endl;
}

CGWilk::CGWilk(COrganizm *w, QColor c):CGOrganizm(w,c)
{
    cout<<"CGWilk"<<endl;
}

void CGWilk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(color, 1);
    painter->setPen(pen);
    painter->drawRect(rect);
    painter->fillRect(rect, color);
}

CGWilk::~CGWilk()
{
    cout<<"~CGWilk"<<endl;
}

CGOwca::CGOwca(COrganizm *w, QColor c):CGOrganizm(w,c)
{
    cout<<"CGOwca"<<endl;
}

void CGOwca::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(color, 1);
    painter->setPen(pen);
    painter->drawEllipse(rect);
//    painter->fillEllipse(rect, color);
}

CGOwca::~CGOwca()
{
    cout<<"~CGWilk"<<endl;
}
