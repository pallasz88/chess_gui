#pragma once


#include <QStack>
#include <QVariant>
#include <QGraphicsItem>
#include <QSettings>
#include <QGraphicsScene>

class Piece;

class Move;

class PiecePosition;

Q_DECLARE_METATYPE(QList<Piece*>)

class History
{

public:

    static History& GetInstance();

	void RestoreBoard(QGraphicsScene *scene);

    bool IsEmpty();

    void AddMoveToHistory(Move& move);

    void PrintMoveHistory();

    const Move& DeleteLastMove();

    void SaveBoard(const QList<Piece*>&);

private:

	History() = default;

	History(const History&) = delete;

	History& operator=(const History&) = delete;

	QVariant ConvertToVariant(Piece* item);

	Piece* ConvertToItem(QVariant variant);

    QList<Move> moveList;

};