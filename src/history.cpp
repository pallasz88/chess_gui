#include "frame.h"
#include "move.h"
#include "piece.h"
#include <iostream>
#include "history.h"

History &History::GetInstance()
{
    static History instance;
    return instance;
}

void History::AddMoveToHistory(Move move)
{
    history.push_back(move);
}

void History::PrintMoveHistory()
{
    for(const auto& move : history)
    {
        std::cout << move << std::endl;
    }
}

const Move& History::DeleteLastMove()
{
    Move& lastMove = history.back();
    history.pop_back();
    return lastMove;
}

void History::DeleteLastPosition()
{
    boardHistory.pop_back();
}

bool History::IsEmpty()
{
    return history.empty() || boardHistory.empty();
}

void History::SaveBoard()
{
    boardHistory.push_back(board);
}

void History::UpdateBoard(Move &move)
{
    int piece = board[move.GetFromCoordinates().y * 8 + move.GetFromCoordinates().x];
    board[move.GetToCoordinates().y * 8 + move.GetToCoordinates().x] = piece;
    board[move.GetFromCoordinates().y * 8 + move.GetFromCoordinates().x] = 0;

    SaveBoard();
}

std::vector<int> &History::GetBoard()
{
    return boardHistory.back();
}

History::History()
{
    SaveBoard();
}
