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

private:

    void CreateSquares();

    void CreatePieces();

    void CreateScene();

    void keyPressEvent(QKeyEvent* event) override;

    void UpdateBoard();

    QGraphicsScene *scene;

    QList<Piece*> pieces;

    std::string fenPosition;

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
