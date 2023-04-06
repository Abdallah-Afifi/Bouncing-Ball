#include "myitem.h"


MyItem::MyItem() {
// random start rotation
angle = (qrand() % 360);
setRotation(angle); // set the speed
speed = 5; // go 5 pixels at a time
// random start position
int StartX = 0;
int StartY = 0;
if ((qrand() % 1)) {
StartX = (qrand() % 200);
StartY = (qrand() % 200);
}
else {
StartX = (qrand() % -100);
StartY = (qrand() % -100);
}// to be very random
setPos(mapToParent(StartX, StartY));
}

QRectF MyItem::boundingRect() const
{
return QRect(0, 0, 20, 20);
}
void MyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget*
widget)//painting it
{
QRectF rec = boundingRect(); // grabbing the 0 0 20 20
QBrush Brush(Qt::gray); // we will add here some basic collision detection
if (scene()->collidingItems(this).isEmpty()) {
//no collision
Brush.setColor(Qt::green);
}
else {
//collision
Brush.setColor(Qt::red);
// set the new position
doCollison();
}
painter->fillRect(rec, Brush);
painter->drawRect(rec); //very simple object
}


void MyItem::advance(int phase)//advancing the position
{
if (!phase)return; // if just calling it with no phase
QPointF location = this->pos(); // we want the current location of this object
setPos(mapToParent(0, -(speed)));// set the current x y to the scene x y
}

void MyItem::doCollison()
{
// Get a new posistion
if ((qrand() % 1))
{
// if it hits something spin it around in the opposite direction
setRotation(rotation() + (180 + (qrand() % 10)));//rotation gets current rotation
}
else {
setRotation(rotation() + (180 + (qrand() % -10)));
}
// add some checking , check if new wposition is in bounds
QPointF newpoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()+ 2));
// + 2 to push it away from the object it is colliding with
if(!scene()->sceneRect().contains(newpoint)) {
// move it back in bounds
newpoint = mapToParent(0, 0);
}
else
{ setPos(newpoint); //set the new position
}
}
