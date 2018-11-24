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
    for(const auto& move : moveList)
        std::cout << move << std::endl;

    for(auto& it : positionHistory)
        for(auto& itt : it.GetCurrentPosition())
            qDebug() << itt;
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
    pieceHistory.pop_back();
}

bool History::IsEmpty()
{
    return moveList.empty() || positionHistory.empty();
}

const QList<Piece *> & History::GetPieces() const
{
    return pieceHistory.back();
}

PiecePosition History::GetLastPosition() const
{
    return positionHistory.first();
}

void History::SaveBoard(const QList<Piece*>& pieces)
{
    PiecePosition position(pieces);
    positionHistory.insert(pieces, position);
    pieceHistory.push_back(pieces);
}