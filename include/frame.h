#pragma once


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "piece.h"


class Frame : public QGraphicsView
{

    Q_OBJECT

public:

    explicit Frame(QWidget *parent = Q_NULLPTR);

public slots:

    void UpdateBoard();

private:

    QGraphicsScene *scene;

    std::vector<Piece*> pieces;

    void CreateSquares();

    void CreatePieces();

    void CreateScene();

};
