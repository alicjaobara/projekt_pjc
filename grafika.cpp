#include "grafika.h"

CGObiekt::CGObiekt(CObiekt *o)
{
    obiekt = o;
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

CGDrzewo::CGDrzewo(CObiekt *w):CGObiekt(w)
{
    color = QColor(50, 204, 50, 255);
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

CGSkala::CGSkala(CObiekt *w):CGObiekt(w)
{
    color = QColor(100, 100, 100, 255);
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



CGOrganizm::CGOrganizm(CObiekt *o):CGObiekt(o)
{
}

CGOrganizm::~CGOrganizm()
{
}

CGWilk::CGWilk(CObiekt *w):CGOrganizm(w)
{

}

void CGWilk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QImage image(":/rys/wolf.png");
    painter->drawImage(rect,image);
}

CGWilk::~CGWilk()
{

}

CGOwca::CGOwca(CObiekt *w):CGOrganizm(w)
{

}

void CGOwca::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QImage image(":/rys/sheep.png");
    painter->drawImage(rect,image);
}

CGOwca::~CGOwca()
{

}

CGZajac::CGZajac(CObiekt *w):CGOrganizm(w)
{

}

void CGZajac::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QImage image(":/rys/rabbit.png");
    painter->drawImage(rect,image);
}

CGZajac::~CGZajac()
{

}

CGLis::CGLis(CObiekt *w):CGOrganizm(w)
{

}

void CGLis::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QImage image(":/rys/fox.png");
    painter->drawImage(rect,image);
}

CGLis::~CGLis()
{

}
