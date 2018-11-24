#include "position.h"
#include "piece.h"

PiecePosition::PiecePosition(QList<Piece *> pieces)
{
    for(const auto& piece : pieces)
        currentPosition.push_back(piece->pos());
}

const QList<QPointF>& PiecePosition::GetCurrentPosition() const
{
    return currentPosition;
}