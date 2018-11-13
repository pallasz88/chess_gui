#include <string>
#include <iostream>
#include <QPointF>
#include "move.h"

Move::Move(QPointF startPosition, QPointF endPosition)
{
    move.push_back(static_cast<char>(static_cast<int>(startPosition.x() / 100) + 'a'));
    move.push_back(static_cast<char>(8 - static_cast<int>(startPosition.y() / 100) + '0'));
    move.push_back(static_cast<char>(static_cast<int>(endPosition.x() / 100) + 'a'));
    move.push_back(static_cast<char>(8 - static_cast<int>(endPosition.y() / 100) + '0'));
}

std::ostream& operator<<(std::ostream& os, const Move& move)
{
    os << move.move;
    return os;
}

Coordinates Move::GetFromCoordinates()
{
    return Coordinates(move[0]-'a', move[1]-'0');
}

Coordinates Move::GetToCoordinates()
{
    return Coordinates(move[2]-'a', move[3]-'0');
}
