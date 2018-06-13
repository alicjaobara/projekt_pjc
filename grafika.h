#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <QGraphicsItem>
#include <QPainter>
#include "obiekt.h"
#include "stale.h"

//class COrganizm;
class CObiekt;

class CGObiekt : public QGraphicsItem
{
protected:
    CObiekt *obiekt;
public:
    CGObiekt(CObiekt *o);
    QRectF boundingRect() const;
    virtual void update();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)=0;
    CObiekt* getObiekt();
    virtual ~CGObiekt()=0;
};

class CGDrzewo :public CGObiekt
{
    QColor color;
public:
    CGDrzewo(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGDrzewo();
};

class CGSkala :public CGObiekt
{
    QColor color;
public:
    CGSkala(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGSkala();
};

class CGOrganizm : public CGObiekt
{
public:
    CGOrganizm(CObiekt *o);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)=0;
    virtual ~CGOrganizm()=0;
};

class CGWilk : public CGOrganizm
{
public:
    CGWilk(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGWilk();
};

class CGOwca : public CGOrganizm
{
public:
    CGOwca(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGOwca();
};

class CGZajac : public CGOrganizm
{
public:
    CGZajac(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGZajac();
};

class CGLis : public CGOrganizm
{
public:
    CGLis(CObiekt *w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    ~CGLis();
};

#endif // GRAFIKA_H
