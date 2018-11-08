#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsItem>
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>

class Piece : public QObject, public QGraphicsItem
{

	Q_OBJECT

public:

	enum class Pieces : int
	{
		King = -6, Queen, Rook, Bishop, Knight, Pawn
	};

	static Piece* createPiece(Pieces);

protected:

	explicit Piece(QObject *parent = nullptr);

	QRectF boundingRect() const override;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // PIECE_H
