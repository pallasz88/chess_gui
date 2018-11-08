#pragma once

#include "piece.h"

class Knight : public Piece
{

	Q_OBJECT

public:

	explicit Knight(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

