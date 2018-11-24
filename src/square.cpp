#include "square.h"

Square::Square(QBrush brush, QGraphicsItem *parent) :
    QGraphicsItem(parent),
    brush(brush)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF Square::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
}