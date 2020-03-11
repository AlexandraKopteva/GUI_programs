#ifndef BLOCKSHEME_H
#define BLOCKSHEME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QContextMenuEvent>
#include <QBrush>

class BlockSheme : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)

public:
    explicit BlockSheme(QObject *parent = nullptr, int i=0);
    void setBrush(QBrush brush) {this->brush = brush; emit reDraw();}
 signals:
    void reDraw();
    void dblClick();
 private:
    void removeItem(QGraphicsItem * item );
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    enum Geometry {RECTANGLE, ELLIPS, STAR};
    int x, y;
    Geometry geometry;
    QPoint bpoint;
    QBrush brush;
    bool rotate;
    bool moving;
 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};
#endif // BLOCKSHEME_H
