#pragma once


#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Piece;

class Move;

class History : public QObject
{

    Q_OBJECT

public:

    static History& GetInstance();

	const QList<Piece*>& GetBoard();

    bool IsEmpty();

    void AddMoveToHistory(Move& move);

    void PrintMoveHistory();

    void SaveBoard(const QList<Piece*>&);

public slots:

    const Move& DeleteLastMove();

    void DeleteLastPosition();

private:

    History();

    QList<Move> history;

    QList<Piece*> currentPosition;

	QList<QList<Piece*>> boardHistory;

};