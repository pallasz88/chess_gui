#pragma once

#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QObject>

class Square : public QObject, public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    explicit Square(QBrush brush, QGraphicsItem *parent = Q_NULLPTR);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    QBrush brush;
};
