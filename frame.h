#ifndef FRAME_H
#define FRAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "piece.h"

class Frame : public QGraphicsView
{

    Q_OBJECT

public:

    explicit Frame(QWidget *parent =  Q_NULLPTR);

private:

    QGraphicsScene *scene;
	static QMap<Piece::Pieces, QImage> img;

};

#endif // FRAME_H
