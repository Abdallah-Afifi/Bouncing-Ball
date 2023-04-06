#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog)
{
ui->setupUi(this);
scene = new QGraphicsScene(this);
ui->graphicsView->setScene(scene);
ui->graphicsView->setRenderHint(QPainter::Antialiasing);
scene->setSceneRect(-200,-200,300,300); // to be at center
QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );
// to create box
QPen mypen(Qt::red);
scene->addLine(TopLine,mypen);
scene->addLine(LeftLine,mypen);
scene->addLine(RightLine,mypen);
scene->addLine(BottomLine,mypen);
timer = new QTimer(this);
connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
timer->start(100);
item = new MyItem();
scene->addItem(item);

/*QBrush RedBrush(Qt::red);
QBrush BlueBrush(Qt::blue);
QPen Blackpen(Qt::black);
Blackpen.setWidth(6);
ellipse = scene->addEllipse(100, 100, 100, 100, Blackpen, BlueBrush);
rectangle = scene->addRect(10, 10, 100, 100, Blackpen, RedBrush);*/
}
Dialog::~Dialog() { delete ui; }


