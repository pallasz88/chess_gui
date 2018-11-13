#pragma once


#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>
#include "piece.h"

class Square : public QObject, public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    explicit Square(QBrush brush, QGraphicsItem *parent = Q_NULLPTR);

private:

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void keyPressEvent(QKeyEvent * event) override ;

    QBrush brush;
};
