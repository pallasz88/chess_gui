#include "piece.h"

Piece::Piece(Pieces pieceType, QPointF offset, QObject *parent) :
	QObject(parent),
	startPosition(offset)
{
	SetPieceImage(pieceType);
	setFlag(QGraphicsItem::ItemIsMovable);
	setPos(startPosition);
}

bool Piece::IsOffBoard(QGraphicsSceneMouseEvent *event)
{
	return (mapToParent(event->pos()).x() > 799 || 
			mapToParent(event->pos()).y() > 799 ||
			mapToParent(event->pos()).x() < 0 ||
			mapToParent(event->pos()).y() < 0);
}

void Piece::ResetPosition()
{
	setPos(startPosition);
}

void Piece::SetPieceImage(Pieces pieceType)
{
	pieceImage = (pieceType == Pieces::King)    ? QImage(":/images/king.png") :
                 (pieceType == Pieces::Queen)   ? QImage(":/images/queen.png"):
                 (pieceType == Pieces::Rook)    ? QImage(":/images/rook.png"):
                 (pieceType == Pieces::Bishop)  ? QImage(":/images/bishop.png"):
                 (pieceType == Pieces::Knight)  ? QImage(":/images/knight.png"):
                 (pieceType == Pieces::Pawn)    ? QImage(":/images/pawn.png"):
                 (pieceType == Pieces::BKing)   ? QImage(":/images/bking.png") :
                 (pieceType == Pieces::BQueen)  ? QImage(":/images/bqueen.png"):
                 (pieceType == Pieces::BRook)   ? QImage(":/images/brook.png"):
                 (pieceType == Pieces::BBishop) ? QImage(":/images/bbishop.png"):
                 (pieceType == Pieces::BKnight) ? QImage(":/images/bknight.png"):
                 (pieceType == Pieces::BPawn)   ? QImage(":/images/bpawn.png"): QImage("");
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->drawImage(boundingRect(), pieceImage);
}

QRectF Piece::boundingRect() const
{
	return QRectF(0, 0, 100, 100);
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mousePressEvent(event);
	setCursor(Qt::ClosedHandCursor);
	startPosition = QPointF((int)(mapToParent(event->pos()).x() / 100) * 100, (int)(mapToParent(event->pos()).y() / 100) * 100);
	setPos(mapToParent(event->pos()).x() - 50, mapToParent(event->pos()).y() - 50);
}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
    QGraphicsItem::mouseReleaseEvent(event);

	if (IsOffBoard(event))
	{
		ResetPosition();
		return;
	}

    setPos((int) (mapToParent(event->pos()).x() / 100) * 100,
           (int) (mapToParent(event->pos()).y() / 100) * 100);

	QList<QGraphicsItem *> list = collidingItems();
	for (const auto& it : list)
	{
		if (it != this && it->flags() == ItemIsMovable)
		{
			delete it;
		}
	}
}