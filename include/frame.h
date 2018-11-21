#pragma once


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

class Piece;

class Frame : public QGraphicsView
{

    Q_OBJECT

public:

    explicit Frame(QWidget *parent = Q_NULLPTR);

	const QList<Piece*>& GetPieces() const;

public slots:

    void UpdateBoard();

private:

    QGraphicsScene *scene;

    QList<Piece*> pieces;

    void CreateSquares();

    void CreatePieces();

    void CreateScene();

	QList<int> board =
	{
		4, 2, 3, 5, 6, 3, 2, 4,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		-1,-1,-1,-1,-1,-1,-1,-1,
		-4,-2,-3,-5,-6,-3,-2,-4
	};

};
