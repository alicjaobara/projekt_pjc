#include "grafika.h"

CGObiekt::CGObiekt(CObiekt *o, QColor c)
{
    obiekt = o;
    color = c;
    setPos(obiekt->getx(),obiekt->gety());
}

QRectF CGObiekt::boundingRect() const
{
    return QRectF(0,0,obiekt->getw(),obiekt->geth());
}

void CGObiekt::update()
{
    setPos(obiekt->getx(),obiekt->gety());
}

CObiekt *CGObiekt::getObiekt()
{
    return obiekt;
}

CGObiekt::~CGObiekt()
{
//    delete obiekt;
}

CGDrzewo::CGDrzewo(CObiekt *w, QColor c):CGObiekt(w,c)
{

}

void CGDrzewo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(color, 1);
    painter->setPen(pen);
    QPainterPath ellipsePath;
    ellipsePath.arcTo(rect, 0.0, 360.0);
    painter->fillPath(ellipsePath,color);
}

CGDrzewo::~CGDrzewo()
{

}

CGSkala::CGSkala(CObiekt *w, QColor c):CGObiekt(w,c)
{

}

void CGSkala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(color, 1);
    painter->setPen(pen);
    QPainterPath ellipsePath;
    ellipsePath.arcTo(rect, 0.0, 360.0);
    painter->fillPath(ellipsePath,color);
}

CGSkala::~CGSkala()
{

}

CGWyspa::CGWyspa(CWyspa *w)
{
    wyspa=w;
}

QRectF CGWyspa::boundingRect() const
{
    return QRectF(0,0,wyspa->getx(),wyspa->gety());
}

void CGWyspa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(colWyspa, 1);
    painter->setPen(pen);
    painter->drawRect(rect);
    painter->fillRect(rect, colWyspa);
}

CGWyspa::~CGWyspa()
{
    delete wyspa;
}

CGOrganizm::CGOrganizm(CObiekt *o,  QColor c):CGObiekt(o,c)
{
}

CGOrganizm::~CGOrganizm()
{
}

CGWilk::CGWilk(CObiekt *w, QColor c):CGOrganizm(w,c)
{

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

}

CGOwca::CGOwca(CObiekt *w, QColor c):CGOrganizm(w,c)
{

}

void CGOwca::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(color, 1);
    painter->setPen(pen);
    QPainterPath ellipsePath;
    ellipsePath.arcTo(rect, 0.0, 360.0);
    painter->fillPath(ellipsePath,color);
}

CGOwca::~CGOwca()
{

}
