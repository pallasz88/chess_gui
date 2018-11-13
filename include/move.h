#pragma once


#include <iostream>
#include <QPointF>

struct Coordinates
{
    int x;
    int y;

    explicit Coordinates(int x, int y)
    {
        this->x = x;
        this->y = 8 - y;
    }
};

class Move
{

public:

    explicit Move(QPointF startPosition, QPointF endPosition);

    bool IsValid() {return true;}

    Coordinates GetFromCoordinates();

    Coordinates GetToCoordinates();

private:

    friend std::ostream& operator<<(std::ostream& os, const Move& move);

    std::string move;

};