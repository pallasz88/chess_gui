#pragma once

#include "piece.h"

class King : public Piece
{

	Q_OBJECT

public:

	King(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

