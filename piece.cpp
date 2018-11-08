#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

Piece::Piece(QObject *parent) :
	QObject(parent)
{
	setFlag(QGraphicsItem::ItemIsMovable);
}

void Piece::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	return;
}

Piece * Piece::createPiece(Pieces piece)
{
	if (piece == Pieces::Knight)
		return new Knight;

	else if (piece == Pieces::Bishop)
		return new Bishop;

	else if (piece == Pieces::Pawn)
		return new Pawn;

	else if (piece == Pieces::Rook)
		return new Rook;

	else if (piece == Pieces::Queen)
		return new Queen;

	else if (piece == Pieces::King)
		return new King;

	else
		return new Pawn;

	throw "Not a valid piece";
}

QRectF Piece::boundingRect() const
{
	return QRectF(0, 0, 100, 100);
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mousePressEvent(event);
	setCursor(Qt::ClosedHandCursor);
}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsItem::mouseReleaseEvent(event);
	setCursor(Qt::ArrowCursor);
}