#include "obj.h"
obj::obj(SquareType type, Piece* piece):m_type(type), m_piece(piece){}

SquareType obj::getType()const{
    return m_type;
}

Piece* obj::getPiece()const{
    return m_piece;
}

void obj::setPiece(Piece* piece){
    m_piece = piece;
}
