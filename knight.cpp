#include "knight.h"

Knight::Knight(Piece *parent):
	Piece(parent)
{

}

void Knight::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/knight.png"));
}