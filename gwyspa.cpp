#include "gwyspa.h"

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
    QColor colWyspa = QColor(114, 202, 114, 55);
    QRectF rect = boundingRect();
    QPen pen(colWyspa, 1);
    painter->setPen(pen);
    painter->drawRect(rect);
    painter->fillRect(rect, colWyspa);
}

CGWyspa::~CGWyspa()
{
//    delete wyspa;
}
