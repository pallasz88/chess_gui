#ifndef FRAME_H
#define FRAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "piece.h"

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

#endif // FRAME_H
