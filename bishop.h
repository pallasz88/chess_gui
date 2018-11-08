#pragma once

#include "piece.h"

class Bishop : public Piece
{

	Q_OBJECT

public:

	Bishop(Piece *parent = Q_NULLPTR);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};
