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

bool History::IsEmpty()
{
    return history.empty() || boardHistory.empty();
}

void History::SaveBoard(const std::vector<int> &board)
{
    boardHistory.push_back(board);
}

const std::vector<int> &History::DeleteLastPosition()
{
    const std::vector& board = boardHistory.back();
    boardHistory.pop_back();
    return board;
}
