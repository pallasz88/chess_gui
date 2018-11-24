#pragma once


#include <QList>

class Piece;

class Move;

class PiecePosition;

class History
{

public:

    static History& GetInstance();

	const QList<Piece*>& GetPieces() const;

	PiecePosition GetLastPosition() const;

    bool IsEmpty();

    void AddMoveToHistory(Move& move);

    void PrintMoveHistory();

    const Move& DeleteLastMove();

    void DeleteLastPosition();

    void SaveBoard(const QList<Piece*>&);

private:

    QList<Move> moveList;

    QMap<QList<Piece*>, PiecePosition> positionHistory;

    QList<QList<Piece*>> pieceHistory;

};