#include "frame.h"
#include "history.h"
#include "piece.h"
#include "square.h"
#include "position.h"

Frame::Frame(QWidget *parent) :
    QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    CreateScene();
    CreateSquares();
    CreatePieces();
}

void Frame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace &&
       !History::GetInstance().IsEmpty())
    {
        History::GetInstance().DeleteLastMove();
        History::GetInstance().DeleteLastPosition();
        UpdateBoard();
    }
}

void Frame::CreateScene() {
    scene = new QGraphicsScene(this);
    setScene(scene);
    setSceneRect(-30, -20, 1200, 900);
    setBackgroundBrush(QBrush(QColor(1, 133, 116, 255)));
}

void Frame::CreatePieces()
{
    int i = 0;
    for (const auto &it : board)
    {
        QPointF offset((i % 8) * 100, (i / 8) * 100);
        if (it < 7 && it != 0)
        {
            pieces.push_back(new Piece((Piece::PieceTypes) it, offset, this));
            scene->addItem(pieces.back());
        }

        ++i;
    }
	
	History::GetInstance().SaveBoard(pieces);
}

const QList<Piece*>& Frame::GetPieces() const
{
	return pieces;
}

void Frame::CreateSquares()
{
    QList<Square *> squares;
    for (int i = 0; i < 64; i++)
	{
        ((i % 2 == 0 && (i / 8) % 2) == 1 ||
         (i % 2 == 1 && (i / 8) % 2 == 0)) ?
        squares.push_back(new Square(QColor(0, 99, 177, 255))) :
        squares.push_back(new Square(Qt::white));

        squares[i]->setPos((i % 8) * 100, (i / 8) * 100);
        scene->addItem(squares[i]);
    }
}

void Frame::UpdateBoard()
{
	pieces = History::GetInstance().GetPieces();
	PiecePosition position = History::GetInstance().GetLastPosition();

	for (auto& piece : pieces)
	    for (auto& pos : position.GetCurrentPosition()) {
            piece->setPos(pos);
            break;
        }

	scene->update(sceneRect());
}
