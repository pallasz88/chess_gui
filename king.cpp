#include "king.h"

King::King(Piece *parent) :
	Piece(parent)
{

}

void King::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/king.png"));
}