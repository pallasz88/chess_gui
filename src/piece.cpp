#include "piece.h"
#include "move.h"
#include "history.h"
#include "frame.h"
#include <limits>

Piece::Piece(PieceTypes pieceType, QPointF offset, QObject *parent) :
    QObject(parent),
    startPosition(offset)
{
	this->pieceType = pieceType;
	this->zPosition = zValue();
    SetPieceImage(pieceType);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
    setPos(startPosition);
	parentFrame = (Frame*)parent;
}

bool Piece::IsOffBoard(QGraphicsSceneMouseEvent *event) const
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

void Piece::SetPieceImage(PieceTypes pieceType)
{
    pieceImage = (pieceType == PieceTypes::King)    ? QImage(":/images/king.png") :
                 (pieceType == PieceTypes::Queen)   ? QImage(":/images/queen.png"):
                 (pieceType == PieceTypes::Rook)    ? QImage(":/images/rook.png"):
                 (pieceType == PieceTypes::Bishop)  ? QImage(":/images/bishop.png"):
                 (pieceType == PieceTypes::Knight)  ? QImage(":/images/knight.png"):
                 (pieceType == PieceTypes::Pawn)    ? QImage(":/images/pawn.png"):
                 (pieceType == PieceTypes::BKing)   ? QImage(":/images/bking.png") :
                 (pieceType == PieceTypes::BQueen)  ? QImage(":/images/bqueen.png"):
                 (pieceType == PieceTypes::BRook)   ? QImage(":/images/brook.png"):
                 (pieceType == PieceTypes::BBishop) ? QImage(":/images/bbishop.png"):
                 (pieceType == PieceTypes::BKnight) ? QImage(":/images/bknight.png"):
                 (pieceType == PieceTypes::BPawn)   ? QImage(":/images/bpawn.png"): QImage("");
}

Piece::PieceTypes Piece::GetPieceType() const
{
	return pieceType;
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
    SaveStartPosition(event);
    GrabPieceCentroid(event);
    setZValue(std::numeric_limits<int>::max());
}

void Piece::GrabPieceCentroid(const QGraphicsSceneMouseEvent *event) {
    setPos(mapToParent(event->pos()).x() - 50,
           mapToParent(event->pos()).y() - 50);
}

void Piece::SaveStartPosition(const QGraphicsSceneMouseEvent *event) {
    startPosition = QPointF((int)(mapToParent(event->pos()).x() / 100) * 100,
                            (int)(mapToParent(event->pos()).y() / 100) * 100);
}

void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    setCursor(Qt::OpenHandCursor);
    setZValue(zPosition);

    if (IsOffBoard(event))
    {
        ResetPosition();
        return;
    }

    Move move(startPosition, mapToParent(event->pos()));
    if(!move.IsValid())
        return;

    MovePieceToSquare(event);
    DeleteCapturedPiece();
    History::GetInstance().AddMoveToHistory(move);
    History::GetInstance().SaveBoard(parentFrame->GetPieces());
    History::GetInstance().PrintMoveHistory();
}

void Piece::MovePieceToSquare(const QGraphicsSceneMouseEvent *event)
{
    setPos((int) (mapToParent(event->pos()).x() / 100) * 100,
           (int) (mapToParent(event->pos()).y() / 100) * 100);
}

void Piece::DeleteCapturedPiece() const
{
    QList<QGraphicsItem*> collidingItemList = collidingItems();
    for (const auto& it : collidingItemList)
		if (it != this && IsPieceOnBoard(it))
		{
			it->hide();
			scene()->removeItem(it);
		}
}

bool Piece::IsPieceOnBoard(QGraphicsItem *const &item) const
{
    return item->flags() == ItemIsMovable;
}

void Piece::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverEnterEvent(event);
    setCursor(Qt::OpenHandCursor);
}

void Piece::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverLeaveEvent(event);
    setCursor(Qt::ArrowCursor);
}