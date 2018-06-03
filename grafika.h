#ifndef GRAFIKA_H
#define GRAFIKA_H

//#include <QObject>
//#include <QtGui>
//#include <QtCore>
#include <QGraphicsItem>
#include <QPainter>
#include "logika.h"
#include "stale.h"

class CWyspa;
class COrganizm;
//class CWilk;
class CObiekt;

class CGObiekt : public QGraphicsItem
{
protected:
    CObiekt *obiekt;
    QColor color;
public:
    CGObiekt(CObiekt *o, QColor c = colObiekt);
    QRectF boundingRect() const;
    virtual void update();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
    virtual ~CGObiekt()=0;
    CObiekt* getObiekt();
};

class CGDrzewo :public CGObiekt
{
public:
    CGDrzewo(CObiekt *w, QColor c = colDrzewo);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGDrzewo();
};

class CGSkala :public CGObiekt
{
public:
    CGSkala(CObiekt *w, QColor c = colSkala);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGSkala();
};


class CGWyspa : public QGraphicsItem
{
public:
    CGWyspa(CWyspa *w);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGWyspa();

private:
    CWyspa *wyspa;
};

class CGOrganizm : public CGObiekt
{
public:
    CGOrganizm(CObiekt *o, QColor c = colOrganizm);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
    virtual ~CGOrganizm()=0;
};

class CGWilk : public CGOrganizm
{
public:
    CGWilk(CObiekt *w, QColor c = colWilk);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGWilk();
};

class CGOwca : public CGOrganizm
{
public:
    CGOwca(CObiekt *w, QColor c = colOwca);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGOwca();
};


#endif // GRAFIKA_H
