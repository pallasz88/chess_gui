#include "rook.h"

Rook::Rook(Piece *parent) :
	Piece(parent)
{

}

void Rook::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/rook.png"));
}
