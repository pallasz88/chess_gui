#pragma once


#include <QList>

class Piece;

class PiecePosition
{

public:

    explicit PiecePosition(QList<Piece*>);

    const QList<QPointF>& GetCurrentPosition() const;

private:

    QList<QPointF> currentPosition;

};
