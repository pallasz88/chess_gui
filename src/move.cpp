#include "move.h"
#include "adapter.h"

Move::Move(QPointF startPosition, QPointF endPosition)
{
    move.push_back(static_cast<char>(static_cast<int>(startPosition.x() / 100) + 'a'));
    move.push_back(static_cast<char>(8 - static_cast<int>(startPosition.y() / 100) + '0'));
    move.push_back(static_cast<char>(static_cast<int>(endPosition.x() / 100) + 'a'));
    move.push_back(static_cast<char>(8 - static_cast<int>(endPosition.y() / 100) + '0'));
}

bool Move::IsValid()
{
    return Chess::IsValidMove(move);
}

std::ostream& operator<<(std::ostream& os, const Move& move)
{
    os << move.move;
    return os;
}
