#pragma once


#include "move.h"
#include <vector>

class History
{

public:

    static History& GetInstance();

    bool IsEmpty();

    void AddMoveToHistory(Move move);

    const Move& DeleteLastMove();

    void PrintMoveHistory();

    void SaveBoard(const std::vector<int> &board);

    const std::vector<int>& DeleteLastPosition();

private:

    History() = default;

    std::vector<Move> history;

    std::vector<std::vector<int>> boardHistory;

};