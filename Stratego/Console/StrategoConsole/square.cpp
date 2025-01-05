#include "square.h"

Square::Square(SquareType type):m_type(type), m_piece(nullptr){}

SquareType Square::getType()const{
    return m_type;
}

Piece* Square::getPiece()const{
    return m_piece;
}

void Square::setPiece(Piece* piece){
    m_piece = piece;
}
