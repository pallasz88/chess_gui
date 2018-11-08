#pragma once

#include "piece.h"

class Rook : public Piece
{

	Q_OBJECT

public:

	Rook(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

