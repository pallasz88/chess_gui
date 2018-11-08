#include "queen.h"

Queen::Queen(Piece *parent) :
	Piece(parent)
{

}

void Queen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/queen.png"));
}