#ifndef GRAFIKA_H
#define GRAFIKA_H

//#include <QObject>
//#include <QtGui>
//#include <QtCore>
#include <QGraphicsItem>
#include <QPainter>
#include "logika.h"

class CWyspa;
class COrganizm;
class CWilk;


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

class CGOrganizm : public QGraphicsItem
{
protected:
    int x;
    int y;
    COrganizm *organizm;
    QColor color;

public:
    CGOrganizm(COrganizm *o, QColor c=Qt::black);
    QRectF boundingRect() const;
    virtual void update();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
    virtual ~CGOrganizm()=0;
    COrganizm* getOrgnizm();
};

class CGWilk : public CGOrganizm
{
public:
    CGWilk(COrganizm *w, QColor c=Qt::red);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGWilk();
};

class CGOwca : public CGOrganizm
{
public:
    CGOwca(COrganizm *w, QColor c=Qt::blue);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~CGOwca();
};
#endif // GRAFIKA_H
