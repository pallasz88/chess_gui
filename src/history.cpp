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

void History::RestoreBoard(QGraphicsScene *scene)
{
	QSettings settings("Moose Soft", "Facturo-Pro");
	foreach(QVariant data, settings.value("items").toList())
	{
		QGraphicsItem* item = ConvertToItem(data);
		scene->addItem(item);
	}
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

bool History::IsEmpty()
{
    return moveList.empty();
}

QVariant History::ConvertToVariant(Piece* item)
{
	QVariantHash data;
	data["pos"] = item->pos();
	data["visibility"] = item->isVisible();
	data["type"] = (int)item->GetPieceType();
	return data;
}

Piece* History::ConvertToItem(QVariant variant)
{
	QVariantHash data = variant.toHash();
	Piece* result = new Piece((Piece::PieceTypes)data["type"].toInt(), data["pos"].toPointF());
	result->setPos(data["pos"].toPointF());
	result->setVisible(data["visible"].toBool());
	return result;
}

void History::SaveBoard(const QList<Piece*>& pieces)
{
	QVariantList pieceList;
	QSettings settings("Moose Soft", "Facturo-Pro");
	foreach (Piece* piece, pieces)
		pieceList << ConvertToVariant(piece);
	
	settings.setValue("items", pieceList);
	qDebug() << settings.value("items").toList().at(0);
}