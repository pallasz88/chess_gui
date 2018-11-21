#include "history.h"
#include "piece.h"
#include "frame.h"
#include "move.h"
#include <iostream>
#include <qdebug.h>

History &History::GetInstance()
{
    static History instance;
    return instance;
}

void History::AddMoveToHistory(Move& move)
{
    history.push_back(move);
}

void History::PrintMoveHistory()
{
    for(const auto& move : history)
        std::cout << move << std::endl;
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
    currentPosition = boardHistory.back();
	for(const auto& it : currentPosition)
		qDebug() << it->pos();
}

bool History::IsEmpty()
{
    return history.empty() || boardHistory.empty();
}

void History::SaveBoard(const QList<Piece*>& pieces)
{
    boardHistory.push_back(pieces);
	currentPosition = pieces;
	for (const auto& it : currentPosition)
		qDebug() << "Save board: " << it->pos();
}

const QList<Piece*>& History::GetBoard()
{
	for (const auto& it : currentPosition)
		qDebug() << "Get board:" << it->pos();
    return currentPosition;
}

History::History()
{
    //SaveBoard();
}
