#pragma once

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QCursor>

class Piece : public QObject, public QGraphicsItem
{

	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)

public:

	enum class Pieces : int
	{
		King = -6, Queen, Rook, Bishop, Knight, Pawn,
        BPawn = 1, BKnight, BBishop, BRook, BQueen, BKing
	};

    explicit Piece(Pieces pieceType, QObject *parent = Q_NULLPTR);

private:

	void SetPieceImage(Pieces);

	QRectF boundingRect() const override;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

	QImage pieceImage;

};
