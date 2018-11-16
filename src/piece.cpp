#include <iostream>
#include "piece.h"
#include "move.h"
#include "history.h"
#include "frame.h"

Piece::Piece(PieceTypes pieceType, QPointF offset, QObject *parent) :
    QObject(parent),
    startPosition(offset)
{
    SetPieceImage(pieceType);
    setFlag(QGraphicsItem::ItemIsMovable);
    setPos(startPosition);
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
    setCursor(Qt::ArrowCursor);

    if (IsOffBoard(event))
    {
        ResetPosition();
        return;
    }

    Move move(startPosition, mapToParent(event->pos()));
    if(!move.IsValid())
        return;

    MovePieceToSquare(event);
    DeleteCapturedPieces();
    History::GetInstance().AddMoveToHistory(move);
    History::GetInstance().UpdateBoard(move);
}

void Piece::MovePieceToSquare(const QGraphicsSceneMouseEvent *event)
{
    setPos((int) (mapToParent(event->pos()).x() / 100) * 100,
           (int) (mapToParent(event->pos()).y() / 100) * 100);
}

void Piece::DeleteCapturedPieces() const
{
    QList<QGraphicsItem *> collidingItemList = collidingItems();
    for (const auto& it : collidingItemList)
        if (it != this && IsPieceOnBoard(it))
            scene()->removeItem(it);
}

bool Piece::IsPieceOnBoard(QGraphicsItem *const &item) const
{
    return item->flags() == ItemIsMovable;
}

