#pragma once


#include "move.h"
#include <vector>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class History : public QObject
{

    Q_OBJECT

public:

    static History& GetInstance();

    std::vector<int>& GetBoard();

    bool IsEmpty();

    void AddMoveToHistory(Move move);

    void PrintMoveHistory();

    void SaveBoard();

    void UpdateBoard(Move&);

public slots:

    const Move& DeleteLastMove();

    void DeleteLastPosition();

signals:

    void BoardChanged(std::vector<int> board);

private:

    History();

    std::vector<Move> history;

    std::vector<std::vector<int>> boardHistory;

    std::vector<int> board =
    {
        4, 2, 3, 5, 6, 3, 2, 4,
        1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
       -1,-1,-1,-1,-1,-1,-1,-1,
       -4,-2,-3,-5,-6,-3,-2,-4
    };

};