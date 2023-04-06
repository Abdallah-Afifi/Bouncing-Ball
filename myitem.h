#ifndef MYITEM_H
#define MYITEM_H

#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>


class MyItem : public QGraphicsItem // add this inheritance
{
public:
    MyItem();
QRectF boundingRect() const;
void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget*
widget);
protected:
void advance(int phase);
//timer in .h will fire timeout scene and will tell how many phases in advance
private:
qreal angle;
qreal speed; // speed of our object
void doCollison();// we will create func to do anything when object hit another one
};

#endif // MYITEM_H
