#include "history.h"
#include "piece.h"
#include "move.h"
#include "position.h"
#include <QDebug>

History &History::GetInstance()
{
    static History instance;
    return instance;
}

void History::AddMoveToHistory(Move& move)
{
    moveList.push_back(move);
}

void History::PrintMoveHistory()
{
    foreach(const auto& move, moveList)
        std::cout << move << std::endl;
}

const Move& History::DeleteLastMove()
{
    Move& lastMove = moveList.back();
    moveList.pop_back();
    return lastMove;
}

void History::DeleteLastPosition()
{
    positionHistory.erase(positionHistory.end());
}

bool History::IsEmpty()
{
    return moveList.empty() || positionHistory.empty();
}

PiecePosition History::GetLastPosition() const
{
    return positionHistory.first();
}

void History::SaveBoard(const QList<Piece*>& pieces)
{
    PiecePosition position(pieces);
    positionHistory.insert(pieces, position);
}