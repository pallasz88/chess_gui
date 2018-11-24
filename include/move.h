#pragma once


#include <iostream>
#include <string>
#include <QPointF>

class Move
{

public:

    explicit Move(QPointF startPosition, QPointF endPosition);

    bool IsValid() {return true;}

private:

    friend std::ostream& operator<<(std::ostream& os, const Move& move);

    std::string move;

};