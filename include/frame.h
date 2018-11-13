#pragma once


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "piece.h"

static std::vector<int> board =
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

class Frame : public QGraphicsView
{

    Q_OBJECT

public:

    explicit Frame(QWidget *parent = Q_NULLPTR);

private:

    QGraphicsScene *scene;

    void CreateSquares();

    void CreatePieces();

    void CreateScene();

};
