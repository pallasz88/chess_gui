#pragma once

#include "piece.h"

class Queen : public Piece
{

	Q_OBJECT

public:

	Queen(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

