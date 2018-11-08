#include "square.h"

Square::Square(QBrush brush, QGraphicsItem* parent) :
	QGraphicsItem(parent),
	brush(brush)
{
	
}


QRectF Square::boundingRect() const
{
	return QRectF(0, 0, 100, 100);
}

void Square::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setBrush(brush);
	painter->drawRect(0, 0, 100, 100);
}
