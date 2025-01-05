#include "gstrategoboard.h"

#include <QObject>
#include <QGridLayout>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <algorithm>
#include <QDebug>


int GStrategoBoard::N = 10;
QString TYPE = QString("My mime type");

GStrategoBoard::GStrategoBoard()
    : m_squares{{(obj(GROUND,new Piece("10",BLUE))), obj(GROUND, new Piece("9",BLUE)), obj(GROUND,new Piece("D",BLUE)), obj(GROUND,new Piece("6",BLUE)), obj(GROUND,new Piece("6",BLUE)), obj(GROUND,new Piece("5",BLUE)), obj(GROUND,new Piece("7",BLUE)), obj(GROUND,new Piece("7",BLUE)), obj(GROUND,new Piece("8",BLUE)), obj(GROUND,new Piece("8",BLUE))},
{(obj(GROUND,new Piece("1",BLUE))), obj(GROUND, new Piece("7",BLUE)), obj(GROUND,new Piece("4",BLUE)), obj(GROUND,new Piece("4",BLUE)), obj(GROUND,new Piece("6",BLUE)), obj(GROUND,new Piece("6",BLUE)), obj(GROUND,new Piece("4",BLUE)), obj(GROUND,new Piece("4",BLUE)), obj(GROUND,new Piece("5",BLUE)), obj(GROUND,new Piece("5",BLUE))},
{(obj(GROUND,new Piece("2",BLUE))), obj(GROUND, new Piece("2",BLUE)), obj(GROUND,new Piece("2",BLUE)), obj(GROUND,new Piece("3",BLUE)), obj(GROUND,new Piece("3",BLUE)), obj(GROUND,new Piece("3",BLUE)), obj(GROUND,new Piece("3",BLUE)), obj(GROUND,new Piece("2",BLUE)), obj(GROUND,new Piece("2",BLUE)), obj(GROUND,new Piece("2",BLUE))},
{(obj(GROUND,new Piece("B",BLUE))), obj(GROUND, new Piece("B",BLUE)), obj(GROUND,new Piece("B",BLUE)), obj(GROUND,new Piece("2",BLUE)), obj(GROUND,new Piece("3",BLUE)), obj(GROUND,new Piece("5",BLUE)), obj(GROUND,new Piece("2",BLUE)), obj(GROUND,new Piece("B",BLUE)), obj(GROUND,new Piece("B",BLUE)), obj(GROUND,new Piece("B",BLUE))},
{(obj(GROUND)), obj(GROUND), obj(LAKE), obj(LAKE), obj(GROUND), obj(GROUND), obj(LAKE), obj(LAKE), obj(GROUND), obj(GROUND)},
{(obj(GROUND)), obj(GROUND), obj(LAKE), obj(LAKE), obj(GROUND), obj(GROUND), obj(LAKE), obj(LAKE), obj(GROUND), obj(GROUND)},
{(obj(GROUND,new Piece("B",RED))), obj(GROUND, new Piece("B",RED)), obj(GROUND,new Piece("D",RED)), obj(GROUND,new Piece("2",RED)), obj(GROUND,new Piece("3",RED)), obj(GROUND,new Piece("5",RED)), obj(GROUND,new Piece("2",RED)), obj(GROUND,new Piece("B",RED)), obj(GROUND,new Piece("B",RED)), obj(GROUND,new Piece("B",RED))},
{(obj(GROUND,new Piece("2",RED))), obj(GROUND, new Piece("2",RED)), obj(GROUND,new Piece("2",RED)), obj(GROUND,new Piece("3",RED)), obj(GROUND,new Piece("3",RED)), obj(GROUND,new Piece("3",RED)), obj(GROUND,new Piece("3",RED)), obj(GROUND,new Piece("2",RED)), obj(GROUND,new Piece("2",RED)), obj(GROUND,new Piece("2",RED))},
{(obj(GROUND,new Piece("1",RED))), obj(GROUND, new Piece("7",RED)), obj(GROUND,new Piece("4",RED)), obj(GROUND,new Piece("4",RED)), obj(GROUND,new Piece("6",RED)), obj(GROUND,new Piece("6",RED)), obj(GROUND,new Piece("4",RED)), obj(GROUND,new Piece("4",RED)), obj(GROUND,new Piece("5",RED)), obj(GROUND,new Piece("5",RED))},
{(obj(GROUND,new Piece("10",RED))), obj(GROUND, new Piece("9",RED)), obj(GROUND,new Piece("B",RED)), obj(GROUND,new Piece("6",RED)), obj(GROUND,new Piece("6",RED)), obj(GROUND,new Piece("5",RED)), obj(GROUND,new Piece("7",RED)), obj(GROUND,new Piece("7",RED)), obj(GROUND,new Piece("8",RED)), obj(GROUND,new Piece("8",RED))}
}{
    this->resize(600, 600);
    /* setStyleSheet don't work so good;
     * - repeat background
     * - not resize component
    this->setStyleSheet(
                "background-image: url(./stratego-board.png) no-repeat");
    */
    this->setPixmap(QPixmap("./stratego-board.png"));


    auto * layout = new QGridLayout();
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(0);
    for (auto row = 0; row < 10 ; row++ ) {
        for (auto col = 0; col < 10; col++) {
            Square* lbl = new Square(m_squares[row][col].getType(),m_squares[row][col].getPiece());


            layout->addWidget(lbl, row, col);
            std::cout<<"done"<<std::endl;
        }
    }
    this->setLayout(layout);
    this->setAcceptDrops(true);

}



