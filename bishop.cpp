#include "bishop.h"

Bishop::Bishop(Piece *parent):
	Piece(parent)
{

}

void Bishop::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawImage(boundingRect(), QImage(":/images/bishop.png"));
}