#include "frame.h"
#include "history.h"
#include "piece.h"
#include "square.h"
#include "position.h"
#include "adapter.h"
#include <QDebug>

Frame::Frame(QWidget *parent) :
    QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    fenPosition = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

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
    for(auto & it : fenPosition)
    {
        QPointF offset((i % 8) * 100, (i / 8) * 100);
        switch ( it )
        {
            case 'P':
            case 'p':
            case 'N':
            case 'n':
            case 'B':
            case 'b':
            case 'R':
            case 'r':
            case 'K':
            case 'k':
            case 'Q':
            case 'q':
                pieces.push_back(new Piece((Piece::PieceTypes) it, offset, this));
                scene->addItem(pieces.back());
                i++;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                i += it - '0';
                break;
            case '/':
            default:
                break;
        }
        if (it == ' ') break;
    }

    Chess::ParseFen(fenPosition);
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
	History::GetInstance().RestoreBoard(scene);
	scene->update(sceneRect());
}
