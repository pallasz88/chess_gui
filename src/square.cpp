#include "history.h"
#include "frame.h"
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

void Square::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace &&
       !History::GetInstance().IsEmpty())
    {
        emit TakeBackOrdered();
    }
}