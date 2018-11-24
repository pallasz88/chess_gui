#include "frame.h"
#include "history.h"
#include "piece.h"
#include "square.h"
#include "position.h"
#include <QDebug>

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
    setSceneRect(-130, -20, 1200, 900);
    setBackgroundBrush(QBrush(QColor(51, 62, 68, 255)));
}

void Frame::CreatePieces()
{
    int i = 0;
    for (const auto &it : board)
    {
        QPointF offset((i % 8) * 100, (i / 8) * 100);
        if (it < 7 && it != 0)
        {
			auto *piece = new Piece((Piece::PieceTypes) it, offset, this);
            pieces.push_back(piece);
            scene->addItem(piece);
        }

        ++i;
    }
	
	History::GetInstance().SaveBoard(pieces);
	History::GetInstance().PrintMoveHistory();
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
        squares.push_back(new Square(QColor(140, 162, 173, 255))) :
        squares.push_back(new Square(QColor(222, 227, 230, 255)));

        squares[i]->setPos((i % 8) * 100, (i / 8) * 100);
        scene->addItem(squares[i]);
    }
}

void Frame::UpdateBoard()
{
	PiecePosition position = History::GetInstance().GetLastPosition();

	foreach (const auto& pos, position.GetCurrentPosition()) 
		foreach(auto& piece, pieces)
		{
			qDebug() << "Take: " << pos;
			piece->setPos(pos);
			break;
		}

	scene->update(sceneRect());
}
