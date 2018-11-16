#pragma once


#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QCursor>


class Move;

class Piece : public QObject, public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    enum class PieceTypes : int
    {
        King = -6, Queen, Rook, Bishop, Knight, Pawn,
        BPawn = 1, BKnight, BBishop, BRook, BQueen, BKing
    };

    explicit Piece(PieceTypes pieceType, QPointF offset, QObject *parent = Q_NULLPTR);

private:

    QImage pieceImage;

    QPointF startPosition;

    bool IsOffBoard(QGraphicsSceneMouseEvent *event) const;

    void SetPieceImage(PieceTypes);

    void ResetPosition();

    void DeleteCapturedPieces() const;

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    bool IsPieceOnBoard(QGraphicsItem *const &item) const;

    void MovePieceToSquare(const QGraphicsSceneMouseEvent *event);

    void SaveStartPosition(const QGraphicsSceneMouseEvent *event);

    void GrabPieceCentroid(const QGraphicsSceneMouseEvent *event);

};
