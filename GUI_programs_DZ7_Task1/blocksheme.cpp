#include "blocksheme.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

BlockSheme::BlockSheme(QObject *parent, int i) : QObject(parent), QGraphicsItem()
{
   x = 0;
   y = 0;
   brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
   brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
   geometry = (Geometry)i;
   setPos(0,0);
   moving = false;
   rotate = false;
   setFlag(QGraphicsItem::ItemIsMovable,true);
}

void BlockSheme::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   QPolygon poligon;
   //звезда пятиугольная
   //poligon<<QPoint(-100.0, 0.0)<<QPoint(-25.0, 0.0)<<QPoint(0.0, 75.0)<<QPoint(25.0, 0.0)<<QPoint(100.0, 0.0)<<QPoint(38.0, -38.0)<<QPoint(75.0, -125.0)<<QPoint(0.0, -75.0)<<QPoint(-75.0, -125.0)<<QPoint(-38.0, -38.0);
   //звезда четырехугольная(ромб)
   poligon<<QPoint(100,0)<<QPoint(0,100)<<QPoint(-100,0)<<QPoint(0,-100);
   painter->setBrush(brush);
   if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
   if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
   if (geometry == Geometry::STAR) painter->drawPolygon(poligon);
   Q_UNUSED(option)
   Q_UNUSED(widget)
}
/*
1. добавлять графические элементы щелчком левой кнопки мыши на пустой области окна
Добавляемыми элементами могут быть прямоугольник, эллипс, звезда
2.При щелчке правой кнопки мыши по элементу он должен удалиться.
3.Должна быть возможность перемещать элементы, с помощью зажатой левой кнопкой мыши.
*/
QRectF BlockSheme::boundingRect() const         // Обязателен для переопределения
{
    if (geometry == Geometry::ELLIPS || geometry == Geometry::RECTANGLE)
        return QRectF(x, y, 200, 100);                // Текущие координаты
    else
        return QRectF(x,y,80,80);
}

void BlockSheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

   if (event->button() == Qt::LeftButton)
   {
       moving = true;
       bpoint = event->pos().toPoint();

   }
   if (event->button() == Qt::RightButton)
   {
       this->deleteLater();
       emit reDraw();                            // переотрисовка
   }
   if (event->button() == Qt::MiddleButton)
   {
       rotate = true;
   }
}

void BlockSheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)
   {
       moving = false;                            // Снимаем флаг на перемещение
       emit reDraw();
   }
   if (event->button() == Qt::MiddleButton)
   {
       rotate = false;
   }
}

void BlockSheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (moving)                                    // Если активен флаг
                                                  // перемещения
   {
       QPoint p = event->pos().toPoint() - bpoint;
       x += p.x();
       y += p.y();
       bpoint = event->pos().toPoint();           // Запоминаем новую позицию
                                                  // курсора
       emit reDraw();                             // Переотрисовываем
   }
   if (rotate)
   {
       QPoint p = event->pos().toPoint() - bpoint;
       this->setRotation(this->rotation() + 10);
       emit reDraw();
   }
}

