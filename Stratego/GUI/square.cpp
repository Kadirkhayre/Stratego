#include "square.h"
int Square::size = 50;

Square::Square(SquareType type, Piece* piece):m_type(type), m_piece(piece){
    QString styleSheet;
    if(piece){
        this->setText(QString::fromStdString(m_piece->getSymbol()));
        if(piece->getColor()==RED){
            styleSheet = "background-color: red;";
        }
        else if(piece->getColor()==BLUE){
            styleSheet = "background-color: blue;";
        }

    }
    styleSheet =styleSheet+"font-size: 15pt;"
                           "border: 1px solid gray;";
    this->setStyleSheet(styleSheet);
    this->setAlignment(Qt::AlignCenter);


    this->setMinimumSize(QSize(size, size));
    this->setMaximumSize(QSize(size, size));


}

SquareType Square::getType()const{
    return m_type;
}

Piece* Square::getPiece()const{
    return m_piece;
}

void Square::setPiece(Piece* piece){
    QString styleSheet;
    m_piece = piece;
    if(piece){
        this->setText(QString::fromStdString(m_piece->getSymbol()));
        if(piece->getColor()==RED){
            styleSheet = "background-color: red;";
        }
        else if(piece->getColor()==BLUE){
            styleSheet = "background-color: blue;";
        }

    }
    else{
        this->setText("");
        this->m_piece=nullptr;
    }

    styleSheet =styleSheet+"font-size: 15pt;"
                           "border: 1px solid gray;";
    this->setStyleSheet(styleSheet);
}

void Square::revealPiece(){
     QString styleSheet;
    this->setText(QString::fromStdString(this->getPiece()->getSymbol()));
}

void Square::hidePiece(){
    this->setText("");
}