bool GStrategoBoard::isInside(int row, int col)
{
    return row >= 0 && row < GStrategoBoard::N
           && col >= 0 && col < GStrategoBoard::N;
}

/*
 * The click on element (here a cell) initiate the drag and drop.
 * When initiate drag and drop, the "drag" memorise information. Here I
 * memorize position of the cell source of drag and drop.
 */
void GStrategoBoard::mousePressEvent(QMouseEvent * event)
{
    qDebug() << "Initiate the drag and drop ";
    if (event->button() == Qt::LeftButton) {
        auto position { target(event->pos()) };
        if (position.first >= 0 && position.first < N
                && position.second >= 0 && position.second < N) {
            QByteArray itemData;
            QDataStream dataStream(&itemData, QIODevice::WriteOnly);
            dataStream << position.first << position.second ;
            QMimeData * mimeData = new QMimeData();
            mimeData->setData(TYPE, itemData);
            QDrag * drag = new QDrag(this);
            QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
            /*GImageCell * cell = dynamic_cast<GImageCell *>(
                                    layout->itemAtPosition(position.first, position.second)->widget());
            cell->setText("");*/
            //cell->setStyleSheet("background-color: white;");
            drag->setMimeData(mimeData);
            drag->exec();
        }
    }
}


void GStrategoBoard::dragEnterEvent(QDragEnterEvent * event)
{
    /*
     * Mouse pressed initiate drag and drop. I accept the drag and drop
     * if it'is a drag and drop with good type.
     */
    if (event->mimeData()->hasFormat(TYPE)) {
        event->acceptProposedAction();

    } else {
        event->ignore();
    }
}

void GStrategoBoard::dragLeaveEvent([[maybe_unused]] QDragLeaveEvent *
                                    event)
{
    // just accept when leave during draging
    event->accept();
}

void GStrategoBoard::dragMoveEvent([[maybe_unused]] QDragMoveEvent *
                                   event)
{
    // nothing to do durring move

}


void GStrategoBoard::dropEvent(QDropEvent * event)
{
    qDebug() << "Drop ";
    std::pair<int, int> destination { target(event->pos()) };
    std::pair<int, int> source {};

    QByteArray datas = event->mimeData()->data(TYPE);
    QDataStream dataStream(&datas, QIODevice::ReadOnly);
    dataStream >> source.first >> source.second;
    qDebug() << "Drag and drop: "
             << "source " << source
             << "destination " << destination;
    event->acceptProposedAction();
    // Send signal if positions are on board (source is already verified)
    if (destination.first >= 0 && destination.first < N
            && destination.second >= 0 && destination.second < N) {
        emit send_positions(source, destination);
    }
}



const std::pair<int, int> GStrategoBoard::target(
    const QPoint & position)
{
    int row = (position.y() / Square::size) - 1;
    int col = (position.x() / Square::size) - 1;
    return { row, col };
}

std::string GStrategoBoard::setDest(int row, int col, Piece* piece){
    if (!isInside(row, col))
        throw std::invalid_argument("Incorrect position");
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    std::string symbol;
    if(cell->getPiece()){
        symbol = cell->getPiece()->getSymbol();
    }
    else{
        symbol = " ";
    }

    cell->setPiece(piece);
    return symbol;
}

Piece* GStrategoBoard::setSource(int row, int col){
    if (!isInside(row, col))
        throw std::invalid_argument("Incorrect position");
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    Piece* piece = new Piece(cell->getPiece()->getSymbol(),cell->getPiece()->getColor());
    QString lbl = cell->text();
    cell->setStyleSheet("font-size: 10pt;"
                        "border: 1px solid gray;");
    cell->setText("");
    cell->setPiece(nullptr);
    return piece;
}

std::string GStrategoBoard::getSymbol(int row, int col){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    return cell->text().toStdString();
}

Color GStrategoBoard::getColor(int row, int col){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    return cell->getPiece()->getColor();
}

SquareType GStrategoBoard::getType(int row, int col){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    return cell->getType();
}

Piece* GStrategoBoard::getPiece(int row, int col){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    return cell->getPiece();
}

void GStrategoBoard::delDest(int row, int col){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    Square * cell = dynamic_cast<Square *>(
                            layout->itemAtPosition(row, col)->widget());
    cell->setPiece(nullptr);

}

void GStrategoBoard::visiblePlayerColor(Color color){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE ; j++ ) {
            Square * cell = dynamic_cast<Square *>(
                                    layout->itemAtPosition(i, j)->widget());
            if(cell->getPiece()&&cell->getPiece()->getColor()==color){
                cell->revealPiece();
            }
            else if(cell->getPiece()&&cell->getPiece()->getColor()!=color){
                cell->hidePiece();
            }
        }
    }
}

void GStrategoBoard::allVisiblePlayer(){
    QGridLayout * layout = dynamic_cast<QGridLayout *>(this->layout());
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE ; j++ ) {
            Square * cell = dynamic_cast<Square *>(
                                    layout->itemAtPosition(i, j)->widget());
            if(cell->getPiece()){
               cell->revealPiece();
            }

        }
    }
}







