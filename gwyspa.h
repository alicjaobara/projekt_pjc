#ifndef GWYSPA_H
#define GWYSPA_H

#include "wyspa.h"

//class CWyspa;


class CGWyspa : public QGraphicsItem
{
    CWyspa *wyspa;
public:
    CGWyspa(CWyspa *w);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGWyspa();

};

#endif // GWYSPA_H
