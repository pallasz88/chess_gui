#include "pawn.h"

Pawn::Pawn(Piece *parent) :
	Piece(parent)
{

}

void Pawn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/pawn.png"));
}