#pragma once

#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QObject>

class Square : public QObject, public QGraphicsItem
{

	Q_OBJECT

public:

	Square(QBrush brush, QGraphicsItem *parent = Q_NULLPTR);

	Square(const Square&) { brush = QBrush(Qt::black); };

	QRectF boundingRect() const override;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

private:

	QBrush brush;
};
