#pragma once

#include "piece.h"

class Pawn : public Piece
{

	Q_OBJECT

public:

	Pawn(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};